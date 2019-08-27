for col in range(7):
    print(' ' * abs(7//2-col), end='')
    print('*' * (7-abs(7//2-col)*2))
