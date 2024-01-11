# Helper

Command line modified sort command.

![helper](https://skokotos.com/images/helper.png)

## Important

**Helper** has not produced any errors so far on UNIX systems. It has been designed and tested on Ubuntu Flavour version 23.10 x86_64.

If you face a situation full of errors, please contact the maintainers. 

## Table of Contents
<!-- vim-markdown-toc Marked -->

* [Features](#features)
* [Requirements](#requirements)
* [Installation](#installation)
* [Basic usage](#basic-usage)
* [Alternative usage (Optional)](#alternative-usage-optional)
* [Error codes](#error-codes)
* [Reporting bugs](#reporting-bugs)
* [License](#license)
* [Authors](#authors)

<!-- vim-markdown-toc -->

## Features

**Helper** provides the following features:

 - Display the contents of a given file sorted on the standard output.
 -  Easy error detection.
 
## Requirements
* Unix based OS's

  - GCC Compiler
  - makefile

## Installation

Clone the above repository locally on your computer, open the src folder, run the command 'make' in the terminal, and finally, execute the command `./helper`.

## Basic usage

After a successful cloning and compiling, the command to execute it:

    ./helper

This will display the usage of helper program's window with a list of options.

![Usage](https://skokotos.com/images/usage2.png)

## Alternative usage (Optional)

If you prefer not to use the command via `./helper`, there is also an alternative usage:

  - You need to save the `src` folder to a specific location within your system where you believe it won't be altered.

  - Open the terminal within the directory `src` and issue the following command `pwd`, it will display the current working directory, showing the full path.

  - Copy the full path that the terminal displayed to you and open another terminal window.

  - Issue the command: `nano ~/.bashrc` to insert the path from the helper file.

  - Insert the following command at the end of the file (.bashrc): `export PATH=$PATH:/home/username/helper`

**Warning:** You need to replace the username with the name you are using!

  - After issuing the above command, press `CTRL + O` to save, then press `ENTER`, and finally, press `CTRL + X` to exit the .bashrc file.

  - Finally, execute the following command: `source ~/.bashrc` to update the .bashrc file so that you can run the `helper` command.

## Error codes

**Helper** has an integrated error system with numerical codes. Each code corresponds to a string explaining the error. Below, you will find the table of possible errors:

| Exit code | Description |
| :---------: |  :---------:  |
|     0     |   SUCCESS   |
|     1     |EMPTY_FILEFILE_ERROR|
|     2     |ARGUMENT_ERROR|
|     3     |PIPE_CREATION_ERROR|
|     4     |FORK_ERROR|
|     5     |DUP_ERROR|
|     6     |EXEC_ERROR|
|     7     |READ_ERROR|
|     8     |WRITE_ERROR|
|     9     |CHILD_EXIT_ERROR|
|    10     |WAIT_ERROR|

**Exit Code 0:** If your program returns exit code 0 after execution, it means that it ran without any issues. :D

**Exit Code 1:** If your program returns exit code 1 after execution, it means that it refers to the case where the given file is empty. There is no reason to execute the program on an empty file.

**Exit Code 2:** If your program returns exit code 2 after execution, it means that it corresponds to an incorrect number of arguments during program execution. The accompanying message informs the user about the correct usage of the program.

**Exit Code 3:** If your program returns exit code 3 after execution, it means that it pertains to an issue encountered during the creation of a pipe. It displays a message regarding the failure to create the pipe.

**Exit Code 4:** If your program returns exit code 4 after execution, it means that it refers to an error that occurred during the creation of a new process using fork(). It displays a message regarding the failure to create the new process.

**Exit Code 5:** If your program returns exit code 5 after execution, it means that if there is an issue during the creation of a new copy of a file descriptor using dup2(), it displays a message regarding the failure of the copy process.

**Exit Code 6:** If your program returns exit code 6 after execution, it means that it concerns any error during the execution of a new command using execlp(). It displays a message regarding the failure to execute the command.

**Exit Code 7:** If your program returns exit code 7 after execution, it means that if there is an issue while reading data from the pipe, it displays a message regarding the failure of data reading.

**Exit Code 8:** If your program returns exit code 8 after execution, it means that it refers to any problem during the writing of data to a pipe or any other write process. It displays a message regarding the failure of the writing process.

**Exit Code 9:** If your program returns exit code 9 after execution, it means that it refers to cases where the child process terminates with a non-zero exit code. It displays a message indicating that the child process terminated with an error.

**Exit Code 10:** If your program returns exit code 10 after execution, it means that it refers to any problem encountered while waiting for the completion of the child process using wait(). It displays a message regarding the failure of the waiting process.

## Reporting bugs


When a bug is found, please do report it by [opening an issue at github](https://github.com/Greekforce1821/helper/issues), as already stated above.

In your report you should, at the very least, state your **Linux version**, **GCC version**, **Kernel version** and **CPU version (x86 or x64)** of installation.

A simple screenshot of your terminal output would be preferable by issuing the following command: `neofetch`

![Neofetch output](https://skokotos.com/images/neofetch.png)

**Warning:** As you can see in the above screenshot, it does not include the correct information required because the program is running on a virtual machine and cannot display the real components of the computer.


## License

MIT License

Copyright (c) 2023 Spyridon Eftychios Kokotos & Christos Spyridon Karydis

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


## Authors

The above program is a creation of Spyros Kokotos - inf2021098@ionio.gr & Christos Karydis - inf2022076@ionio.gr, and you can use it for your personal projects or further develop it as long as you always give credit to the creators.



