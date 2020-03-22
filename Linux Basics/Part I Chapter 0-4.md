# 第一部分：Linux的规则与安装

***鸟哥的Linux私房菜* 的笔记**

## 第0章：计算机概论

### 一、基本常识

- **电脑的五大组成部分**：输入单元（如鼠标、键盘）、输出单元（如屏幕、打印机）、控制单元（CPU内部协调设备工作的组件）、算术逻辑单元（CPU内进行逻辑运算的组件）、内存
- **CPU的架构**
  - 字长：8 bit, 16 bit, 32 bit, 64 bit
  - 指令集：精简指令集（RISC）、复杂指令集（CISC）
- **电脑的分类**：超级计算机（Supercomputer)、大型计算机(Mainframe Computer)、迷你计算机（Minicomputer）、工作站（Workstation）、微电脑（Microcomputer）
- **计算机常用单位**
  - 容量单位
    - 1 Byte = 8 bit
    - B  KB  MB  GB  TB  PB  EB  ZB 采用二进制换算，1 KB = 1024 B，以此类推
  - 速度单位
    - CPU命令周期：Hz  KHz  MHz  GHz  THz  PHz  EHz  ZHz采用十进制换算，1 KHz = 1000 Hz,以此类推
    - 网络带宽 Bits/s,采用十进制换算，仅为与CPU命令周期类似

### 二、个人电脑相关架构与设备组件

- **早期主板芯片组**分为北桥（连接速度较快的CPU、显卡等，目前已经被整合进CPU中）和南桥（连接速度较慢的设备接口）

- **CPU**

  - 频率：每秒执行的工作次数（每次工作都能执行少数指令）
  - 外频与倍频：外频*倍频 = 实际频率
  - 字长：CPU每次能够处理的数据量
  - 等级：对于不同种类的CPU的规范（32位有 i386,i586,i686，64位统称x86-64)
  - 超线程：使CPU逻辑上具有比物理上多的内核，并用于多任务的级数
  - 数据会流进/流出内存是CPU发布的控制命令，CPU实际处理的数据则完全来源于内存

- **内存**

  - DRAM
    - 技术迭代：SDRAM, DDR SDRAM, DDR2/3/4/5
    - 多通道
    - 位宽：均为64-bit
    - 频率
    - 带宽=频率*位宽，单位通常为MB/s或GB/s
    - 容量
  - SRAM
    - 速度快，成本高，通常不易做成大容量，通常作为CPU的二级缓存（L2 Cache）
  - ROM

- **显卡**

  - 图像显示基本参数：分辨率、颜色深度
  - 与主板接口：PCI, PCI 2.2, PCI-X, AGP 4x, AGP 8x, PCIe 1.0 x1, PCIe 1.0 x8, PCIe 1.0 x16 , PCIe 2.0/3.0/4.0 x1~x16
  - 与电脑屏幕接口：D-Sub(VGA), DVI, HDMI, DisplayPort

- **硬盘与存储设备**

  - 主要参数：种类，容量，缓冲存储器（缓存），（机械硬盘的）转速
  - 机械硬盘（HDD）
    - 组成：圆形碟片、机械手臂、磁头、主轴马达
    - 实际运行时，主轴马达让碟片转动，机械手臂可伸展让磁头在碟片上面进行读写操作
    - 最小存储单位为山区，一个同心圆内所有山区组成磁道，所有碟片上同一磁道组成柱面
    - 传输接口：SATA，SAS，IDE（目前被SATA取代），SCSI（目前被SAS替换），USB
  - 固态硬盘（SSD）

- **拓展卡与接口**

  - PCI，AGP，PCI-X，PCIe（主流）
  - 多通道卡安装在少通道插槽，仅以少通道插槽的速度来传输数据

