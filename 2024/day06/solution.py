import numpy as np

with open("2024/6.txt", "r") as file:
    grid = np.array([list(line.strip()) for line in file])

x_size, y_size = grid.shape     #dimensions
empty_grid = np.zeros((y_size, y_size))
moves = np.array([(-1, 0), (0, 1), (1, 0), (0, -1)])

pos = tuple(np.argwhere(grid == '^')[0])  # determin start position
orientation = 0
empty_grid[pos] = 1


while 0 < pos[0] < x_size-1 and 0 < pos[1] < y_size-1 :
    xi, yi = moves[orientation]
    x, y = pos

    if grid[x+xi][y+yi] == '#':                # lahko tund [x+xi, y+yi]
        orientation = (orientation + 1) % 4
    else:
        pos = (x+xi, y+yi)
        empty_grid[pos] = 1


print(int(np.sum(empty_grid)))








