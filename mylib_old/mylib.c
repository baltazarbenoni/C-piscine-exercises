#include <unistd.h>
#include <stdbool.h>
//=====================================================//
/*
Useful functions outside lessons.
*/
//=====================================================//
int ft_abs(int num)
{
    if(num < 0)
    {
        return -num;
    }
    else
    {
        return num;
    }
}
void ft_print_ints(int *arr, int size)
{
    if(size == 0)
    {
        return;
    }
    for(int i = 0; i < size; ++i)
    {
        ft_putnbr(arr[i]);
    }
}
/*
LESSON ONE
*/
//=====================================================//
//Exercise 00:
//Write a function that displays the character passed as a parameter.
void ft_putchar(char c)
{
    write(1, &c, 1);
}
//Exercise 01:
//Create a function that displays the alphabet in lowercase, on a single line, by ascending order, starting from the letter ’a’.
void ft_print_alphabet(void)
{
    char c;
    int length = 0;
    for(c = 'a'; c <= 'z'; ++c)
    {
        ++length;
    }
    char letters[length * 2];
    int index = 0;
    for(c = 'a'; c <= 'z'; ++c)
    {
        letters[index] = c;
        letters[index + 1] = ' ';
        index = index + 2;
    }
    write(1, &letters, length * 2);
    write(1, "\n", 1);
}
//Exercise 02:
//Create a function that displays the alphabet in lowercase, on a single line, by descending order, starting from the letter ’z’.
void ft_print_reverse_alphabet(void)
{
    char letters[26];
    char c;
    int index = 0;
    for(c = 'z'; c >= 'a'; --c)
    {
        letters[index] = c;
        ++index;
    }
    write(1, &letters, 26);
}
//Exercise 03:
//Create a function that displays all digits, on a single line, by ascending order.
void ft_print_numbers(void)
{
    int i;
    char space = ' ';

    for(i = 0; i <= 9; ++i)
    {
        char c = i + '0';
        write(1, &c, 1);
        write(1, &space, 1);
    }
    write(1, "\n", 1);
}
//Exercise 04:
//Create a function that displays ’N’ or ’P’ depending on the integer’s sign entered as a parameter. If n is negative, display ’N’. If n is positive or null, display ’P’
void ft_is_negative(int n)
{
    char c;
    if(n >= 0)
    {
        c = 'P';
    }
    else
    {
        c = 'N';
    }
    write(1, &c, 1);
    write(1, "\n", 1);
}
//Exercise 05:
//Create a function that displays all different combinations of three different digits in ascending order, listed by ascending order.
void ft_print_comb(void)
{
    for(int i = 0; i <= 9; ++i)
    {
        for(int j = i + 1; j <= 9; ++j)
        {
            for(int k = j + 1; k <= 9; ++k)
            {
                char c_i = i + '0';
                char c_j = j + '0';
                char c_k = k + '0';
                char arr[3] = {c_i, c_j, c_k};
                write(1, &arr, 3);
                char space = ' ';
                write(1, &space, 1);
            }
        }
    }
    write(1, "\n", 1);
}
//Exercise 06:
//Create a function that displays all different combination of two two digits numbers (XX XX) between 00 and 99, listed by ascending order.
int ft_print_comb2_subroutine(int num)
{
    char zero = '0';
    char space = ' ';
    char c_num = num % 10 + '0';
    if(num < 10)
    {
        write(1, &zero, 1);
    }
    else
    {
        char c = num / 10 + '0';
        write(1, &c, 1);
    }
    write(1, &c_num, 1);
    write(1, &space, 1);
    return 0;
}
void ft_print_comb2(void)
{
    int counter = 0;
    for(int i = 0; i <= 99; ++i)
    {
        for(int j = i + 1; j <= 99; ++j)
        {
            ft_print_comb2_subroutine(i);
            ft_print_comb2_subroutine(j);
            char space = ' ';
            write(1, &space, 1);
            ++counter;
        }
        write(1, "\n", 1);
    }
}

//Exercise 07
//Create a function that displays the number entered as a parameter. The function has to be able to display all possible values within an int type variable.
void ft_putnbr(int nb)
{
    char buff[12];
    int size = 0;
    char sign = '-';
    bool has_sign = false;

    if (nb == -2147483648) //INT_MIN
    {
        write(1, "-2147483648", 11);
        return;
    }
    if(nb < 0)
    {
        has_sign = true;
        nb = -nb;
    }
    if(nb == 0)
    {
        write(1, "0", 1);
        return;
    }
    else
    {
        while(nb > 0)
        {
            buff[size] = '0' + (nb % 10);
            nb /= 10;
            ++size;
        }
    }
    //reverse order
    char rev_buff[12];
    for(int j = 0, i = size - 1; i >= 0; ++j, --i)
    {
        rev_buff[j] = buff[i];
    }
    /*for(int j = 0, i = size - 1; j <= ((size + 1 ) / 2); ++j, --i)
    {
        char temp = buff[i];
        buff[i] = buff[j];
        buff[j] = temp;
    }*/
    if(has_sign)
    {
        write(1, &sign, 1);
    }
    write(1, &rev_buff, size);
    //write(1, "\n", 1);
}


