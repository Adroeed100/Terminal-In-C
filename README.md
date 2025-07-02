# 🖥️ Terminal-In-C

A simple command-line interface built in C that supports basic commands like `mkfile`, `exit`, and more to come.

## 🚀 Features

- `mkfile <filename>`: Creates a new file with the specified name and lets you enter its content.
- `exit`: Exits the program.
- (More commands like `mkdir`, `ls` can be easily added — code is designed to scale!)

## 🛠️ How to Compile

You can compile the program using GCC:

```bash
gcc terminal.c -o terminal
```

On Windows (to create a `.exe` file):

```bash
gcc terminal.c -o terminal.exe
```

## ▶️ How to Run

After compiling, run the program from your terminal:

```bash
./terminal
```

or (on Windows):

```bash
terminal.exe
```

Example usage:

```
>>> mkfile Adroeed.txt
Enter the text 
Hello from my new file!
File 'Adroeed.txt' has been created
```

#### ⚠️ Only tested on Windows. Linux/macOS users should build from source.


## 💡 Future Improvements (Todo)

- [ ] Add `mkdir` command to create directories  
- ✅ Add `ls` command to list files  
- [ ] Add `readfile` to display file contents  
- [ ] Support multi-line file input  
- [ ] Command history or autocomplete

