# C is a low level language

    char c = *p;

What could be more complicated than a simple pointer dereference?  It might
translate to some innocent looking machine code:

      40122a:       0f b6 00                movzx  eax,BYTE PTR [rax]

But don't let appearances fool you!  On a modern machine, these three bytes can
invoke arbitrary Python code just to read a byte out of memory.  How?

1. `mmap()` can be used to map the contents of a file into memory
2. Linux will not actually read anything from the file before we need to
3. Filesystem-in-userspace (FUSE) is used to implement a file system driver in
   Python

Try it yourself!  Install the Python package `fusepy` and run `fs.py`.  It will
create a directory `fuse-dir`, where all paths are files containing the bytes
`pointer schmointer\n`.  Compile and run `main.c`, and when you hit enter, the C
code will dereference a pointer and Python code will run.

