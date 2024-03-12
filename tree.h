#include <stdio.h>
#include <stdlib.h>

#define container_of(ptr, type, member) \
    ((type *) ((char *) (ptr) - (size_t) & (((type *) 0)->member)))

#define list_entry(ptr, type, member) container_of(ptr, type, member)

#define hlist_for_each(pos, head) \
    for (pos = (head)->first; pos; pos = pos->next)

struct hlist_node {
    struct hlist_node *next, **pprev;
};
struct hlist_head {
    struct hlist_node *first;
};

static inline void INIT_HLIST_HEAD(struct hlist_head *h);
static inline void hlist_add_head(struct hlist_node *n, struct hlist_head *h);

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct order_node {
    struct hlist_node node;
    int val;
    int idx;
};

static int find(int num, int size, const struct hlist_head *heads);
static struct TreeNode *dfs(int *preorder,
                            int pre_low,
                            int pre_high,
                            int *inorder,
                            int in_low,
                            int in_high,
                            struct hlist_head *in_heads,
                            int size);

static inline void node_add(int val,
                            int idx,
                            int size,
                            struct hlist_head *heads);

static struct TreeNode *buildTree(int *preorder,
                                  int preorderSize,
                                  int *inorder,
                                  int inorderSize);