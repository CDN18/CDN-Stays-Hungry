# 第二部分：Linux文件、目录与磁盘格式

***鸟哥的Linux私房菜* 的笔记**

## 第5章：Linux的文件权限与目录配置

### 一、用户与用户组

文件权限规定的管理对象：

- 文件拥有者
- 文件所属用户组
- 除上述二者外的其他用户

### 二、Linux文件权限概念

- 文件权限示例

```
[cdn@localhost /]$ ll
total 2256
lrwxrwxrwx.   1 root root       7 May 11  2019 bin -> usr/bin
dr-xr-xr-x.   5 root root    4096 Jan 25 17:47 boot
drwxr-xr-x.  20 root root    3220 Mar 19 09:20 dev
drwxr-xr-x. 135 root root    8192 Mar 19 09:35 etc
drwxr-xr-x.   3 root root      17 Jan 25 17:20 home
lrwxrwxrwx.   1 root root       7 May 11  2019 lib -> usr/lib
lrwxrwxrwx.   1 root root       9 May 11  2019 lib64 -> usr/lib64
drwxr-xr-x.   2 root root       6 May 11  2019 media
drwxr-xr-x.   3 root root      19 Feb 22 13:55 mnt
drwxr-xr-x.   4 root root      52 Feb 19 07:31 opt
dr-xr-xr-x. 325 root root       0 Mar 19 09:18 proc
dr-xr-x---.   6 root root    4096 Mar 17 18:33 root
drwxr-xr-x.  40 root root    1220 Mar 19 09:24 run
lrwxrwxrwx.   1 root root       8 May 11  2019 sbin -> usr/sbin
drwxr-xr-x.   2 root root       6 May 11  2019 srv
dr-xr-xr-x.  13 root root       0 Mar 19 09:17 sys
-rw-r--r--.   1 root root 2279852 Jan 25 17:49 @System.solv
drwxrwxrwt.  15 root root    4096 Mar 19 09:33 tmp
drwxr-xr-x.  12 root root     144 Jan 25 17:12 usr
drwxr-xr-x.  21 root root    4096 Jan 25 17:22 var
-rw-------.   1 root root       0 Mar 19 09:23 VBox.log
```

- 说明

    - 第一栏代表文件的类型与权限，共十个字符
    
- 第一个字符代表文件类型：目录为d，文件为-，链接文件为l，可按块随机读写设备（如存储设备）为b，串行端口设备（一次性读取设备，如键盘，鼠标）为c
    - 接下来的字符三个一组，分别代表文件拥有者、加入此文件所属用户组的用户（不包括拥有者本人）、除上述二者之外其它用户的权限。r代表可读，w代表可写，x代表可执行，若为-，代表不具备相应权限
    - 第二栏代表有多少文件名链接到此节点（详见第七章）
    - 第三栏表示文件拥有者账号
    - 第四栏表示文件所属用户组
    - 第五栏位文件容量，默认单位Bytes
    - 第六栏文件创建日期或最近修改日期，若文件被修改时间距离现在太久，则仅显示年份（此时若要显示完整时间，需添加`--full-time`）
    - 第七栏为文件名，若以.开头，则为隐藏文件
    
- 修改文件属性与权限

- 修改文件所属用户组：chgrp

    ```
    chgrp [-R] dirname/filename ...
    # -R ：修改该目录下所有子文件/子目录的用户组
    ```

- 修改文件拥有者：chown

    ```
    chown [-R] 账号名称[:用户组名称] 文件或目录...
    ```

- 修改文件权限：chmod

    ```
    chmod xxx filename/dirname
    ```

    - xxx为数字，可以为0，1，2，4，5，6，7
    - 每一个x从前往后分别代表拥有者、所属用户组、其它用户的权限
    - r对应数字4，w对应2，x对应1，若无相应权限，则为0，累加得到x
    - 例如，rwxrw-r-x对应数字为765

    ```
    chmod [u/g/o/a][+/-/=][r/w/x] filename/dirname ...
    ```

    - u,g,o,a分别代表拥有者、所属用户组、其他用户、所有
    - +代表添加权限，-代表删除权限，=代表设置权限
    - 示例：`chmod u=rwx,go=rx .bashrc`为文件.bashrc的拥有者设定权限rwx，用户组、其它用户设定权限rx

- 文件是否可执行，与文件拓展名无关

- 文件的rwx是对文件内容而言的，拥有一个文件的rwx权限不代表就能删除该文件

- 目录的权限

    - r：可读取目录内的五年间列表
    - w：可修改目录结构，即可以建立/删除/重命名/移动文件或目录（无论该文件/目录的权限是什么）
    - x：可以让该目录称为用户在终端或命令行的工作目录，即获得进入该目录的权限，想要读取此目录中的文件，其所在目录必须具备该权限
    
- Linux文件种类

  - 常规文件（Regular File）
  
- 纯文本文件（ASCII）：可用cat等命令读出
  
    - 二进制文件（Binary）：如脚本文件
    
- 数据文件（Data）
  - 目录（Directory）
  - 链接文件（Link）
  - 设备与设备文件（Device）
      - 区块（Block）设备文件：可随机在不同区块读写
      - 字符（Character）设备文件：一次性读取，不能截断输出
  - 数据接口文件（Sockets)
  - 数据输送文件（FIFO，pipe）
  
- 文件拓展名（与文件是否可执行无关）

    -    *.sh : 脚本或批处理文件
    -    *.Z, *.tar, *.tar.gz, *.zip, *.tgz : 经过打包的压缩文件
    -    *.html, *.php : 网页相关文件

- 文件名长度限制：以ASCII计，最大容许文件名为255字节

