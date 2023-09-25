# 42 Berlin - C Piscine - C 01 - Exercise 00

**Subject**
> * _Create a function that takes a pointer to int as a parameter, and sets the value "42"
to that int._   
>
> * _Here’s how it should be prototyped :_   
>
>_void ft_ft(int *nbr);_
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
>void	ft_ft(int *nbr)
>```
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_   
>
>**Set the new value to the pointer variable**
>```c
>{    
>	*nbr = 42;    
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
>	// use the dereference operator to declare pointer variable    
>	int *nbr;    
>	
>	// use the address of operator to store the address of a variable in the pointer variable    
>	nbr = &i;    
>
>	// display the first value of the variable    
>	printf("Before: %d\n", i);    
>
>	// pass the pointer to the function that changes it    
>	ft_ft(nbr);
>
>	// display the new value of the variable 
>	printf("After: %d", i);
>}  
>```    

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_ft.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_ft.c
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
