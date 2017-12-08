#ifndef _GRAPHTREE_H_
#define _GRAPHTREE_H_

// graphtree.h
// Header-only c library to visualize DFS(depth-first search) easily with graphviz!
// License CC0 by https://github.com/toduq

#include <stdio.h>

#define GRAPHTREE_MAX_DEPTH 100

typedef struct graphtree {
  int depth;
  int current_id;
  int stack[GRAPHTREE_MAX_DEPTH];
  FILE *fp;
} graphtree_t;

void graphtree_init(graphtree_t *graph, char *filename) {
  graph->depth = 0;
  graph->stack[0] = 0;
  graph->fp = fopen(filename, "w");
  fputs("digraph G {\n", graph->fp);
  fputs("  rankdir=TB;\n", graph->fp);
}

void graphtree_append(graphtree_t *graph, char *content) {
  graph->stack[graph->depth] = graph->current_id;
  fprintf(graph->fp, "  %d [label = \"%s\"];\n", graph->current_id, content);
  if(graph->depth > 0) {
    fprintf(graph->fp, "  %d -> %d;\n", graph->stack[graph->depth-1], graph->stack[graph->depth]);
  }
  graph->depth++;
  graph->current_id++;
}

void graphtree_up(graphtree_t *graph) {
  graph->depth--;
}

void graphtree_save(graphtree_t *graph) {
  fputs("}", graph->fp);
  fclose(graph->fp);
}

#endif
