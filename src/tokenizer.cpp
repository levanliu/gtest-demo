#include "tokenizer.h"

std::vector<Token> tokenizer(std::string code) {
  std::vector<Token> tokens;

  int current = 0;

  char currentChar = code[current];
  if (currentChar == '(') {
    Token token(Paren, "(");
    tokens.push_back(token);
  }

  if (currentChar == ')') {
    Token token(Paren, ")");
    tokens.push_back(token);
  }

  return tokens;
}
