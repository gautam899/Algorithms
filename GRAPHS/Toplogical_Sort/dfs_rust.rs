fn dfs(node: usize, adj: &[Vec<usize>], visited: &mut [bool], ans: &mut Vec<usize>) {
    visited[node] = true;

    for &neighbor in &adj[node] {
        if !visited[neighbor] {
            dfs(neighbor, adj, visited, ans);
        }
    }
    ans.push(node);
}
fn main() {
    let edges = vec![(0, 1), (0, 2), (1, 2), (2, 3)];
    let v: usize = 4;

    let mut adj = vec![vec![]; v];

    for &(u, v) in &edges {
        adj[u].push(v);
    }

    let mut visited: Vec<bool> = vec![false; v];
    let mut ans = Vec::new();
    for node in 0..v {
        if !visited[node] {
            dfs(node, &adj, &mut visited, &mut ans);
        }
    }
    ans.reverse();
    println!("Printing Topological Sort: ");
    for i in 0..ans.len() {
        println!("{} ", ans[i]);
    }

    // Time complexity: O(V+E)
}
