
/* x: at what length in row
 * y: at what depth in column
 */
void
traverse_surr_sqrs(x, y)
{
  int i = 0;
  int j = 0;
  int c = 0;

  //  Generate x,y coor surrounding [x,y]  
  //  --  Still written in python. Needs translatin'
  for (i=0 in range(max(x - 1, 0), min(x + 2, m)) {
    for j in range(max(y - 1, 0), min(y + 2, n)) {
      if board[i][j] == '*' {
        c += 1;
      }
    }
  }

  return c
}
