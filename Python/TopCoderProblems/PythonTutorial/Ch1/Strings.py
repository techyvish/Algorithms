__author__ = 'vishal'

import string,itertools


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

    hello_word = "Hello World"
    print(hello_word[-1])
    print(hello_word[3:-2])
    print(hello_word[::2])

    digits = "0123456789"
    print(digits[::2])
    print(digits[1::2])
    print(digits[::-2])
    print(digits[-2::-2])

    name_one = "Monty Sonty"
    name_two = name_one[:]
    print(name_two)

    for ch in "This is a string test":
        print(ch, type(ch))

    if 'a' in 'aeiou':
        print("Yes it is")
    else:
        print("No its not")

    my_str = "Mellow Yellow"
    print(my_str.find('M'))
    print(my_str.find("Y"))
    print(my_str.find("Z"))



main()