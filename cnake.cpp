#include "cnake.h"

Cnake::Cnake() {
  initNode(head, SOUTH, 4, 4);
  grow();
  grow();
  grow();
}

Cnake::~Cnake() {
  node* p = head->child;
  node* n = head->child;

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

void Cnake::updateNodes(node* n) {
  if(n->child == NULL) return;
  node* child = n->child;
  moveNode(child);
  child->d = locateNode(n, child);
  updateNodes(child);
}

void Cnake::grow() {
  node* newTail = (node*) malloc(sizeof(node));
  initNode(newTail, SOUTH, tail->xPos, tail->yPos - 1);
  tail->child = newTail;
  tail = newTail;
}

// TODO the if handling is flawed in the case where the nodes overlap
Direction Cnake::locateNode(node* base, node* target) {
  if(target->xPos > base->xPos) return EAST;
  if(target->xPos < base->xPos) return WEST;
  if(target->yPos > base->yPos) return SOUTH;
  return NORTH;
}

void Cnake::moveNode(node* n) {
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

void Cnake::initNode(node* n, Direction d, int x, int y) {
  n->d = d;
  n->xPos = x;
  n->yPos = y;
}

