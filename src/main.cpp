#include <iostream>

#include "antlr4-runtime.h"
#include "../grammar/CACTLexer.h"
#include "../grammar/CACTParser.h"
#include "../grammar/CACTBaseListener.h"

#include "semanticAnalysis.h"

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

    if (errorNum = lexer.getNumberOfSyntaxErrors()) {
        std::cout << "[Error]> Lexer reported " << errorNum << " errors." << std::endl;
        return 1;
    }
    if (errorNum = parser.getNumberOfSyntaxErrors()) {
        std::cout << "[Error]> Parser reported " << errorNum << " syntax errors." << std::endl;
        return 1;
    }

    SemanticAnalysis listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
    
    std::cout << "debug: hello" << std::endl;


    std::cout << "-------------------------Print AST:--------------------------" << std::endl;
    std::cout << tree->toStringTree(&parser) << std::endl;

}
