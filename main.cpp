
//  main.cpp
//  Logans_Labyrinth
//
//  Created by J T on 9/13/22.
//

/*
 ___       __   _______   ___       ________  ________  _____ ______   _______           _________  ________
|\  \     |\  \|\  ___ \ |\  \     |\   ____\|\   __  \|\   _ \  _   \|\  ___ \         |\___   ___|\   __  \
\ \  \    \ \  \ \   __/|\ \  \    \ \  \___|\ \  \|\  \ \  \\\__\ \  \ \   __/|        \|___ \  \_\ \  \|\  \
 \ \  \  __\ \  \ \  \_|/_\ \  \    \ \  \    \ \  \\\  \ \  \\|__| \  \ \  \_|/__           \ \  \ \ \  \\\  \
  \ \  \|\__\_\  \ \  \_|\ \ \  \____\ \  \____\ \  \\\  \ \  \    \ \  \ \  \_|\ \           \ \  \ \ \  \\\  \
   \ \____________\ \_______\ \_______\ \_______\ \_______\ \__\    \ \__\ \_______\           \ \__\ \ \_______\
    \|____________|\|_______|\|_______|\|_______|\|_______|\|__|     \|__|\|_______|            \|__|  \|_______|
 ___       ________  ________  ________  ________   ________
|\  \     |\   __  \|\   ____\|\   __  \|\   ___  \|\   ____\
\ \  \    \ \  \|\  \ \  \___|\ \  \|\  \ \  \\ \  \ \  \___|_
 \ \  \    \ \  \\\  \ \  \  __\ \   __  \ \  \\ \  \ \_____  \
  \ \  \____\ \  \\\  \ \  \|\  \ \  \ \  \ \  \\ \  \|____|\  \
   \ \_______\ \_______\ \_______\ \__\ \__\ \__\\ \__\____\_\  \
    \|_______|\|_______|\|_______|\|__|\|__|\|__| \|__|\_________\
                                                      \|_________|
 ___       ________  ________      ___    ___ ________  ___  ________   _________  ___  ___
|\  \     |\   __  \|\   __  \    |\  \  /  /|\   __  \|\  \|\   ___  \|\___   ___|\  \|\  \
\ \  \    \ \  \|\  \ \  \|\ /_   \ \  \/  / \ \  \|\  \ \  \ \  \\ \  \|___ \  \_\ \  \\\  \
 \ \  \    \ \   __  \ \   __  \   \ \    / / \ \   _  _\ \  \ \  \\ \  \   \ \  \ \ \   __  \
  \ \  \____\ \  \ \  \ \  \|\  \   \/  /  /   \ \  \\  \\ \  \ \  \\ \  \   \ \  \ \ \  \ \  \
   \ \_______\ \__\ \__\ \_______\__/  / /      \ \__\\ _\\ \__\ \__\\ \__\   \ \__\ \ \__\ \__\
    \|_______|\|__|\|__|\|_______|\___/ /        \|__|\|__|\|__|\|__| \|__|    \|__|  \|__|\|__|
                                 \|___|/
*/
/* ascii banner by: https://manytools.org/hacker-tools/ascii-banner/
   TODO: Be more original and create better one later... */

   /************************************************************************/
   /*                                                                      */
   /*                          INTRODUCTION                                */
   /*                                                                      */
   /************************************************************************/

// This is an adventure puzzle horror game my kid creatively designed and made with me where you are
// trying to find your way through a labyrinth while being chased /hunted through a series of rooms.
// At the end you hunt the "hunter"
// The chase scenes have to be funny when you are chasing the "hunter"
// Hero: Logan
// Hunter/Villain/Main Boss: A creepy cake monster
// End game Weapon: A giant Fork... "the master fork"
// 2 creepy killer cookie sidekicks jump out and scare you like mini bad guys
// ninja star side weapons maybe "ninja milk stars"
// special tools to acquire along the way


/************************************************************************/
/*                                                                      */
/*                           TO DO                                      */
/*                                                                      */
/************************************************************************/

// 1. Turn some of this sh-tuff into classes.... maybe create a header file or two... make it more readable
// 2. Find a way to clean up look around command. Maybe create functions for the text or something.
// 3. When you go back upstairs from jail room to start room and don't get the letter,
//    the "look around" command doesn't work until you get the letter
// 4. Create a manual
// 5. Create timer to make a decision to either go back or fight.
//    if timer runs out before decision is made, the cookies eat you.
// 6. Create Huggy Wuggy "guard" code
// 7. Work on The Boss Room
// 8. Work on The Death Room
// 9. Work on the Master Fork Room
//10. Create "entered room" ascii pics for all rooms  and have them change depending on what happened in the room

#include <iostream>
#include <string>
#include <vector> // for inventory
#include <iomanip>// to make things pretty
#include <ctime> // for countdown timer to select right answer
#include <thread> // for letting the countdown timer run while trying to type the right answer
//#include <algorithm> // to search through vectors
using namespace std;

/************************************************************************/
/*                                                                      */
/*                    Global Variables Are Bad Mkay                     */
/*                   (Evil evil evil evil... fix it?)                   */
/************************************************************************/
bool stillAlive = true;
string command = "...";//TODO: Could we create a command function?

//title and screen selection
bool title = true;
bool selection = false;

//start room
bool beginning = false;
bool letterInInventory = false;
bool lanternInInventory = false;
bool pileOfHayMoved = false;
bool trapDoorOpen = false;
bool wentToJailRoom = false;

//jail room
bool keyInInventory = false;
bool sawHuggyWuggy = false;
//bool huggyWuggyFreed = false; //moved to huggy wuggy bools
bool mapRoomDoorOpen = false;
bool wentToMapRoom = false;

//map room
bool gotNinjaStars = false;
bool wentToCookieRoom = false;
bool gotMap = false;
bool cookieDoorUnlocked = false;

//cookie room
bool wentToZombieRoom = false;
bool cookiesDead = false;
bool cookieTreasureChestAppears = false;
bool canShootLightning = false;
//bool deathByCookieTimer //TODO: Create a countdown timer to escape from cookies

//zombie room
bool wentToBossRoom = false;
bool talkedToBrockKillie = false;
bool zombie_Boss_Room_Door_Open = false;
bool ranOutOfTime = false; // timer to make decisions in cookie and vegetable rooms as well as the boss chase
bool rightAnswer = false;
//bool zombieStunned = false //TODO: create a stun mechanic to add more time to countdown timer 


//boss room
bool cakeIsAwake = false; //starts cake timer to count down when you will get eaten unless you make a decision.
bool cakeStunned = false;// pauses timer (or maybe adds more time to cake timer) to stop cake from chasing and killing you
bool wentToDeathRoom = false;//stops timer upon entering
bool inChest = false;

//death room
bool wentToMasterForkRoom = false;
bool  goldenKeyInInventory = false; //key to unlock master fork room


// master fork room
bool masterForkInInventory = false;
bool wentToPedestal = true;

//huggy wuggy
bool huggyWuggyAlive = true; //if huggy wuggy is freed and alive, he acts like a body gaurd and saves you from death once and then dies from the incident
bool huggyWuggyFreed = false;// EXCEPT for the boss fight and if you have the master fork, than he could be saved

//Ending
bool wonGame = false;


void commands()
/************************************************************************/
/*                                                                      */
/*                           COMMANDS LIST                              */
/*                                                                      */
/************************************************************************/
{
    vector<string> commands
    {
        "Look around", "Look at", "Look under", "Examine", "Investigate",
        "Read", "Go east", "Go west", "Go south", "Go north",
        "Run away", "Hide", "Open", "Close", "Take", "Commands",
        "Pick up", "Grab", "Drop", "Move", "Lock", "Unlock",
        "Inventory", "Bag","Items", "Pinch yourself","Exit","Quit", "Walk down", "Run down",
        "Shoot lightning","Lightning", "Throw", "Ninja stars", "Map",
        "Where am I?", "Manual"
    };
    cout << "List of Commands: " << endl;
    for (int c = 0; c < commands.size(); ++c) {//prints out items in commands vector in colums
        string commandList = commands[c];
        cout << left << setw(20) << commandList;//TODO: this wraps it... but it changes with the screen, find a way to create just four colums

    }
    cout << endl;
}
/************************************************************************/
/*                                                                      */
/*                           COMMAND FUNCTIONS                          */
/*                                                                      */
/************************************************************************/

/* function to lower case a variable*/
string tolower(string str)
{
    string str_lower = "";
    for (char c : str)
    {
        str_lower += tolower(c);
    }
    return str_lower;
};
// get command function
void getCommand()
{
    cout << endl;
    getline(cin, command);
    cout << endl;
    command = tolower(command);//lowers all input to lower case

}
void manual()
{
    /************************************************************************/
    /*                                                                      */
    /*                           THE GAME MANUAL                            */
    /*                                                                      */
    /************************************************************************/

    //TODO: Yep... still need to do this...
    commands();


}

/************************************************************************/
/*                                                                      */
/*                           THE INVENTORY                              */
/*                                                                      */
/************************************************************************/
vector<string> items;
// TODO: Try to include this in the inventory function / class
void inventory()// Inventory bag
{
    cout << "Items in Inventory: " << endl;
    cout << "The Manual" << endl;
    for (int i = 0; i < items.size(); ++i) {//prints out items in inventory vector
        string itemList = items[i];
        cout << itemList << endl;
    }
    cout << endl;
}

//letter
void letter()
{
    
    cout << "On the paper it says,\n\n\"Welcome to the labyrinth of your mind." << endl;
    cout << "You are trapped inside this nightmare caused by indigestion from" << endl;
    cout << "consuming too much cake and cookies at a dinner party which is now " << endl;
    cout << "trying to hunt you down and eat you in this horrific dream." << endl;
    cout << "To wake up, you must escape this labyrinth without being eaten by the" << endl;
    cout << "killer cake and cookies. Otherwise, you will die in your sleep.\"" << endl << endl;
    cout << "P.S.\n\nDon't try to \"pinch yourself\" otherwise your will wake up and die!\n Muahaha!" << endl << endl;

}

void map()
/************************************************************************/
/*                                                                      */
/*                           THE MAP                                    */
/*                                                                      */
/************************************************************************/



{
    cout << "_________________________________________________________________________" << endl;
    cout << "|                      MAP OF THE LABYRINTH                             |" << endl;
    cout << "|-----------------------------------------------------------------------|" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|                                 __________________________            |" << endl;
    cout << "|       ________                 |                       |__|           |" << endl;
    cout << "|      |Start|__|                |                          |           |" << endl;
    cout << "|      |Room |__|                |       Boss Room          |           |" << endl;
    cout << "|      |  /**\\  |                |                          |           |" << endl;
    cout << "|      ---|--|--                 |________________________/ |           |" << endl;
    cout << "|         |--| Stair               Zombie                |  |  nw N ne  |" << endl;
    cout << "|         |--| Well                 |  |       __________|  |   \\ | /   |" << endl;
    cout << "|      ___|--|_____                 Hall       |            | W---|---E |" << endl;
    cout << "|     |            |                |  |       |   Death    |   / | \\   |" << endl;
    cout << "|     |   Jail     |                |  |       |   Room     |  sw S se  |" << endl;
    cout << "|     |      ______|                |  |       |__________/ |           |" << endl;
    cout << "|     |      |cell |           _____|/ |_____   __________| | [COMPASS] |" << endl;
    cout << "|     |/ ____|_____|___________|            |   |  Master   |           |" << endl;
    cout << "|     |           / ___________   Killer    |   |   Fork    |           |" << endl;
    cout << "|     |  Map   ____|           |  Cookie    |   |   Room    |           |" << endl;
    cout << "|     | Room   |___|           |   Room     |   |___________|           |" << endl;
    cout << "|     |___     ||_||           |         ___|                           |" << endl;
    cout << "|     |___|____|___|           |_________|__|                           |" << endl;
    cout << "|_______________________________________________________________________|" << endl << endl;

}

void secretMap()
{
    cout << "_________________________________________________________________________" << endl;
    cout << "|                      MAP OF THE LABYRINTH                             |" << endl;
    cout << "|-----------------------------------------------------------------------|" << endl;
    cout << "|            Letter                                                     |" << endl;
    cout << "|              |        \"Killer   __________________________            |" << endl;
    cout << "|       _______V_         Cake ->|o_0|                   |__|<-\"Empty   |" << endl;
    cout << "|      |Start|__|         Boss\"  |---|                      |   Chest\"  |" << endl;
    cout << "|      |Room |__|<-Table         |       Boss Room          |(hide here)|" << endl;
    cout << "|Trap--|->/**\\  |                |                          |           |" << endl;
    cout << "|Door  ---|--|--                 |________________________/ |           |" << endl;
    cout << "|         |--| Stair               Zombie                |  |  nw N ne  |" << endl;
    cout << "|         |--| Well                 |  |       __________|  |   \\ | /   |" << endl;
    cout << "|      ___|--|_____                 Hall       |            | W---|---E |" << endl;
    cout << "|Key->|            |                |  |       |   Death    |   / | \\   |" << endl;
    cout << "|     |   Jail     |                |  |       |   Room     |  sw S se  |" << endl;
    cout << "|     |      ______|                |  |       |__________/ |           |" << endl;
    cout << "|     |      |cell |           _____|/ |_____   __________| | [COMPASS] |" << endl;
    cout << "|     |/ ____|_____|___________|            |   |  Master   |           |" << endl;
    cout << "|     |           / ___________   Killer    |   |   Fork    |           |" << endl;
    cout << "|     |  Map   ____|           |  Cookie    |   |   Room    |           |" << endl;
    cout << "|     | Room   |___|           |   Room     |   |___________|           |" << endl;
    cout << "|     |___     ||_||<--Map on  |         ___|                           |" << endl;
    cout << "|Chest|___|____|___|   Table   |_________|__|<-Chest                    |" << endl;
    cout << "|_______________________________________________________________________|" << endl << endl;
}
/************************************************************************/
/*                                                                      */
/*                           "Here you are"                             */
/*                            Map Function                              */
/************************************************************************/

