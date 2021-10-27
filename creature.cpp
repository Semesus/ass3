//
//

#include "creature.h"

std::ostream &operator<<(std::ostream &out, const Creature &creature) {
    out << "C(" << creature.row_ << ", " << creature.col_ << ")" << endl;
  return out;
}

Creature::Creature(int row, int col) : row_(row), col_(col) {}

bool Creature::atExit(const Maze &maze) const {
    return row_ == maze.getExitRow() && col_ == maze.getExitColumn();
}

string Creature::solve(Maze &maze) {
  string path;
  return path;
}

string Creature::goNorth(Maze &maze) {
    string path;
    if(maze.isClear(row_ - 1, col_)) { // if clear to north
        maze.markAsPath(row_, col_);        // mark as path
        row_--;                             // move north
        if(atExit(maze)) {                  // if at exit
            path += "N";
            maze.markAsPath(row_,col_);     // mark as path
        } else {                            // if wall or visited
            path = goNorth(maze);        // try north again
            if(path == "X") {
                path = goWest(maze);     // try west
                if(path == "X") {
                    path = goEast(maze); // try east
                    if(path == "X") {
                        maze.markAsVisited(row_, col_); // mark as visited
                        row_++;                         // backtrack
                    }
                }
            }
        }
    } else {
        path = "X";                         // mark as wall
    }
    return path;
}

string Creature::goWest(Maze &maze) {

  return "X";
}

string Creature::goEast(Maze &maze) {
  return "X";
}

string Creature::goSouth(Maze &maze) {
  return "X";
}
