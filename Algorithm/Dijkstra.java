package Algorithm;

import java.util.*;

public class Dijkstra {

    static int[] dijkstra(List<int[]>[] nodes, int start) {
        int[] result = new int[nodes.length];
        for (int i = 0; i < result.length; i++)
            result[i] = Integer.MAX_VALUE;
        PriorityQueue<int[]> pq = new PriorityQueue<>((x1, x2) -> x1[1] - x2[1]);
        result[start] = 0;
        pq.add(new int[] { start, 0 });
        while (!pq.isEmpty()) {
            int[] v = pq.poll();
            if (v[1] > result[v[0]])
                continue;
            for (int[] n : nodes[v[0]]) {
                int t = v[1] + n[1];
                if (t < result[n[0]]) {
                    result[n[0]] = t;
                    pq.add(new int[] { n[0], t });
                }
            }
        }
        for (int i = 0; i < result.length; i++)
            if (result[i] == Integer.MAX_VALUE)
                result[i] = -1;

        return result;
    }

    public static void main(String[] args) {
        List<int[]>[] list = new List[5];
        for (int i = 0; i < list.length; i++)
            list[i] = new ArrayList<>();
        list[0].add(new int[] { 1, 2 });
        list[1].add(new int[] { 2, 3 });
        list[1].add(new int[] { 4, 1 });
        list[2].add(new int[] { 3, 4 });
        list[3].add(new int[] { 4, 5 });
        list[0].add(new int[] { 3, 3 });
        int[] distances = dijkstra(list, 0);
        for (int i = 0; i < distances.length; i++) {
            System.out.printf("Node %d: %d\n", i, distances[i]);
        }
    }
}
