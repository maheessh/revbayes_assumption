#ifndef READ_ASSUMPTION_H
#define READ_ASSUMPTION_H

#include "nxsreader.h"
#include <string>
#include <set>
#include <map>
#include <iostream>

/*!
    Class to extend NxsReader for handling custom assumptions parsing.
*/
class NxsReaderExtended : public NxsReader {
public:
    void ReadFile(std::istream& in);
protected:
    void ReadAssumptionsBlock(NxsToken& token);
};

/*!
    Function to preprocess and handle ranges in the assumptions block.
*/
void PreprocessRangeToken(NxsToken& token);

#endif // READ_ASSUMPTION_H
