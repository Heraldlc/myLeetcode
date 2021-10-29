class UF {
    private:
        int count;
        vector<int> parent;
        vector<int> size;

    public:
        UF(int n) {
            this->count = n;
            parent.resize(n);
            size.resize(n);
            for(int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        // 将 p 和 q 相连通
        void addUnion(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            if(rootP == rootQ) {
                return;
            }

            if(size[rootP] < size[rootQ]) {
                parent[rootP] = rootQ;
                size[rootQ] += size[rootP];
            }
            else {
                parent[rootQ] = rootP;
                size[rootP] += size[rootQ];
            }
        }

        // 判断p和q是否连通
        bool isConnect(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            return rootP == rootQ;
        }

        // 查找根节点
        int find(int x) {
            while(parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        // 返回连通分量的个数
        int count() {
            return count;
        }
    };