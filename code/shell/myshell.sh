#! /bin/bash
echo "尊敬的用户，请选择如下功能（按数字即可）"
echo "1.查看进程信息"
echo "2.查看用户和主机信息"
echo "3.显示当前目录信息"
echo "4.显示Linux创始人"
echo "5.显示Linux发行版本名称和Linux内核版本"
echo "6.显示当前的IP地址"
echo "7.退出"

read -p "请输入：" n
case $n in
  1)
    ps
    ;;
  2)
    w
    ;;
  3)
    ls 
    ;;
  4)
    echo "Linus Benedict Torvalds"
    ;;
  5)
    echo "发行版本："
    cat /etc/redhat-release
    echo "内核版本"
    uname -r
    ;;
  6)
    ifconfig
    ;;
  7)
esac 
