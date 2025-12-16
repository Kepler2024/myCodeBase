#ex 8.12
def sandwich(*ingredients):
    print(f'Your sandwich are made by:\n')
    for ingredient in ingredients:
        print(f'- {ingredient}')

sandwich('fuck','bitch')
sandwich('gg','ee','kk')