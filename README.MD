There's a C app and also now a Haskell app they will do the same.
Currently the Haskell version is a bit behind. I made it because it seems to be way easier to generalise the idea of neighborhood in Haskell from 3 points on top to something more interesting 

A shell app (C version) that prints all 256 cellular automatons with beautiful ASCII characters.

Compile like: 

        $ gcc main.c rule.c -o cell
        
Run it like:

        $ ./cell 22 33 100
        
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
