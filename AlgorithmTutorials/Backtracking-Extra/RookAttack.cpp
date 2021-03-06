//
//  RookAttack.m
//  AlgorithmTutorials
//
//  Created by Vishal Patel on 16/07/2014.
//  Copyright (c) 2014 Vishal. All rights reserved.
//

//
//        Problem Statement
//        You have been given a rows-by-cols chessboard, with a list of squares cut out. The list of cutouts will be given in a String[] cutouts. Each element of cutouts is a comma-delimited lists of coords. Each coord has the form (quotes for clarity) "r c". If coord "r c" appears in an element of cutouts, it means that the square at row r column c (0-based) has been removed from the chessboard. This problem will involve placing rooks on a chessboard, so that they cannot attack each other. For a rook to attack a target piece, it must share the same row or column as the target. Your method will return an int that will be the maximum number of rooks that can be placed on the chessboard, such that no pair of rooks can attack each other. Rooks cannot be placed on cut out squares. The cut out squares do not affect where the rooks can attack.
//
//        Definition
//
//        Class:	RookAttack
//        Method:	howMany
//        Parameters:	int, int, String[]
//        Returns:	int
//        Method signature:	int howMany(int rows, int cols, String[] cutouts)
//        (be sure your method is public)
//
//
//        Constraints
//        -	rows will be between 1 and 300 inclusive.
//        -	cols will be between 1 and 300 inclusive.
//        -	cutouts will contain between 0 and 50 elements inclusive.
//        -	Each element of cutouts will contain between 3 and 50 characters inclusive.
//        -	Each element of cutouts will be a comma delimited list of coords. Each coord will be of the form "r c", where
//        r and c are integers, with no extra leading zeros,
//        r is between 0 and rows-1 inclusive,
//        and c is between 0 and cols-1 inclusive.
//        -	Each element of cutouts will not contain leading or trailing spaces.
//
//        Examples
//        0)
//
//        8
//        8
//        {}
//        Returns: 8
//        ........
//        ........
//        ........
//        ........
//        ........
//        ........
//        ........
//        ........
//        1)
//
//        2
//        2
//        {"0 0","0 1","1 1","1 0"}
//        Returns: 0
//        XX
//        XX
//        2)
//
//        3
//        3
//        {"0 0","1 0","1 1","2 0","2 1","2 2"}
//        Returns: 2
//        X..
//        XX.
//        XXX
//        3)
//
//        3
//        3
//        {"0 0","1 2","2 2"}
//        Returns: 3
//        X..
//        ..X
//        ..X
//        4)

class RookAttack {
    
    
public:
    
    int howmany()
    {
        return 0;
    }
};
