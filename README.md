# AVL Tree Implementation in C

## Overview
This repository contains a C implementation of an AVL Tree, a self-balancing binary search tree. Each node in the AVL tree has a balance factor that is maintained to ensure that the tree remains approximately balanced at all times, providing optimal search, insert, and delete operations in logarithmic time.

## Features
- **Insertion**: Safely insert elements while maintaining the tree balance.
- **Rotation**: Perform right, left, left-right, and right-left rotations to keep the tree balanced.
- **Traversal**: In-order traversal of the tree to display elements in a sorted order.

## Requirements
- A C compiler (like GCC or Clang)
- Basic knowledge of command line operations for compiling and running C programs

## Compilation and Execution
To compile and run this AVL Tree implementation, you can use the following commands on a Unix-based system:

```bash
gcc -o avlTree avlTree.c
./avlTree
