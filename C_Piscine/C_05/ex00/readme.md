# 42 Berlin - C Piscine - C 05 - Exercise 00

**Subject**
> * _Create an iterated function that returns a number. This number is the result of a factorial operation based on the number given as a parameter._   
>
> * _If the argument is not valid the function should return 0._    
>
> * _Overflows must not be handled, the function return will be undefined._    
>
> * _Here’s how it should be prototyped :_   
>
>_int ft_iterative_factorial(int nb);_    
>

<br>

**Libraries**        
>
>stdio.h    
>_[C file input/output](https://en.wikipedia.org/wiki/C_file_input/output)_
>    

**Used functions**   
>
>printf   
>_[Printf in C](https://www.geeksforgeeks.org/printf-in-c/)_    

**Statements**
>
>while    
>_[While loop in C](https://www.geeksforgeeks.org/c-while-loop/?ref=lbp)_
>   
>if    
>_[The if-else Statement in C](https://www.geeksforgeeks.org/c-if-else-statement/?ref=lbp)_   

<br>

**Main steps**
>
>**Prototype function**
>```c
>int	ft_iterative_factorial(int nb)
>```  
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_  
>
>**Body of the function**
>```c
>{
>	// Declare an integer variable that will be used to store the accumulating factorial value
>	int	result;
>
>	// Return 0 for invalid input
>	if (nb < 0)
>		return (0); 
>
>	// Initialize (result) with 1 to return the correct value if (nb) is 0 or 1
>	result = 1;
>
>	// Calculates the factorial while nb is greater than 1
>	while (nb > 1)
>	{
>		// Multiply (result) by the current value of (nb) to effectively accumulate the factorial
>		result *= nb;
>
>		// Decrement (nb) to move closer to the factorial of 1
>		--nb;
>	}
>	// Returns the calculated factorial value 
>	return (result);
>}   
>```
>_[Factorial](https://en.wikipedia.org/wiki/Factorial)_
>
>_[Operators in C](https://www.geeksforgeeks.org/operators-in-c/)_   
>
>_[How To Iterate Over C String](https://dev.to/zirkelc/how-to-iterate-over-c-string-lcj)_  
>
>_[Pre-increment and Post-increment](https://www.geeksforgeeks.org/pre-increment-and-post-increment-in-c/)_    
>

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
>	// Function test with value 0
>	int nb = 0;
>
>	printf("Factorial %d! -> %d\n", nb, ft_iterative_factorial(nb));
>
>	// Function test with value 1
>	nb = 1;
>	printf("Factorial %d! -> %d\n", nb, ft_iterative_factorial(nb));
>
>	// Function test with value greater than 1
>	nb = 5;
>	printf("Factorial %d! -> %d\n", nb, ft_iterative_factorial(nb));
>
>	// Function test with an invalid value
>	nb = -1;
>	printf("Factorial %d! -> %d\n", nb, ft_iterative_factorial(nb));
>}
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_      

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_iterative_factorial.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_iterative_factorial.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_Factorial 0! -> 1_   
>_Factorial 1! -> 1_   
>_Factorial 5! -> 120_   
>_Factorial -1! -> 0_   
>_$_   