void hereYouAre()
{
    if (gotMap == false)
    {
        if (beginning == true)
        {
            cout << "You are in the Start Room" << endl;
        }
        else if (wentToJailRoom == true)
        {
            cout << "You are in the jail room" << endl;
        }
        else if (wentToMapRoom == true)
        {
            cout << "You are in the Map Room" << endl;
        }
        else if (wentToCookieRoom == true)
        {
            cout << "You are in the Cookie Room" << endl;
        }
        else if (wentToZombieRoom == true)
        {
            cout << "You are in the Zombie Room" << endl;
        }
        else if (wentToBossRoom == true)
        {
            cout << "You are in the Boss Room" << endl;
        }
        else if (wentToDeathRoom == true)
        {
            cout << "You are in the Death Room" << endl;
        }
        else if (wentToMasterForkRoom == true)
        {
            cout << "You are in the Master Fork Room" << endl;
        }
    }
    else if (gotMap == true)
    {
        if (beginning == true)
        {
            cout << "_________________________________________________________________________" << endl;
            cout << "|                      MAP OF THE LABYRINTH                             |" << endl;
            cout << "|-----------------------------------------------------------------------|" << endl;
            cout << "| YOU ARE _                                                             |" << endl;
            cout << "|  HERE    |                      __________________________            |" << endl;
            cout << "|       ___V____                 |                       |__|           |" << endl;
            cout << "|      |Start|__|                |                          |           |" << endl;
            cout << "|      |Room |__|                |       Boss Room          |           |" << endl;
            cout << "|      |  /**\\  |                |                          |           |" << endl;
            cout << "|      ---|--|--                 |________________________/ |           |" << endl;
            cout << "|         |--| Stair               Zombie                |  |  nw N ne  |" << endl;
            cout << "|         |--| Well                 |  |       __________|  |   \\ | /   |" << endl;
            cout << "|      ___|--|_____                 Hall       |            | W---|---E |" << endl;
            cout << "|     |            |                |  |       |   Death    |   / | \\   |" << endl;
            cout << "|     |   Jail     |                |  |       |   Room     |  sw S se  |" << endl;
            cout << "|     |      ______|                |  |       |__________/ |           |" << endl;
            cout << "|     |      |cell |           _____|/ |_____   __________| | [COMPASS] |" << endl;
            cout << "|     |/ ____|_____|___________|            |   |  Master   |           |" << endl;
            cout << "|     |           / ___________   Killer    |   |   Fork    |           |" << endl;
            cout << "|     |  Map   ____|           |  Cookie    |   |   Room    |           |" << endl;
            cout << "|     | Room   |___|           |   Room     |   |___________|           |" << endl;
            cout << "|     |___     ||_||           |         ___|                           |" << endl;
            cout << "|     |___|____|___|           |_________|__|                           |" << endl;
            cout << "|_______________________________________________________________________|" << endl << endl;
        }
        else if (wentToJailRoom == true)
        {
            cout << "_________________________________________________________________________" << endl;
            cout << "|                      MAP OF THE LABYRINTH                             |" << endl;
            cout << "|-----------------------------------------------------------------------|" << endl;
            cout << "|                                                                       |" << endl;
            cout << "|                                 __________________________            |" << endl;
            cout << "|       ________                 |                       |__|           |" << endl;
            cout << "|      |Start|__|                |                          |           |" << endl;
            cout << "|      |Room |__|                |       Boss Room          |           |" << endl;
            cout << "|      |  /**\\  |                |                          |           |" << endl;
            cout << "|      ---|--|--                 |________________________/ |           |" << endl;
            cout << "|         |--| Stair               Zombie                |  |  nw N ne  |" << endl;
            cout << "|         |--| Well                 |  |       __________|  |   \\ | /   |" << endl;
            cout << "|      ___|--|_____                 Hall       |            | W---|---E |" << endl;
            cout << "|     |            |    YOU         |  |       |   Death    |   / | \\   |" << endl;
            cout << "|     |   Jail     |<---ARE         |  |       |   Room     |  sw S se  |" << endl;
            cout << "|     |      ______|    HERE        |  |       |__________/ |           |" << endl;
            cout << "|     |      |cell |           _____|/ |_____   __________| | [COMPASS] |" << endl;
            cout << "|     |/ ____|_____|___________|            |   |  Master   |           |" << endl;
            cout << "|     |           / ___________   Killer    |   |   Fork    |           |" << endl;
            cout << "|     |  Map   ____|           |  Cookie    |   |   Room    |           |" << endl;
            cout << "|     | Room   |___|           |   Room     |   |___________|           |" << endl;
            cout << "|     |___     ||_||           |         ___|                           |" << endl;
            cout << "|     |___|____|___|           |_________|__|                           |" << endl;
            cout << "|_______________________________________________________________________|" << endl << endl;
        }
        else if (wentToMapRoom == true)
        {
            cout << "_________________________________________________________________________" << endl;
            cout << "|                      MAP OF THE LABYRINTH                             |" << endl;
            cout << "|-----------------------------------------------------------------------|" << endl;
            cout << "|                                                                       |" << endl;
            cout << "|                                 __________________________            |" << endl;
            cout << "|       ________                 |                       |__|           |" << endl;
            cout << "|      |Start|__|                |                          |           |" << endl;
            cout << "|      |Room |__|                |       Boss Room          |           |" << endl;
            cout << "|      |  /**\\  |                |                          |           |" << endl;
            cout << "|      ---|--|--                 |________________________/ |           |" << endl;
            cout << "|         |--| Stair               Zombie                |  |  nw N ne  |" << endl;
            cout << "|         |--| Well                 |  |       __________|  |   \\ | /   |" << endl;
            cout << "|      ___|--|_____                 Hall       |            | W---|---E |" << endl;
            cout << "|     |            |                |  |       |   Death    |   / | \\   |" << endl;
            cout << "|     |   Jail     |                |  |       |   Room     |  sw S se  |" << endl;
            cout << "|     |      ______|                |  |       |__________/ |           |" << endl;
            cout << "|     |      |cell |           _____|/ |_____   __________| | [COMPASS] |" << endl;
            cout << "|     |/ ____|_____|___________|            |   |  Master   |           |" << endl;
            cout << "| YOU |           / ___________   Killer    |   |   Fork    |           |" << endl;
            cout << "| ARE |  Map   ____|           |  Cookie    |   |   Room    |           |" << endl;
            cout << "|HERE | Room   |___|           |   Room     |   |___________|           |" << endl;
            cout << "| --->|___     ||_||           |         ___|                           |" << endl;
            cout << "|     |___|____|___|           |_________|__|                           |" << endl;
            cout << "|_______________________________________________________________________|" << endl << endl;
        }
        else if (wentToCookieRoom == true)
        {
            cout << "_________________________________________________________________________" << endl;
            cout << "|                      MAP OF THE LABYRINTH                             |" << endl;
            cout << "|-----------------------------------------------------------------------|" << endl;
            cout << "|                                                                       |" << endl;
            cout << "|                                 __________________________            |" << endl;
            cout << "|       ________                 |                       |__|           |" << endl;
            cout << "|      |Start|__|                |                          |           |" << endl;
            cout << "|      |Room |__|                |       Boss Room          |           |" << endl;
            cout << "|      |  /**\\  |                |                          |           |" << endl;
            cout << "|      ---|--|--                 |________________________/ |           |" << endl;
            cout << "|         |--| Stair               Zombie                |  |  nw N ne  |" << endl;
            cout << "|         |--| Well                 |  |       __________|  |   \\ | /   |" << endl;
            cout << "|      ___|--|_____                 Hall       |            | W---|---E |" << endl;
            cout << "|     |            |    YOU         |  |       |   Death    |   / | \\   |" << endl;
            cout << "|     |   Jail     |    ARE______   |  |       |   Room     |  sw S se  |" << endl;
            cout << "|     |      ______|    HERE     |  |  |       |__________/ |           |" << endl;
            cout << "|     |      |cell |           __V__|/ |_____   __________| | [COMPASS] |" << endl;
            cout << "|     |/ ____|_____|___________|            |   |  Master   |           |" << endl;
            cout << "|     |           / ___________   Killer    |   |   Fork    |           |" << endl;
            cout << "|     |  Map   ____|           |  Cookie    |   |   Room    |           |" << endl;
            cout << "|     | Room   |___|           |   Room     |   |___________|           |" << endl;
            cout << "|     |___     ||_||           |         ___|                           |" << endl;
            cout << "|     |___|____|___|           |_________|__|                           |" << endl;
            cout << "|_______________________________________________________________________|" << endl << endl;
        }
        else if (wentToZombieRoom == true)
        {
        cout << "_________________________________________________________________________" << endl;
        cout << "|                      MAP OF THE LABYRINTH                             |" << endl;
        cout << "|-----------------------------------------------------------------------|" << endl;
        cout << "|                                                                       |" << endl;
        cout << "|                                 __________________________            |" << endl;
        cout << "|       ________                 |                       |__|           |" << endl;
        cout << "|      |Start|__|                |                          |           |" << endl;
        cout << "|      |Room |__|                |       Boss Room          |           |" << endl;
        cout << "|      |  /**\\  |                |                          |           |" << endl;
        cout << "|      ---|--|--                 |________________________/ |           |" << endl;
        cout << "|         |--| Stair               Zombie                |  |  nw N ne  |" << endl;
        cout << "|         |--| Well                 |  |       __________|  |   \\ | /   |" << endl;
        cout << "|      ___|--|_____                 Hall       |            | W---|---E |" << endl;
        cout << "|     |            |    YOU         |  |       |   Death    |   / | \\   |" << endl;
        cout << "|     |   Jail     |    ARE-------->|  |       |   Room     |  sw S se  |" << endl;
        cout << "|     |      ______|    HERE        |  |       |__________/ |           |" << endl;
        cout << "|     |      |cell |           _____|/ |_____   __________| | [COMPASS] |" << endl;
        cout << "|     |/ ____|_____|___________|            |   |  Master   |           |" << endl;
        cout << "|     |           / ___________   Killer    |   |   Fork    |           |" << endl;
        cout << "|     |  Map   ____|           |  Cookie    |   |   Room    |           |" << endl;
        cout << "|     | Room   |___|           |   Room     |   |___________|           |" << endl;
        cout << "|     |___     ||_||           |         ___|                           |" << endl;
        cout << "|     |___|____|___|           |_________|__|                           |" << endl;
        cout << "|_______________________________________________________________________|" << endl << endl;
        }
        else if (wentToBossRoom == true)
        {
        cout << "_________________________________________________________________________" << endl;
        cout << "|                      MAP OF THE LABYRINTH                             |" << endl;
        cout << "|-----------------------------------------------------------------------|" << endl;
        cout << "|                                                                       |" << endl;
        cout << "|                                 __________________________            |" << endl;
        cout << "|       ________        YOU      |                       |__|           |" << endl;
        cout << "|      |Start|__|       ARE      |                          |           |" << endl;
        cout << "|      |Room |__|       HERE---->|       Boss Room          |           |" << endl;
        cout << "|      |  /**\\  |                |                          |           |" << endl;
        cout << "|      ---|--|--                 |________________________/ |           |" << endl;
        cout << "|         |--| Stair               Zombie                |  |  nw N ne  |" << endl;
        cout << "|         |--| Well                 |  |       __________|  |   \\ | /   |" << endl;
        cout << "|      ___|--|_____                 Hall       |            | W---|---E |" << endl;
        cout << "|     |            |                |  |       |   Death    |   / | \\   |" << endl;
        cout << "|     |   Jail     |                |  |       |   Room     |  sw S se  |" << endl;
        cout << "|     |      ______|                |  |       |__________/ |           |" << endl;
        cout << "|     |      |cell |           _____|/ |_____   __________| | [COMPASS] |" << endl;
        cout << "|     |/ ____|_____|___________|            |   |  Master   |           |" << endl;
        cout << "|     |           / ___________   Killer    |   |   Fork    |           |" << endl;
        cout << "|     |  Map   ____|           |  Cookie    |   |   Room    |           |" << endl;
        cout << "|     | Room   |___|           |   Room     |   |___________|           |" << endl;
        cout << "|     |___     ||_||           |         ___|                           |" << endl;
        cout << "|     |___|____|___|           |_________|__|                           |" << endl;
        cout << "|_______________________________________________________________________|" << endl << endl;
        }
        else if (wentToDeathRoom == true)
        {
        cout << "_________________________________________________________________________" << endl;
        cout << "|                      MAP OF THE LABYRINTH                             |" << endl;
        cout << "|-----------------------------------------------------------------------|" << endl;
        cout << "|                                                                       |" << endl;
        cout << "|                                 __________________________            |" << endl;
        cout << "|       ________                 |                       |__|           |" << endl;
        cout << "|      |Start|__|                |                          |           |" << endl;
        cout << "|      |Room |__|                |       Boss Room          |           |" << endl;
        cout << "|      |  /**\\  |                |                          |           |" << endl;
        cout << "|      ---|--|--                 |________________________/ |           |" << endl;
        cout << "|         |--| Stair               Zombie                |  |  nw N ne  |" << endl;
        cout << "|         |--| Well                 |  |       __________|  |   \\ | /   |" << endl;
        cout << "|      ___|--|_____                 Hall       |            | W---|---E |" << endl;
        cout << "|     |            |                |  | YOU   |   Death    |   / | \\   |" << endl;
        cout << "|     |   Jail     |                |  | ARE-->|   Room     |  sw S se  |" << endl;
        cout << "|     |      ______|                |  | HERE  |__________/ |           |" << endl;
        cout << "|     |      |cell |           _____|/ |_____   __________| | [COMPASS] |" << endl;
        cout << "|     |/ ____|_____|___________|            |   |  Master   |           |" << endl;
        cout << "|     |           / ___________   Killer    |   |   Fork    |           |" << endl;
        cout << "|     |  Map   ____|           |  Cookie    |   |   Room    |           |" << endl;
        cout << "|     | Room   |___|           |   Room     |   |___________|           |" << endl;
        cout << "|     |___     ||_||           |         ___|                           |" << endl;
        cout << "|     |___|____|___|           |_________|__|                           |" << endl;
        cout << "|_______________________________________________________________________|" << endl << endl;
        }
        else if (wentToMasterForkRoom == true)
        {
        cout << "_________________________________________________________________________" << endl;
        cout << "|                      MAP OF THE LABYRINTH                             |" << endl;
        cout << "|-----------------------------------------------------------------------|" << endl;
        cout << "|                                                                       |" << endl;
        cout << "|                                 __________________________            |" << endl;
        cout << "|       ________                 |                       |__|           |" << endl;
        cout << "|      |Start|__|                |                          |           |" << endl;
        cout << "|      |Room |__|                |       Boss Room          |           |" << endl;
        cout << "|      |  /**\\  |                |                          |           |" << endl;
        cout << "|      ---|--|--                 |________________________/ |           |" << endl;
        cout << "|         |--| Stair               Zombie                |  |  nw N ne  |" << endl;
        cout << "|         |--| Well                 |  |       __________|  |   \\ | /   |" << endl;
        cout << "|      ___|--|_____                 Hall       |            | W---|---E |" << endl;
        cout << "|     |            |                |  |       |   Death    |   / | \\   |" << endl;
        cout << "|     |   Jail     |                |  |       |   Room     |  sw S se  |" << endl;
        cout << "|     |      ______|                |  |       |__________/ |           |" << endl;
        cout << "|     |      |cell |           _____|/ |_____   __________| | [COMPASS] |" << endl;
        cout << "|     |/ ____|_____|___________|            |   |  Master   |           |" << endl;
        cout << "|     |           / ___________   Killer    |   |   Fork    |           |" << endl;
        cout << "|     |  Map   ____|           |  Cookie    |   |   Room    |    YOU    |" << endl;
        cout << "|     | Room   |___|           |   Room     |   |___________|<---ARE    |" << endl;
        cout << "|     |___     ||_||           |         ___|                    HERE   |" << endl;
        cout << "|     |___|____|___|           |_________|__|                           |" << endl;
        cout << "|_______________________________________________________________________|" << endl << endl;
        }
    }


}








