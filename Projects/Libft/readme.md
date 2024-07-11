## 42 Berlin - Projects - Libft

**Subject**
>_C programming can be very tedious when one doesn’t have access to the highly useful standard functions.
>This project is about understanding the way these functions work, implementing and learning to use them.
>Your will create your own library. It will be helpful since you will use it in your next C school assignments._
>

<br>

**Mandatory part** 
> _[**Makefile**: Configuration file that defines how a C program should be compiled](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/Makefile)_   
> _[**libft.h:** Header file that defines prototypes for functions and structures](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/libft.h)_
>
> **Part 1 - Libc functions**   
> _[**ft_isalpha.c** Determines whether the input value corresponds to an alphabetic character](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_isalpha.c)_    
> _[**ft_isdigit.c** Check whether the provided integer represents a digit character](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_isdigit.c)_    
> _[**ft_isalnum.c** Checks whether the input c falls within the ASCII range of alphanumeric characters](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_isalnum.c)_    
> _[**ft_isascii.c** Checks whether an integer corresponds to a valid ASCII character](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_isascii.c)_    
> _[**ft_isprint.c** Check whether a given integer value corresponds to a printable ASCII character](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_isprint.c)_    
> _[**ft_strlen.c** Calculates the length of a null-terminated string](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_strlen.c)_   
> _[**ft_memset.c** Fills a block of memory with a specific integer value](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_memset.c)_   
> _[**ft_bzero.c** Sets a specified number of bytes in a given memory block to zero](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_bzero.c)_   
> _[**ft_memcpy.c** Copies 'n' bytes from one block of memory to another](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_memcpy.c)_   
> _[**ft_memmove.c** Copies 'n' bytes from one block of memory to another avoiding overlapping memory areas](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_memmove.c)_   
> _[**ft_strlcpy.c** Copies a string from source to dest. with a specified size limit, ensuring null-termination of the destination string](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_strlcpy.c)_    
> _[**ft_strlcat.c** Appends a string from source to destination with a specified size limit](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_strlcat.c)_    
> _[**ft_toupper.c** Converts a lowercase ASCII character to uppercase](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_toupper.c)_    
> _[**ft_tolower.c** Converts a uppercase ASCII character to lowercase](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_tolower.c)_    
> _[**ft_strchr.c** Searches for the first occurrence of a specified character in a string](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_strchr.c)_    
> _[**ft_strrchr.c** Searches for the last occurrence of a specified character in a string](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_strrchr.c)_    
> _[**ft_strncmp.c** Compares at most n characters of two strings, and returns an integer indicating their relative ordering](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_strncmp.c)_    
> _[**ft_memchr.c** Searches for a byte within a memory block and returns a pointer to its first occurrence](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_memchr.c)_    
> _[**ft_memcmp.c** Compares the first n bytes of two memory blocks and returns their relative order](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_memcmp.c)_    
> _[**ft_strnstr.c** Compares the first n bytes of two memory blocks and returns their relative order](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_strnstr.c)_    
> _[**ft_atoi.c** Function that converts a string of digits into an integer value](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_atoi.c)_    
> _[**ft_calloc.c** Allocates 'n' bytes and returns a pointer to the allocated memory](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_calloc.c)_   
> _[**ft_strdup.c** Duplicates a string by allocating memory and copying the content of the source string into it](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_strdup.c)_    
>    
> **Part 2 - Additional functions**    
> _[**ft_substr.c** Extract a specific portion of a string and returns a pointer to the newly allocated substring](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_substr.c)_    
> _[**ft_strjoin.c** Concatenates two strings into a newly allocated string](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_strjoin.c)_    
> _[**ft_strtrim.c** Trims characters from the start and end of a string that are present in a given set](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_strtrim.c)_    
> _[**ft_itoa.c** Converts an integer to its string representation](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_itoa.c)_    
> _[**ft_strmapi.c** Applies a function to each character of a string to create a new string](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_strmapi.c)_    
> _[**ft_striteri.c** Applies a function to each character of a string, modifying the string in place](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_striteri.c)_    
> _[**ft_putchar_fd.c** Writes a single character to a specified file descriptor](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_putchar_fd.c)_    
> _[**ft_putstr_fd.c** Writes a string to a specified file descriptor](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_putstr_fd.c)_    
> _[**ft_putendl_fd.c** Writes a string followed by a newline to a specified file descriptor](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_putendl_fd.c)_    
> _[**ft_putnbr_fd.c** Writes an integer to a specified file descriptor](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_putnbr_fd.c)_    
>    
> **Bonus Part**    
> _[**ft_lstnew.c** Creates a new list node](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_lstnew.c)_    
> _[**ft_lstadd_front.c** Adds a new node at the beginning of a list](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_lstadd_front.c)_    
> _[**ft_lstsize.c** Counts the number of nodes in a list](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_lstsize.c)_    
> _[**ft_lstlast.c** Returns the last node of a list](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_lstlast.c)_    
> _[**ft_lstadd_back.c** Adds a new node at the end of a list](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_lstadd_back.c)_    
> _[**ft_lstdelone.c** Deletes a single node from a list](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_lstdelone.c)_    
> _[**ft_lstclear.c** Deletes and frees all nodes of a list](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_lstclear.c)_    
> _[**ft_lstiter.c** Applies a function to each content of the list nodes](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_lstiter.c)_    
> _[**ft_lstmap.c** Applies a function to each content of the list nodes and creates a new list with the results](https://github.com/Tarcisio2code/42Berlin/blob/master/Projects/Libft/files/ft_lstmap.c)_    

<br>

**Documentation**
>_[An Introduction to Makefiles](https://www.gnu.org/software/make/manual/html_node/Introduction.html)_    
>_[**make**](https://www.gnu.org/software/make/manual/make.html)_   
>_[**ar** - Linux manual page](https://man7.org/linux/man-pages/man1/ar.1.html)_   
>_[**rm** - Linux manual page](https://man7.org/linux/man-pages/man1/rm.1.html)_   
>_[**ranlib** - Linux manual page](https://man7.org/linux/man-pages/man1/ranlib.1.html)_   
>_[C Preprocessors (#)](https://www.geeksforgeeks.org/cc-preprocessors/)_    
>_[man isaplha](https://man7.org/linux/man-pages/man3/isspace.3.html)_   
>_[ASCII - Linux manual page](https://man7.org/linux/man-pages/man7/ascii.7.html)_  
>_[man bzero](https://man7.org/linux/man-pages/man3/bzero.3.html)_    
>_[**C Pointers**](https://www.geeksforgeeks.org/c-pointers/)_     
>_[Pointers to functions](https://www.ibm.com/docs/en/zos/3.1.0?topic=functions-pointers)_    
>_[**size_t** data type in C](https://www.geeksforgeeks.org/size_t-data-type-c-language/)_    
>_[man atoi](https://man7.org/linux/man-pages/man3/atoi.3.html)_    
>_[**File descriptiors** in Linux](https://en.wikipedia.org/wiki/File_descriptor)_    
>_[**Recursive functions** in C](https://www.geeksforgeeks.org/c-recursion/)_   
>_[**Linked List** Program in C](https://www.tutorialspoint.com/data_structures_algorithms/linked_list_program_in_c.htm)_   
>_[**void Pointer** in C Program in C](https://www.geeksforgeeks.org/void-pointer-c-cpp/)_   
