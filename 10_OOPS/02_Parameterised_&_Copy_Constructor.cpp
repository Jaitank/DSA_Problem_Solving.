#include <bits/stdc++.h>
using namespace std;

class Hero{

    // properties or Data-members
    int health;
    public:
    char Level;

    Hero(int health, int Level) // when paramterised constructor is created then default contructor existence finished.
    {
        this->health = health;
        this->Level = Level;
    }

    int getHealth()
    {
        return health;
    }


};

class Villian{

    // properties or Data-members
    int health;
    public:
    char Level;
    Villian(int health, char Level)
    {
        cout << "paratmerised contructor is called" << endl;
        this->health  = health;
        this->Level = Level;
    }

    Villian(Villian & temp_paul_friend) // when paramterised constructor is created then default contructor existence finished.
    // here we cant use pass by value, we have to use pass by reference.
    {
        cout << "Copy constructor is called" << endl;
        this->health = temp_paul_friend.health;
        this->Level = temp_paul_friend.Level;
    }

    void print()
    {
        cout << "Level is : "<<  Level << endl;

        cout << "Health is : "<< health << endl; 
    }

    int getHealth()
    {
        return health;
    }


};
int main()
{
    Hero Huzefa(90,'B'); // Object creation and default constructor( which do not accept input parameters) is called.

    Villian paul(100, 'A');
    Villian paul_friend(paul); // here paul friend is copy constructor.
    // Accessing data-members

    paul_friend.print();

    paul.print();

    cout << paul_friend.getHealth();



    return 0;
}