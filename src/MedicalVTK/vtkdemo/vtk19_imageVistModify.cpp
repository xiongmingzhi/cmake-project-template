/**
 * @author  Created by xzy on 2024/5/18
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/
#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkBMPReader.h>
#include <vtkImageViewer2.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkImageIterator.h>

void imageVistModify1()
{
    vtkSmartPointer<vtkBMPReader> reader =
            vtkSmartPointer<vtkBMPReader>::New();
    reader->SetFileName("../../doc/lena.bmp");
    reader->Update();

    int dims[3];
    reader->GetOutput()->GetDimensions(dims);

    int nbofComp;
    nbofComp = reader->GetOutput()->GetNumberOfScalarComponents();

    for (int k = 0; k < dims[2]; k++)
    {
        for (int j = 0; j < dims[1]; j++)
        {
            for (int i = 0; i < dims[0]; i++)
            {
                if (i < 384 && i > 128 && j > 128 && j < 384)
                {
                    unsigned char *pixel = (unsigned char *)(reader->GetOutput()->GetScalarPointer(i, j, k));
                    *pixel = 255 - *pixel;
                    *(pixel + 1) = 255 - *(pixel + 1);
                    *(pixel + 2) = 255 - *(pixel + 2);
                }
            }
        }
    }

    vtkSmartPointer<vtkImageViewer2> imgViewer =
            vtkSmartPointer<vtkImageViewer2>::New();
    imgViewer->SetInputData(reader->GetOutput());

    vtkSmartPointer<vtkRenderWindowInteractor> rwi =
            vtkSmartPointer<vtkRenderWindowInteractor>::New();
    imgViewer->SetupInteractor(rwi);
    imgViewer->Render();
    imgViewer->GetRenderer()->ResetCamera();
    imgViewer->Render();
    imgViewer->GetRenderer()->SetBackground(1.0, 1.0, 1.0);
    imgViewer->SetSize(1800, 1200);
    imgViewer->GetRenderWindow()->SetWindowName("VisitImagePixelDirectly");

    rwi->Start();
}

void imageVistModify2()
{
    vtkSmartPointer<vtkBMPReader> reader =
            vtkSmartPointer<vtkBMPReader>::New();
    reader->SetFileName("../../doc/lena.bmp");
    reader->Update();

    int subRegion[6] = { 64, 448, 64, 448, 0, 0 };
    vtkImageIterator<unsigned char> iter(reader->GetOutput(),subRegion);

    while (!iter.IsAtEnd())
    {
        unsigned char *inSI = iter.BeginSpan();
        unsigned char *inSIEnd = iter.EndSpan();

        while ( inSI != inSIEnd )
        {
            *inSI = 255 - *inSI;
            ++inSI;
        }
        iter.NextSpan();
    }

    vtkSmartPointer<vtkImageViewer2> imgViewer =
            vtkSmartPointer<vtkImageViewer2>::New();
    imgViewer->SetInputConnection(reader->GetOutputPort());

    vtkSmartPointer<vtkRenderWindowInteractor> rwi =
            vtkSmartPointer<vtkRenderWindowInteractor>::New();
    imgViewer->SetupInteractor(rwi);
    imgViewer->Render();
    imgViewer->GetRenderer()->ResetCamera();
    imgViewer->Render();
    imgViewer->GetRenderer()->SetBackground(1.0, 1.0, 1.0);
    imgViewer->SetSize(1800, 1200);
    imgViewer->GetRenderWindow()->SetWindowName("VisitImagePixelIteratively");

    rwi->Start();
}

int main(int arg, char* argv[])
{
    //imageVistModify1();
    imageVistModify2();
    return 0;
}