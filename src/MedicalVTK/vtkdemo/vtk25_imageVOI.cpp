/**
 * @author  Created by xzy on 2024/5/18
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/
#include <vtkSmartPointer.h>
#include <vtkBMPReader.h>
#include <vtkImageData.h>//提取图像内部信息，如维度等
#include <vtkExtractVOI.h>
#include <vtkImageActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkInteractorStyleImage.h>

int main()
{
    vtkSmartPointer<vtkBMPReader> reader =
            vtkSmartPointer<vtkBMPReader>::New();
    reader->SetFileName("../../doc/lena2.bmp");
    reader->Update();

    int dim[3];
    reader->GetOutput()->GetDimensions(dim);
    //提取图像子模块
    vtkSmartPointer<vtkExtractVOI> extractVOI =
            vtkSmartPointer<vtkExtractVOI>::New();
    extractVOI->SetInputConnection(reader->GetOutputPort());
    extractVOI->SetVOI(dim[0] / 4., 3.*dim[0] / 4., dim[1] / 4., 3.*dim[1] / 4, 0, 0);
    extractVOI->Update();
    //创建演员
    vtkSmartPointer<vtkImageActor> origActor =
            vtkSmartPointer<vtkImageActor>::New();
    origActor->SetInputData(reader->GetOutput());

    vtkSmartPointer<vtkImageActor>  voiActor =
            vtkSmartPointer<vtkImageActor>::New();
    voiActor->SetInputData(extractVOI->GetOutput());
    //化妆
    double origView[4] = { 0, 0, 0.5, 1.0 };
    double voiView[4] = { 0.5, 0, 1.0, 1.0 };
    vtkSmartPointer<vtkRenderer> origRender =
            vtkSmartPointer<vtkRenderer>::New();
    origRender->SetViewport(origView);
    origRender->AddActor(origActor);
    origRender->ResetCamera();
    origRender->SetBackground(1.0, 0, 0);

    vtkSmartPointer<vtkRenderer> voiRender =
            vtkSmartPointer<vtkRenderer>::New();
    voiRender->SetViewport(voiView);
    voiRender->AddActor(voiActor);
    voiRender->ResetCamera();
    voiRender->SetBackground(0.0, 0.0, 0.0);
    //舞台
    vtkSmartPointer<vtkRenderWindow> renderwindow =
            vtkSmartPointer<vtkRenderWindow>::New();
    renderwindow->AddRenderer(origRender);
    renderwindow->AddRenderer(voiRender);
    renderwindow->SetSize(640, 320);
    renderwindow->SetWindowName("ExtractVolumeOfInterestFromImage");
    //设置交互
    vtkSmartPointer<vtkRenderWindowInteractor> rwi =
            vtkSmartPointer<vtkRenderWindowInteractor>::New();
    vtkSmartPointer<vtkInteractorStyleImage> style =
            vtkSmartPointer<vtkInteractorStyleImage>::New();
    rwi->SetInteractorStyle(style);
    rwi->SetRenderWindow(renderwindow);
    rwi->Initialize();

    rwi->Start();
    return 0;
}