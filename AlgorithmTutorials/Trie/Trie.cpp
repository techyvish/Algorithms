//
//  Trie.cpp
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 16/07/2014.
//  Copyright (c) 2014 Vishal. All rights reserved.
//


#include <cstdio>

#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <unistd.h>
#include <climits>

using namespace std;
#define ALPHABET_SIZE 26

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct trie_node_t {
    int value;
    trie_node_t *children[ALPHABET_SIZE];
};

typedef struct trie_node_t trie_node;

class Trie {
    
    trie_node *root;
    int count;
    
public:
    Trie()
    {
        this->root = new trie_node();
    }
    trie_node *getNode()
    {
        Trie *trie = new Trie();
        if ( trie )
        {
            int i ;
            trie->root->value = 0;
            
            for ( i = 0 ; i < ALPHABET_SIZE ; i++ )
            {
                trie->root->children[i] = NULL;
            }
        }
        return trie->root;
    }
    
    void initialize()
    {
        this->root = getNode();
        this->count = 0;
    }
    
    void insert(const char key[])
    {
        int level = 0 ;
        unsigned long length = strlen(key);
        
        int index ;
        trie_node *pCrawl = NULL;
        
        this->count++;
        pCrawl = this->root;
        
        for ( level = 0 ; level < length ; level++ )
        {
            index = CHAR_TO_INDEX(key[level]);
            if( !pCrawl->children[index] )
            {
                pCrawl->children[index] = getNode();
            }
            pCrawl = pCrawl->children[index];
        }
          pCrawl->value = this->count;
    }
    
    int search( const char key[])
    {
        int level;
        unsigned long length = strlen(key);
        int index;
        trie_node_t *pCrawl;
        
        pCrawl = this->root;
        
        for( level = 0; level < length; level++ )
        {
            index = CHAR_TO_INDEX(key[level]);
            
            if( !pCrawl->children[index] )
            {
                return 0;
            }
            
            pCrawl = pCrawl->children[index];
        }
        
        return (0 != pCrawl && pCrawl->value);
    }
    
};

//int main()
//{
//    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
//    Trie trie;
//
//    char output[][32] = {"Not present in trie", "Present in trie"};
//
//    trie.initialize();
//
//    // Construct trie
//    for(int i = 0; i < ARRAY_SIZE(keys); i++)
//    {
//        trie.insert(keys[i]);
//    }
//
//    printf("%s --- %s\n", "the", output[trie.search((char *)"the")] );
//    printf("%s --- %s\n", "these", output[trie.search((char *)"these")] );
//    printf("%s --- %s\n", "their", output[trie.search((char *)"their")] );
//    printf("%s --- %s\n", "thaw", output[trie.search((char *)"thaw")] );
//    return 0;
//}