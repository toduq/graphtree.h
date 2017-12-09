#include "graphtree.h"
#include <stdlib.h>
#include <time.h>

void before_labeling() {
  graphtree_t graph;
  graphtree_init(&graph, "before.dot");
  graphtree_down(&graph, "parent");
  graphtree_down(&graph, "child");
  graphtree_down(&graph, "grandchild");
  graphtree_up(&graph);
  graphtree_down(&graph, "grandchild2");
  graphtree_up(&graph);
  graphtree_up(&graph);
  graphtree_down(&graph, "child2");
  graphtree_save(&graph);
}

int after_labeling_search(graphtree_t *graph, int depth) {
  graphtree_enter(graph);
  if(depth==0) {
    int score = rand() % 20;
    graphtree_exit(graph, "%d", score);
    return score;
  } else {
    int max = -1;
    for(int i=0; i<3; i++) {
      int score = after_labeling_search(graph, depth-1);
      if(score > max) max = score;
    }
    graphtree_exit(graph, "%d", max);
    return max;
  }
}

int after_labeling() {
  srand((unsigned)time(NULL));
  graphtree_t graph;
  graphtree_init(&graph, "after.dot");
  after_labeling_search(&graph, 2);
  graphtree_save(&graph);
}

int main() {
  before_labeling();
  after_labeling();
  return 0;
}
