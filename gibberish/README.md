## this file memory Online question answering system《Gibberish》
### Following requirements
* 为“瞎扯”公司设计一个问答系统，构建一个允许用户分享知识的平台。
  * 必须用面向对象的方法（继承+多态）实现问答系统的基本功能。
  * 系统中只有用户这一种角色。
  * 用户可以使用自己的用户名和密码登录系统。
  * 用户进入系统后可以进行如下操作：
    * 查看操作：用户可查看当前所有的提问，提问按发表时间排序，顺序为由新到旧，显示问题列表时至少需显示用户和问题标题，用户选择一个提问后可以查看该提问的详细描述及其下的回答，显示回答列表时至少需要显示回答用户、回答内容以及被赞次数。
    * 提问操作：用户可以在系统中发起提问。
    * 回答操作：用户可以回答提问。
    * 点赞操作：用户可以为回答点赞，被赞的次数要能与回答一同显示。
    * 添加关注操作：用户在查看提问和回答时可以选择添加提问者或回答者为关注，用户可以查看自己关注的用户列表。
    * 注销操作：即退出登录，返回最初界面，供后续用户使用。
  * 问题需要有标题和内容两部分，回答只有内容不需要标题，一个问题可以有多个回答。
  * 在列表显示时应有分页功能。
  * 系统中可能涉及的对象有用户、问题、回答等。
  * 有用户类，用户类具有：id、name、password、focuslist等属性（其他属性可根据需求自己定义），且具有以下功能。
    * 添加用户为关注功能
  * 有BasicInfo类，BasicInfo类使用抽象类的方式实现，BasicInfo类具有id、创建者id、创建时间、内容等属性（其他属性可根据需求自己定义）
  * BasicInfo类的功能有（定义为虚函数或纯虚函数）
    * 获取属性并格式化输出；
    * 创建问题或答案。
  * BasicInfo子类有问题类和回答类，问题类须有属性title表示问题的标题，回答类须有属性praiseNum表示被赞的次数。
### Attention
* 本题主要考察对C++面向对象特性的掌握，本题需体现继承、虚函数/纯虚函数、抽象类及容器等概念的使用
* 所有用户信息，问题信息，答案信息，不强行要求以文本形式存储，可在程序内部自行定义
* 不强求关闭程序时存储程序内数据状态，即重启程序后一切可以重置
* 必须使用容器类作为保存数据的内部数据结构，可自行选择合适的容器类
* 必须使用分离式编译，各个类实现于自身的.h和.cpp文件中
* 提供字符操作界面，提供图形界面的将适当加分
### Above