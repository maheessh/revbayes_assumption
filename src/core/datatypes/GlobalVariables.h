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

// Setter functions
void setOrderedMatrix(const std::vector<std::pair<int, int>>& matrix);
void setUnorderedMatrix(const std::vector<std::pair<int, int>>& matrix);

// Registration functions for interpreter
void registerOrderedMatrix();
void registerUnorderedMatrix();

#endif // GLOBAL_VARIABLES_H
