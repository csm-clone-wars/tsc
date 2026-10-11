# tsc


## Some basic rules followed ragarding dynamic memory
- Free the data structure using its appropriate free function right after you are done with it.
- Set the variable to `NULL` right after free, to avoid double-free error.

## License
Apache 2.0