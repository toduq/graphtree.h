#include "graphtree.h"

int main() {
  graphtree_t graph;
  graphtree_init(&graph, "test.dot");
  graphtree_append(&graph, "parent");
  graphtree_append(&graph, "child");
  graphtree_append(&graph, "grandchild");
  graphtree_up(&graph);
  graphtree_append(&graph, "grandchild2");
  graphtree_up(&graph);
  graphtree_up(&graph);
  graphtree_append(&graph, "child2");
  graphtree_save(&graph);
  return 0;
}
