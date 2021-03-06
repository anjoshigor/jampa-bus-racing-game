
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <string>
#include "Loader.h"
Loader* loader1;
unsigned int ViewPortWidth  = 800;
unsigned int ViewPortHeight = 600;
GLfloat angle = 0;
    void display(void)
    {

    glViewport(0, 0, ViewPortWidth, ViewPortHeight);

	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
  	glLoadIdentity();
	gluPerspective(	55.0f, 								// angulo de abertura da camera
					(1.0f * ViewPortWidth)/ViewPortWidth, // aspecto da imagem
					0.5f, 								// near plane
					50.0f);								// far plane

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(	-1.0f, 1.0f, 0.6f,	// posição da câmera
				-0.3f, 0.0f, 0.0f,	// ponto para o qual a camera está olhando
				0.0f, 1.0f, 0.0f);	// vetor "up"

        glTranslatef(0.0f, -0.5f, 0.0f);
        glRotatef(0.0f, 0.0f, 1.0f, 0.0f);

        glBegin(GL_LINES);
			for(int i=0; i<loader1->numVertices;i+=3)
			{
                glVertex3f(loader1->vertexArray[i].x,loader1->vertexArray[i].y,loader1->vertexArray[i].z);
                glVertex3f(loader1->vertexArray[i+1].x, loader1->vertexArray[i+1].y, loader1->vertexArray[i+1].z);

                glVertex3f(loader1->vertexArray[i+1].x, loader1->vertexArray[i+1].y, loader1->vertexArray[i+1].z);
                glVertex3f(loader1->vertexArray[i+2].x, loader1->vertexArray[i+2].y, loader1->vertexArray[i+2].z);

                glVertex3f(loader1->vertexArray[i+2].x, loader1->vertexArray[i+2].y, loader1->vertexArray[i+2].z);
                glVertex3f(loader1->vertexArray[i].x, loader1->vertexArray[i].y, loader1->vertexArray[i].z);
			}
        glEnd();


        glFlush();
        glutSwapBuffers();
        glutPostRedisplay();

    }


    int main(int argc, char** argv)
    {

        loader1 = new Loader();
        loader1->loadScene("Models/FullTrack.obj");
        //loader1->PrintVector(loader1->vertexArray);




        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
        glutInitWindowSize(ViewPortWidth,ViewPortHeight);
        glutInitWindowPosition(100,100);
        glutCreateWindow("JampaBus Racing Game");
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1.0f,1.0f,-1.0f,1.0f,-1.0f,1.0f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();


        glutDisplayFunc(display);

        glutMainLoop();

        return 0;
    }

