#include "Snake.h"
#include <algorithm>

Snake::Snake(const int fieldRows, const int fieldCols, const Point& startPos)
    : _FIELD_ROWS(fieldRows), _FIELD_COLS(fieldCols), _currPos(startPos)
{
    // Initialize snake with starting position
    _snakeNodes.push_back(startPos);
}

Snake::~Snake()
{
    // Destructor is empty as there is no dynamic memory allocation
}

StatusCode Snake::move(const Direction dir, const std::vector<Point>& obstacles, std::vector<Point>& powerUps)
{
    // Calculate the new position based on the direction
    Point newPos = _currPos;
    switch (dir)
    {
    case Direction::UP:
        newPos.row--;
        break;
    case Direction::RIGHT:
        newPos.col++;
        break;
    case Direction::DOWN:
        newPos.row++;
        break;
    case Direction::LEFT:
        newPos.col--;
        break;
    default:
        break;
    }

    // Check if the new position is within the field bounds
    if (newPos.row < 0 || newPos.row >= _FIELD_ROWS || newPos.col < 0 || newPos.col >= _FIELD_COLS)
    {
        return StatusCode::SNAKE_DEAD;
    }

    // Check if the new position is on an obstacle
    for (const auto& obstacle : obstacles)
    {
        if (obstacle == newPos)
        {
            return StatusCode::SNAKE_DEAD;
        }
    }

    // Check if the new position is on the snake's body
    for (const auto& node : _snakeNodes)
    {
        if (node == newPos)
        {
            return StatusCode::SNAKE_DEAD;
        }
    }

    // Check if the new position is on a power-up
    auto it = std::find(powerUps.begin(), powerUps.end(), newPos);
    if (it != powerUps.end())
    {
        // Remove the power-up from the vector
        powerUps.erase(it);
        // Snake is growing, so just add the new position to the snake nodes
        _snakeNodes.push_front(newPos);
        _currPos = newPos;
        return StatusCode::SNAKE_GROWING;
    }

    // Move the snake
    _snakeNodes.pop_back(); // Remove the tail
    _snakeNodes.push_front(newPos); // Add the new position as the head
    _currPos = newPos;

    return StatusCode::SNAKE_MOVING;
}

std::deque<Point>& Snake::getSnakeNodes()
{
    return _snakeNodes;
}
