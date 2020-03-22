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