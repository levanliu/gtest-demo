#pragma once
#include "../src/tokenizer.hpp"
#include "./ast.hpp"
#include <stdexcept>
#include <iostream>

std::shared_ptr<Node> walk(std::vector<Token> &tokens,
                           int &current); // declaration

std::shared_ptr<RootNode> parser(std::vector<Token> tokens) {
  std::shared_ptr<RootNode> root = createRootNode();

  int current = 0;

  while (current < tokens.size()) {
    root->body.push_back(walk(tokens, current));
    std::cout << root->body.size() << std::endl;
  }

  return root;
}

std::shared_ptr<Node> walk(std::vector<Token> &tokens,
                           int &current) { // definition
  Token token = tokens[current];

  if (token.type == TokenTypes::Number) {
    current++;

    return createNumberLiteralNode(token.value);
  }

  if (token.type == TokenTypes::String) {
    current++;

    return createStringLiteralNode(token.value);
  }

  if (token.type == TokenTypes::Paren && token.value == "(") {
    token = tokens[++current];

    auto node = createCallExpression(token.value);

    token = tokens[++current];
    while (!(token.type == TokenTypes::Paren && token.value == ")")) {
      node->params.push_back(walk(tokens, current));
      token = tokens[current];
    }

    current++;

    return node;
  }

  throw std::runtime_error("token: " + token.value);
}

