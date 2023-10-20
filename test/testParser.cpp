#include <cstddef>
#include <gtest/gtest.h>

#include <memory>
#include <string>
#include <vector>

#include "../src/parser.hpp"

TEST(ParserTest, BasicTest) {

  std::vector<Token> tokens = tokenizer("(add 2 (subtract 4 2))");

  std::shared_ptr<RootNode> root = parser(tokens);

  EXPECT_EQ(root->body.size(), 1);
  // EXPECT_EQ(root->body[0]->type,NodeTypes::CallExpression); 
  // std::shared_ptr<CallExpressionNode> callExpressionNode = std::dynamic_pointer_cast<CallExpressionNode>(root->body[0]);
  // EXPECT_EQ(callExpressionNode->name, "add");
}
