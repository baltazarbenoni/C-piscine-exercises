#ifndef BOOLEAN 
#define BOOLEAN
//==========================
#define EVEN_MSG "I have an even number of arguments."
#define ODD_MSG "I have an odd number of arguments."
//==========================
#define EVEN(nb) ((nb) % 2 == 0 ? TRUE : FALSE)
//==========================
#ifndef SUCCESS
#define SUCCESS 0
#endif
//==========================
typedef enum { FALSE, TRUE } t_bool;
//==========================
#endif

