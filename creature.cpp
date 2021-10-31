/****************************************************************
 * Creature.cpp
 * Devin Clarke
 * CSS 342
 * Created 10/19/21
 * C++
 *
 * This program uses recursive backtracking to solve a maze. The
 * algorithm attempts possible solutions one step at a time. If
 * current path won't lead to a viable solution, it reverts back
 * to previous steps to try other paths.
 * **************************************************************/

#include "creature.h"

/**
 * Overloaded ostream operator<< prints creature coordinates to console
 * @param out: the ostream
 * @param creature: creature object to display
 * @return valid ostream reference
 * */
std::ostream &operator<<(std::ostream &out, const Creature &creature) {
    out << "C(" << creature.row_ << ", " << creature.col_ << ")" << endl;
    return out;
} // operator<<

/**
 * Creature Class Constructor
 * Creates and initializes creature at starting position in maze
 * @param row: Starting row position of creature
 * @param col: Starting column position of creature
 * */
Creature::Creature(int row, int col) : row_(row), col_(col) {}

/**
 * Recursively solves maze and returns solution path
 * @param maze: a valid maze object
 * @return: string of successful maze solution
 * */
string Creature::solve(Maze &maze) {
    string path;
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
    for(int i = 0; i < soln_.size(); i++) {
        path += soln_.at(i);
    }
    return path;
} //solve()

/**
 * Returns if creature is at maze exit
 * @param maze: a valid maze object
 * @return: true if creature at exit coordinates, else false
 * */
bool Creature::atExit(const Maze &maze) const {
    return row_ == maze.getExitRow() && col_ == maze.getExitColumn();
} // atExit()

/**
 * Moves north recursively until exit or wall found,
 * marking as path or visited. If no successful path,
 * backtracks to coordinate where called.
 * @param maze: a valid maze object
 * @return "N" if viable path, "X" if no path
 * */
string Creature::goNorth(Maze &maze) {
    string path;
    if(maze.isClear(row_ - 1, col_)) { // if no wall and not visited
        maze.markAsPath(row_, col_);        // mark as path
        soln_.push_back("N");               // add path to vector
        row_--;                             // move north
        if(atExit(maze)) {                  // if at exit
            maze.markAsPath(row_,col_);     // mark as path
        } else {
            path = goNorth(maze);        // try north again
            if(path == "X") {               // if wall
                path = goWest(maze);     // try west
                if(path == "X") {
                    path = goEast(maze); // try east
                    if(path == "X") {       // not a viable path
                        // mark as visited
                        maze.markAsVisited(row_, col_);
                        //remove path from vector
                        soln_.pop_back();
                        // backtrack
                        row_++;
                    }
                }
            }
        }
    } else {
        // mark as wall
        path = "X";
    }
    return path;
} // goNorth()

/**
 * Moves south recursively until exit or wall found,
 * marking as path or visited. If no successful path,
 * backtracks to coordinate where called.
 * @param maze: a valid maze object
 * @return "S" if viable path, "X" if no path
 * */
string Creature::goSouth(Maze &maze) {
    string path;
    if(maze.isClear(row_ + 1, col_)) {
        maze.markAsPath(row_, col_);
        soln_.push_back("S");
        row_++;
        if(atExit(maze)) {
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
} // goSouth()

/**
 * Moves east recursively until exit or wall found,
 * marking as path or visited. If no successful path,
 * backtracks to coordinate where called.
 * @param maze: a valid maze object
 * @return "E" if viable path, "X" if no path
 * */
string Creature::goEast(Maze &maze) {
    string path;
    if(maze.isClear(row_, col_ + 1)) {
        maze.markAsPath(row_, col_);
        soln_.push_back("E");
        col_++;
        if(atExit(maze)) {
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
} // goEast()

/**
 * Moves west recursively until exit or wall found,
 * marking as path or visited. If no successful path,
 * backtracks to coordinate where called.
 * @param maze: a valid maze object
 * @return "W" if viable path, "X" if no path
 * */
string Creature::goWest(Maze &maze) {
    string path;
    if(maze.isClear(row_, col_ - 1)) {
        maze.markAsPath(row_, col_);
        soln_.push_back("W");
        col_--;
        if(atExit(maze)) {
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
} // goWest()


