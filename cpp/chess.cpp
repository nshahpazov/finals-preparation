#include <iostream>
#include <string.h>
#include <vector>

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

Knight& Knight::Knight(const Knight& knight)
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
    
}

bool Knight::captures(ChessPosition pos)
{
    return true;
}

int main()
{
    return 0;
}
