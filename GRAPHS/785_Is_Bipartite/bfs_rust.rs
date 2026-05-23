use std::collections::VecDeque;

fn bfs(start: usize, adj: &[Vec<usize>], color: &mut Vec<i32>) -> bool {
    let mut queue: VecDeque<usize> = VecDeque::new();
    queue.push_back(start);
    while !queue.is_empty() {
        let node = queue.pop_front().unwrap();
        for &neighbor in &adj[node] {
            if color[neighbor] == -1 {
                color[neighbor] = 1 - color[node];
                queue.push_back(neighbor);
            } else if color[neighbor] == color[node] {
                return false;
            }
        }
    }
    true
}
fn is_bipartite(adj: &[Vec<usize>], v: usize) -> bool {
    let mut color = vec![-1; v];

    for start in 0..v {
        if color[start] == -1 {
            color[start] = 1;
            if !bfs(start, adj, &mut color) {
                return false;
            };
        }
    }
    return true;
}
fn main() {
    let adj: Vec<Vec<usize>> = vec![vec![1, 2, 3], vec![0, 2], vec![0, 1, 3], vec![0, 2]];
    let v = 4;
    let ans: bool = is_bipartite(&adj, v);
    println!("The ans is {}", ans);
    return;
}
