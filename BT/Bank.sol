

// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank{
    address public owner;
    uint256 private  balance;

    constructor(){
        owner = msg.sender;
    }
    



    function deposit() public payable {
        require(msg.value>0, "Amount should be greater than 0");
        balance += msg.value;
    }

    function withdraw(uint amount) public payable {
        require(amount>0, "Amount should be greater than 0");
        require(amount <= balance, "Insufficient balance");
        balance -= amount;
    }

    function showBalance() public view returns(uint){
        return balance;
    }


}