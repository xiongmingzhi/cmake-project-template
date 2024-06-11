/**
 * @author  Created by xzy on 2024/5/18
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/
#include <vtkSmartPointer.h>
#include <vtkBMPReader.h>
#include <vtkImageData.h>
#include <vtkXYPlotActor.h>
#include <vtkProperty2D.h>
#include <vtkTextProperty.h>
#include <vtkImageExtractComponents.h>
#include <vtkImageAccumulate.h>

#include <vtkImageActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>

int main()
{
    vtkSmartPointer<vtkBMPReader> reader =
            vtkSmartPointer<vtkBMPReader>::New();
    reader->SetFileName("../../doc/lena2.bmp");
    reader->Update();

    int numComponents = reader->GetOutput()->GetNumberOfScalarComponents();

    //
    vtkSmartPointer<vtkXYPlotActor> plot =
            vtkSmartPointer<vtkXYPlotActor>::New();
    plot->ExchangeAxesOff();
    plot->SetLabelFormat("%g");
    plot->SetXTitle("灰度值");
    plot->SetYTitle("像素频率");
    plot->SetXValuesToValue();
    plot->GetProperty()->SetColor(1.0, 1.0, 1.0);
    plot->GetAxisLabelTextProperty()->SetColor(0, 0, 0);
    plot->GetAxisTitleTextProperty()->SetColor(0, 0, 0);

    double colors[3][3] = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };
    const char* labels[3] = { "Red", "Green", "Blue" };
    int xmax = 0;
    int ymax = 0;
    for (int i = 0; i < numComponents; ++i)
    {
        vtkSmartPointer<vtkImageExtractComponents> extract =
                vtkSmartPointer<vtkImageExtractComponents>::New();
        extract->SetInputConnection(reader->GetOutputPort());
        extract->SetComponents(i);
        extract->Update();

        double range[2];
        extract->GetOutput()->GetScalarRange(range);
        int extent = static_cast<int> (range[1]) - static_cast<int>(range[0]) - 1;

        vtkSmartPointer<vtkImageAccumulate> histogram =
                vtkSmartPointer<vtkImageAccumulate>::New();
        histogram->SetInputConnection(reader->GetOutputPort());
        histogram->SetComponentExtent(0,extent, 0, 0, 0, 0);
        histogram->SetComponentOrigin(range[0], 0, 0);
        histogram->SetComponentSpacing(1, 0, 0);
        histogram->SetIgnoreZero(1);
        histogram->Update();

        if (range[1] > xmax)
        {
            xmax = range[1];
        }
        if (histogram->GetOutput()->GetScalarRange()[1] > ymax)
        {
            ymax = histogram->GetOutput()->GetScalarRange()[1];
        }
        plot->AddDataSetInput(histogram->GetOutput());
        plot->SetPlotColor(i, colors[i]);
        plot->SetPlotLabel(i, labels[i]);
        plot->LegendOn();
    }
    plot->SetXRange(0, xmax);
    plot->SetYRange(0, ymax);

    vtkSmartPointer<vtkImageActor> imgActor =
            vtkSmartPointer<vtkImageActor>::New();
    imgActor->SetInputData(reader->GetOutput());

    double imgView[4] = { 0.0, 0.0, 0.5, 1.0 };
    double histView[4] = { 0.5, 0.0, 1.0, 1.0 };
    vtkSmartPointer<vtkRenderer> imgRender =
            vtkSmartPointer<vtkRenderer>::New();
    imgRender->SetViewport(imgView);
    imgRender->AddActor(imgActor);
    imgRender->SetBackground(1.0, 0.0, 0.0);

    vtkSmartPointer<vtkRenderer> histRender =
            vtkSmartPointer<vtkRenderer>::New();
    histRender->SetViewport(histView);
    histRender->AddActor(plot);
    histRender->SetBackground(1.0, 1.0, 1.0);

    vtkSmartPointer<vtkRenderWindow> rw =
            vtkSmartPointer<vtkRenderWindow>::New();
    rw->AddRenderer(imgRender);
    rw->AddRenderer(histRender);
    rw->SetSize(640, 320);
    rw->SetWindowName("RGB-Image Histogram");

    vtkSmartPointer<vtkRenderWindowInteractor> rwi =
            vtkSmartPointer<vtkRenderWindowInteractor>::New();
    rwi->SetRenderWindow(rw);
    rwi->Initialize();

    rwi->Start();
    return 0;
}