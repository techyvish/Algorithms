__author__ = 'Vishal'

def main():
    dict = {"Salam namaste": 2006,
            "Superman returns": 2011,
            "Tu khiladi main anadi": 1996}

    print(dict["Salam namaste"])
    print(dict["Superman returns"])
    print(dict["Tu khiladi main anadi"])

    dict["Salam namaste"] = 2007

    print(dict["Salam namaste"])
    print(dict["Superman returns"])
    print(dict["Tu khiladi main anadi"])
    print(dict.get("Salam namaste"))
    print(dict.keys())
    print(dict.values())
    print(dict.items())
    #print(dict.has_key("Superman returns"))

main()