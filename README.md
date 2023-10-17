# Task Manager

This is a simple command-line task manager program created using the ncurses library in C.

## Features

- Add tasks
- Delete tasks
- View tasks
- Simple UI with a list of tasks

## Usage

- Use the `a` key to add a new task.
- Use the `d` key to delete a task. You will be prompted to enter the task number to delete.
- Use the `q` key to quit the program.

## How to Run

Make sure you have the ncurses library installed. You can compile the program using any C compiler that supports the ncurses library.

### Running on Windows

#### Step 1: Setting up the Compiler

1. Install a C compiler such as MinGW-w64 (for example, using the MSYS2 environment).
2. Ensure that the ncurses library is available. You can use the PDCurses library, which is a public-domain curses library for DOS, OS/2, and Windows console based on the original PDCurses project.

#### Step 2: Compiling the Program

Use the following command to compile the program on Windows:

gcc -o task_manager.exe task_manager.c -lpdcurses


#### Step 3: Running the Program

Run the executable by typing:

task_manager.exe



### Running on Linux

#### Step 1: Setting up the Compiler

Most Linux distributions come with the necessary tools for C programming preinstalled. If not, you can install them using your package manager. For example, on Debian-based systems, you can use the following command:

sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install libncurses5-dev libncursesw5-dev


#### Step 2: Compiling the Program

Compile the program using the following command:

gcc -o task_manager task_manager.c -lncurses


#### Step 3: Running the Program

Run the compiled program by typing:

./task_manager



Make sure you have the necessary permissions to execute the file.

## Dependencies

- ncurses library

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements

This program was created with reference to the ncurses library documentation and examples.

For more information on the ncurses library, visit: [https://invisible-island.net/ncurses/](https://invisible-island.net/ncurses/)

## Author

Kumahor Edem Godwin