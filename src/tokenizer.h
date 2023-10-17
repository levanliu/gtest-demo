#pragma once

#include <string>
#include <vector>
enum TokenTypes { Paren, Name, Number, String };

struct Token {
  TokenTypes type;
  std::string value;
  Token(TokenTypes _type,std::string _value){
    type = _type;
    value = _value;
  }
};

std::vector<Token> tokenizer(std::string code);
