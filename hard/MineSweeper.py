import sys
import re

def mark(o, i, w, h):
    o[i] = '*'

with open(sys.argv[1]) as f:
    for l in f:
        m = re.match('([1-9]),([1-9]);([\.\*]*)', l)
        w = int(m.group(1))
        h = int(m.group(2))
        o = [0] * w * h
        for i, x in enumerate(m.group(3)):
            if x == '*':
                mark(o, i, w, h)
        print ''.join(map(str, o))