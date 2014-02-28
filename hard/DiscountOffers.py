import sys
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
            names = b[0].split(',')
            print(names)
            products = b[1].split(',')
            print(products)
            matrix = [[ss(n, p) for p in products] for n in names]
            print(matrix)
            max_overall = max(max(row) for row in matrix)
            print(max_overall)
            inv_matrix = [[max_overall - col for col in row] for row in matrix]
            print(inv_matrix)
            inv_matrix = [[col - min(row) for col in row] for row in inv_matrix]
            print(inv_matrix)
