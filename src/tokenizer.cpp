#include "tokenizer.hpp"

std::vector<Token> tokenizer(std::string code) {
  std::vector<Token> tokens;

  int current = 0;

  while (current < code.size()) {
    char currentChar = code[current];

    if (currentChar == ' ') {
      current++;
      continue;
    }

    if (currentChar == '(') {
      Token token(TokenTypes::Paren, "(");
      tokens.push_back(token);
      current++;
      continue;
    }

    if (currentChar == ')') {
      Token token(TokenTypes::Paren, ")");
      tokens.push_back(token);
      current++;
      continue;
    }

    if (isalpha(currentChar)) {
      std::string value = "";
      while (isalpha(currentChar) && current < code.size()) {
        value += currentChar;
        currentChar = code[++current];
      }
      Token token(TokenTypes::Name, value);
      tokens.push_back(token);
      continue;
    }

    if (isalnum(currentChar)) {
      std::string value = "";
      while (isalnum(currentChar) && current < code.size()) {
        value += currentChar;
        currentChar = code[++current];
      }
      Token token(TokenTypes::Number, value);
      tokens.push_back(token);
      continue;
    }
  }
  return tokens;
}