//Exercice 08:
//Create a function that displays all different combinations of n numbers by ascending order.
void print_num(int depth, int start, int max_depth, char *buff)
{
    for(int i = start; i <= 9; ++i)
    {
        buff[depth] = '0' + i;
        if(depth < max_depth)
        {
            print_num(depth + 1, i + 1, max_depth, buff);
        }
        else
        {
            write(1, buff, (max_depth + 1));
            write(1, " ", 1);
        }
    }
    if(depth == 0)
    {
        write(1, "\n", 1);
    }
}
void ft_print_combn(int n)
{
    if(n <= 0 || n > 9)
    {
        return;
    }
    char buffer[10];
    print_num(0, 0, n - 1, buffer);
}
//====================================================//
//=====================================================//
/*
LESSON TWO
*/
//=====================================================//
//Exercise 00:
//Create a function that takes a pointer to int as a parameter, and sets the value "42" to that int.
void ft_ft(int *nbr)
{
    *nbr = 42;
}
//Exercise 01:
//Create a function that takes a pointer to pointer to pointer to pointer to pointer to pointer to pointer to pointer to pointer to int as a parameter and sets the value "42" to that int.
// --> 9 pointers
void ft_ultimate_ft(int *********nbr)
{
    *********nbr = 42;
}
//Exercise 02:
//Create a function that swaps the value of two integers whose addresses are entered as parameters.
void ft_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//Exercise 03:
//Create a function ft_div_mod. This function divides parameters a by b and stores the result in the int pointed by div. It also stores the remainder of the division of a by b in the int pointed by mod.
void ft_div_mod(int a, int b, int *div, int *mod)
{
    *mod = a % b;
    *div = a / b;
}
//Exercise 04:
//Create a function ft_ultimate_div_mod. This function divides parameters a by b. The result of this division is stored in the int pointed by a. The remainder of the division is stored in the int pointed by b.
void ft_ultimate_div_mod(int *a, int *b)
{
    int tmp = *a;
    *a = *a / *b;
    *b = tmp % *b;
}
//Exercise 05:
//Create a function that displays a string of characters on the standard output.
void ft_putstr(char *str)
{
    int length_counter = 0;
    while(str[length_counter] != '\0') 
    {
        ++length_counter;
    }
    write(1, str, length_counter);
    write(1, "\n", 1);
}
//Exercise 06:
//Create a function that counts and returns the number of characters in a string.
int ft_strlen(char *str)
{
    int length_counter = 0;
    while(str[length_counter] != '\0') 
    {
        ++length_counter;
        //Guard against not null-terminated strings.
        if(length_counter >= 2147483647)
        {
            return length_counter;
        }
    }
    return length_counter;
}
//Exercise 07:
//Create a function which reverses a given array of integer (first goes last, etc). The arguments are a pointer to int and the number of ints in the array.
void ft_rev_int_tab(int *tab, int size)
{
    char temp;
    for(int i = 0, j = size - 1; i <= (float)(size / 2); ++i, --j)
    {
        temp = tab[j];
        tab[j] = tab[i];
        tab[i] = temp;
    }
}
//Exercise 08:
//Create a function which sorts an array of integers by ascending order. The arguments are a pointer to int and the number of ints in the array.
//=====================================
void ft_sort_int_tab(int *buffer, int size)
{
    if(size <= 0)
    {
        return;
    }
    int tmp;
    for(int i = 0; i < size - 1; ++i)
    {
        for(int j = i + 1; j < size; ++j)
        {
            if(buffer[i] > buffer[j])
            {
                tmp = buffer[i];
                buffer[i] = buffer[j];
                buffer[j] = tmp;
            }
        }
    }
}
//=====================================================//
/*
LESSON THREE
*/
//=====================================================//
//Exercise 00:
//Reproduce the behavior of the function strcpy (man strcpy).
/*
strcpy: Copy string
Copies the C string pointed by source into the array pointed by destination, including the terminating null character (and stopping at that point).

To avoid overflows, the size of the array pointed by destination shall be long enough to contain the same C string as source (including the terminating null character), and should not overlap in memory with source.
*/
char *ft_strcpy(char *dest, char *src)
{
    int i = 0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = src[i];
    return dest;
}
//=======================================================
//Exercise 01:
//Reproduce the behavior of the function strncpy (man strncpy).
/*
===========================================
strncpy
Copy characters from string
Copies the first num characters of source to destination. If the end of the source C string (which is signaled by a null-character) is found before num characters have been copied, destination is padded with zeros until a total of num characters have been written to it.

No null-character is implicitly appended at the end of destination if source is longer than num. Thus, in this case, destination shall not be considered a null terminated C string (reading it as such would overflow). Destination and source shall not overlap (see memmove for a safer alternative when overlapping).
*/
char *ft_strncpy(char *dest, char *src, unsigned int n)
{
    _Bool source_ended = false;
    for(int i = 0; i < n; ++i)
    {
        if(source_ended == false)
        {
            dest[i] = src[i];
        }
        else
        {
            dest[i] = '0';
        }
        if(src[i] == '\0')
        {
            source_ended = true;
        }
    }
    return dest;
}
//=======================================================
//Exercise 02:
//Create a function that returns 1 if the string given as a parameter contains only alphabetical characters, and 0 if it contains any other character.
int ft_str_is_alpha(char *str)
{
    int index = 0;
    int flag = 1;
    while(str[index] != '\0')
    {
        char c = str[index];
        if(!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z'))
        {
            return 0;
        }
        ++index;
    }
    return 1;
}
//=======================================================
//Exercise 03:
//Create a function that returns 1 if the string given as a parameter contains only digits, and 0 if it contains any other character.
int ft_str_is_numeric(char *str)
{
    int index = 0;
    int flag = 1;
    while(str[index] != '\0')
    {
        char c = str[index];
        if(!(c >= '0' && c <= '9'))
        {
            return 0;
        }
        ++index;
    }
    return 1;
}
//=======================================================
//Exercise 04:
//Create a function that returns 1 if the string given as a parameter contains only lowercase alphabetical characters, and 0 if it contains any other character.
int ft_str_is_lowercase(char *str)
{
    int index = 0;
    int flag = 1;
    while(str[index] != '\0')
    {
        char c = str[index];
        if(!(c >= 'a' && c <= 'z'))
        {
            return 0;
        }
        ++index;
    }
    return 1;
}
//=======================================================
//Exercise 05:
//Create a function that returns 1 if the string given as a parameter contains only uppercase alphabetical characters, and 0 if it contains any other character.
int ft_str_is_uppercase(char *str)
{
    int index = 0;
    int flag = 1;
    while(str[index] != '\0')
    {
        char c = str[index];
        if(!(c >= 'A' && c <= 'Z'))
        {
            return 0;
        }
        ++index;
    }
    return 1;
}
//=======================================================
//Exercise 06:
//Create a function that returns 1 if the string given as a parameter contains only printable characters, and 0 if it contains any other character.
int ft_str_is_printable(char *str)
{
    int index = 0;
    int flag = 1;
    while(str[index] != '\0')
    {
        char c = str[index];
        if(!(c >= '!' && c <= '~'))
        {
            return 0;
        }
        ++index;
    }
    return 1;
}
//=======================================================
//Exercise 07:
//Create a function that transforms every letter to uppercase.
char *ft_strupcase(char *str)
{
    int index = 0;
    while(str[index] != '\0')
    {
        char c = str[index];
        if((c >= 'a' && c <= 'z'))
        {
            str[index] ^= 32;
        }
        ++index;
    }
    return str;
}
//=======================================================
//Exercise 08:
// Create a function that transforms every letter to lowercase.
char *ft_strlowcase(char *str)
{
    int index = 0;
    while(str[index] != '\0')
    {
        char c = str[index];
        if((c >= 'A' && c <= 'Z'))
        {
            str[index] |= 0x20;
        }
        ++index;
    }
    return str;
}
//=======================================================
//Exercise 09:
//Create a function that capitalizes the first letter of each word and transforms all other letters to lowercase. A word is a string of alphanumeric characters.
int ft_is_alphanumeric(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
        return 1;
    }
    return 0;
}
char *ft_strcapitalize(char *str)
{
    if(str[0] == '\0')
    {
        return str;
    }
    if((str[0] >= 'a' && str[0] <= 'z'))
    {
        str[0] ^= 0x20;
    }
    int index = 1;
    while(str[index] != '\0')
    {
        char c = str[index];
        if((c >= 'a' && c <= 'z') && !(ft_is_alphanumeric(str[index - 1])))
        {
            str[index] ^= 0x20;
        }
        else if((c >= 'A' && c <= 'Z') && ft_is_alphanumeric(str[index - 1]))
        {
            str[index] |= 0x20;
        }
        ++index;
    }
    return str;
}
//=======================================================
//Exercise 10:
//Reproduce the behavior of the function strlcpy (man strlcpy).

