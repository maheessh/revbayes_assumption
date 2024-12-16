#include "GlobalVariables.h"

// Define global variables
std::vector<std::pair<int, int>> orderedMatrix;
std::vector<std::pair<int, int>> unorderedMatrix;

// Implement getter functions
const std::vector<std::pair<int, int>>& getOrderedMatrix() {
    return orderedMatrix;
}

const std::vector<std::pair<int, int>>& getUnorderedMatrix() {
    return unorderedMatrix;
}

// Implement setter functions (optional, if needed)
void setOrderedMatrix(const std::vector<std::pair<int, int>>& matrix) {
    orderedMatrix = matrix;
}

void setUnorderedMatrix(const std::vector<std::pair<int, int>>& matrix) {
    unorderedMatrix = matrix;
}