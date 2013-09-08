//
//  RemoveSpaces.cpp
//  AlgorithmTutorials
//
//  Created by Vishal on 26/06/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#include "StringOperations.h"

using namespace std;

void StringOperations :: removeSpaces(char *string) {
	if (string == NULL) return;
    
	int i  = 0;
	while (string[i] != '\0') {
		while (true) {
			if (string[i + 1] != '\0' && (string[i] == ' ' && string[i + 1] == ' ')) {
				int k = i;
				int j = i + 1;
				while (j != strlen(string))
					string[k++] = string[j++];
				string[k] = '\0';
			}
			else {
				break;
			}
		}
		i++;
	}
}

void StringOperations :: copy(char *source, char *dest) {
	dest = (char *)malloc(strlen(source) * sizeof(char));
	int i = 0;
	while (source[i] != '\0')
		dest[i++] = source[i++];
	dest[i] = '\0';
}

/*
 please delete generated string
 its allocated inside the function
 */

char *StringOperations :: concatenate(char *string1, char *string2) {
	char *newString = (char *)malloc(strlen(string1) * sizeof(char) + strlen(string2) * sizeof(char));
	memcpy(newString, string1, strlen(string1));
	memcpy(newString + strlen(string1), string2, strlen(string2));
	newString[strlen(string1) + strlen(string2)] = '\0';
	return newString;
}

int StringOperations :: strstr(char *string, char *str) {
	int i = 0, j = 0;
	while (string[i] != '\0') {
		if (string[i] == str[j]) {
			while (str[j] != '\0') {
				if (string[i] != str[j]) {
					break;
				}
				i++; j++;
			}
			if (str[j] == '\0') return 1;
			else j = 0;
		}
		i++;
	}
	return -1;
}

void StringOperations :: removeOccurancesOfString(char *string, char *str) {
	int i = 0, j = 0, temp = 0, occ = 0;
	while (string[i] != '\0') {
		j = 0;
		if (string[i] == str[j]) {
			temp = i;
			while (str[j] != '\0') {
				if (string[i] != str[j]) {
					break;
				}
				i++; j++;
			}
			if (str[j] == '\0') {
				int p = temp;
				int k = i;
				while (string[k] != '\0')
					string[p++] = string[k++];
				occ++;
			}
			else j = 0;
		}
		i++;
	}
	if (occ) {
		string[strlen(string) - (occ * strlen(str))] = '\0';
	}
}

char *StringOperations :: findLongestEvenPelindrom(char *string) {
	return 0;
}

//reverseReplace("I like cats", "cats", "dogs") -> "dogs like I"
//reverseReplace("I like cats", "mice", "cats") -> "cats like I"

void StringOperations :: reverseAndReplace(char *string, char *str, char *replaceWith) {
}

bool StringOperations :: isEqual(char *strSource, char *strDest) {
	int i = 0;
	while (i < 3) {
		if (strSource[i] != strDest[i])
			return false;
		i++;
	}
	return true;
}

void StringOperations :: decodeURL(char *str) {
	int i  = 0;
	while (str[i] != '\0') {
		char space[] = "%20";
		if (str[i] == '%' && isEqual(space, str + i)) {
			str[i] = 32;
			int j = i + 1;
			int k = i + 3;
			while (str[k] != '\0') {
				str[j++] = str[k++];
			}
			str[j] = '\0';
		}
		i++;
	}
}

int sortfunction(int i, int j) {
	return i < j;
}

bool StringOperations::isAnagram(char *str1, char *str2) {
	if (strlen(str1) != strlen(str2))
		return false;
    
	sort((str1 + 0), (str1 + strlen(str1)), sortfunction);
	sort((str2 + 0), (str2 + strlen(str2)), sortfunction);
    
	int i = 0;
	while (str1[i] != '\0') {
		if (str1[i] == str2[i])
			i++;
		else
			return false;
	}
	return true;
}

void StringOperations :: run() {
	//    char test[] = "This is         test of awesomeness. and ";
	//    StringOperations stringOp;
	//    cout << test << endl;
	//    stringOp.removeSpaces(test);
	//    cout << test << endl;
	//
	//    char *dest = NULL;
	//    stringOp.copy(test, dest);
	//    cout << test << endl;
	//
	//    char string2[] = "I'm Awesome";
	//    char *result = stringOp.concatenate(test,string2);
	//    cout << result << endl;
	//    free(result);
    
	//char s1[] = "ABCDEIIIIFGHIJKDIIIIEFkIIQQQIIII";
	//char s2[] = "IIII";
    
	//    if ( this->strstr(s1,s2) == 1){
	//        cout << "s2 is substring of s1" << endl;
	//    }
	//    else {
	//        cout << "s2 is not substring of s1" << endl;
	//    }
    
	//this->removeOccurancesOfString(s1, s2);
	//cout << s1 << endl;
    
    //    char t1[] = "kittne%20pic.jpg";
    //    decodeURL(t1);
    //    cout << t1 << endl;
    
	char str1[] = "BDCDEA";
	char str2[] = "ABCDDE";
	bool anagram = isAnagram(str1, str2);
}
