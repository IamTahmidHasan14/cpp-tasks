#include
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;
int count, flag;
struct vertex {​​​
    int v;
    int d, color;
    int finish, discovery;
    vertex *parent;

    vertex() {​​​
        parent = NULL;
    }​​​
    vertex(int v) {​​​
        this->v = v;
        parent = NULL;
    }​​​
}​​​;
struct graph {​​​
    vertex *vertices;
    int n_v;
    vector *adj_list;
    bool is_directed;
    int time;

    graph(int n_v, bool is_directed) {​​​
        this->n_v = n_v;
        this->is_directed = is_directed;
        vertices = new vertex[n_v];
        for(int i = 0; i < n_v; ++i) vertices[i] = vertex(i);
        adj_list = new vector[n_v];
    }​​​
    void add_edge(int u, int v) {​​​
        vertex v_ = vertex(v);
        adj_list[u].push_back(v_);
        if(!is_directed) {​​​
            vertex u_ = vertex(u);
            adj_list[v].push_back(u_);
        }​​​
    }​​​
    void vis_graph() {​​​
        for(int i = 0; i < n_v; ++i) {​​​
            int n = adj_list[i].size();
            printf("%d-> ", i);
            for(int j = 0; j < n; ++j)
                printf("%d-> ", adj_list[i][j].v);
            printf("\n");
        }​​​
    }​​​
    void dfs() {​​​
        for(int i = 0; i < n_v; ++i) {​​​
            vertices[i].color = WHITE;
            vertices[i].parent = NULL;
        }​​​
        time = 0;
        for(int i = 0; i < n_v; ++i)
            if(vertices[i].color == WHITE)
                dfs_visit(vertices[i].v);
    }​​​
    void dfs_visit(int u) {​​​
        ++time;
        vertices[u].discovery = time;
        vertices[u].color = GRAY;
        printf("%d ", u);
        int n = adj_list[u].size();
        for(int i = 0; i < n; ++i) {​​​
            int v = adj_list[u][i].v;
            if(vertices[v].color == WHITE) {​​​
                vertices[v].parent = &vertices[u];
                dfs_visit(v);
            }​​​
            else flag++;
        }​​​
        vertices[u].color = BLACK;
        ++time;
        vertices[u].finish = time;
        count++;
    }​​​
    void print_dfs() {​​​
        for(int i = 0; i < n_v; ++i)
            if(vertices[i].parent != NULL)
                printf("v.d=%d v.f=%d v.pie=%d\n", vertices[i].discovery, vertices[i].finish, vertices[i].parent->v);
            else
                printf("(root)v.d=%d v.f=%d\n", vertices[i].discovery, vertices[i].finish);
    }​​​
}​​​;
int main() {​​​
    count=0;
    flag=0;
    freopen("dfs_in.txt", "r", stdin);
    int n_v, n_e;
    scanf("%d%d", &n_v, &n_e);
    graph g(n_v, true);
    for(int i = 1; i <= n_e; ++i) {​​​
        int u, v;
        scanf("%d%d", &u, &v);
        g.add_edge(u, v);
    }​​​
    g.dfs();
    printf("\n");
    g.print_dfs();
    cout<<"There are "<    if(flag==0)
    cout<<"There is no cicle.";
    else
    cout<<"There is cicles.";
    return 0;
}​​​
