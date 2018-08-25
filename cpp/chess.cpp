#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;

struct ChessPosition {
    int x;
    int y;
};

class ChessPiece {
public:
    virtual ChessPosition getPosition();
    virtual vector<ChessPosition> allowedMoves();
    virtual bool captures(ChessPosition pos);
};

class Rook: public ChessPiece {
public:
    Rook();
    Rook(ChessPosition);
    ~Rook();
    Rook& operator=(const Rook&);

    ChessPosition getPosition();
    vector<ChessPosition> allowedMoves();
    bool captures(ChessPosition pos);
private:
    ChessPosition position;
};

Rook::Rook()
{
    position.x = 0;
    position.y = 0;
}

Rook::Rook(ChessPosition pos)
{
    position = pos;
}

Rook::~Rook()
{}

Rook& Rook::operator=(const Rook& another)
{
    if (this != &another) {
        position = another.position;
    }
    return *this;
}

ChessPosition Rook::getPosition()
{
    return position;
}

vector<ChessPosition> Rook::allowedMoves()
{

}

bool Rook::captures(ChessPosition pos)
{
    return position.x == pos.x || position.y == pos.y;
}

class Knight: public ChessPiece
{
public:
    Knight();
    Knight(ChessPosition);
    ~Knight();
    Knight& operator=(const Knight&);
    ChessPosition getPosition();
    vector<ChessPosition> allowedMoves();
    bool captures(ChessPosition pos);

private:
    ChessPosition position;
};

Knight::Knight()
{
    position.x = 0;
    position.y = 0;
}

Knight::Knight(ChessPosition pos)
{
    position = pos;
}

Knight::Knight(const Knight& knight)
{
    position = knight.position;
}

Knight& Knight::operator=(const Knight& knight)
{
    if (this != &knight) {
        
        position = knight.position;
    }
    return *this;
}

ChessPosition Knight::getPosition()
{
    return position;
}

vector<ChessPosition> Knight::allowedMoves()
{
    vector<ChessPosition> positions;
    int x = position.x;
    int y = position.y;
    // move up-left
    if (x >= 2 && y >= 1) {
        ChessPosition position;
        position.x = x-2;
        position.y = y-1;
        positions.push_back(position);
    }
    
    // analogically for the rest
    
    return positions;
}

bool Knight::captures(ChessPosition pos)
{
    int horizontalDistance = abs(pos.x - position.x);
    int verticalDistance = abs(pos.y - position.y);
    bool capturesHorizontally = horizontalDistance == 2 && verticalDistance == 1;
    bool capturesVertically =   horizontalDistance == 1 && verticalDistance == 2;

    return capturesHorizontally || capturesVertically;
}

int main()
{
    return 0;
}
