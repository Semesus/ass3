//
//

#include "creature.h"
#include <stack>

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
    stack<string> stackPath;
    maze.markAsPath(row_, col_);
    if(atExit(maze)) {
        return path;
    }
    path = goNorth(maze);
    if(path == "X") {
        path = goSouth(maze);
        if(path == "X") {
            path = goWest(maze);
             if(path == "X") {
                path = goEast(maze);
            }
        }
    }
    path = "";
    /*
    while(!soln_.empty()) {
        path += soln_.pop();
    }*/
    for(int i = 0; i < soln_.size(); i++) {
        path += soln_.at(i);
    }
    return path;
}

string Creature::goNorth(Maze &maze) {
    string path;
    //stack<string> stackPath;
    if(maze.isClear(row_ - 1, col_)) { // if clear to north
        maze.markAsPath(row_, col_);        // mark as path
        path += "N";
        soln_.push_back(path);
        row_--;                             // move north
        if(atExit(maze)) {                  // if at exit
            path += "N";
            soln_.push_back(path);
            maze.markAsPath(row_,col_);     // mark as path
        } else {                            // if wall or visited
            path = goNorth(maze);        // try north again
            if(path == "X") {
                path = goWest(maze);     // try west
                if(path == "X") {
                    path = goEast(maze); // try east
                    if(path == "X") {
                        maze.markAsVisited(row_, col_); // mark as visited
                        soln_.pop_back();
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
    string path;
    if(maze.isClear(row_, col_ - 1)) {
        maze.markAsPath(row_, col_);
        path += "W";
        soln_.push_back(path);
        col_--;
        if(atExit(maze)) {
            path += "W";
            soln_.push_back(path);
            maze.markAsPath(row_, col_);
        } else {
            path = goWest(maze);
            if(path == "X") {
                path = goNorth(maze);
                if(path == "X") {
                    path = goSouth(maze);
                    if(path == "X") {
                        maze.markAsVisited(row_, col_);
                        soln_.pop_back();
                        col_++;
                    }
                }
            }
        }
    } else {
        path = "X";
    }
  return path;
}

string Creature::goEast(Maze &maze) {
    string path;
    if(maze.isClear(row_, col_ + 1)) {
        maze.markAsPath(row_, col_);
        path +="E";
        soln_.push_back(path);
        col_++;
        if(atExit(maze)) {
            path += "E";
            soln_.push_back(path);
            maze.markAsPath(row_, col_);
        } else {
            path = goEast(maze);
            if(path == "X") {
                path = goNorth(maze);
                if(path == "X") {
                    path = goSouth(maze);
                    if(path == "X") {
                        maze.markAsVisited(row_, col_);
                        soln_.pop_back();
                        col_--;
                    }
                }
            }
        }
    } else {
        path = "X";
    }
    return path;
}

string Creature::goSouth(Maze &maze) {
    string path;
    if(maze.isClear(row_ + 1, col_)) {
        maze.markAsPath(row_, col_);
        path += "S";
        soln_.push_back(path);
        row_++;
        if(atExit(maze)) {
            path += "S";
            soln_.push_back(path);
            maze.markAsPath(row_, col_);
        } else {
            path = goSouth(maze);
            if(path == "X") {
                path = goWest(maze);
                if(path == "X") {
                    path = goEast(maze);
                    if(path == "X") {
                        maze.markAsVisited(row_, col_);
                        soln_.pop_back();
                        row_--;
                    }
                }
            }
        }
    } else {
        path = "X";
    }

  return path;
}
