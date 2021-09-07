import matplotlib.pyplot as plt
import random
import numpy as np


def searching_better_place(matrix, tolerance, x, y, color):
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            if (matrix[i][j] == 0 and is_happy(matrix, j, i, color, tolerance)):
                return (j, i)
    return (x, y)

def make_matrix(n=5, popul=10, part_of_popul=0.5):
    blue = int(popul*part_of_popul)
    red = popul - blue
    data = [1] * blue + [2] * red + [0] * (n * n - popul)
    random.shuffle(data)
    data = np.reshape(data, (n, n))
    return data

def is_happy(matrix, x, y, color, tolerance):
    blue, red = look_around(matrix, x, y)
    if (blue == 0 and red ==0):
        return False
    if color == 1:
        return blue/(blue+red) >= tolerance
    return red/(blue+red) >= tolerance

def look_around(matrix, x, y):
    accumRed = 0
    accumBlue = 0
    if x != 0:
        if matrix[y][x-1] == 1:
            accumBlue += 1
        if matrix[y][x-1] == 2:
            accumRed += 1
    if y != 0:
        if matrix[y-1][x] == 1:
            accumBlue += 1
        if matrix[y-1][x] == 2:
            accumRed += 1
    if x != len(matrix)-1:
        if matrix[y][x+1] == 1:
            accumBlue += 1
        if matrix[y][x+1] == 2:
            accumRed += 1
    if y != len(matrix)-1:
        if matrix[y+1][x] == 1:
            accumBlue += 1
        if matrix[y+1][x] == 2:
            accumRed += 1
    if (x != 0 and y != 0):
        if matrix[y-1][x-1] == 1:
            accumBlue += 1
        if matrix[y-1][x-1] == 2:
            accumRed += 1
    if (x != len(matrix)-1 and y != 0):
        if matrix[y-1][x+1] == 1:
            accumBlue += 1
        if matrix[y-1][x+1] == 2:
            accumRed += 1
    if (x != len(matrix)-1 and y != len(matrix)-1):
        if matrix[y+1][x+1] == 1:
            accumBlue += 1
        if matrix[y+1][x+1] == 2:
            accumRed += 1
    if (x != 0 and y != len(matrix)-1):
        if matrix[y+1][x-1] == 1:
            accumBlue += 1
        if matrix[y+1][x-1] == 2:
            accumRed += 1
    return (accumBlue, accumRed)

def make_agent_list(matrix, tolerance):
    agents=[]
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            if matrix[i][j] != 0:
                agents.append([j, i, is_happy(matrix, j, i, matrix[i][j], tolerance)])
    return agents

def cycle(agents, matrix, tolerance):
    for agent in agents:
        agent[2] = is_happy(matrix, agent[0], agent[1], matrix[agent[1]][agent[0]], tolerance)
        if agent[2] == False:
            tmpColor = matrix[agent[1]][agent[0]]
            matrix[agent[1]][agent[0]] = 0
            newX, newY = searching_better_place(matrix, tolerance, agent[0], agent[1], tmpColor)
            matrix[newY][newX] = tmpColor
            return matrix

def all_happy(agents):
    t = True
    for agent in agents:
        if agent[2] == False:
            t = False
            break
    return t

def happiness_coef(agents):
    a = 0
    for _ in agents:
        if _[2] == True:
            a += 1
    return a/len(agents)
