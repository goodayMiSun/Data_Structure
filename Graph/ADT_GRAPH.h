#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ADT_LLIST.h"

typedef struct {

	LLIST* vertex_list;

} GRAPH;

typedef struct {

	int data_ptr;
	LLIST* arc_list;

}VERTEX;

typedef struct {

	VERTEX to_vertex;

}ARC;

GRAPH* create_graph();

bool g_insert_vertex(GRAPH* graph, int data);
int find_vertex (LLIST* list, void* search_data);
bool g_insert_arc (GRAPH* graph, int from, int to);

void* get_data_at (LLIST* LIST, unsigned int index);

