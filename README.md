# Hand

北京大学图形学课程小作业代码。

> 注：Assimp是经过裁剪的版本，只支持FBX文件的导入



## 作业代码编译

于/third_party中添加了imgui相关文件并在/third_party/CMakeLists.txt添加了一行

    add_subdirectory(imgui)

用于生成imgui库

同时在/src中添加了hand_motion.h声名并实现相关骨骼动作动画.

对Linux平台，在本地运行时需要在主目录下

    $ cmake .
    $ make

之后会在/src里生成Hand可执行文件

    $ cd src
    $ ./Hand

或在当前目录

    ./src/Hand

均可运行.

### 特别提示

注意到/src/config.h是由/src/config.h.in生成得到的，且/src/config.h内对文件路径使用了绝对路径，故而代码在移动后需要重新cmake生成新路径下的/src/config.h内容.

## 代码运行

### 动画

代码运行后会得到手的渲染结果，鼠标点击ui界面中的按钮，手便会进行相应动作.

其中Scissor Paper Rock Game部分下有四个单选按键ready,scissor,paper,rock分别表示准备动作，剪刀，布，石头. 准备动作为静态握拳，其余动作为单词动画，并会定格在最后一步. 再下一行有random按键，点击后手会随机在剪刀石头布里选择一个执行.

Hand Gun下有两个按钮：aiming为静态瞄准动作；shoot!为枪击动作，执行完毕后会定格在最后一步.

Good Good下只有一个winwin按钮，点击后手会6.

### 镜头移动

W/S/A/D分别可以上/下/左/右平移镜头.

Up/Down/Left/Right(小键盘的上下左右键)可以在对应方向上转动镜头.