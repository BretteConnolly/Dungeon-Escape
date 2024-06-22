What the program does:
-- A text-based choose your own adventure game in which the player chooses which room from a decision tree of rooms to go into next. When they reach the last room, they either die or live (lose or win). 

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

What the program entails:
-- An object-oriented design with instances of class Room. Every Room has the following data members: a room ID, a description, a left pointer, a right pointer, and a game status (keep playing, lose, or win). 
-- A linked list structure to move from one Room to the next
-- A two-dimensional array that stores information that is later applied to dynamic Room instances on the heap
-- Deletion of the Rooms after the end of the game to prevent memory leak

Further applications:
-- More rooms and more directions 

Sample output:
Welcome to room A1
You are in a dark cave with only your wits to guide you...
Left or right? left

Welcome to room B1
You are standing in a shallow stream with glowing eels circling your heels. 
 A breeze is coming from the left, but it smells horrible...
Left or right? left

Welcome to room C1
The ceiling here glows near the right exit.  It is beautiful, but something in the right tunnel is moving. CLOSER...
Left or right? left

You see an opening. A possible escape?? Nooooo - the floor falls away into a dark abyss. 
 As your foot loses its grip, you wonder..should I perhaps have turned right?...
Sorry, you lost.
Goodbye 
