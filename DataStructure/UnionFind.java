package DataStructure;

public class UnionFind {
    static int[] arr;
    static int[] rank;

    static int find(int x) {
        if (arr[x] == x)
            return x;
        return arr[x] = find(arr[x]);
    }

    static boolean union(int x, int y) {
        int a = find(x);
        int b = find(y);
        if (a == b)
            return false;

        if (rank[a] >= rank[b]) {
            if (rank[a] == rank[b])
                rank[a]++;
            arr[b] = a;
        } else {
            arr[a] = b;
        }
        return true;
    }

    public static void main(String[] args) {
        arr = new int[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        rank = new int[10];

        union(1, 3);
        System.out.println(find(1));
        System.out.println(find(7));
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
    }
}
