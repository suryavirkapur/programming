def minimum_total(triangle: list[list[int]]) -> int:
    n = len(triangle)

    dp = [[0 for _ in range(n + 1)] for _ in range(n + 1)]
    print(dp)

    for i in range(n - 1, -1, -1):
      for j in range(len(triangle[i])):
        print(i,j)
        dp[i][j] = triangle[i][j] + min(dp[i + 1][j],dp[i+1][j+1])

    return dp[0][0]

if __name__ == "__main__":
    triangle = [[int(x) for x in input().split()] for _ in range(int(input()))]
    res = minimum_total(triangle)
    print(res)
