#include <iostream>
#include "creature.h"
#include "maze.h"
#include <cassert>

void test() {
    Maze M("maze.txt");
    Creature C(4, 4);
    string path = C.solve(M);
    cout << "Path: " << path << endl;
    cout << M << endl;
    assert(path == "EEENNNEEEEEESEESSSEEENNNNN");
}

void test2() {
    Maze M("maze1.txt");
    Creature C(5, 18);
    string path = C.solve(M);
    cout << "Path: " << path << endl;
    cout << M << endl;
    assert(path == "WWWNNNWWNWWWWWWWWWWN");

}

void test3() {
    Maze M("maze2.txt");
    Creature C(4, 3);
    string path = C.solve(M);
    cout << "Path: " << path << endl;
    cout << M << endl;
    assert(path == "EEEENNNEEEEEESEESSSEEENNNNEEEEEEEEESSEENEEEEEEEESSSEEEEEEENNEEENEESSSEEEEEEEENNWWWWWWNNN");
}

void test4() {
    Maze M("maze3.txt");
    Creature C(1, 51);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
}

void test5() {
    Maze M("maze4.txt");
    Creature C(1, 50);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
}

int main() {
    test();
    test2();
    test3();
    test4();
    test5();
    cout << "Done!" << std::endl;
    return 0;
}