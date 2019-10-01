//
//  main.cpp
//  HW1
//
//  Created by Anand Chowdhary on 10/1/19.
//  Copyright © 2019 Anand Chowdhary. All rights reserved.
//

#define GL_SILENCE_DEPRECATION

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>
#include <stdlib.h>

void redraw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0, 0, 1);
    glBegin(GL_TRIANGLES);
    glVertex3f(0.1, 0.1, 0.0);
    glVertex3f(0.5, 0.1, 0.0);
    glVertex3f(0.1, 0.7, 0.0);
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char * argv[]) {
    std::cout << "Hello, World!\n";
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("One triangle");
    glutPositionWindow(10,10);
    glutReshapeWindow(500,500);
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(redraw);
    glutMainLoop();
    return 0;
}
