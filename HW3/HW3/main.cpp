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
float translateX = 0.0;
float translateY = 0.0;
int buttonPressed = 0;
int currX = 0;
int currY = 0;
float scale = 1.0;

bool spacePressed = false;

void mouseMove(int x, int y) {
    // Todo: Check if square is pressed before dragging
    float X = ((float) x / 700);
    float Y = 1.0 - ((float) y / 700);
    if (buttonPressed != 0) {
        scale = (float) (scale + ((float) (x - currX) / 5000));
        std::cout << "NEW SCALE " << scale;
    } else {
        translateX = X - 0.5;
        translateY = Y - 0.5;
    }
}

void drawRectangleOnPosition(float x, float y) {
    glPushMatrix();
    // To rotate in position, we first translate the object
    glTranslatef(x, y, 0);
    // Then rotate it
    glRotatef(-1 * angle, 0, 0, 1);
    // Then translate it back to its original position
    glTranslatef(-1 * x, -1 * y, 0);
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(x - 0.2, y + 0.1, 0.5);
    glVertex3f(x + 0.2, y + 0.1, 0.5);
    glVertex3f(x + 0.2, y - 0.1, 0.5);
    glVertex3f(x - 0.2, y - 0.1, 0.5);
    glEnd();
    glPopMatrix();
}

void drawSquare() {
    glPushMatrix();
    glColor3f(1, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(-0.5, 0.5, 0.2);
    glVertex3f(0.5, 0.5, 0.2);
    glVertex3f(0.5, -0.5, 0.2);
    glVertex3f(-0.5, -0.5, 0.2);
    glEnd();
    glPopMatrix();
}

void redraw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glPushMatrix();
    glTranslatef(translateX, translateY, 0);
    angle += 2;
    glScalef(scale, scale, 1);
    drawSquare();
    drawRectangleOnPosition(-0.5, 0.5);
    drawRectangleOnPosition(0.5, 0.5);
    glPopMatrix();
    glutSwapBuffers();
}

void checkMouseButton(int button, int state, int x, int y) {
    buttonPressed = button;
    currX = x;
    currY = y;
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
    glOrtho(-1.0, 1.0, -1.0, 1.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(redraw);
    glutIdleFunc(redraw);
    glutMotionFunc(mouseMove);
    glutMouseFunc(checkMouseButton);
    glutMainLoop();
    return 0;
}
