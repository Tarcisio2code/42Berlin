# 42 Berlin - C Piscine - C 01 - Exercise 03

**Subject**
> * _Create a function ft_div_mod prototyped like this :_   
>
>_void ft_div_mod(int a, int b, int *div, int *mod);_    
>
> * _This function divides parameters a by b and stores the result in the int pointed by div. It also stores the remainder of the division of a by b in the int pointed by mod._   
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

**Statements**
>
>if    
>_[The if-else Statement in C](https://www.geeksforgeeks.org/c-if-else-statement/?ref=lbp)_

<br>

**Main steps**
>
>**Prototype function**
>```c
>void	ft_div_mod(int a, int b, int *div, int *mod)
>```
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_   
>
>**Body of the function**
>```c
>{
>	// declare two integer variables
>	int	r1;
>	int	r2;
>
>	// prevent division by zero error
>	if (b != 0)
>	{
>		// set the value of the first variable with the result of division
>		r1 = a / b;
>
>		// set the value of the second variable with the the remainder of the division
>		r2 = a % b;
>		
>		// assign the value to pointers
>		*div = r1;
>		*mod = r2;
>	}
>}  
>```
>_[Operators in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_    
>_[Modulo Operator (%) in C](https://www.geeksforgeeks.org/modulo-operator-in-c-cpp-with-examples/)_
>
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
>      // initialize the integer variables
>      int a = 211;
>      int b = 5;
>      int div = 0;
>      int mod = 0;
>
>      // pass the values to the function
>      // use the address of operator(&) to pass the address of variables
>      ft_div_mod(a, b, &div, &mod);
>
>      // display the results
>      printf("division = %d, remainder = %d\n", div, mod);
>}  
>```       

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_div_mod.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_div_mod.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_division = 42, remainder = 1_      
>_$_    
