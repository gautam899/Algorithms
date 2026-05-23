use std::collections::VecDeque;

fn find_toposort(v: usize, edges: &Vec<Vec<usize>>) -> Vec<usize> {
    let mut ans: Vec<usize> = Vec::new();
    let mut adj: Vec<Vec<usize>> = vec![vec![]; v as usize];
    let mut indegree: Vec<usize> = vec![0; v];
    for i in 0..edges.len() {
        adj[edges[i][0]].push(edges[i][1]);
        indegree[edges[i][1]] += 1;
    } // O(E). Every edge is processed once.

    let mut queue: VecDeque<usize> = VecDeque::new();
    for i in 0..indegree.len() {
        if indegree[i] == 0 {
            queue.push_back(i);
            ans.push(i);
        }
    } // O(V). Every vertex is visited once.

    while !queue.is_empty() {
        let node = queue.pop_front().unwrap();
        for i in 0..(adj[node].len()) {
            let neighbor = adj[node as usize][i as usize];
            indegree[neighbor as usize] -= 1;
            if indegree[neighbor as usize] == 0 {
                queue.push_back(neighbor);
                ans.push(neighbor);
            }
        }
    }
    // For the while loop: Every node goes in the queue exactly once O(V) and inside the for loop every edge is processed once O(E)
    // Hence the time complexity goes O(V+E).
    ans
}
fn main() {
    let mut edges: Vec<Vec<usize>> = vec![vec![0, 1], vec![0, 2], vec![1, 2], vec![2, 3]];
    let v = 4;
    let ans: Vec<usize> = find_toposort(v, &edges);

    for i in 0..ans.len() {
        println!("{} ", ans[i]);
    }
    return;
}
// In the above code, the reason why we keep type of edge value type as usize is to avoid multiple type casting later.
