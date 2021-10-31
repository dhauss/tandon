#include <iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

const int GRID_SIZE = 20;
const int INITIAL_ANTS = 100;
const int INITIAL_DOODLEBUGS  = 5;
const int ANT_BREED_TIME = 3;
const int DOODLEBUG_BREED_TIME = 8;
const int DOODLEBUG_STARVE_TIME = 3;
const int UP = 0;
const int DOWN = 1 ;
const int LEFT = 2;
const int RIGHT = 3;
const char EMPTY_CHAR = '-';
const char ANT_CHAR = 'o';
const char DOODLEBUG_CHAR = 'X';

struct Position{
    int x;
    int y;
};

class World;

class Organism{
protected:
    Position pos;
public:
    Organism(const Position& newPos) : pos(newPos) {}
    virtual ~Organism() {}
    Position getPosition() const {return pos;}
    void setPosition(const Position& newPos);
    virtual void move(World& world) = 0;
    virtual void breed(World& world) = 0;
    virtual void starve(World& world) = 0;
    virtual char getType() const = 0;
    virtual void print(ostream& outs) const = 0;
    friend ostream& operator<<(ostream& outs, const Organism& organism);
};

class Ant: public Organism {
int breedTimer;
public:
    Ant(Position& pos) : Organism(pos), breedTimer(0) {}
    virtual ~Ant() {}
    virtual char getType() const {return ANT_CHAR;}
    virtual void move(World& world);
    virtual void breed(World& world);
    virtual void starve(World& world) {}
    virtual void print(ostream& outs) const {outs<<ANT_CHAR;}
};

class Doodlebug: public Organism{
    int breedTimer;
    int starveTimer;
    vector<Position> findAdjacentAnts(const World& world) const;
public:
    Doodlebug(const Position& pos) : Organism(pos), breedTimer(0), starveTimer(0) {}
    virtual ~Doodlebug() {}
    virtual char getType() const {return DOODLEBUG_CHAR;}
    virtual void move(World& world);
    virtual void breed(World& world);
    virtual void starve(World& world);
    virtual void print(ostream& outs) const {outs<<DOODLEBUG_CHAR;}
};

class World{
    Organism* grid[GRID_SIZE][GRID_SIZE];
public:
    World();
    ~World();
    void printWorld();
    bool isEmpty(const Position& pos) const;
    vector<Position> findAdjacentEmpty(const Position& currPos) const;
    void moveOrganism(const Position& currPos, const Position& nextPos);
    void setOrganism(const Position& pos, Organism* orgPtr);
    Organism* getOrganism(const Position& pos) const;
    void killOrganism(const Organism* orgPtr);
    void timeStep();
};


int main() {
    srand(time(0));
    World world;
    bool isEmpty = true;
    string userInput;

    cout<<"Note: Cannot get Doodlebug move function to work, seems to be accessing\n"
        <<"memory it shouldn't or maybe dereferencing a nullptr. Breed and starve\n"
        <<"functions do work if you lower the breed timer and increment the\n"
        <<"breed and starve timers in breed and starve functions after commenting\n"
        <<"out move function in timeStep function. Please let me know my error\n"
        <<"with the move function because it is slowly driving me insane, thanks!\n";

    while(isEmpty){
        cout<<"\nType return to simulate time step, any other key to terminate program:\n";
        getline(cin, userInput);
        if(!userInput.empty())
            isEmpty = false;
        else{
            world.printWorld();
            world.timeStep();
        }
    }

    return 0;
}
void Organism::setPosition(const Position &newPos) {
    pos.x = newPos.x;
    pos.y = newPos.y;
}

void Ant::move(World& world) {
    int direction = rand() % 4;
    Position currPos = pos;
    Position nextPos = currPos;

    switch(direction) {
        case(UP):
            nextPos.y = currPos.y + 1;
            break;
        case(DOWN):
            nextPos.y = currPos.y - 1;
            break;
        case(LEFT):
            nextPos.x = currPos.x - 1;
        case(RIGHT):
            nextPos.x = currPos.x + 1;
        default:
            break;
    }
    if(world.isEmpty(nextPos))
        world.moveOrganism(currPos, nextPos);

    breedTimer++;
}

void Ant::breed(World& world) {
    if(breedTimer < ANT_BREED_TIME)
        return;

    vector<Position> emptyCells = world.findAdjacentEmpty(this->pos);
    if(emptyCells.size() > 0) {
        int direction = rand() % emptyCells.size();
        Position newPos = emptyCells[direction];

        world.setOrganism(newPos, new Ant(newPos));
    }
}

void Doodlebug::move(World &world) {
    vector<Position> adjacentAnts;
    adjacentAnts = findAdjacentAnts(world);

    if(adjacentAnts.size() > 0){
        int direction = rand() % adjacentAnts.size();
        Position targetAntPos = adjacentAnts[direction];
        Organism* targetAntPtr = world.getOrganism(targetAntPos);


        world.killOrganism(targetAntPtr);
        world.moveOrganism(pos, targetAntPos);
        starveTimer = 0;
        breedTimer++;
    }
    else{
        int direction = rand() % 4;
        Position nextPos = pos;

        switch(direction) {
            case(UP):
                nextPos.y = pos.y + 1;
                break;
            case(DOWN):
                nextPos.y = pos.y - 1;
                break;
            case(LEFT):
                nextPos.x = pos.x - 1;
            case(RIGHT):
                nextPos.x = pos.x + 1;
            default:
                break;
        }
        if(world.isEmpty(nextPos))
            world.moveOrganism(pos, nextPos);

        breedTimer++;
        starveTimer++;
    }
}

