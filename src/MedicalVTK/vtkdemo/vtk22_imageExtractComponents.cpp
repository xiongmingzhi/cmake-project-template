/**
 * @author  Created by xzy on 2024/5/18
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/
#include <vtkSmartPointer.h>
#include <vtkBMPReader.h>
#include <vtkImageExtractComponents.h>
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

    vtkSmartPointer<vtkImageExtractComponents> redComponent =
            vtkSmartPointer<vtkImageExtractComponents>::New();
    redComponent->SetInputConnection(reader->GetOutputPort());
    redComponent->SetComponents(0);
    redComponent->Update();

    vtkSmartPointer<vtkImageExtractComponents> greenComponent =
            vtkSmartPointer<vtkImageExtractComponents>::New();
    greenComponent->SetInputConnection(reader->GetOutputPort());
    greenComponent->SetComponents(1);
    greenComponent->Update();

    vtkSmartPointer<vtkImageExtractComponents> blueComponent =
            vtkSmartPointer<vtkImageExtractComponents>::New();
    blueComponent->SetInputConnection(reader->GetOutputPort());
    blueComponent->SetComponents(2);
    blueComponent->Update();
    //创建演员
    vtkSmartPointer<vtkImageActor> origActor =
            vtkSmartPointer<vtkImageActor>::New();
    origActor->SetInputData(reader->GetOutput());

    vtkSmartPointer<vtkImageActor> redActor =
            vtkSmartPointer<vtkImageActor>::New();
    redActor->SetInputData(redComponent->GetOutput());

    vtkSmartPointer<vtkImageActor> greenActor =
            vtkSmartPointer<vtkImageActor>::New();
    greenActor->SetInputData(greenComponent->GetOutput());

    vtkSmartPointer<vtkImageActor> blueActor =
            vtkSmartPointer<vtkImageActor>::New();
    blueActor->SetInputData(blueComponent->GetOutput());
    //定义窗口 并化妆
    double origView[4] = { 0.0, 0.0, 0.25, 1.0 };
    double redView[4] = { 0.25, 0.0, 0.5, 1.0 };
    double greenView[4] = { 0.5, 0.0, 0.75, 1.0 };
    double blueView[4] = { 0.75, 0.0, 1.0, 1.0 };

    vtkSmartPointer<vtkRenderer> origRender =
            vtkSmartPointer<vtkRenderer>::New();
    origRender->SetViewport(origView);
    origRender->AddActor(origActor);
    origRender->ResetCamera();
    origRender->SetBackground(1.0, 1.0, 1.0);

    vtkSmartPointer<vtkRenderer> redRender =
            vtkSmartPointer<vtkRenderer>::New();
    redRender->SetViewport(redView);
    redRender->AddActor(redActor);
    redRender->ResetCamera();
    redRender->SetBackground(1.0, 1.0, 1.0);

    vtkSmartPointer<vtkRenderer> greenRender =
            vtkSmartPointer<vtkRenderer>::New();
    greenRender->SetViewport(greenView);
    greenRender->AddActor(greenActor);
    greenRender->ResetCamera();
    greenRender->SetBackground(1.0, 1.0, 1.0);

    vtkSmartPointer<vtkRenderer> blueRender =
            vtkSmartPointer<vtkRenderer>::New();
    blueRender->SetViewport(blueView);
    blueRender->AddActor(blueActor);
    blueRender->ResetCamera();
    blueRender->SetBackground(1.0, 1.0, 1.0);
    //上舞台
    vtkSmartPointer<vtkRenderWindow> renderwindow =
            vtkSmartPointer<vtkRenderWindow>::New();
    renderwindow->AddRenderer(origRender);
    renderwindow->AddRenderer(redRender);
    renderwindow->AddRenderer(greenRender);
    renderwindow->AddRenderer(blueRender);
    renderwindow->SetSize(960, 320);
    renderwindow->Render();
    renderwindow->SetWindowName("ExtraImageColorComponents");
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