#include "cnake.h"

Cnake::Cnake() {
  head = new Node(SOUTH, 0, 4);
  tail = head;
  grow();
  grow();
  grow();
}

Cnake::~Cnake() {
  Node* p = head->child;
  Node* n = head->child;

  while(true) {
    n = p->child;
    if(n == NULL) {
      free(p);
      break;
    }
    free(p);
    p = n;
  }
}

void Cnake::updateNodes() {
  moveNode(head);
  updateNodes(head);
}

void Cnake::updateNodes(Node* n) {
  if(n->child == NULL) return;
  Node* child = n->child;
  moveNode(child);
  child->d = locateNode(child, n);
  updateNodes(child);
}

void Cnake::grow() {
  Node* newTail = new Node(SOUTH, tail->xPos, tail->yPos - 1);
  tail->child = newTail;
  tail = newTail;
}

// TODO the if handling is flawed in the case where the Nodes overlap
Direction Cnake::locateNode(Node* base, Node* target) {
  if(target->xPos > base->xPos) return EAST;
  if(target->xPos < base->xPos) return WEST;
  if(target->yPos > base->yPos) return SOUTH;
  return NORTH;
}

void Cnake::moveNode(Node* n) {
  switch(n->d) {
    case NORTH:
      --n->yPos;
      break;
    case SOUTH:
      ++n->yPos;
      break;
    case WEST:
      --n->xPos;
      break;
    case EAST:
      ++n->xPos;
      break;
  }
}

Node::Node(Direction d, int xPos, int yPos) {
  this->d = d;
  this->xPos = xPos;
  this->yPos = yPos;
  this->child = NULL;
}

Node::~Node() {
}

