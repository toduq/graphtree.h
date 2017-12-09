# graphtree.h

[CC0] Header-only c library to visualize DFS(depth-first search) easily with graphviz!

License CC0 by https://github.com/toduq

## HOW TO USE

Just include `graphtree.h`.

### BEFORE

Labeling BEFORE children node search.

```c
#include "graphtree.h"
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
```

Execute `dot -T png before.dot -o before.png`

![/before.png](/before.png)

### AFTER

Labeling AFTER children node search.

```c
#include "graphtree.h"
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
```

Execute `dot -T png after.dot -o after.png`

![/after.png](/after.png)

Actual code is here [/sample.c](/sample.c)
