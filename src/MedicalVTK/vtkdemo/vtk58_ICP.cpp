/**
 * @author  Created by xzy on 2024/5/25
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/

#include <vtkSmartPointer.h>
#include <vtkPolyDataReader.h>
#include <vtkPolyData.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkIterativeClosestPointTransform.h>
#include <vtkLandmarkTransform.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkAxesActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkOrientationMarkerWidget.h> //坐标系交互
int main()
{
    vtkSmartPointer <vtkPolyDataReader> reader =
            vtkSmartPointer<vtkPolyDataReader>::New();
    reader->SetFileName("fran_cut.vtk");
    reader->Update();

    //构造浮动数据点集
    vtkSmartPointer<vtkPolyData> orig = reader->GetOutput();
    vtkSmartPointer<vtkTransform> trans =
            vtkSmartPointer<vtkTransform>::New();
    trans->Translate(0.2, 0.1, 0.1);
    trans->RotateX(10);

    vtkSmartPointer<vtkTransformPolyDataFilter> transformFilter1 =
            vtkSmartPointer<vtkTransformPolyDataFilter>::New();
    transformFilter1->SetInputData(reader->GetOutput());
    transformFilter1->SetTransform(trans);
    transformFilter1->Update();
    /*********************************************************/
    //源数据 与 目标数据
    vtkSmartPointer<vtkPolyData> source =
            vtkSmartPointer<vtkPolyData>::New();
    source->SetPoints(orig->GetPoints());

    vtkSmartPointer<vtkPolyData> target =
            vtkSmartPointer<vtkPolyData>::New();
    target->SetPoints(transformFilter1->GetOutput()->GetPoints());

    vtkSmartPointer<vtkVertexGlyphFilter>  sourceGlyph =
            vtkSmartPointer<vtkVertexGlyphFilter>::New();
    sourceGlyph->SetInputData(source);
    sourceGlyph->Update();

    vtkSmartPointer<vtkVertexGlyphFilter>  targetGlyph =
            vtkSmartPointer<vtkVertexGlyphFilter>::New();
    targetGlyph->SetInputData(target);
    targetGlyph->Update();

    //进行ICP配准求变换矩阵
    vtkSmartPointer<vtkIterativeClosestPointTransform> icptrans =
            vtkSmartPointer<vtkIterativeClosestPointTransform>::New();
    icptrans->SetSource(sourceGlyph->GetOutput());
    icptrans->SetTarget(targetGlyph->GetOutput());
    icptrans->GetLandmarkTransform()->SetModeToRigidBody();
    icptrans->SetMaximumNumberOfIterations(50);
    icptrans->StartByMatchingCentroidsOn();
    icptrans->Modified();
    icptrans->Update();

    //配准矩阵调整源数据
    vtkSmartPointer<vtkTransformPolyDataFilter> solution =
            vtkSmartPointer<vtkTransformPolyDataFilter>::New();
    solution->SetInputData(sourceGlyph->GetOutput());
    solution->SetTransform(icptrans);
    solution->Update();

    vtkSmartPointer<vtkPolyDataMapper> sourceMapper =
            vtkSmartPointer<vtkPolyDataMapper>::New();
    sourceMapper->SetInputConnection(sourceGlyph->GetOutputPort());
    vtkSmartPointer<vtkActor> sourceActor =
            vtkSmartPointer<vtkActor>::New();
    sourceActor->SetMapper(sourceMapper);
    sourceActor->GetProperty()->SetColor(1, 1, 0);
    sourceActor->GetProperty()->SetPointSize(2);

    vtkSmartPointer<vtkPolyDataMapper> targetMapper =
            vtkSmartPointer<vtkPolyDataMapper>::New();
    targetMapper->SetInputConnection(targetGlyph->GetOutputPort());
    vtkSmartPointer<vtkActor> targetActor =
            vtkSmartPointer<vtkActor>::New();
    targetActor->SetMapper(targetMapper);
    targetActor->GetProperty()->SetColor(0, 1, 0);
    targetActor->GetProperty()->SetPointSize(3);

    vtkSmartPointer<vtkPolyDataMapper> soluMapper =
            vtkSmartPointer<vtkPolyDataMapper>::New();
    soluMapper->SetInputConnection(solution->GetOutputPort());
    vtkSmartPointer<vtkActor> soluActor =
            vtkSmartPointer<vtkActor>::New();
    soluActor->SetMapper(soluMapper);
    soluActor->GetProperty()->SetColor(1, 0, 0);
    soluActor->GetProperty()->SetPointSize(2);
    //设置坐标系
    vtkSmartPointer<vtkAxesActor> axes =
            vtkSmartPointer<vtkAxesActor>::New();
    ///
    vtkSmartPointer<vtkRenderer> render =
            vtkSmartPointer<vtkRenderer>::New();
    render->AddActor(sourceActor);
    render->AddActor(targetActor);
    render->AddActor(soluActor);
    render->SetBackground(0, 0, 0);

    vtkSmartPointer<vtkRenderWindow> rw =
            vtkSmartPointer<vtkRenderWindow>::New();
    rw->AddRenderer(render);
    rw->SetSize(480, 320);
    rw->SetWindowName("Regisration by ICP");

    vtkSmartPointer<vtkRenderWindowInteractor> rwi =
            vtkSmartPointer<vtkRenderWindowInteractor>::New();
    rwi->SetRenderWindow(rw);
    /****************************************************************/
    //谨记：顺序不可以颠倒！！！
    vtkSmartPointer<vtkOrientationMarkerWidget> widget =
            vtkSmartPointer<vtkOrientationMarkerWidget>::New();
    widget->SetOutlineColor(1, 1, 1);
    widget->SetOrientationMarker(axes);
    widget->SetInteractor(rwi); //加入鼠标交互
    widget->SetViewport(0.0, 0.0, 0.3, 0.3);  //设置显示位置
    widget->SetEnabled(1);
    widget->InteractiveOn();//开启鼠标交互
    /****************************************************************/
    render->ResetCamera();
    rw->Render();
    rwi->Initialize();
    rwi->Start();

    return 0;
}