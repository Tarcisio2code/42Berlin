# 42 Berlin - C Piscine - C 05 - Exercise 02

**Subject**
> * _Create an iterated function that returns the value of a power applied to a number.
An power lower than 0 returns 0. Overflows must not be handled._   
>
> * _We’ve decided that 0 power 0 will returns 1._    
>
> * _Here’s how it should be prototyped :_   
>
>_int ft_iterative_power(int nb, int power);_    
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
>int	ft_iterative_power(int nb, int power)
>```  
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_  
>
>**Body of the function**
>```c
>{
>	// Declare an integer variable that will be used to store the result of raising (nb) to the power of (power)
>	int	result;
>
>	// Return 0 when power lower than 0
>	if (power < 0)
>		return (0); 
>
>	// Initialize (result) with 1 to return the correct value when (power) is 0
>	result = 1;
>
>	// Calculates the power while power is greater than 0 
>	// Decrement (power) to move closer to the base case (power equal to 0)
>	while (power > 0 && power--)
>	{
>		// Multiply the current value of (result) by (nb) to effectively accumulate the power
>		result *= nb;
>	}
>	// Return the calculated result stored in the result variable 
>	return (result);
>}   
>```
>_[Exponentiation](https://en.wikipedia.org/wiki/Exponentiation)_
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
>	// Function test with power value greater than 0
>	int nb = 2;
>	int power = 3;
>	printf("%d ^ %d = %d\n", nb, power, ft_iterative_power(nb, power));
>
>	// Function test with power value less than 0
>	nb = 2;
>	power = -1;
>	printf("%d ^ %d = %d\n", nb, power, ft_iterative_power(nb, power));
>
>	// Function test with power value equal to 0
>	nb = 0;
>	power = 0;
>	printf("%d ^ %d = %d\n", nb, power, ft_iterative_power(nb, power));
>}
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_      

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_iterative_power.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_iterative_power.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_   
>_2 ^ 3 = 8_  
>_2 ^ -1 = 0_   
>_0 ^ 0 = 1_   
>_$_   