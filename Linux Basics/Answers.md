# 《鸟哥的Linux私房菜》习题参考答案

- [另一份参考答案](https://blog.csdn.net/qq_41151659/article/details/94491657)

## 第0章 计算机概论

1. 全球最快的超级电脑：Summit

   所在位置：美国能源部橡树岭国家实验室

   架构：9,216颗POWER9 22核心CPU 3.1GHz，27,648块NVIDIA Tesla V100 GPGPU运算加速卡

   CPU规格：14nm，24核心96线程

   功率：13MW

   当地电价：（Tennessee）10.1¢/kWh

   全功率运行1天消耗电能：3,151,200¢=31512$ (约217464.312元）

 

2. CPU：Intel Core i7 9750H 睿频4.5GHz

   内存：2*16GB DDR4

   显卡：Intel UHD Graphics 630/集成

    NVDIA GeForce GTX 1650/PCIe/4GB GDDR5

   主板：Dell G5 5590

   北桥芯片组型号：Intel Coffee Lake-H IMC

   南桥芯片组型号：Intel Cannon Point HM370

   BIOS：Dell

   集成网卡/声卡：有/有

   硬盘：Drive #1 - ST1000LM035-1RK172 (931 GB) /SATA/5400RPM/128MB

    Drive #2 - BC501 NVMe SK hynix 256GB (238 GB) /PCIe NVMe/无缓存信息

   

3. Intel     i7 4790

   南桥DMI带宽：DMI2 5GT/s

   二级缓存容量：4*256KBytes

   最大PCIe通道数量：16（Up to 1x16, 2x8, 1x8+2x4）

4. Intel     SSD 520

   接口：SATA 3.0

   最大顺序读写：550/520 MB/s

   最大随机读写：50000/42000 IOPS

## 第一章 Linux是什么与如何学习

### 一、实践题

1. 最新稳定 5.4.14 （2020/01/23查询）

   开发中 5.5-rc7

2. 名称：Tux

   原始图形文件：https://upload.wikimedia.org/wikipedia/commons/archive/3/35/20060527184142%21Tux.svg  17:53, 3 May 2006 （不一定为最原始文件）

3.  

Android Version  | API Level | Linux Version in AOSP |Header Version
-----------------|-----------|-----------------------|--------
   1.5  Cupcake   |3     |(2.6.27)                 |
   1.6  Donut    |4     |(2.6.29)                 |2.6.18
   2.0/1 Eclair    |5-7    |(2.6.29)                 |2.6.18
   2.2.x Froyo    |8     |(2.6.32)                 |2.6.18
   2.3.x Gingerbread |9, 10   |(2.6.35)                 |2.6.18
   3.x.x Honeycomb  |11-13   |(2.6.36)                 |2.6.18
   4.0.x Ice Cream San|14, 15   |(3.0.1)                 |2.6.18
   4.1.x Jelly Bean  |16     |(3.0.31)                 |2.6.18
   4.2.x Jelly Bean  |17     |(3.4.0)                 |2.6.18
   4.3  Jelly Bean  |18     |(3.4.39)                 |2.6.18
   4.4  Kit Kat   |19, 20   |(3.10)                  |2.6.18
   5.x  Lollipop   |21, 22   |(3.16.1)                 |3.14.0
   6.0  Marshmallow |23     |(3.18.10)                |3.18.10
   7.0  Nougat    |24     | 3.18.48 4.4.0              |4.4.1
   7.1  Nougat    |25     | ?                    |4.4.1
   8.0  Oreo     |26     | 3.18.72 4.4.83 4.9.44         |4.10.0
   8.1  Oreo     |27     | 3.18.70 4.4.88 4.9.56         |4.10.0
   9.0  Pie     |28     |     4.4.146 4.9.118 4.14.61     |4.15.0
   10.0  Q      |29     |         4.9.191 4.14.142 4.19.71|5.0.3

### 二、简答题

1. 可能原因：系统中未安装网卡驱动/无支持该系统的网卡驱动/网卡被系统禁用

   解决：安装网卡驱动/开发相应驱动或更换系统/启用该网卡

2. 输入单元、输出单元、控制单元、算术逻辑单元、记忆单元
3. Windows上的游戏不能直接在Linux上运行。
4. 系统套件、软件管理模式、交互界面、维持方式等
5. Kenneth     Thompson和Dennis Ritchi；Richard Matthew Stallman
6. GNU is     Not Unix；Free Software Foundation，FSF
7. 多用户：在同一时间有多个用户能使用操作系统

   多任务：同时处理多个任务

8. GPL: 可修改、复制、共享，互利互助，保护原作者版权，不可直接销售

   开源：开放， 可修改、复制、共享、商业化。

9. POSIX：可移植操作系统接口，重点在于规范内核和应用程序之间的接口

   好处：UNIX也遵循POSIX，故Linux对UNIX软件有很好的兼容性

10. 成功因素：发布于网络，保持开放，供所有人使用交流；遵循POSIX，对UNIX保持很好的兼容性；Linus个人的天赋与热情，虚拟团队志愿者的维护。

## 第二章 主机规划与磁盘分区

1. 130w*4h*365Days*0.61元=115.778元
2. 不是，当计算机的性能瓶颈在于其它硬件而不在于CPU时，CPU速度的提升对于整体性能的提升贡献很少。
3. 考虑个人或组织的经济状况和需求；不是，Linux对于硬件的要求并不算高
4. 电子元件是否老化、主机的主要任务和需求
5. SATA硬盘：/dev/sd[a-p] （虚拟机为/dev/vd[a-p]）

   CDROM:/dev/scd[0-1] 或 /dev/sr[0-1]

   打印机：/dev/lp[0-2] 或 /dev/usb/lp[0-15]

6. SATA和SAS（注：现在还有M.2）

## 第三章 安装CentOS 7.x

1. 安装的时候必须有/和/swap
2. /dev/sdb1

   /dev/sdb2

   /dev/sdb5

   /dev/sdb6

   /dev/sdb7

   /dev/sdb8

3. 格林威治时间；八小时
4. /dev/md[0-15]
5. 不能

## 第四章 首次登陆与在线求助

### 简答题

1. （1）基于物理设备的连接，称为物理终端（Pysical Terminal），也可以称为物理控制台（Pyhsical console）。

   （2）一个物理终端（物理控制台），可以支持多个虚拟终端（或虚拟控制台 virtual console）。

   （3）随着X视窗系统的广泛使用，虚拟控制台的使用需求也越来越少，控制台程序可以在终端模拟器(terminal emulator)中运行，这些被称为伪终端(Pseudo Terminal)。

   ​		[更详细的说明](https://my.oschina.net/xinghaitao/blog/994374)

2. 除去采用图形界面的tty，共有5个（但CenetOS 8上前两个tty都是图形界面，故只有四个）

   切换快捷键：ctrl+alt+F[1-6]

3. 不是
4. date --help 或 man date 或 info     date
5. 终端执行     shutdown 1:30
6. Ctrl+alt+backspace
7. 终端执行 date --date=20100502     +%A 或 cal 02 05 2010
8. date +%Y/%m/%d-%H:%M
9. 切换到只有命令行的tty，通常为ctrl+alt+F[2-6]
10. 补齐（包括命令、文件、参数、格式）
11. Ctrl+c
12. 使用 man -k     passwd；使用info/whatis/apropos
13. 1：普通用户使用的命令

    5：系统配置文件

    8：系统管理员常用命令

14. /usr/share/man

15. ~~foo1是命令，foo2，foo3，foo4是参数~~

    **更正：**

    foo3与foo4则不一定，可能是foo1的参数设定值，也可能是额外加入的parameters。

16. 终端不支持该man文件显示的语系；

    可以在终端输入echo &LANG命令查看当前使用的语言，再输入LANG=en_CN.UTF-8修改语言（临时修改）即可。

17. 文件或目录/vbird不存在
18. 终端键入bz，然后按两次tab
19. a block-sorting     file compressor.（文件压缩程序）
20. $代表用户身份是一般用户，#代表用户是root权限用户，平时应使用一般用户（$）进行操作
21. ~~可以；reboot调用systemctl来让系统重新启动~~

    **更正：**

    理论上reboot仅能让root运行。不过，如果dmtsai是在主机前面以图形接口登陆时，则dmtsai还是可以透过图形接口功能来关机。

## 第五章 Linux的文件权限与目录配置

1. 255个英文字符或128个中文字符
2. 任何人均能读、写、执行该文件
3.  chmod 754 [FILEPATH]
4. /etc/ ：系统主要配置文件

   /boot :启动相关文件

   /usr/bin:所有一般用户能使用的命令

   /bin/: 在单人维护模式下仍能使用的命令

   /usr/sbin/：系统正常运行需要的系统命令之外的其它命令

   /sbin/：与启动、修复、还原系统有关的系统命令

   /dev/：所有设备与接口设备

   /var/log/：日志文件

   /run/:系统启动后产生的各项信息

5. 代表该文件为隐藏文件。

   终端执行 `ls -al [FILEPATH]` 

## 第六章 Linux文件与目录管理

1. 绝对路径：从根目录开始索引的路径

   相对路径：以当前目录为基准开始索引的路径

2. mv /home/test /home/test2
3. 在任意目录通过bash执行命令时都可以调用PATH变量中的二进制文件
4. 用处：提供了目录及文件属性的默认值

   优点：便于文件管理

5. 033文件 `-rw-r--r--`

   033目录 `drwxr--r--`

   044文件 `-rw--w--w-`

   044目录 `drwx-wx-wx`

6. 一种特殊权限，使得当对文件具有可执行权限的用户在执行该文件时对程序临时获得该文件拥有者的权限，仅对二进制程序有效

7. 传统权限： `ll /usr/bin/passwd`

   文件类型：`file /usr/bin/passwd`

   文件隐藏属性：`lsattr /usr/bin/passwd`

8. `find / -perm /4000`
9. `find /etc -size +50k -a -size -60k -exec ls     -l {} \;`
10. `find /etc -size +50k -a ! -user root -exec ls     -ld {} \`（注：其中的!可改为-not)
11. `find /etc -size +1500k -a -size 0`

## 第七章 Linux磁盘与文件系统管理

1. 文件系统的损坏
2. 不会

## 第八章 文件与文件系统的压缩