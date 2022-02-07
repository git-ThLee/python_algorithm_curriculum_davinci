## 4949번: 균형잡힌 세상

스택은 가장 나중에 들어온 값이 가장 먼저 나가는 **LIFO**의 특징을 가지고 있다.

스택문제들은 모두 해당 특성을 어떻게 활용할 것인가이다.

대표적인 문제가 괄호를 짝짓는 문제들인데 괄호는 마지막에 열린 괄호가 가장 먼저들어온 닫는 괄호와 짝지어지기 때문에

여는 괄호가 나올 때 스택에 PUSH, 닫는 괄호가 나올 때 스택에서 POP을 하면 알맞게 짝지어져 있는지 판별할 수 있다.


### 코드

```python
    result = True
    for i in string:
        if i == '(':
            stack.append('(')
        elif i == '[':
            stack.append('[')
        elif i == ')':
            if len(stack) == 0:
                result = False
                break
            elif stack[len(stack)-1] == '[':
                result = False
                break
            else:
                stack.pop()
        elif i == ']':
            if len(stack) == 0:
                result = False
                break
            elif stack[len(stack) - 1] == '(':
                result = False
                break
            else:
                stack.pop()
    if result == False or len(stack) != 0:
        print('no')
    else:
        print('yes')
```
해당 문제의 메인이 되는 코드이다. 문자열을 탐색하면서 다른 문자열들은 상관없이 괄호를 중점적으로 봐준다.

```python
        if i == '(':
            stack.append('(')
        elif i == '[':
            stack.append('[')
```
여는 괄호가 나왔을 때는 다른 경우와 상관없이 stack에 push 해준다. 괄호가 맞는 괄호인지 판별은 닫는 괄호가 나왔을 때 진행한다.

```python
        elif i == ')':
            if len(stack) == 0:
                result = False
                break
            elif stack[len(stack)-1] == '[':
                result = False
                break
            else:
                stack.pop()
```
닫는 괄호가 나왔을 때 스택이 비어 있다면 남아있는 여는 괄호가 없다는 뜻이므로 짝이 지어지지 않는다.

stack의 top이 맞지 않는 괄호라면 해당 괄호와 짝지어지는 괄호인데 맞지 않으므로 잘못된 괄호이다.

다른 경우에는 짝지어지는 여는 괄호를 스택에서 pop해준다.

```python
    if result == False or len(stack) != 0:
        print('no')
    else:
        print('yes')
```
모든 문자열을 검토했을 때, 스택이 비어있지 않다면 여는 괄호가 짝지어지지 않고 남아있다는 뜻이므로 잘못된 괄호이다.