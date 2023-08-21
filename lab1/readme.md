
### Dependencies

- Follow the instruction in the ``` README ``` to install the relevant tools:
	- [RISC-V GNU Compiler Toolchain](https://github.com/riscv-collab/riscv-gnu-toolchain)
	- [RISC-V Proxy Kernel](https://github.com/riscv-software-src/riscv-pk)
	- [RISC-V  Spike](https://github.com/riscv-software-src/riscv-isa-sim)

### C Code

- Open your terminal and run the following command to create a  ```.c```  file. 

```bash 
vim lab1/sum1ton.c 
``` 

*we are writing a C program that finds the sum of number from 1 to n*  . We are going to use SPIKE simulator to simulate the code.

```c
#include<stdio.h>

int main(){
	int sum =0, n=5;

	for(int i= 0; i <= n; ++i){
		sum += i;
	}

	printf("Sum of the series is %d", sum);
	return 0;
}
```

- To run the above code use :

```shell 
gcc lab1/sum1ton.c
```

> However this will return an executable for the system  it is run on. I am running it on an intel-i5 so the assembly is not RISC-V Assembly

```bash
cat lab1/sum1ton.c
```


### C to Disassembly 

- To generate a RISC-V object file we need to use the  ```riscv64-unknown-elf-gcc```

```bash
riscv64-unknown-elf-gcc -01 -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
ls -ltr sum1ton.o
```
![Screenshot from 2023-08-21 22-12-02](https://github.com/JoyenBenitto/pes_asic_class/assets/75515758/b018e397-29e8-40eb-90e6-d8fc6a2aaeb4)

>*Few flags we used*
>o1 - Level 1 optimization
>lp64 - l (long integer) p(pointer) 

- To view the assembly code:

```shell
riscv64-unknown-elf-objdump -d  sum1ton.o 
```

- Repeat the above but with ``` ofast ``` :

``` shell
riscv64-unknown-elf-gcc -0fast -mabi=lp64 -march=rv64i -o sum1ton.o sum1ton.c
```

### Debug



