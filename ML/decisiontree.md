* 决策树包含一个根节点，若干个内部节点和若干个叶子节点，其中叶节点对应于决策结果，其他节点对应与一个属性测试，跟节点包含样本全集，
× 从根节点到每个叶节点的路径对应一个判定测试序列
× 决策树学习的目的是为了产生一颗泛化能力强的树
/media/awxmike/MATHWORKS_R2017`A7`/install
最近由于项目需要，需要在ubuntu下安装Matlab，具体操作如下：

* 下载完成后将iso文件挂载到linux
linux可以直接鼠标右键挂载，挂载在不同的文件夹下，切换第二章cd的时候名字一定要相同
sudo mkdir /media/matlab
mount -o loop [path][filename].iso /media/matlab
cd /media/matlab
sudo ./install
进行安装

* 安装过程中使用readme.txt中的序列号

* 破解
安装完成后使用crack下的 license进行激活
将crack文件夹下的libmwservices.so copy到  /usr/local/MATLAB/R2014A/bin/glnxa64

* 完成安装，命令行下使用sudo matlab即可启动使用
buptcsc626
* 预剪纸策略基于验证集精度和“贪心”降低了过拟合的风险，增加了欠拟合的风险
* 后剪纸策略欠拟合风险小泛化性能优于预剪纸决策树，但是训练时间很长
* 决策树的特点就是轴平行的分段组成分类空间
```
     现在才看完书，只能宿舍看习题了
　　　晚安
　　　０７／１３
```
