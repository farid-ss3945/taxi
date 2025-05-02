#include <iostream>

class Figure
{
protected:
    char chessboard[8][8] = {
        {'#', '*', '#', '*', '#', '*', '#', '*'},
        {'*', '#', '*', '#', '*', '#', '*', '#'},
        {'#', '*', '#', '*', '#', '*', '#', '*'},
        {'*', '#', '*', '#', '*', '#', '*', '#'},
        {'#', '*', '#', '*', '#', '*', '#', '*'},
        {'*', '#', '*', '#', '*', '#', '*', '#'},
        {'#', '*', '#', '*', '#', '*', '#', '*'},
        {'*', '#', '*', '#', '*', '#', '*', '#'}
    };
    char _name;
    int _a;
    int _b;
    char _temp;
public:
    Figure()
    {
        
    }
    void Put(int x, int y)
    {
        if (x>=0 && y>=0 && x<8 && y<8)
        {
            _a = x;
            _b = y;
            _temp = chessboard[_a][_b];
            chessboard[_a][_b] = _name;
        }
    }
    virtual void Move(int a, int b)
    {
        _a = a;
        _b = b;
        chessboard[_a][_b] = _name;
    }
    void printBoard()
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                std::cout<<chessboard[i][j]<<" ";
            }
            std::cout<<"\n";
        }
        std::cout<<"\n";
    }
    
};

class Pawn : public Figure
{
protected:
    char _name='P';    
public:

    void Put(int x, int y)
    {
        if (x>=0 && y>=0 && x<8 && y<8)
        {
            _a = x;
            _b = y;
            _temp = chessboard[_a][_b];
            chessboard[_a][_b] = _name;
        }
    }
    
    void Move(int a,int b) override
    {
        if (_a!=6 && a-_a==-1 && b-_b==0 && (a>=0 && b>=0) && (a<8 && b<8))
        {
            chessboard[_a][_b] = _temp;
            _a=a;
            _b=b;
            _temp = chessboard[_a][_b];
            chessboard[_a][_b] = _name;
        }
        else if (_a==6 && a-_a==-1 && b-_b==0 || a-_a==-2 && b-_b==0 && (a>0 && b>0) && (a<8 && b<8))
        {
            chessboard[_a][_b] = _temp;
            _a=a;
            _b=b;
            _temp = chessboard[_a][_b];
            chessboard[_a][_b] = _name;
        }
    }
};

class Rook : public Figure
{
protected:
    char _name='R';
public:
    void Put(int x, int y)
    {
        if (x>=0 && y>=0 && x<8 && y<8)
        {
            _a = x;
            _b = y;
            _temp = chessboard[_a][_b];
            chessboard[_a][_b] = _name;
        }
    }
    void Move(int a,int b) override
    {
        if (_a-a!=0 && _b-b==0 && (a>=0 && b>=0) && (a<8 && b<8))
        {
            chessboard[_a][_b] = _temp;
            _a=a;
            _b=b;
            _temp = chessboard[_a][_b];
            chessboard[_a][_b] = _name;
        }
        else if (_a-a==0 && _b-b!=0 && (a>=0 && b>=0) && (a<8 && b<8))
        {
            chessboard[_a][_b] = _temp;
            _a=a;
            _b=b;
            _temp = chessboard[_a][_b];
            chessboard[_a][_b] = _name;
        }
    }
};

class King : public Figure
{
protected:
    char _name='K';
public:
    void Put(int x, int y)
    {
        if (x>=0 && y>=0 && x<8 && y<8)
        {
            _a = x;
            _b = y;
            _temp = chessboard[_a][_b];
            chessboard[_a][_b] = _name;
        }
    }
    void Move(int a,int b) override
    {
        if (-2<_a-a && _a-a<2 && -2<_b-b && _b-b<2 && (a>=0 && b>=0) && (a<8 && b<8))
        {
            chessboard[_a][_b] = _temp;
            _a=a;
            _b=b;
            _temp = chessboard[_a][_b];
            chessboard[_a][_b] = _name;
        }
    }
};

