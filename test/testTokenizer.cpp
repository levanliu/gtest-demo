#include <cstddef>
#include <gtest/gtest.h>

#include "../src/tokenizer.h"

TEST(left_paren, tokenizer) {
  std::string code = "(";
  TokenTypes paren = Paren;
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
  TokenTypes paren = Paren;
  struct Token token(paren, ")");
  std::vector<Token> tokens;
  tokens.push_back(token);
  for (std::size_t i = 0; i < tokens.size(); i++) {
    ASSERT_EQ(tokens[i].type, tokenizer(code)[i].type);
    ASSERT_EQ(tokens[i].value, tokenizer(code)[i].value);
  }
}
