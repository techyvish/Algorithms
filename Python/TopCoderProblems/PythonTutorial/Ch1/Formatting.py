__author__ = 'vishal'

import  math
import nltk
from nltk.book import  *

def main():
    print("{} is good number but {} is devine !!".format(1, math.pi))
    print("{:>10} is {:<10} years old".format("BILL", 25))

    for i in range(5):
        print("{:10d} ----> {:4d}".format(i, i*i))

    print("PI is {:.4f}".format(math.pi))
    print("PI is {:8.4f}".format(math.pi))
    print("PI is {:8.2f}".format(math.pi))

    str1 = "ABCDCBA"
    str2 = str1[::-1];
    if str1 == str2:
        print("Palindrom sring")

    nltk.download()

main();