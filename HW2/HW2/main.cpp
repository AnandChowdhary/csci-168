//
//  main.cpp
//  HW2
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

float topLeftX = 0.1;
float topLeftY = 0.9;

float topRightX = 0.9;
float topRightY = 0.9;

float centerX = 0.5;
float centerY = 0.5;

float bottomLeftX = 0.1;
float bottomLeftY = 0.1;

float bottomRightX = 0.9;
float bottomRightY = 0.1;

void redraw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    
    // POLYGONS

    // Top polygon
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3f(topLeftX, topLeftY, 0.2);
    glVertex3f(centerX, centerY, 0.2);
    glVertex3f(topRightX, topRightY, 0.2);
    glEnd();

    // Right polygon
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(topRightX, topRightY, 0.2);
    glVertex3f(bottomRightX, bottomRightY, 0.2);
    glVertex3f(centerX, centerY, 0.2);
    glEnd();

    // Bottom polygon
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(bottomLeftX, bottomLeftY, 0.2);
    glVertex3f(centerX, centerY, 0.2);
    glVertex3f(bottomRightX, bottomRightY, 0.2);
    glEnd();

    // Left polygon
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f(topLeftX, topLeftY, 0.2);
    glVertex3f(centerX, centerY, 0.2);
    glVertex3f(bottomLeftX, bottomRightY, 0.2);
    glEnd();
    
    // LINES
    glLineWidth(3);
    
    // Top
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(topLeftX, topLeftY, 0.3);
    glVertex3f(topRightX, topRightY, 0.3);
    glEnd();
    
    // Right
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(topRightX, topRightY, 0.3);
    glVertex3f(bottomRightX, bottomRightY, 0.3);
    glEnd();
    
    // Bottom
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(bottomLeftX, bottomLeftY, 0.3);
    glVertex3f(bottomRightX, bottomRightY, 0.3);
    glEnd();

    // Left
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(topLeftX, topLeftY, 0.3);
    glVertex3f(bottomLeftX, bottomLeftY, 0.3);
    glEnd();

    // Diagonal Top Left
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(topLeftX, topLeftY, 0.3);
    glVertex3f(centerX, centerY, 0.3);
    glEnd();

    // Diagonal Top Right
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(topRightX, topRightY, 0.3);
    glVertex3f(centerX, centerY, 0.3);
    glEnd();

    // Diagonal Bottom Left
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(bottomLeftX, bottomLeftY, 0.3);
    glVertex3f(centerX, centerY, 0.3);
    glEnd();

    // Diagonal Bottom Right
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(bottomRightX, bottomRightY, 0.3);
    glVertex3f(centerX, centerY, 0.3);
    glEnd();
    
    // POINTS
    glPointSize(10);
    glColor3f(0, 1, 1);
    glBegin(GL_POINTS);
    
    glVertex3f(topLeftX, topLeftY, 0.5);
    glVertex3f(topRightX, topRightY, 0.5);
    glVertex3f(bottomLeftX, bottomLeftY, 0.5);
    glVertex3f(bottomRightX, bottomRightY, 0.5);
    glVertex3f(centerX, centerY, 0.5);

    glEnd();

    glutSwapBuffers();
}

void mouseMove(int x, int y) {
    std::cout << "MOUSE\n" << ((float) x / 700) << "  " << 1.0 - ((float) y / 700) << "\n";
    topLeftX = ((float) x / 700);
    topLeftY = (1.0 - ((float) y / 700));
    redraw();
}

int main(int argc, char * argv[]) {
    std::cout << "Homework 2\n" << "Output" << "\n";
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
    glutMotionFunc(mouseMove);
    glutMainLoop();
    return 0;
}
