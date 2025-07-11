Banking Management System
Overview
The Banking Management System is a C++ console-based application designed to simulate basic banking operations. It allows users to manage bank accounts, perform transactions such as deposits, withdrawals, and transfers, and handle account creation and deletion. The system supports both admin and customer functionalities, with a user-friendly interface that includes ATM operations and account management features.
Features

Admin Features:
Create new customer accounts.
Delete existing accounts.
Search accounts by ID or CNIC.
Display all accounts.
Modify admin credentials (ID and PIN).


Customer/ATM Features:
Login to user accounts with ID and PIN.
Check account balance.
Deposit and withdraw money.
Transfer funds between accounts.
Modify account details (name, mobile number, PIN, email).
Generate deposit and withdrawal slips.


Data Management:
Stores account data persistently in a file (User.txt).
Tracks account IDs and counts using separate files (id.txt, count.txt).
Admin credentials stored in Admin.txt.


Input Validation:
Validates Pakistani mobile numbers and Gmail addresses using regex.
Ensures PINs and IDs are numeric and meet length requirements.
Removes numeric characters from names for data consistency.


User Interface:
Console-based UI with decorative borders and loading animations.
Sound effects for login, keypresses, and transaction confirmations (Windows-specific).



Technologies Used

Language: C++ (Standard C++ libraries)
Libraries:
<iostream>: For input/output operations.
<fstream>: For file handling.
<windows.h>: For Windows-specific features like sound and sleep.
<conio.h>: For keyboard input handling.
<string>: For string manipulation.
<ctime>: For date and time handling.
<regex>: For input validation (mobile numbers, emails).
<mmsystem.h>: For playing sound effects.


Data Structure: Doubly Linked List for storing and managing account data.

File Structure

User.txt: Stores customer account details (ID, PIN, name, mobile, CNIC, amount, date, email).
Admin.txt: Stores admin credentials (ID and PIN).
id.txt: Tracks the last assigned account ID for auto-increment.
count.txt: Maintains the count of account data entries in User.txt.

Installation and Setup

Prerequisites:
A C++ compiler (e.g., g++, MinGW for Windows).
Windows operating system (due to <windows.h> and <mmsystem.h> dependencies).
Sound files (WELCOME A.wav, ATM KEY.wav, LOGGED IN SUCCES.wav, TRANS B PROS.wav, THANK B.wav, THANK ATM.wav) in the project directory for audio feedback.


Steps:
Clone the repository:git clone https://github.com/yourusername/banking-management-system.git


Navigate to the project directory:cd banking-management-system


Compile the code:g++ main.cpp -o banking_system -lwinmm


Run the executable:./banking_system




Notes:
Ensure the sound files are present in the same directory as the executable for audio to work.
The program creates User.txt, Admin.txt, id.txt, and count.txt automatically if they don't exist.
Default admin credentials: ID: root, PIN: 1234.



Usage

Run the Program:
Launch the executable to start the system.
The program displays a group introduction and a loading animation.


Main Menu:
Choose between Bank Management (admin mode) or ATM (customer mode).
Press Esc to exit the program.


Admin Mode:
Log in with admin ID and PIN.
Access options to create/delete accounts, search accounts, display all accounts, or modify admin credentials.


ATM Mode:
Log in with a customer account ID and PIN.
Perform actions like checking balance, depositing, withdrawing, or transferring money.


Navigation:
Use numeric keys (e.g., 1, 2) to select options.
Press Backspace to go back or Esc to log out.



Limitations

Platform Dependency: The program relies on Windows-specific libraries (<windows.h>, <mmsystem.h>), making it incompatible with non-Windows systems without modifications.
Sound Dependency: Requires specific .wav files for audio feedback; missing files may cause errors.
File Handling: Assumes files are accessible and writable; errors may occur if files are locked or corrupted.
Security: PINs and IDs are stored in plain text in files, which is not secure for real-world applications.
Error Handling: Limited handling for invalid inputs in some cases (e.g., non-numeric input for amounts).

Future Improvements

Port to cross-platform compatibility (e.g., remove Windows-specific dependencies).
Enhance security by encrypting sensitive data (e.g., PINs).
Add a graphical user interface (GUI) using frameworks like Qt or SDL.
Improve error handling for file operations and user inputs.
Implement a database (e.g., SQLite) instead of text files for better data management.
Add support for multiple admin accounts and user roles.

Contributors

Abdul Rahman
Hafiz Ahmed Zahid

License
This project is licensed under the MIT License. See the LICENSE file for details.
