#!/bin/bash
#shell.sh
echo "hello world"
read -p "?-" firstname      # 提示使用者輸入
read -p "Please input your last name:  " lastname       # 提示使用者輸入
echo -e "\nYour full name is: ${firstname} ${lastname}" # 結果由螢幕輸出
# while read line
# do
#     IFS=','
#     read -a record <<< "$line"
#
#     echo ${record[0]}
#     echo ${record[1]}
#     echo ${record[2]}
# done $1
