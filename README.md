# 🔗 Linked Lists Implementations in C++

This repository contains my solutions for the **Basic Data Structures I (EDB1)** assignment at UFRN (Universidade Federal do Rio Grande do Norte). The goal of this project is to implement and manipulate different types of Linked Lists in C++ with strict time and space complexity constraints (in-place operations).

## 🚀 Features & Algorithms Implemented

This project explores three core data structures: **Singly Linked Lists**, **Doubly Linked Lists**, and **Circular Linked Lists**. 

The following operations were implemented manually using raw pointers:

1. **In-Place Reversal (`inverte`)**: Reverses a singly linked list in $O(n)$ time and $O(1)$ space using the 3-pointers technique.
2. **Circular Rotation (`rotaciona`)**: Rotates a circular linked list to the right by $k$ positions in $O(k \pmod n)$ time.
3. **Priority Queue Enqueue (`enqueue_priority`)**: Inserts elements into a doubly linked list based on priority levels in $O(1)$ time, maintaining FIFO for elements with the same priority.
4. **Merge Sorted Lists (`merge`)**: Merges two already sorted singly linked lists into a single sorted list in $O(n+m)$ time and $O(1)$ space, using a dummy node approach.
5. **Cycle Detection (`tem_ciclo`)**: Implements **Floyd’s Cycle-Finding Algorithm** (Tortoise and Hare) to detect if a singly linked list contains a loop in $O(n)$ time and $O(1)$ space.

## 🛠️ Technologies & Concepts
* **Language:** C++
* **Concepts:** Dynamic Memory Allocation, Pointers Manipulation, Rule of Three, Time/Space Complexity (Big O Notation).

## 💡 How to Run
To compile and run this project, ensure you have a C++ compiler installed (like GCC):

```bash
g++ linked_lists_exercises.cpp -o lists
./lists
