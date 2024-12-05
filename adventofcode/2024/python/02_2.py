import sys

def arr(v, i, idx):
    if i < idx:
        return v[i]
    else:
        return v[i+1]

def solve(v):
    inc = v[0] < v[1]
    for i in range (len(v)-1):
        if (inc and v[i] >= v[i+1]) or (not inc and v[i] < v[i+1]):
            return False
        if v[i] == v[i+1] or abs(v[i]-v[i+1]) > 3:
            return False
    return True

def solve_tolerate(v, idx):
    if len(v) < 3:
        return False
    inc = arr(v, 0, idx) < arr(v, 1, idx)
    for i in range(len(v)-2):
        if (inc and arr(v, i, idx) >= arr(v, i+1, idx)) or (not inc and arr(v, i, idx) < arr(v, i+1, idx)):
            return False
        if arr(v, i, idx) == arr(v, i+1, idx) or abs(arr(v, i, idx)-arr(v, i+1, idx)) > 3:
            return False
    return True

def main():
    sys.stdin = open("../input.txt", "r")
    sys.stdout = open("../output.txt", "w")
    
    LINES = 1000
    ans = 0
    
    for _ in range(LINES):
        try:
            s = input().strip()
        except EOFError:
            break
        if not s:
            continue
        v = list(map(int, s.split()))
        if solve(v):
            ans+=1
        else:
            tolerable = False
            for idx in range(len(v)):
                if (solve_tolerate(v, idx)):
                    tolerable = True
                    break
            if tolerable:
                ans += 1
    
    print(ans)

if __name__ == "__main__":
    main()