class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        rows, cols = len(matrix), len(matrix[0])
        max_seq = 0

        dp = {}
        
        def check(r: int, c: int) -> bool:
            if (0 <= r < rows) and (0 <= c < cols):
                return True
            return False

        dirs = [(0,1), (1,0), (-1,0), (0,-1)]
        def dfs(sr: int, sc: int):
            if (sr,sc) in dp:
                return dp[(sr,sc)]
            res = 1
            for d1, d2 in dirs:
                nr, nc = sr + d1, sc + d2
                if not check(nr, nc):
                    continue
                if matrix[nr][nc] > matrix[sr][sc]:
                    res = max(res, 1 + dfs(nr,nc))

            dp[(sr,sc)] = res
            return res

                
        for i in range(rows):
            for j in range(cols):
                max_seq = max(max_seq, dfs(i, j))
       

        return max_seq