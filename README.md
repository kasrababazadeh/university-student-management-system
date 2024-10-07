# Student Management System

A simple console-based application written in C++ for managing student records, including grades and averages for various subjects. This application allows administrators to log in, add students, search for students, calculate averages, and analyze student performance.

## Features

- **User Authentication**: Secure login for administrators.
- **Student Management**: Add and manage student records, including personal details and subject marks.
- **Grade Calculations**: Automatically calculates average grades based on weighted marks.
- **Statistical Analysis**: Provides functionalities to analyze student performance, including flunk counts and maximum/minimum marks.
- **Subject Averages**: Calculates and displays average marks for each subject.
- **Dynamic User Interface**: Simple console-based navigation to access different features.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., g++, clang++)
- Basic understanding of C++ programming

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/kasrababazadeh/student-management-system.git

2. Navigate to the project directory:

   ```bash
   cd student-management-system

3. Compile the application:

   ```bash
   g++ -o student_manager student_manager.cpp

4. Run the application:

   ```bash
   ./student_manager


## Usage

1. **Login as Admin**: Use the credentials:
   - **Username**: `admin`
   - **Password**: `5648`
  
2. **Add Students**: Choose the option to add student records and input their details.

3. **Analyze Grades**: Use the menu to calculate averages, view maximum/minimum scores, and identify flunking students.

4. **Logout**: Exit the admin interface and return to the main login menu.

## Code Structure

- **`student_manager.cpp`**: Contains the main application logic, including classes for students and student management.

## Code Quality

The code is well-structured and modular, with comments provided for clarity. It employs basic input validation and follows good programming practices.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any feature requests or bug reports.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
