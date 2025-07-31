#include <iostream>
#include <string>

using namespace std;

void showMap(int position) {
    string map = "Start -> ";
    for (int i = 0; i < 5; ++i) {
        if (i == position)
            map += "[You] ";
        else
            map += "[ ] ";
    }
    map += "-> Exit";
    cout << map << endl;
}

int main() {
    int position = 0;
    string move;
    cout << "🌴 Welcome to 'Lost in the Jungle' 🌴" << endl;
    cout << "You must find your way to the exit. Use 'left' or 'right' to move." << endl;

    while (position < 5) {
        showMap(position);
        cout << "Enter move: ";
        cin >> move;

        if (move == "right") {
            if (position < 4)
                position++;
            else
                cout << "🧱 There's a wall, can't move further right!" << endl;
        } else if (move == "left") {
            if (position > 0)
                position--;
            else
                cout << "🕳️ You can't go back beyond the start!" << endl;
        } else {
            cout << "❌ Invalid move! Try 'left' or 'right'." << endl;
        }
    }

    cout << "\n🎉 Congrats! You found the exit of the jungle! 🌟\n";
    return 0;
}
