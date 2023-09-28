# 42 Berlin - C Piscine - C 01 - Exercise 05

**Subject**
> * _Create a function that displays a string of characters on the standard output._   
>
> * _Here’s how it should be prototyped :_   
>
>_void ft_putstr(char *str);_
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
>while    
>_[While loop in C](https://www.geeksforgeeks.org/c-while-loop/?ref=lbp)_

<br>

**Main steps**
>
>**Include the Library**
>```c
>#include <unistd.h>
>```
>_[Using the library](https://www.gnu.org/software/libc/manual/html_mono/libc.html#Using-the-Library)_
>
>**Prototype function**
>```c
>void	ft_putstr(char *str)
>```
>_[Function prototype in C](https://www.geeksforgeeks.org/function-prototype-in-c/)_   
>
>**Body of the function**
>```c
>{    
>	// declare an integer counter variable
>	int	i;
>
>	// initialize the counter variable
>	i = 0;
>
>	// increment counter while string value is not a null character
>	while (str[i] != '\0')
>		i++;
>
>	// print the string on the standard output
>	// use the counter variable to specify the number of bytes to write
>	write(1, str, i);  
>}    
>```
>_[How To Iterate Over C String](https://dev.to/zirkelc/how-to-iterate-over-c-string-lcj)_    
>


**Function call**
>
>**Create the main function**
>```c
>int main(void)
>{
>	// use the dereference operator(*) to declare the pointer
>	char *s;
>	
>	// assign string value directly to pointer
>	s = "42 Berlin ;)";
>
>	// pass the pointer as a parameter to the function
>	ft_putstr(s);     
>}  
>```    
>_[Storage for Strings in C](https://www.geeksforgeeks.org/storage-for-strings-in-c/)_   

**Check the norm**
>```
>norminette -R CheckForbiddenSourceHeader ft_putstr.c
>```
>_[Norminette for 42 schools](https://github.com/42School/norminette)_

**Compile program**
>```
>gcc -Wall -Wextra -Werror ft_putstr.c
>```
>_[GCC, the GNU Compiler Collection](https://gcc.gnu.org)_

**Run program**
>```
>./a.out
>```

**Result**
>_$_    
>_42 Berlin ;)_       
>_$_    
