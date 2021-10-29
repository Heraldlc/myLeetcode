class UF {
    // 记录连通分量的个数
    private int count;
    // 存储若干树，这是一个一维数组
    private int[] parent;
    // 记录树的重量，方便平衡优化
    private int[] size;

    public UF(int n) {
        this.count = n;
        parent = new int[n];
        size = new int[n];
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // 将 p 和 q 相连通
    public void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ) {
            return;
        }
        // 取重量小的连到重量大的上
        if(size(rootP) < size(rootQ)) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--;
    }

    // 判断 p 和 q 是否是连通的
    public boolean isConnect(int p, int q) {
        // 连通的两个点用拥有相同的根节点
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    // 返回节点的根节点
    public int find(int x) {
        while(parent[x] != x) {
            // 进行了路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    // 返回连通分量的数量
    public int count() {
        retun count;
    }

}