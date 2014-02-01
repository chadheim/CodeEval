import sys
import math
import re
with open(sys.argv[1]) as f:
    for line in f:
        m = re.findall(r'([-+]?[0-9]*\.?[0-9]+)', line)
        if math.hypot(float(m[3])-float(m[0]), float(m[4])-float(m[1])) <= float(m[2]):
            print('true')
        else:
            print('false')

