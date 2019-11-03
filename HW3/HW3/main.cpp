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
    glVertex3f(bottomLeftX, bottomLeftY, 0.2);
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

float diff(float x, float y, float X, float Y) {
    return sqrt(pow((X - x), 2) + pow((Y - y), 2));
}

void mouseMove(int x, int y) {
    float X = ((float) x / 700);
    float Y = 1.0 - ((float) y / 700);
    std::string selected = "top-left";
    float minimumDistance = 1.0;
    
    // First, we select the point you want to move
    if (diff(X, Y, topLeftX, topLeftY) < minimumDistance) {
        selected = "top-left";
        minimumDistance = diff(X, Y, topLeftX, topLeftY);
    }
    if (diff(X, Y, topRightX, topRightY) < minimumDistance) {
        selected = "top-right";
        minimumDistance = diff(X, Y, topRightX, topRightY);
    }
    if (diff(X, Y, bottomLeftX, bottomLeftY) < minimumDistance) {
        selected = "bottom-left";
        minimumDistance = diff(X, Y, bottomLeftX, bottomLeftY);
    }
    if (diff(X, Y, bottomRightX, bottomRightY) < minimumDistance) {
        selected = "bottom-right";
        minimumDistance = diff(X, Y, bottomRightX, bottomRightY);
    }
    if (diff(X, Y, centerX, centerY) < minimumDistance) {
        selected = "center";
        minimumDistance = diff(X, Y, centerX, centerY);
    }
    
    std::cout << "MOUSE\n" << X << "  " << Y << " " << minimumDistance << " " << selected << "\n";

    // Then, we move that point
    if (selected == "top-left") {
        topLeftX = X;
        topLeftY = Y;
    } else if (selected == "top-right") {
        topRightX = X;
        topRightY = Y;
    } else if (selected == "bottom-left") {
        bottomLeftX = X;
        bottomLeftY = Y;
    } else if (selected == "bottom-right") {
        bottomRightX = X;
        bottomRightY = Y;
    } else {
        centerX = X;
        centerY = Y;
    }

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
