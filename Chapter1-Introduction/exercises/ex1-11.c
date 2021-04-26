/**
 * Exercice 1.11 
 * 
 *  How would you test the word count program ? What kinds of input are most
 * likely to uncover bugs if there are any ?
 * 
 **/

/*
I:
    1. no input             -> nl = 0, nw = 0, nc = 0
    2. fdsqfq               -> nl = 0, nw = 1, nc = 7
    3. fsfqsf fqsfsqf\n     -> nl = 1, nw = 2, nc = 15

II:
    - no input
    - no word
    - no blaks or tabs
*/