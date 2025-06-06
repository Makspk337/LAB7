#include <GLUT/glut.h>
#include <cmath>

const float MIN_SIZE = 0.001f; // Минимальный размер
int depth = 13; // Начальная глубина рекурсии

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void drawPythagorasTree(float x1, float y1, float x2, float y2, int currentDepth) {
    if (currentDepth <= 0) return;
    
    // Вектор основания
    float dx = x2 - x1;
    float dy = y2 - y1;
    
    // Перпендикулярный вектор (повернутый на 90°)
    float px = -dy;
    float py = dx;
    
    // Нормализация перпендикулярного вектора
    float length = sqrt(dx*dx + dy*dy);
    if (length < MIN_SIZE) return;
    
    px = px / length * length;
    py = py / length * length;
    
    // Верхние точки квадрата
    float x3 = x2 + px;
    float y3 = y2 + py;
    float x4 = x1 + px;
    float y4 = y1 + py;
    
    // Рисуем квадрат (4 линии)
    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x4, y4);
    drawLine(x4, y4, x1, y1);
    
    // Центр верхней стороны
    float cx = (x3 + x4) * 0.5f;
    float cy = (y3 + y4) * 0.5f;
    
    // Вектор от центра к углу
    float hx = x3 - cx;
    float hy = y3 - cy;
    
    // Вершина треугольника (перпендикулярно)
    float tx = -hy;
    float ty = hx;
    float x5 = cx + tx;
    float y5 = cy + ty;
    
    // Рисуем треугольник (3 линии)
    drawLine(x3, y3, x4, y4);
    drawLine(x4, y4, x5, y5);
    drawLine(x5, y5, x3, y3);
    
    // Рекурсивный вызов для двух ветвей
    drawPythagorasTree(x4, y4, x5, y5, currentDepth - 1);
    drawPythagorasTree(x5, y5, x3, y3, currentDepth - 1);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Начальное основание дерева
    float x1 = -0.15f, y1 = -0.6f;
    float x2 = 0.15f, y2 = -0.6f;
    
    drawPythagorasTree(x1, y1, x2, y2, depth);
    
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == '+' && depth < 15) depth++;
    else if (key == '-' && depth > 1) depth--;
    else if (key == 27) exit(0); // ESC - выход
    
    glutPostRedisplay();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Белый фон
    glColor3f(0.0, 0.0, 0.0); // Черные линии
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Pythagoras Tree");
    
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    return 0;
}
