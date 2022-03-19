#include <bits/stdc++.h>
using namespace std;

class Hero{

    // properties or Data-members
    int health;
    public:
    char Level;

    void setHealth(int health)
    {
        this->health = health;   // this is pointer to object, so we can access Huzefa(object) data-members using this.
    }

    int getHealth()
    {
        return health;
    }


};
int main()
{
    Hero Huzefa; // Object creation and default constructor( which do not accept input parameters) is called.

    Huzefa.Level = 'A'; //  Like this we can't access the Health because that is private data member, so for that we have to use getter and setter.
    Huzefa.setHealth(90);
    // Accessing data-members
    cout << "Level of huzefa is : "<<  Huzefa.Level << endl;

    cout << "Health of huzefa is : "<<Huzefa.getHealth() << endl; 

    return 0;
}