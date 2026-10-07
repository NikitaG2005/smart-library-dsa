# Mini Project Report

---

## 1. Title of Mini Project
**Smart Library Management System Using Data Structures and Algorithms**

---

## 2. Problem Statement
Traditional manual library record-keeping systems suffer from inefficiencies such as linear search delays, redundant memory consumption when managing issue grids, fixed array capacity limitations, and lack of prioritized request queues. Standard database systems hide low-level execution mechanisms, making it difficult for students to analyze algorithmic complexities.

**Real-World Context:**
In an academic library setting, thousands of books and student members must be managed efficiently. Dynamically growing book catalogs require pointer-based dynamic memory allocation (Linked Lists), return histories require Last-In-First-Out processing (Stack), reserved requests require priority and circular queue structures (Queue), and member-book allocation grids contain mostly zeros, requiring storage compression (Sparse Matrix).

**Inputs:**
- Book Details: Book ID, Title, Author, Category, Total Copies.
- Member Details: Member ID, Name, Department, Contact, Role (Student/Faculty).
- Transaction Requests: Issue requests, Return requests, Search queries, Sorting keys.

**Outputs:**
- Dynamic Book Catalog & Member Directory.
- Real-time Issue/Return logs and fine calculations.
- Visual Node inspection for Singly Linked List, Doubly Linked List, Stack, and Queue.
- Comparative algorithm performance metrics (Comparisons, Swaps, Execution time in ms).

**Significance:**
This project bridges the gap between theoretical Data Structures & Algorithms (DSA) concepts taught in the syllabus and practical software application, providing empirical proof of time and space complexity.

---

## 3. Objectives
1. **Implement Dynamic Memory Management:** Use Singly Linked List (SLL) for books and Doubly Linked List (DLL) for members to support dynamic insert/delete operations without pre-allocation overhead.
2. **Demonstrate Linear & Priority Buffer Operations:** Utilize Stack (LIFO) for returned books and Queue ADTs (Linear, Circular, Priority, Deque) for student/faculty waiting queues.
3. **Optimize Memory for Sparse Datasets:** Implement 3-Tuple Sparse Matrix representation to store large issue matrices efficiently.
4. **Implement & Compare Search Algorithms:** Provide custom implementations of Linear Search, Sentinel Search, Binary Search, Indexed Sequential Search, and Fibonacci Search.
5. **Implement & Compare Sort Algorithms:** Provide custom implementations of Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, and Shell Sort.

---

## 4. Background / Concept
Data structures provide organized formats for storing and managing data efficiently. Key concepts used in this project include:

- **Abstract Data Type (ADT):** Defines data behavior independent of implementation (e.g., Stack ADT, Queue ADT).
- **Linear Data Structures:** Elements arranged sequentially in memory (Arrays, Linked Lists, Stacks, Queues).
- **Linked Lists:** Pointer-based dynamic structures where each node contains data and references (`next`, `prev`) to adjacent nodes.
- **LIFO (Last-In-First-Out):** Operating principle of Stack where the most recently added element is processed first.
- **FIFO (First-In-First-Out):** Operating principle of Queue where elements are processed in order of arrival.
- **Sparse Matrix (3-Tuple):** Matrix where majority elements are zero. Represented as `(Row, Column, Value)` to minimize space complexity from $O(m \times n)$ to $O(k)$ non-zero entries.
- **Searching & Sorting Paradigms:** Algorithmic techniques including Sequential Search, Divide and Conquer (Binary Search, Quick Sort), and Diminishing Increments (Shell Sort).

---

## 5. Real-World Application
In a real-world library system:
- **Book Cataloging:** Singly Linked List allows continuous addition of new books without needing contiguous memory allocation or array resizing.
- **Member Directory:** Doubly Linked List enables forward and backward navigation through student and faculty directories.
- **Book Return Desk:** Stack acts as a temporary stack of returned books waiting to be re-shelved.
- **Reservation Desk:** Priority Queue prioritizes Faculty members over Students, while Circular Queue efficiently manages waiting slots without memory wastage.
- **Issue Tracking Grid:** Sparse Matrix compresses large Member $\times$ Book borrowing matrix, saving up to 80% memory space.

---

## 6. Data Structures Selection and Justification

| Data Structure / Algorithm | Proposed Approach & Processing Steps | Justification for Selection |
| :--- | :--- | :--- |
| **Singly Linked List (SLL)** | Nodes created dynamically; insertion at end, deletion by Key (`Book ID`), traversal. | Avoids array size limits; insertion/deletion does not require element shifting ($O(1)$ at head). |
| **Doubly Linked List (DLL)** | Nodes contain `prev` & `next` pointers. Bidirectional traversal for member directory. | Allows $O(1)$ deletion when node reference is known and easy backward navigation. |
| **Stack (LIFO)** | Array-based push, pop, peek operations for recently returned books history. | Perfect for tracking most recent operations and implementing undo features. |
| **Queue (FIFO / Priority / Deque)** | Linear, Circular Queue with `(rear+1)%capacity`, Priority Queue, and Deque. | Manages waiting reservations smoothly; Priority Queue enforces faculty preference. |
| **Sparse Matrix (3-Tuple)** | Converts 2D issue grid into 3-column array `[Row, Col, Value]`. | Reduces space complexity from $O(m \times n)$ to $O(k)$ for sparse borrowing tables. |
| **Binary Search** | Validates sorted state, computes `mid = floor((low+high)/2)`, recursively narrows range. | Achieves logarithmic time complexity $O(\log n)$ for fast book lookups. |
| **Quick Sort** | Selects pivot element, partitions array into smaller/larger sub-arrays, recurses. | Highly efficient in-place sorting algorithm with average time complexity $O(n \log n)$. |

