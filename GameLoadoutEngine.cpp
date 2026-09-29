#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class GameEntity
{
protected:
    string name;
    int powerLevel;

public:
    GameEntity(string n, int pl) : name(n), powerLevel(pl) {}
    virtual void showStats() = 0;
};

class Player : public GameEntity
{
protected:
    int rank;
    float health;

public:
    Player(string n, int pl, int r, float h) : GameEntity(n, pl), rank(r), health(h) {}
    void showStats()
    {
        cout << "Player Name :- " << name
             << "\nPower Level :- " << powerLevel
             << "\nRank :- " << rank
             << "\nHealth :- " << health;
    }
};

class Equipment : public GameEntity
{
protected:
    string weapon;
    float damage;

public:
    Equipment(string n, int pl, string wp, float dm) : GameEntity(n, pl), weapon(wp), damage(dm) {}
    void showStats()
    {
        cout << "Player Name :- " << name
             << "\nPower Level :- " << powerLevel
             << "\nWeapon :- " << weapon
             << "\nWeapon Damage :- " << damage;
    }
};

int main()
{
    string name = "None", weapon = "None";
    int power = 0, rank = 0;
    float damage = 0, health = 0;
    Player p(name, power, rank, health);
    Equipment e(name, power, weapon, damage);
    GameEntity *game[2];
    game[0] = &p;
    game[1] = &e;
    for (int i = 0; i < 2; i++)
    {
        game[i]->showStats();
        cout << endl;
    }
    int choice;
    do
    {
        cout << "\n\nPress 1 -> Create a New Player"
             << "\nPress 2 -> View Current Loadout"
             << "\nPress 3 -> Save Game to Disk"
             << "\nPress 4 -> Load Game from Disk"
             << "\nPress 5 -> Exit" << endl;
        cout << "\nEnter Your Choice :- ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                {
                    cin.ignore();
                    cout << "Enter player Name :- ";
                    getline(cin, name);
                    cout << "Enter player Power level :- ";
                    cin >> power;
                    cout << "Enter player Rank :- ";
                    cin >> rank;
                    cout << "Enter player Health :- ";
                    cin >> health;
                    cin.ignore();
                    cout << "Enter player Weapon :- ";
                    getline(cin, weapon);
                    cout << "Enter player Damage :- ";
                    cin >> damage;
                    break;
                }
            case 2:
                {
                    Player p(name, power, rank, health);
                    Equipment e(name, power, weapon, damage);
                    GameEntity *game[2];
                    game[0] = &p;
                    game[1] = &e;
                    for (int i = 0; i < 2; i++)
                    {
                        game[i]->showStats();
                        cout << endl;
                    }
                    break;
                }
            case 3:
                {
                    ofstream out;
                    out.open("Game_Data_Set.txt");
                    out << "Player Name :- " << name
                        << "\nPower Level :- " << power
                        << "\nRank :- " << rank
                        << "\nHealth :- " << health
                        << "\nWeapon :- " << weapon
                        << "\nWeapon Damage :- " << damage;
                    out.close();
                    cout << "The Game Successfully Saved " << endl;
                    break;
                }
            case 4:
                {
                    ifstream in("Game_Data_Set.txt");
                    string data;
                    int i = 0;
                    while (getline(in, data))
                    {
                        string line = data;
                        int pos = line.find(":-")+3;
                        string piece = line.substr(pos);
                        switch(i)
                        {
                            case 0:
                                name = piece;
                                break;
                            case 1:
                                power=stoi(piece);
                                break;
                            case 2:
                                rank=stoi(piece);
                                break;
                            case 3:
                                health=stof(piece);
                                break;
                            case 4:
                                weapon = piece;
                                break;
                            case 5 :
                                damage = stoi(piece);
                                break;
                        }
                        i++;
                        cout << data << endl;
                    }
                    in.close();
                    break;
                }
            case 5:
                {
                    cout << "Thanking You \nGood Bye";
                    return 0;
                }
            default:
                {
                    cout << "Invalid Input ";
                    break;
                }
        }
    } while (choice != 5);
    return 0;
}
