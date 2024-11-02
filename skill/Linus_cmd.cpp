cd ..        回到上一層資料夾
cd ../..     回到上上層資料夾
cd test      到當前目錄的test資料夾
ls           顯示當前資料夾的檔案
cat a.cpp    印出當前檔案的內容
mkdir test   在當前目錄建立 test 的資料夾
rm  a.cpp    刪除 a.cpp 的檔案
g++ solve.cpp                編譯solve.cpp的檔案成 a.out 檔
g++ solve.cpp -o ac.out      編譯solve.cpp的檔案成 ac.out 檔
g++ solve.cpp -std=c++14     編譯solve.cpp的檔案成 a.out 檔 並且編譯版本為 c++14
./a.out                      執行 a.out 檔
-fsanitize=undefined  
插入各種undefined behavior檢查，會在執行期輸出錯誤訊息
-Wall -Wextra
把warning都開起來，常能預防bug發生
-Wshadow
當有宣告了相同變數名稱的情形發生時予以警告
alias [name]='[value]'
alias g++ = `g++ -std=c++14 -fsanitize=undefined -Wall -Wextra -Wshadow`
factor 100 //產生質因數