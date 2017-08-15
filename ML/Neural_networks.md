* 神经网络是由具有适应性的简单单元组成的广泛并行互联的网络，他的组织能够模拟生物神经系统对真实世界物体所做出的交互反应
* 非线性可分问题使用多层功能神经元，例如异或问题使用两层感知，输入与输出层间的神经元被称为隐含层神经元
* 每层神经元与下层神经元全互联，不存在同层互联，也不存在跨层互联，这样的神经网络称为多层前馈神经网络(multi-layer feedforward nerual neetworks)
* 神经网络学到的东西蕴含在连接权与阈值中
* 误差逆传播算法（error backpropagation,简称BP）
* 神经网络中必须要有非线性的激活函数，无论是在隐层，还是输出层，或者全部都是。如果单用wtx作为激活函数，无论多少层的神经网络会退化成一个线性回归，只不过是把他复杂化了。
* 学习率的影响：如果学习率太低，每次下降的很慢，使得迭代次数非常多。 如果学习率太高，在后面迭代时会出现震荡现在，在最小值附近来回波动。
* BP改进算法，能通过动态学习率显著提升收敛速度
    * Neural Networks: Tricks of the Trade
    * Neural Smithing:Supervised learning in Feedforward Artificial Neural Networks
* 试推导用于Elman网络的BP算法。
```go
Elman比正常网络多了个反馈，把前一次的bh作为隐层的输入来调节隐层。 
假设用uih来表示反馈输入与隐层连接的参数，由于前一次计算的bh作为常数输入
uij与vij的计算方法一样，Δuih=ηehbh，其中e_h书上5.15给出。
就是相当于多了几个输入会变的输入层神经元。
```
* [Neural Network](http://playground.tensorflow.org)
* 三天才看完神经网络，接下来就是聚类
* [相关问题/代码](http://blog.csdn.net/golden1314521/article/details/45053809#t1)
* 要注重代码实现
