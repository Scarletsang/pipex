# PIPEX

This is an attempt to recreate the behavior of unix pipes using C.

## Known Issues

1. Lexer not working, error log:

```
AddressSanitizer:DEADLYSIGNAL
=================================================================
==17526==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000 (pc 0x0001078392f2 bp 0x7ffee83c7430 sp 0x7ffee83c73f0 T0)
==17526==The signal is caused by a READ memory access.
==17526==Hint: address points to the zero page.
    #0 0x1078392f2 in ignore_spaces consumer.c:62
    #1 0x107838f1e in lex_command lexer.c:52
    #2 0x10783ac45 in parse_command parse_inputs.c:20
    #3 0x10783bad1 in safe_execve_from_states safe_executor.c:38
    #4 0x10783b72d in run_command child.c:49
    #5 0x10783b92e in fork_command parent.c:33
    #6 0x10783bd5d in main pipex_main.c:33
    #7 0x7fff7196ccc8 in start+0x0 (libdyld.dylib:x86_64+0x1acc8)

==17526==Register values:
rax = 0x0000000000000000  rbx = 0x00007ffee83c7480  rcx = 0x0000000000000000  rdx = 0x0000100000000000  
rdi = 0x00007ffee83c7400  rsi = 0x0000100000000000  rbp = 0x00007ffee83c7430  rsp = 0x00007ffee83c73f0  
 r8 = 0x0000200000000000   r9 = 0x0000000000000000  r10 = 0xffffffffffffffff  r11 = 0x00000fffffffffff  
r12 = 0x0000000000000000  r13 = 0x0000000000000000  r14 = 0x0000000000000000  r15 = 0x0000000000000000  
AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV consumer.c:62 in ignore_spaces
==17526==ABORTING
```