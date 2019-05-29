intArray = [ 1, 2, 3, 1 , 2 , 3 , 2 , 2 , 3, 3, 3 , 3, 3 ,3]

intArray.sort()

# Solution 1
max = 1
previousMax = 0
previousElement = intArray[0]
for i in intArray:
    if i == previousElement:
        max+=1
    else:
        if max > previousMax:
            previousMax = max
        previousElement = i
        max = 1
if max > previousMax:
    previousMax = max
print(previousMax)
