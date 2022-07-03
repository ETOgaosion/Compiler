#include <iostream>

#include "antlr4-runtime.h"
#include "../grammar/CACTLexer.h"
#include "../grammar/CACTParser.h"
#include "../grammar/CACTBaseListener.h"

#include "semanticAnalysis.h"
#include <string>

using namespace antlr4;

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    int errorNum = 0;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    CACTLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    CACTParser parser(&tokens);
    tree::ParseTree *tree = parser.compUnit();
    SemanticAnalysis listener;
    listener.programName = std::string(argv[1]).substr(0, std::string(argv[1]).find_last_of("."));
    if (argc > 2) {
        if (argv[2][0] == '-' && argv[2][1] == 'O') {
            listener.optimizationLevel = argv[2][2] - '0';
        }
    }
    else {
        listener.optimizationLevel = 0;
    }

    if (errorNum = lexer.getNumberOfSyntaxErrors()) {
        std::cout << "[Error]> Lexer reported " << errorNum << " errors." << std::endl;
        goto exit;
    }
    if (errorNum = parser.getNumberOfSyntaxErrors()) {
        std::cout << "[Error]> Parser reported " << errorNum << " syntax errors." << std::endl;
        goto exit;
    }

    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);


    // std::cout << "-------------------------Print AST:--------------------------" << std::endl;
    // std::cout << tree->toStringTree(&parser) << std::endl;

exit:
    return errorNum;
}
