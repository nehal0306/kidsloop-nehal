#include <cmath>
#include <iostream>
#include <vector>

int answer = 0;
const int SIZE = 5000;
int v[2*SIZE][2*SIZE];

const struct {
  int dx;
  int dy;
} moves[] = {
    {1, 0},   // Up
    {-1, 0},  // Down
    {0, -1},  // Left
    {0, 1}    // Right
};

class Solution{
  public: 

    int calc_sum(int n);
    bool isSafe(int x, int y);
    void dfs(int x, int y, int size);

};
int Solution::calc_sum(int n) {
    n = abs(n);
    int sum = 0;
    while (n) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
}

bool Solution::isSafe(int x, int y){
  return (calc_sum(x) + calc_sum(y) <= 23); 
}

void Solution::dfs(int x, int y, int SQUARE_SIDE) {
  // Add SQUARE_SIDE to make indices non-negative.
  v[x + SQUARE_SIDE][y + SQUARE_SIDE] = 1;
  answer++;

  for (const auto &move : moves)
    if (isSafe(x + move.dx, y + move.dy) &&
        !v[x + move.dx + SQUARE_SIDE][y + move.dy + SQUARE_SIDE]) {
      dfs(x + move.dx, y + move.dy, SQUARE_SIDE);
    }


}



int solve(int x, int y, int size) {
  Solution ans;

  ans.dfs(x,y,size);
  std::cout << answer << std::endl;
  return answer;
}