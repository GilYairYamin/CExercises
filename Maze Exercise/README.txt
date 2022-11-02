This is my answer to the question:

You are trapped in a deadly escape room and have to navigate your way out.
You start at the 'starting points' (see below), have to find the key, and then you can search for the exit. You can only move left, right, up or down (no diagonal steps).
Write a function that gets a 'room' parameter and returns true if you can escape the room and false otherwise.
The 'room' parameter is an array of characters, each represents a different element:
'o' - represents an open passage.
'x' - represents a wall.
's' - represents the starting point.
'e' - represents the ending point.
'k' - represents the key.

Note, not all escape rooms are fair. In some you might not even have a key!
Examples:
Input: [ ['s', 'o', 'o', 'k', 'o'], ['x', 'x', 'x', 'o', 'x'], ['e', 'o', 'o', 'o', 'x'] ]
Output: true
Input: [ ['s', 'o', 'o', 'k', 'o'], ['x', 'x', 'x', 'o', 'x'], ['e', 'x', 'o', 'o', 'x'] ]
Output: false

Stack.c:
An implemented stack that keeps the last "row : collumn" pair.

maze.c:
The file where I implemented the algorithm itself.
The function is called "findPath".

main.c:
The main file with the main function that creates a maze and prints the result of the function findPath.