/*

*/
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    if(size = 0)
    {
        return 0;
    }
    int i = 0;
    while(src[i] != '\0')
    {
        if(i < size)
        {
            dest[i] = src[i];
        }
        else if(i == size)
        {
            dest[i] = '\0';
        }
        ++i;
    }
    return i;
}
//=======================================================
//Exercise 11:
/*
Create a function that displays a string of characters onscreen. If this string contains characters that aren’t printable, they’ll have to be displayed in the shape of hexadecimals (lowercase), preceeded by a "backslash".
 For example :
    Coucou\ntu vas bien ?
• The function should display :
    Coucou\0atu vas bien ?
*/
void dec_to_hex(int dec, char *hex, int size)
{
    if(size == 0)
    {
        return;
    }
    if(dec < 10)
    {
        hex[0] = '0' + dec;
    }
    int counter = 0;
    while(dec != 0)
    {
        int rem = dec % 16;
        char c = '0' + rem;
        if(rem > 9)
        {
            c = 'a' + (rem - 10);
        }
        hex[counter] = c;
        write(0, &c, 1);
        dec /= 16;
        counter++;
        if(counter >= size)
        {
            break;
        }
    }
}
void ft_putstr_non_printable(char *str)
{
    int index = 0;
    while(str[index] != '\0')
    {
        char c = str[index];
        if(!(c >= ' ' && c <= '~'))
        {
            write(1, "\\0", 2);
            int dec = (unsigned char)c;
            char hex[128];
            dec_to_hex(dec, hex, 128);
            ft_putstr(hex);
        }
        else
        {
            write(1, &c, 1);
        }
        ++index;
    }
    write(1, "\n", 1);
}
//=======================================================
//Exercise 12:
/*Create a function that displays the memory area onscreen.
• The display of this memory area should be split into three "columns" separated by a space:
1. The hexadecimal address of the first line’s first character followed by a ’:’.
2. The content in hexadecimal with a space each 2 characters and should be
padded with spaces if needed (see the example below).
3. The content in printable characters.

• If a character is non-printable, it’ll be replaced by a dot.
• Each line should handle sixteen characters.
• If size is equal to 0, nothing should be displayed.
*/
//=======================================================
void ft_putnbr(int nb);
void long_dec_to_hex(unsigned long long dec, char *hex);
void short_dec_to_hex(int dec, char *hex);
void print_one_line_memory(void *addr, int block_start, int block_end, int line_size);

