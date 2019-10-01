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
    glBegin(GL_POLYGON);
    for (int i = 0; i < sides; i++) {
        // Here, we place points on a circle to make a polygon
        // For example, when sides = 3, we draw an equilateral triangle
        glVertex3f(
            x + scale * cos(2 * M_PI / sides * i),
            y + scale * sin(2 * M_PI / sides * i),
            sides * 0.1 // This trick makes sure the z-index increases for each polygon
        );
    }
    glEnd();
}

// Generate a random float between 0.3 and 0.7
float rand01() {
    return ((float) (rand() % (700 - 300 + 1) + 300) / 1000);
}

// Generate a random float between 0.1 and 0.2
float rand02() {
    return ((float) (rand() % (200 - 100 + 1) + 100) / 1000);
}

void redraw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);

    glColor4f(0, 0, 1, rand01());
    drawPolygon(3, 0.5, 0.5, rand02());
    
    glColor4f(0, 1, 0, rand01());
    drawPolygon(4, 0.4, 0.4, rand02());
    
    glColor4f(1, 0, 0, rand01());
    drawPolygon(5, 0.2, 0.2, rand02());
    
    glColor4f(1, 1, 0, rand01());
    drawPolygon(6, 0.7, 0.3, rand02());
    
    glColor4f(1, 0, 1, rand01());
    drawPolygon(7, 0.4, 0.6, rand02());
    
    glColor4f(0, 1, 1, rand01());
    drawPolygon(8, 0.6, 0.8, rand02());

    glutSwapBuffers();
}

int main(int argc, char * argv[]) {
    srand(time(NULL));
    std::cout << "Hello, World!\n" << "\n";
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
