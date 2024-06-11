/**
 * @author  Created by xzy on 2024/3/12
 * Copyright (c) 2022-2029 xzy
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
**/
#include <iostream>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

int main() {
    // 创建一个Assimp的导入器
    Assimp::Importer importer;

    // 加载3D模型文件
    const aiScene* scene = importer.ReadFile("path_to_your_model_file", aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals);

    if (!scene) {
        std::cerr << "Error loading model: " << importer.GetErrorString() << std::endl;
        return -1;
    }

    // 打印模型信息
    std::cout << "Model loaded successfully!" << std::endl;
    std::cout << "Number of meshes: " << scene->mNumMeshes << std::endl;

    // 遍历所有网格
    for (unsigned int i = 0; i < scene->mNumMeshes; ++i) {
        aiMesh* mesh = scene->mMeshes[i];
        std::cout << "Mesh " << i << " has " << mesh->mNumVertices << " vertices and " << mesh->mNumFaces << " faces." << std::endl;
    }

    // 释放Assimp资源
    importer.FreeScene();

    return 0;
}
