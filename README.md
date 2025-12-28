#include <GL/glut.h>
#include <math.h>

void drawCircle(float cx, float cy, float r) {
    glBegin(GL_POINTS);
    for(int i = 0; i <= 360; i++) {
        float theta = i * 3.1416 / 180;
        float x = cx + r * cos(theta);
        float y = cy + r * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Base
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_QUADS);
        glVertex2f(0.2, 0.1);
        glVertex2f(0.8, 0.1);
        glVertex2f(0.8, 0.2);
        glVertex2f(0.2, 0.2);
    glEnd();

    // Left Pillar
    glColor3f(1, 1, 1);
    glBegin(GL_QUADS);
        glVertex2f(0.25, 0.2);
        glVertex2f(0.35, 0.2);
        glVertex2f(0.35, 0.7);
        glVertex2f(0.25, 0.7);
    glEnd();

    // Middle Pillar (Tall)
    glBegin(GL_QUADS);
        glVertex2f(0.45, 0.2);
        glVertex2f(0.55, 0.2);
        glVertex2f(0.55, 0.8);
        glVertex2f(0.45, 0.8);
    glEnd();

    // Right Pillar
    glBegin(GL_QUADS);
        glVertex2f(0.65, 0.2);
        glVertex2f(0.75, 0.2);
        glVertex2f(0.75, 0.7);
        glVertex2f(0.65, 0.7);
    glEnd();

    // Red Sun
    glColor3f(1, 0, 0);
    drawCircle(0.5, 0.45, 0.08);

    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1, 0, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Shohid Minar");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
