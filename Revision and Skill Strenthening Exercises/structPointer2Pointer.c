#include <stddef.h>
#include <stdlib.h>


typedef struct Token {
  char *literal;
  int line;
  int column;
} token_t;

token_t **create_token_pointer_array(token_t *tokens, size_t count);


  // this finction returns a pointer to a pointer to a token_t struct
token_t **create_token_pointer_array(token_t *tokens, size_t count) {


  // this is the new array we are creating. It is assigning an array of pointers to the heap
  token_t **token_pointers = malloc(count * sizeof(token_t *));
  
  if (token_pointers == NULL) 
  {
    exit(1);
  }
  
  for (size_t i = 0; i < count; ++i) 
  {
    //token_pointers[i] = &tokens[i];
    token_pointers[i] = malloc(sizeof(tokens));
    tokens = *token_pointers;
    token_pointers[i]->literal = tokens->literal;
    token_pointers[i]->line = tokens->line;
    token_pointers[i]->column = tokens->column;
  }
  
  return token_pointers;
}

int main()
{
    token_t tokens[3] = {
                     {"foo", 1, 1},
                     {"bar", 2, 5},
                     {"baz", 3, 10},
                 };
    token_t **result = create_token_pointer_array(tokens, 3);
    return 0;
}


