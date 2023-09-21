# 42 Berlin - C Piscine - C 00 - Exercise 04

**Subject**
> * _Create a function that displays ’N’ or ’P’ depending on the integer’s sign entered as a parameter. If n is negative, display ’N’. If n is positive or null, display ’P’._   
>
> * _Here’s how it should be prototyped :_   
>
>_void ft_is_negative(int n);_
>

<br>

**Libraries**        
>
>unistd.h    
>_[The Unistd.h library](https://en.wikipedia.org/wiki/Unistd.h)_

**Used functions**   
>
>write   
>_[Write - Linux manual page](https://www.man7.org/linux/man-pages/man2/write.2.html)_

**Statements**
>
>if    
>_[The if-else Statement in C](https://www.geeksforgeeks.org/c-if-else-statement/?ref=lbp)_

<br>

**Main steps**
>
>**Include the Library**
>```c
>#include <unistd.h>
>```
>_[Using the library](https://www.gnu.org/software/libc/manual/html_mono/libc.html#Using-the-Library)_
>
>
>**Prototype function**
>```c
>void ft_is_negative(int n)
>```
>
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_    
>
>**The if-else Statement**
>```c
>if (n < 0)
>	write(1, "N", 1);
>else
>	write(1, "P", 1);
>```
>
>_**the if-else body is not enclosed in square brackets**_    
>_This is because the C language allows the skipping of the braces around the body of the if-else statement when there is only one statement in the body._

<br>

**Function call**
>```c
>int	main(void) {ft_is_negative(-1);ft_is_negative(0);ft_is_negative(1);}   
>```    

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_is_negative.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_is_negative.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_NPP_    
>_$_    
