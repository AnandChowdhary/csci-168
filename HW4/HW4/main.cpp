//
//  main.cpp
//  HW4
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
#include <math.h>

int main(int argc, char * argv[]) {
    std::cout << "Homework 3\n" << "Output" << "\n";
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Homework 4");
    glutPositionWindow(10,10);
    glutReshapeWindow(700,700);
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutMainLoop();
    return 0;
}
