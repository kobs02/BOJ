N = int(input())
arr = []
result = {-1:0, 0:0, 1:0 }

for _ in range(N):
    arr.append(list(map(int, input().split())))

def divide(x, y, n):
    num = arr[x][y]
    for i in range(x, x + n):
        for j in range(y, y + n):
            if(arr[i][j] != num):
                div_num = n // 3

                divide(x, y, div_num)
                divide(x, y + div_num, div_num)
                divide(x, y + (2 * div_num), div_num)
                divide(x + div_num, y, div_num)
                divide(x + div_num, y + div_num, div_num)
                divide(x + div_num, y + (2 * div_num), div_num)
                divide(x + (2 * div_num), y, div_num)
                divide(x + (2 * div_num), y + div_num, div_num)
                divide(x + (2 * div_num), y + (2 * div_num), div_num)
                return
    result[num] += 1
    return

divide(0, 0, N)
for i in result.values():
    print(i)