// SPDX-License-Identifier: MIT
pragma solidity ^0.8.18;

contract StudentData {
    struct Student {
        uint id;
        string name;
        uint age;
    }

    Student[] public students;
    event StudentAdded(uint id, string name, uint age);

    // Function to add a new student
    function addStudent(uint id, string calldata name, uint age) external {
        students.push(Student(id, name, age));
        emit StudentAdded(id, name, age);
    }

    // Function to get student details by index
    function getStudent(uint index) external view returns (uint, string memory, uint) {
        require(index < students.length, "Student not found");
        Student storage student = students[index];
        return (student.id, student.name, student.age);
    }

    // Fallback function to handle unexpected calls
    fallback() external {
        revert("Invalid function call");
    }
}
