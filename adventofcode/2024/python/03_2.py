import sys

import re

def main():
    sys.stdin = open("../input.txt", "r")
    sys.stdout = open("../output.txt", "w")
    
    pattern = re.compile(r"do\(\)|don't\(\)|mul\((\d+),(\d+)\)")
    LINES = 6
    ans = 0
    enabled = True
    
    for _ in range(LINES):
        try:
            s = input().strip()
        except EOFError:
            break
        if not s:
            continue
        matches = pattern.finditer(s)
        
        for match in matches:
            match_str = match.group(0)
            if match_str == "do()":
                enabled = True
            elif match_str == "don't()":
                enabled = False
            elif enabled and len(match.group()) >= 2:
                a = int(match.group(1))
                b = int(match.group(2))
                ans += a*b
    
    print(ans)

if __name__ == "__main__":
    main()