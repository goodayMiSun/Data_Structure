#include "ADT_GRAPH.h"

GRAPH* create_graph(){

	GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));

	if( graph == NULL )
		return NULL;

	graph->vertex_list = create_list();

	return graph;
		

}

bool g_insert_vertex(GRAPH* graph, int data){

	VERTEX* new_vertex = (VERTEX*)malloc(sizeof(VERTEX));

	new_vertex -> data_ptr = data;
	new_vertex -> arc_list = create_list();

	int vertex_loc = find_vertex(graph->vertex_list, new_vertex);
	
	if(vertex_loc != -1)
		return false;

	return add_node_at(graph->vertex_list, graph->vertex_list->count, &(new_vertex-> data_ptr));

}

int find_vertex( LLIST* list, void* search_data){

	list->pos = list->front;
	int iter_i=0;

	while(list->pos != NULL) {

		VERTEX* left = (VERTEX*)(list->pos->data_ptr);
		VERTEX* right = (VERTEX*) search_data;

		if(left->data_ptr == right->data_ptr)
			return iter_i;

		list->pos = list->pos->next;
		iter_i++;

	}

	return -1;


}

bool g_insert_arc (GRAPH* graph, int from, int to){

	VERTEX temp_vertex1;
	temp_vertex1.data_ptr = from;
	temp_vertex1. arc_list = NULL;

	int vertex_loc = find_vertex (graph->vertex_list, &temp_vertex1);

	if( vertex_loc == -1){
		printf("from_vertex %c : not found \n", (char)from);
		return false;
	}

	VERTEX* from_vertex = (VERTEX*) get_data_at(graph->vertex_list, vertex_loc);

	VERTEX temp_vertex2;
	temp_vertex2.data_ptr = from;
	temp_vertex2. arc_list = NULL;

	vertex_loc = find_vertex (graph->vertex_list, &temp_vertex2);

	if( vertex_loc == -1){
		printf("from_vertex %c : not found \n", (char)from);
		return false;
	}

	from_vertex = (VERTEX*) get_data_at(graph->vertex_list, vertex_loc);

}



void* get_date_at (LLIST* list, unsigned int index){

	if( index >= list->count)
		return NULL;

	list->pos = list->front;
	int iter_i = 0;

	while(list->pos != NULL){

		if( iter_i == index )
			return list->pos->data_ptr;

		list->pos = list->pos->next;
		iter_i++;

	}

	return NULL;

}
