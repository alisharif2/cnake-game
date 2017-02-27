#ifndef CNAKE_H
#define CNAKE_H

#include <stdio.h>
#include <stdlib.h>

enum Direction {NORTH = 1, SOUTH = -1, EAST = 2, WEST = -2};

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
    Node* tail;
  public:
    Cnake();
    ~Cnake();
    void updateNodes();
    void updateNodes(Node*);
    void grow();
    void turn(Direction d);
    Node* head;
};

#endif
