# greastest common divisor
def gcd(p, q):
    if (q == 0):
        return p
    r = p % q
    return gcd(q, r)

data = input().split()

p = int(data[0])
q = int(data[1])

print(gcd(p, q))
print(int(p*q/gcd(p,q)))

