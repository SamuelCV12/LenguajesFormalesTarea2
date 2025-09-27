# Algorithm to Eliminate Left-recursion

## Samuel Correa Velasquez — Class # 5730  
## Thomas Bedoya Rendon — Class # 5730

---

## Environment and Tools Used

- **Operating System:** Windows 11  
- **C++ Compiler:** g++ (MinGW.org GCC-6.3.0-1) 6.3.0  
- **Programming Language:** C++17  

---

## How to Run the Program

### 1. Open a Terminal

- **Windows (CMD):**  
  1. Press `Windows + R`  
  2. Type `cmd` and press **Enter**

- **Linux:**  
  - Press `Ctrl + Alt + T`

- **macOS:**  
  1. Press `Command + Space`  
  2. Type `terminal` and press **Enter**

---

### 2. Verify if g++ is Installed

Run in terminal (works on Windows, Linux, macOS):  
```bash
g++ --version
```

### 3. Go to the Project Folder

- **Windows example:**  
```cmd
cd C:\Users\samue\OneDrive\Escritorio\LenguajesFormales
```
- **Linux/macOS example:**  
```bash
cd /home/samue/Escritorio/LenguajesFormales
```
### 4. Compile the Program

```bash
g++ -std=c++17 eliminacion.cpp -o eliminacion
```
---

### 5. Run the Program

- **Windows:**  
```cmd
eliminacion.exe < entrada.txt
```

### 6. Expected Output Example

If you use the input file entrada.txt (the one provided in the assignment), the output will look like this:
```
S -> bZ
Z -> aZ e

S -> Aa b
A -> bdZ mZ
Z -> cZ adZ e

S -> AbZ
A -> cY
Z -> aZ e
Y -> cY bZcY e
```
---
### 7. Algorithm to Eliminate Left-recursion Explanation

This project implements an algorithm to eliminate left recursion from a context-free grammar (CFG).

Left recursion is a situation where a non-terminal symbol in a grammar can derive itself as the first symbol on the right-hand side, which makes some parsing algorithms (like recursive descent) enter infinite loops.

Example:

A → Aα | β


is left-recursive because A immediately calls itself.

This program transforms such grammars into an equivalent form without left recursion.

How the Code Works
1. Grammar Representation (struct Grammar)

prod: a mapping from a non-terminal (like A) to its list of productions (A → α1 | α2 | ...).

order: keeps track of the order in which non-terminals are processed.

used: keeps track of which non-terminals are already in use (to avoid duplicates when creating new symbols).

2. Choosing a New Non-Terminal
char nextNonTerminal(set<char>& usados)


Finds an unused uppercase letter (Z → A) to create a fresh non-terminal when we need to rewrite a rule.

Throws an error if no letters are left.

3. Eliminating Immediate Left Recursion
void eliminateImmediateLeftRecursion(char A, Grammar& G)


Splits the productions of a non-terminal A into:

α (alpha): productions where A appears immediately (e.g., A → Aα).

β (beta): productions that do not start with A.

If left recursion exists, it rewrites as:

A → βA'
A' → αA' | ε


where A' is a new non-terminal and ε is the empty string (e in this code).

4. Eliminating General Left Recursion
void eliminateLeftRecursion(Grammar& G)


Iterates through all non-terminals in the given order.

For each pair (Ai, Aj) with j < i, it substitutes indirect recursion (when Ai → Ajγ).

After substitution, it calls eliminateImmediateLeftRecursion to clean up any direct recursion.

This ensures the grammar is fully free of left recursion.

5. Main Function

Reads n test cases.

For each case:

Reads grammar rules (lhs → rhs1 rhs2 ...).

Calls eliminateLeftRecursion.

Prints the transformed grammar.

---
## References
1. **Pdf:** 
   - Explanation of the homework(https://drive.google.com/file/d/1P2XtygCCF8CkqCuAXUK-2dTonKUYhyZH/view?usp=sharing)
2. **Book**
   - Aho, Alfred V. et al. (2006). Compilers: Principles, Techniques, and Tools (2nd Edition). 
3. **AI Tools:**
   - ChatGPT for code organization and explanation of the algorithms to eliminate left-recursion .


