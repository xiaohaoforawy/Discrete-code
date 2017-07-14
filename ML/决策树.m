%{
    x:样本属性  连续变量直接用数值,离散变量用1，2，3区别
    y:样本分类值  1-好 2-不好
    tree:生成的树形结构，用数组表示 按先根遍历编号 值为父节点编号 1为根节点
    treeleaf:标记是否为叶子节点
    treeres:每组3个变量
            1:如果是叶子节点则记录分类 如果是非叶节点记录当前节点的分类属性
            2:离散属性直接记录父节点分类的具体属性 连续属性1-小于 2-大于
            3:如果是连续属性，记录阀值，离散属性为0
    ptr:节点数目累加变量
%}
global x y fenlei1 fenlei xigua; 
global tree treeleaf treeres ptr;

x = xlsread('C:\Users\icefire\Desktop\ml\西瓜3.xlsx', 'sheet1', 'A1:Q8');
y = xlsread('C:\Users\icefire\Desktop\ml\西瓜3.xlsx', 'sheet1', 'A9:Q9');

%西瓜属性的中文标识
fenlei1={'色泽',  '根蒂',   '敲声',   '纹理',   '脐部'    ,'触感','密度','含糖率'};
fenlei={
 '青绿','蜷缩', '浊响',   '清晰',   '凹陷',   '硬滑','小于','小于';
'乌黑',   '稍蜷',   '沉闷',   '稍糊',   '稍凹',   '软粘','大于','大于';
'浅白',   '硬挺',   '清脆',   '模糊',   '平坦',   '无','无','无';
};
xigua = {'好瓜','坏瓜'};

[m,n]=size(y);
%为set集合提前分配空间 集合中存放所有样本的编号
for i=n:-1:1
    set(i) = i;
end

%为tree相关变量提前分配空间
tree=zeros(1,100);
treeleaf=zeros(1,100);
treeres=cell(3,100);
ptr = 0;
%{
手动设置的变量:修改输入数据时要收到修改
    pf：属性的编号，按顺序编号
    pu：属性是连续还是离散的0-离散 1-连续
    pt：属性对应的分类数，连续属性用不着(可以设为0)
%}
pf=[1 2 3 4 5 6 7 8];
pu=[0 0 0 0 0 0 1 1];
pt=[3 3 3 3 3 2 0 0];

%主递归程序
TreeGenerate(0,set,pf,pu,pt);

%绘制树形 仅有树形
treeplot(tree(1:ptr));
%{
    parent:父节点编号
    curset:当前的样本编号集合
    pf:当前的属性编号集合
%}


function TreeGenerate(parent,curset,pf,pu,pt)
global x y xigua fenlei1 fenlei; 
global tree treeleaf treeres ptr;
       %新增一个节点，并记录它的父节点
       ptr=ptr+1;
       tree(ptr)=parent;
       cur = ptr;

       %递归返回情况1:当前所有样本属于同一类
       n = size(curset);
       n = n(2);

       %计算当前y的取值分类及各有多少个  如果只有一类表示属于同一类
       cury=y(curset);  %通过当前样本编号从所有样本中选出当前样本
       y_data=unique(cury); %集合去重
       y_nums=histc(cury,y_data);   %统计各个取值各多少个

       if(y_nums(1)==n) 
            treeres{1,ptr} = xigua{y_data};
            treeleaf(cur) = 1;
            return;
       end

       %递归返回情况2:
       %属性已经全部划分还有不同分类的样本，或者所有样本属性一致但是分类不同(这时就是有错误的样本)
       pfn=size(pf);    %记录当前属性个数

       tmp_para = x(pf,curset(1));
       f = 1;
       classy = y(curset(1));
       sum=zeros(1,2);
       for i=1:n
            if isequal(tmp_para , x(pf,curset(i)))
                t = (classy == y(curset(i)));
                sum(t) = sum(t)+1;
            else
                f=0;
                break;
            end
       end
       if(f == 1 || pfn(2) == 0) 
            treeres{1,cur} = xigua{(sum(2)>=sum(1))+1};
            treeleaf(cur) = 1;
            return;
       end

       %主递归
       %实现了4个最优属性选择方法,使用了相同的参数与输出:信息增益，增益率，基尼指数，对率回归
       %具体参数介绍间函数具体实现
       %因为是相同的参数与输出，直接该函数名就能换方法
       [k, threshold] = entropy_paraselect(curset,pf,pu);
       curx = x(pf,:);  %通过属性编号从样本总体中选取样本(已经分类的离散属性不再需要)
       p_num=pf(k);       %记录当前属性的具体编号
       treeres{1,cur} = fenlei1{p_num};%记录当前节点的分类属性

       %离散与连续属性分别处理
       if(pu(k))    %连续属性
           %连续属性只会分为两类 大于阀值一类 小于阀值一类 分类后继续递归
             num = [1 1];
             tmp_set = zeros(2,100);
             for i=1:n
                if(curx(k,curset(i))>=threshold)
                    tmp_set(1,num(1))=curset(i);
                    num(1) = num(1)+1;
                else
                    tmp_set(2,num(2))=curset(i);
                    num(2) = num(2)+1;
                end
             end
             for i=1:2
                    %由于用数组存编号，会有0存在，将样本分开后与当前的样本求交集  把0去掉
                    ttmp_set = intersect(tmp_set(i,:),curset);  

                    treeres{2,ptr+1} = fenlei{i,p_num};               %记录分类具体属性
                    treeres{3,ptr+1} = threshold;       %记录阀值
                    TreeGenerate(cur,ttmp_set,pf,pu,pt);
             end
       else
            %离散型分类要按每个取值分，就算某个取值下样本为0，也要标记为当前样本下最多的一个分类
            tpt=pt(k);  %该属性对应多少情况

            pf(:,k)=[]; %离散属性只分一次，用完就从集合中去掉
            pu(:,k)=[];
            pt(:,k)=[];
            %记录每种属性取值下对应的正反例各是多少
            num = ones(1,tpt);
            tmp_set = zeros(tpt,100);
            n=size(curset);
            for i=1:n(2)             
               tmp_set(curx(k,curset(i)),num(curx(k,curset(i))))=curset(i);
               num(curx(k,curset(i))) = num(curx(k,curset(i)))+1;
            end
            %然后按每种取值递归
            for i=1:tpt
                   ttmp_set = intersect(tmp_set(i,:),curset);
                   n = size(ttmp_set);
                   %如果该取值下没有样本，不进行递归，标记为当前样本下最多的一个分类
                   if(n(2)==0)
                       ptr=ptr+1;
                       tree(ptr)=cur;
                       treeres{1,ptr} = xigua{(y_nums(2)>y_nums(1))+1};
                       treeres{2,ptr} = fenlei{i,p_num};
                   else
                    treeres{2,ptr+1} = fenlei{i,p_num};    %记录分类具体属性
                    TreeGenerate(cur,ttmp_set,pf,pu,pt);
                   end
            end
       end