void Doodlebug::breed(World &world) {
    if(breedTimer < DOODLEBUG_BREED_TIME)
        return;
    else{
        vector<Position> emptyCells = world.findAdjacentEmpty(this->pos);
        if(emptyCells.size() > 0){
            int direction = rand() % emptyCells.size();
            Position newPos = emptyCells[direction];
            world.setOrganism(newPos, new Doodlebug(newPos));
        }
    }
}

void Doodlebug::starve(World &world) {
    if(starveTimer < DOODLEBUG_STARVE_TIME)
        return;
    else
        world.killOrganism(this);
}

vector<Position> Doodlebug::findAdjacentAnts(const World& world) const{
    vector<Position> adjacentAnts;
    vector<Position> potentialAnts {
            {pos.x + 1, pos.y},
            {pos.x -1, pos.y},
            {pos.x, pos.y - 1},
            {pos.x, pos.y + 1}
    };

    for(auto cell: potentialAnts) {
        if ((cell.x >= 0) && (cell.x < GRID_SIZE) && (cell.y >= 0) && (cell.y < GRID_SIZE)) {
            Organism* potentialAnt = world.getOrganism(cell);
            if ((potentialAnt != nullptr) && (potentialAnt->getType() == ANT_CHAR))
                adjacentAnts.push_back(cell);
        }
    }
    return adjacentAnts;
}


World::World(){
    for(int i = 0; i < GRID_SIZE; i++){
        for(int j = 0; j < GRID_SIZE; j++){
            grid[i][j] = nullptr;
        }
    }

    for(int i = 0; i < INITIAL_DOODLEBUGS; i++) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;

        while (grid[x][y] != nullptr) {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        }

        Position doodlePos = {x, y};
        grid[x][y] = new Doodlebug(doodlePos);
    }

    for(int i = 0; i < INITIAL_ANTS; i++) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;

        while (grid[x][y] != nullptr) {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        }

        Position antPos = {x, y};
        grid[x][y] = new Ant(antPos);
    }
}

World::~World(){
    for(int i = 0; i < GRID_SIZE; i++){
        for(int j = 0; j < GRID_SIZE; j++){
            if(grid[i][j] != nullptr)
            delete grid[i][j];
        }
    }
}

void World::printWorld() {
    for(int i = 0; i < GRID_SIZE; i++){
        for(int j = 0; j < GRID_SIZE; j++){
            if(grid[i][j] == nullptr)
                cout<<EMPTY_CHAR<<" ";
            else
                cout<<*grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool World::isEmpty(const Position &pos) const {
    return ((pos.x >= 0) && (pos.x < GRID_SIZE) && (pos.y >= 0) && (pos.y < GRID_SIZE) && (grid[pos.x][pos.y] == nullptr));
}

vector<Position> World::findAdjacentEmpty(const Position &currPos) const {
    vector<Position>adjacentCells;
    vector<Position>potentialCells = {
            {currPos.x - 1, currPos.y},
            {currPos.x + 1, currPos.y},
            {currPos.x, currPos.y - 1},
            {currPos.x, currPos.y + 1}
    };
    for(auto i: potentialCells){
        if(isEmpty(i))
            adjacentCells.push_back(i);
    }
    return adjacentCells;
}

void World::moveOrganism(const Position& currPos, const Position& nextPos){
    grid[nextPos.x][nextPos.y] = grid[currPos.x][currPos.y];
    grid[nextPos.x][nextPos.y]->setPosition(nextPos);
    grid[currPos.x][currPos.y] = nullptr;
}

void World::setOrganism(const Position &pos, Organism *orgPtr) {
    grid[pos.x][pos.y] = orgPtr;
    orgPtr->setPosition(pos);
}

Organism* World::getOrganism(const Position &pos) const {
    if((pos.x >= 0) && (pos.x < GRID_SIZE) && (pos.y >= 0) && (pos.y < GRID_SIZE))
        return grid[pos.x][pos.y];
    else
        return nullptr;
}

void World::killOrganism(const Organism *orgPtr) {
    Position currPos = orgPtr->getPosition();
    grid[currPos.x][currPos.y] = nullptr;
    delete orgPtr;
}

void World::timeStep() {
    vector<Organism*> ants;
    vector<Organism*> doodlebugs;

    for(int i = 0; i < GRID_SIZE; i++){
        for(int j = 0; j < GRID_SIZE; j++){
            if(grid[i][j] != nullptr && grid[i][j]->getType() == ANT_CHAR)
                ants.push_back(grid[i][j]);
        }
    }

    for(int i = 0; i < GRID_SIZE; i++){
        for(int j = 0; j < GRID_SIZE; j++){
            if(grid[i][j] != nullptr && grid[i][j]->getType() == DOODLEBUG_CHAR)
                doodlebugs.push_back(grid[i][j]);
        }
    }

    for(auto doodlePtr: doodlebugs)
        doodlePtr->move(*this);

    for(auto antPtr: ants)
        antPtr->move(*this);

    for(auto doodlePtr: doodlebugs)
        doodlePtr->breed(*this);

    for(auto antPtr: ants)
        antPtr->breed(*this);

    for(auto doodlePtr: doodlebugs)
        doodlePtr->starve(*this);

}

ostream& operator<<(ostream& outs, const Organism& organism){
    organism.print(outs);

    return outs;
}