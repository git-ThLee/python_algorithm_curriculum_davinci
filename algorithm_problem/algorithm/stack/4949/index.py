while True:
    string = input()
    if string == '.':
        break
    
    stack = []
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