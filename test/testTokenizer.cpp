#include <cstddef>
#include <gtest/gtest.h>

#include "../src/tokenizer.hpp"

TEST(left_paren, tokenizer) {
  std::string code = "(";
  TokenTypes paren = TokenTypes::Paren;
  struct Token token(paren, "(");
  std::vector<Token> tokens;
  tokens.push_back(token);
  for (std::size_t i = 0; i < tokens.size(); i++) {
    ASSERT_EQ(tokens[i].type, tokenizer(code)[i].type);
    ASSERT_EQ(tokens[i].value, tokenizer(code)[i].value);
  }
}

TEST(right_paren, tokenizer) {
  std::string code = ")";
  TokenTypes paren = TokenTypes::Paren;
  struct Token token(paren, ")");
  std::vector<Token> tokens;
  tokens.push_back(token);
  for (std::size_t i = 0; i < tokens.size(); i++) {
    ASSERT_EQ(tokens[i].type, tokenizer(code)[i].type);
    ASSERT_EQ(tokens[i].value, tokenizer(code)[i].value);
  }
}

TEST(add, tokenizer) {
  std::string code = "add";
  TokenTypes name = TokenTypes::Name;
  struct Token token(name, "add");
  std::vector<Token> tokens;
  tokens.push_back(token);
  for (std::size_t i = 0; i < tokens.size(); i++) {
    ASSERT_EQ(tokens[i].type, tokenizer(code)[i].type);
    ASSERT_EQ(tokens[i].value, tokenizer(code)[i].value);
  }
}


TEST(number, tokenizer) {
  std::string code = "22";
  TokenTypes number = TokenTypes::Number;
  struct Token token(number, "22");
  std::vector<Token> tokens;
  tokens.push_back(token);
  for (std::size_t i = 0; i < tokens.size(); i++) {
    ASSERT_EQ(tokens[i].type, tokenizer(code)[i].type);
    ASSERT_EQ(tokens[i].value, tokenizer(code)[i].value);
  }
}

TEST(expression, tokenizer) {
  std::string code = "(add 1 2)";
  struct Token token0(TokenTypes::Paren, "(");
  struct Token token1(TokenTypes::Name, "add");
  struct Token token2(TokenTypes::Number, "1");
  struct Token token3(TokenTypes::Number, "2");
  struct Token token4(TokenTypes::Paren, ")");
  std::vector<Token> tokens;
  tokens.push_back(token0);
  tokens.push_back(token1);
  tokens.push_back(token2);
  tokens.push_back(token3);
  tokens.push_back(token4);

  for (std::size_t i = 0; i < tokens.size(); i++) {
    ASSERT_EQ(tokens[i].type, tokenizer(code)[i].type);
    ASSERT_EQ(tokens[i].value, tokenizer(code)[i].value);
  }
}
