import sys
import itertools

with open(sys.argv[1]) as f:
    for l in f:
        n, s = l.strip().split(',')
        r = itertools.product(sorted(set(s)), repeat=int(n))
        print(','.join([''.join(e) for e in r]))
