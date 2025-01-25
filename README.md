# Class Representative Voting System

## Overview
The **Class Representative Voting System** is a C-based program designed to streamline the election process for selecting a Class Representative (C.R.). It enables students to register and cast their votes, while administrators can manage candidate registrations and display results. This system promotes fairness, anonymity, and efficiency in elections.

---

## Features
- **Admin Panel:**
  - Register candidates with names and IDs.
  - Display voting results with the winning candidate or detect a tie.
  - Secure login with a predefined passkey.
  
- **Voter Panel:**
  - Register voters with a unique registration number, name, and branch.
  - Prevent duplicate voter registrations and multiple votes.
  - Cast votes for registered candidates or choose NOTA (None of The Above).
  
- **Key Functionalities:**
  - Anonymity in voting.
  - Real-time vote counting.
  - User-friendly menu-driven interface.

---

## Purpose
1. Empower students to elect representatives for their needs and concerns.
2. Encourage active engagement and democratic participation among students.
3. Facilitate effective communication between students and the class advisor through an elected representative.

---

## How It Works
1. **Home Page:**
   - Allows access to the Admin Panel, Voter Panel, or program exit (admin-only).
2. **Admin Panel:**
   - Register candidates.
   - Display voting results.
3. **Voter Panel:**
   - Register as a voter.
   - Cast a vote for a candidate.

---

## Implementation Details
- **Programming Language:** C
- **Libraries Used:**
  - `<stdio.h>`: Standard input-output operations.
  - `<stdlib.h>`: Memory allocation and process control.
  - `<string.h>`: String manipulation functions.
  - `<unistd.h>`: Used for delays via the `sleep()` function.

- **Data Structures:**
  - `struct Candidate`: Stores candidate ID, name, and votes.
  - `struct Voter`: Stores voter details (registration number, name, branch) and voting status.

---

## Algorithms
1. **Admin Login:** Validates the admin passkey using string comparison.
2. **Candidate Registration:** Registers candidates up to a predefined limit.
3. **Voter Registration:** Adds voter details and prevents duplicate registration.
4. **Vote Casting:** Allows registered voters to vote and prevents multiple votes.
5. **Result Display:** Determines the winning candidate or handles tie situations.

---

## Testing and Results
- Successfully handles error cases, such as:
  - Duplicate voter registration.
  - Duplicate voting attempts.
  - Invalid admin passkey.
- Displays results dynamically after voting is complete.

---

## Limitations and Future Improvements
### Limitations:
- Data is stored in memory and lost after program termination.

### Future Improvements:
- Implement persistent storage using files or a database to retain voter and candidate information after execution.

---

## Key Learnings
- Modular code structure for better readability and maintainability.
- Dynamic use of arrays of structures for managing data.
- Enhanced user experience with visual elements like screen clearing, color changes, and delay pauses.

---

## How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/class-representative-voting-system.git
