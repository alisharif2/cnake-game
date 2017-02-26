#ifndef CNAKE_H
#define CNAKE_H

#include <stdio.h>
#include <stdlib.h>

enum Direction {NORTH, SOUTH, EAST, WEST};

class Node {
  public:
    Node(Direction d, int xPos, int yPos);
    ~Node();
    Direction d;
    Node* child;
    int xPos;
    int yPos;
};

class Cnake {
  private:
    Direction locateNode(Node* base, Node* target);
    void moveNode(Node*);
    Node* head;
    Node* tail;
  public:
    Cnake();
    ~Cnake();
    void updateNodes();
    void updateNodes(Node*);
    void grow();
};

#endif
