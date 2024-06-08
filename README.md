# Simple_Text_Editor_C

## Explanation

### `read()` Declaration 

`read (int __fd, void *__buf, size_t __nbytes)`

This function requires three arguments:
1. **1st argument**: standard file I/O
2. **2nd argument**: address buffer
3. **3rd argument**: number of bytes required to read

Here we are using this function like below with arguments:

`read(STDIN_FILENO, &c , 1);`

- **STDIN_FILENO**: standard input file
- **&c**: 1-byte buffer 
- **1**: buffer size

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

### Fixing Terminal Echo Issues

After a program quits, your terminal may not echo what you type. Press **Ctrl-C**, then type `reset` and press **Enter**. If that fails, restart your terminal emulator.

### Modifying Terminal Attributes

You can read terminal attributes into a `termios` struct using `tcgetattr()`. After modifying them, apply the changes with `tcsetattr()`. Using `TCSAFLUSH` ensures all pending output is written and discards unread input.

### Disabling Raw Mode at Exit

Let’s be nice to the user and restore their terminal’s original attributes when our program exits. We’ll save a copy of the `termios` struct in its original state, and use `tcsetattr()` to apply it to the terminal when the program exits.

To restore the terminal's original attributes when our program exits, we use `atexit()` from `<stdlib.h>`. This registers our `disableRawMode()` function to be called automatically when the program exits, ensuring the terminal attributes are restored.

We store the original terminal attributes in a global variable, `orig_termios`. We copy `orig_termios` to `raw` before making changes. Using `TCSAFLUSH` with `tcsetattr()` discards any unread input before applying changes, preventing leftover input from being fed into the shell after the program quits.

### Understanding ICANON

`ICANON` comes from `<termios.h>`. Input flags, which are found in the `c_iflag` field, generally start with `I` like `ICANON`. However, `ICANON` is a "local" flag in the `c_lflag` field, which can be confusing.

Now, the program will quit as soon as you press `q`.

### Enabling Raw Mode

`void enableRawMode()` 

structure defined in termino.h raw is a varibale for structure, tcgettattr(STDIN_FILENO, &raw) p
arameter associate with termial gets back and pass to a structure variable of struct terminos
terminos struct contains input mode flag, aoutput mode flags, control mode flags 

# Fixing Terminal Echo Issues

After a program quits, your terminal may not echo what you type. Press **Ctrl-C**, then type `reset` and press **Enter**. If that fails, restart your terminal emulator.

# Modifying Terminal Attributes

You can read terminal attributes into a `termios` struct using `tcgetattr()`. After modifying them, apply the changes with `tcsetattr()`. Using `TCSAFLUSH` ensures all pending output is written and discards unread input.

## Disabling Raw Mode at Exit

Let’s be nice to the user and restore their terminal’s original attributes when our program exits. We’ll save a copy of the `termios` struct in its original state, and use `tcsetattr()` to apply it to the terminal when the program exits.

To restore the terminal's original attributes when our program exits, we use `atexit()` from `<stdlib.h>`. This registers our `disableRawMode()` function to be called automatically when the program exits, ensuring the terminal attributes are restored.

We store the original terminal attributes in a global variable, `orig_termios`. We copy `orig_termios` to `raw` before making changes. Using `TCSAFLUSH` with `tcsetattr()` discards any unread input before applying changes, preventing leftover input from being fed into the shell after the program quits.

### Understanding ICANON

`ICANON` comes from `<termios.h>`. Input flags, which are found in the `c_iflag` field, generally start with `I` like `ICANON`. However, `ICANON` is a "local" flag in the `c_lflag` field, which can be confusing.

Now, the program will quit as soon as you press `q`.


