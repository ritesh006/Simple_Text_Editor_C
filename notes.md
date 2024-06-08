# Explanation

# read() declaration 

`read (int __fd, void *__buf, size_t __nbytes)`

this function requried a 1st argument is standard file I/O, 2nd address buffer, and 3rd is number of bytes 
required to read.

here we are using thi function like below with argument

`read(STDIN_FILENO, &c , 1);`

STDIN_FILENO = standard input file
&c = 1byte buffer 
1 = buffer size

`while(read(STDIN_FILENO, &c , 1) == 1);`
read() returns the number of bytes that it read, and will return 0 when it reaches the end of a file.
so while loop continue unitl its false means O or EOF (end of file)

# Usage of STDIN_FILENO
STDIN_FILENO is commonly used with lower-level I/O functions such as read and write, which operate directly on file descriptors. This is in contrast to higher-level I/O functions like fscanf and fgets, which operate on FILE * streams.


### Entering raw mode

Typical program when we run that time terminal starts in ***conical mode*** also called ***cooked mode*** for taking input like a simple program adding a two number when we press number after pressing ***ENTER*** only it will feed to program but our case its not possible 
we need immedigate response whenver key pressed it has to pass on thats whya we need to enable
***raw mode*** entering in raw mode is not much easy for now if you want to exit you can press
***ctrl + c*** to quit


# Press q to quit?

` while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q'); `
for time being we have added letter or charactor 'q' if you want to exit from file you can press 'q' and hit ***ENTER** 


