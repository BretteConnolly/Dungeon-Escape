# Overview
Recall the solution to your first homework assignent from this semester: "Dungeon Escape". (You will NOT be using if-elif-else trees for this assignment. )

Write an Object-Oriented version of your program using a "Room" class to describe each room, and connect the rooms together using their left and right data members (pointers to other Rooms)

You will use a while loop in main() that sets the currentRoom variable to either the currentRoom.left or currentRoom.right, based on the user's "left" or "right" input from "cin".

Your Game should behave as in our original assignment: it should allow a player to travel through a Dungeon by entering  "left" or "right" at each room that is visited.  Based on the user input (left or right), a progression of room "descriptions" should be printed, until the user either wins (escapes) or loses (is lost in the dungeon forever).

# Details
In main(), you will need to create instances of the Room class for each room in the game.  You will call the Room class constructor to initialize the ID and description of each room based on the information provided.

You will then need to connect the left and right data members of each instance of each room to its approapriate room on the map.

The connection of the rooms will represent a "decision tree" that will guide your movement through the dungeon.  The room descriptions and connectivity of the rooms is provided for you in the starting code sample associated with this assignment.

# The Room Class

Your Room class's constructor should initialize the following data members, named exactly as shown below:

- roomId  : The id of the room (A1, B1, B2, etc.)
- description  : A string description of the room "You have entered a glowing room"
- right  : A pointer to a room on the right, or nullptr if there is no room on the right
- left : A pointer to a room on the left, or nullptr if there is no room on the left
- gameStatus : A string describing what happens when you enter the room: "keep playing", "lose, or "win"


Your Room class supports a single method named printMe() 
- Your printMe() method will print the Room's id and its description of the current room (it will not return anything)


# The Map
You will start in "room A1" and progress through a collection of connected rooms based on the decision tree shown below:

Your decision tree should follow this pattern

```

              Room A1 
         "left"     "right"
          /               \
        B1                  B2
      /    \              /    \
   C1        C2        C3L        C4
  /   \     /  \                 /  \
D1L  D2W  D3L  D4L             D7W   D8L
```

# Where
- A1 is the room where you start
- B1 is the room you enter if you go left, else B2 if you go right (etc).
- L attached to a room name above like D1L represents a room where you "lose" the Game (die)
- W attached to a room name like D2W represents a room where you "win" the game
- Every "leaf" in your decision tree will result in either a Loss (L) or a win (W)
- You do not win or die until you reach a leaf node


Also:
Notice that your tree is not "symmetric" - Room C3L is a "dead end" leaf.
You should print string variables for each room description, when you enter the room.
You should use the same prompt string each time you ask the user for directions after describing the room they entered.



# ROOM DATA
  Room data is stored in a 2D array with 13 rows and 3 columns
  - Each room stores a description of a room that we must put into a new instance of the Room class
  - There are 13 rooms (one per row), each labled A1, B2, C1, C2, etc. (Please see the README.md file)
    
  Each room is described by 3 string values corresponding to each column of the 2D array
    - Where the 1st column is the ID string of the room
    - The 2nd column is the description of the room that should be printed when you enter the room
    - And the 3rd column is the game status that indicates if the game is over, and if so, if it was won or lost

see main.cpp for a complete descriptoin of this 2D array


# SAMPLE OUTPUT
```
Dungeon Escape

Welcome to room A1 .
 You are in a dark cave with only your wits to guide you...
 Which way would you like to go? left or right? left
 You chose left...

Welcome to room B1 .
 You are standing in a shallow stream with glowing eels circling your heels. 
 A breeze is coming from the left, but it smells horrible...
 Which way would you like to go? left or right? right
 You chose right...

Welcome to room C2 .
 There's a smell of sulfur here. And a distant booming drum beat. But which tunnel is it coming from?...
 Which way would you like to go? left or right? left
 You chose left...
Sorry - You have lost.  Better luck next time.

Game Over

```

# HINTS
You can assume that "left" takes you to the left based on the tree shown above ("left" from A1 takes you to B1)
There are only 7 ways to travel through the dungeon - you should test all of them

