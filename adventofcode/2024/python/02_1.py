import sys

def solve(v):
    inc = v[0] < v[1]
    for i in range (len(v)-1):
        if (inc and v[i] >= v[i+1]) or (not inc and v[i] < v[i+1]):
            return False
        if v[i] == v[i+1] or abs(v[i]-v[i+1]) > 3:
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
    
    print(ans)

if __name__ == "__main__":
    main()