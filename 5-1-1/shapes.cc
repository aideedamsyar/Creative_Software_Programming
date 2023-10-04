#include "shapes.h" 
#include <iostream> 
using namespace std;

static char **init(char **matrix, const size_t row, const size_t col) { 
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j) 
            matrix[i][j] = '.';
    return matrix; 
}

static char **auto_alloc(const size_t row, const size_t col) { 
    char **matrix = new char*[row];
    for (int i = 0; i < row; ++i) matrix[i] = new char[col];

    matrix = init(matrix, row, col);

    return matrix; 
}

static void auto_delete(char **matrix, const size_t row, const size_t col) { 
    for (int i = 0; i < row; ++i) delete[] matrix[i];
    delete[] matrix;
}

void Canvas::Print() const { 
    cout << " ";
    for (int i = 0; i < this->col; ++i) cout << (i); 
    cout << endl;


    for (int i = 0; i < this->row; ++i) { 
        cout << (i);
        for (int j = 0; j < this->col; ++j) cout << this->canvas[i][j];
        cout << endl; 
    }
}

void Canvas::Clear() {
    this->canvas = init(this->canvas, this->row, this->col);
}
// Implement your code