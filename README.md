# PIPEX

This is an attempt to recreate the behavior of unix pipes using C.

## Known Issues

1. In the child process to pipe the last command to a file, the parsing order should be reversed.
2. Deciding whether I should call `handle_error(states)` in the safe_executor.c or to pass the error out and call it in parent.c