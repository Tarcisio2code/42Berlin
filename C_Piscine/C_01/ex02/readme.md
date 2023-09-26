# 42 Berlin - C Piscine - C 01 - Exercise 02

**Subject**
> * _Create a function that swaps the value of two integers whose addresses are entered as parameters._   
>
> * _Here’s how it should be prototyped :_   
>
>_void ft_swap(int *a, int *b);_
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
>void	void ft_swap(int *a, int *b)
>```
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_   
>
>**swap the values of pointers**
>```c
>{
>	// declare a temporary integer variable
>	int	i;
>
>	// set the variable value to the value pointed to by the first pointer 
>	i = *a;
>
>	// change first pointer value to second pointer value
>	*a = *b;
>
>	// change first pointer value to the temporary variable value
>	*b = i;
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
>	// initialize two integer variables
>	int a = 2;
>	int b = 4; 
>	
>	// display the initial values of variables
>	printf("Before: a = %d, b = %d\n", a,b);
>	
>	// use the address of operator(&) to pass the address of variables
>	ft_swap(&a, &b);
>
>	// display the new value of variables
>	printf("After: a = %d, b = %d\n", a,b);
>}  
>```    

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_swap.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_swap.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_Before: a = 2, b = 4_    
>_After: a = 4, b = 2_    
>_$_    
