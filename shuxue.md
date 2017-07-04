## 数字逻辑实验报告 ##
### 日志 ###
   ##### 2017.06.29 ##### 
   上午布置试验任务，熟悉设备；
   下午学习vhdl语言，初步设计计数器器件原理图，确定系统时钟的频率，确定输入输出。然后初步用vhdl构建十进制计数器，六进制计数器.并且生成原件，在Block Diagram
```vhdl
  process(DD,BB,CC,AA)
    	variable x:std_logic_vector(3 downto 0);
		begin
		x:=DD&CC&BB&AA;
		case x is
			when"0000"=>y<="1111110";--0
			when"0001"=>y<="0110000";--1
			when"0010"=>y<="1101101";--2
			when"0011"=>y<="1111001";--3
			when"0100"=>y<="0110011";--4
			when"0101"=>y<="1011011";--5
			when"0110"=>y<="0011111";--6
			when"0111"=>y<="1110000";--7
			when"1000"=>y<="1111111";--8
			when"1001"=>y<="1111011";--9
			when others=>y<="0000000";
		end case;
		end process;
  }
```
   文件中连接所声成的部件，在Assignments->Pin planner中锁定输入输出对应的管脚，编译，并且通过Tools->Programmer下载到max 7000s中，并且首次在tec-8中实现了初步的demo
    对两个项目进行了讨论，确定了自底向上，vhdl语言和原理图混编的设计模式。在对两个项目的讨论中发现，两个项目的共性很大，逻辑原件基本可以公用，针对细小的差别做微调即可。大体上都可以分为两个模块，一个计数模块，一个发声模块。计数模块的基本原件为计数器，计数器需要有计数，清零，置数，发出警告的功能。发声模块，需要一个激励信号。。。。。。
   ##### 2017.06.30 #####
   开始调试电子时钟，调试目标分为六个阶段：
   * 试验台上的6个数码管显示正确的时、分、秒。
        * 刚开始最后一个数字总是有乱码，并且在没有信号的时候乱跳，改进方法：重新设计七段译码器，删除无用的逻辑判断，增加。
        * 宏单元数量是89
   * 能使电子钟复位（清零）。
        * 在计数器上设置clr信号，当产生一个上升沿的信号时，数位清零。
        * 清零后逻辑不正常，出现乱码，解决办法：对所有不在使用状态的接口接地。并且不再使用系统上的清零端口进行清零操作，使用QD端口代替
	
        * 停止后不能再次启动。改进方法：在每一次clk信号后面检测k1的信号，防止无效的时候，无法启动，实现实时对应。
        * 停止后再次启动从零开始，改进方法：在每次暂停的时候锁定当前定时器状态，在下次k1信号有效时继续。
   * 修改时、分、秒的值。
        * 在启停逻辑的基础上，将启停逻辑改变为修改逻辑，在每次切换到修改逻辑的时候，如果没有任何端口有效的情况下，闪烁，闪烁的频率与时钟频率相同，修改位置对应六个开关，没一个有效的时候就能接受从qd来的信号并随之增加，设置完之后，当前数码管显示的是设置的目标时间，当k2有效时就会把数目关时间设置为当前的时间并且开始计时
        * 闪烁的时候有可能出现闪烁过于快，而不是信号的时间，这个时候可能是系统内部时钟干扰。
        * 修改以后从零开始，解决办法：每次设置修改状态之前，将当前状态保存，根据k2的状态确定究竟是用修改后的值还是之前的值。        
##### 2017.07.01 #####
* 增加提醒音乐模块。
     * 先单独的写好音乐模块，发声频率的算法：根据系统的时钟，如果声音频率的时钟信号是10000hz，那么当输入的数是10000/声音频率/2的2进制码时，扬声器          发出对应频率的声音。
     * 声音模块占用了太多宏单元，改变发声模式，由一段音乐改变为单一音调的声音
