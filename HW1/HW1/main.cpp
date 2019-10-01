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
#include <math.h>

void drawPolygon(int sides, float x, float y, float scale) {
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < sides; i++) {
        // Here, we place points on a circle to make a polygon
        // For example, when sides = 3, we draw an equilateral triangle
        glVertex3f(
            x + scale * cos(2 * M_PI / sides * i),
            y + scale * sin(2 * M_PI / sides * i),
            0.0
        );
    }
    glEnd();
}

void redraw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0, 0, 1);

    drawPolygon(3, 0.5, 0.5, 0.1);

    glutSwapBuffers();
}

int main(int argc, char * argv[]) {
    std::cout << "Hello, World!\n";
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("One triangle");
    glutPositionWindow(10,10);
    glutReshapeWindow(700,700);
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
