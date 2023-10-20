#pragma once

#include <memory>
#include <set>
#include <string>
#include <vector>

enum class NodeTypes {
  NumberLiteral,
  Program,
  StringLiteral,
  CallExpression,
};

struct Node {
  NodeTypes type;
};

struct NumberLiteralNode : Node {
  NodeTypes type = NodeTypes::NumberLiteral;
  std::string value;
};

struct StringLiteralNode : Node {
  NodeTypes type = NodeTypes::StringLiteral;
  std::string value;
};

struct CallExpressionNode : Node {
  NodeTypes type = NodeTypes::CallExpression;
  std::string name;
  std::vector<std::shared_ptr<Node>> params;
  std::vector<std::shared_ptr<Node>> context;
};

struct RootNode : Node {
  NodeTypes type = NodeTypes::Program;
  std::vector<std::shared_ptr<Node>> body;
  std::vector<std::shared_ptr<Node>> context;
};


std::shared_ptr<StringLiteralNode> createStringLiteralNode(std::string value)
{
    auto node = std::make_shared<StringLiteralNode>();
    node->value = value;
    return node;
}

std::shared_ptr<RootNode> createRootNode()
{
    return std::make_shared<RootNode>();
}

std::shared_ptr<NumberLiteralNode> createNumberLiteralNode(std::string value)
{
    auto node = std::make_shared<NumberLiteralNode>();
    node->value = value;
    return node;
}

std::shared_ptr<CallExpressionNode> createCallExpression(std::string name)
{
    auto node = std::make_shared<CallExpressionNode>();
    node->name = name;
    return node;
}