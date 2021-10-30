/****************************************************************
 * Creature.h
 * Devin Clarke
 * CSS 342
 * Created 10/19/21
 * C++
 *
 * This program uses recursive backtracking to solve a maze. The
 * algorithm attempts possible solutions one step ata time. If
 * current path won't lead to a viable solution, it reverts back
 * to previous steps to try other paths.
 * **************************************************************/

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>
#include <vector>

class Creature {
public:
    // overloaded ostream operator<< prints creature coordinates
    friend ostream &operator<<(ostream &out, const Creature &creature);

private:
    int row_;
    int col_;
    // private vector holds solution path
    vector<string> soln_;

public:
    // ctor initializes creature starting position
    Creature(int row, int col);
    // recursively solves maze
    string solve(Maze &maze);
    // checks if creature at exit
    bool atExit(const Maze &maze) const;
    // moves creature north
    string goNorth(Maze &maze);
    // moves creature south
    string goSouth(Maze &maze);
    // moves creature east
    string goEast(Maze &maze);
    // moves creature west
    string goWest(Maze &maze);
};

#endif //ASS3_CREATURE_H
