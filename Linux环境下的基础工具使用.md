@[TOC](文章目录)



---



# 1. Linux环境下的软件包管理器---- yum  



## 1.2 什么是软件包  



> 在Linux下安装软件, 一个通常的办法是下载到程序的源代码, 并进行编译, 得到可执行程序.
> 但是这样太麻烦了, 于是有些人把一些常用的软件提前编译好, 做成软件包(可以理解成windows上的安
> 装程序)放在一个服务器上, 通过包管理器可以很方便的获取到这个编译好的软件包, 直接进行安装.
> 软件包和软件包管理器, 就好比 "App" 和 "应用商店" 这样的关系.
> yum(Yellow dog Updater, Modified)是Linux下非常常用的一种包管理器. 主要应用在Fedora, RedHat,
> Centos等发行版上.  





## 1.3 yum源镜像配置



配置源的作用：

**yum源本身使用的是国外的源，下载时一般速度比较慢，这时候可以配置成国内的源提升下载速度**



```shell
以centos7为例子 修改yum源为阿里源
///////////////////////////////////////////////
首先是到yum源设置文件夹里
1. 查看yum源信息:
    yum repolist
2. 定位到base reop源位置
     cd /etc/yum.repos.d
3. 接着备份旧的配置文件
    mv CentOS-Base.repo CentOS-Base.repo.bak
4. 下载阿里源的文件
  wget -O CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-7.repo
  或者163的源
  wget http://mirrors.163.com/.help/CentOS7-Base-163.repo  
5.清理缓存
    yum clean all
6.重新生成缓存
    yum makecache
7. 再次查看yum源信息
   yum repolist
```









## 1.4 yum查看软件包  



注意事项  

关于 yum 的所有操作必须保证主机(虚拟机)网络畅通

可以通过 ping 指令验证是否联网

```shell
ping www.baidu.com
```



出现下面的字段说明已经联网（按键盘Ctrl+c退出）

![image-20221022201857503](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210222020914.png)



通过 yum list 命令可以罗列出当前一共有哪些软件包. 由于包的数目可能非常之多, 这里我们需要使用 grep 命令只
筛选出我们关注的包. 例如:  我们来搜索一下gcc



```shell
yum list | grep gcc
```



![image-20221022202958782](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210222029891.png)







注意事项: 

>软件包名称: 主版本号.次版本号.源程序发行号-软件包的发行号.主机平台.cpu架构.
>"x86_64" 后缀表示64位系统的安装包, "i686" 后缀表示32位系统安装包. 选择包时要和系统匹配.
>"el7" 表示操作系统发行版的版本. "el7" 表示的是 centos7/redhat7. "el6" 表示 centos6/redhat6.
>最后一列, base,epel等 表示的是 "软件源" 的名称, 类似于 "小米应用商店", "华为应用商店" 这样的概念.  





## 1.5 yum 如何安装软件  





我们可以通过yum尝试把gcc下载到Linux



```shell
sudo yum install  -y gcc//加-y是不想让再次询问是安装（一律通过的意思）
```



yum 会自动找到都有哪些软件包需要下载, 如果没加-y这时候敲 "y" 确认安装  

出现 "complete" 字样, 说明安装完成.  



【注意事项】

> 安装软件时由于需要向系统目录中写入内容, 一般需要 sudo 或者切到 root 账户下才能完成.
> yum安装软件只能一个装完了再装另一个. 正在yum安装一个软件的过程中, 如果再尝试用yum安装另外
> 一个软件, yum会报错.
> 如果 yum 报错, 请自行百度.   



## 1.6 yum 如何卸载软件  



仍然是一条命令:  



```shell
sudo yum remove gcc
```



卸载时一般它会询问是否继续卸载，y确定卸载，n反悔

![image-20221022204450182](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210222044224.png)





---



# 2. Linux编辑器--vim   

## 2.1 vim 简介



