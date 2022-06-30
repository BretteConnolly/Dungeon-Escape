#include <iostream>
#include <string>

using namespace std;

class Room {

  public:
    string roomId = "XX"; // data member which holds the id of the room
    string description = "none"; // data member which holds the description of the room (to be printed when the player enters)
    Room * left = nullptr;  // data member which holds a pointer to the room to our left, or nullptr if there is none
    Room * right = nullptr ;  // data member which holds a pointer to the room to our right, or nullptr if there is none
    string gameStatus = "lose"; // string that describes the status of the game once we enter this room: "keep playing", "win", or "lose"

    Room ( string _id, string _desc, string _gameStatus ){
      // TODO: initialize all corresponding members from the arguments passed into your constructor
      roomId = _id; 
      description = _desc; 
      gameStatus = _gameStatus;
    } // end consructor

  void printMe(){ // DONE FOR YOU:  this method should be called from within your while loop
    cout << endl << "Welcome to room " << roomId << endl;
    cout << description << endl; 
  } // end printMe() method

}; // end class

int main() {

  // roomInfo is a 2D array with 13 rows and 3 columns
  //     each room stores a description of a room that we must put into a new instance of the Room class
  //     there are 13 rooms (one per row), each labled A1, B2, C1, C2, etc. (Please see the README.md file)
  // each room is described by 3 string values corresponding to each column of the 2D array
  //     where the 1st column is the ID string of the room
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
    { "D8" ,  "You have been climbed into a chamber of vampire bats.  You should have listened to the cave...\n You have DIED.", "lose" } 

  };

  // TODO: create new rooms as new "Room" instances on the heap.  
  //   Store the pointer (address) for each new room in a variable called A1_ptr, B1_ptr, B2_ptr, etc. for all rooms

  // The first 3 rooms are done for you below:
  Room * A1_ptr = new Room( roomInfo[0][0], roomInfo[0][1], roomInfo[0][2] ); // construct a new room on the heap and store its pointer in A1_ptr
  
  Room * B1_ptr = new Room( roomInfo[1][0], roomInfo[1][1], roomInfo[1][2]); // construct a new room on the heap and store its pointer in B1_ptr
  Room * B2_ptr = new Room( roomInfo[2][0], roomInfo[2][1], roomInfo[2][2]); // construct a new room on the heap and store its pointer in B2_ptr

  // TODO: Finish constructing rooms C1, C2, C3, C4, D1, D2, D3, D4, D7, D8 below (there is no room D5 or D6)
  
  Room * C1_ptr = new Room( roomInfo[3][0], roomInfo[3][1], roomInfo[3][2]);
  Room * C2_ptr = new Room( roomInfo[4][0], roomInfo[4][1], roomInfo[4][2]);
  Room * C3_ptr = new Room( roomInfo[5][0], roomInfo[5][1], roomInfo[5][2]);
  Room * C4_ptr = new Room( roomInfo[6][0], roomInfo[6][1], roomInfo[6][2]);

  Room * D1_ptr = new Room( roomInfo[7][0], roomInfo[7][1], roomInfo[7][2]);
  Room * D2_ptr = new Room( roomInfo[8][0], roomInfo[8][1], roomInfo[8][2]);
  Room * D3_ptr = new Room( roomInfo[9][0], roomInfo[9][1], roomInfo[9][2]);
  Room * D4_ptr = new Room( roomInfo[10][0], roomInfo[10][1], roomInfo[10][2]);

  Room * D7_ptr = new Room( roomInfo[11][0], roomInfo[11][1], roomInfo[11][2]);
  Room * D8_ptr = new Room( roomInfo[12][0], roomInfo[12][1], roomInfo[12][2]);
  
  // TODO: Connect the left and right pointers of each room to its corresponding room pointer, as shown below:
  // use the map displayed in the README.md file as your guide

  
  // The first 3 rooms are connected for you
  A1_ptr->left = B1_ptr; // connect the "left" pointer of A1 to B1
  A1_ptr->right = B2_ptr; // connectthe "right" pointer of A1 to B2

  // TODO: Finish connecting rooms C1, C2, C3, C4, D1, D2, D3, D4, D7, D8 below (there is no room D5 or D6)

  B1_ptr->left = C1_ptr; // Connect the "left" pointer of B1 to C1
  B1_ptr->right = C2_ptr; // Connect the "right" pointer of B1 to C2
  B2_ptr->left = C3_ptr;
  B2_ptr->right = C4_ptr;

  C1_ptr->left = D1_ptr; // Connect the "left" pointer of B1 to C1
  C1_ptr->right = D2_ptr; // Connect the "right" pointer of B1 to C2
  C2_ptr->left = D3_ptr;
  C2_ptr->right = D4_ptr;

  C4_ptr->left = D7_ptr;
  C4_ptr->right = D8_ptr;
  
 // Now your "Dungeon"has been created and you are ready to play

  Room * currentRoom = nullptr; // currentRoom is "temp" pointer we will use to keep track of which room we are in
  
  currentRoom = A1_ptr; // TODO: set the currentRoom pointer to point to the A1 Room instance you created above.  
  currentRoom->printMe(); // TODO: print a descrption of the current room by calling its printMe() method
  
  string userResponse; // TODO: create a string variable that can be used to collect a user response


  while( currentRoom != nullptr && currentRoom->gameStatus == "keep playing" ){ // TODO: create a while loop that continues as long as the current room pointer is not nullptr AND the current room game status string is "keep playing"
     
    cout << endl << "Which way would you like to go, left or right? "; // TODO: prompt the user to go either left or right
    cin >> userResponse;    // TODO: collect the user response in a string variable

    if (userResponse == "left")   // TODO: if the response is "left", advance the current room pointer to the room on the left
      currentRoom = currentRoom->left;
      
    else if (userResponse == "right") // TODO: if the response is "right", advance the current room to the room on the right
      currentRoom = currentRoom->right;
      
    else  // TODO: else print a warning message indicating that the user provided bad input
      cout << "I do not understand... Please try again..." << endl;

    // TODO: print a description of the current room at the botoom of the while loop using the current room pointer
    currentRoom->printMe();
    
    // // TODO: after advancing to either the left or right room test to room pointer to be sure it is not nullptr... if it is print a warning (because may crash)
    // if (currentRoom == nullptr ) {
    //   cout << "oops.. something bad happend... the current room pointer has become null... please check your room left and right connections" << endl;
    //   exit(1); // quit the program
    // }
  } // end of while loop

  // END OF WHILE LOOP


  // TODO: if the current room pointer is nullptr, print an Error message explaining that the room pointer is somehow null - 
  //    this indicates your rooms were not connected correctly or your while loop has a bug
  //    

  if ( currentRoom == nullptr ) {
    cout << "Something must be wrong.. the current room pointer is null!" << endl;
  }

  // TODO: else you should print a description of the current room using the printMe() method


  if (currentRoom && currentRoom->gameStatus == "win")  // TODO: if the current room is not nullptr and if the game status of the current room is "win", print a congratulatory "winning" message
      cout << "You win!" << endl;
  else if (currentRoom )
      cout << "Sorry - you lost :( " << endl; // TODO: else if the current room pointer is not null, print a losing message 
}