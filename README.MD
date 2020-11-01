A shell app for UNIX-like environmets that prints all 256 cellular automatons with beautiful ASCII characters.

Compile main.c like:

        $gcc main.c -o cell
        
Run it like:

        $./cell 22 33 100
        
22 stands for rule 22. 
Generally it's any 8 bit unsigned int. 

33 is the number of rows of text output.
It's only limited by being 64 bit unsigned int.
Probably you want it to be super huge like in thousands.

100 is the length of a row in characters.
It's an 8 bit unsigned int. 
I generally use 200 on my laptop full screen with pretty small font.

Running as in the example you should a nice Serpinsky triangle.

A great short well-illustrated reference:

        https://mathworld.wolfram.com/ElementaryCellularAutomaton.html
