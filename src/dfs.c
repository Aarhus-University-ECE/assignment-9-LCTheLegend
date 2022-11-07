/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"


void DFT (node * root)
{
	// Implement DFS
  stack *DFS; //creates the stack necessary
  DFS = push(DFS, root);
  while(isEmpty(DFS) != true) //runs until the stack is empty again
  {
  node *temp = top(DFS); //creates temp node pointing to the top element of stack DFS
  DFS = pop(DFS); //then pops first element of stack
  printf("%d, ", temp -> num); //prints current number, not necessary, but good for visualization of path thorugh tree
  if(temp -> lchild != NULL) 
  {
    DFS = push(DFS, temp -> rchild);
    DFS = push(DFS, temp -> lchild);
  } //this loop adds right child and left child to the stack if the current node is not a leaf
  }
  
	// Hint: You can use print_node, print_tree and/or print_stack.
}

node *make_node (int num, node * left, node * right)
{
  node *new = malloc(sizeof(node)); //allocates memory for new node
  new -> num = num;
  new -> visited = false;
  new -> lchild = left;
  new -> rchild = right;
  return new;
}

void free_node (node * p)
{
	
}


void print_node (node * p)
{

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}


void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}


stack *push (stack * topp, node * node)
{
  stack *new = malloc(sizeof(stack)); //allocates memory for new node
  new -> next = topp; //puts new into the list
  topp = new; //makes topp point to the new first element
  topp -> node = node;

	return topp;
}

bool isEmpty (stack *topp)
{
  return(topp == NULL);
}

node *top (stack * topp)
{
	return topp -> node; //returns top node in stack
}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack * topp)
{
  stack *temp = topp; //creates temp pointer for further freeing
  topp = topp -> next; //sets topp to next element, essentially removing the top element
  free(temp);
  return topp;
	
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}
