#include "GlobalVariables.h"
#include "RbException.h"
#include "RevObject.h"
#include "RbVector.h"
#include "Workspace.h"

// Global matrices
std::vector<std::pair<int, int>> orderedMatrix;
std::vector<std::pair<int, int>> unorderedMatrix;

// Getters
const std::vector<std::pair<int, int>>& getOrderedMatrix() {
    return orderedMatrix;
}

const std::vector<std::pair<int, int>>& getUnorderedMatrix() {
    return unorderedMatrix;
}

// Setters
void setOrderedMatrix(const std::vector<std::pair<int, int>>& matrix) {
    orderedMatrix = matrix;
}

void setUnorderedMatrix(const std::vector<std::pair<int, int>>& matrix) {
    unorderedMatrix = matrix;
}

// RevObject-compatible wrapper for ordered and unordered matrices
class RevMatrixWrapper : public RevLanguage::RevObject {
public:
    explicit RevMatrixWrapper(const std::vector<std::pair<int, int>>& matrix)
        : internalMatrix(matrix) {}

    // Clone method
    RevMatrixWrapper* clone() const override {
        return new RevMatrixWrapper(*this);
    }

    // Return the TypeSpec for RevMatrixWrapper
    const RevLanguage::TypeSpec& getTypeSpec() const override {
        static RevLanguage::TypeSpec typeSpec("MatrixWrapper", &RevLanguage::RevObject::getClassTypeSpec());
        return typeSpec;
    }

    // Print method for the wrapped matrix
    void printValue(std::ostream& o, bool user) const override {
        o << "[ ";
        for (const auto& pair : internalMatrix) {
            o << "(" << pair.first << ", " << pair.second << ") ";
        }
        o << "]";
    }

private:
    std::vector<std::pair<int, int>> internalMatrix; // Internal storage
};

// Register ordered matrix
void registerOrderedMatrix() {
    using namespace RevLanguage;

    // Wrap orderedMatrix into a RevMatrixWrapper
    RevMatrixWrapper* wrappedOrderedMatrix = new RevMatrixWrapper(orderedMatrix);

    // Add the wrapped matrix to the global workspace
    Workspace::globalWorkspace().addVariable("orderedMatrix", wrappedOrderedMatrix);
}

// Register unordered matrix
void registerUnorderedMatrix() {
    using namespace RevLanguage;

    // Wrap unorderedMatrix into a RevMatrixWrapper
    RevMatrixWrapper* wrappedUnorderedMatrix = new RevMatrixWrapper(unorderedMatrix);

    // Add the wrapped matrix to the global workspace
    Workspace::globalWorkspace().addVariable("unorderedMatrix", wrappedUnorderedMatrix);
}
