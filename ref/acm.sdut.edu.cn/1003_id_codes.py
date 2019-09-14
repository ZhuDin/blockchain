while(1):
    data = input()
    if(data == '#'):
        break
    
    if(data == ''.join(sorted(data)[::-1])):
        print('No Successor')
        continue
    '''
    example:
    string = 'abaacb' 
    ------------------
    #1 from right to left find two consecutive letters: small and large
    (small < large) (small on the left)
    'aba<ac>b'
    'small'=a | large='c' 
    ------------------
    #2 from right to left find the replace letters large than small
    'abaac<b>'
    replace = b
    ------------------
    #3 exchange the small and replace
    'aba<b>c<a>'
    ------------------
    #4 sorted string[large:] get the next_permutation
    'abab<ca>' sorted<ca> ==> 'ababac'
    '''

    string = list(data[::-1])
    length = len(string)
    small = ''
    large = ''
    replace = ''
    result = ''
    label = length - 1
    
    for char in string[1:]:
        # 1
        if ord(char) < ord(data[label]):
            small = char
            large = data[label]
            #print('#1 small:' + small + ' large:' + large)
            # 2
            for temp in data[::-1]:
                if ord(temp) > ord(small):
                    replace = temp
                    break
            #print('#2 replace:' + replace)
            break
        label -= 1

    # 3
    string[length-label] = str(replace)
    result += ''.join(string[length-label:][::-1])
    string[string.index(replace)] = small
    #print('#3 ' + result)

    # 4
    result += ''.join(sorted(string[:length-label]))
    #print('#4 ' + result)

    print(result)