end

%{
信息增益选择
    curset:当前样本集合
    pf：当前属性的编号
    pu：当前属性是连续还是离散的0-离散 1-连续
输出
    n：最优属性
    threshold:连续属性返回阀值
%}
function [n, threshold] = entropy_paraselect(curset,pf,pu)
global x y; 
    %通过样本编号与属性获取当前需要的样本
    curx = x(pf,curset);
    cury = y(curset);
    pn = size(pf);  %剩余属性数
    all = size(cury);   %当前样本总数
    max_ent = -100;     %为ent设初值，要最大值，所以设为一个很小的数
    minn=0;             %记录最优的属性编号
    threshold = 0;  
    for i=1:pn(2)
        if(pu(i) == 1)%连续性变量   %具体方法书上有
            con_max_ent =  -100;
            con_threshold = 0;
            xlist = sort(curx(i,:),2);
            %计算n-1个阀值
            for j=all(2):-1:2
               xlist(j) = (xlist(j)+xlist(j-1))/2;
            end
            %从n-1个阀值中选最优    (循环过程中ent先递减后递增 其实只要后面的ent比前面的大就可以停止循环)
            for j=2:all(2)
               cur_ent = 0; 
               %计算各类正负例数
               nums = zeros(2,2);
               for k=1:all(2)
                    nums((curx(i,k)>=xlist(j))+1,cury(k)) = nums((curx(i,k)>=xlist(j))+1,cury(k)) + 1;
               end
               %计算ent  连续属性只分两种情况
               for k=1:2
                   if(nums(k,1)+nums(k,2) > 0)
                p=nums(k,1)/(nums(k,1)+nums(k,2));
                cur_ent = cur_ent + (p*log2(p+0.00001)+(1-p)*log2(1-p+0.00001))*(nums(k,1)+nums(k,2))/all(2);
                   end
               end
               %记录该分类最优取值
               if(cur_ent>con_max_ent)
                   con_max_ent = cur_ent;
                   con_threshold = xlist(j);
               end
            end
            %如果该最优取值比当前总的最优还要优，记录
            if(con_max_ent > max_ent)
                max_ent=con_max_ent;
                minn = i;
                threshold = con_threshold;
            end
        else
            %离散型
            %除了分类数多了 其他一样
            cur_ent = 0; 
            set_data=unique(curx(i,:));
            setn=size(set_data);
            nums = zeros(10,2);
            for j=1:all(2)
               nums(curx(i,j),cury(j))=nums(curx(i,j),cury(j))+1;
            end
            for j=1:setn(2)
                if((nums(set_data(j),1)+nums(set_data(j),2))>0)
                 p=nums(set_data(j),1)/(nums(set_data(j),1)+nums(set_data(j),2));
                 cur_ent = cur_ent +(p*log2(p+0.00001)+(1-p)*log2(1-p+0.00001))*(nums(set_data(j),1)+nums(set_data(j),2))/all(2);
                end
            end
            if(cur_ent > max_ent)
                minn = i;
                max_ent = cur_ent;
            end
        end
    end
    n = minn;
    threshold = threshold * pu(n);

end
