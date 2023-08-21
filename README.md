# VSD_ASIC_DESIGN

This Repository Guides you the process of complete ASIC flow, we begin our journey with simulating basic C code and go all the way to putting together an SoC ready to be fabbed out.  
*(FACULTY : Mahesh Awati, GUIDE : Kunal Ghosh)*

> The course files are present under those respective Lab directories, make sure to download all the dependencies before proceeding with the lab 

# Introduction
### Flow : HLL -> ALP -> Binary -> (HDL) -> GDS
#### 1. HLL -> High level language (c , c++) 
- A high-level programming language is a type of programming language that is designed to be more human-readable and user-friendly compared to low-level languages like assembly or machine code.

#### 2. ALP -> Assembly level program
- Assembly language is a low-level programming language that is closely related to the architecture of a specific computer's central processing unit (CPU). Assembly language programs are written using mnemonic codes that represent specific machine instructions which the machine can understand.

#### 3. HDL -> Hardware Description Language
- It is a specialized programming language used for designing and describing digital hardware circuits. HDLs allow engineers to model and simulate complex digital systems before physical implementation, aiding in the design and verification of integrated circuits and FPGA configurations.
- Verilog, System Verilog, VHDL

#### 4. GDS -> Graphic Data System (layout)
- Format used in the semiconductor industry to represent the layout and design of integrated circuits at a highly detailed level. GDSII files contain information about the geometric shapes, layers, masks, and other essential details that make up the physical layout of a chip.
- Tools : Klayout, Magic

##### The Hardware needs to understand what the Application software is saying it to do.This relation can be eshtablished by System Software

____System Software____
- OS : Operating System : Handles IO, memory allocation, Low level system function
- Compiler : Convert the input to hardware dependent instruction
- Assembler : Convert the instructions provided by compiler to Binary format
- HDL : A program that understands the Binary pattern and map it to a netlist
- GDS : Layout

# COURSE 
 ## LAB 1
 [LAB 1: Introduction to RISCV ISA and GNU Compiler Toolchain](https://github.com/JoyenBenitto/VSD_ASIC_Design/tree/main/lab1#readme)<br>
Dependencies

    Follow the instruction in the README to install the relevant tools:
        RISC-V GNU Compiler Toolchain
        RISC-V Proxy Kernel
        RISC-V Spike

C Code

    Open your terminal and run the following command to create a .c file.

vim lab1/sum1ton.c 

we are writing a C program that finds the sum of number from 1 to n . We are going to use SPIKE simulator to simulate the code.

#include<stdio.h>

int main(){
	int sum =0, n=5;

	for(int i= 0; i <= n; ++i){
		sum += i;
	}

	printf("Sum of the series is %d", sum);
	return 0;
}

    To run the above code use :

gcc lab1/sum1ton.c

    However this will return an executable for the system it is run on. I am running it on an intel-i5 so the assembly is not RISC-V Assembly

cat lab1/sum1ton.c

C to Disassembly

    To generate a RISC-V object file we need to use the riscv64-unknown-elf-gcc

riscv64-unknown-elf-gcc -01 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
ls -ltr sum1ton.o

    Few flags we used o1 - Level 1 optimization lp64 - l (long integer) p(pointer)

    To view the assembly code:

riscv64-unknown-elf-objdump -d  sum1ton.o 

    Repeat the above but with ofast :

riscv64-unknown-elf-gcc -0fast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c

Debug

 ## Lab 2
 [LAB 2: Introduction to ABI and Basic Verification Flow](https://github.com/JoyenBenitto/VSD_ASIC_Design/tree/main/lab2#readme)
