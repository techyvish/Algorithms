//
//  RemoveSpaces.h
//  AlgorithmTutorials
//
//  Created by Vishal on 26/06/13.
//  Copyright (c) 2013 Vishal. All rights reserved.
//

#ifndef __AlgorithmTutorials__RemoveSpaces__
#define __AlgorithmTutorials__RemoveSpaces__

#include <iostream>
#include "TutorialBase.h"

class StringOperations : public TutorialBase {
public:
    
    void  removeSpaces(char *string);
    void  copy(char *source, char *dest);
    char * concatenate(char *strin1, char *string2);
    int strstr(char *string, char *str);
    void removeOccurancesOfString(char *string, char *str);
    char * findLongestEvenPelindrom(char *string);
    void reverseAndReplace(char *string , char *str , char* replaceWith );
    void decodeURL(char *str);
    bool isEqual(char *strSource , char *strDest ) ;
    bool isAnagram(char *str1, char *str2);
    virtual void run();
};

#endif /* defined(__AlgorithmTutorials__RemoveSpaces__) */
