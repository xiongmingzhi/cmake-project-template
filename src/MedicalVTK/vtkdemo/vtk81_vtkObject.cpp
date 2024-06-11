/**
 * @author  Created by xzy on 2024/5/14
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);
VTK_MODULE_INIT(vtkInteractionStyle);

#include <vtkCallbackCommand.h>

long cntPress = 0;
void MyCallbackFunc(vtkObject*, unsigned long eid, void* clientdata, void* calldata)
{
    std::cout << "You have clicked : " << ++cntPress << " times" << std::endl;
}

#include <vtkSmartPointer.h>
#include <vtkPNGReader.h>
#include <vtkImageViewer2.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>

int main()
{
    vtkSmartPointer<vtkPNGReader> reader =
            vtkSmartPointer<vtkPNGReader>::New();
    reader->SetFileName("vtk.png");
    reader->Update();

    vtkSmartPointer<vtkImageViewer2> viewer =
            vtkSmartPointer<vtkImageViewer2>::New();
    viewer->SetInputData(reader->GetOutput());

    viewer->GetRenderer()->SetBackground(0, 0, 0);
    viewer->SetSize(480, 320);
    viewer->GetRenderWindow()->SetWindowName("Observer-Callback");

    vtkSmartPointer<vtkRenderWindowInteractor> rwi =
            vtkSmartPointer<vtkRenderWindowInteractor>::New();
    viewer->SetupInteractor(rwi);
    viewer->Render();
    /*************************************************************/
    //Step1：设置事件回调函数
    vtkSmartPointer<vtkCallbackCommand> mouseCallback =
            vtkSmartPointer<vtkCallbackCommand>::New();
    mouseCallback->SetCallback(MyCallbackFunc); //很重要！！！

    //Step2：将vtkCallbackCommand对象添加到观察者列表。
    rwi->SetRenderWindow(viewer->GetRenderWindow()); //唤醒显示窗口
    rwi->AddObserver(vtkCommand::LeftButtonPressEvent, mouseCallback);

    rwi->Initialize();
    rwi->Start();
    return 0;
}