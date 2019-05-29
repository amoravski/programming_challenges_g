intNum = 231111

def to_binary(baseTen):
    i=0
    binary=0
    while(baseTen>0):
        if (baseTen<2**i):
            baseTen-=2**(i-1)
            binary+=10**(i-1)
            i=0
        else:
            i+=1
    return binary

print(to_binary(intNum))
