The aim of this project is to make you code a function that returns a line, read from a file descriptor.

roadmap of the project:
#Since we are working with strings, i started considering what functions i probably would use.
___________________________________________________________________________________________
.strlen - man strlen

.strchr - man strchr

.strjoin - libft project

.get_next_line - This function takes an opened file descriptor and returns its next line.

.get_line - Takes the opened file descriptor and saves on a buffer variable what readed from it. Then joins it to the cumulative static variable for the persistence of the information.

.read_line - Extracts the line  from static variable.

.save_line - Stores in the cumulative static variable the new updated variable with whatever is left from the original, minus the line extracted.

___________________________________________________________________________________________
Basic routine GNL:

  char		*line;
  static char	*next_line;

  line = NULL;

  if (fd < 0 || BUFFER_SIZE <= 0)
		  return (0);

  next_line = get_line(next_line, fd): This line is responsible to pick what was passsed by fd and save it on a buffer so we can use the information later.

  if (next_line == NULL): Just a basic verification for NULL
		return (NULL);

  line = ft_read_line(next_line): This line will extract the content stored in next_line
  
  if (line[0] == '\0')
	{
		
   free(next_line);
		  
   free(line);
		  
   return (NULL);
	
  }
	
  return (line);

}
  
  In this part, we check if line[ has reached to \0, if this is the case, we free next line and line and then we return NULL, otherwise, return line
