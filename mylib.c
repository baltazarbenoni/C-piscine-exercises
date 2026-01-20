
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
    int index = 0;
    int reverse_start = 0;

    if (nb == -2147483648) //INT_MIN
    {
        write(1, "-2147483648", 11);
        return;
    }
    if(nb < 0)
    {
        buff[index] = '-';
        ++index;
        reverse_start = 1;
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
            buff[index] = '0' + (nb % 10);
            nb /= 10;
            ++index;
        }
    }
    //reverse order.
    for(int j = reverse_start, i = index - 1; j <= (float)(index / 2); ++j, --i)
    {
        char temp = buff[i];
        buff[i] = buff[j];
        buff[j] = temp;
    }
    write(1, &buff, index);
    write(1, "\n", 1);
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
//Using merge-sort to solve the exercise.
#define MIN(a,b) ((a)<(b)?(a):(b)) 

void copy_array(int *copied, int *destination, int size, int start_index)
{
    for(int i = 0; i < size; ++i)
    {
        destination[start_index + i] = copied[i];
    }
}
void merge(int *left, int left_size, int *right, int right_size, int *result, int result_size)
{
    int full_size = left_size + right_size;
    if(result_size < full_size || full_size < 1)
    {
        return;
    }
    //===================================================
    //Handle empty arrays.
    if(left_size < 1)
    {
        copy_array(right, result, right_size, 0);
        return;
    }
    if(right_size < 1)
    {
        copy_array(left, result, left_size, 0);
        return;
    }
    //===================================================
    //Handle merge when both arrays are longer than 0.
    int left_index = 0;
    int right_index = 0;
    while(right_index < right_size && left_index < left_size)
    {
        if(left[left_index] >= right[right_index])
        {
            result[right_index + left_index] = right[right_index];
            ++right_index;
        }
        else
        {
            result[right_index + left_index] = left[left_index];
            ++left_index;
        }
    }
    //===================================================
    //Drain the remaining values into the result if one array is exhausted.
    if(left_index == left_size)
    {
        while(right_index < right_size)
        {
            result[right_index + left_index] = right[right_index];  
            ++right_index;
        }
    }
    else
    {
        while(left_index < left_size)
        {
            result[right_index + left_index] = left[left_index];  
            ++left_index;
        }
    }
}
void iterate_merge(int step_size, int *buffer, int *left_buffer, int *right_buffer, int *result, int size)
{
    if(step_size >= size)
    {
        return;
    }
    int left_index = 0;
    int right_index = left_index + step_size;
    int buffer_start_index = 0;
    while(buffer_start_index < size)
    {
        //=============================
        //If buffer bounds exceeded --> return.
        if(left_index >= size)
        {
            break;
        }
        //==============================
        //Copy left block from buffer.
        int left_block_length = MIN(step_size, size - left_index);
        for(int i = 0; i < left_block_length; ++i)
        {
            left_buffer[i] = buffer[left_index + i];
        }
        //==============================
        //If right index exceeds the bounds of the buffer, copy left block to result and return.
        int right_block_length = 0;
        if(right_index >= size)
        {
            for(int i = 0; i < left_block_length; ++i)
            {
                buffer[buffer_start_index + i] = left_buffer[i];
            }
            buffer_start_index += left_block_length;
            break;
        }
        //==============================
        //Get right block.
        right_block_length = MIN(step_size, size - right_index);
        for(int i = 0; i < right_block_length; ++i)
        {
            right_buffer[i] = buffer[right_index + i];
        }
        //==============================
        //Merge and sort the two copied arrays
        int merge_block_length = left_block_length + right_block_length;
        merge(left_buffer, left_block_length, right_buffer, right_block_length, result, merge_block_length);
        //==============================
        //Copy the merged array to buffer
        for(int i = 0; i < merge_block_length; ++i)
        {
            buffer[buffer_start_index + i] = result[i];
        }
        buffer_start_index += merge_block_length;
        //=============================
        //Increase indices.
        left_index = buffer_start_index;
        right_index = left_index + step_size;
        //================================
    }
}
//Merge-sort function to sort small arrays (arrays allocated on stack).
void ft_sort_int_tab(int *buffer, int size)
{
    int result[size];
    int left_buffer[size];
    int right_buffer[size];
    int step_size = 1;
    while(step_size < size)
    {
        iterate_merge(step_size, buffer, left_buffer, right_buffer, result, size);
        step_size *= 2;
    }
}
void print_sorted_array(int *ar, int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("%d", ar[i]);
        if(i < size - 1)
        {
            printf(", ");
        }
    }
}

void ft_putstr(char *str)
{
    int length_counter = 0;
    while(str[length_counter] != '\0') 
    {
        ++length_counter;
    }
    write(1, str, length_counter);
}
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
int is_alphanumeric(char c)
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
        if((c >= 'a' && c <= 'z') && !(is_alphanumeric(str[index - 1])))
        {
            str[index] ^= 0x20;
        }
        else if((c >= 'A' && c <= 'Z') && is_alphanumeric(str[index - 1]))
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
