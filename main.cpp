#include <iostream>
#include <string>
using namespace std;

class Room 
{
  public:
    string roomId = "XX"; // data member which holds the id of the room
    string description = "none"; // data member which holds the description of the room (to be printed when the player enters)
    Room* left = nullptr;  // data member which holds a pointer to the room to our left, or nullptr if there is none
    Room* right = nullptr ;  // data member which holds a pointer to the room to our right, or nullptr if there is none
    string gameStatus = "lose"; // string that describes the status of the game once we enter this room: "keep playing", "win", or "lose"

    Room (string _id, string _desc, string _gameStatus )
  {
    roomId = _id;
    description = _desc;
    gameStatus = _gameStatus;
  } 

  // void printMe(Room currentRoom)
  // { //this method should be called from within your while loop
  //   cout << endl << "Welcome to room " << currentRoom.roomId << endl; 
  //   // TODO : print the description string for this room on a single line 
  //   cout << currentRoom.description << endl;
  // } 
}; 

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
  
  string roomInfo[13][3] = 
{ 
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
  Room* A1 = new Room( roomInfo[0][0], roomInfo[0][1], roomInfo[0][2] ); // DONE: construct a new room on the heap and store its pointer in A1
  Room* B1 = new Room( roomInfo[1][0], roomInfo[1][1], roomInfo[1][2]); // DONE: construct a new room on the heap and store its pointer in B1
  Room* B2 = new Room( roomInfo[2][0], roomInfo[2][1], roomInfo[2][2]); // DONE: construct a new room on the heap and store its pointer in B2
  Room* C1 = new Room( roomInfo[3][0], roomInfo[3][1], roomInfo[3][2]);
  Room* C2 = new Room( roomInfo[4][0], roomInfo[4][1], roomInfo[4][2]);
  Room* C3 = new Room( roomInfo[5][0], roomInfo[5][1], roomInfo[5][2]);
  Room* C4 = new Room( roomInfo[6][0], roomInfo[6][1], roomInfo[6][2]);
  Room* D1 = new Room( roomInfo[7][0], roomInfo[7][1], roomInfo[7][2]);
  Room* D2 = new Room( roomInfo[8][0], roomInfo[8][1], roomInfo[8][2]);
  Room* D3 = new Room( roomInfo[9][0], roomInfo[9][1], roomInfo[9][2]);
  Room* D4 = new Room( roomInfo[10][0], roomInfo[10][1], roomInfo[10][2]);
  Room* D7 = new Room( roomInfo[11][0], roomInfo[11][1], roomInfo[11][2]);
  Room* D8 = new Room( roomInfo[12][0], roomInfo[12][1], roomInfo[12][2]);
  
  
  // Connect the left and right pointers of each room to its corresponding room pointer, as shown below:

  A1->left = B1; 
  A1->right = B2; 
  B1->left = C1;
  B1->right = C2;
  B2->left = C3;
  B2->right = C4;
  C1->left = D1;
  C1->right = D2;
  C2->left = D3;
  C2->right = D4;
  C4->left = D7;
  C4->right = D8;

  // TODO: create a currentRoom pointer variable and set it to nullptr
  Room* currentRoom = nullptr;
  
  // TODO: set the currentRoom pointer to point to the A1 Room instance you created above.  
  currentRoom = A1; 
  // TODO: print a descrption of the current room by calling its printMe() method
  // currentRoom->printMe(currentRoom);
  
  // TODO: create a string variable that can be used to collect a user response
  string choice;

  // TODO: create a while loop that continues as long as the current room pointer is not nullptr AND the current room game status string is "keep playing"
  while (currentRoom != nullptr && currentRoom->gameStatus == "keep playing")
    {
      cout << "Welcome to room " << currentRoom->roomId << endl;
      cout << currentRoom->description << endl;
      cout << "Left or right? ";
      cin >> choice;
      if (choice == "left")
        currentRoom = currentRoom->left;
      else if (choice == "right")
        currentRoom = currentRoom->right;
      else
        cout << "Incompatible input"; 
      if (currentRoom == nullptr || currentRoom->gameStatus == "win" || currentRoom->gameStatus == "lose")
        break;
    }

  if (currentRoom == nullptr)
    cout << "Error: room pointer is somehow null" << endl;
  else
  {
   // currentRoom->printMe(currentRoom);
   if (currentRoom->gameStatus == "win")
   {
     cout << currentRoom->description << endl;
     cout << "Yay! You won!" << endl;
  }  
   else
   {
    cout << currentRoom->description << endl;
    cout << "Sorry, you lost." << endl;
   }
  }
  cout << "Goodbye";

  delete A1;
  delete B1;
  delete B2;
  delete C1;
  delete C2;
  delete C3;
  delete C4;
  delete D1;
  delete D2;
  delete D3;
  delete D4;
  delete D7;
  delete D8;
}