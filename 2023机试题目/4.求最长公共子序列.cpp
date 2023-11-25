#include <stdio.h>
#include <string.h>

// 动态规划函数，返回最长公共子序列的长度
int longestCommonSubsequence(char* text1, char* text2) {
    int m = strlen(text1);
    int n = strlen(text2);

    // 创建二维数组用于存储中间结果
    int dp[m + 1][n + 1];

    // 初始化第一行和第一列
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    // 返回最终结果
    return dp[m][n];
}

int main() {
    char text1[] = "abcde";
    char text2[] = "ace";

    int result = longestCommonSubsequence(text1, text2);

    printf("Length of Longest Common Subsequence: %d\n", result);

    return 0;
}