* 具有报时功能，整点时喇叭鸣叫。
     * 在每次到达整点信号的时候就抛出一个脉冲，音乐模块在接收到脉冲时候发出间断报时的声音。
     * 在每次设置闹钟的时候就在闹钟模块单独记录当前的小时数，分钟数，并且在下次达到与寄存器保存时间相同的时候就调用音乐模块发出声音，提醒用户。
     * 整点的时间由生活体验来说-一般采用间断报时，发出滴滴声，在写代码的过程中存在频率互相干扰的问题，这样就不能 在播发结束声音之后继续计时，后来改变声音的频率源，问题就解决了
     * 针对药片系统，调用了和电子钟相同的计数器，对信号变量名做了微调，并舍去一些不需要的功能，进行调试。
     * 问题：所有药片装完之后，当前药瓶所属的计数器仍在计数。解决方案：对使能端增加一个判断，只有在工作端口有效和药片未装完同时符合条件的情况下，药瓶才能继续装片。
     ##### 2017.07.02 #####
     * 对整点报时功能进行调试。
     * 我们开始以第四个技术器的进位信号为整点报时信号，但是调试过程中发现这个信号会持续10分钟，导致报时效果不够理想，权衡之后决定对该技术器进行微调，使之产生一个报时的脉冲。
     * 一番调试之后发现报时功能成功实现，但报时提前了10分钟，并且该功能会导致每次一到50分的时候所有计数器整体清零
      ##### 2017.07.03 #####
      * 发现了代码中的严重漏洞，在对报时这个特性进行修改的时候没有将旧的实现删去，导致了7.02最后的bug
      * 报时功能实现，相应的药片系统的提示音也得到实现
      * 实现提示音的间断发声
      代码
      * 增加闹钟功能
      * 资源不够。
      * 优化，对秒计时器进行合理的取舍，删除了闹钟的功能，只在分和时的计数器上进行闹钟的判断。
      * 仍不够，对代码逻辑进行了梳理，删去了一个中间信号，将中间一系列的 if..else  语句进行了整合，节省了很多资源。
      修改前
      process(clk)
		begin
		
		if(clk'event and clk='1' ) then
			q2<=q1;
		if(set1='1')	then		
			if(flag='0') then
				flag<='1';
			else
				flag<='0';
				q2<="1111";
			end if;
		end if;

		if(set0='0') then
			q<=q_temp;
		else 
			q<=q2;
		end if;
		end if;
		end process;
	process(add)--set
		begin
		if (set0='1' and set1='1' and (add'event and add='1')) then
			if(q1="1001") then q1<="0000";
			else q1<=q1+1;
			end if;
		end if;
      修改后
      	process(clk1)
		begin
		if(clk1'event and clk1='1') then
			if(set0='0' and set1='0') then
				q<=q_temp;
			elsif(set0='1' and set1='0') then 
				q<=q1;
			else	
				if(flag='0') then
					flag<='1';
					q<=q1;
				else
					flag<='0';
					q<="1111";
				end if;
			end if;
		end if;
	end process;
      ##### 2017.07.04 #####
      * 对闹钟功能进行调试
      * 实现音乐闹钟，从1
      * 药片方面增加药瓶数的显示功能。
      * 做了二分频，使药片从一秒加一个变成两秒加一个，符合题目要求
### 优化日志 ###
* 计数器优化：对计数器的管脚进行合理性评估，比如六进制代码就不需要四个输出端口，而是通过默认只输出低位信号而把高位信号接地因此来节省mocrocell数量，但是这样会对闪烁功能造成影响，进一步迭代，保留了四个输出端口，但在内部经行操作时，只对第三位的信号进行操作，只在需要闪烁时对高位信号进行操作，对计数器进行特化，虽然增加了代码的数量但是显著降低了使用的管脚。在代码逻辑方面，
* 在绘制原理图的过程中，由于第一次绘制没有考虑到后期很多的功能以及功能之间的复用，原理图之间的逻辑混乱，连线错综复杂，无奈之下只能重新绘图，增加了开发的时间。
* 绘制的过程中产生了无用的管脚，以为不会占用微核，但是却超过了，后来发现把能服用的信号尽量进行复用就可以减少微核的数量，整个原理图中只使用一个vcc和gnd
* 音乐模块在刚开始的时候增加了乐曲模块，但是占用了很多的资源，并且在音乐发声频率的选择上，与占用的系统内核大大相关，如果使用100000hz的信号那么音调的长度占用的vector大小是11为，但是如果改用10000hz 就可以降低到4bit，减少了微核的占用量还可以加速开发，但是这种方式会显著的降低音质，因为频率数在表达的硬件中只有整数，所以就降低了音阶的准确性
* 在显示的过程中数码管的显示并不稳定，原因就是有很多端口没有输入信号的话就会出现乱码，所以优化的过程中，我们减少无用的信号口，降低信号的接口，降低占用的微核，在七段译码的模块中，去除了无用的变量代换，直接把输入信号输出，降低逻辑难度，简化设计


### 设计亮点 ###

### 参考论文 ###
* 基于硬件描述语言(VHDL)的数字时钟设计[J]. 刘君,常明,秦娟,张晟,耿璐.  天津理工大学学报. 2007(04)
* FPGA系统设计与实例[M]. 人民邮电出版社 , 杨晓慧, 2009
* Hardware design and implementation of a novel ANN-based shaotic generator in FPGA[J]. Murat Alçin,İhsan Pehlivan,İsmail Koyuncu.  Optik - International Journal for Light and Electron Optics.
   
   