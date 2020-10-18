#include <iostream>

using namespace std;

bool end_condition(char* tab, char in)
{
    for (int i = 0; i < 3; i++)
    {
        if ((*(tab + i) == in) && (*(tab + i + 3) == in) && (*(tab + i + 6) == in))
        {
            cout << "Wygrana pionowo.\n";
            return true;
        }
        if ((*(tab + i * 3) == in) && (*(tab + i * 3 + 1) == in) && (*(tab + i * 3 + 2) == in))
        {
            cout << "Wygrana poziomo.\n";
            return true;
        }
    }
    if ((*(tab) == in) && (*(tab + 4) == in) && (*(tab + 8) == in))
    {
        cout << "Wygrana na skos.\n";
        return true;
    }
    if ((*(tab + 2) == in) && (*(tab + 4) == in) && (*(tab + 6) == in))
    {
        cout << "Wygrana na skos.\n";
        return true;
    }
    return false;
}

bool set_cell(char* tab, int size_x, int size_y, int target_pos, char in)
{
    const int size = size_x * size_y;
    //cout << "Wypelnianie " << target_pos << '/' << size << " tablicy.\n";
    if (target_pos >= size) return false;
    if (*(tab + target_pos) == '_') *(tab + target_pos) = in;
    else return false;
    return true;
}

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

void draw(char in_a[3][3], int tura)
{
    system("cls");
    cout << "Tic tac toe v1.0\n";
    cout << "Podaj pole (np. A3 lub a3).\n";
    cout << "Tura:\t" << tura << ".\n";
    cout << "Grasz jako " << ((tura % 2) ? 'X' : 'O') << ".\n";
    draw_board(in_a);
}

int get_pos(string in)
{
    int target_pos = 0;
    if ((in[0] > 64) && (in[0] < 68))
    {
        //a,b,c = 65, 66, 67
        target_pos += in[0] - 65;
    }
    else
    {
        //a,b,c = 97, 98, 99
        target_pos += in[0] - 97;
    }
    //1,2,3 = 49, 50, 51
    target_pos += 3 * (in[1] - 49);
    return target_pos;
}

int main()
{
    char board[3][3];
    string odp;
    int tura = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '_';
        }
    }
    draw(board, tura);
    while (1)
    {
        while (1)
        {
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
        if (!set_cell(&board[0][0], 3, 3, get_pos(odp), (tura % 2) ? 'X' : 'O'))
        {
            cout << "Pole zajete\n";
            system("PAUSE");
            tura--;
        }
        draw(board, tura);
        if (end_condition(&board[0][0], (tura % 2) ? 'X' : 'O'))
        {
            cout << "Warunek konca.\n";
            cout << "Wygral gracz " << ((tura % 2) ? 'X' : 'O') << "!\n";
            system("PAUSE");
            return 0;
        }
        if (tura >= 9)
        {
            draw(board, tura);
            cout << "Koniec gry. Wypełniono wszystkie pola. Remis.\n";
            system("PAUSE");
            return 0;
        }
        tura++;
    }
}