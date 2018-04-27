// Problem 1

The program reads in the paragraph using getline. To find the least frequent letter it uses for loops to 
iterate through the string. It counts how many times a selected letter shows up. If it has the least count, the data
is stored. it then loops until it reaches the end of the string. The smallest 'count' is now found and now it will
start to print every letter that matches the minimum count.

Word frequency uses the same idea but with arrays/vectors. Using string stream, the inputted string is stored
in a string vector. The strings are now then being compared. When a current string matches another string, the count
for that string goes up and the matched string is destroyed/erased to prevent copies. Once it iterates through once, the 
current string is stored into a struct vector that will store the string's name and count. This will loop until every unique
word is examined and no copies of same string are left. 

It is then printed and will at the same time find the most frequent word, which will then be printed after.



// Problem 2

Using getline and string stream, the inputted numbers are stored into a vector and a vector copy. 
The numbers are then sorted using nested for loops. Numbers are compared until the smallest number is found. 
When it's found and the nested loop reaches the end of a single iteration, the smallest number is pushed back 
into another vector (which will be the sorted vector) and the number will be destroyed in the original vector.
This repeats until fully sorted. The sorted vector and copy of the original vector are then printed using for loops.