- **主板**

  - 设备I/O地址
  - IRQ中断请求：设备告知CPU其工作状态的方式，设备通过IRQ发送IRQ中断请求
  - CMOS：记录主板重要参数（系统时间，CPU电压/频率、各设备I/O地址与IRQ）
  - BIOS：写入主板的Flash或EEPROM的程序，在启动时执行并加载CMOS参数
  - 连接外置设备接口
    - PS/2：接传统的键盘/鼠标，近来被USB接口取代
    - USB接口：USB2.0黑色，USB3.0蓝色，USB3.1Gen1红色
    - 声音输入/输出与麦克风：圆形接口，需要主板内置音效芯片
    - RJ-45网络头
    - HDMI
  - 电源
    - 主要参数：提供功率、能源转换率s

  ### 三、数据表示方式

  - **字符编码系统**
    - 常用英文编码为ASCII，中文编码为Big5（台湾地区）/GB2312（大陆地区）/GBK（大陆地区）
    - UTF-8编码系统打破了所有国家的不同编码

  ### 四、软件程序运行

  - 机器语言编程的麻烦之处：需要了解机器语言、所有硬件的相关功能函数，程序不具有可移植性、程序具有专一性
  - 操作系统
    - 内核：管理电脑所有活动、驱动系统所有硬件的一组程序。功能包括提供系统调用接口、进程管理、内存管理、文件系统管理、设备驱动
    - 驱动程序：使操作系统支持新的硬件功能的程序

  

  ## 第1章:  Linux是什么与如何学习

  ### 一、Linux是什么

  - Linux是一个操作系统

  - 从UNIX到Linux：

    - 1969年之前，输入设备只有读卡机，输出设备只有打印机，用户无法与操作系统互动（批处理型操作系统）
    - 20世纪60年代储器，麻省理工学院发展了兼容分时系统，使大型主机能够提供数个终端
    - 1969年，Ken Tompson编写了一个小型file server system，包含了两个重要的概念：
      - 所有程序或系统设备都是文件
      - 不管是程序还是附属文件，所写的程序只有一个目的，且要有效的完成目标
    - 1973年，UNIX正式诞生，RItchie等人用C语言写出第一个正式的UNIX内核
    - 1977年，重要的UNIX分支BSD诞生
    - 1979年，AT&T退出SystemV，支持x86架构，可以在个人计算机上安装运行
    - 1984年，x86架构的Minix操作系统开始编写并于两年后诞生，Richard Mathew Stallman发起GNU计划，FSF（自由软件基金会）成立
    - 1985年，GPL（通用公共许可证）发布
    - 1988年，GUI XFree86jihua chengli 
    - 1991年，Linux诞生

  - 自由软件：用户可以自由地执行、复制、再发行、学习、修改、强化的软件，但用户不能擅自取消一个GPL授权的自由软件或单纯销售自由软件

    - 优点：
      - 软件安全性较好
      - 运行性能较好
      - 除错时间较短
      - 贡献的源代码永远存在

  - 开源软件的

    - 特征：
      - 公布源代码且用户具有修改权
      - 任意地在发布
      - 必须允许修改或衍生的作品，且可让再发布的软件使用相似的授权发表
      - 用户可使用与原本软件不同的名称或编号来发布
      - 不可限制某些个人或团体的使用权，不可限制某些领域的应用（如商业领域和学术领域），不可具有排他条款，不可限制在某些产品当中
    - 常见的开放源代码授权：
      - Apache License 2.0
      - BSD 3-Clause "New" or "Revised" License
      - BSD 2-Clause "Simplified" or "FreeBSD" License
      - GNU General Public License (GPL)
      - GNU Library or "Lesser" General Pubic License（LGPL）
      - MIT License
      - Mozilla Public License 2.0
      - Common Development and Distribution License
    - 闭源软件
      - 免费闭源软件代表的授权模式
        - Freeware
        - Shareware（提供免费的试用期）

### 二、Linux的发展

- Linux 的内核版本
  
  - 格式：`主版本.次版本.发布版本-修改版本`  eg.`3.10.0-123.e17.x86-64`
  - 若主次版本为奇数，则为开发中版本
  - 若主次版本为偶数，则为稳定版本
  - 3.0之后，奇数/偶数编号格式停用，改为分为主线版本和长期维护版本

- Linux发行版
  
  - Linux发行版=Linux内核+软件+工具+可完全安装程序
  - 分类
    
      |              | RPM软件管理                          | DPKG软件管理            | 其它未分类 |
      | ------------ | ------------------------------------ | ----------------------- | ---------- |
      | **商业公司** | RHEL(Red Hat)<br />SUSE(Micro Focus) | Ubuntu (Canonical Ltd.) |            |
      | **网络社区** | Fedora<br />CentOS<br />openSUSE     | Debian<br />B2D         | Gentoo     |

### 三、Linux的应用

