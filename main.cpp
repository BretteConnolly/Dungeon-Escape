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
 } 
}; 

int main() 
{
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

  Room* A1 = new Room( roomInfo[0][0], roomInfo[0][1], roomInfo[0][2] ); 
  Room* B1 = new Room( roomInfo[1][0], roomInfo[1][1], roomInfo[1][2]); 
  Room* B2 = new Room( roomInfo[2][0], roomInfo[2][1], roomInfo[2][2]); 
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

  Room* currentRoom = nullptr; 
  currentRoom = A1; 
  string choice;

  
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
