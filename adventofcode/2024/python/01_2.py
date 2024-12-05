import sys
from collections import defaultdict

def main():
    sys.stdin = open("../input.txt", "r")
    sys.stdout = open("../output.txt", "w")
    
    LINES = 1000
    
    # Read input
    x = []
    y = []
    rmp = defaultdict(int)

    for _ in range(LINES):
        a, b = map(int, input().split())
        x.append(a)
        y.append(b)
        rmp[b]+=1
    
    # Sort the lists
    x.sort()
    y.sort()
    
    # Calculate the answer
    ans = 0
    for i in range(LINES):
        ans += x[i] * rmp[x[i]]
    
    print(ans)

if __name__ == "__main__":
    main()