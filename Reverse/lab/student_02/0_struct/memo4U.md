## gdb

C-x a TUI

## add Symbol

```
$ gcc -g -c type.c
(gdb) add-symbol-file type.o 0
(gdb) p *(struct ss*)$m
```
