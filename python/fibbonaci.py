n = 10

# Iterative
x=1
y=1
for i in range(1, n):
    oldx=x
    x=y
    y=oldx+y
print(x)

# Recursive

def fibbonaci(n):
    if n<=1:
        return 1
    else:
        return fibbonaci(n-1) + fibbonaci(n-2)
print(fibbonaci(n))
