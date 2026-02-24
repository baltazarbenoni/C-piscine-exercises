#!/bin/bash
cd srcs && gcc -c -g *.c && ar cr libft.a *.o  && cd ..
