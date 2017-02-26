#ifndef CNAKE_H
#define CNAKE_H

#include <stdio.h>
#include <stdlib.h>

enum Direction {NORTH, SOUTH, EAST, WEST};

typedef struct Node node;

struct Node {
  struct Node* child;
  Direction d;
  int xPos;
  int yPos;
};

class Cnake {
  private:
    Direction locateNode(node* base, node* target);
    void initNode(node*, Direction, int, int);
    void grow();
    void moveNode(node*);
  public:
    Cnake();
    ~Cnake();
    void updateNodes();
    void updateNodes(node*);
    node* head;
    node* tail;
};

#endif
