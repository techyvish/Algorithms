__author__ = 'vishal'

import string

def main():
    string1 = "bannana"
    print(string1[:3])
    print(string1[3:len(string1)])
    print(string1[3:])


    greetings = "Hello World" # immutable string
    # greetings[0] = 'j' #error
    newGreetings = 'j' + greetings[1:]
    print(newGreetings)

    fruit = "banana"
    count = 0
    for char in fruit:
        if char == 'a':
            count = count + 1

    print(count)

    index = fruit.find('a')
    print(index)


main()