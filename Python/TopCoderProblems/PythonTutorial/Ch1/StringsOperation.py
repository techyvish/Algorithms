__author__ = 'Vishal'


def main():

    string1 = "this is a sample string is"
    print(string1.count("is"))
    print(string1.endswith("is"))
    print(string1.find("a"))
    print(string1.upper())
    print(string1.lower())
    print(string1.capitalize())
    print(string1.title())
    string1 = "           this is a sample string is               "
    print(string1.lstrip())
    print(string1.rstrip())
    print(string1.title())
    print(string1.zfill(10))

main()