# **C-Trie – Prefix Tree Library in C**

## **Project Overview**

C-Trie is a lightweight, efficient **Trie (prefix tree) library in C** designed to store and retrieve strings based on their prefixes. This data structure enables fast operations like **insertion, deletion, searching**, and **autocomplete**, making it ideal for **autocomplete engines, spell checkers, and dictionary-based applications**.

This project includes:

* A reusable **Trie library (`trie.h` / `trie.c`)**
* An **interactive demo program** (`main.c`)
* **Unit tests** (`test_trie.c`)
* Optional **dictionary loading** from `dictionary.txt`
* **Trie visualization** for better understanding

---

## **Project Structure**

```
C-trie/
│ include/
│   └── trie.h          # Trie library header
│ src/
│   └── trie.c          # Trie implementation
│ demo/
│   └── main.c          # Interactive demo program
│ tests/
│   └── test_trie.c     # Unit tests
│ build/
│   └── Makefile        # Build script
│ dictionary.txt        # Optional dictionary file
```

---

## **Features**

* **Insert words** – add new strings to the trie.
* **Delete words** – remove words safely; supports root deletion.
* **Search** – check if a word exists.
* **Prefix search** – check if any word starts with a given prefix.
* **Autocomplete** – list all words with a given prefix.
* **Trie visualization** – display the structure of the trie in the terminal.
* **Dictionary loading** – read words from `dictionary.txt` for batch insertion.
* **Memory management** – all dynamically allocated nodes are freed safely.
* **Unit tests** – verify core trie functionality and deletion scenarios.

---

## **Getting Started**

### **1. Build the project**

```bash
cd C-trie/build
make
```

This will:

* Compile the demo program → `c_trie_demo`
* Compile and run unit tests → `test_trie`

---

### **2. Run the demo program**

```bash
./c_trie_demo
```

You will see:

```
--- C-TRIE DEMO ---
1. Insert word
2. Search
3. Autocomplete
4. Visualize Trie
5. Delete word
6. Exit
Select:
```

* Insert words manually or autocomplete using inserted words.
* Visualize the trie structure.
* Delete words safely; root deletion is handled.

---

### **3. Run unit tests**

```bash
./test_trie
```

Expected output:

```
All tests passed!
```

---

### **4. Clean build files**

```bash
make clean
```

Deletes compiled binaries:

* `c_trie_demo`
* `test_trie`

---

## **Optional Dictionary**

* Place a file named `dictionary.txt` in the project root.
* Each line should contain a single word (lowercase ASCII).
* The program will load the dictionary automatically at startup.

Example `dictionary.txt`:

```
apple
application
apt
cat
dog
banana
```

---

## **Implementation Notes**

* Supports **lowercase ASCII letters (`a`–`z`)**.
* Trie is **memory-safe**; all nodes are freed on exit.
* `deletekey()` safely handles **root deletion** if the trie becomes empty.
* Autocomplete uses **DFS traversal** for efficient prefix lookup.
* Visualization displays branches and marks words clearly in the terminal.

---

## **Learning Outcomes**

* Understanding of **tree-like structures for strings**.
* Implementing **prefix matching** efficiently.
* Managing **dynamic memory allocation** in C.
* Creating **interactive console applications**.
* Applying **unit testing** to validate core data structures.

---

## **Build Requirements**

* GCC (or compatible C compiler)
* Unix/Linux environment (tested on Ubuntu)
* Optional: `dictionary.txt` for demo

---

## **Author**

**Anna Astvatsatryan, Tigran Gayranyan, Hrayr Hovsepyan**
Faculty of Computer Science and Applied Mathematics
Academic Year 2025–2026, Project S1

---
