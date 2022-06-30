#include <iostream>
#include <string>
using namespace std;

class Room 
{
  public:
    string roomId = "XX"; // data member which holds the id of the room
    string description = "none"; // data member which holds the description of the room (to be printed when the player enters)
    Room * left = nullptr;  // data member which holds a pointer to the room to our left, or nullptr if there is none
    Room * right = nullptr ;  // data member which holds a pointer to the room to our right, or nullptr if there is none
    string gameStatus = "lose"; // string that describes the status of the game once we enter this room: "keep playing", "win", or "lose"

    Room (string _id, string _desc, string _gameStatus )
  {
      // TODO: initialize all corresponding members from the arguments passed into your constructor
  } 

  void printMe()
  { //this method should be called from within your while loop
    cout << endl << "Welcome to room " << roomId << endl; 
    // TODO : print the description string for this room on a single line   
  } 
}; // end class

int main() 
{
  // DONE FOR YOU (below)
  // roomInfo is a 2D array with 13 rows and 3 columns
  //     each row stores a description of a room that we must put into a new instance of the Room class
  //     there are 13 rooms (one per row), each labled A1, B2, C1, C2, etc. 
  // each room is described by 3 string values corresponding to each column of the 2D array, where:
  //     the 1st column is the roomId string of the room
  //     the 2nd column is the description of the room that should be printed when you enter the room
  //     and the 3rd column is the game status that indicates if the game is over, and if so, if it was won or lost
  
  string roomInfo[13][3] = { 

    { "A1" , "You are in a dark cave with only your wits to guide you...", "keep playing" } ,
    { "B1" ,  "You are standing in a shallow stream with glowing eels circling your heels. \n A breeze is coming from the left, but it smells horrible...", "keep playing" } ,
    { "B2" ,  "You suddenly feel intense hunger.  There's a skeleton here with a note.  It says \'Avoid the Fish on Tuesdays\'...", "keep playing" } ,
    { "C1" ,  "The ceiling here glows near the right exit.  It is beautiful, but something in the right tunnel is moving. CLOSER...", "keep playing" } ,
    { "C2" ,  "There's a smell of sulfur here. And a distant booming drum beat. But which tunnel is it coming from?...", "keep playing" } ,
    { "C3" ,  "A dark pool lies in the center of the cave.  As you aim your lantern into its depths, a giant tentacle wraps around your leg and pulls you down...\nYou have DIED.", "lose" } ,
    { "C4" ,  "You have entered a slanted room.  The floor tilts down to the left.  As if the cave WANTS you to go that way...", "keep playing" } ,
    { "D1" ,  "You see an opening. A possible escape?? Nooooo - the floor falls away into a dark abyss. \n As your foot loses its grip, you wonder..should I perhaps have turned right?...", "lose" } ,
    { "D2" , "Your tour guide emerges from the shadows, angry because the bus was supposed to leave 10 minutes ago... \n You are SAVED!", "win" } ,
    { "D3" , "Orcs!!!!  You try to turn back, but they have blocked your escape.  At least you will not have to turn in your next assignment...\n You have DIED.", "lose" } ,
    { "D4" ,  "The source of the booming reveals itself.  A cave troll beats its club against the wall and the ceiling above you collapses on your head.  If only you had worn that helmet...\n You have DIED.", "lose" } ,
    //# there is no room D5
    //# there is no room D6
    { "D7" ,  "You slip onto a water slide that catapults out of the caverns to a sunlit river below.... \n You are SAVED!", "win" } ,
    { "D8" ,  "You have climbed into a chamber of vampire bats.  You should have listened to the cave...\n You have DIED.", "lose" } 

  };

  // Create new "Room" instances on the heap.  
  //   Store the pointer (address) for each new room in a variable called A1, B1, B2, etc. for all rooms

  // The first 3 rooms are done for you below:
  Room * A1 = new Room( roomInfo[0][0], roomInfo[0][1], roomInfo[0][2] ); // DONE: construct a new room on the heap and store its pointer in A1
  Room * B1 = new Room( roomInfo[1][0], roomInfo[1][1], roomInfo[1][2]); // DONE: construct a new room on the heap and store its pointer in B1
  Room * B2 = new Room( roomInfo[2][0], roomInfo[2][1], roomInfo[2][2]); // DONE: construct a new room on the heap and store its pointer in B2

  // TODO : Finish constructing new rooms C1, C2, C3, C4, D1, D2, D3, D4, D7, D8 below (there is no room D5 or D6)
  
  
  // Connect the left and right pointers of each room to its corresponding room pointer, as shown below:
    // use the map displayed in the README.md file as your guide

  // The first 3 rooms are connected for you
  A1->left = B1; // DONE: connect the "left" pointer of A1 to B1
  A1->right = B2; // DONE: connectthe "right" pointer of A1 to B2

  // TODO : Finish connecting rooms C1, C2, C3, C4, D1, D2, D3, D4, D7, D8 below (there is no room D5 or D6)

  
  // Now your "Dungeon" has been created and you are ready to play

  // TODO: create a currentRoom pointer variable and set it to nullptr
  
  // TODO: set the currentRoom pointer to point to the A1 Room instance you created above.  
  // TODO: print a descrption of the current room by calling its printMe() method
  
  // TODO: create a string variable that can be used to collect a user response


  // TODO: create a while loop that continues as long as the current room pointer is not nullptr AND the current room game status string is "keep playing"

  // Within your while loop:
      // TODO: prompt the user to go either left or right
      // TODO: collect the user response in a string variable

      // TODO: if the response is "left", advance the current room pointer to the room on the left
      // TODO: else if the response is "right", advance the current room to the room on the right
      // TODO: else print a warning message indicating that the user provided bad input

      // TODO: if the current room pointer is null or the  current room game status  is  "win" or "lose", break out of the loop (game is over)

      // TODO: print a description of the current room at the bottom of the while loop using the current room pointer

  // END OF WHILE LOOP


  // TODO: if the current room pointer is nullptr after your while loop, print an Error message explaining that the room pointer is somehow null - 
  //    this indicates your rooms were not connected correctly or your while loop has a bug
  //    

  // TODO: else you should print a description of the current room using the printMe() method


  // TODO: if the current room is not nullptr and if the game status of the current room is "win", print a congratulatory "winning" message
  // TODO: else if the current room pointer is not null, print a losing message

  // TODO: print a Goodbye message

  // TODO: delete all the Rooms on the heap so we do not have a memory leak!

}
