from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
import math
import sys

MIN_SIZE = 0.001
depth = 13  # Начальная глубина рекурсии

def drawLine(x1, y1, x2, y2):
    glBegin(GL_LINES)
    glVertex2f(x1, y1)
    glVertex2f(x2, y2)
    glEnd()

def drawPythagorasTree(x1, y1, x2, y2, currentDepth):
    if currentDepth <= 0:
        return

    dx = x2 - x1
    dy = y2 - y1

    # Перпендикулярный вектор
    px = -dy
    py = dx

    length = math.sqrt(dx * dx + dy * dy)
    if length < MIN_SIZE:
        return

    px = px / length * length
    py = py / length * length

    # Верхние точки квадрата
    x3 = x2 + px
    y3 = y2 + py
    x4 = x1 + px
    y4 = y1 + py

    # Рисуем квадрат
    drawLine(x1, y1, x2, y2)
    drawLine(x2, y2, x3, y3)
    drawLine(x3, y3, x4, y4)
    drawLine(x4, y4, x1, y1)

    # Центр верхней стороны
    cx = (x3 + x4) * 0.5
    cy = (y3 + y4) * 0.5

    # Вершина треугольника
    hx = x3 - cx
    hy = y3 - cy
    tx = -hy
    ty = hx
    x5 = cx + tx
    y5 = cy + ty

    # Рисуем треугольник
    drawLine(x3, y3, x4, y4)
    drawLine(x4, y4, x5, y5)
    drawLine(x5, y5, x3, y3)

    # Рекурсивный вызов
    drawPythagorasTree(x4, y4, x5, y5, currentDepth - 1)
    drawPythagorasTree(x5, y5, x3, y3, currentDepth - 1)

def display():
    glClear(GL_COLOR_BUFFER_BIT)

    # Начальное основание дерева
    x1, y1 = -0.15, -0.6
    x2, y2 = 0.15, -0.6
    drawPythagorasTree(x1, y1, x2, y2, depth)

    glFlush()

def keyboard(key, x, y):
    global depth
    if key == b'+' and depth < 15:
        depth += 1
    elif key == b'-' and depth > 1:
        depth -= 1
    elif key == b'\x1b':  # ESC
        sys.exit()
    glutPostRedisplay()

def init():
    glClearColor(1.0, 1.0, 1.0, 1.0)  # Белый фон
    glColor3f(0.0, 0.0, 0.0)  # Черные линии
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0)


glutInit(sys.argv)
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
glutInitWindowSize(800, 800)
glutCreateWindow(b"Pythagoras Tree")
init()
glutDisplayFunc(display)
glutKeyboardFunc(keyboard)
glutMainLoop()

