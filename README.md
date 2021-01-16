# Sudoku-Solver

## Main Idea
For each empty grid from number 1 - 9:
<ul>
  <li>Check the corresponded column to see if there's any duplicated numbers.</li>
  <li>Check the corresponded row to see if there's any duplicated numbers.</li>
  <li>Check the corresponded 3 by 3 grid to see if there's any duplicated numbers by taking the remainder of each row and column after dividing by 3.</li>
</ul>
