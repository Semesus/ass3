#include <iostream>
#include "creature.h"
#include "maze.h"

void test() {
    Maze M("maze.txt");
    Creature C(4, 4);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
}

void test2() {
    Maze M("maze1.txt");
    Creature C(5, 18);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
}

void test3() {
    Maze M("maze2.txt");
    Creature C(4, 3);
    cout << "Path: " << C.solve(M) << endl;
    cout << M << endl;
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