import sys

dirs = [
    [(0, 0), (0, 1), (0, 2), (0, 3)],  # Horizontal right
    [(0, 0), (0, -1), (0, -2), (0, -3)],  # Horizontal left
    [(0, 0), (1, 0), (2, 0), (3, 0)],  # Vertical down
    [(0, 0), (-1, 0), (-2, 0), (-3, 0)],  # Vertical up
    [(0, 0), (1, 1), (2, 2), (3, 3)],  # Diagonal down-right
    [(0, 0), (-1, -1), (-2, -2), (-3, -3)],  # Diagonal up-left
    [(0, 0), (1, -1), (2, -2), (3, -3)],  # Diagonal down-left
    [(0, 0), (-1, 1), (-2, 2), (-3, 3)],  # Diagonal up-right
]

XMAS = "XMAS"

def search(grid, i, j):
    rows, cols = len(grid), len(grid[0])
    ans = 0
    for d in dirs:
        found = True
        for k in range(4):
            dx, dy = d[k]
            x, y = i+dx, j+dy
            if x<0 or x>=rows or y<0 or y>=cols or grid[x][y] != XMAS[k]:
                found = False
                break
        if found:
            ans += 1
    return ans

def main():
    sys.stdin = open("../input.txt", "r")
    sys.stdout = open("../output.txt", "w")
    
    LINES = 140
    grid = [input().strip() for _ in range(LINES)]
    rows, cols = len(grid), len(grid[0])
    ans = 0;
    
    for i in range(rows):
        for j in range(cols):
            ans += search(grid, i, j)
    
    print(ans)

if __name__ == "__main__":
    main()