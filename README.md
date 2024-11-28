
  Library Management System

Report Submitted By:

•	MUHAMMAD SARMAD CHUGHTAI 
•	SINWAN HAIDER


Submitted To:

•	MR.ZEESHAN


Department:  Computer Science



Date: 29 – 11 – 2024


Course:   DATA STRUCTURE AND ALGORITHM



RIPHAH INTERNATIONAL UNIVERSITY ISLMABAD 

FINAL REPORT ON LIBRARY MANAGEMENT SYSTEM 

Introduction:
The Library Management System is a comprehensive application designed to facilitate the management of library services, including book management, member registration, borrowing and returning books, and displaying available books and registered members. This system aims to streamline the process of library management for both customers and administrators, ensuring a user-friendly experience. It incorporates a modular and interactive design using C++, leveraging concepts from Data Structures and Algorithms (DSA) to optimize functionality and ensure scalability.

Objectives:
1.	Customer Management: Allow customers (members) to register and store their details securely for future reference.
2.	Booking Management: Provide options for adding, searching, and displaying books in the library.
3.	Borrowing and returning book: Enable members to borrow and return books seamlessly.
4.	Receipt Generation: Automatically generate and store records of book transactions.

System Features:
1. User Authentication
•	The application prompts the user to enter their membership id to continue providing a simple authentication mechanism.
2. Customer Management
•	Customers can add their details, including name, membership id and mobile number.
•	Customer information is stored in a link list for future reference.
3. Book Management 
•	Users can add books with titles and authors to the library.
•	The cost is calculated based on the type of cab and the distance traveled.
4. Borrowing and returning book
•	Members can borrow books that are available and return them when done 
•	The system tracks the borrowed status of books
5. Receipt Generation 
•	After borrowing or returning books, the system generates a simple confirmation message for the transaction.

Data Structures and Algorithms Used:
Implementation Details:
1.	Binary Search Tree (BST) for Book Management
•	Where Used: For managing books in the library.
•	Why Used: BST allows efficient searching, adding, and displaying of books based on their titles.
2.	Linked List for Member Management:
•	Where Used: For managing member details.
•	Why Used: A linked list allows dynamic memory allocation and easy insertion of new members.
3.	Static Variables for Data Sharing:
•	Where Used: Shared variables like Member::member Count can be declared as static.
•	Why Used: Static variables allow the program to share data between multiple objects while ensuring a single instance persists throughout program execution.
4.	File Handling for Persistent Data Storage:
•	Where Used: Used for storing member details and transaction records.
•	Why Used: File operations ensure data persistence, allowing user information to be saved and retrieved even after the program terminates.

5.	Switch Case for Decision Making:
•	Where Used: Used extensively in menu navigation and option selection (e.g., borrowing, returning).
•	Why Used: It provides an efficient way to handle multiple conditional paths and makes the code modular and readable.
6.	Modular Design and Encapsulation:
•	Where Used: Classes like Book, Member, BookBST, and MemberList.
•	Why Used: Encapsulation ensures each module is self-contained, adhering to the Single Responsibility Principle in software design, making the code maintainable and scalable.

7.	Algorithmic Efficiency:
•	Where Used: Searching and managing books and members are optimized using direct comparisons and tree traversal.
•	Why Used: This ensures minimal computational overhead and optimal runtime efficiency.

Technologies Used
•	Programming Language: C++
•	File Handling: Used for storing member details and transaction records.
•	User Interface: Console-based interface for interaction with users.

Classes and Structure
•	Book: Represents a book in the library with attributes like title, author, and borrowing status.
•	Member: Represents a library member with attributes like name, membership ID, and mobile number.
•	BookBST: Manages the collection of books using a binary search tree structure.
•	MemberList: Manages the list of library members using a linked list structure.
•	Library: Integrates all functionalities for managing books and members.


Testing and Validation:
The system has been tested for various scenarios, including:
•	Adding new members and verifying data storage.
•	Adding books and checking the search functionality.
•	Borrowing books and validating the borrowing process.
•	Returning books and ensuring the status is updated correctly.

OUTPUT:
•	Main-Menu
 

Conclusion:
The Library Management System effectively addresses the needs of both members and administrators in the library environment. It provides a seamless experience for managing library services, ensuring that all necessary information is easily accessible and securely stored. This project demonstrates the application of data structures and algorithms in building a functional and user-friendly software solution. Future improvements could include a graphical user interface (GUI) and integration with online catalog systems for a more robust application.

GIT HUB LINK : 