///************************************************************************/
///*                                                                      */
///*                           GAME OVER                                  */
///*                           ASCII ART                                  */
///************************************************************************/
//
//void gameOver()

///*ascii art generated by: https://manytools.org/hacker-tools/ascii-banner/ */
//
//{
//    cout << "@@@@@@@     @@@@@@   @@@@@@@@@@   @@@@@@@@    @@@@@@   @@@  @@@ @@@@@@@@ @@@@@@@   " << endl;
//    cout << "!@@        @@!  @@@  @@! @@! @@!  @@!        @@!  @@@  @@!  @@@ @@!      @@!  @@@ " << endl;
//    cout << "!@! @!@!@  @!@!@!@!  @!! !!@ @!@  @!!!:!     @!@  !@!  @!@  !@! @!!!:!   @!@!!@!  " << endl;
//    cout << ":!!   !!:  !!:  !!!  !!:     !!:  !!:        !!:  !!!   !: .:!  !!:      !!: :!!  " << endl;
//    cout << ":: :: :    :    : :   :      :    : :: ::     : :. :      ::    : :: ::   :   : :  " << endl;
//}
//
///*asii art generated by: https://textkool.com/en/ascii-art-generator?hl=default&vl=default&font=Wet%20Letter&text=Game%20Over */
//void gameOverBloody()
//{
//
//    cout << "   ,--,     .--.           ,---.    .---..-.   .-.,---.  ,---.    " << endl;
//    cout << " .' .'     / /\\ \\ |\\    /| | .-'   / .-. )\\ \\ / / | .-'  | .-.\\   " << endl;
//    cout << " |  |  __ / /__\\ \\|(\\  / | | `-.   | | |(_)\\ V /  | `-.  | `-'/   " << endl;
//    cout << " \\  \\ ( _)|  __  |(_)\\/  | | .-'   | | | |  ) /   | .-'  |   (    " << endl;
//    cout << "  \\  `-) )| |  |)|| \\  / | |  `--. \\ `-' / (_)    |  `--.| |\\ \\   " << endl;
//    cout << "  )\\____/ |_|  (_)| |\\/| | /( __.'  )---'         /( __.'|_| \\)\\  " << endl;
//    cout << " (__)             '-'  '-'(__)     (_)           (__)        (__) " << endl;

//}



void cakeGameOver()

{
    cout << "You died." << endl;
    cout << "You wake up and notice you fell out of the bed and hit your head! OUCH!\n\n" << endl;
    cout << "While rubbing your head you notice next to you on a table is a\nflash light and a hand-written note...\n\nJust Kidding..." << endl;
    stillAlive = false;
  
    cout << " ______________________________________________________________________________________ " << endl;
    cout << "|  __________________________________________________________________________________  |" << endl;
    cout << "| |     _/_/_/    _/_/     _/      _/  _/_/_/_/    _/_/   _/    _/  _/_/_/_/  _/_/_/ | |" << endl;
    cout << "| |   _/        _/    _/  _/ _/ _/_/  _/         _/   _/ _/    _/  _/        _/    _/| |" << endl;
    cout << "| |  _/  _/_/  _/_/_/_/  _/   _/ _/  _/_/_/     _/   _/ _/    _/  _/_/_/    _/_/_/   | |" << endl;
    cout << "| | _/    _/  _/    _/  _/      _/  _/         _/   _/   _/ _/   _/        _/    _/  | |" << endl;
    cout << "| |  _/_/_/  _/    _/  _/      _/  _/_/_/_/     _/_/      _/    _/_/_/_/  _/    _/   | |" << endl;
    cout << "| |__________________________________________________________________________________| |" << endl;
    cout << "|______________________________________________________________________________________|" << endl;
    cout << "|                                                                                      |" << endl;
    cout << "|                                                                                      |" << endl;
    cout << "|                                                                                      |" << endl;
    cout << "|                                                    ____________                      |" << endl;
    cout << "|                                             )\\    |            |                     |" << endl;
    cout << "|                                             (_)   | HA HA HA!!!|                     |" << endl;
    cout << "|                                    _/\\___  / /    |____   _____|                     |" << endl;
    cout << "|                                  _/      \\/ /         | /                            |" << endl;
    cout << "|                                _/        / / \\___     |/                             |" << endl;
    cout << "|                              _/                  \\___                                |" << endl;
    cout << "|                             /________________________\\                               |" << endl;
    cout << "|                            |  ________________________|                              |" << endl;
    cout << "|                            |  \\    __ \\    / __    /  |                              |" << endl;
    cout << "|                            | | \\__|_*|_\\  /_|*_|__/   |                              |" << endl;
    cout << "|                            | |________________________|                              |" << endl;
    cout << "|                            |  ________________________|                              |" << endl;
    cout << "|                            | |       /\\/\\/\\/\\         |                              |" << endl;
    cout << "|                            | |______|/\\/\\/\\/\\|________|                              |" << endl;
    cout << "|                            |__________________________|                              |" << endl;
    cout << "|______________________________________________________________________________________|" << endl;
  
}

/************************************************************************/
/*                                                                      */
/*                           Timed Answer Functions                     */
/*                                                                      */
/************************************************************************/


 // Don't touch this! Copy if you wan't to use it! Prototype code for experimenting.
    /*void tenSecondTimer()
    {

        int delay = 10;
        delay *= CLOCKS_PER_SEC;
        clock_t now = clock();
        while (clock() - now < delay)
        {

        }
        ranOutOfTime = true;

        if (rightAnswer == true)
        {
            cout << "You escaped" << endl;
        }
        else
        {
            cout << "You Died" << endl;
        }

    }

    void timedAnswer()
    {

        do

        {
            cout << endl;
            getline(cin, command); //be sure to change this to the getCommand()
            cout << endl;

            if (command == "run" && ranOutOfTime == false)
            {
                rightAnswer = true;
                cout << "Good Choice!" << endl;
            }
            else if (command != "run" && ranOutOfTime == false)
            {
                cout << "Maybe you should try something different..." << endl;
            }
            else if (ranOutOfTime == true)
            {
                cout << "You died" << endl;
            }
        } while (ranOutOfTime == true);
    }*/


    // TO USE THIS CODE:

        //int main()

        //{
        //    cout << "what are you going to do?" << endl;
        //    // Trying to get the timer and the timed answer working together so that when the timer runs out you die.

        //    //thread action(timedAnswer);
        //    //tenSecondTimer();
        //    //action.join();

        //    thread timer(tenSecondTimer);
        //    timedAnswer();
        //    timer.join();
        //    //TODO: right now, you "died" or "escaped" after the timer runs out.
        //    //      I want timer to stop as soon as correct answer is given.
        //    return 0;

        //}




        //for the vegetable room Brock Killie Choice
void twentySecondTimer()
{

    int delay = 20;
    delay *= CLOCKS_PER_SEC;
    clock_t now = clock();
    while (clock() - now < delay)
    {

    }
    ranOutOfTime = true;

    if (rightAnswer == true)
    {
        cout << "Breathing his last breath, Brock says, \"Thank you...\"\nlets go, and both him and the carrot keel over and die." << endl;
        cout << "At the end of the room, a door appears..." << endl;
    }

    else
    {
        cout << "All of the sudden, the carrot behind you lunges at you and proceeds to tear off your skin as you scream in agony to your last breath" << endl;
    }

}

