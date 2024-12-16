#ifndef GLOBAL_VARIABLES_H
#define GLOBAL_VARIABLES_H

#include <vector>
#include <utility>

// Declare global variables
extern std::vector<std::pair<int, int>> orderedMatrix;
extern std::vector<std::pair<int, int>> unorderedMatrix;

// Getter functions
const std::vector<std::pair<int, int>>& getOrderedMatrix();
const std::vector<std::pair<int, int>>& getUnorderedMatrix();

// Setter functions (optional, if needed)
void setOrderedMatrix(const std::vector<std::pair<int, int>>& matrix);
void setUnorderedMatrix(const std::vector<std::pair<int, int>>& matrix);

#endif // GLOBAL_VARIABLES_H
