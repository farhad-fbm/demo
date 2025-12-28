#include <GL/glut.h>
#include <cmath>

// ---------- DDA LINE ----------
void drawLineDDA(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;

    float steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
        glVertex2f(round(x), round(y));
        x += xInc;
        y += yInc;
    }
    glEnd();
}

// ---------- MIDPOINT LINE ----------
void drawLineMidpoint(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int d = dy - dx / 2;
    int x = x1, y = y1;

    glBegin(GL_POINTS);
    glVertex2i(x, y);

    while (x < x2) {
        x++;
        if (d < 0) {
            d += dy;
        } else {
            y++;
            d += dy - dx;
        }
        glVertex2i(x, y);
    }
    glEnd();
}

// ---------- MIDPOINT CIRCLE ----------
void plotCirclePoints(int xc, int yc, int x, int y) {
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);

    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
}

void drawCircleMidpoint(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 1 - r;

    glBegin(GL_POINTS);
    plotCirclePoints(xc, yc, x, y);

    while (x < y) {
        x++;
        if (d < 0) {
            d += 2 * x + 1;
        } else {
            y--;
            d += 2 * (x - y) + 1;
        }
        plotCirclePoints(xc, yc, x, y);
    }
    glEnd();
}

// ---------- DISPLAY ----------
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);

    drawLineDDA(50, 50, 200, 150);
    drawLineMidpoint(50, 150, 200, 250);
    drawCircleMidpoint(300, 200, 80);

    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Line & Circle Algorithms");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
