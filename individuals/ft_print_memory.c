#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "io_utils.h"

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
void long_dec_to_hex(unsigned long long dec, char *hex);
void short_dec_to_hex(int dec, char *hex);
void print_one_line_memory(void *addr, int block_start, int block_end, int line_size);

#define MIN(a,b) ((a)<(b)?(a):(b)) 
void *ft_print_memory(void *addr, unsigned int size)
{
    unsigned block_start = 0;
    unsigned line_size = 16;
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
int main()
{
    //char mem_test[] = "Bonjour les amin";
    char mem_test1[] = "Bonjour les aminches...c'est fou tout ce qu on peut fare avec ..print_memory..lol..xDDD.. ahaha חדלגחדשלחכ";
    int length = strlen(mem_test1);
    ft_print_memory(mem_test1, length);
    return 0;
}