- 文件名限制：尽可能避免:

    ```
    ? > < ; & ! { } [ ] | \ ' " \ ` ( ) - +
    ```


### 三、Linux目录配置

- FHS（Filesystem Hierarchy Standard）

  |                    | 可分享（sharable）                               | 不可分享（unshareable）                     |
  | ------------------ | ------------------------------------------------ | ------------------------------------------- |
  | 不变（static）     | /usr(软件存放处)<br />/opt(第三方辅助软件)       | /etc(配置文件)<br />/boot(启动与内核文件)   |
  | 可变动（variable） | /var/mail(用户邮箱)<br />/var/spool/news(新闻组) | /var/run(程序相关)<br />/var/lock(程序相关) |

  - 可分享：指可以分享给其它系统挂载使用的目录，包括执行文件与用户的邮件等数据
  - 不可分享：自己机器上面运行的设备文件或与程序有关的socket文件等，仅与本机有关
  - 不变：跟随发行版而不变动的数据，如函数库、文件说明、系统管理员所管理的主机服务配置文件等
  - 可变动：经常修改的数据，如日志文件，一般用户可自行接收的新闻组等



- FHS仅定义三层目录下面应该放置什么数据

  - / （根目录）：与启动系统有关
  - /usr （unix software resource) :与软件安装/执行有关
  - /var （variable)：与系统运行过程有关

- 根目录的意义与内容

  - 与启动、还原、系统修复等操作有关

  - FHS建议根目录所在分区越小越好，且应用程序安装的软件最好不要与根目录放在一个分区内，保持根目录越小越好，如此不但性能较佳，根目录所在的文件系统也不容易发生问题

  - 第一部分：FHS要求必须存在的目录

    | 目录   | 应放置文件内容                                               |
    | ------ | ------------------------------------------------------------ |
    | /bin   | 在担任维护模式下还能够被使用的命令，可以被root和一般账号使用 |
    | /boot  | 启动所需文件，包含Linux内核文件和启动选项与启动所需配置文件。Linux内核常用文件名为vmlinuz，若使用grub2引导，则存在/boot/grub2 |
    | /dev   | 设备与接口设备。重要设备文件：/dev/null, /dev/zero, /dev/tty, /dev/loop\*, /dev/sd\* |
    | /etc   | 系统主要配置文件，如账号密码、服务启动文件，一般用户可查看，root可修改。FHS建议不要防止可执行文件再次目录中。<br />较为重要的文件：/etc/modprobe.d, /etc/passwd, /etc/fstab, /etc/issue<br />FHS还规范几个重要文件都放在/etc下：<br />/etc/opt(必要)：放置第三方辅助软件/opt的相应配置文件<br />/etc/X11(建议)：与X Window有关的各种配置文件，尤其是X Server的配置文件xorg.conf<br />/etc/sgml(建议)：与SGML格式有关的各项配置文件<br />/etc/xml(建议)：与XML格式有关的各项配置文件 |
    | /lib   | 在启动时会调用的函数库，以及/bin、/sbin下的命令会调用的函数库<br />FHS要求/lib/moudles必须存在，该目录主要用于放置可抽换式的内核相关模块（驱动程序） |
    | /media | 可删除的设备，是软盘、光盘、DVD的暂时挂载点，常见文件名有：/media/floppy, /media/cdrom |
    | /mnt   | 暂时挂载的额外设备                                           |
    | /opt   | 给第三方辅助软件放置的目录、非原本发行版提供的（自行安装的）额外软件。（但在之前的Linux中，多放置在/usr/local目录下） |
    | /run   | 系统启动后产生的各项信息，可使用内存来模拟此目录，性能上会好很多 |
    | /sbin  | 启动、修复、还原系统所需要的命令。（某些服务器软件程序一般放置到/usr/sbin中，本机自行安装的软件所产生的系统执行文件则放置在/usr/local/sbin中）常见命令包括：fdisk，fsck，ifconfig，mkfs |
    | /srv   | 网络服务的数据目录。                                         |
    | /tmp   | 缓存目录，任何用户均可存取，需要定期清理。FHS建议在启动时清楚/tmp下的数据 |
    | /usr   | 第二层FHS设置，后续介绍                                      |
    | /var   | 第二层FHS设置，后续介绍                                      |

  - 第二部分：FHS建议可以存在的目录

    | 目录        | 应放置文件内容                                               |
    | ----------- | ------------------------------------------------------------ |
    | /lost+found | ext文件系统产生的目录，放置文件系统发生错误时的一些遗失的片段 |
    | /proc       | 内存虚拟的文件系统，放置系统内核、进程信息、外接设备的状态及网络状态<br />重要文件：/proc/cpuinfo, /proc/dma, /proc/interrupts, /proc/ioports, /proc/net/*等 |
    | /sys        | 和/proc非常类似，也是一个虚拟的文件系统，记录内核与系统硬件信息相关的内容，包括目前已加载的内核模块与内核检测到的硬件设备信息 |

- /usr的意义与内容（类似于Windows中的C:\Windows的一部分和C:\Program Files）

  - 第一部分：FHS要求必须存在的目录

    | 目录       | 应放置文件内容                                               |
    | ---------- | ------------------------------------------------------------ |
    | /usr/bin   | 所有一般用户能够使用的命令（CentOS7已经将全部用户命令防止于此，/bin除则使用链接）<br />FHS要求此目录下不得有子目录 |
    | /usr/lib   | /lib链接到此目录中                                           |
    | /usr/local | 系统管理员在本机安装自己下载的（非发行版默认提供的）软件，建议装到此目录 |
    | /usr/sbin  | /sbin链接到此目录，含有某些网络服务器软件的服务命令等        |
    | /usr/share | 放置只读数据文件，包括共享文件，在此目录下放置的数据几乎是不分硬件架构均可读取的数据，几乎都是文本文件<br />常见子目录：<br />/usr/share/man :在线帮助文件<br />/usr/share/doc :软件的说明文档<br />/usr/share/zoneinfo :与时区有关的时区文件 |

  - 第二部分：FHS建议可以存在的目录

    | 目录             | 应放置文件内容                                               |
    | ---------------- | ------------------------------------------------------------ |
    | /usr/games       | 与游戏相关的数据放置处                                       |
    | /usr/include     | C/C++头文件（header）与包含文件（include）放置处，当我们以Tarball（.tar.gz）方式安装某些程序时，会用到里面的许多文件 |
    | /usr/libexec     | 某些不被一般用户常会用的执行文件或脚本，如大部分X窗口下的操作命令 |
    | /usr/lib\<qual>/ | /lib\<qual>/链接到此目录                                     |
    | /usr/src         | 放置一般源代码，至于内核源代码则建议放置到/usr/src/Linux     |

- /var的意义与内容

  - 第一部分：FHS要求必须存在的目录

    | 目录       | 建议放置的文件                                               |
    | ---------- | ------------------------------------------------------------ |
    | /var/cache | 应用程序运行过程中的缓存                                     |
    | /var/lib   | 程序本身执行的过程需要使用到的数据文件（各个软件应有自己的子目录） |
    | /var/lock  | 已移动至/run/lock中，存放同时只能被一个应用程序所使用的文件，如用于克鲁的光盘 |
    | /var/log   | 日志文件，重要文件有//var/log/messages, /var/log/wtmp(记录登录信息)等 |
    | /var/mail  | 个人电子邮箱的目录                                           |
    | /var/run/  | 某些程序的PID。后续会解释何伟PID，链接到/run                 |
    | /var/spool | 放置一些队列数据（排队等待其它程序使用的数据），使用之后通常会被删除 |



- 目录树及特性
  - 由根目录开始往下分支形成的树状文件结构
  - 起始点为根目录
  - 每一个目录不仅能使用本地分区的文件系统，也可以使用网络上的文件系统
  - 每一个文件在此目录树中的文件名都是独一无二的
- 绝对路径与相对路径
  - 绝对路径由根目录`/`开始
  - 相对路径由当前目录`./`开始
  - `../`代表上一层目录，/可删去



## 第6章：Linux文件与目录管理

### 一、目录与路径

- 常见处理目录的命令
  - cd：切换目录
  - pwd：显示当前目录
  - mkdir：建立一个新目录
  - rmdir：删除一个空目录
- 执行文件路径的变量：$PATH
  - `echo $PATH`可查看被定义的目录，每个目录中间由冒号隔开，有先后顺序之分
  - 不同身份用户PATH不同
  - 安全起见，建议不要将本目录`./`加入PATH中

## 二、文件与目录管理

- 文件与目录的查看：ls

  ```
  ls [-aAdfFhilnrRst] dirname/filename
  ls [--color={never,auto,always}] dirname/filename
  ls [--full-time] dirname/filename
  选项与参数：
  -a					#全部文件，包括隐藏文件, .. , .
  -A					#全部文件，包括隐藏文件
  -d					#仅列出目录本身，而不是列出目录内的文件数据
  -f					#直接列出结果，不进行排序
  -F					#根据文件、目录等信息给予附加数据结构
  					# *代表可执行文件；/代表目录；=代表socket文件；|代表FIFO文件
  -h					#以人类易读的方式（GB、KB）显示文件大小
  -i					#列出inode号码
  -l					#详细信息显示，包含文件属性与权限
  -n					#列出UID/GID而非使用者和用户组的名称
  -r					#将排序结果反向输出
  -R					#连同子目录一起列出
  -S					#以文件容量大小排序
  -t					#以时间排序
  --color=never		 #不依据文件特性给予颜色显示
  --color=always		 #显示颜色
  --color=auto		 #让系统根据设置来判断是否显示颜色
  --full-time			 #以完整时间模式（年、月、日、时、分）输出
  --time={atime,ctime}  #输出access时间或改变权限属性时间（ctime）而非内容修改时间（mtime）
  ```

- 复制：cp

  ```
  cp [-adfilprsu] sourcefile destination
  cp [options] source1 source2 ... directory
  选项与参数：
  -a 		#相当于-dr --preserve=all的意思
  -d 		#若源文件为链接文件，则复制链接文件而非源文件
  -f 		#强制：若目标文件已经存在且无法开启，则删除后再试一次
  -i 		#若目标文件已经存在，则覆盖前先询问
  -l 		#进行硬链接的链接文件建立，而非文件本身
  -p 		#连同文件的属性（权限、用户、时间）一起复制，而非使用默认属性（备份常用）
  -r 		#递归复制，用于目录的赋值操作
  -s 		#复制成为符号链接文件
  -u 		#destination比source旧或不存在才更新destination
  --preserve=all: 除了-p的权限相关参数之外，还加入SELinux、links、xattr的复制
  若源文件由两个以上，则destination需要为目录
  ```

  - 默认条件中，cp的源文件与目标文件权限不同

- 删除：rm

  ```
  rm [-fir] 文件或目录
  选项与参数：
  -f :忽略不存在的文件，不出现警告信息
  -I :交互模式，在删除前会询问使用者是否操作
  -r :递归删除，最常用于目录的删除，危险
  ```

- 移动：mv

  ```
  mv [-fiu] source destination
  mv [options] source1 source2 ... directory
  选项与参数：
  -f: 强制，若目标文件存在，不经询问直接覆盖
  -i: 若目标文件存在，询问是否覆盖
  -u: 若目标文件已经存在，且source较新，才更新（update）
  ```

### 三、文件内容的查看

- cat（concatenate）

  ```
  cat [-AbEnTv]
  选项与参数：
  -a: 相当于-vET的整合选项，可以列出一些特殊字符而不只是空白
  -b: 列出行号，仅针对非空白做行号显示
  -E: 将结尾换行符S显示出来
  -n: 打印行号，空白行也有行号
  -T: 将[Tab]键以^T显示出来
  -v: 列出一些看不见的特殊字符
  ```

- tac(反向显示，从最后一行开始一直到第一行)

  ```
  [cdn@localhost tmp]$ cat tmp
  abcdefg
  higklmn
  [cdn@localhost tmp]$ tac tmp
  higklmn
  abcdefg
  ```

- nl(添加行号打印)

  ```
  nl [-bnw] file
  选项与参数：
  -b:指定行号的指定方式
  	-b a:空行也要列出行号
  	-b t:空行不必列出行号
  -n:
  	-n ln:行号在屏幕最左方显示
  	-n rn:行号在自己栏位最右方显示，不加0
  	-n rz:行号在自己栏位最右方显示，且加0
  -w: 行号栏位占用的字符数（具体数字，示例-w 6表示6位）
  ```

- more/less

  ```
  more/less file
  ```

  - more的可用功能
    - 空格键：向下翻一页
    - Enter：向下翻一行
    - /string：向下查找关键词string
    - :f ：显示文件名及目前显示的行数
    - q ：离开more
    - b或ctrl-b：往回翻页（只对文件有用，对管道没用）
  - less比more的更加灵活的地方
    - 可以向上翻页：PageUp
    - 可以向上查找：?string
    - n：重复前一个查找
    - N：反向重复前一个查找
    - g：前进到该数据第一行
    - G：前进到该数据最后一行

- 数据截取

  - head(截取前面几行)

    ```
    head [-n number] file
    
    注：默认显示前10行
    ```

  - tail(截取后面几行)（用法类似head）

- 读取非纯文本文件：od

  ```
  od [-t TYPE] file
  选项或参数：
  -t:
  	a		#利用默认字符输出
  	c		#使用ASCII字符输出
  	d[size]  #利用十进制（decimal）输出，每个整数占用size Bytes
  	f[size]  #利用浮点数值（floating）输出，每个整数占用size Bytes
  	o[size]  #利用八进制（octal）输出，每个整数占用size Bytes
  	z[size]  #利用十六进制（hexadecimal）输出，每个整数占用size Bytes
  ```

- 修改文件时间/创建新文件：touch

  ```
  touch [-acdmt] file
  选项与参数：
  -a : 仅定义access time
  -c : 仅修改文件时间，若该文件不存在则不建立新文件
  -d : 后面可接自定义日期，相当于--date="日期或时间"
  -m : 仅修改mtime
  -t : 后面可接自定义事件，格式[YYYYMMDDhhmm]
  ```

### 四、文件与目录的默认权限与隐藏权限

- 文件默认权限umask

  - 查看：直接输入`umask`或`umask -S`

    ```
    [root@localhost exchange]# umask
    0022
    [root@localhost exchange]# umask -S
    u=rwx,g=rx,o=rx
    ```

  - 数字显示的是默认值需要减掉的权限，文件的默认最大权限没有x，目录有

- 配置文件隐藏属性：chattr

  ```
  chattr [+-=] [ASacdistu] 文件或目录名称
  选项与参数：
  +：增加某一个特殊参数
  -：删除某一个特殊参数
  =：直接设置参数，且仅有后面的参数
  A：若设置该属性，存取此文件是atime不会被修改
  S：文件修改同步写入磁盘
  a：文件将只能增加数据，不能删除/修改，仅有root才可以设置此属性
  c：文件将自动压缩，读取时将自动解压缩
  d：dump程序执行的时候，该文件/目录不会被dump备份
  i：文件将不能被删除、重命名、设置连接、写入新增数据，对于系统安全性有很大帮助，只有root能设置此属性
  s：文件删除时将完全删除，无法恢复
  u：与s相反，删除后可以恢复
  
  注：xfs文件系统仅支持AadiS
  ```

- 显示文件隐藏属性：lsattr

  ```
  lsattr [-adR] 文件或目录
  选项与参数：
  -a： 将隐藏文件的属性也显示出来
  -d： 如果后面接目录，仅列出目录本身属性
  -R：连同子目录数据一并列出
  ```

- 文件特殊权限：SUID、SGID、SBIT

  - SUID（owner执行权限由x改为s）
    - 仅对二进制程序有效
    - 执行者对于该程序要有x权限
    - SUID仅在程序执行过程中生效
    - 执行者将具有该程序拥有者的权限
  - SGID（group执行权限由x改为s）
    - 仅对二进制程序有效
    - 执行者对于该程序要有x权限
    - 执行者在执行过程中将会获得该程序用户组的支持（用户在此目录下的有效用户组将变为目录用户组，用户建立的新文件的用户组与此目录相同）
  - SBIT（仅对目录有效）（others执行权限由x改为t）
    - 当用户对此目录有wx权限
    - 用户在该目录下建立文件或目录时，仅有自己和root能够删除
  - 设置权限
    - 权限的数字形式有四位，后三位分别代表owner，group，others，第一位就代表特殊权限，SUID, SGID, SBIT的对应数字分别为4，2，1

- 观察文件类型：file

### 五、命令与文件的查找

- 脚本文件的查找：which

  ```
  which [-a] command
  -a ：将所有由PATH目录中可以找到的命令均列出，而不止第一个被找到的命令
  ```

- 文件的查找

  - find：直接查找硬盘，但速度慢，影响磁盘性能

    ```
    find [PATH] [option] [action]
    选项或参数：
    1. 时间相关：-atime/ctime/mtime [+/-]n,下面以mtime为例说明
    	-mtime n: n为数字，意为在n天之前的一天之内被修改过内容的文件
    	-mtime +n:列出在n天之前（不含n天本身）被修改过内容的文件
    	-mtime -n:列出在n天之内（含n天本身）被修改过内容的文件
    	
    	-newer file:列出比file还要新的文件
    2. 使用者或用户名称相关
    	-uid n: n为用户的uid，记录在/etc/passwd里面
    	-gid n：用户组gid
    	-user name: 查找所有者为name的文件
    	-group name:查找所有者用户组为name的文件
    	-nouser:查找所有者不在/etc/passwd中的文件
    	-nogroup:查找用户组不在/etc/passwd中的文件
    3. 与文件权限/名称有关：
    	-name filename:查找文件名称为filename的文件
    	-size [+-]SIZE:查找比SIZE还要大/小的文件，SIZE的单位有c（字节）和k（千字节）
    	-type TYPE:查找类型为TYPE的文件，常规文件f，设备文件b/c，目录d，链接文件l，socket文件s，FIFO文件p
    	-perm mode:查找权限刚好等于mode的文件，mode为四位数
    	-perm -mode:查找文件权限多于或等于mode的文件
    	-perm /mode:查找文件权限少于或等于mode的文件
    4. 额外操作
    	-exec command:command为其他命令，用以处理查找结果
    	-print:将结果打印到屏幕上，为默认操作
    ```

  - whereis：从特定目录查找

    ```
    whereis [-bmsu] filename/dirname
    选项与参数：
    -l		#列出whereis会去查询的几个主要目录
    -b		#只找二进制文件
    -m		#只找在文件说明manual路径下的文件
    -s		#只找source源文件
    -u		#查找不在上述三个项目中的其他特殊文件
    ```

  - locate / updatedb

    - updatedb：根据/etc/updatedb.conf的设置去查找系统硬盘内的文件，并更新/var/liv/mlocate内的数据库文件

    - locate：依据/var/lib/mlocate内的数据库记录，找出用户所输入关键词的文件名

      ```
      locate [-ir] keyword
      选项与参数：
      -i		#忽略大小写差异
      -c		#不输出文件名，仅计算找到的文件数量
      -l		#仅输出几行的意思，例如输出五行为 -l 5
      -S		#输出locate所使用的数据库文件的相关信息，包括该数据库文件记录的文件/目录数量等
      -r		#后面可接正则表达式的显示方式
      ```





## 第7章：Linux磁盘与文件系统管理

### 一、认识Linux文件系统

- 文件系统的特性：

  - 一个可被挂载的数据为一个文件系统（而不是一个分区）
  - 文件系统通常会将文件内容和文件权限存放到不同区块，权限与属性放置到inode中，实际数据在数据区块中

  - 超级区块：记录文件系统的整体信息，包括inode与数据区块总量，使用量，剩余量，文件系统格式等
  - inode：记录文件的属性，一个文件占用一个inode，同时记录此文件的数据所在区块号码。
  - 数据区块：实际记录文件内容

- ext2文件系统

  - inode记录的数据：文件属性、拥有者、用户组、文件大小、ctime/atime/mtime、文件特性标识（如SUID）、文件真正内容指向

  - 每个inode大小均固定为128B（ext4与xfs可设置为256B）

  - inode的间接记录：

    - 系统将inode区域定义为12个直接、1个间接、1个双间接、1个三间接；
    - 双间接有2层区块，三间接有3层区块；
    - 第一层区块指定256个第二层，每个第二层可以指定256个第三层，第三层可以指定256个号码

  - 超级区块记录的信息：

    - 数据区块与inode总量
    - 未使用与已使用inode、数据区块的数量、
    - 数据区块与inode大小（block为1、2、4K，inode为128B或256B）
    - 文件系统挂载时间、最近一次写入数据时间、最近一次检验磁盘（fsck）的时间等文件系统的相关信息
    - 一个文件系统仅有一个超级区块，但不同的区块群组可能含有该超级区块的备份

  - Filesystem Description（文件系统描述说明）

    - 描述每个区块群组开始与结束的区块、每个区段（超级区块、区块对照表、inode对照表、数据区块）分别介于哪一个区块之间，这部分也能用dumpe2fs来观察

  - 区块对照表（block bitmap）：记录区块是否已被使用

  - inode对照表（inode bitmap）：类似区块都招标

  - dumpe2fs：查询ext系统超级区块信息的命令

    ```
    用法：dumpe2fs [-bh] devicename
    选项与参数：
    -b		#列出保留为坏道的部分（一般用不到）
    -h		#仅列出superblock的数据，不会列出其它区段内容
    
    （该命令在挂载ext4系统的Ubuntu 18.04 Desktop上执行）
    dumpe2fs /dev/sda1
    
    Filesystem volume name:   <none>   #文件系统名称（不一定会有）
    Last mounted on:          / 		#上次挂载位置
    Filesystem UUID:          fc51bc5a-0219-4385-8cb1-665b93a8220b
    Filesystem magic number:  0xEF53
    Filesystem revision #:    1 (dynamic)
    Filesystem features:      has_journal ext_attr resize_inode dir_index filetype needs_recovery extent 64bit flex_bg sparse_super large_file huge_file dir_nlink extra_isize metadata_csum
    Filesystem flags:         signed_directory_hash 
    Default mount options:    user_xattr acl  #默认在挂载时加入的参数
    Filesystem state:         clean			#系统状态，clean表示没问题
    Errors behavior:          Continue
    Filesystem OS type:       Linux
    Inode count:              6553600		#inode总数
    Block count:              26214144 		#区块总数
    Reserved block count:     1100948 		#保留区块总数
    Free blocks:              18184853		#可用区块总数
    Free inodes:              5813867		#inode可用数
    First block:              0
    Block size:               4096			#单歌区块大小
    Fragment size:            4096
    Group descriptor size:    64
    Reserved GDT blocks:      1014
    Blocks per group:         32768
    Fragments per group:      32768
    Inodes per group:         8192
    Inode blocks per group:   512
    Flex block group size:    16
    Filesystem created:       Mon Sep 30 12:05:29 2019
    Last mount time:          Mon Mar 23 06:25:32 2020
    Last write time:          Mon Mar 23 06:25:28 2020
    Mount count:              43
    Maximum mount count:      -1
    Last checked:             Mon Sep 30 12:05:29 2019
    Check interval:           0 (<none>)
    Lifetime writes:          95 GB
    Reserved blocks uid:      0 (user root)
    Reserved blocks gid:      0 (group root)
    First inode:              11
    Inode size:	          256			#容量大小
    Required extra isize:     32
    Desired extra isize:      32
    Journal inode:            8
    First orphan inode:       1048796
    Default directory hash:   half_md4
    Directory Hash Seed:      9039e6d0-97bd-4dc9-9b1c-6caf0f52b940
    Journal backup:           inode blocks
    Checksum type:            crc32c
    Checksum:                 0x42019794
    Journal features:         journal_incompat_revoke journal_64bit journal_checksum_v3
    Journal size:             128M
    Journal length:           32768
    Journal sequence:         0x000723e1
    Journal start:            8388
    Journal checksum type:    crc32c
    Journal checksum:         0x95039872
    
    
    Group 0: (Blocks 0-32767) csum 0xceb3 [ITABLE_ZEROED]  #第一个区块群组的位置
      Primary superblock at 0, Group descriptors at 1-13  #主要超级区块位置
      Reserved GDT blocks at 14-1027
      Block bitmap at 1028 (+1028), csum 0x65806ece
      Inode bitmap at 1044 (+1044), csum 0x9690416d
      Inode table at 1060-1571 (+1060)					#inode table位置
      13355 free blocks, 1125 free inodes, 841 directories
      Free blocks: 11368, 11410, 11556-11557, 11561-11562, 11577-11579, 11605-11607, 11684, 11724-11848, 11850-11880, 11882-11887, 11889-11896, 12302-12406, 12546-12637, 12679-12780, 12782-13134, 13136-13239, 16258-24575, 28670-32767			#剩余容量
      Free inodes: 138, 142, 144, 146-149, 151-152,.......(省略)	
      
      Group 1: (Blocks 32768-65535) csum 0xbdfc [ITABLE_ZEROED]
      Backup superblock at 32768, Group descriptors at 32769-32781
      Reserved GDT blocks at 32782-33795
      Block bitmap at 1029 (bg #0 + 1029), csum 0x2b83f466
      Inode bitmap at 1045 (bg #0 + 1045), csum 0xabd82c68
      Inode table at 1572-2083 (bg #0 + 1572)
      470 free blocks, 11 free inodes, 1434 directories
      Free blocks: 33808-33843, 33920-33983, 34160-34175, 34462-34815
      Free inodes: 8922-8923, 8927, 8930-8931, 9109, 9128-9130, 9134, 11832
    Group 2: (Blocks 65536-98303) csum 0x94b8 [ITABLE_ZEROED].....
    ```

  - 与目录树关系

    - 目录：建立目录时，文件系统分配一个inode和至少一个区块给目录，区块记录目录下的文件名及对应inode
    - 文件：建立一般文件时，文件系统分配一个inode和相对于该文件大小的区块数量给该文件，若该文件的数据区块超过了inode的直接指向限制（12个），就还需要一个区块来记录区块号码
    - 读取流程（以/etc/passwd为例）
      1. 通过挂载点信息找到 / 的inode为128，读取该inode知用户对对应数据区块有wx权限，读取区块号码
      2. /  的区块：按区块号码读取区块，找到/etc的inode
      3. 读取/etc的inode，类似第1步
      4. 读取/etc的区块，类似第2步
      5. 读取passwd的inode，类似第1步
      6. 读取passwd的区块，直接读出数据

  - ext2/3/4的文件存取和日志式系统的功能：

    - 改动文件的过程：以新增为例
      1. 确定用户对新增文件的目录是否具有wx权限
      2. 根据inode对照表指派未使用的inode号码，写入新文件权限/属性
      3. 根据区块对照表找到未使用区块号码，向实际区块写入数据，并更新inode的区块指向数据
      4. 将刚写入的inode和区块数据同步更新至inode之招标和区块对照表，并更新超级区块的内哦那个
    - 元数据：每次改动文件都会影响到超级区块、inode对照表、区块对照表，故这一部分称为元数据
    - 数据的不一致状态：系统异常终端时，元数据可能并未同步更新。系统重启时会借助超级区块的有效位、文件系统状态等来进行数据一致性检查，这样的检查很费时。
    - 日志式文件系统
      - 规划日志区块来记录文件的写入和修改：
        1. 预备：当准备写入一个文件时，现在日志记录骑跨更新某个文件准备写入的信息
        2. 实际写入：开始写入文件的权限和数据，开始更新metadata
        3. 结束：完成metadata更新后，在日志区块完成该文件的记录

  - 文件系统的运行：

    - 内存中被修改的数据已全部写回磁盘：clean, 有修改但未写回磁盘：dirty
    - 系统将常用文件放在内存缓冲区以加速读写
    - 因此Linux的内存最后都会被用光
    - 手动使用sync来强制内存中设置为dirty的数据写回磁盘
    - 正常关机会主动调用sync
    - 非正常关机重启后，需要花很多时间进行磁盘校验，甚至可能导致文件系统的损坏

  - 挂载点的意义：进入该文件系统的入口

  - 其它文件系统与VFS

    - 常见支持文件系统：
      - 传统文件系统：ext2, minix, FAT(vfat模块), iso9660(光盘)等
      - 日志式文件系统：ext3, ext4, ReiserFS, Windows NTFS, IBM JFS, SGI XFS, ZFS
      - 网络文件系统：NFS、SMBFS
    - 查看`/lib/modules/$(uname -r)/kernel/fs`来查看当前Linux支持的文件系统
    - `cat /proc/filesystems`查看已经加载到内存的文件系统
    - Linux使用VFS来管理文件系统（具体见P222）

  - XFS文件系统简介

    - ext系列文件系统支持度广，但格式化很慢（高容量磁盘）
    - xfs系统主要规划为三部分：数据区、文件系统活动登录区、实时运行区
      - 数据区：包括inode、数据区块、超级区块等，分为多个存储区群组，inode有多种容量可以设置（512B-64KB，由于Linux pagesize的容量限制，最多设置为4k）inode容量可在256B-2MB，但256B足够
      - 文件系统活动登录区：log section，和ext4类似
      - 实时运行区：建立文件时，xfs先在此找到一个到数个extent区块，将文件放置在此区块内，分配完毕后再写入data section的数据和元数据中，extent区块只可在格式化前指定，不建议随意挑哼，非阵列磁盘默认64k，若具有磁盘阵列stripe，则可以设置成和stripe一样大
    - 用xfs_info观察xfs文件系统的数据

### 二、文件系统的简单操作

- 磁盘与目录的容量

  - df —— 列出文件系统整体磁盘使用量

    ```
    df [-ahikHTm] [dirname/filename]
    选项与参数：
    -a		#列出所有文件系统，包括系统特有的/proc
    -k		#以KB显示容量
    -m		#以MB显示容量
    -h		#以人类易读方式GB、MB等自行显示
    -H		#以M=1000L替换1024仅为方式
    -T		#连同该硬盘分区的文件系统也列出
    -i		#用inode数量代替磁盘容量
    
    示例：
    [cdn@localhost exchange]$ df
  Filesystem              1K-blocks      Used Available Use% Mounted on
    devtmpfs                  6129416         0   6129416   0% /dev
  tmpfs                     6146104         0   6146104   0% /dev/shm
    tmpfs                     6146104      9704   6136400   1% /run
    tmpfs                     6146104         0   6146104   0% /sys/fs/cgroup
    /dev/mapper/CentOS-root  20961280   5599032  15362248  27% /
    /dev/sda2                 2086912    239888   1847024  12% /boot
    /dev/mapper/CentOS-home  20961280    437852  20523428   3% /home
    Exchange                976629756 823033776 153595980  85% /home/cdn/exchange
    tmpfs                     1229220      1180   1228040   1% /run/user/42
    tmpfs                     1229220      5812   1223408   1% /run/user/1000
    
    说明：
    Filesystem: 该文件系统所在硬盘分区
    1k-block：数字单位为1KB
    Used：已用空间
    Available：可用空间
    Use%：已使用百分比，最好不要超过90%
    Mounted on：挂载点
    ```
  
  - du
  
    ```
    du [-ahskm] filename/dirname
    选项与参数：
    -a		#列出所有文件与目录容量（默认仅显示目录下面的文剑良）
    -h		#以人类易读方式显示
    -s		#仅列出总量，布列出每个目录占用容量
    -S		#不包括子目录的总计，仅列出总量，与-s有差别
    -k		#以KB显示
    -m		#以MB显示
    ```

### 二、硬链接与符号链接 —— ln

- 硬链接（实际链接）

  - 硬链接就是链接到与之前存在的一个文件相同inode的文件
  - 只要至少有一个硬链接存在（包括文件到文件本身），该文件就可以被访问
  - 硬链接不能跨文件系统和目录

- 符号链接（快捷方式）

  - 建立一个独立的文件，让数据指向它链接的文件的文件名
  - 删除源文件后，符号链接就无法打开
  - 符号链接占用新的inode

- 制作链接文件 —— ln

  ```
  ln [-sf] 源文件 目标文件
  选项与参数：
  -s		:ln默认建立硬链接，加此参数建立符号链接
  -f		:若目标文件存在，主动将目标文件直接删除后再建立
  ```

- 目录的连接数量

  - 新建目录的连接数为2（该目录本身和该目录内的硬链接 /directory/.
  - 建立新目录时，上层目录链接+1 （目录内链接 /directory/..）

### 三、分区、格式化、检验、挂载

- 观察分区状态

  - lsblk —— 列出系统所有磁盘列表

    ```
    lsblk [-dfimpt] [device]
    选项与参数：
    -d		#仅列出磁盘本身，并不会列出该磁盘分区数据
    -f		#同时累出磁盘内的文件系统名称
    -i		#使用ASCII字符输出
    -m		#同时输出设备在/dev下的权限信息（rwx的数据）
    -p		#列出该设备的完整文件名
    -t		#列出该设备的详细数据，包括磁盘阵列机制，预读写数据量大小等
    
[cdn@localhost ~]$ lsblk
    NAME            MAJ:MIN RM  SIZE RO TYPE MOUNTPOINT
    sda               8:0    0   60G  0 disk
    ├─sda1            8:1    0    2M  0 part
    ├─sda2            8:2    0    2G  0 part /boot
    └─sda3            8:3    0   48G  0 part
      ├─CentOS-root 253:0    0   20G  0 lvm  /
      ├─CentOS-swap 253:1    0    2G  0 lvm  [SWAP]
      └─CentOS-home 253:2    0   20G  0 lvm  /home
    sr0              11:0    1 1024M  0 rom
    
    输出信息解释
    - NAME：设备的文件名
    - MAJ:MIN：主要设备代码:次要设备代码，用于内核对设备的识别
    - RM：是否为可卸载设备
    - SIZE：容量
    - RO：是否为只读设备
    - TYPE：磁盘disk，分区part，lvm分区lvm，只读存储rom
    - MOUNTPOINT：挂载点
    ```
    
  - blkid ——列出设备的UUID
  
    ```
    [root@localhost cdn]# blkid
    /dev/sda1: PARTUUID="f5992bfb-027a-48c3-bb3b-00a0bee9dc27"
    /dev/sda2: UUID="3bc7d491-e532-4247-8794-6226f7673d56" TYPE="xfs" PARTUUID="7a2297e3-5740-4b65-a58c-519557d3cbf3"
    /dev/sda3: UUID="r60f2J-0ZF0-qJam-r80q-Naqf-1Kre-JswHXO" TYPE="LVM2_member" PARTUUID="7ac8a1ce-4ced-4783-809a-a70a0f402cbe"
    /dev/mapper/CentOS-root: UUID="f63f3692-af8d-48ad-8200-7d60cc64c29d" TYPE="xfs"
    /dev/mapper/CentOS-swap: UUID="df237ac2-2ce3-4ecb-83c8-7355bb962131" TYPE="swap"
    /dev/mapper/CentOS-home: UUID="4cbb2d7b-501d-40a6-8ec2-f756a9db4b2f" TYPE="xfs"
    ```
  
  - parted列出磁盘的分区表类型与分区信息
  
    ```
    parted [device] [name] print
    
    [root@localhost cdn]# parted /dev/sda print
    Model: ATA VBOX HARDDISK (scsi)
    Disk /dev/sda: 64.4GB
    Sector size (logical/physical): 512B/512B
    Partition Table: gpt
    Disk Flags: pmbr_boot
    
    Number  Start   End     Size    File system  Name  Flags
     1      1049kB  3146kB  2097kB                     bios_grub
     2      3146kB  2151MB  2147MB  xfs
     3      2151MB  53.7GB  51.5GB                     lvm
     
     parted也可以用于显示分区的相关信息
     显示信息说明：
     Number:分区编号，1号为/dev/sda1
     Start/End:其实/结束扇区
     Size:分区容量
     File system：文件系统名称
    ```
  
- 分区：gdisk/fdisk

  - gdisk（用于gpt分区表）

    ```
    gdisk [device_name]
    
    [root@localhost cdn]# gdisk /dev/sda
    GPT fdisk (gdisk) version 1.0.3
    
    Partition table scan:
      MBR: protective
      BSD: not present
      APM: not present
      GPT: present
    
    Found valid GPT with protective MBR; using GPT.
    
    Command (? for help): ?
    b	back up GPT data to a file
    c	change a partition's name
    d	delete a partition
    i	show detailed information on a partition
    l	list known partition types
    n	add a new partition
    o	create a new empty GUID partition table (GPT)
    p	print the partition table
    q	quit without saving changes
    r	recovery and transformation options (experts only)
    s	sort partitions
    t	change a partition's type code
    v	verify disk
    w	write table to disk and exit
    x	extra functionality (experts only)
    ?	print this menu
    
    Command (? for help):
    ```

  - fdisk（用于MBR分区表）

  - parted

    ```
    parted [device] [command[option]]
    
    选项与参数：
    新增分区 mkpart [primary|logical|Extended] [ext4|vfat|xfs] 开始位置 结束位置
    显示分区 print
    删除分区 rm [partition]
    ```

    

- 格式化（创建文件系统）

  - XFS文件系统（mkfs.xfs）

    ```
    mkfs.xfs [-b bsize] [-d parms] [-i parms] [-l parms] [-L label] [-f] [-r parms] device_name
    
    选项与参数：
    单位：默认为Bytes，可用k,m,g,t,p(小写)来解释
    -b:后面接区块容量。由512到64k，Linux最大为4k
    -d:后面接相关参数
    	agcount=数值 ：设置需要几个存储群组（AG），通常与CPU有关
    	agsize=数值： 每个AG设置为多少容量，agcount和agsize设置一个即可
    	file：表明格式化的设备是文件而不是设备，例如虚拟磁盘
    	size=数值：data section的容量，设置这个可以不用完全部的设置容量
    	su=数值：当有RAID时，stripe的数值
    	sw=数值：当有RAID时，用于保存数据的磁盘数量（需扣除备份盘与备用盘）
    	sunit=数值：与su相当，但以sector为单位（1sector=512Bytes）
    	swidth=数值：su*sw的数值，但以secotr为单位
    -f：设备已存在文件系统时 需要加上此选项以强制格式化
    -i：与inode有较相关的设置，主要的参数有：
    	size=数值：最小256Bytes最大2K，256即可
    	internal=[0|1]:log设备是否内置，默认内置
    	logdev=device:log设备为device
    	size=数值：指定容量，通常最小要有512个区块，大概2M以上
    	
    通常使用mkfs.xfs即可
    ```

  - ext4文件系统mkfs.ext4

    ```
    mkfs.ext4 [-b size] [-L label] device_name
    
    选项与参数：
    -b: 设置区块的大小，有1K，2K，4K的容量
    -L：后面接这个设备的标头名称
    ```

  - 其他文件系统mkfs

    ```
    mkfs[TAB][TAB]
    
    [root@localhost cdn]# mkfs
    mkfs         mkfs.ext2    mkfs.ext4    mkfs.minix   mkfs.vfat    
    mkfs.cramfs  mkfs.ext3    mkfs.fat     mkfs.msdos   mkfs.xfs
    ```

- 文件系统检验

  - xfs_repair处理xfs文件系统

    ```
    xfs_repair [-fnd] device_name
    
    选项与参数：
    -f: 后面的是设备文件而不是实体设备
    -n: 单纯检查并不修改文件系统任何数据
    -d：用于单人维护，针对根目录进行检查与修复，危险慎用
    ```

  - fsck.ext4处理ext4文件系统

    ```
    fsck.ext4 [-pf] [-b 超级区块] 设备名称
    
    选项与参数：
    -p：若遇到需要回复y的操作，自动回复
    -f：强制检查（fsck若未发现unclean标识不会主动进入）
    -D：针对文件系统下的目录进行最佳化配置
    -b：接超级区块所在的位置，一般用不到。超级区块损坏时可用此指定备份超级区块所在的位置，1K备份区块在8193（注：存疑，此处可能为8192），2K在16384，4K在32768
    
    用dump2fs -h partition_name | grep 'Blocks per group'可帮助判断超级区块所在位置
    ```

- 文件系统挂载与卸载

  - 注意事项

    - 单一文件系统不应重复挂载
    - 单一挂载点（目录）不应挂载多个文件系统
    - 挂载点理论上应为空目录（若部位空目录则原来的数据会被隐藏）

  - mount

    ```
    mount [-a]
    mount [-l]
    mount [-t 文件系统] LABEL='' 挂载点
    mount [-t 文件系统] UUID='' 挂载点 #建议用这种方式，因为UUID唯一，出错率低
    mount [-t 文件系统] 设备文件名 挂载点
    
    选项与参数：
    -a:依照配置文件/etc/fstab的数据将所有未挂载的磁盘都挂载上来
    -l：单纯输入mount会显示目前挂载信息，加上l可显示Label名称
    -t：可以加上文件系统种类来指定要挂载的类型，常见支持类型：xfs,ext3,ext4,reiserfs,vfat,iso9600,nfs,cifs,smbfs（后三种为网络文件系统）
    -n：默认情况下实际挂载情况即时写入/etc/fstab中，若在单人维护模式等需要不写入的情况下可加入此参数
    -o：加入额外的挂载参数：
    	async,sync:异步写入，同步写入，默认async
    	atime,noatime:是否修改文件读取时间，为了性能有时可使用-noatime
    	ro,rw:只读，可读写
    	auto,noauto:是否允许被mount -a自动挂载
    	dev,nodev:是否允许此文件系统建立设备文件
    	suid,nosuid：是否允许此文件系统含有SUID/SGID文件格式
    	exec,noexec:是否允许此文件系统拥有可执行二进制文件
    	user,nouser:是否允许文件系统让任何使用者执行mount（默认只有root可执行，即nouser）
    	defaults:默认值为rw,suid,dev,exec,auto,nouser,async
    	remount:重新挂载，在系统出错/更新系统参数时有用
    ```

  - umount

    ```
    umount [-fn] device_name/mount_point
    
    选项与参数：
    -f：强制卸载，可用在如网络文件系统（NFS）无法读取时
    -l：立即强制卸载
    -n：不更新/etc/mtab情况下卸载
    ```

- 磁盘/文件系统参数自定义

  - mknod

    - 常见硬件设备代码（major:minor）

      | 磁盘文件名 | major | minor |
      | ---------- | ----- | ----- |
      | /dev/sda   | 8     | 0-15  |
      | /dev/sdb   | 8     | 16-31 |
      | /dev/loop0 | 7     | 0     |
      | /dev/loop1 | 7     | 1     |

    - 命令说明

      ``` 
      mknod device_name [bcp] [Major] [Minor]
      
      选项与参数：
      bcp可以设置设备种类：b外接存储设备，c外接输入设备，p为FIFO文件
      ```

  - xfs_admin修改XFS文件系统的UUID与Label Name

    ```
    xfs_admin [-lu] [-L label] [-U uuid] 设备文件名
    
    选项与参数：
    -l：列出设备的的label name
    -u：列出设备的UUID
    -L：设置设备的label name
    -U：设置设备的UUID
    ```

  - tune2fs修改ext4的label name和UUID

    ```
    tune2fs [-l] [-L label] [-U uuid] device_name
    
    选项与参数：
    -l：类似dump2fs -h，读取superblock数据
    -L：修改Label Name
    -U：修改UUID
    ```

### 四、设置启动挂载

- 系统挂载的限制
  - 根目录必须挂载，且必须最先挂载
  - 其它挂载点必须为已经建立的目录，可任意指定，但需要遵守FHS
  - 所有挂载点在同一时间只能挂载一次
  - 所有分区在同一时间只能挂载一次
  - 若要进行卸载，需要先将工作目录移动到挂载点（子目录）之外

- **`/etc/fstab`**（/etc/mtab）

  ```
  [root@localhost cdn]# cat /etc/fstab
  
  #
  # /etc/fstab
  # Created by anaconda on Sat Jan 25 04:11:08 2020
  #
  # Accessible filesystems, by reference, are maintained under '/dev/disk/'.
  # See man pages fstab(5), findfs(8), mount(8) and/or blkid(8) for more info.
  #
  # After editing this file, run 'systemctl daemon-reload' to update systemd
  # units generated from this file.
  #
  /dev/mapper/CentOS-root /                       xfs     defaults        0 0
  UUID=3bc7d491-e532-4247-8794-6226f7673d56 /boot                   xfs     defaults        0 0
  /dev/mapper/CentOS-home /home                   xfs     defaults        0 0
  /dev/mapper/CentOS-swap swap                    swap    defaults        0 0
  
  
  各栏信息：
  [设备/UUID/Label] [挂载点] [文件系统] [文件系统参数] [dump] [fsck]
  ```

- 特殊设备loop挂载

  - 挂载CD/DVD

    ```
    mount -o loop /path/to/dvd /path/of/mount/point
    ```

  - 制作loop文件

    ```
    dd if=/dev/zero of=/path/to/the/loop/file bs=1M count=512  #建立一个512M的空文件
    mkfs.xfs -f /path/to/the/loop/file #格式化此文件
    blkid /path/to/the/loop/file
    #记住上一条命令输出的UUID
    /mount -o loop UUID="刚刚的UUID" /mount/point #挂载
    ```

### 五、创建swap

- 创建物理分区（gdisk，略）
- 创建swap文件（见上面，略）
- 格式化为swap：mkswap
- 开启/关闭内存文件 swapon/swapoff



## 第8章：文件与文件系统的压缩

### 一、常见压缩命令

- 压缩文件拓展名

  ```
  .Z			compress程序压缩的文件
  .zip		zip程序压缩的文件
  .gz			gzip程序压缩的文件
  .bz2		bzip2程序压缩的文件
  .xz			xz程序压缩的文件
  .tar		tar程序打包文件
  .tar.gz		tar+gzip
  .tar.bz2	tar+bzip2
  .tar.xz		tar+xz
  ```

- gzip, zcat/zmore/zless/zgrep

  ```
  gzip [-cdtv#] filename
  zcat filename.gz
  
  选项与参数：
  -c：输出压缩的数据，便于数据流重定向
  -d：解压缩参数
  -t：检验压缩文件是否有错误
  -v：显示压缩比等信息
  -#：#用数字代替，代表压缩等级，1最快，压缩比最差，9则反之，默认是6
  
  注意：使用gzip压缩后源文件不再存在
  
  其余四个命令就是压缩状态下的cat more less grep， 针对纯文本文件
  ```

- bzip2, bzcat/bzmore/bzless/bzgrep

  ```
  bzip2 [-cdkzv#] filename
  
  选项与参数
  -c同上
  -d同上
  -k：保留原始文件
  -z：压缩的参数，默认值，可不加
  -v同上
  -#同上
  ```

- xz, xzcat/xzmore/xzless/xzgrep

  ```
  xz [-dtlkc#] filename
  
  选项与参数：
  -d/-t/-k/-c同上
  -l：列出文件相关信息
  ```

- 打包命令：tar

  ```
  tar [-z|-j|-J] [cv] [-f tar_filename] origin_filename ...  #打包与压缩
  tar [-z|-j|-J] [tv] [-f tar_filename] 					#查看文件名
  tar [-z|-j|-J] [xv] [-f tar_filename] origin_filename [-C directory_name] ... #解压缩
  
  选项与参数：
  -c：建立打包文件，可搭配-v来查看过程中被打包的文件名
  -t：查看我打包文件的内容含有哪些文件名
  -x：解包或解压缩
  -z：通过gzip来压缩和解压，文件名最好为.tar.gz
  -j：通过bzip2，文件名最好为.tar.bz2
  -J：通过xz，文件名最好为.tar.xz
  -z/-j/-J一条命令最多出现一个
  -v：显示正在处理的文件名
  -f fileneme ：-f后面接要处理的文件名 建议单独写一个选项
  -C:后加要解压缩到的特定目录
  -p：保留备份数据的原本权限与属性，常用于备份重要的配置文件
  -P：保留绝对路径，允许根目录的存在
  --exclude=FILE：打包过程中忽略FILE
  
  常用命令：
  tar -jcvf filename.tar.bz2
  tar -jtvf filename.tar.bz2
  tar -jxvf filename.tar.bz2 -C destination
  ```



### 二、XFS文件系统的备份与还原

- 备份：xfsdump

  - 使用条件：
    - 文件系统必须已挂载
    - 仅支持文件系统的备份
    - 必须以root权限执行
    - 只能备份xfs文件系统
    - 备份下来的数据只能用xfsstore解析
    - 通过文件系统UUID来辨别各备份文件，因此不能备份UUID相同的文件系统
  - 用法

  ```
  xfsdump [-L S Label] [-M M label] [-l #] [-f 备份文件] 待备份数据
  xfsdump -I
  选项与参数：
  -L：xfsdump会记录每次备份的session标头，这里可以填写针对此文件系统的简易说明
  -M：xfsdump可以记录存储媒介的标头，这里可以填写此媒介的简易说明
  -l：指定等级，有0-9十个等级，默认为0，完整备份,此后依次为上一个数字对应的增量备份
  -f：类似tar 后面接产生的文件，亦可接设备文件名或其它一半文件名
  -I：从/var/lib/xfsdump/inventory列出目前备份的信息状态
  ```

- 还原：xfsrestore

  ```
  xfsrestore -I		#查看备份文件
  xfsrestore [-f backup_file] [-L S Label] [-s] 待恢复目录  #单一文件系统恢复
  xfsrestore [-f backup_file] -r 待恢复目录		#通过增量备份恢复
  xfsrestore [-f backup_file] -i 待恢复目录		#进入交互模式
  
  选项与参数：
  -I：查询备份数据，输出与xfsdump相同
  -f：后面接备份文件（也可以是设备文件）
  -L：session的Label Name，可用-l查到
  -s：接特定的目录(仅恢复该文件或目录)
  -r：如果一个备份设备内有多个文件，选择此项来完成累积恢复
  -i：进入交互模式，共高级管理员使用
  ```

### 三、光盘写入工具

- 建立镜像文件：mkisofs

  ```
  mkisofs [-o image_file] [-Jrv] [-V vol] [-m file] 待备份文件 ... -graft-point isodir=directitory
  选项与参数：
  -o：后面接想要产生的镜像文件
  -J：产生较兼容Windows的文件名结构，可增加文件名长度到64个Unicode字符
  -v：显示创建iso文件的过程
  -V vol：建立volume，类似于Windows资源管理器看到的CD卷标哦
  -m fileA：排除file，支持通配符
  -graft-point：有转嫁或移植的意思
  ```

- wodim：光盘刻录工具

  ```
  新版Centos使用wodim，wodim的一些操作链接至之前的工具cdreord
  wodim --devices dev=/dev/sr0...
  wodim -v dev=/dev/sr0 blank=[fast[all]]
  wodim -v dev=/dev/sr0 [optional_features] file.iso
  选项与参数：
  --devices:扫描磁盘总线并找出可用的刻录机，后续设备为ATA接口
  -v：在cdrecord运行过程中显示过程
  -dev=/dev/sr0:可以找出光盘的bus地址，重要
  blank=[fast[all]]:blank为抹除可重复写入的DVD-RW/CD。其中fast较快，all较完整
  [format]：对光盘进行格式化，仅针对DVD-RW格式的DVD
  ```

### 四、其它常见压缩/备份工具

- dd

  ```
  dd if="input file" of="output file" bs="block size" count="number"
  ```

- cpio

  ```
  cpio -ovcB > [file|device]		#备份
  cpio -ivcdu < [file|device]		#还原
  cpio -ivct < [file|device]		#查看
  选项与参数：
  备份：
  -o：将数据复制输出到文件或设备上
  -B：让默认的blocks可增加至5120字节，默认512字节，好处是加快大文件存储速度
  还原：
  -i：将数据或文件从设备复制到系统当中
  -d：自动建立目录
  -u：自动将较新文件覆盖较旧文件
  -t：配合-i查看cpio建立的文件或设备的内容
  共用选项与参数：
  -v：在存储过程中文件名可以在屏幕上显示
  -c：portable format方式存储（较新）
  ```

  