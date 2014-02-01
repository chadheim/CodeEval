import sys
import re

def mark(o, w, h, x, y):
    if 0 <= x < w and 0 <= y < h:
        i = y * w + x
        if o[i] != '*':
            o[i] += 1

with open(sys.argv[1]) as f:
    k = [(-1,-1), (0,-1), (1,-1), (-1,0), (1,0), (-1,1), (0,1), (1,1)]
    for l in f:
        m = re.match('([1-9]),([1-9]);([\.\*]*)', l)
        h, w = int(m.group(1)), int(m.group(2))
        o = [0] * w * h
        for y in range(h):
            for x in range(w):
                i = y * w + x
                if m.group(3)[i] == '*':
                    o[i] = '*'
                    for dx, dy in k:
                        mark(o, w, h, x + dx, y + dy)
        print(''.join(map(str, o)))