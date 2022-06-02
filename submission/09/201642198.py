from copy import deepcopy


def main():
    def get_max_res(lp: int, rp: int) -> int:
        res_list = []
        for k in range(lp, rp):
            if opr_list[k] == '+':
                res_list.append(max_dp[lp][k] + max_dp[k+1][rp])
            elif opr_list[k] == '-':
                res_list.append(max_dp[lp][k] - min_dp[k+1][rp])
            else:
                res_list.extend([max_dp[lp][k] * max_dp[k+1][rp],
                                 min_dp[lp][k] * min_dp[k+1][rp]])
        return max(res_list)

    def get_min_res(lp: int, rp: int) -> int:
        res_list = []
        for k in range(lp, rp):
            if opr_list[k] == '+':
                res_list.append(min_dp[lp][k] + min_dp[k+1][rp])
            elif opr_list[k] == '-':
                res_list.append(min_dp[lp][k] - max_dp[k+1][rp])
            else:
                res_list.extend([max_dp[lp][k] * min_dp[k+1][rp],
                                 min_dp[lp][k] * max_dp[k+1][rp],
                                 min_dp[lp][k] * min_dp[k+1][rp]])
        return min(res_list)

    inp_char_list = list(input().split())
    digit_list = [int(char) for idx, char in enumerate(inp_char_list) if idx % 2 == 0]
    opr_list = [char for idx, char in enumerate(inp_char_list) if idx % 2 != 0]

    min_dp = [[0 for row in range(len(digit_list))] for col in range(len(digit_list))]
    for i, digit in enumerate(digit_list):
        min_dp[i][i] = digit
    max_dp = deepcopy(min_dp)

    for num_opr in range(1, len(opr_list) + 1):
        for left in range(len(digit_list) - num_opr):
            right = left + num_opr
            max_dp[left][right] = get_max_res(left, right)
            min_dp[left][right] = get_min_res(left, right)

    print(max_dp[0][len(digit_list)-1])


if __name__ == '__main__':
    main()
