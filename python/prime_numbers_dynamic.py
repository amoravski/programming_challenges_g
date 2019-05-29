prime_count = 50000

def find_primes(primes):
    counter = 2
    # Primes by definition
    primes_found = [0, 1]
    cache_checked = []
    while(primes>0):
        if (is_prime(counter)):
            primes_found.append(counter)
            cache_checked.append(counter)
            primes-=1
        else:
            cache_checked.append(counter)
        counter+=1
        while(True):
            untested=True
            for i in cache_checked:
                if (counter%i==0):
                    untested=False
                    break
            if (untested):
                break
            else:
                counter+=1
    return primes_found

def is_prime(num):
    isPrime=True
    for i in range(2, num):
        if(num%i==0):
            isPrime=False
            break
    return isPrime

print(find_primes(prime_count))
