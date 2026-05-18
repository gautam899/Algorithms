use std::collections::VecDeque;

fn bfs(i: usize, j: usize, grid: &mut Vec<Vec<char>>) {
    let rows = grid.len();
    let cols = grid[0].len();
    grid[i][j] = '0';
    let mut queue: VecDeque<(usize, usize)> = VecDeque::new();
    queue.push_back((i, j));

    let delr: Vec<isize> = vec![-1, 0, 1, 0];
    let delc: Vec<isize> = vec![0, 1, 0, -1];
    while !queue.is_empty() {
        let (r, c) = queue.pop_front().unwrap();
        for i in 0..4 {
            let nr = r as isize + delr[i];
            let nc = c as isize + delc[i];
            if nr >= 0
                && nr < rows as isize
                && nc >= 0
                && nc < cols as isize
                && grid[nr as usize][nc as usize] == '1'
            {
                let nr = nr as usize;
                let nc = nc as usize;
                grid[nr][nc] = '0';
                queue.push_back((nr, nc));
            }
        }
    }
}

fn number_of_island(grid: &mut Vec<Vec<char>>) -> u64 {
    let mut count = 0;
    let row = grid.len();
    let col = grid[0].len();

    for r in 0..row {
        for c in 0..col {
            if grid[r][c] == '1' {
                count += 1;
                bfs(r, c, grid);
            }
        }
    }
    count
}

fn main() {
    let mut grid: Vec<Vec<char>> = Vec::new();
    grid = vec![
        vec!['1', '1', '1', '1', '0'],
        vec!['1', '1', '0', '1', '0'],
        vec!['1', '1', '0', '0', '0'],
        vec!['0', '0', '0', '0', '0'],
    ];
    let ans = number_of_island(&mut grid);

    println!("The number of island in the gird is {}", ans);
    return;
}
