# Simple_Text_Editor_C

### Explanation

### `read()` Declaration 

`read (int __fd, void *__buf, size_t __nbytes)`

This function requires three arguments:
1. **1st argument**: standard file I/O
2. **2nd argument**: address buffer
3. **3rd argument**: number of bytes required to read

Here we are using this function like below with arguments:

`read(STDIN_FILENO, &c , 1);`

- **STDIN_FILENO** = standard input file
- **&c** = 1-byte buffer 
- **1** = buffer size

`while(read(STDIN_FILENO, &c , 1) == 1);`

`read()` returns the number of bytes that it read, and will return 0 when it reaches the end of a file. So, the while loop continues until it's false, meaning 0 or EOF (end of file).

### Usage of `STDIN_FILENO`

`STDIN_FILENO` is commonly used with lower-level I/O functions such as `read` and `write`, which operate directly on file descriptors. This is in contrast to higher-level I/O functions like `fscanf` and `fgets`, which operate on `FILE *` streams.

### Entering Raw Mode

Typically, when a program runs, the terminal starts in **conical mode** (also called **cooked mode**) for taking input. For example, in a simple program adding two numbers, when we press a number and then press **ENTER**, it will be fed to the program. However, in our case, we need an immediate response whenever a key is pressed, hence we need to enable **raw mode**. Entering raw mode is not easy, but for now, if you want to exit, you can press **Ctrl + C** to quit.

### Press `q` to Quit

`while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');`

For the time being, we have added the letter or character **'q'**. If you want to exit the file, you can press 'q' and hit **ENTER**.

### Turn off Echoing

`struct termios`, `tcgetattr()`, `tcsetattr()`, `ECHO`, and `TCSAFLUSH` all come from `<termios.h>`. The **ECHO** feature is used when you type anything, it gets back to the terminal and you can see what you are typing. It's very useful for **cooked mode** or **conical mode**.

After enabling the echo mode, you will not see the print on the terminal, like in **Linux** while entering a **password**, it's blank.

After the program quits, depending on your **shell**, you may find your **terminal** is still not **echoing** what you type. Don't worry, it will still listen to what you type. Just press **Ctrl-C** to start a fresh line of input to your shell, and type in **reset** and press **Enter**. This resets your terminal back to normal in most cases. Failing that, you can always restart your **terminal emulator**. We'll fix this whole problem in the next step.
