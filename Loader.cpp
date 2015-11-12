#include "Loader.h"

Loader::Loader()
{
    numVertices=0;
}

Loader::~Loader()
{

}

void Loader::loadScene(const char* filePath){
    Assimp::Importer importer;
    myScene = importer.ReadFile(filePath, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs);

    if(!myScene){
        std::clog<<"Couldn't load "<<filePath<<" "<<importer.GetErrorString()<<std::endl;
        return;
    } else {
        std::clog<<"Loaded "<<filePath<<" successfully"<<std::endl;
        loadMeshes(myScene);
    }
}

void Loader::loadMeshes(const aiScene* loadedScene){


    for (int i = 0; i < myScene->mNumMeshes; ++i)
    {
        //loadNormals(myScene->mMeshes[i]);
        loadVertices(myScene->mMeshes[i]);
        //loadTextures(myScene->mMeshes[i]);

        numVertices += myScene->mMeshes[i]->mNumVertices;
    }

}


void Loader::loadNormals(aiMesh* loadedMesh){

    glm::vec3 auxiliarNormalVec;

    for(int i=0; i < loadedMesh->mNumVertices; ++i)
    {
        auxiliarNormalVec[0] = loadedMesh->mNormals[i][0];
        auxiliarNormalVec[1] = loadedMesh->mNormals[i][1];
        auxiliarNormalVec[2] = loadedMesh->mNormals[i][2];
        normalArray.push_back(auxiliarNormalVec);
    }

}


void Loader::loadVertices(aiMesh* loadedMesh){

    glm::vec3 auxiliarVertexVec;
    std::clog<<" number of vertices"<<loadedMesh->mNumFaces<<std::endl;

    for(int i=0; i < loadedMesh->mNumVertices; ++i)
    {
        auxiliarVertexVec[0] = loadedMesh->mVertices[i][0];
        auxiliarVertexVec[1] = loadedMesh->mVertices[i][1];
        auxiliarVertexVec[2] = loadedMesh->mVertices[i][2];
        vertexArray.push_back(auxiliarVertexVec);
    }

}

void Loader::loadTextures(aiMesh* loadedMesh){

    glm::vec2 auxiliarTextureVec;

    for(int i=0; i < loadedMesh->mNumFaces; ++i)
    {
        aiFace tmpFace = loadedMesh->mFaces[i];
       auxiliarTextureVec[0] = loadedMesh->mTextureCoords[0][tmpFace.mIndices[0]].x;
       auxiliarTextureVec[1] = loadedMesh->mTextureCoords[0][tmpFace.mIndices[1]].y;
       textureArray.push_back(auxiliarTextureVec);

    }

}

void Loader::PrintVec3(glm::vec3 v3){
	for (int i = 0; i < 3; ++i)
	{
		std::cout<<v3[i]<<" ";
	}

	std::cout<<std::endl;
}

void Loader::PrintVec2(glm::vec2 v2){
	for (int i = 0; i < 2; ++i)
	{
		std::cout<<v2[i]<<" ";
	}

	std::cout<<std::endl;
}

void Loader::PrintVector(std::vector <glm::vec3> vec){

    for(int i=0; i<vec.size(); ++i)
        PrintVec3(vec[i]);
}



