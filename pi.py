import math
def sqrt(n,MAX):
    float_max=10**16
    n_float=float((n*float_max)//MAX)/float_max
    curr=(int(float_max*math.sqrt(n_float))*MAX)//float_max
    n_MAX=n*MAX
    while True:
        prev=curr
        curr=(curr+n_MAX//curr)//2
        if curr==prev:
            break
    return curr
def power(n):
    if n==0:
        return 1
    ans=power(n//2)
    if n%2==0:
        return ans*ans
    return ans*ans*10
def pi():
    MAX=power(100000)
    c=(640320**3)//24
    n=1
    a_n=MAX
    a_summation=MAX
    b_summation=0
    while a_n!=0:
        a_n*=-(6*n-5)*(2*n-1)*(6*n-1)
        a_n//=n*n*n*c
        a_summation+=a_n
        b_summation+=n*a_n
        n+=1
    ans=(426880*sqrt(10005*MAX,MAX)*MAX)//(13591409*a_summation+545140134*b_summation)
    return ans
p=str(pi())
p='3.'+p[1:]
t=int(raw_input())
while t:
    t-=1
    n=int(raw_input())
    print p[:n+2]
