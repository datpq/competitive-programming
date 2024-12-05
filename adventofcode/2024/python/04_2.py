import sys

dirs = [
    [(-1, -1), (0, 0), (1, 1)],
    [(-1, 1), (0, 0), (1, -1)],
]

MAS = "MAS"
SAM = "SAM"
rows, cols = 0, 0
grid = []

def search(i, j):
    ans = 0
    for d in dirs:
        s = ""
        for k in range(3):
            dx, dy = d[k]
            x, y = i+dx, j+dy
            if x<0 or x>=rows or y<0 or y>=cols:
                return 0
            s += grid[x][y]
        if s != MAS and s != SAM:
            return 0
    return 1

def main():
    sys.stdin = open("../input.txt", "r")
    sys.stdout = open("../output.txt", "w")
    
    global rows, cols, grid
    LINES = 140
    grid = [input().strip() for _ in range(LINES)]
    rows, cols = len(grid), len(grid[0])
    ans = 0
    
    for i in range(rows):
        for j in range(cols):
            ans += search(i, j)
    
    print(ans)

if __name__ == "__main__":
    main()