void timedAnswer()
{

    do

    {
        getCommand();

        if (command == "sorry" || command == "i am sorry" || (command == "i apologize" && ranOutOfTime == false))
        {
            rightAnswer = true;
            cout << "You apologize... his dead eyes seem to\nlook through your soul as you wait for his reply..." << endl;
        }
        else if (command != "run" && ranOutOfTime == false)
        {
            cout << "Maybe you should try something different..." << endl;
        }

        else if (ranOutOfTime == true)
        {
            cakeGameOver();
            break;
        }
    } while (ranOutOfTime == true);
}







    void start_room()
    {
        /************************************************************************/
        /*                                                                      */
        /*                           THE START ROOM                             */
        /*                                                                      */
        /************************************************************************/
        if (lanternInInventory == false)
        {

            cout << " __________________________________________________________________________________ " << endl;
            cout << "|\\ ______________________________________________________________________________ /|" << endl;
            cout << "| |                    _____     You wake up on a pile of hay                    | |" << endl;
            cout << "| |                   /____/|    in a dimly lit stone-walled room...             | |" << endl;
            cout << "| |                  |  _  ||     Next to you on a table is a                    | |" << endl;
            cout << "| |                  | ||| ||_     glowing lantern and a hand-written letter.    | |" << endl;
            cout << "| |                 /|_|/|_|/|                                                   | |" << endl;
            cout << "| |                /_______/||                There is seemingly                 | |" << endl;
            cout << "| |                |   |   |||                  no way to escape...              | |" << endl;
            cout << "| |                |   |   |/|                                                   | |" << endl;
            cout << "| |         _______|---|---|||__________________________________                 | |" << endl;
            cout << "| |        /       |   |   ||/   /      ___/___     /         / |                | |" << endl;
            cout << "| |       /        |___|___|/   /      / ===  /    /         / /                 | |" << endl;
            cout << "| |      /          /          /      / ===  /    /         / /|                 | |" << endl;
            cout << "| |     /__________/__________/______/______/____/_________/ /||                 | |" << endl;
            cout << "| |     |__________|_________|__________|________|_________|/ ||                 | |" << endl;
            cout << "| |     |  || ||                                       |  ||| ||                 | |" << endl;
            cout << "| |     |  || ||                                       |  ||| ||                 | |" << endl;
            cout << "| |______________________________________________________________________________| |" << endl;
            cout << "|/________________________________________________________________________________\\|" << endl;

            cout << endl << endl;
        }


        do//continues until player goes down stairs
        {
            getCommand();

            if (command == "read letter" || command == "look at letter" || command == "examine letter" || command == "take letter"
                || command == "grab letter" || command == "grab the letter" || command == "get the letter"
                || command == "get letter" || command == "grab the letter" || command == "get letter")
            {
                if (letterInInventory == false)
                {
                    if (beginning == true)
                    {
                        items.push_back("Letter");// letter added to inventory vector
                        letterInInventory = true;
                        cout << "(Letter added to inventory!)" << endl << endl;
                        letter();
                    }
                    else if (beginning == false)
                    {
                        cout << "What are you talking about? you don't have that..." << endl;
                    }
                }
                else if (letterInInventory == true)
                {
                    letter();
                }
            }

            else if (command == "get lamp" || command == "grab the lamp" || command == "take lantern"
                || command == "pick up lantern" || command == "grab lantern" || command == "get lantern"
                || command == "get the lantern" || command == "grab the lantern" || command == "take the lantern")
            {
                if (lanternInInventory == false)
                {
                    lanternInInventory = true;
                    items.push_back("Lantern");//lantern added to inventory vector
                    cout << "You now have light! (Lantern moved to inventory)" << endl;
                }
                else if (lanternInInventory == true)
                {
                    cout << "You already have it" << endl;
                }
            }
            else if (command == "run away" && trapDoorOpen == false)
            {
                cout << "There is no way out! Muahahah!" << endl;

            }
            else if (command == "move pile of hay" || command == "move hay" || command == "move pile")
            {
                pileOfHayMoved = true;
                cout << "You move the pile of hay and there is a secret trap door." << endl;

            }
            else if ((pileOfHayMoved == true && command == "open trap door") || command == "open door" || command == "open" || command == "open trapdoor")
            {
                trapDoorOpen = true;
                if (lanternInInventory == false)
                {
                    cout << "You opened the trap door on the floor and find" << endl;
                    cout << "stairs leading down to a pitch black hole." << endl << endl;
                }
                else if (lanternInInventory == true)
                {
                    cout << "You opened the trap door on the floor and find stairs leading down" << endl;
                    cout << "a dark passage way." << endl << endl;
                }
            }
            else if (command == "move table" || command == "pickup table" || command == "pick up table")
            {
                cout << "Woah! This table sure is heavy! You are super strong!" << endl;
            }
            else if (command == "grab table" || command == "get table" || command == "take table")
            {
                cout << "Where are you going to store this table ?\n...\nYou put the table back" << endl;
            }
            else if (command == "look at table" || command == "examine table" || command == "investigate table" || command == "examine table")
            {
                cout << "As you examine the table you notice something stamped on it... It says, \"Ikea\"\n(The disembodied voice of the developer says, \"Hey, I am on a buget here!\")" << endl;
            }

            /************************| LOOK AROUND COMMAND |**********************/
            else if (command == "look around" || command == "examine room" || command == "investigate room")//TODO: is there an easier way to do this?
            {
                if (letterInInventory == false && lanternInInventory == false && pileOfHayMoved == false && trapDoorOpen == false)
                {
                    cout << "You are on a pile of hay in a dimly lit stone-walled room." << endl;
                    cout << "Next to you on a table is a glowing lantern and a hand-written letter." << endl;
                    cout << "There is seemingly no way to escape." << endl << endl;
                    continue;
                }
                else if (letterInInventory == true && lanternInInventory == false && pileOfHayMoved == false && trapDoorOpen == false)
                {
                    cout << "You are on a pile of hay in a dimly lit stone-walled room." << endl;
                    cout << "Next to you on a table is a glowing lantern." << endl;
                    cout << "There is seemingly no way to escape." << endl << endl;
                    continue;
                }
                else if (letterInInventory == true && lanternInInventory == true && pileOfHayMoved == false && trapDoorOpen == false)
                {
                    cout << "You are on a pile of hay in a dimly lit stone-walled room." << endl;
                    cout << "Next to you is a table." << endl;
                    cout << "There is seemingly no way to escape." << endl << endl;
                    continue;
                }
                else if (lanternInInventory == true && letterInInventory == false && pileOfHayMoved == false && trapDoorOpen == false)
                {
                    cout << "You are on a pile of hay in a dimly lit stone-walled room." << endl;
                    cout << "Next to you on a table is a glowing lantern." << endl;
                    cout << "There is seemingly no way to escape." << endl << endl;
                    continue;
                }
                else if (letterInInventory == true && lanternInInventory == true && pileOfHayMoved == true && trapDoorOpen == false)
                {
                    cout << "You are in a dimly lit stone-walled room." << endl;
                    cout << "Next to you is a table." << endl;
                    cout << "There is a closed trap door on the floor and a pile of hay in the corner." << endl << endl;
                    continue;
                }
                else if (letterInInventory == true && lanternInInventory == true && pileOfHayMoved == true && trapDoorOpen == true)
                {
                    cout << "You are in a dimly lit stone-walled room." << endl;
                    cout << "Next to you is a table." << endl;
                    cout << "There is an open trap door on the floor with stairs leading down" << endl;
                    cout << "a dark passage way, and a pile of hay in the corner." << endl << endl;
                    continue;
                }
                else if (letterInInventory == true && pileOfHayMoved == true && trapDoorOpen == true && lanternInInventory == false)
                {
                    cout << "You are in a dimly lit stone-walled room." << endl;
                    cout << "Next to you on a table is a glowing lantern." << endl;
                    cout << "There is an open trap door on the floor with stairs leading down" << endl;
                    cout << "to a pitch black hole, and a pile of hay in the corner." << endl << endl;
                    continue;
                }
                else if (letterInInventory == true && pileOfHayMoved == true && lanternInInventory == false && trapDoorOpen == false)
                {
                    cout << "You are on in a dimly lit stone-walled room." << endl;
                    cout << "Next to you on a table is a glowing lantern." << endl;
                    cout << "There is a closed trap door on the floor and a pile of hay in the corner." << endl << endl;
                    continue;
                }
                else if (pileOfHayMoved == true && letterInInventory == false && lanternInInventory == false && trapDoorOpen == false)
                {
                    cout << "You are in a dimly lit stone-walled room." << endl;
                    cout << "Next to you on a table is a glowing lantern and a hand-written letter." << endl;
                    cout << "There is a closed trap door on the floor and a pile of hay in the corner." << endl << endl;
                    continue;
                }
                else if (pileOfHayMoved == true && trapDoorOpen == true && letterInInventory == false && lanternInInventory == false)
                {
                    cout << "You are in a dimly lit stone-walled room." << endl;
                    cout << "Next to you on a table is a glowing lantern and a hand-written letter." << endl;
                    cout << "There is an open trap door on the floor with stairs leading down" << endl;
                    cout << "to a pitch black hole, and a pile of hay in the corner." << endl << endl;
                    continue;
                }
            }
            /*****************************************************************/

            else if ((pileOfHayMoved == true && trapDoorOpen && command == "go down") || command == "go down stairs"
                || command == "go down hole" || command == "go down passage way" || command == "go downstairs"
                || command == "go down passageway")
            {
                if (lanternInInventory == false)
                {
                    cout << "As you venture down the pitch-black hole you feel the\nkiller cookies bite your toes viciously" << endl;
                    cout << "and you proceed to get eaten from the feet up while screaming in agony." << endl;
                    cakeGameOver();
                    break;
                }
                else if (lanternInInventory == true)
                {
                    cout << "As you venture down the stairwell with your lantern, you see a\ncouple of evil killer cookies scurry off" << endl;
                    cout << "and then poof into white smoke... That was weird... o_0" << endl << endl;
                    cout << "At the bottom of the stairs, there is a dimly lit room." << endl;
                    beginning = false;
                    wentToJailRoom = true;
                    break;
                }

            }
            else if (command == "inventory" || command == "items" || command == "bag" || command == "look in bag" || command == "look in inventory")
            {
                inventory();
            }
            else if (command == "secret map")
            {
                secretMap();
            }
            else if (command == "commands")
            {
                commands();
            }
            else if (command == "where am i?")
            {
            hereYouAre();
            }
            else if (command == "pinch yourself" || command == "exit" || command == "quit") { //exits out of game
                cakeGameOver();
                break; 
            }
            else {
                cout << "What do you mean by \"" << command << "?\" Try a different command..." << endl << endl;
            }

        } while (wentToJailRoom == false);
    }

    void jail_room()
        /************************************************************************/
        /*                                                                      */
        /*                           THE JAIL ROOM                              */
        /*                                                                      */
        /************************************************************************/

        //TODO: Create easter egg if you go inside the jail cell to aqquire "HUGZ" (the ability to hug Huggy Wuggy)
        //TODO: test and debug "look around" command
    {


        if (keyInInventory == false)
        {
            cout << "There is a key hanging on the wall next to you." << endl;
            cout << "In the shadowy far-left corner of the room, there is\na darkened prison cell with something moving around in it." << endl;
            cout << "In the far-right corner there is a closed door with a keyhole." << endl;
        }



        do
        {

            getCommand();

            if (command == "take key" || command == "pick up key" || command == "grab key" || command == "get key")
            {
                if (keyInInventory == false)
                {
                    items.push_back("Key");// Key added to inventory vector
                    keyInInventory = true;
                    cout << "You take the key!(Key added to inventory)" << endl;
               }
                else if (keyInInventory == true)
                {
                 cout << "You look at the key in the bag." << endl;
                }
                
            }

            else if (command == "look at cell" || command == "examime cell" || command == "investigate cell"
                || command == "go to cell" || command == "walk to cell" || command == "go to jail cell"
                || command == "go to jail" || command == "walk to jail cell")
            {
                sawHuggyWuggy = true;
                cout << "There, huddled in the corner in the corner of the cell, you see Huggy Wuggy staring back out" << endl;
                cout << "at you with his black beady eyes..." << endl;
               
            }
            else if (command == "unlock cell" || command == "unlock prison cell" || command == "unlock huggy wuggy"
                || command == "unlock jail" || command == "let huggy wuggy out" || command == "open cell"
                || command == "open jail" || command == "open prison" || command == "free huggy wuggy")
            {
                if (keyInInventory == false)
                {
                    cout << "The prison cell is locked. You need a key." << endl;
                  
                }
                else if (keyInInventory == true)
                {
                    if (huggyWuggyFreed == false)
                    {
                        items.push_back("Huggy Wuggy"); // Huggy Wuggy added to inventory vector
                        huggyWuggyFreed = true;
                        cout << "You freed Huggy Wuggy from the prison cell!" << endl;
                        cout << "Huggy Wuggy looks at you, nods his head in thanks, and proceeds to be your body guard." << endl;
                        cout << "(Huggy Wuggy joins the team!)" << endl;
                    }
                    else if (huggyWuggyFreed == true)
                    {
                        cout << " You already unlocked the cell and freed Huggy Wuggy." << endl;
                    }
                }
            }
            else if (command == "investigate door" || command == "examine door" || command == "go to door")
            {
                cout << "You find that the door is locked." << endl;
            
            }

            /************************| LOOK AROUND COMMAND |**********************/



            else if (command == "look around" || command == "examine room" || command == "investigate room") {
                //didn't take key
                if (keyInInventory == false && sawHuggyWuggy == false && huggyWuggyFreed == false && mapRoomDoorOpen == false)
                {
                    cout << "There is a key hanging on the wall by the stairs." << endl;
                    cout << "In the shadowy far-left corner of the room, there is a\ndarkened prison cell with something moving behind its bars." << endl;
                    cout << "In the far-right corner there is a closed door with a keyhole." << endl;
                    continue;
                }
                else if (keyInInventory == false && sawHuggyWuggy == true && huggyWuggyFreed == false && mapRoomDoorOpen == false)
                {
                    cout << "There is a key hanging on the wall by the stairs." << endl;
                    cout << "In the shadowy far-left corner of the room, there is a\ndarkened prison cell with Huggy Wuggy trapped behind its bars." << endl;
                    cout << "In the far-right corner there is a closed door with a keyhole." << endl;
                    continue;
                }

                // took key, saw huggy wuggy, set him free,unlocked and opened door
                else if (keyInInventory == true && sawHuggyWuggy == false && huggyWuggyFreed == false && mapRoomDoorOpen == false)
                {
                    cout << "A door leads back up the darkened stair well." << endl;
                    cout << "In the shadowy far-left corner of the room, there is\na darkened prison cell with something moving behind its bars." << endl;
                    cout << "In the far-right corner there is a closed door with a keyhole." << endl;
                    continue;
                }
                else if (keyInInventory == true && sawHuggyWuggy == true && huggyWuggyFreed == false && mapRoomDoorOpen == false)
                {
                    cout << "A door leads back up the darkened stair well." << endl;
                    cout << "In the shadowy far-left corner of the room, there is\na darkened prison cell with Huggy Wuggy trapped behind its bars." << endl;
                    cout << "In the far-right corner there is a closed door with a keyhole." << endl;
                    continue;
                }
                else if ((keyInInventory == true && sawHuggyWuggy == true) || (sawHuggyWuggy == false && huggyWuggyFreed == true && mapRoomDoorOpen == false))
                {
                    cout << "A door leads back up the darkened stair well." << endl;
                    cout << "In the shadowy far-left corner of the room, there is\nan open prison cell and Huggy Wuggy is faithfully by your side." << endl;
                    cout << "In the far-right corner there is a closed door with a keyhole." << endl;
                    continue;
                }
                else if ((keyInInventory == true && sawHuggyWuggy == true) || (sawHuggyWuggy == false && huggyWuggyFreed == true && mapRoomDoorOpen == false))
                {
                    cout << "A door leads back up the darkened stair well." << endl;
                    cout << "In the shadowy far-left corner of the room, there is an open prison cell.\nHuggy Wuggy is faithfully by your side." << endl;
                    cout << "In the far-right corner there is a closed door with a keyhole." << endl;
                    continue;
                }
                else if ((keyInInventory == true && sawHuggyWuggy == true) || (sawHuggyWuggy == false && huggyWuggyFreed == true && mapRoomDoorOpen == true))
                {
                    cout << "A door leads back up the darkened stair well." << endl;
                    cout << "In the shadowy far-left corner of the room, there is an open prison cell.\nHuggy Wuggy is faithfully by your side." << endl;
                    cout << "In the far-right corner there is a door that has now been unlocked and opened." << endl;
                    continue;
                }
                // took key, saw and didn't free huggy wuggy, unlocked and opened door
                else if (keyInInventory == true && sawHuggyWuggy == true && huggyWuggyFreed == false && mapRoomDoorOpen == false)
                {
                    cout << "A door leads back up the darkened stair well." << endl;
                    cout << "In the shadowy far-left corner of the room, there is\na darkened prison cell with Huggy Wuggy trapped behind its bars." << endl;
                    cout << "In the far-right corner there is a closed door with a keyhole." << endl;
                    continue;
                }
                else if (keyInInventory == true && sawHuggyWuggy == true && huggyWuggyFreed == false && mapRoomDoorOpen == true)
                {
                    cout << "A door leads back up the darkened stair well." << endl;
                    cout << "In the shadowy far-left corner of the room, there is\na darkened prison cell with Huggy Wuggy trapped behind its bars." << endl;
                    cout << "In the far-right corner there is a door that has now been unlocked and opened." << endl;
                    continue;
                }
                //took key, didn't see or free huggy wuggy, opened door
                else if (keyInInventory == true && sawHuggyWuggy == false && huggyWuggyFreed == false && mapRoomDoorOpen == false)
                {
                    cout << "A door leads back up the darkened stair well." << endl;
                    cout << "In the shadowy far-left corner of the room, there is\na darkened prison cell with something moving behind its bars." << endl;
                    cout << "In the far-right corner there is a closed door with a keyhole." << endl;
                    continue;
                }
                else if (keyInInventory == true && sawHuggyWuggy == false && huggyWuggyFreed == false && mapRoomDoorOpen == true)
                {
                    cout << "A door leads back up the darkened stair well." << endl;
                    cout << "In the shadowy far-left corner of the room, there is\na darkened prison cell with something moving behind its bars." << endl;
                    cout << "In the far-right corner there is a door that has now been unlocked and opened." << endl;
                    continue;
                }
            }
            /********************************************************************************/
            else if (command == "unlock door" || command == "open door")
            {
                if (keyInInventory == false)
                {
                    cout << "You need a key to unlock this door..." << endl;
                   
                }
                else if (keyInInventory == true)
                {
                    cout << "You open unlock and open the door.\nInside you see a brightly lit cozy room." << endl;
                    mapRoomDoorOpen = true;
            
                }

            }
            else if (command == "go upstairs" || command == "walk upstairs" || command == "go to beginning room" || command == "go to start room")
            {
                wentToJailRoom = false;
                beginning = true;
                cout << "You went back upstairs to where you began your quest" << endl;
                break;
            }
            else if (command == "go into room" || command == "walk into room" || command == "enter room"
                || command == "go in room" || command == "go through door" || command == "walk in room"
                || command == "go to map room" || command == "go to room" || (command == "go inside room"
                    && mapRoomDoorOpen == true))
            {
                cout << "You step inside the room" << endl;
                wentToMapRoom = true; // works through main() if/else statements to determine which room function to go to
                wentToJailRoom = false;
                break;
            }
            //command statements that go in every room function
            else if (command == "inventory" || command == "items" || command == "bag" || command == "look in bag" || command == "look in inventory")
            {
                inventory();
            }
            else if (command == "secret map")
            {
            secretMap();
            }
            else if (command == "commands")
            {
                commands();
            }
            else if (command == "pinch yourself" || command == "quit" || command == "exit")
            { //exits out of game
            cakeGameOver();
            break;
            }
            else if (command == "where am i?")
            {
            hereYouAre();
            }
            else
            {
                cout << "What do you mean by \"" << command << "?\" Try a different command..." << endl << endl;
                continue;
            }





        } while (wentToMapRoom == false || beginning == false);
    }



    void map_room()
        /************************************************************************/
        /*                                                                      */
        /*                           THE MAP ROOM                               */
        /*                                                                      */
        /************************************************************************/
        // Chest has ninja stars to defeat mini boss in next room.
        // If you leave without ninja stars and go to mini-boss room you die after 10 seconds.
        // Table has map.

    {
        if (gotMap == false && gotNinjaStars == false)
        {
            cout << "To your left you see a door. There is a chest in one corner,\nand a table and chair in the other corner with a scroll on top of it." << endl;
        }
        else if (gotMap == true && gotNinjaStars == false)
        {
            cout << "To your left you see a door. There is a chest in one corner,\nand a table and chair in the other corner." << endl;
        }
        else if (gotMap == true && gotNinjaStars == true)
        {
            cout << "To your left you see a door. There is an opened chest in one corner,\nand a table and chair in the other corner." << endl;
        }
        do
        {


            getCommand();
            if (command == "go to chest" || command == "examine chest" || command == "investigate chest"
                || command == "open chest" || command == "look at chest" || command == "look in chest")
            {
                if (gotNinjaStars == false)
                {
                    gotNinjaStars = true;
                    items.push_back("Milk Ninja Stars"); // Milk Ninja Stars added to inventory vector
                    cout << "You look inside the chest and some find milk ninja stars! Nice!" << endl;
                    cout << "(Milk ninja stars are added to inventory)" << endl;
                }
                else if (gotNinjaStars == true)
                {
                    cout << "You already opened that chest and got the milk ninja stars." << endl;
                }
            }
            else if (command == "go to table" || command == "grab scroll" || command == "open scroll" || command == "go to desk" || command == "look at desk" || command == "look at table"
                || command == "look at scroll" || command == "get scroll" || command == "investigate scroll" || command == "see scroll")
            {
                if (gotMap == false) {

                    gotMap = true;
                    items.push_back("Map"); // Map added to inventory vector
                    cout << "_________________________________________________________________________" << endl;
                    cout << "|                      MAP OF THE LABYRINTH                             |" << endl;
                    cout << "|-----------------------------------------------------------------------|" << endl;
                    cout << "|                                                                       |" << endl;
                    cout << "|                                 __________________________            |" << endl;
                    cout << "|       ________                 |                       |__|           |" << endl;
                    cout << "|      |Start|__|                |                          |           |" << endl;
                    cout << "|      |Room |__|                |       Boss Room          |           |" << endl;
                    cout << "|      |  /**\\  |                |                          |           |" << endl;
                    cout << "|      ---|--|--                 |________________________/ |           |" << endl;
                    cout << "|         |--| Stair               Zombie                |  |  nw N ne  |" << endl;
                    cout << "|         |--| Well                 |  |       __________|  |   \\ | /   |" << endl;
                    cout << "|      ___|--|_____                 Hall       |            | W---|---E |" << endl;
                    cout << "|     |            |                |  |       |   Death    |   / | \\   |" << endl;
                    cout << "|     |   Jail     |                |  |       |   Room     |  sw S se  |" << endl;
                    cout << "|     |      ______|                |  |       |__________/ |           |" << endl;
                    cout << "|     |      |cell |           _____|/ |_____   __________| | [COMPASS] |" << endl;
                    cout << "|     |/ ____|_____|___________|            |   |  Master   |           |" << endl;
                    cout << "|     |           / ___________   Killer    |   |   Fork    |           |" << endl;
                    cout << "|     |  Map   ____|           |  Cookie    |   |   Room    |           |" << endl;
                    cout << "|     | Room   |___|           |   Room     |   |___________|           |" << endl;
                    cout << "|     |___     ||_||           |         ___|                           |" << endl;
                    cout << "|     |___|____|___|           |_________|__|                           |" << endl;
                    cout << "|_______________________________________________________________________|" << endl << endl;
                }
                else if ((gotMap == true && command == "go to table") || command == "go to desk" || command == "look at desk" || command == "look at table")
                {
                    cout << "Yep, looks like an ordinary table..." << endl;
                }
                else if ((gotMap == true && command == "grab scroll") || command == "open scroll"
                    || command == "look at scroll" || command == "get scroll"
                    || command == "investigate scroll" || command == "see scroll")
                {
                    cout << "Yep, it\'s a map." << endl;
                    map();
                }
            }
            else if (command == "go to door" || command == "walk to door" || command == "examine door"
                || command == "investigate door" || command == "look at door" || command == "open door" || command == "move to door")
            {
                cout << "You examine the door and find it locked." << endl;
            }
            else if (command == "unlock door")
            {
                cookieDoorUnlocked = true;
                cout << "You unlock the door and find long dark passage way\nleading to another room with eerie sounds coming from it." << endl;
            }
            //command statements that go in every room function
            else if (command == "inventory" || command == "items" || command == "bag" || command == "look in bag" || command == "look in inventory")
            {
                inventory();
            }
            else if (command == "map" || command == "open map" || command == "look at map" || command == "examine map" || (command == "read map" && gotMap == true))
            {
                map();
            }
            else if (command == "secret map")
            {
                secretMap();
            }
            else if (command == "commands")
            {
                commands();
            }
            else if (command == "pinch yourself" || command == "quit" || command == "exit")
            { //exits out of game
                cakeGameOver();
                break;
            }
            else if (command == "where am i?")
            {
                hereYouAre();
            }
            /************************| LOOK AROUND COMMAND |**********************/
            else if (command == "look around" || command == "examine room" || command == "investigate room")
            {
                if (gotNinjaStars == false && gotMap == false && cookieDoorUnlocked == false)
                {
                    cout << "To your left you see a door. There is a chest in one corner," << endl;
                    cout << "and a table and chair in the other corner with a scroll on top of it." << endl;
                    cout << "On the north wall there is the door leading to the jail room." << endl;
                }
                else if (gotNinjaStars == true && gotMap == false && cookieDoorUnlocked == false)
                {
                    cout << "To your left you see a door. There is an empty chest in one corner," << endl;
                    cout << "and a table and chair in the other corner with a scroll on top of it." << endl;
                    cout << "On the north wall there is the door leading to the jail room." << endl;
                }
                else if (gotNinjaStars == true && gotMap == true && cookieDoorUnlocked == false)
                {
                    cout << "To your left you see a door. There is an empty chest in one corner," << endl;
                    cout << "and a table and chair in the other corner." << endl;
                    cout << "On the north wall there is the door leading to the jail room." << endl;
                }
                else if (gotNinjaStars == true && gotMap == true && cookieDoorUnlocked == true)
                {
                    cout << "To your left is an open door leading down a dark passageway." << endl;
                    cout << "There is an empty chest in one corner," << endl;
                    cout << "and a table and chair in the other corner." << endl;
                    cout << "On the north wall there is the door leading to the jail room." << endl;
                }
                else if (gotNinjaStars == true && gotMap == false && cookieDoorUnlocked == true)
                {
                    cout << "To your left is an open door leading down a dark passageway.\nThere is an empty chest in one corner," << endl;
                    cout << "and a table and chair in the other corner with a scroll on top of it." << endl;
                    cout << "On the north wall there is the door leading to the jail room." << endl;
                }
                else if (gotNinjaStars == false && gotMap == true && cookieDoorUnlocked == false)
                {
                    cout << "To your left you see a door. There is a chest in one corner," << endl;;
                    cout << "and a table and chair in the other corner." << endl;
                    cout << "On the north wall there is the door leading to the jail room." << endl;
                }
                else if (gotNinjaStars == false && gotMap == true && cookieDoorUnlocked == true)
                {
                    cout << "To your left you see a door. There is a chest in one corner," << endl;;
                    cout << "and a table and chair in the other corner." << endl;
                    cout << "On the north wall there is the door leading to the jail room." << endl;
                }
                else if (gotNinjaStars == false && gotMap == false && cookieDoorUnlocked == true)
                {
                    cout << "To your left is an open door leading down a dark passageway. There is a chest in one corner," << endl;
                    cout << "and a table and chair in the other corner with a scroll on top of it." << endl;
                    cout << "On the north wall there is the door leading to the jail room." << endl;
                }
            }
            /*********************************************************************/
            
            //duplicate code... check
            //else if (command == "passageway door" || command == "passageway" || command == "go down passageway"
            //    || command == "go to passageway" || command == "go down passageway door"
            //    || command == "go into passageway" || command == "go up passageway" || command == "go in passageway")
            //{
            //    cout << "You proceed to venture down the dark passageway." << endl;
            //    wentToCookieRoom = true;
            //    wentToMapRoom = false;
            //    break;
            //}
            else if (command == "go to jail room" || command == "go to previous room" || command == "enter jail room"
                || command == "go back to jail room" || command == "exit to jail room"
                || command == "go out to jail room" || command == "go into jail room" || command == "jail" || command == "jail room")
            {
                cout << "You went back to the jail room" << endl;
                wentToJailRoom = true;
                wentToMapRoom = false;
            }
            else if (command == "exit room" || command == " go through door" || command == "go out door"
                || command == " go into room" || command == "go in room")
            {

                cout << " Which door? The passageway door or the jail door?" << endl;

                if (command == "passageway door" || command == "passageway" || command == "go down passageway"
                    || command == "go to passageway" || command == "go down passageway door"
                    || command == "go into passageway" || command == "go up passageway" || command == "go in passageway")
                {
                    cout << "You proceed to venture down the dark passageway." << endl;
                    wentToCookieRoom = true;
                    wentToMapRoom = false;
                    break;
                }
                else if (command == "go to jail room" || command == "go to previous room" || command == "enter jail room"
                    || command == "go back to jail room" || command == "exit to jail room"
                    || command == "go out to jail room" || command == "go into jail room" || command == "jail" || command == "jail room")
                    cout << "You went back to the jail room" << endl;
                wentToJailRoom = true;
                wentToMapRoom = false;
                break;
            }

            else if (command == "go in hall" || command == "go down hall" || command == "go down passageway"
                || command == "go to passageway" || command == "go down passageway door" || command == "go into passageway"
                || command == "go up passageway" || command == "passageway door" || command == "go down passage" || command == "go up passage"
                || command == "passageway" || command == "go in passageway" || command == "go to hall"
                || command == "enter hall" || command == "enter passage")
            {
                cout << "You proceed to venture down the dark passageway." << endl;
                wentToCookieRoom = true;
                wentToMapRoom = false;
                break;

            }


            else
            {
                cout << "What do you mean by \"" << command << "?\" Try a different command..." << endl << endl;
            }


        } while (wentToMapRoom == true || wentToCookieRoom == false || wentToJailRoom == false);
    }


    void killer_cookie_room()
        /************************************************************************/
        /*                                                                      */
        /*                           THE COOKIE ROOM                            */
        /*                                                                      */
        /************************************************************************/

        //TODO: Lightning good idea or bad idea?
        //TODO: Create timer for action
        //TODO: incorporate hug wug to act as a sheild/ second chance but kill him if attacked
    {
        do
        {
            if (cookiesDead == false)
            {
                cout << "As the eerie sounds of loud crunching, slurping,\nand crying get louder and louder," << endl;
                cout << "you finally reach the end of the hall, and see what is making all that noise.\n\n" << endl;
                cout << "There, standing up the middle of the room,\nare the too large cookies from" << endl;
                cout << "before. The one on the left gulped down\nits last bite, the while other stifled a cry " << endl;
                cout << "suffering from with what looked to be a large bloody bite mark out of it." << endl;
                cout << "They both stare back at you with dark, large,\nsunken bloody pits from where their eyes used to be." << endl;
                cout << "A look of endless hunger consumes the spooky,\ndark aura surrounding them." << endl;
                cout << "\n\nCarefully, they start to crawl towards you." << endl;

            }

                //TODO: Create action timer to make a descion to either go back or fight. if timer runs out before decision is made, the cookies eat you.
            getCommand();

            if (command == "throw ninja stars" || command == "throw milk ninja stars" || command == "throw stars"
                || command == "throw stars at cookies" || command == "throw ninja stars at cookies" || command == "throw milk ninja stars at cookies")
            {
                if (gotNinjaStars == true && cookiesDead == false)
                {
                    cout << "You throw the ninja stars at the cookies and they suddenly " << endl;
                    cout << "disintegrate into a mushy mess while screaming in torment on the floor in front of you." << endl;
                    cout << " In the corner of the room a treasure chest appears!" << endl << endl;
                    cout << "On the side of the room, you also notice a dark doorway appear!" << endl;
                    cookiesDead = true;
                    cookieTreasureChestAppears = true;
                }
                else if (gotNinjaStars == false && cookiesDead == false)
                {
                    cout << "What are you talking about! You have no ninja stars!" << endl;
                    cout << "All of the sudden, the evil blood thristy cookies pounce on you" << endl;
                    cout << "and proceed to tear you apart with there large needle-like teeth\nas you scream in agony until your last breath." << endl;
                    cakeGameOver();
                    break;
                }
                else if (cookiesDead == true)
                {
                    cout << "What are you throwing at? There is nothing there!" << endl;
                }
            }
            else if (command == "open chest" || command == "go to chest" || command == "go to treasure chest" ||
                command == "open treasure chest" || command == "look at chest" || command == "examine chest" ||
                command == "look at treasure chest" || (command == "examine treasure chest" && cookiesDead == true))
            {
                if (canShootLightning == false)
                {
                    cout << "You open the chest to find an old Book of Spells... You learned how to shoot lightning!" << endl;
                    cout << "(Spell Book added to inventory)" << endl;
                    items.push_back("Spell Book"); // Spell Book added to inventory vector
                    canShootLightning = true;
                }
                else if (canShootLightning == true)
                {
                    cout << "You examine the large empty chest" << endl;
                }
            }
            else if (command == "go back" || command == "go to map room" || command == "go back to map room" || command == "run away")
            {
                if (cookiesDead == false)
                {
                    cout << "You race back down the hall, through the door, and quickly shut and lock it. " << endl;
                    cookieDoorUnlocked = false;
                    wentToMapRoom = true;
                    wentToCookieRoom = false;
                    break;
                }
                else if (cookiesDead == true)
                {
                    cout << "You proceed to the Map Room" << endl;
                }
            }
            else if (command == "go to side doorway" || command == "go to doorway" || command == "go to vegetable doorway" || command == "step through doorway" || command == "look at doorway" || (command == "examine doorway" && cookiesDead == true))
            {
                cout << "You go through the doorway and look around to see" << endl;
                cout << "a long room." << endl;
                wentToCookieRoom = false;
                wentToZombieRoom = true;
                break;
            }
            /************************| LOOK AROUND COMMAND |**********************/
            else if (command == "look around" || command == "examine room" || command == "investigate room")
            {
                if (cookiesDead == false && cookieTreasureChestAppears == false && canShootLightning == false)
                {
                    cout << "In the middle of the room, are the too large cookies." << endl;
                    cout << "They both stare back at you with dark, large, sunken bloody pits from where their eyes used to be." << endl;
                    cout << "A look of endless hunger consumes the spooky, dark aura surrounding them." << endl;
                    cout << "\n\nSlowly, they start to crawl towards you." << endl;
                }
                else if (cookiesDead == true && cookieTreasureChestAppears == true && canShootLightning == false)
                {
                    cout << "In the middle of the room is the puddle of mush where the cookies used to stand." << endl;
                    cout << "On the far side of the room, a chest sits in the dark" << endl;
                    cout << "On the side of the room, you also notice a dark doorway." << endl;
                    cout << "Down the passageway, the Map Room Door..." << endl;

                }
                else if (cookiesDead == true && cookieTreasureChestAppears == true && canShootLightning == true)
                {
                    cout << "In the middle of the room is the puddle of mush where the cookies used to stand." << endl;
                    cout << "On the far side of the room, an opened chest sits in the dark" << endl;
                    cout << "On the side of the room, you notice a closed door, and down the passageway, the Map Room Door..." << endl;
                }
            }
            /*********************************************************************/

            //command statements that go in every room function
            else if (command == "inventory" || command == "items" || command == "bag" || command == "look in bag" || command == "look in inventory")
            {
                inventory();
            }
            else if (command == "map" || command == "open map" || command == "look at map" || command == "examine map" || (command == "read map" && gotMap == true))
            {
                map();
            }
            else if (command == "secret map")
            {
                secretMap();
            }
            else if (command == "commands")
            {
                commands();
            }
            else if (command == "pinch yourself" || command == "quit" || command == "exit")
            { //exits out of game
            cakeGameOver();
            break;
            }
            else if (command == "where am i?")
            {
            hereYouAre();;
            }
            else
            {
                cout << "What do you mean by \"" << command << "?\" Try a different command..." << endl << endl;
                continue;
            }

        } while (wentToCookieRoom == true || wentToZombieRoom == false || wentToMapRoom == false);
    }

    void zombie_vegetable_room()
    {
        /************************************************************************/
        /*                                                                      */
        /*                           THE ZOMBIE VEGETABLE ROOM                  */
        /*                                                                      */
        /************************************************************************/
        // you see 2 dead and rotting vegetables in the room.
        // one of them appears to be moving
        // you go up to Brock Killie and he grabs you by the shirt and proceeds
        //to shout while shaking you,
        // "WHY!? WHY DIDN'T YOU EAT YOUR VEGETABLES LOGAN! Now me are nothing
        // but rotting zom..bies..."
        //
        // Brock slowly slumps and loosens his grip a little and says,
        // "Are you even sorry? You should apologize..."
        //
        // You hear something in the background. You turn around to see Care Rot
        // standing up and looking hungrily at you...
        //
        //the vegetables eat you if you don't apologize. they help you by opening the boss
        //door if you do apologize or say you're sorry
        //TODO: milk ninja stars do nothing
        //TODO: stuns them for more time * or * lighting tickles them (this seems easier) ... maybe lighting a bad idea
        do
        {



            if (talkedToBrockKillie == false)
            {
                cout << "You notice two large, dead-looking, rotting vegetables in the room.\nOne of them appears to be moving" << endl;
                cout << "The wiggling broccoli calls out to you in a weak voice,\n\"I am Brock Killie. Please... Come closer...\"" << endl;
            }
            //else if (talkedToBrockKillie == true)
            //{
             //   cout << "You notice two large, dead-looking, rotting vegetables in the room.\nOn one side, an open doorway leading to the cookie room.\n On the other side, a closed door." << endl;
            //}

            getCommand();

            if (command == "talk to broccoli" || command == "walk to broccoli" || command == "run to broccoli"
                || command == "examine broccoli" || command == "investigate broccoli" || command == "walk to brock killie"
                || command == "walk to brock" || command == "go to brock killie" || command == "go to brock"
                || command == "talk to brock" || command == "examine brock killie" || (command == "examine brock" && talkedToBrockKillie == false))
            {
                talkedToBrockKillie = true;// timer starts immediately, so i added some time to it for reading
                cout << "You go up to Brock Killie and he grabs you by the shirt and proceeds" << endl;
                cout << "to shout while shaking you," << endl;
                cout << "\"WHY!? WHY DIDN'T YOU EAT YOUR VEGETABLES LOGAN! Now we are nothing" << endl;
                cout << "but rotting zom..bies...\"\n" << endl;
                cout << "You here something in the background." << endl;
                cout << "You turn around to see a large bloodied carrot standing up and looking hungrily at you.." << endl;
                cout << "Brock slowy slumps and loosens his grip a little and says,\n\"I\'m giving you 10 seconds to apologize...\"" << endl;
                thread timer(twentySecondTimer);//TODO: threaded timer... is there a better way to do this?
                timedAnswer();
                timer.join();
            }
            else if (command == "look at carrot" || command == "look at care rot" || (command == "look at other vegetable" && talkedToBrockKillie == false))
            {
                cout << "The carrot looks to be a zombie." << endl;
            }
            else if (command == "open door" || command == "examine door" || command == "investigate door")
            {
                cout << "You proceed to the door, open it, and step inside the large dark room." << endl;
                cout << "Behind you, the door vanishes to wall. There is a large snoring sound in the room..." << endl;
                wentToZombieRoom = false;
                wentToBossRoom = true;
                break;

            }
            /************************| LOOK AROUND COMMAND |**********************/
            else if (command == "look around" || command == "examine room" || command == "investigate room")
            {
                if (talkedToBrockKillie == false)
                {
                    cout << "You notice two large, dead-looking, rotting vegtables in the room.\nOne of them appears to be moving" << endl;
                    cout << "The wiggling broccoli calls out to you in a weak voice,\n\"I am Brock Killie. Please... Come closer...\"" << endl;
                }
                else if (talkedToBrockKillie == true)
                {
                    cout << "There are two large, dead, rotting vegtables in the room.\nOn one side, an open doorway leading to the cookie room.\n On the other side, a closed door." << endl;
                }
            }
            /*********************************************************************/

            //command statements that go in every room function

            else if (command == "inventory" || command == "items" || command == "bag" || command == "look in bag" || command == "look in inventory")
            {
                inventory();
            }
            else if (command == "map" || command == "open map" || command == "look at map" || command == "examine map" || (command == "read map" && gotMap == true))
            {
                map();
            }
            else if (command == "secret map")
            {
                secretMap();
            }
            else if (command == "commands")
            {
                commands();
            }
            else if (command == "pinch yourself" || command == "quit" || command == "exit")
            { //exits out of game
                cakeGameOver();
                break;
            }
            else if (command == "where am i?")
            {
                hereYouAre();
            }
            else
            {
                cout << "What do you mean by \"" << command << "?\" Try a different command..." << endl << endl;
                continue;
            }




        } while (wentToZombieRoom == true && wentToCookieRoom == false && wentToBossRoom == false);
    };

    void boss_room()
    {
        /************************************************************************/
        /*                                                                      */
        /*                           THE BOSS ROOM                              */
        /*                                                                      */
        /************************************************************************/
        // Create ability to hide in chest-- maybe possibly restart the timer or chase
        //cake boss room has dead bodies everywhere
        // the boss is sleeping but will wake up if you try to open the chest, exit the room, attack him or touch him
        // the boss will fall back asleep if you hide in the chest for a short amount of time.
        // after the boss wakes up you have a limited amount of time to either hide or go to death room
        // milk ninja stars wake him up and/or piss him off
        // lighting can wake him up and/or stun him for ten seconds... should we get rid of lightning?

        do
        {
            if (cakeIsAwake == false && inChest == false)
            {
                cout << "You turn around and see a giant piece of cake sleeping in the corner." << endl;
                cout << "It's large mouth gapping open with blood-stained needle-sharp teeth,\nglistening in the lantern\'s light." << endl;
                cout << "You notice a chest in the corner." << endl;
            }
            else if (cakeIsAwake == true & inChest == false)
            {
                //start cake timer
                cout << "The cake is coming after you!" << endl;
            }

            getCommand();

            if (command == "go to chest" || command == "check out chest" || command == "look at chest"
                || command == "open chest" || command == "examine chest" || command == "investigate chest")
            {
                if (cakeIsAwake == false)
                {
                    //cake timer starts
                    cout << "As you slowly open the large chest, it lets out a loud creek as you find out it is empty." << endl;
                    cout << "The cake suddenly becomes quiet." << endl;
                    cout << "You slowly turn around and find that the cake is" << endl;
                    cout << "staring directly at you" << endl;
                    cakeIsAwake == true;
                }
                else if (cakeIsAwake == true)
                {
                    // cout << "Do you want to climb in the chest?" << endl;


                    if (command == "go in chest" || command == "go inside chest")
                    {
                        //cake timer resets and than starts again after you exit the chest
                        cout << "You hide inside the chest and listen. After a while, the cake starts snoring again." << endl;
                        cout << "Do you want to climb out of the chest?" << endl;
                        cakeIsAwake = false;
                        inChest = true;

                        if (command == "yes" || command == "get out" || command == "climb out" || command == "climb out of chest")
                        {
                            inChest = false;
                            cakeIsAwake = true;
                            cout << "The treasure chest creaked loudly as you exited the chest." << endl;
                            cout << "The cake suddenly becomes quiet." << endl;
                            cout << "You slowly turn around and find that the cake is" << endl;
                            cout << "staring directly at you" << endl;
                            //Cake timer starts again
                        }
                        else if (command == "no" || command == "get out of chest" || command == "get out"
                            || command == "climb out" || command == "climb out of chest")
                        {
                            cout << "You stay in the chest a while longer" << endl;
                        }
                    }

                }
            }
            /**********************duplicate chest code*****************************/
            //TODO: fix it
            else if (command == "go in chest" || command == "go inside chest")
            {
                //cake timer resets and than starts again after you exit the chest
                cout << "You hide inside the chest and listen. After a while, the cake starts snoring again." << endl;
                cout << "Do you want to climb out of the chest?" << endl;
                cakeIsAwake = false;
                inChest = true;

                if (command == "yes" || command == "get out" || command == "climb out" || command == "climb out of chest")
                {
                    inChest = false;
                    cakeIsAwake = true;
                    cout << "The treasure chest creaked loudly as you exited the chest." << endl;
                    cout << "The cake suddenly becomes quiet." << endl;
                    cout << "You slowly turn around and find that the cake is" << endl;
                    cout << "staring directly at you" << endl;
                    //Cake timer starts 
                }
                else if (command == "no" || command == "stay in chest" || command == "stay in"
                    || command == "stay" || command == "stay here")
                {
                    cout << "You stay in the chest a while longer" << endl;
                }
            }
            /***********************************************************************/
            else if (command == "go to cake" || command == "examine cake" || command == "investigate chest"
                || command == "check out the cake" || command == "check out cake" || command == "look at cake"
                || command == " cake")
            {
                cout << "You walk up to the cake as it let out another loud snore." << endl;
                cout << "It seems to be sleeping soundly." << endl;
            }
            else if (command == "attack cake" || command == "throw stars" || command == "throw stars at cake"
                || command == "throw ninja stars" || command == "throw ninja milk stars"
                || command == "throw milk stars" || command == "throw ninja stars at cake"
                || command == "throw ninja milk stars at cake" || command == "poke cake"
                || command == "touch cake")
            {
                if (cakeIsAwake == false)
                {
                    cout << "The the cake wakes up with loud a rowr and and proceeds to chase you." << endl;
                    cakeIsAwake == true;
                    //cake timer starts
                }
                else if (cakeIsAwake == true)
                {
                    cout << "That seems to do nothing but make him even more angry!" << endl;
                }
            }
            else if (command == "lightning" || command == "shoot lightning")
            {

                if (cakeIsAwake == true)
                {
                    //cake timer stops for a certain amount of time before starting again (or time is added to cake timer)
                    cout << "That seemed to have stunned the cake for a few seconds..." << endl;
                    cakeStunned = true;
                }
                else if (cakeIsAwake == false)
                {
                    cout << "The the cake wakes up with loud a rowr!" << endl;
                    cout << "That seemed to have stunned the cake for a few seconds..." << endl;
                    cakeIsAwake = true;
                    cakeStunned = true;
                }
            }
            else if (command == "go to door" || command == "run to door" || command == "door" || command == "run away")// exits room and goes to the DEATH ROOM. 0_0
            {
            cout << "The turns around and starts to come after you!" << endl;
                cout << "You run to the door and escaped into a dark room." << endl;
                wentToBossRoom = false;
                wentToDeathRoom = true;
                cakeIsAwake = true;
                break;
            }
            /************************| LOOK AROUND COMMAND |**********************/
            else if (command == "look around" || command == "examine room" || command == "investigate room")
            {

                if (cakeIsAwake == false)
                {
                    cout << "A giant piece of cake snores in the corner." << endl;
                    cout << "It's large mouth gapping open with blood-stained needle-sharp teeth,\nglistening in the lantern\'s light." << endl;
                    cout << "A chest is in the corner." << endl;
                }
                else if (cakeIsAwake == true)
                {
                    cout << "The cake is coming after you!" << endl;
                }
                else if (inChest == true)
                {
                    cout << "You are hiding in a chest" << endl;
                }

            }


            //command statements that go in every room function
            else if (command == "inventory" || command == "items" || command == "bag" || command == "look in bag" || command == "look in inventory")
            {
                inventory();
            }
            else if (command == "map" || command == "open map" || command == "look at map" || command == "examine map" || (command == "read map" && gotMap == true))
            {
                map();
            }
            else if (command == "secret map")
            {
            secretMap();
            }
            else if (command == "commands")
            {
                commands();
            }
            else if (command == "pinch yourself" || command == "quit" || command == "exit")
            { //exits out of game
                cout << "You wake up and notice that you fell out of the bed and hit your head! Ouch!\n\n" << endl;
                cakeGameOver();
                break;
            }
            else if (command == "where am i?")
            {
            hereYouAre();
            }
            else
            {
                cout << "What do you mean by \"" << command << "?\" Try a different command..." << endl << endl;
                continue;
            }


        } while (wentToBossRoom == true && wentToDeathRoom == false);
    }
    void death_room()
    {
        /************************************************************************/
        /*                                                                      */
        /*                           THE DEATH ROOM                             */
        /*                                                                      */
        /************************************************************************/
         // huggy wuggy turns to fight the boss cake so that you may escape.
         // he will die trying to save you, but you have the opportunity to come back
         // and save him.
        do
        {

            cout << "Inside the dark room, you notice piles of bones scattered everywhere." << endl;
            cout << "The smell of death and rotting flesh permeates throughout the room." << endl;
            cout << "In the far corner of the room, you notice a chest,\nand on the other side of the room there is a closed door with a golden lock." << endl;

            getCommand();

            if (command == "go to chest" || command == "open chest" || command == "check out chest"
                || command == "look at chest" || command == "examine chest" || command == "investigate chest")
            {
                cout << "You walk over to the chest and open it.\nInside you find a golden key." << endl;
                cout << "Golden Key added to inventory" << endl;
                cout << "With a loud crash, the evil man-eating cake enters the room." << endl;
                
                if (huggyWuggyAlive == false || huggyWuggyFreed == false)
                {
                    // cake timer starts
                    cout << "The cake starts chasing you!" << endl;
                    // if you get to the other room before the timer is up you get the timer reset
                    // until you kill the cake with the master fork
                }
                else if (huggyWuggyFreed == true && huggyWuggyAlive == true)
                {
                    cout << "Huggy Wuggy proceeds to battle the cake.\nHe can hold him off for as long it will take you to escape." << endl;
                 //no cake timer. huggy wuggy fights off the cake until you are able to get to the master fork
                }            
                
                items.push_back("Golden Key");//Golden key added to inventory vector
                goldenKeyInInventory = true;

            }
            else if (command == "go to door" || command == "unlock door" || command == "examine door"
                || command == "investigate door" || command == "open door")
            {
                cout << "Which door? The door with the golden lock, or the door leading back to the cake room?" << endl;

            }
            if (command == "go to locked door" || command == "locked door" || command == "go to the locked door"
                || command == "go to the door with the golden lock" || command == "the locked door")
                {
                    if (goldenKeyInInventory == true)
                    {
                        cout << "You unlock and step through the door into a brightly lit room.\nIt takes a moment for your eyes to adjust..." << endl;
                        wentToDeathRoom = false;
                        wentToMasterForkRoom = true;

                    }
                    else if (goldenKeyInInventory == false)
                    {
                        cout << "The door is locked." << endl;
                    }
            }
            else if (command == "cake room" || command == "go to cake room"
                    || command == "go to the cake room" || command == "go back" || command == " go back to the cake room")
            {
                   cout << "You go back to the Cake Room" << endl;
                   wentToDeathRoom = false;
                   wentToBossRoom = true;
                   cakeIsAwake = true;
            }
            //command statements that go in every room function

           else if (command == "inventory" || command == "items" || command == "bag" 
                   || command == "look in bag" || command == "look in inventory")
           {
               inventory();
           }
           else if (command == "map" || command == "open map" || command == "look at map" 
                   || command == "examine map" || (command == "read map" && gotMap == true))
           {
               map();
           }            else if (command == "secret map")
           {
               secretMap();
           }
           else if (command == "commands")
           {
               commands();
           }
          else if (command == "pinch yourself" || command == "quit" || command == "exit")
           { //exits out of game
                cakeGameOver();
                break;
           }
           else if (command == "where am i?")            {
                hereYouAre();
           }
           else
           {
               cout << "What do you mean by \"" << command << "?\" Try a different command..." << endl << endl;
               continue;
           }






        } while (wentToDeathRoom == true);
    }


        void master_fork_room()
        {
            /************************************************************************/
            /*                                                                      */
            /*                       THE MASTER FORK ROOM                           */
            /*                                                                      */
            /************************************************************************/
            do
            {


                // you grab the master fork and have the opportunity to either escape or go back and save huggy wuggy
                // if you go back to save huggy wuggy, you defeat the boss with one blow
                //if you try to escape huggy wuggy dies and the cake boss  comes and fights you.
                // he sees you have the master fork and proceeds to run away.
                // in order to kill him, you must chase him and hit him before a certain amount
                // of time before he escapes to another room.
                // you must hit him 1 time with the fork, or three times with the ninja stars
                // you can stun him and stop time with lighting power
                // you escape the nightmare after killing him
                // and wake up in your own bed with your huggy wuggy stuffed animal if you saved him
                // along with all of your other treasures stored in a little treasure chest in your room.




                cout << "You enter the bright room and find there is a pedestal in the corner." << endl;

                if (command == "go to pedestal" || command == "walk to pedestal" || command == "examine pedestal" || command == "investigate pedestal" || command == "check out pedestal")
                {
                    cout << "As you get closer to the pedestal, a light comsumes it\nand becomes so bright that it blinds you for a moment." << endl;
                    cout << "As the light dims, you notice before you a large golden fork. The Master Fork!" << endl;
                    wentToPedestal = true;
                }
                else if (command == "grab the master fork" || command == "get master fork" || command == "get the master fork"
                    || command == "look at master fork" || command == "examine master fork" || command == "get master fork"
                    || command == "get the master fork" || command == "take the master fork" || command == "take master fork")
                {
                    if (masterForkInInventory == false && wentToPedestal == true)
                    {
                        cout << "Congratulations! You got the Master Fork!" << endl;
                        items.push_back("Master Fork");//Master Fork added to inventory vector
                        masterForkInInventory = true;
                    }
                    else if (masterForkInInventory == false && wentToPedestal == false)
                    {
                        cout << "What are talking about?\n\n\Maybe you should check out the pedistal over there..." << endl;
                    }
                    else if (masterForkInInventory == true)
                    {
                        cout << "You hold the master fork in your hands as you raise it above your head!" << endl;
                    }
                    /************************| LOOK AROUND COMMAND |**********************/
                    else if (command == "look around" || command == "examine room" || command == "investigate room")
                    {
                        if (wentToPedestal == false && masterForkInInventory == false)
                        {
                            cout << "In the room there is a pedestal in the corner with a bright ray of light shining down on it." << endl;
                        }
                        else if (wentToPedestal == true && masterForkInInventory == false)
                        {
                            cout << "In the corner of the room rests the golden Master Fork on its pedistal." << endl;
                        }
                        else if (wentToPedestal == true && masterForkInInventory == true)
                        {
                            cout << "In the room there is a pedestal in the corner with a bright ray of light shining down on it." << endl;
                        }
                    }
                    
                    //command statements that go in every room function

                    else if (command == "inventory" || command == "items" || command == "bag"
                        || command == "look in bag" || command == "look in inventory")
                    {
                        inventory();
                    }
                    else if (command == "map" || command == "open map" || command == "look at map"
                        || command == "examine map" || (command == "read map" && gotMap == true))
                    {
                        map();
                    }
                    else if (command == "secret map")
                    {
                        secretMap();
                    }
                    else if (command == "commands")
                    {
                        commands();
                    }
                    else if (command == "pinch yourself" || command == "quit" || command == "exit")
                    { //exits out of game
                        cakeGameOver();
                        break;
                    }
                    else if (command == "where am i?")
                    {
                        hereYouAre();
                    }
                    else
                    {
                        cout << "What do you mean by \"" << command << "?\" Try a different command..." << endl << endl;
                        continue;
                    }
                }

            } while (wentToMasterForkRoom == true);

        }


        void ending()
        {
            /************************************************************************/
            /*                                                                      */
            /*                              THE ENDING                              */
            /*                                                                      */
            /************************************************************************/

            cout << "_________________________________________________________________" << endl;
            cout << "|                                    |\\__________/|              |" << endl;
            cout << "|                                    |   _   _    |              |" << endl;
            cout << "|                                    |__|.|_|.|___|              |" << endl;
            cout << "|                                    \\\\/\\/\\/\\/\\/\\//              |" << endl;
            cout << "|                                     \\\\/\\/\\/\\/\\//               |" << endl;
            cout << "|          ^ ^ ^                       ----------                |" << endl;
            cout << "|         ||||||    ||||||||           ___|  |___                |" << endl;
            cout << "|         ||||||   _| _  _ |_         |          |               |" << endl;
            cout << "|          \\  /   |_|| || ||_|        | ||     | |               |" << endl;                       
            cout << "|           ||      |  _   |          | ||     | |               |" << endl;                   
            cout << "|           ||       \\_==_/           | ||     | |               |" << endl;                      
            cout << "|           ||-________||____         |_||  __ |_|               |" << endl;                     
            cout << "|           |_|_|_____      __\\       |_|| | | |_|               |" << endl;
            cout << "|           ||       |     || |          | | | |                 |" << endl;
            cout << "|           ||       |     | /           | | | |                 |" << endl;
            cout << "|           ||       |_____|/            | | | |                 |" << endl;
            cout << "|          /  \\      |     |             | | | |                 |" << endl;
            cout << "|          \\__/      |  |  |             | | | |                 |" << endl;
            cout << "|                    |  |  |             | | | |                 |" << endl;
            cout << "|                   _|__|__|_           _|_| |_|_                |" << endl;
            cout << "|__________________|____|____|_________|___|_|___|_______________|" << endl;
            cout << "|  _______   _    _   _____          _____   __     _     ___    |" << endl;
            cout << "| |__   __| | |  | | |  ___|        |  ___| |  \\   | |   |  _\\   |" << endl;
            cout << "|    | |    | |__| | | |_           | |_    |   \\  | |   | | \\\\  |" << endl;
            cout << "|    | |    |  __  | |  _|          |  _|   | |\\ \\ | |   | | / | |" << endl;
            cout << "|    | |    | |  | | | |___         | |___  | | \\ \\| |   | |/ /  |" << endl;
            cout << "|    |_|    |_|  |_| |_____|        |_____| |_|  \\___|   |___/   |" << endl;
            cout << "|================================================================|" << endl; 


            // Create a super cool ascii art ending? Credits?

            cout << "You WON! The End!" << endl;
            


        }

        void title_menu()
        {
            
            


                /************************************************************************/
                /*                                                                      */
                /*                         Title Menu Page                              */
                /*                                                                      */
                /************************************************************************/
                              

                // FIRST DESIGN              
                    //cout << "**************************************************************************************" << endl;
                    //cout << "*  ____                                ____      ___                     __          *" << endl;
                    //cout << "*  |  |  Josh Townson's           ___  |  |      | |            ___   __|  |__       *" << endl;
                    //cout << "*  |  |_____ ______ _______ _____ | /__|  |______| |___ ____---\\  |__|__   ___|      *" << endl;
                    //cout << "*  |  |  _  |      |       |     ||/   |  |      |     | | |  --\\_|     |  |  |      *" << endl;
                    //cout << "*  |  | | | | |--| | |-|   |  |  |   --|  | |-|  | |-| | | |  ||  |  |  |  |  |__    *" << endl;
                    //cout << "*  |  | |_| | |--| | |_|   |  |  |--   |  | |_|  | |_| | | |  ||  |  |  |  |     |   *" << endl;
                    //cout << "*  |  |_____|____  |_____|_|__|__|_____|  |____|_|_____|__ |__||__|__|__|__|__|__|   *" << endl;
                    //cout << "*  |________|______|                   |_________|    |____|                         *" << endl;
                    //cout << "*     A text-based adventure horror game directed by Logan Townson                   *" << endl;
                    //cout << "**************************************************************************************" << endl;
                    //cout << "|-----------------------__      __     ____     _____   _     _ ---------------------|" << endl;
                    //cout << "|----------------------|  \\    /  |   /____\\   |__ __| | \\   | |---------------------|" << endl;
                    //cout << "|----------------------| |\\\\  //| |  //____\\\\    | |   |  \\  | |---------------------|" << endl;
                    //cout << "|----------------------| | \\\\// | | / ______ \\   | |   | |\\\\ | |---------------------|" << endl;
                    //cout << "|----------------------| |      | | | |    | |  _| |_  | | \\\\| |---------------------|" << endl;
                    //cout << "|----------------------|_|      |_| |_|    |_| |_____| |_|  \\__|---------------------|" << endl;
                    //cout << "|------------------------------------------------------------------------------------|" << endl;
                    //cout << "|--------------------------------|\\  /| |--- |\\  | |  |------------------------------|" << endl;
                    //cout << "|--------------------------------| \\/ | |--  | \\ | |  |------------------------------|" << endl;
                    //cout << "|--------------------------------|    | |--- |  \\| |__|------------------------------|" << endl;
                    //cout << "|--------------------------------- _____________________ ----------------------------|" << endl;
                    //cout << "|---------------------------------|                     |----------------------------|" << endl;
                    //cout << "|-------------------------------- |       START         |----------------------------|" << endl;
                    //cout << "|---------------------------------|_____________________|----------------------------|" << endl;
                    //cout << "|-------------------------------- ______________________ ----------------------------|" << endl;
                    //cout << "|--------------------------------|                      |----------------------------|" << endl;
                    //cout << "|--------------------------------|     SELECT LEVEL     |----------------------------|" << endl;
                    //cout << "|--------------------------------|______________________|----------------------------|" << endl;
                    //cout << "|-------------------------------- ______________________ ----------------------------|" << endl;
                    //cout << "|--------------------------------|                      |----------------------------|" << endl;
                    //cout << "|--------------------------------|         QUIT         |----------------------------|" << endl;
                    //cout << "|--------------------------------|______________________|----------------------------|" << endl;
                    //cout << "|____________________________________________________________________________________| " << endl;

                    //SECOND DESIGN
                cout << " ____________________________________________________________________________________" << endl;
                cout << "|                                                                                    |" << endl;
                cout << "|  ____                                ____      ___                     __          |" << endl;
                cout << "|  |  |  Josh Townson's           ___  |  |      | |            ___   __|  |__       |" << endl;
                cout << "|  |  |_____ ______ _______ _____ | /__|  |______| |___ ____---\\  |__|__   ___|      |" << endl;
                cout << "|  |  |  _  |      |       |     ||/   |  |      |     | | |  --\\_|     |  |  |      |" << endl;
                cout << "|  |  | | | | |--| | |-|   |  |  |   --|  | |-|  | |-| | | |  ||  |  |  |  |  |__    |" << endl;
                cout << "|  |  | |_| | |--| | |_|   |  |  |--   |  | |_|  | |_| | | |  ||  |  |  |  |     |   |" << endl;
                cout << "|  |  |_____|____  |_____|_|__|__|_____|  |____|_|_____|__ |__||__|__|__|__|__|__|   |" << endl;
                cout << "|  |________|______|                   |_________|    |____|                         |" << endl;
                cout << "|     A text-based adventure horror game directed by Logan Townson                   |" << endl;
                cout << "|____________________________________________________________________________________|" << endl;
                cout << "|____________________________________________________________________________________|" << endl;
                cout << "|  __      __     ____     _____   _     _    __      __   _____   __     _   _   _  |" << endl;
                cout << "| |  \\    /  |   /____\\   |__ __| | \\   | |  |  \\    /  | |  ___| |  \\   | | | | | | |" << endl;
                cout << "| | |\\\\__//| |  //____\\\\    | |   |  \\  | |  | |\\\\__//| | | |__   | |\\\\  | | | | | | |" << endl;
                cout << "| | | \\__/ | | /  ____  \\   | |   | |\\\\ | |  | | \\__/ | | |  __|  | | \\\\ | | | | | | |" << endl;
                cout << "| | |      | | | |    | |  _| |_  | | \\\\| |  | |      | | | |___  | |  \\\\| | | |_| | |" << endl;
                cout << "| |_|      |_| |_|    |_| |_____| |_|  \\__|  |_|      |_| |_____| |_|   \\__| |_____| |" << endl;
                cout << "|____________________________________________________________________________________|" << endl;
                cout << "|__|____|____|____|____|____|____|____|____|____|____|____|____|____|____|____|____|_|" << endl;
                cout << "|____|____|____|____|____|____|_  ______________________  __|____|____|____|____|____|" << endl;
                cout << "|__|____|____|____|____|____|___ |                      | |____|____|____|____|____|_|" << endl;
                cout << "|____|____|____|____|____|____|_ |        START         | __|____|____|____|____|____|" << endl;
                cout << "|__|____|____|____|____|____|___ |______________________| |____|____|____|____|____|_|" << endl;
                cout << "|____|____|____|____|____|____|_  ______________________  __|____|____|____|____|____|" << endl;
                cout << "|__|____|____|____|____|____|___ |                      | |____|____|____|____|____|_|" << endl;
                cout << "|____|____|____|____|____|____|_ |     SELECT LEVEL     | __|____|____|____|____|____|" << endl;
                cout << "|__|____|____|____|____|____|___ |______________________| |____|____|____|____|____|_|" << endl;
                cout << "|____|____|____|____|____|____|_  ______________________  __|____|____|____|____|____|" << endl;
                cout << "|__|____|____|____|____|____|___ |                      | |____|____|____|____|____|_|" << endl;
                cout << "|____|____|____|____|____|____|_ |         QUIT         | __|____|____|____|____|____|" << endl;
                cout << "|__|____|____|____|____|____|___ |______________________| |____|____|____|____|____|_|" << endl;
                cout << "|____|____|____|____|____|____|_____________________________|____|____|____|____|____|" << endl;

               do

               {
                cout << "\nWhat do you wish to do?" << endl;

                getCommand();

                if (command == "start")
                {
                    beginning = true;
                    title = false;
                }
                else if (command == "select level")

                {
                    title = false;
                    selection = true;
                }
                else if (command == "quit")
                {
                    title = false;
                    stillAlive = false;
                }
                else
                {
                    cout << "What do you mean by \"" << command << "?\" Try a different command..." << endl << endl;
                    continue;
                }
            }while (title == true);
        } 

        void level_selection()

            //TODO: Set up parameters
           
        {
            cout << " ______________________________________________________________________________ " << endl;
            cout << "|  _______ _____ _     _____ ____ _______     _     _____ _    _ _____ _       |" << endl;
            cout << "|  |      |  ___| |   |  ___|  __|__   __|   | |   |  ___| |  | |  ___| |      |" << endl;
            cout << "|  |   ___| |_  | |   | |_  | |     | |      | |   | |_  | |  | | |_  | |      |" << endl;
            cout << "|  |___   |  _| | |   |  _| | |     | |      | |   |  _| | |  | |  _| | |      |" << endl;
            cout << "|  |      | |___| |___| |___| |__   | |      | |___| |___ \\ \\/ /| |___| |___   |" << endl;
            cout << "|  |______|_____|_____|_____|____|  |_|      |_____|_____| \\__/ |_____|_____|  |" << endl;
            cout << "|______________________________________________________________________________|" << endl;
            cout << "|                                                                              |" << endl;
            cout << "|    ____________                 ___________                     __________   |" << endl;
            cout << "|   | START ROOM |               | JAIL ROOM |                   | MAP ROOM |  |" << endl;
            cout << "|    ------------                 -----------                     ----------   |" << endl;
            cout << "|    _____________               _____________                   ___________   |" << endl;
            cout << "|   | COOKIE ROOM |             | ZOMBIE ROOM |                 | BOSS ROOM |  |" << endl;
            cout << "|    -------------               -------------                   -----------   |" << endl;
            cout << "|    ____________              __________________                   ________   |" << endl;
            cout << "|   | DEATH ROOM |            | MASTER FORK ROOM |                 | ENDING |  |" << endl;
            cout << "|    ------------              ------------------                   --------   |" << endl;
            cout << "|______________________________________________________________________________|" << endl;
            do
            {
                cout << "\nWhich level would you like to start at?" << endl;

                getCommand();
                
                //would this be better as a switch statement?
                if (command == "start room")
                {
                    beginning = true;
                    selection == false;
                    start_room();
                    
                    break;
                    //parameters in default
                }
                else if (command == "jail room")
                {
                 
                    letterInInventory = true;
                    lanternInInventory = true;
                    pileOfHayMoved = true;
                    trapDoorOpen = true;
                    wentToJailRoom = true;
                    selection == false;
                    jail_room();
                    break;
                    //parameters
                }
                else if (command == "map room")
                {
                  

                    letterInInventory = true;
                    lanternInInventory = true;
                    pileOfHayMoved = true;
                    trapDoorOpen = true;
                    keyInInventory = true;
                    sawHuggyWuggy = true;
                    huggyWuggyFreed = true; //moved to huggy wuggy bools
                    mapRoomDoorOpen = true;
                    wentToMapRoom = true;
                    selection == false;
                    map_room();
                    break;
                    //parameters
                }
                else if (command == "cookie room")
                {
                    letterInInventory = true;
                    lanternInInventory = true;
                    pileOfHayMoved = true;
                    trapDoorOpen = true;
                    keyInInventory = true;
                    sawHuggyWuggy = true;
                    huggyWuggyFreed = true; //moved to huggy wuggy bools
                    mapRoomDoorOpen = true;
                    gotNinjaStars = true;
                    gotMap = true;
                    cookieDoorUnlocked = true;
                    wentToCookieRoom = true;
                    selection == false;
                    killer_cookie_room();
                    break;
                    //parameters
                }
                else if (command == "zombie room")
                {
                    letterInInventory = true;
                    lanternInInventory = true;
                    pileOfHayMoved = true;
                    trapDoorOpen = true;
                    keyInInventory = true;
                    sawHuggyWuggy = true;
                    huggyWuggyFreed = true; //moved to huggy wuggy bools
                    mapRoomDoorOpen = true;
                    gotNinjaStars = true;
                    gotMap = true;
                    cookieDoorUnlocked = true;
                    cookiesDead = true;
                    cookieTreasureChestAppears = true;
                    canShootLightning = true;
                    //bool deathByCookieTimer //TODO: Create a countdown timer to escape from cookies
                    wentToZombieRoom = true;
                    selection == false;
                    zombie_vegetable_room();
                    break;
                    //parameters
                }
                else if (command == "boss room")
                {
                    letterInInventory = true;
                    lanternInInventory = true;
                    pileOfHayMoved = true;
                    trapDoorOpen = true;
                    keyInInventory = true;
                    sawHuggyWuggy = true;
                    huggyWuggyFreed = true; //moved to huggy wuggy bools
                    mapRoomDoorOpen = true;
                    gotNinjaStars = true;
                    gotMap = true;
                    cookieDoorUnlocked = true;
                    cookiesDead = true;
                    cookieTreasureChestAppears = true;
                    canShootLightning = true;
                    //bool deathByCookieTimer //TODO: Create a countdown timer to escape from cookies
                    talkedToBrockKillie = true;
                    zombie_Boss_Room_Door_Open = true;
                    ranOutOfTime = false; // timer to make decisions in cookie and vegetable rooms as well as the boss chase
                    rightAnswer = true;
                    //bool zombieStunned = false //TODO: create a stun mechanic to add more time to countdown timer 
                    wentToBossRoom = true;
                    selection == false;
                    boss_room();
                    break;
                    //enter in parameters
                }
                else if (command == "death room")
                {
                    letterInInventory = true;
                    lanternInInventory = true;
                    pileOfHayMoved = true;
                    trapDoorOpen = true;
                    keyInInventory = true;
                    sawHuggyWuggy = true;
                    huggyWuggyFreed = true; //moved to huggy wuggy bools
                    mapRoomDoorOpen = true;
                    gotNinjaStars = true;
                    gotMap = true;
                    cookieDoorUnlocked = true;
                    cookiesDead = true;
                    cookieTreasureChestAppears = true;
                    canShootLightning = true;
                    //bool deathByCookieTimer //TODO: Create a countdown timer to escape from cookies
                    talkedToBrockKillie = true;
                    zombie_Boss_Room_Door_Open = true;
                    ranOutOfTime = false; // timer to make decisions in cookie and vegetable rooms as well as the boss chase
                    rightAnswer = true;
                    //bool zombieStunned = false //TODO: create a stun mechanic to add more time to countdown timer 
                    cakeIsAwake = false; //starts cake timer to count down when you will get eaten unless you make a decision.
                    cakeStunned = false;// pauses timer (or maybe adds more time to cake timer) to stop cake from chasing and killing you
                    inChest = false;
                    wentToDeathRoom = true;//stops timer upon entering
                    selection == false;
                    death_room();
                    break;
                    //enter in parameters
                }
                else if (command == "master fork room")
                {
             
                    goldenKeyInInventory = true; //key to unlock master fork room and also releases the cake boss into the death room
                    wentToMasterForkRoom = true;
                    selection == false;
                    master_fork_room();
                    break;
                    //enter in parameters
                }
                else if (command == "ending")
                {
                    wonGame = true; 
                    selection == false;
                    ending();
                    stillAlive = false;
                    break;

                    //enter in parameters
                }
                else
                {
                    cout << "What do you mean by \"" << command << "?\" Try a different command..." << endl << endl;
                    continue;
                }

            } while (selection == true);
        }




        int main()
      
        /**************************************************************************************/
        /*__/\\\\____________/\\\\_____/\\\\\\\\\_____/\\\\\\\\\\\__/\\\\\_____/\\\___________*/
        /*__\/\\\\\\________/\\\\\\___/\\\\\\\\\\\\\__\/////\\\///__\/\\\\\\___\/\\\__________*/
        /*___\/\\\//\\\____/\\\//\\\__/\\\/////////\\\_____\/\\\_____\/\\\/\\\__\/\\\_________*/
        /*____\/\\\\///\\\/\\\/_\/\\\_\/\\\_______\/\\\_____\/\\\_____\/\\\//\\\_\/\\\________*/
        /*_____\/\\\__\///\\\/___\/\\\_\/\\\\\\\\\\\\\\\_____\/\\\_____\/\\\\//\\\\/\\\_______*/
        /*______\/\\\____\///_____\/\\\_\/\\\/////////\\\_____\/\\\_____\/\\\_\//\\\/\\\______*/
        /*_______\/\\\_____________\/\\\_\/\\\_______\/\\\_____\/\\\_____\/\\\__\//\\\\\\_____*/
        /*________\/\\\_____________\/\\\_\/\\\_______\/\\\__/\\\\\\\\\\\_\/\\\___\//\\\\\____*/
        /*_________\///______________\///__\///________\///__\///////////__\///_____\/////____*/
        /*____________________________________________________________________________________*/
        /**************************************************************************************/
        {
           

            cout << endl;
            do // game ends if you die, pinch yourself, exit, or quit
            {
                if (title == true)
                {
                    title_menu();
                    continue;
                }
                else if (selection == true)
                {
                    level_selection();
                    continue;
                }
                else if (beginning == true)
                {
                    start_room();
                    continue;
                }
                else if (wentToJailRoom == true)
                {
                    jail_room();
                    continue;
                }
                else if (wentToMapRoom == true)
                {
                    map_room();
                    continue;
                }
                else if (wentToCookieRoom == true)
                {
                    killer_cookie_room();
                    continue;
                }
                else if (wentToZombieRoom == true)
                {
                    zombie_vegetable_room();
                    continue;
                }
                else if (wentToBossRoom == true) {
                    boss_room();
                    continue;
                }
                else if (wentToDeathRoom == true)
                {
                    death_room();
                    continue;
                }

                else if (wentToMasterForkRoom == true)
                {
                    master_fork_room();
                    continue;
                }
                else if (wonGame == true)
                {
                    ending();
                    stillAlive = false;
                }

                } while (stillAlive == true);

                return 0;

            }

