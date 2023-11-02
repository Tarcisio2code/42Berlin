# 42 Berlin - C Piscine - C 05 - Exercise 03

**Subject**
> * _Create a recursive function that returns the value of a power applied to a number._   
>
> * _Overflows must not be handled, the function return will be undefined._    
>
> * _We’ve decided that 0 power 0 will returns 1_    
>
> * _Here’s how it should be prototyped :_   
>
>_int ft_recursive_power(int nb, int power);_    
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
>int	ft_recursive_power(int nb, int power)
>```  
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_  
>
>**Body of the function**
>```c
>{
>	if (power < 0)
>		// Return 0 when power lower than 0
>		return (0);
>	else if (power == 0)
>		// Return 1 when (power) is 0
>		return (1);
>	else
>		// Make a recursive call to ft_recursive_power with (nb) and (power - 1) as argument and multiply the result by (nb)
>		return (ft_recursive_power(nb, power - 1) * nb);
>}   
>```
>_[Exponentiation](https://en.wikipedia.org/wiki/Exponentiation)_
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
>	// Function test with power value greater than 0
>	int nb = 2;
>	int power = 3;
>	printf("%d ^ %d = %d\n", nb, power, ft_recursive_power(nb, power));
>
>	// Function test with power value less than 0
>	nb = 2;
>	power = -1;
>	printf("%d ^ %d = %d\n", nb, power, ft_recursive_power(nb, power));
>
>	// Function test with power value equal to 0
>	nb = 0;
>	power = 0;
>	printf("%d ^ %d = %d\n", nb, power, ft_recursive_power(nb, power));
>}
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_      

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_recursive_power.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_recursive_power.c
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