//
//

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>

class Creature {
public:
  friend ostream &operator<<(ostream &out, const Creature &creature);

private:
  int row_;
  int col_;

public:
  Creature(int row, int col);
  string solve(Maze &maze);
  bool atExit(const Maze &maze) const;
  string goNorth(Maze &maze);
  string goSouth(Maze &maze);
  string goEast(Maze &maze);
  string goWest(Maze &maze);
};

#endif //ASS3_CREATURE_H
