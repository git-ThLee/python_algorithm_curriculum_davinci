# 그리디 알고리즘(Greedy Algorithm)

## 1. 정의

매 순간 최적인 답을 선택하여 문제를 해결하는 알고리즘 기법. 탐욕 알고리즘이라고도 한다.

## 2. 예시와 구현

1원 10원 50원 100원 500원짜리 동전이 있고 n원을 최소한의 동전으로 바꿀 때 동전의 개수를 구하고자 한다.

```python
def coin(n):
    result = 0
    coin_kind = [500, 100, 50, 10, 1]
    for i in coin_kind:
        result += n // i
        n = n % i
    return result
```

매번 환전할 수 있는 가장 큰 단위로 환전을 하면 동전의 최소개수를 구할 수 있다.