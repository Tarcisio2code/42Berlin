# 42 Berlin - C Piscine - C 05 - Exercise 07

**Subject**  
> * _Create a function that returns the next prime number greater or equal to the number given as argument._    
>
> * _Here’s how it should be prototyped :_   
>
>_int ft_find_next_prime(int nb);_    
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
>**Use a utility function that checks whether a given integer is a prime number.
>```c
>int	ft_is_prime(int nb)
>{
>	int	i;
>
>	if (nb < 2)
>		return (0);
>	i = 2;
>	while (i < nb)
>	{
>		if (nb % i == 0)
>			return (0);
>		i++;
>	}
>	return (1);
>}   
>```
>_[Function that returns whether a number is a prime](https://github.com/Tarcisio2code/42Berlin/tree/master/C_Piscine/C_05/ex06)_
>
>**Prototype function**
>```c
>int	ft_find_next_prime(int nb)
>```  
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_  
>
>**Body of the function**
>```c
>{
>	// Start a loop to increment the value of (nb) until it finds the next prime number
>	while (!(ft_is_prime(nb)))
>		// Increment (nb) by 1 in each iteration of the loop to check the next integer.
>		nb++;
>	// Return the next prime number greater than or equal to the initial one (nb)
>	return (nb);
>}
>
>```
>_[Prime number](https://en.wikipedia.org/wiki/Prime_number)_
>
>_[Operators in C](https://www.geeksforgeeks.org/operators-in-c/)_   
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
>	// Function test with a non-prime number
>	int number = 8;
>	printf("The next prime number of %d is %d\n", number, ft_find_next_prime(number));
>
>	// Function test with a prime number
>	number = 5;
>	printf("The next prime number of %d is %d\n", number, ft_find_next_prime(number));
>
>	// Function test with number less than 2
>	int number = 0;
>	printf("The next prime number of %d is %d\n", number, ft_find_next_prime(number));
>	}
>}
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_     
>
>

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_find_next_prime.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_find_next_prime.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_   
>_The next prime number of 8 is 11_    
>_The next prime number of 5 is 5_    
>_The next prime number of 0 is 2_    
>_$_   