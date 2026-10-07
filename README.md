# Smart Library Management System Using Data Structures and Algorithms

**Computer Engineering Academic Mini Project (DSA Syllabus)**

---

## 📖 Overview

The **Smart Library Management System** is a college academic mini project developed for Computer Engineering students. The project demonstrates core Data Structures (Linked Lists, Stacks, Queues, Sparse Matrices) and Algorithms (5 Searching techniques, 5 Sorting techniques, Divide & Conquer, Greedy Strategy, Dynamic Programming) through a simple library management system.

---

## 🛠️ Data Structures Implemented

1. **Singly Linked List (SLL)**: Dynamic storage of Book records (`[Data | Next] ->`).
2. **Doubly Linked List (DLL)**: Bi-directional storage of Member records (`<- [Prev | Data | Next] ->`).
3. **Stack (LIFO)**: Stores Recently Returned Books log & Undo operations.
4. **Linear Queue (FIFO)**: Member Waiting List for popular books.
5. **Circular Queue**: Fixed capacity queue wrapping front & rear pointers using `(rear + 1) % capacity`.
6. **Priority Queue**: Schedules waiting requests based on Member Role (Faculty > Student).
7. **Deque (Double Ended Queue)**: Allows insertion and deletion at both Front and Rear ends.
8. **Sparse Matrix (3-Tuple)**: Stores Member $\times$ Book borrow status matrix as `(Row, Column, Value)` triplets.

---

## 🔍 Searching & ⚡ Sorting Algorithms

### Searching Algorithms
- **Linear / Sequential Search**: $O(n)$
- **Sentinel Search**: $O(n)$ (Optimized loop boundary condition)
- **Binary Search**: $O(\log n)$ (Validates that array is sorted before searching)
- **Indexed Sequential Search**: $O(\sqrt{n})$
- **Fibonacci Search**: $O(\log n)$ (Interval splitting without division)

### Sorting Algorithms
- **Bubble Sort**: $O(n^2)$
- **Selection Sort**: $O(n^2)$
- **Insertion Sort**: $O(n^2)$
- **Quick Sort**: $O(n \log n)$ (Divide & Conquer Partitioning)
- **Shell Sort**: $O(n^{1.5})$ (Diminishing Increments)

---

## 🚀 How to Run the Project

1. Open `index.html` directly in any web browser (Google Chrome, Microsoft Edge, Firefox).
2. No database or external server installation is required. Everything runs in standard ES6 JavaScript.

---

## 📁 Folder Structure

```
eh1/
├── index.html              # Main UI Dashboard, Visualizers, Workbenches & Tab Views
├── css/
│   └── style.css           # Responsive modern CSS layout & visual node containers
├── js/
│   ├── ds.js               # Custom Data Structures (SLL, DLL, Stack, Queue, SparseMatrix)
│   ├── algorithms.js       # Searching, Sorting & Algorithmic Paradigms
│   ├── sampleData.js       # Pre-populated datasets
│   └── app.js              # Controller logic & DOM handlers
├── README.md               # Quick setup guide
└── PROJECT_REPORT.md       # Academic Project Documentation & Viva Voce Q&A
```
