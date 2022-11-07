#include <stdio.h>
extern "C"{
    // Add the header files required to run your main 
    #include "sum.h"
    #include "search.h"
    #include "dfs.h"
}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    /*
    int a[5] = {10, 12, 53, 23, 91};
    printf("%d\n", sum(a, 5));
    printf("%d", search(a, 5, 52));
    */
   //node *root = make_node(10, make_node(5, NULL, NULL), make_node(6, make_node(3, NULL, NULL), make_node(8, NULL, NULL)));

   node *root1 = make_node (4,
			  make_node (7,
				     make_node (28,
						make_node (77,
							   NULL,
							   NULL),
						make_node (23,
							   NULL,
							   NULL)),
				     make_node (86,
						make_node (3,
							   NULL,
							   NULL),
						make_node (9,
							   NULL,
							   NULL))),
			  make_node (98,
				     NULL,
				     NULL));
	//DFT(root1);
    return 0;
}