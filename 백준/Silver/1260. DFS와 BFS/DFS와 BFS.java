import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.*;

public class Main {

    public static ArrayList<Integer>[] graph;
    public static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int v = Integer.parseInt(st.nextToken());

        graph = new ArrayList[n+1];

        for(int i=1; i<=n; i++){
            graph[i] = new ArrayList<>();
        }

        /* 설명. 간선 입력 */

        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            graph[a].add(b);
            graph[b].add(a);
        }

        for(int i=1; i<=n; i++){
            Collections.sort(graph[i]);
        }

        visited = new boolean[n+1];
        StringBuilder dfsResult = new StringBuilder();
        dfs(v, dfsResult);
        System.out.println(dfsResult);

        visited = new boolean[n+1];
        StringBuilder bfsResult = new StringBuilder();
        bfs(v, bfsResult);
        System.out.println(bfsResult);
    }

    private static void bfs(int start, StringBuilder result){
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(start);
        visited[start] = true;

        while(!queue.isEmpty()){
            int v = queue.poll();
            result.append(v).append(" ");
            for(int neighbor : graph[v]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    queue.offer(neighbor);
                }
            }
        }
    }

    private static void dfs(int v, StringBuilder result){
        visited[v] = true;
        result.append(v).append(" ");
        for(int neighbor : graph[v]){
            if(!visited[neighbor]){
                dfs(neighbor, result);
            }
        }
    }

}



