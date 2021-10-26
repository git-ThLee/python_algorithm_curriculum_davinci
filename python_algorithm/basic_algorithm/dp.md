# 동적계획법 (dynamic programming)

## 1. 정의

주어진 문제를 풀기 위해 여러가지 하위 문제로 나누어서 해결한 후 큰 문제를 푸는 알고리즘 기법

## 2. 예시와 구현

N번째 피보나치 수를 구하는 함수를 구현하고자 한다.

기존 재귀함수를 이용하여 구현을 할 때는 아래와 같이 구현을 했을 것이다.

```python
def fibonacci(n):
    if n==1 or n == 2:
        return 1
    return fibonacci(n-1) + fibonacci(n-2)
```

이 경우 5번째 피보나치 수를 구하기 위해서

fibonacci(5) = fibonacci(4) + fibonacci(3) = (fibonacci(3) + fibonacci(2)) + (fibonacci(2) + fibonacci(1))
 = ((fibonacci(2) + fibonacci(1)) + fibonacci(2)) + (fibonacci(2) + fibonacci(1))

 과 같이 함수가 호출될 것이며 똑같은 함수가 여러번 호출되어 비효율적으로 코드가 동작한다는 것을 알 수 있다.

 n번째 피보나치 수를 구하는 과정을 세분화 하여 1번째 피보나치수, 2번째 피보나치수, 3번째 피보나치수, ... , n번째 피보나치수를 구하는 문제로 나누어서 해결을 할 수 있다.

이 때 각 해당되는 i번째 피보나치 수를 기억을 해두는 메모이제이션(Memoization) 기법을 활용한다.

### bottom-up dynamic programming

리스트를 활용하여 아래에서부터 데이터를 쌓아 올라가는 방식으로 dp를 구현하는 방법이다.

```python
def fibonacci(n):
    li = [0,1,1]
    for i in range(3, n+1):
        li.append(li[i-1] + li[i-2])
    return li[n]
```

### top-down dynamic programming

재귀적으로 순환하며 데이터를 쌓아나가는 방식이다.

```python
li = [0,1,1]
def fibonacci(n):
    global li
    if len(li) >= n:
        return li[n]
    return fibonacci(n-1) +  fibonacci(n-2)
```

데이터가 이미 존재할 경우 재귀적으로 들어가지 않고 이미 있는 데이터를 꺼낸다.