> Vim是从 [vi](https://baike.baidu.com/item/vi/5043202?fromModule=lemma_inlink) 发展出来的一个文本编辑器。代码补全、编译及错误跳转等方便编程的功能特别丰富，在程序员中被广泛使用，和Emacs并列成为类Unix系统用户最喜欢的文本编辑器。 [1] 

> vim的设计理念是命令的组合。用户学习了各种各样的文本间移动/跳转的命令和其他的普通模式的编辑命令，并且能够灵活组合使用的话，能够比那些没有模式的编辑器更加高效的进行文本编辑。同时VIM与很多快捷键设置和[正则表达式](https://baike.baidu.com/item/正则表达式?fromModule=lemma_inlink)类似,可以辅助记忆。并且vim针对程序员做了优化。



这里只讲vim的三种模式(其实有好多模式，目前掌握这3种即可),分别是**命令模式（command mode）、插
入模式（Insert mode）和底行模式（last line mode）**，各模式的功能区分如下  



+ 正常/普通/命令模式(Normal mode)  

> 控制屏幕光标的移动，字符、字或行的删除，移动复制某区段及进入Insert mode下，或者到 last line mode  

+ 插入模式(Insert mode)  

>只有在Insert mode下，才可以做文字输入，按「ESC」键可回到命令行模式。该模式是我们后面用的最频繁
>的编辑模式。  

+ 末行模式(last line mode)  

>文件保存或退出，也可以进行文件替换，找字符串，列出行号等操作。 在命令模式下，shift+: 即可进入该模
>式。要查看你的所有模式：打开vim，底行模式直接输入  :help vim-modes  





![image-20221022205322260](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210222053317.png)





![image-20221022205346737](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210222053817.png)



![image-20221022205505210](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210222055338.png)





## 2.2 . vim的基本操作  



1. 进入vim,在系统提示符号输入vim及文件名称后，就进入vim全屏幕编辑画面:  

不过有一点要特别注意，就是你进入vim之后，是处于[正常(命令)模式]，你要切换到[插入模式]才能够输入文
字。  

+ [命令模式]切换至[插入模式]  

1. 输入a（在当前位置之前插入）

2. 输入i（在当前位置之后插入(追加)）

3. 输入o  （在当前行的下一行插入）

```shell
vim test.c
```

![image-20221022205835699](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210222058843.png)









+ [插入模式]切换至[正常模式]  

>目前处于[插入模式]，就只能一直输入文字，如果发现输错了字,想用光标键往回移动，将该字删除，可
>以先按一下「ESC」键转到[正常模式]再删除文字。当然，也可以直接删除  





+ [命令模式]切换至[末行模式]  

>「shift + ;」, 其实就是输入「:」  



![image-20221023194014579](C:/Users/Administrator/AppData/Roaming/Typora/typora-user-images/image-20221023194014579.png)





+ 退出vim及保存文件,在[正常模式]下，按一下「:」冒号键进入「末行模式」,例如  



> : w （保存当前文件）  
>
> : wq (输入「wq」,存盘并退出vim)  
>
> : q! (输入q!,不存盘强制退出vim)  

![image-20221023194223991](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210231942166.png)





## 2.3 vim命令模式下的命令集 



 ### 2.3.1 光标移动



简单的移动命令

```shell
 h 左移
 l 右移
 k 上移
 j 下移
 
按「G」：移动到文章的最后
按「 $(shift+4) 」：移动到光标所在行的“行尾”
按「^(shift+6)」：移动到光标所在行的“行首”
按「w」：光标跳到下个字的开头
按「e」：光标跳到下个字的字尾
按「b」：光标回到上个字的开头
按「#l」：光标移到该行的第#个位置，如：5l,56l
按［gg］：进入到文本开始
按［shift＋g］：进入文本末端
按「ctrl」+「b」：屏幕往“后”移动一页
按「ctrl」+「f」：屏幕往“前”移动一页
按「ctrl」+「u」：屏幕往“后”移动半页
按「ctrl」+「d」：屏幕往“前”移动半页
```

很显然，这几个命令只在命令模式下可用，当然，你可以用方向键(在所有模式下适用)



### 2.3.2 编辑

在Vim中，插入文本是很简单的事情，只需要敲i并且开始输入.但是vim提供了相当丰富的文本编辑命令

+ **删除文字**  

```shell
「x」：每按一次，删除光标所在位置的一个字符
「#x」：例如，「6x」表示删除光标所在位置的“后面（包含自己在内）”6个字符
「X」：大写的X，每按一次，删除光标所在位置的“前面”一个字符
「#X」：例如，「20X」表示删除光标所在位置的“前面”20个字符
「dd」：删除光标所在行
「#dd」：从光标所在行开始删除#行
```



+ **复制**

  

```shell
「yw」：将光标所在之处到字尾的字符复制到缓冲区中。
「#yw」：复制#个字到缓冲区
「yy」：复制光标所在行到缓冲区。
「#yy」：例如，「6yy」表示拷贝从光标所在的该行“往下数”6行文字。
「p」：将缓冲区内的字符贴到光标所在位置。注意：所有与“y”有关的复制命令都必须与“p”配合才能完
成复制与粘贴功能。
```



+ **替换** 

```shell
「r」：替换光标所在处的字符。
「R」：替换光标所到之处的字符，直到按下「ESC」键为止。
```



+ **撤销上一次操作**

  

```shell
「u」：如果您误执行一个命令，可以马上按下「u」，回到上一个操作。按多次“u”可以执行多次回复。
「ctrl + r」: 撤销的恢复
```



+ **更改**

  

```shell
「cw」：更改光标所在处的字到字尾处
「c#w」：例如，「c3w」表示更改3个字
```



+ **跳至指定的行**

  

```shell
「ctrl」+「g」列出光标所在行的行号。
「#G」：例如，「15G」，表示移动光标至文章的第15行行首
```



---





## 2.4 vim末行模式下的命令集



在使用末行模式之前，请记住先按「ESC」键确定您已经处于命令模式模式，再按「shift+;」即可进入末行模式。  



+ **列出行号**

  

```shell
「set nu」: 输入「set nu」后，会在文件中的每一行前面列出行号
```







+ **跳到文件中的某一行**  

```shell
「#」:「#」号表示一个数字，在冒号后输入一个数字，再按回车键就会跳到该行了，如输入数字15，再回车，就会跳到文章的第15行
```





+ **查找字符**

  

```shell
「/关键字」: 先按「/」键，再输入您想寻找的字符，如果第一次找的关键字不是您想要的，可以一直按「n」会往后寻找到您要的关键字为止。

「?关键字」：先按「?」键，再输入您想寻找的字符，如果第一次找的关键字不是您想要的，可以一直按「n」会往前寻找到您要的关键字为止
```



+ **保存文件**

  

```shell
「w」: 在冒号输入字母「w」就可以将文件保存起来
```



+ **离开vim**  



```shell
「q」：按「q」就是退出，如果无法离开vim，可以在「q」后跟一个「!」强制离开vim。
「wq」：一般建议离开时，搭配「w」一起使用，这样在退出的时候还可以保存文件
```





## 2.5 vim配置原理和配置插件推荐

原生的vim没有任何插件，用起来会非常不顺畅，这个时候可以根据自己是需求去安装一下插件，以便编辑。

### 2.5.1配置文件的位置  

```shell
在目录 /etc/ 下面，有个名为vimrc的文件，这是系统中公共的vim配置文件，对所有用户都有效。（一般不推荐配置全局的vim）
而在每个用户的主目录下，都可以自己建立私有的配置文件，命名为：“.vimrc”。例如，/root目录下，
通常已经存在一个.vimrc文件,如果不存在，自己手动创建就可以。
切换用户成为自己执行 su ，进入自己的主工作目录,执行 cd ~
打开自己目录下的.vimrc文件，执行 vim .vimrc即可进行配置
```



## 2.5.2 常用配置选项  

```shell
//只需把下面的代码放进.vimrc即可
设置语法高亮: syntax on
显示行号: set nu
设置缩进的空格数为4: set shiftwidth=4
```



## 2.5.3 vim的一键自动配置

参考资料--->

[VimForCpp]: https://gitee.com/HGtz2222/VimForCpp?_from=gitee_search

##  安装方法

在 shell 中执行指令(想在哪个用户下让vim配置生效, 就在哪个用户下执行这个指令. 强烈 "不推荐" 直接在 root 下执行):

```shell
curl -sLf https://gitee.com/HGtz2222/VimForCpp/raw/master/install.sh -o ./install.sh && bash ./install.sh

```

出现下面的结果说明已经安装成功

![image-20221023204433217](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210232044293.png)

##  卸载方法

在安装了 VimForCpp 的用户下执行:

```shell
bash ~/.VimForCpp/uninstall.sh
```



更多vim知识请参考资料--->

[Vim从入门到牛逼(vim from zero to hero)]: https://github.com/wsdjeg/vim-galore-zh_cn



## 2.6 vim操作总结  



![image-20221023202713489](https://iubaopicbed.oss-cn-shenzhen.aliyuncs.com/img2/picbed202210232027587.png)





----

