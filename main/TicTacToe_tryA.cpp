#include <iostream>

using namespace std;

void draw_board(char in[3][3])
{
    cout << "_|A|B|C|\n";
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << "|";
        for (int j = 0; j < 3; j++)
        {
            //cout << i << "-" << j << "\n";
            cout << in[i][j] << "|";
        }
        cout << "\n";
    }
}

void draw(char in_a[3][3], bool in_b)
{
    system("cls");
    cout << "Tic tac toe v1.0\n";
    cout << "Podaj pole (np. A3 lub a3).\n";
    cout << "Grasz jako ";
    if (in_b == 1) cout << "X.\n";
    else cout << "O.\n";
    draw_board(in_a);
}

//ta funkcja ma "dostać" tablicę 'board' i dodać do niej X lub O na właściwe miejsce
void fill_array(string in, bool in_b)
{
    if ((in[0] > 64) && (in[0] < 68))
    {
        //a,b,c = 65, 66, 67
    }
    else
    {
        //a,b,c = 97, 98, 99
    }
    //1,2,3 = 49, 50, 51
}

int main()
{
    char board[3][3];
    string odp;
    char odpA;
    int odpB;
    bool gra_x = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '_';
        }
    }
    while (1)
    {
        while (1)
        {
            draw(board, gra_x);
            cout << "Podaj pole:";
            cin >> odp;
            if (((odp[0] > 64) && (odp[0] < 68)) || ((odp[0] > 96) && (odp[0] < 100)))
            {
                if ((odp[1] > 48) && (odp[1] < 52))
                {
                    if(odp.size()==2) break;
                }
            }
        }

        cout << "Brawo, poprawne dane!\n";
        system("PAUSE");
        gra_x = !gra_x;
        //ciąg dalszy programu.
    }


    draw(board, gra_x);
    system("PAUSE");
}