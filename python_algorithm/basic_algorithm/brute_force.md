# 브루트포스 알고리즘 (brute force search algorithm)

## 1. 정의

모든 경우의 수를 완전히 탐색하는 알고리즘 기법

가능한 모든 경우의 수를 하나씩 대입하면서 문제를 해결한다.

## 2. 예시와 구현

숫자 n의 약수를 모두 구하는 함수를 구현해보자

```python
def divisor(n):
    result = []
    for i in range(1,n+1):
        if n % i == 0:
            result.append(i)
    return result
```

1부터 n까지 모든 수를 하나씩 대입해보면서 약수인지 아닌지를 판별하여 해결한다.
