#include "Matrix.h"

Matrix& Matrix::operator=(const std::vector<std::vector<int>>& data) {
    _data = data;
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    int rows = std::min(_data.size(), other._data.size());
    int cols = std::min(_data[0].size(), other._data[0].size());

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            _data[i][j] += other._data[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    int rows = std::min(_data.size(), other._data.size());
    int cols = std::min(_data[0].size(), other._data[0].size());

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            _data[i][j] -= other._data[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    int rows = std::min(_data.size(), other._data.size());
    int cols = std::min(_data[0].size(), other._data[0].size());

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            _data[i][j] *= other._data[i][j];
        }
    }

    return *this;
}

Matrix& Matrix::operator/=(const Matrix& other) {
    int rows = std::min(_data.size(), other._data.size());
    int cols = std::min(_data[0].size(), other._data[0].size());

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (other._data[i][j] != 0) {
                _data[i][j] /= other._data[i][j];
            }
            else {
                _data[i][j] = 0; // Division by zero, set result to 0
            }
        }
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (const auto& row : matrix._data) {
        for (const auto& element : row) {
            os << element << " ";
        }
        os << std::endl;
    }
    return os;
}
