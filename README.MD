A shell app that prints all 256 cellular automatons with beautiful ASCII characters.
Implemented originaly in C because it has awesome bitwise features. 
Later also in Haskell because I don't know it and because apperently it's awesome. 
It seems like it's going to be very convenient for generalisin neighborhood when I get better at it.

C version - compile like: 

        $ gcc main.c rule.c -o cell
        
Run it like:

        $ ./cell 22 33 100
        
   
Haskell version - can be run with:

        $ runhaskell 22 33 100

22 stands for rule 22. 
Generally it's any 8 bit unsigned int. 

33 is the number of rows of text output.
It's only limited by being 64 bit unsigned int.
Probably you want it to be super huge like in thousands.

100 is the length of a row in characters.
It's an 8 bit unsigned int. 
I generally use 200 on my laptop full screen with pretty small font.

Running as in the example you should see a nice Serpinsky triangle.

A great short well-illustrated reference I used:

        https://mathworld.wolfram.com/ElementaryCellularAutomaton.html
