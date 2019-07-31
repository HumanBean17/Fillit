# Fillit
Can you feel it?

My program take a file as parameter, which contains a list of Tetriminos, and arrange them in order to create the smallest square possible.

To complete this, i used simple recursive search algorithm with some optimisations. For example I don't send map (field with tetraminos) as argument each time i want to try set new tetramino. I save coordinates and map as a static variables. I also use only one function which puts or swaps tetramino.
As a result my program correctly searchs the smallest square with 26 hardest tetraminos (26 squares) less than 1 second.

Usage:
1. Make
2. ./fillit filename

File with tetraminos example:

...#
...#
...#
...#

####
....
....
....

##..
.##.
....
....

..##
..##
....
....\n
