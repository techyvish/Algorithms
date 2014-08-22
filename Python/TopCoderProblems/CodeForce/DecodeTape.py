__author__ = 'Vishal'

import binascii;

class DecodeTape:
    def decodeThisFile(self):
        finalstring = ""
        with open("sample.txt", "r") as f:
            while True:
                binstring = ""
                newstring = f.readline()
                if newstring.startswith("-"):
                    break
                for i in range(len(newstring)):
                    if newstring[i] == " ":
                        binstring += '0'
                    if newstring[i] == "o":
                        binstring += '1'
                finalstring += chr(int(binstring, 2))
        print(finalstring)

instance = DecodeTape()
instance.decodeThisFile();