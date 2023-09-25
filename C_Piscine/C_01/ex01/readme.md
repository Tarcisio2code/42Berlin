# 42 Berlin - C Piscine - C 01 - Exercise 01

**Subject**
> * _Create a function that takes a pointer to pointer to pointer to pointer to pointer to pointer to pointer to pointer to pointer to int as a parameter and sets the value "42" to that int._   
>
> * _Here’s how it should be prototyped :_   
>
>_void ft_ultimate_ft(int *********nbr);_
>

<br>

**Libraries**        
>
>stdio.h    
>_[C file input/output](https://en.wikipedia.org/wiki/C_file_input/output)_

**Used functions**   
>
>printf   
>_[Printf in C](https://www.geeksforgeeks.org/printf-in-c/)_

<br>

**Main steps**
>
>**Prototype function**
>```c
>void	ft_ultimate_ft(int *********nbr)
>```
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_   
>
>**Set the new value to the pointer variable**
>```c
>{    
>	*********nbr = 42;    
>}    
>```
>_[C Pointers](https://www.geeksforgeeks.org/c-pointers/)_    
>
>_[What are pointers](https://youtu.be/2ybLD6_2gKM?si=yLpSffSRbA60G3Se)_
<br>

**Function call**
>**Include the Library**
>```c
>#include <stdio.h>
>```
>_[Using the library](https://www.gnu.org/software/libc/manual/html_mono/libc.html#Using-the-Library)_
>
>**Create the main function**
>```c
>int main(void)
>{
>	// declare and initialize the variable    
>	int i = 24;    
>
>	// declare and initialize the level-1 pointer variable     
>	// use the dereference operator(*) to declare pointer variable 
>	// use the address of operator(&) to store the address of a variable in the pointer variable   
>	int *ptr1 = &i;
>
>	// use multiple indirections to create a chain of pointers   
>	int **ptr2 = &ptr1;    
>	int ***ptr3 = &ptr2;    
>	int ****ptr4 = &ptr3;    
>	int *****ptr5 = &ptr4;    
>	int ******ptr6 = &ptr5;    
>	int *******ptr7 = &ptr6;    
>	int ********ptr8 = &ptr7;    
>	int *********ptr9 = &ptr8;    
>
>	// display the first value of the level-1 pointer  
>	printf("Before: %d\n", *********ptr9);
>
>	// pass the last level pointer to the function    
>	ft_ultimate_ft(ptr9);    
>
>	// display the new value stored at the address pointed to by the level-1 pointer 
>	printf("After: %d\n", *********ptr9);
>}  
>```    
>_[Chain of Pointers in C](https://www.geeksforgeeks.org/chain-of-pointers-in-c-with-examples/)_    

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_ultimate_ft.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_ultimate_ft.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_Before: 24_    
>_After: 42_    
>_$_    
