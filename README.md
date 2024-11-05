# get_next_line

Create a function that access a file, using a file descriptor, and returns the first line that encounters, 
until a new line is encountered, then it will return each consecutive line until the end of the file. 
If the file is empty, an error occurred, or it already reached the end line, it will return null.
