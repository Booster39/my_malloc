# my_malloc
Recoding the C malloc function which allocates the requested memory and returns a pointer to it
How it works:

```link
https://en.cppreference.com/w/c/memory/malloc
```

# USAGE
First, you have to get the owner rights of the exec.sh file. In order to do that, tap the following command your Command Line Interface:
```bash
chmod exec.sh 755
```

Once the first step is done, we are now able to execute the program with a command like: 

```bash 
./exec.sh [Files or "Command with double quotes"]
```

For example, I am executing a command that shows rights of each files and folders of the computer, last time they were modified,
group and user names, and other things, all that in a recursive way:

```bash
./exec.sh "ls -lRt /"
```
# Advice

If you want to see the memory activity of the my_malloc program in your computer, open a new window in your shell and tap:

```bash
htop
```
Watch how the program is playing with the memory, you will see allocation and de-allocation of blocks.
Just amazing how your memory is alive!

# Go
Let's have Fun and enjoy !
