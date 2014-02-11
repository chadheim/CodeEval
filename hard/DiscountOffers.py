import sys
import itertools
import fractions

def isvowel(c):
    return c in 'AEIOUY'

def isconsonant(c):
    return str.isalpha(c) and not isvowel(c)

def ss(n, p):
    nl = sum(map(str.isalpha, n))
    pl = sum(map(str.isalpha, p))
    if pl % 2 == 0:
        score = sum(map(isvowel, n)) * 1.5
    else:
        score = sum(map(isconsonant, n))
    if fractions.gcd(nl, pl) > 1:
        score *= 1.5
    return score

with open(sys.argv[1]) as f:
    for line in f:
        b = line.upper().rstrip().split(';')
        if len(b) == 2:
            m = list(map((lambda s: s.split(',')), b))
            names = m[0]
            products = m[1]
            ss_max = 0
            for np in itertools.permutations(range(len(products)), len(names)):
                total = 0
                for n, p in enumerate(np):
                    total += ss(names[n], products[p])
                ss_max = max(ss_max, total)
            print(ss_max)