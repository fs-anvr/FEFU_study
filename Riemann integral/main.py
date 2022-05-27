from math import *
from tkinter import *

# размеры окна, здесь они же - размеры холста
window_height = 800 
window_wigth = 1000

# размеры координатной сетки
x_right = 20
x_left = -20
y_top = 20
y_bottom = -20
# количество отображаемых делений
countX = 20
countY = 20
# переменные шага разбиения и точности определения границ пересечения
step = 0.003
eps = 0.1


dx = window_wigth / (x_right - x_left)
dy = window_height / (y_top - y_bottom)

font=('Comic Sans MS', 9, 'bold italic')


window = Tk()
window.title("Графики функций:")
window.config(width = window_wigth, height = window_height)
window.resizable(False, False)

canvas = Canvas(window, width = window_wigth, height = window_height, bg = '#121018')


def axis():
    cx = screenX(0)
    cy = screenY(0)

    canvas.create_line(0, cy, window_wigth, cy, fill = '#ffffff', arrow= LAST)
    canvas.create_line(cx, window_height, cx, 0, fill = '#ffffff', arrow= LAST)

    x_step = (x_right - x_left) / countX
    x = x_left + x_step

    while x < x_right:
        x_canvas = screenX(x)
        canvas.create_line(x_canvas, cy - 5, x_canvas, cy + 5, fill = '#ffffff', width = 2)
        canvas.create_text(x_canvas, cy + 25, text = str(round(x, 0)), font = font, fill = '#ffffff')
        x += x_step

    y_step = (y_top - y_bottom) / countY
    y = y_bottom + y_step

    while y < y_top:
        y_canvas = screenY(y)
        canvas.create_line(cx - 5, y_canvas, cx + 5, y_canvas, fill = '#ffffff', width = 2)
        canvas.create_text(cx - 25, y_canvas, text = str(round(y, 0)), font = font, fill = '#ffffff')
        y += y_step

def screenX(x):
    return (x - x_left) * dx

def screenY(y):
    return (y_top - y) * dy


def graphics():
    intersect_points = []

    x_1 = x_left
    x_2 = x_1 + step
    x = x_1

    y1_1 = y1_2 = eval(formula1)
    y2_1 = y2_2 = eval(formula2)
    while x_2 <= x_right:
        if abs(y1_2 - y2_2) < eps:
            intersect_points.append(x_2)
        x = x_2
        y1_2 = eval(formula1)
        y2_2 = eval(formula2)
        canvas.create_line(screenX(x_1), screenY(y1_1), screenX(x_2), screenY(y1_2), fill = '#ff0000', width = 2)
        canvas.create_line(screenX(x_1), screenY(y2_1), screenX(x_2), screenY(y2_2), fill = '#ff0000', width = 2)

        x_1 = x_2
        y1_1 = y1_2
        y2_1 = y2_2
        x_2 += step


    return intersect_points


def correctlyPoints(intersect_points):
    if (intersect_points.count != 0):
        intersect_points = [
            intersect_points[0],
            intersect_points[-1]
            ]

        x = intersect_points[0]
        yi_1 = eval(formula1)
        x = intersect_points[1]
        yi_2 = eval(formula1)

        if abs(yi_1 - yi_2) < eps:
            if abs(intersect_points[0] - intersect_points[1]) < eps:
                return [False, intersect_points]
    else:
        return [False, intersect_points]

    return [True, intersect_points]


def areaTrapez(intersect_points):
    S = 0
    x = intersect_points[0]
    S += eval(formula1)
    S -= eval(formula2)
    x = intersect_points[1]
    S += eval(formula1)
    S -= eval(formula2)
    S /= 2.0

    count = 0
    x = intersect_points[0] + step
    while x < intersect_points[1]:
        S += eval(formula1) - eval(formula2)
        if count % 100 == 5:
            canvas.create_line(screenX(x), screenY(eval(formula1)), screenX(x), screenY(eval(formula2)), fill = '#00ff00', width = 0.3)
        x += step
        count += 1
    S *= step

    return abs(S)



def areaMediumTriang(intersect_points):
    S = 0
    count = 0
    x = intersect_points[0] + step / 2

    while x < intersect_points[1]:
        S += eval(formula1) - eval(formula2)
        if count % 100 == 5:
            canvas.create_line(screenX(x), screenY(eval(formula1)), screenX(x), screenY(eval(formula2)), fill = '#00ff00', width = 0.3)
        x += step
        count += 1
    S *= step

    return abs(S)



axis()

formula1 = input('f1(x):')
formula2 = input('f2(x):')

points = graphics()
#print(points)
if correctlyPoints(points)[0]:
    points = correctlyPoints(points)[1]
    print("Площадь методом средних прямоугольников: ")
    triangS = areaMediumTriang(points)
    print(triangS)
    print("Площадь методом трапеций: ")
    trapezS = areaTrapez(points)
    print(trapezS)

    x = points[0]
    canvas.create_text(screenX(x - 2.5), screenY(eval(formula1) + 1.5), text = "x : " + str(round(x, 6)) + "\ny : " + str(round(eval(formula1), 6)), font = font, fill = '#ffffff')
    x = points[1]
    canvas.create_text(screenX(x + 2.5), screenY(eval(formula1) + 1.5), text = "x : " + str(round(x, 6)) + "\ny : " + str(round(eval(formula1), 6)), font = font, fill = '#ffffff')
    canvas.create_text(100, 100, text = "S triang : " + str(round(triangS, 10)) + "\nS trapez : " + str(round(trapezS, 10)), font = font, fill = '#ffffff')
else:
    print("NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO")

canvas.pack()	
window.mainloop()
