//high score entry : each player has a max number of high scores stored(10). higher scores replace the lower ones as new scores get scored. in first 10 
//scores the scores get properly ordered and placed at correct position with descending order

#include <iostream>
using namespace std;

class GameEntry
{
    string name;
    int score;

public:
    GameEntry(const string& n = "", int s = 0);
    string getName() const;
    int getScore() const;
};


GameEntry::GameEntry(const string& n, int s) : name(n) , score(s){}

string GameEntry::getName() const {return name;}
int GameEntry::getScore() const {return score;}

class Scores
{
    int maxEntries;
    int numEntries;
    GameEntry* entries;

public:
    Scores(int maxEnt = 0);
    ~Scores();
    void add(const GameEntry& e);
    GameEntry remove(int i);        
};

Scores::Scores(int maxEnt)
{
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}
Scores::~Scores() {delete[] entries; }

int main()
{
    
}