//
//  main.cpp
//  HW3
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

int angle = 0;

void drawRectangleOnPosition(float x, float y) {
    glPushMatrix();
    // To rotate in position, we first translate the object
    glTranslatef(x, y, 0);
    // Then rotate it
    glRotatef(angle, 0, 0, 1);
    // Then translate it back to its original position
    glTranslatef(-1 * x, -1 * y, 0);
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(x - 0.1, y + 0.05, 0.5);
    glVertex3f(x + 0.1, y + 0.05, 0.5);
    glVertex3f(x + 0.1, y - 0.05, 0.5);
    glVertex3f(x - 0.1, y - 0.05, 0.5);
    glEnd();
    glPopMatrix();
}

void drawSquare() {
    glPushMatrix();
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(0.25, 0.25, 0.2);
    glVertex3f(0.25, 0.75, 0.2);
    glVertex3f(0.75, 0.75, 0.2);
    glVertex3f(0.75, 0.25, 0.2);
    glEnd();
    glPopMatrix();
}

void redraw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    angle += 2;
    drawSquare();
    drawRectangleOnPosition(0.25, 0.75);
    drawRectangleOnPosition(0.75, 0.75);
    glutSwapBuffers();
}

int main(int argc, char * argv[]) {
    std::cout << "Homework 3\n" << "Output" << "\n";
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Homework 2");
    glutPositionWindow(10,10);
    glutReshapeWindow(700,700);
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,1.0,0.0,1.0,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(redraw);
    glutIdleFunc(redraw);
    glutMainLoop();
    return 0;
}
