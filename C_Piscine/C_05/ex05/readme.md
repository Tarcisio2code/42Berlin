# 42 Berlin - C Piscine - C 05 - Exercise 05

**Subject**  
> * _Create a function that returns the square root of a number (if it exists), or 0 if the
square root is an irrational number._    
>
> * _Here’s how it should be prototyped :_   
>
>_int ft_sqrt(int nb);_    
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
>int	ft_sqrt(int nb)
>```  
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_  
>
>**Body of the function**
>```c
>{
>	//Declare an integer variable that will be used to store the potential square root values 
>	int	result;
>
>	// Initialize (result) with 0
>	result = 0;
>
>	// Iterates as long as (result) is less than or equal to the input value (nb)
>	while (result <= nb)
>	{
>		// Check if the (square) of the current result is equal to (nb)
>		if (result * result == nb)
>			// Return (result) when an integer square root is found
>			return (result);
>		// Increment (result) by 1 if square root condition is not met
>		result++;
>	}
>	// Return 0 when the square root is an irrational number 
>	return (0);
>}   
>```
>_[Square root](https://en.wikipedia.org/wiki/Square_root)_
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
>	// Function test with integer with square root
>	int number = 1764;
>	printf("The square root of %d is %d\n", number, ft_sqrt(number));
>
>	// Function test with an irrational number 
>	number = 2;
>	printf("The square root of %d is %d\n", number, ft_sqrt(number));
>}
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_      

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_sqrt.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_sqrt.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_   
>_The square root of 1764 is 42_  
>_The square root of 2 is 0_   
>_$_   