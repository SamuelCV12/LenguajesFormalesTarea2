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

---
## References
1. **Pdf:** 
   - Explanation of the homework(https://drive.google.com/file/d/1P2XtygCCF8CkqCuAXUK-2dTonKUYhyZH/view?usp=sharing)
2. **Book**
   - Aho, Alfred V. et al. (2006). Compilers: Principles, Techniques, and Tools (2nd Edition). 
3. **AI Tools:**
   - ChatGPT for code organization and explanation of the algorithms to eliminate left-recursion .


