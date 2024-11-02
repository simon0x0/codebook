對拍script
set -e
g++ ac.cpp -o ac
g++ wa.cpp -o wa
for ((i=0;;i++))
do
    echo "$i"
    python3 gen.py > input
    ./ac < input > ac.out
    ./wa < input > wa.out
    diff ac.out wa.out || break
done

產生隨機測資(Python)
from random import *
n = randint(1, 100)                       # 隨機產生 1~100的整數
ch = chr(ord('a') + randint(0, 25))       # 隨機產生 'a'~'z' 其中一個字元
choiceSet = sample(s, 4)                  # 從集合 s 選出 4 個不同的元素
choiceSet = sample(range(1, n+1), 4)      # 從整數 1~n 選出 4 個不同的元素
shuffle(arr)                              # 把序列 arr 順序打亂
隨機生成1~n排列
n = randint(3, 6)
arr = [i+1 for i in range(n)]
shuffle(arr) 
print(n)
print(*arr)    #輸出 arr 的內容並且用空格隔開
隨機生成長度為n的小寫字母字串
s = ""
n = randint(1, 10)
for i in range(n):
    s += chr(ord('a') + randint(0, 25))
print(s)
隨機生成樹
n = randint(3, 6) 
print(n)
for i in range(2, n+1):
    print(randint(1, i-1), i)
無自環無重邊連通圖
n = randint(5, 10)
m = randint(n-1, n+3)
print(n, m)
edge = list()
#construct tree
for i in range(2, n+1):
    x = randint(1, i-1)
    y = i
    edge.append([min(x, y), max(x, y)])
    print(x, y)
 
#add extra edge
for i in range(m-(n-1)):
    x = randint(1, n)
    y = randint(1, n)
    while x == y or [min(x, y), max(x, y)] in edge:
        x = randint(1, n)
        y = randint(1, n)
    print(x, y)
    edge.append([min(x, y), max(x, y)])