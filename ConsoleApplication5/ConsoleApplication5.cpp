#include<iostream>
int main()
{
    const int row=3,col=3;
    char arr[row][col]={
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    int count=0,count_x=0,count_o=0,a,b,c,d;
    bool win=false;
    while (true)
    {
        int k=0;
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                std::cout<<"|"<<arr[i][j]<<"|";
            }
            std::cout<<std::endl;
        }
        for (int i=0;i<row;i++)
        {
            if (arr[i][0]=='x' && arr[i][1]=='x' && arr[i][2]=='x')
            {
                std::cout<<"first player wins";
                win=true;
            }
            else if (arr[i][0]=='o' && arr[i][1]=='o' && arr[i][2]=='o')
            {
                std::cout<<"second player wins";
                win=true;
            }
        }
        for (int i=0;i<col;i++)
        {
            if (arr[0][i]=='x' && arr[1][i]=='x' && arr[2][i]=='x')
            {
                std::cout<<"first player wins";
                win=true;
            }
            else if (arr[0][i]=='o' && arr[1][i]=='o' && arr[2][i]=='o')
            {
                std::cout<<"second player wins";
                win=true;
            }
        }
        count_x=0,count_o=0;
        for (int i=0;i<3;i++)
        {
            if (arr[i][i]=='x')
            {
                count_x+=1;
            }
            else if (arr[i][i]=='o')
            {
                count_o+=1;
            }
        }
        if (count_x==3)
        {
            std::cout<<"first player wins";
            win=true;
        }
        else if (count_o==3)
        {
            std::cout<<"second player wins";
            win=true;
        }
        if (arr[0][2]=='x' && arr[1][1]=='x' && arr[2][0]=='x')
        {
            std::cout<<"first player wins";
            win=true;
        }
        else if (arr[0][2]=='o' && arr[1][1]=='o' && arr[2][0]=='o')
        {
            std::cout<<"second player wins";
            win=true;
        }
        if (win==true)
        {
            break;
        }
        if (count==5 && win==false)
        {
            std::cout<<"draw";
            break;
        }
        std::cout<<"first player's coordinates: "<<std::endl;
        std::cin>>a>>b;
        arr[a][b]='x';
        for (int i=0;i<row;i++)
        {
            for (int j=0;j<col;j++)
            {
                std::cout<<arr[i][j];
            }
            std::cout<<std::endl;
        }
        for (int i=0;i<row;i++)
        {
            if (arr[i][0]=='x' && arr[i][1]=='x' && arr[i][2]=='x')
            {
                std::cout<<"first player wins";
                win=true;
            }
            else if (arr[i][0]=='o' && arr[i][1]=='o' && arr[i][2]=='o')
            {
                std::cout<<"second player wins";
                win=true;
            }
        }
        for (int i=0;i<col;i++)
        {
            if (arr[0][i]=='x' && arr[1][i]=='x' && arr[2][i]=='x')
            {
                std::cout<<"first player wins";
                win=true;
            }
            else if (arr[0][i]=='o' && arr[1][i]=='o' && arr[2][i]=='o')
            {
                std::cout<<"second player wins";
                win=true;
            }
        }
        count_x=0,count_o=0;
        for (int i=0;i<3;i++)
        {
            if (arr[i][i]=='x')
            {
                count_x+=1;
            }
            else if (arr[i][i]=='o')
            {
                count_o+=1;
            }
        }
        if (count_x==3)
        {
            std::cout<<"first player wins";
            win=true;
        }
        else if (count_o==3)
        {
            std::cout<<"second player wins";
            win=true;
        }
        if (arr[0][2]=='x' && arr[1][1]=='x' && arr[2][0]=='x')
        {
            std::cout<<"first player wins";
            win=true;
        }
        else if (arr[0][2]=='o' && arr[1][1]=='o' && arr[2][0]=='o')
        {
            std::cout<<"second player wins";
            win=true;
        }
        if (win==true)
        {
            break;
        }
        if (count==5 && win==false)
        {
            std::cout<<"draw";
            break;
        }
        
        std::cout<<"second player's coordinates: "<<std::endl;
        std::cin>>c>>d;
        arr[c][d]='o';
        count+=1;
        if (count==5 && win==false)
        {
            std::cout<<"draw";
            break;
        }
    }
    return 0;
}