#ifndef ASTAR_HPP
#define ASTAR_HPP

#include <vector>
#include <utility>

class AStar {
private:
    bool* collisionGrid;
    int cols, rows;
    bool moveDiagonally;
    const std::vector<std::pair<int, int>> directions = {
        { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 },
        { -1, -1 }, { 1, 1 }, { -1, 1 }, { 1, -1 }
    };
    
    float heuristic_cost_estimate(int x1, int y1, int x2, int y2);
    bool isCollisionAt(int x, int y) { return collisionGrid[y * cols + x]; }

public:
    AStar(bool* collisionGrid, int cols, int rows, bool moveDiagonally)
        : collisionGrid(collisionGrid)
        , cols(cols)
        , rows(rows)
        , moveDiagonally(moveDiagonally) {
    }
    std::vector<std::pair<int, int>> findPath(int x1, int y1, int x2, int y2);
};

#endif /* ASTAR_HPP */
