# Chord Algorithm for Peer-to-Peer (P2P) Networks

This README provides a comprehensive explanation of the C++ code that implements the Chord algorithm for creating a peer-to-peer (P2P) network. The code consists of two files: `Chord.h`, which defines the `Node` and `FingerTable` classes, and `main.cpp`, which demonstrates the Chord algorithm in action.

## Table of Contents

1. [Introduction](#introduction)
2. [Code Overview](#code-overview)
   - [Chord.h - Class Definitions](#chordh---class-definitions)
   - [main.cpp - Chord Algorithm Example](#maincpp---chord-algorithm-example)
3. [Chord Algorithm Details](#chord-algorithm-details)
   - [Node Join Operation](#node-join-operation)
   - [Creating Finger Tables](#creating-finger-tables)
   - [Stabilizing Finger Tables](#stabilizing-finger-tables)
   - [Finding Successors](#finding-successors)
   - [Searching for Key-Value Pairs](#searching-for-key-value-pairs)
   - [Inserting Keys](#inserting-keys)
4. [Usage](#usage)
5. [Conclusion](#conclusion)

## Introduction

The Chord algorithm is a decentralized protocol used in P2P networks for efficiently locating resources or data in a distributed system. It forms a scalable and robust foundation for building decentralized applications. This README explains how the Chord algorithm works and provides a detailed walkthrough of the provided code.

## Code Overview

### Chord.h - Class Definitions

1. **Node Class**:

   - Represents a node in the Chord network.
   - Attributes:
     - `id`: A unique identifier for the node.
     - `predecessor`: A pointer to the predecessor node in the Chord ring.
     - `local_keys`: A map to store key-value pairs locally.
     - `fingertable`: A pointer to the node's finger table, which stores references to other nodes.
   - Methods:
     - `moveKeys(Node *succ, int new_node_id)`: Moves keys from the successor node to the newly added node during a join operation.
     - `join(Node *node)`: Allows a node to join the Chord network.
     - `createFingerTable()`: Creates the node's finger table.
     - `stabilize()`: Stabilizes the finger tables of all nodes in the network.
     - `find_successor(int id)`: Finds the successor node for a given identifier.
     - `find_key(int key)`: Searches for a key in the network.
     - `insert_key(int key, int value)`: Inserts a key-value pair into the network.
     - `insert_key_local(int key, int value)`: Inserts a key-value pair into the local storage of a node.
     - `local_key_lookup(int key)`: Searches for a key in the local storage of a node.

2. **FingerTable Class**:
   - Represents the finger table of a Chord node.
   - Attributes:
     - `fingerTable`: A vector of pointers to other nodes, representing the finger table entries.
     - `local_node`: A pointer to the node to which this finger table belongs.
     - `nodeId`: The identifier of the node to which this finger table belongs.
   - Methods:
     - `printFingerTable(int pred)`: Prints the finger table and local keys of the associated node.

### main.cpp - Chord Algorithm Example

The `main()` function in this file demonstrates the Chord algorithm's functionality through a series of steps, including node creation, joining nodes in the network, inserting keys, stabilizing the network, and searching for keys.

## Chord Algorithm Details

### Node Join Operation

The `join(Node *node)` method allows a node to join the Chord network. During this operation, finger tables are updated, predecessors and successors are determined, and keys are transferred if necessary.

### Creating Finger Tables

The `createFingerTable()` method populates a node's finger table based on its successors. It iteratively updates each finger table entry to point to the appropriate node, ensuring efficient key lookups.

### Stabilizing Finger Tables

The `stabilize()` method is used to stabilize the finger tables of all nodes in the network. It ensures that finger tables are kept up-to-date with the network's topology.

### Finding Successors

The `find_successor(int id)` method finds the successor node for a given identifier using the Chord algorithm's lookup mechanism.

### Searching for Key-Value Pairs

The `find_key(int key)` method searches for a key-value pair in the Chord network. It starts by searching locally on the node and then iterates through the finger table if needed to locate the key-value pair.

### Inserting Keys

The `insert_key(int key, int value)` method inserts a key-value pair into the Chord network. It determines the appropriate node for insertion based on the Chord algorithm's principles and inserts the key-value pair either locally or on the successor node.

## Usage

To use this Chord algorithm implementation and example:

1. Compile the code with both `Chord.h` and `main.cpp` files included.

```bash
g++ -o chord Chord.h Chord.cpp
```

2. Run the compiled executable.

```bash
./chord
```

3. Follow the on-screen prompts to specify the number of nodes, their values, the number of keys, and the keys to search for.
4. Observe the output, including finger table displays and key search results. Also the finger table is printed in a separate file named as FingerTable.txt

## Sample Input

```javascript
Enter the value of m where 2^m-1 is max value for a node or key and note all values should be unique: 8
Enter the number of nodes you want to insert in the network: 3
Enter node value : 13
Enter node value : 44
Enter node value : 18
Enter the number of keys to insert : 13
Enter key value : 3
Enter key value : 4
Enter key value : 9
Enter key value : 14
Enter key value : 15
Enter key value : 29
Enter key value : 50
Enter key value : 16
Enter key value : 18
Enter key value : 44
Enter key value : 35
Enter key value : 38
Enter key value : 41
Enter number of keys to be searched : 6
Enter key value to be searched : 50
Enter key value to be searched : 4
Enter key value to be searched : 29
Enter key value to be searched : 14
Enter key value to be searched : 3
Enter key value to be searched : 18
```

## Sample Output

```javascript

**** Pred ID : 44 ****
**** Node ID : 13 ****
FingerTable
1 : 18
2 : 44

Keys : 3  4  9  50
**********************



**** Pred ID : 18 ****
**** Node ID : 44 ****
FingerTable
1 : 13
2 : 18

Keys : 29  35  38  41  44
**********************



**** Pred ID : 13 ****
**** Node ID : 18 ****
FingerTable
1 : 44
2 : 13

Keys : 14  15  16  18
**********************


Enter number of keys to be searched : 6
Enter key value to be searched : 50

 Searching Key 50 on node 13
 Node 13 searched
 Found value - 50 on Node - 13
Enter key value to be searched : 4

 Searching Key 4 on node 13
 Node 13 searched
 Found value - 4 on Node - 13
Enter key value to be searched : 29

 Searching Key 29 on node 13
 Node 13 searched
 Node 18 searched
 Node 44 searched
 Found value - 29 on Node - 44
Enter key value to be searched : 14

 Searching Key 14 on node 13
 Node 13 searched
 Node 18 searched
 Found value - 14 on Node - 18
Enter key value to be searched : 5

 Searching Key 5 on node 13
 Node 13 searched
 Node 18 searched
 Node 44 searched
 Found value - 0 on Node - 44
Enter key value to be searched : 99

 Searching Key 99 on node 13
 Node 13 searched
 Node 18 searched
 Node 44 searched
 Node 13 searched
 Node 13 searched
 Node 13 searched
 Node 13 searched
 Node 13 searched
 Node 13 searched
 Not Found
```

## Conclusion

This code demonstrates the Chord algorithm for creating a P2P network, inserting keys, and performing key-value lookups. Understanding this example can serve as a foundation for building more complex distributed systems that rely on Chord-based decentralized key-value storage and retrieval in P2P networks.