- 企业环境
  - 网络服务器
  - 关键任务应用（金融数据库、大型企业网络环境）
  - 学术机构的高性能计算任务
- 个人环境
  - 桌面计算机
  - 手机系统
  - 嵌入式系统
- 云端应用
  - 云程序
  - 终端设备

### 四、Linux该如何学习

- 建议：
  - 掌握计算机概论与硬件相关只是
  - 先从Linux的安装与命令学期
  - Linux操作系统的基础技能
  - 务必学会vi文本编辑器
  - Shell与Shell脚本的学习
  - 一定要会软件管理
  - 网络基础的建立
- 发生问题怎么处理
  - Linux自己的文件数据：`/usr/share/doc`
  - [The Linux Documentation Project](http://www.tldp.org)
  - [Google](https://www.google.com)
  - [鸟哥的网站](http://linux.vbird.org/Searching.php)
  - 注意信息输出，自行解决疑难杂症
  - 查找过后，注意网络礼节，讨论区大胆发言

## 第2章： 主机规划与磁盘分区

### 一、Linux与硬件的搭配

- 新添购计算机硬件设备时，需要考虑的角度有游戏机/工作机、性能/价格比、性能/消耗瓦数比、支持度等

- 旧的硬件设备可能由于保存的问题或电子元件老化的问题，导致计算机系统非常容易在运行过程中出现不明的宕机情况

- 企业用服务器最好不要自行组装，购买商用服务器最佳

- 各硬件设备在Linux中的文件名

  | 设备            | 在Linux中的文件名                                            |
  | --------------- | ------------------------------------------------------------ |
  | SCSI, SATA, USB | /dev/sd[a-p]                                                 |
  | Virtio接口      | /dev/vd[a-p]                                                 |
  | 软盘驱动器      | /dev/fd[0-7]                                                 |
  | 打印机          | /dev/lp[0-2] (25针打印机)<br />/dev/usb/lp[0-15] (USB接口)   |
  | 鼠标            | /dev/input/mouse[0-15] (通用)<br />/dev/psaux(PS/2接口)<br />/dev/mouse(当前鼠标) |
  | CD-ROM、DVD-ROM | /dev/scd[0-1] (通用)<br />/dev/sr[0-1] (通用，CentOS较常见)<br />/dev/cdrom(当前CD-ROM) |
  | 磁带机          | /dev/ht0(IDE接口)<br />/dev/st0(SATA/SCSI接口)<br />/dev/tape(当前磁带) |
  | IDE磁盘驱动器   | /dev/hd[a-d] (旧式系统)                                      |

### 二、磁盘分区

- MBR与GPT磁盘分区表

  - MBR分区表组成（均位于磁盘第一个扇区，大小512字节）
    - 主引导记录：446字节，含有启动引导程序
    - 分区表：记录硬盘分区状态，64字节
    - 默认分区表仅能写入四组分区信息，称为主要（Primary）或扩展（Extended）分区
    - 分区的最小单位通常为柱面
    - 扩展分区最多只有一个（操作系统限制），目的是使用额外的扇区来记录分区信息，本身并不能拿来格式化
    - 从扩展分区继续分割的分区叫做逻辑分区，在Linux中的编号从5开始，如`/dev/sda5`
    - 逻辑分区的数量依操作系统而不同
    - 考虑到磁盘的连续性，一般建议讲扩展分区的柱面分配在最后的柱面内
  - MBR分区表的问题
    - 操作系统无法使用2.2TB以上的容量（因为每组分区表仅有16字节）
    - MBR仅有一个区块，若被破坏，经常无法或很难恢复
    - MBR的引导程序区块仅446字节，无法存储较多的程序代码
  - GPT分区表
    - GPT分区表为兼容所有的磁盘扇区大小，采用了逻辑区块地址（LBA）的概念来规划磁盘区块，第一个LBA为LBA0
    - GPT分区表使用了34个LBA区块来记录分区信息，且将整个磁盘的最后34个LBA区块也拿来作为备份
    - LBA0（MBR兼容区块）
      - 该区块含有特殊标识符，阻止不兼容GPT的磁盘管理程序读写整块磁盘
      - 这个区块也分为两部分，一部分存储第一阶段引导程序，另一部分存放特殊标识符（在原本MBR的分区表及录取内）
    - LBA1（GPT表头记录）
      - 记录分区表本身的位置与大小、备用GPT分区放置的位置、分区表校验码
    - LBA2-33（实际记录分区信息处）
      - 每个LBA都能提供4组分区记录，默认情况下可以有128组分区记录，最大容量限制为8ZB
    - GPT分区已经没有所谓的主、扩展、逻辑分区的概念

- BIOS与UEFI BIOS的启动过程

  - BIOS搭配MBR/GPT的启动流程

    1. BIOS：启动主动执行的固件、识别第一个可启动的设备

    2. MBR：第一个可启动设备的第一个扇区内的主引导记录快，内含启动引导代码

    3. 启动引导程序（Boot loader）：一个可读取内核文件来执行的软件，能够提供选项、加载内核文件、转交其他启动引导程序（多重引导）

    4. 内核文件：开始启动操作系统

    注：启动引导程序可以安装在MBR和每个分区的引导扇区

  - UEFI BIOS搭配GPT的启动流程

    | 比较项目             | 传统BIOS                                                     | UEFI               |
    | -------------------- | ------------------------------------------------------------ | ------------------ |
    | 使用程序语言         | 汇编语言                                                     | C语言              |
    | 硬件资源控制         | 使用中断（IRQ）管理<br />不可变的内存存取<br />不可变的输入/输出存取 | 使用驱动程序协议   |
    | 处理器运行环境       | 16位                                                         | CPU保护模式        |
    | 扩充方式             | 通过IRQ连接                                                  | 直接加载驱动程序   |
    | 第三方厂商支持       | 较差                                                         | 较佳且可支持多平台 |
    | 图形能力             | 较差                                                         | 较佳               |
    | 内置简化操作系统环境 | 不支持                                                       | 支持               |

- 磁盘分区的选择
  - 目录树结构
  - 文件系统与目录树的关系（挂载）：利用某一目录作为进入点，将磁盘分区的数据放在该目录下
  - 要找到某个文件/目录所处的进入点时，可沿目录树反向读取，先读到的进入点就是该文件/目录的进入点

## 第3章：安装CentOS 8.x

`注：原书安装的系统为CentOS7，这份笔记以CentOS8作为操作环境，在虚拟机中安装并运行，若有冲突，将展现CentOS 8的实际情况`

- 参考分区方案（磁盘总大小 40G）

  | 所需目录/设备 | 磁盘容量 | 文件系统   | 分区格式 |
  | ------------- | -------- | ---------- | -------- |
  | BIOS boot     | 2MB      | 系统自定义 | 主要分区 |
  | /boot         | 1GB      | xfs        | 主要分区 |
  | /             | 10GB     | xfs        | LVM方式  |
  | /home         | 5GB      | xfs        | LVM方式  |
  | swap          | 1GB      | swap       | LVM方式  |

- 强制使用GPT分区

  - 在初始启动界面，将光标移动到 Install CentOS 8
  - 按下**`Tab`**,让光标移动到最下方
  - 在末尾加入`inst.gpt`(注意要和前面参数保持哦那个个)，然后回车

- 在安装过程中，使用“自定义的分区模式”来处理自己规划的分区方式

## 第4章：首次登录与在线求助

### 一、首次登陆

- 图形界面与命令行模式的切换

  - 默认情况下 `Ctrl + Alt + F1 `为图形界面，`Ctrl + Alt + F2-F6`为终端

- 基本命令的执行

  - 命令的基本格式：`command [-options] parameter1 parameter2`

  - 语系的支持

    - 纯命令行模式默认不支持以中文编码输出数据
- 显示当前语系：`locale`或`echo $LANG`
    - 修改语系为英文语系：

      - `LANG=en_US.utf8` (修改输出信息显示语系)

      - `export LC_ALL=en_US.utf8` （修改全部信息的显示语系）

  - 显示日期时间：
  
     - `date`   (默认格式)  

       效果：`Tue Feb 11 17:56:31 CST 2020`

     - `date +%Y/%m/%d--%H:%M` (自定义格式) 

       效果：`2020/02/11--17:58`

     - 注：若自定义的格式中有空格，需要用双引号把自定义格式包起来（`date +"%m/%d  %H:%M"`）

  - 显示日历：`cal` (默认显示当前月份)

     - 显示整年日历： `cal 2020`
   - 基本语法：`cal [month] [year]`
  
  - 简易计算器：`bc`

     - 操作演示

     ```
   [cdn@localhost ~]$ bc
     bc 1.07.1
     Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006, 2008, 2012-2017 Free Software Foundation, Inc.
     This is free software with ABSOLUTELY NO WARRANTY.
     For details type `warranty'.  					#以上显示的是bc的版本信息
     1+2+3.323									   #支持加减乘除、幂运算、求模
     6.323										  #输入算式后回车，下一行就输出结果
     10%3
     1
     10^22
     10000000000000000000000
     10/100 											#bc默认仅输出整数（在算式中不含有小数时）
     0
     scale=3 										#将bc设置为输出小数点后三位，3可以替换成其它数
     10/100
     .100
     quit											#离开bc
     [cdn@localhost ~]$ 
     ```
  
  - 综上我们会发现命令执行的两种主要情况

     - 直接显示结果，然后回到命令提示字符等待下一个命令的输入
   - 进入到该命令的环境，直到该命令结束才回到命令行界面的环境
  
- 常用热键

  - **`Tab`**:具有命令补全和文件补全的功能
    - 接在命令的第一个字段后面，为命令补全
    - 接在命令的第二个字段后面，为文件补全
    - 如果安装了`bash-completion`，则可以在某些命令后面使用Tab进行命令选项/参数的补齐
    
  - **`Ctrl + C`**:强制中断目前正在执行的命令

  - **`Ctrl + D`**:代表键盘输入的结束，还能相当于输入exit离开命令行

  - **`Shift + PageUp`**/**`Shift + PageDn`**: 实现命令行的前后翻页

### 二、在线求助

#### 命令的`--help`求助说明

- 在几乎所有的命令之后加上 `--help`，就能够得到该命令的基本用法

#### man page

- 要查阅相关文件格式，或更为详细的解释，需要使用 man page

- 查阅格式：`man [command]    #查阅command的man page`

- 示例：输入`man date`并回车

  ```
  DATE(1)                          User Commands                         DATE(1)
  
  NAME
         date - print or set the system date and time
  
  SYNOPSIS
         date [OPTION]... [+FORMAT]
         date [-u|--utc|--universal] [MMDDhhmm[[CC]YY][.ss]]
  
  DESCRIPTION
         Display the current time in the given FORMAT, or set the system date.
  
         Mandatory  arguments  to  long  options are mandatory for short options
         too.
  
         -d, --date=STRING
                display time described by STRING, not 'now'
  
         --debug
                annotate the parsed date, and warn about questionable  usage  to
                stderr
  
         -f, --file=DATEFILE
   Manual page date(1) line 1 (press h for help or q to quit)
  ```

  - 常用操作

    | 按键      | 进行工作                                                     |
  | --------- | ------------------------------------------------------------ |
    | [Space]   | 向下翻一页                                                   |
    | [Page Dn] | 向下翻一页                                                   |
    | [Page Up] | 向上翻一页                                                   |
    | [Home]    | 第一页                                                       |
    | [End]     | 最后一页                                                     |
    | /string   | 向下（光标之后）查找string这个字符串                         |
    | ?string   | 向上（光标之前）查找string这个字符串                         |
    | n,N       | 若前面已经输入了`/string`或`?string`，可以利用n来继续下一个查找<br />（执行一次方向相同，查找字符串相同的查找），用N来执行上一个查找<br />（执行一次方向相反，查找字符串相同的查找） |
    | q         | 退出man page                                                 |

    

  - 示例中左上角的`Date(1)`中的（1）代表一般用户可使用的命令，详细数字代表信息见下表：

    | 代号（加粗为重要） | 代表内容                                                     |
  | ------------------ | ------------------------------------------------------------ |
    | **1**              | **用户在shell环境中可以操作的命令或可执行文件**              |
    | 2                  | 系统内核可调用的函数与工具                                   |
    | 3                  | 常用函数（function）与函数库（library），大部分为C语言函数库（libc） |
    | 4                  | 设备文件说明，通常为/dec下的文件                             |
    | **5**              | **配置文件或是某些文件的格式**                               |
    | 6                  | 游戏（games）                                                |
    | 7                  | 惯例与协议等，例如Linux文件系统、网络协议、ASCII代码等的说明 |
    | **8**              | **系统管理员可用的管理命令**                                 |
    | 9                  | 与内核有关的文件                                             |

    输入`man man`可以获取更多关于此表格的相应说明。
    
  - man page的组成

    | 代号        | 内容说明                                       |
    | ----------- | ---------------------------------------------- |
    | NAME        | 简短的命令/数据名称说明                        |
    | SYNOPSIS    | 简短的语法（syntax）简介                       |
    | DESCRIPTION | 较为完整的说明，最好仔细看看。                 |
    | OPTIONS     | 针对SYNOPSIS部分中，有列举的所有可用选项的说明 |
    | COMMANDS    | 程序执行时可以在此程序中执行的命令             |
    | FILES       | 此程序或数据所使用/参考/链接到的文件           |
    | SEE ALSO    | 可以参考的与此命令/数据相关的其他说明          |
    | EXAMPLE     | 范例                                           |
    
  - 使用man命令时，会按照/etc/man_db.conf文件的顺序查找，默认显示最先查找到的说明文件，若要实现其余查找功能，请自行man man

  - 与man有关的还有两个命令：

    ```
    whatis [string]  #相当于 man -f [string] （列出man page中所有与string有关的说明文件，而不是首个）
    apropos [string] #相当于 man -k [string] （列出man page中包含string的所有说明）
    ```
#### info page

- info与man的不同：将说明文件数据拆成一个一个段落，每个段落用自己的页面来便携，各个页面中还有类似网页的超链接来跳到不同的页面中

- info操作说明

  | 按键      | 进行工作                             |
  | --------- | ------------------------------------ |
  | [Space]   | 向下翻一页                           |
  | [Page Dn] | 向下翻一页                           |
  | [Page Up] | 向上翻一页                           |
  | [Tab]     | 在节点之间移动（节点通常会用*标示）  |
  | [Enter]   | 当光标在节点上面时，按此键进入该节点 |
  | b         | 移动光标到该info界面的第一处         |
  | e         | 移动光标到该info界面的最后一处       |
  | n         | 前往下一个节点处                     |
  | p         | 前往上一个节点处                     |
  | u         | 向上移动一层                         |
  | s (/)     | 在info page中进行查找                |
  | h (?)     | 显示帮助选项                         |
  | q         | 结束此次info page                    |
  
- CentOS 8的info文件位置: `/usr/share/info`

#### 其它有用的文件（Documents）：位于`/usr/share/doc`

- 总结
  - 命令行模式中，若知道某个命令，但忘记了相关选项与参数，请先使用`--help`来查询相关信息
  - 若希望了解命令或文件的格式，可使用man或者info
  - 若想架设其它服务，或利用一整组软件来完成某项功能，请在`/usr/share/doc`中查看是否有该服务的说明文件
  - 可以安装一些字典软件助力帮助文档的阅读（如Golden Dict、Star Dict）

#### 简单的文本编辑器：Nano

#### 正确的关机方法

- Linux环境下可能有多人同时在主机上工作，且由于其采用异步磁盘写入，非正常关机可能造成文件系统的损毁

- 关机时的注意事项

  - 观察系统的使用状态

    ```
    who 	#查看目前有谁在线
    netstat -a #查看网络联机状态
    ps -aux #查看当前后台程序
    ```
    
  - 数据同步写入磁盘：sync
  
    - root身份执行sync，可更新整个系统的数据，一般账号执行sync，仅更新自己的数据
    - 目前shutdown、reboot、halt等均已集成了sync
  
  - shutdown
  
    ```
    shutdown [OPTIONS...] [TIME] [WALL...]
    
    Shut down the system.
    
         --help      Show this help
      -H --halt      Halt the machine
      -P --poweroff  Power-off the machine
      -r --reboot    Reboot the machine
      -h             Equivalent to --poweroff, overridden by --halt
      -k             Don't halt/power-off/reboot, just send warnings
         --no-wall   Don't send wall message before halt/power-off/reboot
      -c             Cancel a pending shutdown
    ```
  
    
  
  - reboot、halt、poweroff
  
    - 一般情况下，三个命令效果相同，都调用了systemctl
    - 使用halt，系统停止，屏幕可能会保留系统已经停止的信息
    - 使用poweroff，系统关机，没有提供额外电力，屏幕空白
  
  - 使用systemctl关机
  
  - 建议作为服务器的Linux主机加上UPS来提供稳定电源