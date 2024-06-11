#include<vtkSmartPointer.h>
#include<vtkImageViewer2.h>
#include<vtkDICOMImageReader.h>
#include<vtkRenderWindow.h>
#include<vtkRenderWindowInteractor.h>
#include<vtkRenderer.h>
#include<iostream>
#include<string.h>
#include <unistd.h>
#include<vtkAutoInit.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);

int main()
{
    std::string OpenPath = "../../doc/DicomData/2011-11-30liping/00200.dcm";
    //char* root = getcwd(nullptr, 0);
    //printf("the paths is %s", root);

    vtkSmartPointer<vtkDICOMImageReader> reader =
            vtkSmartPointer<vtkDICOMImageReader>::New();
    reader->SetFileName(OpenPath.c_str());
    reader->Update();

    vtkSmartPointer<vtkImageViewer2> imageViewer =
            vtkSmartPointer<vtkImageViewer2>::New();
    imageViewer->SetInputConnection(reader->GetOutputPort());

    vtkSmartPointer<vtkRenderWindowInteractor> renWin =
            vtkSmartPointer<vtkRenderWindowInteractor>::New();
    imageViewer->SetupInteractor(renWin);
    imageViewer->Render();
    imageViewer->GetRenderer()->ResetCamera();
    imageViewer->Render();

    renWin->Start();

    return EXIT_SUCCESS;
}