---

## 7. Algorithm / Pseudocode / Code

### Pseudocode 1: Singly Linked List Insertion (`insertAtEnd`)
```text
Algorithm InsertAtEnd(head, newData):
1. Create newNode with newNode.data = newData, newNode.next = NULL
2. IF head == NULL THEN
3.     SET head = newNode
4. ELSE
5.     SET current = head
6.     WHILE current.next != NULL DO
7.         current = current.next
8.     END WHILE
9.     current.next = newNode
10. END IF
11. RETURN head
```

### Pseudocode 2: Binary Search (`binarySearch`)
```text
Algorithm BinarySearch(arr, targetKey):
1. SET low = 0, high = arr.length - 1
2. WHILE low <= high DO
3.     SET mid = floor((low + high) / 2)
4.     IF arr[mid].id == targetKey THEN
5.         RETURN mid // Found
6.     ELSE IF arr[mid].id < targetKey THEN
7.         low = mid + 1
8.     ELSE
9.         high = mid - 1
10.    END IF
11. END WHILE
12. RETURN -1 // Not Found
```

### Pseudocode 3: Quick Sort (`quickSort`)
```text
Algorithm QuickSort(arr, low, high):
1. IF low < high THEN
2.     SET pivotIndex = Partition(arr, low, high)
3.     QuickSort(arr, low, pivotIndex - 1)
4.     QuickSort(arr, pivotIndex + 1, high)
5. END IF
```

---

## 8. Implementation & Functionality
The system is implemented as a responsive web application using clean HTML5, CSS3, and modern vanilla JavaScript:

1. **Dashboard Module:** Displays real-time counts for Total Books, Available Copies, Issued Books, Registered Members, and Pending Requests.
2. **Book Management Module:** Allows adding, updating, searching, sorting, and deleting books stored inside the Singly Linked List.
3. **Member Management Module:** Supports registration and management of library members in a Doubly Linked List.
4. **Issue & Return Module:** Processes book issuance and return transactions, updating availability counts dynamically.
5. **DSA Visualizer Modules:** Provides interactive visual representations of SLL nodes, DLL nodes, Stack containers, and Queue structures.
6. **Algorithms Workbench:** Executes 5 searching algorithms and 5 sorting algorithms with comparison tracking and step-by-step logs.

---

## 9. Data Structure Operations
- **Singly Linked List:**
  - `insertAtStart(data)` / `insertAtEnd(data)`
  - `deleteByKey(key, prop)`
  - `search(key, prop)`
  - `traverse()`
- **Doubly Linked List:**
  - `insertTail(data)`
  - `deleteNode(node)`
  - `traverseForward()` / `traverseBackward()`
- **Stack:**
  - `push(element)`
  - `pop()`
  - `peek()`
- **Queue & Variants:**
  - `enqueue(element)` / `dequeue()`
  - `enqueueCircular(element)` / `dequeueCircular()`
  - Priority scheduling based on `priorityScore`
- **Sparse Matrix:**
  - `insert(row, col, value)`
  - `getTupleRepresentation()`

---

## 10. Complexity Analysis

Discuss best, average, and worst-case time complexity wherever applicable, and space complexity.

| Parameter | Analysis / Justification |
| :--- | :--- |
| **Best Case Time Complexity** | **Searching:** $O(1)$ for Linear/Sentinel Search when target is at first position; $O(1)$ for Binary Search when target is at exact `mid`. <br>**Sorting:** $O(n)$ for Bubble Sort and Insertion Sort when array is already sorted. |
| **Average Case Time Complexity** | **Searching:** $O(n)$ for Linear/Sentinel Search; $O(\log n)$ for Binary Search & Fibonacci Search; $O(\sqrt{n})$ for Indexed Sequential Search. <br>**Sorting:** $O(n \log n)$ for Quick Sort & Shell Sort; $O(n^2)$ for Bubble, Selection, and Insertion Sort. |
| **Worst Case Time Complexity** | **Searching:** $O(n)$ for Linear/Sentinel Search when target is at end or absent. <br>**Sorting:** $O(n^2)$ for Bubble Sort, Selection Sort, Insertion Sort, and Quick Sort (when worst pivot is chosen). |
| **Space Complexity** | **Linked Lists & Arrays:** $O(n)$ linear auxiliary space. <br>**Sparse Matrix:** $O(k)$ where $k$ is the number of non-zero elements (saving memory over $O(m \times n)$ dense matrix). <br>**Stack & Queue:** $O(N)$ allocated memory buffer. |

---

## 11. Conclusion
The **Smart Library Management System** successfully demonstrates the core Data Structures and Algorithms prescribed in the Computer Engineering syllabus. 

**Key Learning Outcomes:**
1. Dynamic memory allocation via Singly and Doubly Linked Lists eliminates fixed array buffer limitations.
2. Abstract Data Types (Stack, Queue ADTs) efficiently streamline transaction logging and request scheduling.
3. Sparse Matrix representation drastically reduces memory footprint for mostly empty 2D grids.
4. Comparative analysis proves that Binary Search ($O(\log n)$) and Quick Sort ($O(n \log n)$) offer superior scalability for large datasets compared to simple linear algorithms ($O(n)$ and $O(n^2)$).

---
