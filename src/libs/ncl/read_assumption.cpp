#include "read_assumption.h"
#include "nxsreader.h"
#include "nxsdefs.h"
#include "nxstoken.h"
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * Helper function to ensure that a token ends with a semicolon.
 */
void CheckEndSemicolon(NxsToken &token, const std::string &context) {
    token.GetNextToken();
    if (!token.Equals(";")) {
        throw NxsException("Expected ';' after " + context, token.GetFilePosition(), token.GetFileLine(), token.GetFileColumn());
    }
}

/**
 * Helper function to ensure that the token is an equals sign.
 */
void CheckEqualsSign(NxsToken &token, const std::string &context) {
    token.GetNextToken();
    if (!token.Equals("=")) {
        throw NxsException("Expected '=' after " + context, token.GetFilePosition(), token.GetFileLine(), token.GetFileColumn());
    }
}

/**
 * Preprocesses the token, typically handling range tokens.
 */
void PreprocessRangeToken(NxsToken &token) {
    std::stringstream processedToken;
    // Your custom logic for processing the token
    // For example: processedToken << "modified_" << token.GetToken();

    token.ReplaceToken(NxsString(processedToken.str().c_str())); // Using NxsString constructor
}

/**
 * Reads and processes the ASSUMPTIONS block from the NEXUS file.
 */
void NxsReaderExtended::ReadAssumptionsBlock(NxsToken &token) {
    token.GetNextToken();  // Read the next token after "BEGIN ASSUMPTIONS"

    while (!token.Equals("END") && !token.Equals("ENDBLOCK")) {
        if (token.Equals("OPTIONS")) {
            CheckEndSemicolon(token, "OPTIONS");
        } else if (token.Equals("TYPESET")) {
            CheckEqualsSign(token, "TYPESET");
            token.GetNextToken();  // Process the typeset value
            CheckEndSemicolon(token, "TYPESET");
        } else {
            SkippingBlock(token.GetToken());
            token.GetNextToken();  // Skip unknown commands
        }
    }
    token.GetNextToken(); // Skip the "END" or "ENDBLOCK" command
}

/**
 * Reads the entire NEXUS file from the provided input stream.
 */
void NxsReaderExtended::ReadFile(std::istream &in) {
    NxsToken token(in);

    token.GetNextToken();  // Start reading the file
    while (!token.AtEOF()) {
        if (token.Equals("BEGIN")) {
            token.GetNextToken();  // Read the block type
            if (token.Equals("ASSUMPTIONS")) {
                ReadAssumptionsBlock(token);
            } else {
                SkippingBlock(token.GetToken());  // Handle unknown blocks
            }
        }
        token.GetNextToken();
    }
}
