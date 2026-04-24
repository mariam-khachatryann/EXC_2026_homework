#include <iostream>
using namespace std;

void print(char arr[12][12], int i, int j, char direction) {
    cout << "i = " << i << "\nj = " << j << endl;
    cout << "Direction: " << direction << endl;

    for (int x = 0; x < 12; x++) {
        for (int y = 0; y < 12; y++) {
            cout << arr[x][y] << ' ';
        }
        cout << endl;
    }
    cout << "------------------\n";
}

void move(char arr[12][12], char direction, int i, int j) {
    print(arr, i, j, direction);
    cin.get(); 

    if (i < 0 || i >= 12 || j < 0 || j >= 12) {
        return;
    }

    int ni = i, nj = j;

    if (direction == '>') {
        nj++;
    }
    else if (direction == '<') {
        nj--;
    }
    else if (direction == 'v') {
        ni++;
    }
    else if (direction == '^') {
        ni--;
    }

    if (arr[ni][nj] == '#') {
        if (direction == '>') {
            direction = 'v';
        }
        else if (direction == 'v') {
            direction = '<';
        }
        else if (direction == '<') {
            direction = '^';
        }
        else if (direction == '^') {
            direction = '>';
        }
        
        move(arr, direction, i, j);
        return;
    }

    arr[i][j] = ' ';   
    arr[ni][nj] = 'o'; 

    move(arr, direction, ni, nj);
}

int main()
{
    int i;
    int j;
    char direction = '>';

    i = 2;
    j = 0;

    cout << "\nPress ENTER to see the object's next steps\n";

    char arr[12][12] = {

        '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#',
        'o', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#',
        '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#',
        '#', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', ' ', '#',
        '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',
        '#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',
        '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#',
        '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#',
        '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#',
        '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'};

    move(arr, direction, i, j);

    return 0;
}