class Bishop : public Figure
{
protected:
    char _name='B';
public:
    void Put(int x, int y)
    {
        if (x>=0 && y>=0 && x<8 && y<8)
        {
            _a = x;
            _b = y;
            _temp = chessboard[_a][_b];
            chessboard[_a][_b] = _name;
        }
    }
    void Move(int a,int b) override
    {
        int s=_a-a;
        int r=_b-b;
        int k=s+r;
        if (s==r || k==0 && (a>=0 && b>=0) && (a<8 && b<8))
        {
            chessboard[_a][_b] = _temp;
            _a=a;
            _b=b;
            _temp = chessboard[_a][_b];
            chessboard[_a][_b] = _name;
        }
    }
};

class Queen : public Figure
{
protected:
    char _name='Q';
public:
    void Put(int x, int y)
    {
        if (x>=0 && y>=0 && x<8 && y<8)
        {
            _a = x;
            _b = y;
            _temp = chessboard[_a][_b];
            chessboard[_a][_b] = _name;
        }
    }
    void Move(int a,int b) override
    {
        int s=_a-a;
        int r=_b-b;
        int k=s+r;
        if (_a==a || _b==b || (s==r || k==0) && (a>=0 && b>=0) && (a<8 && b<8))
        {
            chessboard[_a][_b] = _temp;
            _a=a;
            _b=b;
            _temp = chessboard[_a][_b];
            chessboard[_a][_b] = _name;
        }
    }
};

class Knight : public Figure
{
protected:
    char _name='K';
public:
    void Put(int x, int y)
    {
        if (x>=0 && y>=0 && x<8 && y<8)
        {
            _a = x;
            _b = y;
            _temp = chessboard[_a][_b];
            chessboard[_a][_b] = _name;
        }
    }
    void Move(int a,int b) override
    {
        int s=_a-a;
        int r=_b-b;
        if (s*s+r*r==5 && (a>=0 && b>=0) && (a<8 && b<8))
        {
            chessboard[_a][_b] = _temp;
            _a=a;
            _b=b;
            _temp = chessboard[_a][_b];
            chessboard[_a][_b] = _name;
        }
    }
};

int main()
{
    // Pawn
    
    // Pawn pawn;
    // pawn.Put(6,1);
    // pawn.printBoard();
    // std::cout<<"\n";
    // pawn.Move(1,2);
    // pawn.printBoard();
    // std::cout<<"\n";
    // pawn.Move(5,1);
    // pawn.printBoard();
    
    //========================
    
    // Rook
    
    // Rook rook;
    // rook.Put(7,0);
    // rook.printBoard();
    // std::cout<<"\n";
    // rook.Move(0,7);
    // rook.printBoard();
    // std::cout<<"\n";
    // rook.Move(7,7);
    // rook.printBoard();

    // King

    // King king;
    // king.Put(2,3);
    // king.printBoard();
    // std::cout<<"\n";
    // king.Move(1,6);
    // king.printBoard();
    // std::cout<<"\n";
    // king.Move(2,4);
    // king.printBoard();

    // Bishop

    // Bishop bishop;
    // bishop.Put(2,3);
    // bishop.printBoard();
    // std::cout<<"\n";
    // bishop.Move(2,4);
    // bishop.printBoard();
    // std::cout<<"\n";
    // bishop.Move(1,4);
    // bishop.printBoard();

    // Queen

    // Queen queen;
    // queen.Put(5,6);
    // queen.printBoard();
    // std::cout<<"\n";
    // queen.Move(4,4);
    // queen.printBoard();
    // std::cout<<"\n";
    // queen.Move(5,7);
    // queen.printBoard();
    // std::cout<<"\n";
    // queen.Move(4,6);
    // queen.printBoard();
    // std::cout<<"\n";

    // Knight

    // Knight knight;
    // knight.Put(6,2);
    // knight.printBoard();
    // std::cout << "\n";
    // knight.Move(6,3);
    // knight.printBoard();
    // std::cout << "\n";
    // knight.Move(5,0);
    // knight.printBoard();
    
    return 0;
}
