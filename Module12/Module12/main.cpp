//
//  main.cpp
//  Module12
//
//  Created by Daniel Bacon on 11/19/19.
//  Copyright © 2019 Daniel Bacon. All rights reserved.
//

#include <iostream>
#include "BinaryNode.h"
#include "BinaryNodeTree.h"


using namespace std;

void visit(int& temp)
{
    cout << temp << endl;
}

int main()
{
    cout << "hello world." << endl;
    BinaryNode<int>* testNode = nullptr;
    testNode = new BinaryNode<int>(5);
    cout << testNode->getItem() << endl;
    
    BinaryNodeTree<int>* testTree = nullptr;
    testTree = new BinaryNodeTree<int>();
    testTree->add(5);
    testTree->add(7);
    testTree->add(9);
    testTree->add(11);
    testTree->inorderTraverse(visit);
}
