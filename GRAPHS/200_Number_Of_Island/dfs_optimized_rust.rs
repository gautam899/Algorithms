fn dfs(r: usize, c: usize, grid: &mut Vec<Vec<char>>) {
    let delr: [isize; 4] = [-1, 0, 1, 0];
    let delc: [isize; 4] = [0, 1, 0, -1];
    let rows = grid.len() as isize;
    let cols = grid[0].len() as isize;
    grid[r as usize][c as usize] = '0';
    for i in 0..4 {
        let nr = r as isize + delr[i];
        let nc = c as isize + delc[i];
        let condition: bool = (nr >= 0)
            && (nr < rows)
            && (nc >= 0)
            && (nc < cols)
            && (grid[nr as usize][nc as usize] == '1');
        if condition == true {
            dfs(nr as usize, nc as usize, grid);
        }
    }
}
fn number_of_island(grid: &mut Vec<Vec<char>>) -> i64 {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut count = 0;
    // println!("Rows: {}", rows);
    // println!("Cols: {}", cols);
    for r in 0..rows {
        for c in 0..cols {
            if grid[r as usize][c as usize] == '1' {
                // println!("r: {}, c: {}", r, c);
                count += 1;
                dfs(r, c, grid);
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