#define MIN(a,b) ((a)<(b)?(a):(b)) 
void *ft_print_memory(void *addr, unsigned int size)
{
    int block_start = 0;
    int line_size = 16;
    while(block_start < size)
    {
        int block_end = MIN(block_start + line_size, size);

        print_one_line_memory(addr, block_start, block_end, line_size);
        block_start = block_end; 
    }
    return addr;

}
void print_one_line_memory(void *addr, int block_start, int block_end, int line_size)
{

    if(block_end <= block_start)
    {
        return;
    }
    //print address.
    unsigned long long dec = (unsigned long long)(unsigned char*)(addr + block_start);
    char hex[128];
    long_dec_to_hex(dec, hex);
    write(1, ":", 1);
    //print content in hex.
    for(int i = 0; i < line_size; ++i)
    {
        if(i % 2 == 0)
        {
            write(1, " ", 1);
        }
        if(i + block_start >= block_end)
        {
            write(1, " ", 1);
            write(1, " ", 1);
            continue;
        }
        unsigned char x = *(unsigned char*)(addr + block_start + i); 
        int num = (int)x;
        char buff[32];
        short_dec_to_hex(num, buff);
    }
    write(1, " ", 1);
    //print characters.
    for(int i = block_start; i < block_end; ++i)
    {
        unsigned char c = *(unsigned char*)(addr + i); 
        if(!(c >= ' ' && c <= '~'))
        {
            write(1, ".", 1);
        }
        else
        {
            write(1, &c, 1);
        }
    }
    write(1, "\n", 1);
}
void long_dec_to_hex(unsigned long long dec, char *hex)
{
    if(dec < 10)
    {
        hex[0] = '0' + dec;
    }
    int counter = 0;
    while(dec != 0)
    {
        int rem = dec % 16;
        char c = '0' + rem;
        if(rem > 9)
        {
            c = 'a' + (rem - 10);
        }
        hex[counter] = c;
        dec /= 16;
        counter++;
    }
    while(counter < 16)
    {
        hex[counter] = '0';
        counter++;
    }
    hex[counter] = '\0';
    //reverse order.
    for(int j = 0, i = counter - 1; j < (counter / 2); ++j, --i)
    {
        char temp = hex[i];
        hex[i] = hex[j];
        hex[j] = temp;
    }
    //print.
    int index = 0;
    while(hex[index] != '\0')
    {
        write(1, &hex[index], 1);
        ++index;
    }
}
void short_dec_to_hex(int dec, char *hex)
{
    if(dec < 10)
    {
        hex[0] = '0' + dec;
    }
    int counter = 0;
    while(dec != 0)
    {
        int rem = dec % 16;
        char c = '0' + rem;
        if(rem > 9)
        {
            c = 'a' + (rem - 10);
        }
        hex[counter] = c;
        write(1, &c, 1);
        dec /= 16;
        counter++;
    }
    hex[counter] = '\0';
    //reverse order.
    for(int j = 0, i = counter - 1; j < (float)(counter / 2); ++j, --i)
    {
        char temp = hex[i];
        hex[i] = hex[j];
        hex[j] = temp;
    }
}
//=====================================================//
/*
LESSON FOUR
*/
//=====================================================//
//Exercise 00 : ft_strcmp
//Reproduce the behavior of the function strcmp (man strcmp).
/*
strcmp() returns an integer indicating the result of the
       comparison, as follows:
       •  0, if the s1 and s2 are equal;
       •  a negative value if s1 is less than s2;
       •  a positive value if s1 is greater than s2.
*/
int ft_strcmp(char *s1, char *s2)
{
    if(s1[0] == '\0' && s2[0] == '\0')
    {
        return 0;
    }
    int counter1 = 0;
    int counter2 = 0;
    while(s1[counter1] != '\0')
    {
        ++counter1;
    }
    while(s2[counter2]!= '\0')
    {

        ++counter2;
        if(counter2 > counter1)
        {
            return -1;
        }
    }
    if(counter1 > counter2)
    {
        return 1;
    }
    else if(counter1 < counter2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
//Exercise 01 : ft_strncmp
//Reproduce the behavior of the function strncmp (man strncmp).
/*
    The strncmp() function is similar (to strcmp), except it compares only the first (at most) n bytes of s1 and s2.
*/
int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    if(s1[0] == '\0' && s2[0] == '\0')
    {
        return 0;
    }
    int counter1 = 0;
    int counter2 = 0;
    for(int i = 0; i < n; ++i)
    {
        if(s1[i] != '\0')
        {
            ++counter1;
        }
        if(s2[i] != '\0')
        {
            ++counter2;
        }
        if(counter1 != counter2)
        {
            if(counter1 > counter2)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
    return 0;
}
//Exercise 02 : ft_strcat
//Reproduce the behavior of the function strcat (man strcat).
/*
The strcat() function shall append a copy of the string pointed to
by s2 (including the terminating NUL character) to the end of the
string pointed to by s1.  The initial byte of s2 overwrites the
NUL character at the end of s1.  If copying takes place between
objects that overlap, the behavior is undefined.
*/
char *ft_strcat(char *dest, char *src)
{
    int start = 0;
    while(dest[start] != '\0')
    {
        ++start;
    }
    int i = 0;
    while(src[i] != '\0')
    {
        dest[start + i] = src[i];
        ++i;
    }
    //Get the null
    dest[start + i] = '\0';
    return dest;
}
//Exercise 03 : ft_strncat
/*
Reproduce the behavior of the function strncat (man strncat).

       This function appends at most size non-null bytes from the array
       pointed to by src, followed by a null character, to the end of the
       string pointed to by dst.  dst must point to a string contained in
       a buffer that is large enough, that is, the buffer size must be at
       least strlen(dst) + strnlen(src, ssize) + 1.

*/
char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    int start = 0;
    while(dest[start] != '\0')
    {
        ++start;
    }
    for(int i = 0; i < nb; ++i)
    {
        if(src[i] == '\0')
        {
            //Get the null
            dest[start + i] = '\0';
            break;
        }
        dest[start + i] = src[i];
    }
    return dest;
}
//Exercise 04 : ft_strstr
//Reproduce the behavior of the function strstr (man strstr).
/*
The strstr() function finds the first occurrence of the substring
       needle in the string haystack.  The terminating null bytes ('\0')
       are not compared.

       The strcasestr() function is like strstr(), but ignores the case
       of both arguments.

       These functions return a pointer to the beginning of the located
       substring, or NULL if the substring is not found.

       If needle is the empty string, the return value is always haystack
       itself.
*/
char *ft_strstr(char *str, char *to_find)
{
    int i = 0;
    int j = 0;
    int match;
    char* ptr;
    while(str[i] != '\0')
    {
        //printf("i is %d, and j is %d\n", i, j);
        //printf("i (%d) char is %c, and j (%d) char is %c\n", i, str[i], j, to_find[j]);
        if(str[i] == to_find[j])
        {
            if(j == 0)
            {
                //printf("pointer inside: %p\n", &str[i]);
                ptr = &str[i];
            }
            ++j;
        }
        else if(to_find[j] == '\0')
        {
            //printf("Exiting loop\n");
            break;
        }
        else
        {
            //printf("Restarting\n");
            ptr = NULL;
            j = 0;
        }
        ++i;
    }
    return ptr;
}
//Exercise 05 : ft_strlcat
//Reproduce the behavior of the function strlcat (man strlcat).
/*
The strlcpy() and strlcat() functions copy and concatenate strings respectively. They are designed to be safer, more consistent, and less error prone replacements for strncpy(3) and strncat(3). Unlike those functions, strlcpy() and strlcat() take the full size of the buffer (not just the length) and guarantee to NUL-terminate the result (as long as size is larger than 0 or, in the case of strlcat(), as long as there is at least one byte free in dst). Note that a byte for the NUL should be included in size. Also note that strlcpy() and strlcat() only operate on true ''C'' strings. This means that for strlcpy() src must be NUL-terminated and for strlcat() both src and dst must be NUL-terminated.

The strlcat() function appends the NUL-terminated string src to the end of dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.

The strlcpy() and strlcat() functions return the total length of the string they tried to create. For strlcpy() that means the length of src. For strlcat() that means the initial length of dst plus the length of src. While this may seem somewhat confusing, it was done to make truncation detection simple.

Note, however, that if strlcat() traverses size characters without finding a NUL, the length of the string is considered to be size and the destination string will not be NUL-terminated (since there was no space for the NUL). This keeps strlcat() from running off the end of a string. In practice this should not happen (as it means that either size is incorrect or that dst is not a proper ''C'' string). The check exists to prevent potential security problems in incorrect code.
*/
unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    if(size == 0)
    {
        return 0;
    }
    //Get length of dest.
    unsigned int i = 0;
    while(dest[i] != '\0')
    {
        ++i;
        //If buffer size reached, return without copying or null, terminating.
        if(i >= size)
        {
            unsigned int j = 0;
            while(src[j] != '\0')
            {
                ++j;
            }
            return i + j;
        }
    }
    //Write to buffer.
    unsigned int j = 0;
    while(src[j] != '\0' && i + j < size)
    {
        dest[i + j] = src[j];
        ++j;
    }
    //Null terminate result.
    dest[i + j] = '\0';
}
//=====================================================//
/*
LESSON FIVE
*/
//=====================================================//
//Exercise 03 : ft_atoi
/*
Write a function that converts the initial portion of the string pointed by str to its int
representation
• The string can start with an arbitray amount of white space (as determined by isspace(3))
• The string can be followed by an arbitrary amount of + and - signs, - sign will change
the sign of the int returned based on the number of - is odd or even.
• Finally the string can be followed by any numbers of the base 10.
• Your function should read the string until the string stop following the rules and return
the number found until now.
• You should not take care of overflow or underflow. result can be undefined in that case.
• Here’s an example of a program that prints the atoi return value:
$>./a.out " ---+--+1234ab567"
-1234
*/
int ft_atoi(char *str)
{
    int is_pos = 1;
    int num = 0;
    int finished = 0;
    int index = 0;
    /*
    whitespaces: x >= 9 && x <= 13 || x == 32.
    plus minus: x == '+' , x == '-'
    */
    while(finished == 0)
    {
        char c = str[index];
        ++index;
        //Initial whitespace.
        if(c >= '\t' && c <= '\r' || c == ' ')
        {
            //printf("whitespace: %c\n", c);
            if(num == 0)
            {
                continue;
            }
            else
            {
                return num * is_pos;
            }
        }
        //Minus signs.
        else if(c == '-')
        {
            //printf("minus");
            if(num == 0)
            {
                is_pos *= -1;
                continue;
            }
            return num * is_pos;
        }
        //Plus signs.
        else if(c == '+')
        {
            //printf("plus");
            if(num == 0)
            {
                continue;

            }
            return num * is_pos;
        }
        //Handle numbers.
        else if(c >= '1' && c <= '9')
        {
            //printf("numbers %c", c);
            num *= 10;
            num += c - '0';
        }
        else if(num != 0)
        {
            //printf("exiting");
            return num * is_pos;
        }
    }
}
//Exercise 04 : ft_putnbr_base
//
/*
Create a function that displays a number in a base system in the terminal.
• This number is given in the shape of an int, and the radix in the shape of a string
of characters.
• The base-system contains all useable symbols to display that number :
◦ 0123456789 is the commonly used base system to represent decimal numbers
◦ 01 is a binary base system ;
◦ 0123456789ABCDEF an hexadecimal base system ;
◦ poneyvif is an octal base system.
• The function must handle negative numbers.
• If there’s an invalid argument, nothing should be displayed. Examples of invalid
arguments :
◦ base is empty or size of 1;
◦ base contains the same character twice ;
◦ base contains + or - ;
*/
int ft_check_base(char* base, int len)
{
    //check initial conditions.
    if(base[0] == '\0' || base[1] == '\0')
    {
        return 0;
    }
    //create array for duplicate comparison.
    char buffer[len + 1];
    buffer[len] = '\0';
    int i = 0;
    while(base[i] != '\0')
    {
        if(base[i] == '+' || base[i] == '-')
        {
            return 0;
        }
        if(base[i] >= '\t' && base[i] <= '\r' || base[i] == ' ')
        {
            return 0;
        }
        int j = 0;
        while(buffer[j] != '\0')
        {
            if(base[i] == buffer[j])
            {
                return 0;
            }
            ++j;
        }
        buffer[i] = base[i];
        ++i;
    }
    return 1;
}
char ft_get_char(int nbr, int base)
{
    if(base == 0 || base == 1)
    {
        return '0';
    }
    if(nbr > base)
    {
        //printf("error, digit is %d, base is %d", nbr, base);
        return '=';
    }
    if(nbr < 10)
    {
        char c = nbr + '0';
        return c;
    }
    else
    {
        char c = 'A' + (char)(nbr - 10);
        return c;
    }
}
void ft_putnbr_base(int nbr, char *base)
{
    int buffer_limit = 128;
    char buffer[buffer_limit];
    int base_len = ft_strlen(base);
    if(ft_check_base(base, base_len) < 1)
    {
        return;
    }
    if(nbr < 0)
    {
        char a = '-';
        write(1, &a, 1);
        nbr *= -1;
    }
    //get value.
    int counter = 0;
    while(nbr > 0)
    {
        int digit = (nbr % base_len);
        char c = ft_get_char(digit, base_len);
        buffer[counter] = c;
        nbr /= base_len;
        ++counter;
        //printf("\ndigit: %d, nbr: %d, base: %d, c: %c, counter: %d\n", digit, nbr, base_len, c, counter);
        if(counter >= buffer_limit)
        {
            break;
        }
    }
    //print and reverse order.
    {
        for(int x = counter - 1; x >= 0; --x)
        {
            char a = buffer[x];
            write(1, &a, 1);
        }
    }
    write(1, "\n", 1);
}
//Exercise 05 : ft_atoi_base
/*
Write a function that converts the initial portion of the string pointed by str to int
representation.
• str is in a specific base given as a second parameter.
• excepted the base rule, the function should work exactly like ft_atoi.
• If there’s an invalid argument, the function should return 0. Examples of invalid
arguments :
◦ base is empty or size of 1;
◦ base contains the same character twice ;
◦ base contains + or - or whitespaces;
• Here’s how it should be prototyped :
*/
int ft_atoi_base(char *str, char *base)
{
    int number = ft_atoi(str);
    //printf("%d", number);
    ft_putnbr_base(number, base);
}
//=====================================================//
/*
LESSON SIX 
*/
//=====================================================//
//Exercise 00 : ft_iterative_factorial
/*
Create an iterated function that returns a number. This number is the result of a
factorial operation based on the number given as a parameter.
• If the argument is not valid the function should return 0.
• Overflows must not be handled, the function return will be undefined.
*/
int ft_iterative_factorial(int nb)
{
    if(nb <= 0)
    {
        return 0;
    }
    int product = nb;
    for(int i = 1; i < nb; ++i)
    {
        product *= i;
    }
    return product;
}
//Exercise 01 : ft_recursive_factorial
/*
Create a recursive function that returns the factorial of the number given as a
parameter.
• If the argument is not valid the function should return 0.
• Overflows must not be handled, the function return will be undefined.
*/
int ft_recursive_factorial(int nb)
{
    if(nb <= 0)
    {
        return 0;
    }
    int product = nb;
    while(nb > 1)
    {
        nb = nb - 1;
        product *= nb;
    }
    return product;
}
//Exercise 02 : ft_iterative_power
/*
Create an iterated function that returns the value of a power applied to a number.
An power lower than 0 returns 0. Overflows must not be handled.
• We’ve decided that 0 power 0 will returns 1
*/
int ft_iterative_power(int nb, int power)
{
    if(power < 0)
    {
        return 0;
    }
    if(power == 0)
    {
        return 1;
    }
    int result = 1;
    for(int i = 0; i < power; ++i)
    {
        result *= nb;
    }
    return result;
}
//Exercise 03 : ft_recursive_power
/*
Create a recursive function that returns the value of a power applied to a number.
• Overflows must not be handled, the function return will be undefined.
• We’ve decided that 0 power 0 will returns 1
*/
int ft_recursive_power(int nb, int power)
{
    if(power < 0)
    {
        return 0;
    }
    if(power == 0)
    {
        return 1;
    }
    int result = 1;
    while(power > 0)
    {
        result *= nb;
        power -= 1;
    }
    return result;
}
//Exercise 04 : ft_fibonacci
/*
Create a function ft_fibonacci that returns the n-th element of the Fibonacci
sequence, the first element being at the 0 index. We’ll consider that the Fibonacci
sequence starts like this: 0, 1, 1, 2.
• Overflows must not be handled, the function return will be undefined.
• Obviously, ft_fibonacci has to be recursive.
• If the index is less than 0, the function should return -1.
*/
int ft_fibonacci(int index)
{
    if(index < 0)
    {
        return -1;
    }
    int previous = 0;
    int element = 1;
    int temp = 0;
    while(index > 0)
    {
        temp = element;
        element += previous;
        previous = temp;
        --index;
    }
    return element;
}
//Exercise 05 : ft_sqrt
//Create a function that returns the square root of a number (if it exists), or 0 if the square root is an irrational number.
int ft_sqrt(int nb)
{
    if(nb == 1)
    {
        return 1;
    }
    int root = nb / 2;
    int previous = 0;
    while(root * root != nb)
    {
        previous = root;
        //Using Newton's method.
        root = (root + nb / root) / 2;
        //If not converging --> has no retional root, exit loop.
        if(root == previous && root * root != nb)
        {
            return 0;
        }
    }
    return root;
}
//Exercise 06 : ft_is_prime
//Create a function that returns 1 if the number given as a parameter is a prime number, and 0 if it isn’t.
int ft_is_prime(int nb)
{
    if(nb < 2)
    {
        return 0;
    }
    if(nb == 2)
    {
        return 1;
    }
    for(int i = 2; i < nb; ++i)
    {
        if(nb % i == 0)
        {
            //printf("Found divider %d, %d is not prime\n", i, nb);
            return 0;
        }
    }
    //printf("Not divider found, %d is prime\n", nb);
    return 1;
}
//Exercise 07 : ft_find_next_prime
// Create a function that returns the next prime number greater or equal to the number given as argument.
int ft_find_next_prime(int nb)
{
    if(ft_is_prime(nb) == 1)
    {
        //printf("nb %d is prime\n", nb);
        return nb;
    }
    while(ft_is_prime(nb) != 1)
    {
        nb += 1;
        //printf("Trying if %d is prime\n", nb);
    }
    //printf("Found! %d is prime\n", nb);
    return nb;
}
//Exercise 08 : The Ten Queens
/*
Create a function that displays all possible placements of the ten queens on a
chessboard which would contain ten columns and ten lines, without them being
able to reach each other in a single move, and returns the number of possibilities.
• Recursivity is required to solve this problem.
• Here’s how it’ll be displayed :
$>./a.out | cat -e
0257948136$
0258693147$
...
4605713829$
4609582731$
...
9742051863$
$>
• The sequence goes from left to right. The first digit represents the first Queen’s
position in the first column (the index starting from 0). The Nth digit represents
the Nth Queen’s position in the Nth column.
• The return value must be the total number of displayed solutions.
*/
int ft_check_for_queens(int x, int y, int *queens)
{
    int current_size = x;
    for(int i = 0; i < current_size; ++i)
    {
        //Check if this y-row is free.
        if(queens[i] == y)
        {
            return 0;
        }
        //Check diagonals.
        if(ft_abs(queens[i]- y) == ft_abs(i - x))
        {
            return 0;
        }
    }
    return 1;
}
enum SolveResult
{
    SOLVE_BACKTRACK,
    SOLVE_ADVANCE,
    SOLVE_CONTINUE_COLUMN,
    SOLVE_BACKTRACK_AFTER_SOLUTION,
    SOLVE_DONE
};
int ft_queen_solver(int column, int* queens, int size)
{
    //start is 0 if queens is empty (-1) at this column, else its one larger than the current value.
    int start = queens[column] + 1;
    //If all the cells on this column have been checked, backtrack.
    if(queens[column] >= size - 1)
    {
        queens[column] = -1;
        //Do not backtrack if already at the first column.
        if(column <= 0)
        {
            return SOLVE_DONE;
        }
        //Returning zero causes backtrack.
        return SOLVE_BACKTRACK;
    }
    //Check if there are any options above current queen y-value (or zero).
    for(int i = start; i < size; ++i)
    {
        if(ft_check_for_queens(column, i, queens) == 1)
        {
            //Free cell found, store value in queens.
            queens[column] = i;
            //If completed, break and add this configuration to solutions.
            if(column == size - 1)
            {
                for(int j = 0; j < size; ++j)
                {
                    //char c = queens[j] + '0';
                    //write(1, &c, 1);
                    ft_putnbr(queens[j]);
                    //printf("%d", queens[j]);
                    if(j == size - 1)
                    {
                        write(1, "\n", 1);
                    }
                    else
                    {
                        char cln = ',';
                        write(1, &cln, 1);
                    }
                }
                //Return value 3 causes backtracking from correct solution.
                if(queens[column] == size - 1)
                {
                    queens[column] = -1;
                    return SOLVE_BACKTRACK_AFTER_SOLUTION;
                }
                //Return value 2 --> check other cells in this column.
                else
                {
                    return SOLVE_CONTINUE_COLUMN;
                }
            }
            //Else continue, go to next column.
            else
            {
                //Returning 1 causes program to advance 'deeper'.
                return SOLVE_ADVANCE;
            }
        }
        //this means dead end --> backtrack and remove queen from current column.
        else if(i == size - 1)
        {
            if(column <= 0)
            {
                return SOLVE_DONE;
            }
            //printf("Backtracking to column %d\n", column - 1);
            queens[column] = -1;
            //Returning zero causes backtrack.
            return SOLVE_BACKTRACK;
        }
    }
    char str[] = "End of loop, returning 0\n"; 
    ft_putstr(str);
    return SOLVE_DONE;
}
int ft_manage_queen_loop(int *queens, int size, int *solution_count)
{
    int column = 1;
    int result = 0;
    while(result != SOLVE_DONE)
    {
        //Check column is assigned correctly.
        if(column < 0 || column >= size)
        {
            char str[] = "Incorrect column index, returning...\n";
            ft_putstr(str);
            return 0;
        }
        //Run one iteration.
        result = ft_queen_solver(column, queens, size);
        //If result is 0, backtrack.
        if(result == SOLVE_BACKTRACK)
        {
            column -= 1;
        }
        //If result is 1, go deeper.
        else if(result == SOLVE_ADVANCE)
        {
            column += 1;
        }
        else if(result == SOLVE_BACKTRACK_AFTER_SOLUTION || result == SOLVE_CONTINUE_COLUMN)
        {
            *solution_count += 1;
            char msg[] = "\nFound solution, count is: ";
            ft_putstr(msg);
            ft_putnbr(*solution_count);
            write(1, "\n", 1);
            //If result is 3, backtrack from correct solution.
            if(result == SOLVE_BACKTRACK_AFTER_SOLUTION)
            {
                column -= 1;
            }
            //If result is 2, loop was successfully completed, try other options in the last column.
            else
            {
                continue;
            }
        }
    }
    //If result is -1, backtracking is complete, loop is broken, return 0.
    return 0;
}
void ft_ten_queens_puzzle(void)
{
    int solution_count = 0;
    int queens[10];
    int result = 0;
    queens[0] = 0;
    //Initialize array//.
    for(int i = 1; i < 10; ++i)
    {
        queens[i] = -1;
    }
    int *ptr = &solution_count;
    result = ft_manage_queen_loop(queens, 10, ptr);
    char line[] = "=====================================";
    ft_putstr(line);
    char msg[] = "Final solution count is: ";
    ft_putstr(msg);
    ft_putnbr(solution_count);
    write(1, "\n", 1);
}
void ft_n_queens_puzzle(int n)
{
    int upper_limit = 13;
    if(n == 0 || n > upper_limit)
    {
        return;
    }
    int solution_count = 0;
    int queens[n];
    int result = 0;
    queens[0] = 0;
    //Initialize array//.
    for(int i = 1; i < n; ++i)
    {
        queens[i] = -1;
    }
    int *ptr = &solution_count;
    result = ft_manage_queen_loop(queens, n, ptr);
    char line[] = "=====================================";
    ft_putstr(line);
    char msg[] = "Final solution count is: ";
    ft_putstr(msg);
    ft_putnbr(solution_count);
    write(1, "\n", 1);
}