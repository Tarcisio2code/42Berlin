# 42 Berlin - C Piscine - C 05 - Exercise 01

**Subject**
> * _Create a recursive function that returns the factorial of the number given as a
parameter._   
>
> * _If the argument is not valid the function should return 0._    
>
> * _Overflows must not be handled, the function return will be undefined._    
>
> * _Here’s how it should be prototyped :_   
>
>_int ft_recursive_factorial(int nb);_    
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
>if    
>_[The if-else Statement in C](https://www.geeksforgeeks.org/c-if-else-statement/?ref=lbp)_   

<br>

**Main steps**
>
>**Prototype function**
>```c
>int	ft_recursive_factorial(int nb)
>```  
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_  
>
>**Body of the function**
>```c
>{
>	if (nb < 0)
>		// Return 0 for invalid input
>		return (0);
>	else if (nb == 0 || nb == 1)
>		// Return 1 because the factorial of 0 and 1 is 1
>		return (1);
>	else
>		// Make a recursive call to ft_recursive_factorial with (nb - 1) as argument and multiply the result by (nb)
>		return (ft_recursive_factorial(nb - 1) * nb);
>}   
>```
>_[Factorial](https://en.wikipedia.org/wiki/Factorial)_
>
>_[Recursive functions in C](https://www.geeksforgeeks.org/c-recursion/)_   
>
>_[Operators in C](https://www.geeksforgeeks.org/operators-in-c/)_   
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
>	printf("Factorial %d! -> %d\n", nb, ft_recursive_factorial(nb));
>
>	// Function test with value 1
>	nb = 1;
>	printf("Factorial %d! -> %d\n", nb, ft_recursive_factorial(nb));
>
>	// Function test with value greater than 1
>	nb = 5;
>	printf("Factorial %d! -> %d\n", nb, ft_recursive_factorial(nb));
>
>	// Function test with an invalid value
>	nb = -1;
>	printf("Factorial %d! -> %d\n", nb, ft_recursive_factorial(nb));
>}
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_      

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_recursive_factorial.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_recursive_factorial.c
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