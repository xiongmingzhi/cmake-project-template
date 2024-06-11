/**
 * @author  Created by xzy on 2024/5/18
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/
#include <vtkSmartPointer.h>
#include <vtkImageCast.h>
#include <vtkImageShiftScale.h>
#include <vtkBMPReader.h>
#include <vtkMetaImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>

int main()
{
    vtkSmartPointer<vtkMetaImageReader> reader =
            vtkSmartPointer<vtkMetaImageReader>::New(); //读*.mhd文件
    reader->SetFileName("../../doc/brain.mhd");
    reader->Update();
    //第一种类型转换方案
    vtkSmartPointer<vtkImageCast> imgCast =
            vtkSmartPointer<vtkImageCast>::New();
    imgCast->SetInputData( (vtkDataObject *) reader->GetOutput() );
    imgCast->SetOutputScalarTypeToFloat();
    //第二种类型转换方案
    vtkSmartPointer<vtkImageShiftScale> imgShiftScale =
            vtkSmartPointer<vtkImageShiftScale>::New();
    imgShiftScale->SetInputData((vtkDataObject*)reader->GetOutput());
    imgShiftScale->SetOutputScalarTypeToFloat();

    vtkSmartPointer<vtkImageViewer2> imgViewer =
            vtkSmartPointer<vtkImageViewer2>::New();
    imgViewer->SetInputConnection(imgCast->GetOutputPort());

    vtkSmartPointer<vtkRenderWindowInteractor> rwi =
            vtkSmartPointer<vtkRenderWindowInteractor>::New();
    imgViewer->SetupInteractor(rwi);

    imgViewer->SetColorLevel(500);
    imgViewer->SetColorWindow(2000);
    imgViewer->SetSlice(20);
    imgViewer->SetSliceOrientationToXY();
    imgViewer->Render();

    /*imgViewer->GetRenderer()->ResetCamera();
    imgViewer->Render();*/
    imgViewer->GetRenderer()->SetBackground(1.0, 1.0, 1.0);
    imgViewer->SetSize(1800, 1200);
    imgViewer->GetRenderWindow()->SetWindowName("ImageTypeTrans");

    rwi->Start();
    return 0;
}