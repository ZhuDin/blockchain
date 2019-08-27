dictionary = {'0':'9', '1':'8', '2':'7', '3':'6', '4':'5', '5':'4', '6':'3', '7':'2', '8':'1', '9':'0',
        'a':'A', 'b':'B', 'c':'C', 'd':'D', 'e':'E', 'f':'F', 'g':'G', 
        'h':'H', 'i':'I', 'j':'J', 'k':'K', 'l':'L', 'm':'M', 'n':'N',
        'o':'O', 'p':'P', 'q':'Q', 'r':'R', 's':'S', 't':'T', 
        'u':'U', 'v':'V', 'w':'W', 'x':'X', 'y':'Y', 'z':'Z',
        'A':'a', 'B':'b', 'C':'c', 'D':'d', 'E':'e', 'F':'f', 'G':'g',
        'H':'h', 'I':'i', 'J':'j', 'K':'k', 'L':'l', 'M':'m', 'N':'n',
        'O':'o', 'P':'p', 'Q':'q', 'R':'r', 'S':'s', 'T':'t', 
        'U':'u', 'V':'v', 'W':'w', 'X':'x', 'Y':'y', 'Z':'z'
        }

data = list(input())

data = data[::-1]

for num in range(len(data)):
    data[num] = dictionary[data[num]]

print(''.join(data))

