#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <windows.h>
#include <string.h>
#include <vector>

using namespace std;

int book_system_time;           //全局变量，时间，世界通用
int Cur_log_denti=0;               //全局变量，当前登陆区分，1表示管理员，0表示没有登陆，client登陆值是读者编号的int类型

int stringtoint(string s)//基本函数
{
    int num;
    stringstream ss(s);
    ss>>num;
    return num;
}

string inttostring(int i)
{
    stringstream ss;
    ss<<i;
    return ss.str();
}

typedef struct book_singal                   //书结构,全部是静态信息
{

    string type;                             //书的类型
    int buytime;                             //书的购买时间，也就是书被录入图书馆的时间
    string name;                             //书名
    string author;                           //书的作者
    string press;                            //出版社
    double price;                            //书价格
    int borrowpermission;                    //书的借阅权限，1代表老师和学生均可以借阅，0代表只有老师可以借阅
    int state;                               //书的状态，1代表该书还在图书馆中，0代表该书已被借阅,2代表已经删除,3被预约
    string id;                               //书的编号，由code()函数生成
    void introduction();                      //书的简介，生成不用输入
} sinbook;

void introduction(book_singal b)
{
    cout<<"this book has a name of "<<b.name
        <<",wroten by "<<b.author
        <<",type is "<<b.type
        <<",press is "<<b.press<<endl;
}

typedef struct lib_client
{
    //人员结构
    string name;                            //客户姓名
    string cli_pass_word;                    //客户密码
    int client_identity;                    //身份信息用来区分老师和学生，0代表老师，1代表学生,2代表管理员
    string institute;                       //客户所在学院
    int creat_time;                          //账户创建时间
    int borrownum;                          //客户已借阅图书数量
    string borrowid[5];                     //客户已借图书的id
    int orderbooknum;
    string orderbookid[5];                   //预约的图书ID
    double Arrears_money;                     //借书欠款
    int honestlevel;                         //诚信等级
    string clid;                              //id
} boclient;

typedef struct lib_comm_list
{
    string bor_book_id;                       //借书的id/预约的id
    string bor_client_id;                     //借书人的id
    int bor_time;                              //借书的时间/预约时间
    int bor_term;                               //借书时长/预约时间
    string bor_way;                               //借书方式（管理员/用户）/预约方式（管理员/用户自己）
    int bookfine;                               //产生罚款/预约不填
    int retu_book;                              //还书没？还书保存还书时间.没换0/预约过期或者失效了失效时间
	int type_comm;                              //借书还是预约,借书1，预约2
} borrow_mass;


class book_shelf
{
public:
    book_shelf();                             //构造函数
    ~book_shelf();                            //析构函数
    vector<sinbook> booklib;                 //书的总数量
    void buybook();                          //图书入库
    //void initializebook();                   //从文件初始化图书
    void renewbook(string renewid,int renew_choice);                        //更新修改信息
    void search_book_shelf(int num,string inf);         //查询模块
    sinbook & id_to_book(string bokide);            //根据bookid返回book

    vector<boclient> suclient;          //存人员信息
    void new_client();                        //加入人员
    //void initializecli();                    //初始化
    void renewclient(string renewid,int renew_choice);                       //更新人员信息
    void search_client_inf(int num,string inf);       //查询模块
    boclient & id_to_client(string cli_gr);             //根据id返回人员

    //借书模块
    vector<borrow_mass> bor_record;                    //交易记录
    void statistic();                                   //交易记录本月统计
    void borr_book(string bookid,string clinid);       //借书
    void back_book(string bookid);                                  //还书
    void order_book(string bookid, string clinid);                                 //预约
    void order_dele_book(string clinid);                            //预约显示
	void delet_book(string bookid);                                         //删除
    int judg_ord_suc(string okid,string inid);      //判断有没有预约书


    //显示模块
    void displaybook(sinbook boid);                      //显示书，一本
    void displaybook();                                  //显示所有书
    void display_client(boclient cl_id);                 //显示顾客
    void display_client();                               //显示所有顾客
};

int str_dist(const string source,const string target)
{
    //step 1

    int n=source.length();
    int m=target.length();
    if (m==0) return n;
    if (n==0) return m;
    //Construct a matrix
    typedef vector< vector<int> >  Tmatrix;
    Tmatrix matrix(n+1);
    for(int i=0; i<=n; i++)  matrix[i].resize(m+1);

    //step 2 Initialize

    for(int i=1;i<=n;i++) matrix[i][0]=i;
    for(int i=1;i<=m;i++) matrix[0][i]=i;

     //step 3
     for(int i=1;i<=n;i++)
     {
        const char si=source[i-1];
        //step 4
        for(int j=1;j<=m;j++)
        {

            const char dj=target[j-1];
            //step 5
            int cost;
            if(si==dj){
                cost=0;
            }
            else{
                cost=1;
            }
            //step 6
            const int above=matrix[i-1][j]+1;
            const int left=matrix[i][j-1]+1;
            const int diag=matrix[i-1][j-1]+cost;
            matrix[i][j]=min(above,min(left,diag));

        }
     }//step7
      return matrix[n][m];
}


book_shelf::~book_shelf()                                                                     //析构函数
{
    ofstream fout(".//document//time_single.txt");//对时间的保存
    fout<<book_system_time;
    fout.clear();
    fout.close();

    ofstream dout(".//document//book_she_text.txt");//对书的保存
    for(int i=0; i<(int)booklib.size(); i++)
    {
        dout<<"类型："<<endl;
        dout<<booklib[i].type<<endl;
        dout<<"购入时间："<<endl;
        dout<<booklib[i].buytime<<endl;
        dout<<"书名："<<endl;
        dout<<booklib[i].name<<endl;
        dout<<"作者："<<endl;
        dout<<booklib[i].author<<endl;
        dout<<"出版社："<<endl;
        dout<<booklib[i].press<<endl;
        dout<<"价格："<<endl;
        dout<<booklib[i].price<<endl;
        dout<<"借阅权限："<<endl;
        dout<<booklib[i].borrowpermission<<endl;
        dout<<"状态："<<endl;
        dout<<booklib[i].state<<endl;
        dout<<"ID："<<endl;
        dout<<booklib[i].id<<endl;
        if(i!=booklib.size()-1)
            dout<<endl;
    }
    dout.clear();
    dout.close();

    ofstream gout(".//document//client_he_text.txt");//对客户的保存
    for(int i=0; i<(int)suclient.size(); i++)
    {
        gout<<"姓名："<<endl;
        gout<<suclient[i].name<<endl;
        gout<<"密码："<<endl;
        gout<<suclient[i].cli_pass_word<<endl;
        gout<<"身份："<<endl;
        gout<<suclient[i].client_identity<<endl;
        gout<<"学院："<<endl;
        gout<<suclient[i].institute<<endl;
        gout<<"账号创建时间："<<endl;
        gout<<suclient[i].creat_time<<endl;
        gout<<"借书数量："<<endl;
        gout<<suclient[i].borrownum<<endl;
        gout<<"借书ID："<<endl;
        for(int j=0; j<suclient[i].borrownum; j++)
            gout<<suclient[i].borrowid[j]<<endl;
        gout<<"预约数量："<<endl;
        gout<<suclient[i].orderbooknum<<endl;
        gout<<"预约ID："<<endl;
        for(int j=0; j<suclient[i].orderbooknum; j++)
            gout<<suclient[i].orderbookid[j]<<endl;
        gout<<"欠款："<<endl;
        gout<<suclient[i].Arrears_money<<endl;
        gout<<"诚信等级："<<endl;
        gout<<suclient[i].honestlevel<<endl;
        gout<<"ID："<<endl;
        gout<<suclient[i].clid<<endl;
        if(i!=suclient.size()-1)
            gout<<endl;
    }
    gout.clear();
    gout.close();


	ofstream rout(".//document//log_file.txt");//交易记录的保存
	for (int i = 0;i<(int)bor_record.size();i++)
	{
	    rout<<"书ID："<<endl;
		rout << bor_record[i].bor_book_id << endl;
		rout<<"用户ID："<<endl;
		rout << bor_record[i].bor_client_id << endl;
		rout<<"借书/预约时间："<<endl;
		rout << bor_record[i].bor_time << endl;
		rout<<"借书时长/预约生效时间："<<endl;
		rout << bor_record[i].bor_term << endl;
		rout<<"借书/预约用户类型："<<endl;
		rout << bor_record[i].bor_way << endl;
		rout<<"罚款："<<endl;
		rout << bor_record[i].bookfine << endl;
		rout<<"状态："<<endl;
		rout << bor_record[i].retu_book << endl;
		rout<<"借书/预约："<<endl;
		rout << bor_record[i].type_comm << endl;
		if(i!=bor_record.size()-1)
            rout<<endl;
	}
	rout.clear();
	rout.close();
	cout << "good night!" << endl;
}

book_shelf::book_shelf()                                                             //构造函数
{
    fstream fin;
    fin.open(".//document//book_she_text.txt",fstream::in);                         //读取图书基本信息
    string str;

    sinbook temmem;
    while(!fin.eof())
    {
        getline(fin,str);
        getline(fin,temmem.type);   //读取图书类型
        getline(fin,str);
        fin>>temmem.buytime;         //读取图书购买时间
        getline(fin,str);
        getline(fin,str);
        getline(fin,temmem.name);   //读取书名
        getline(fin,str);
        getline(fin,temmem.author);  //读取书的作者信息
        getline(fin,str);
        getline(fin,temmem.press);   //读取图书出版社
        getline(fin,str);
        fin>>temmem.price;           //读取图书价格
        getline(fin,str);
        getline(fin,str);
        fin>>temmem.borrowpermission; //读取图书借阅权限
        getline(fin,str);
        getline(fin,str);
        fin>>temmem.state;           //读取图书借阅状态
        getline(fin,str);
        getline(fin,str);
        getline(fin,temmem.id);      //读取图书ID
        getline(fin,str);

        booklib.push_back(temmem);//memory the information of temp book
    }

    fin.clear();
    fin.close();

    fstream dfin(".//document//client_he_text.txt",fstream::in);//人员信息
    boclient temclie;

    dfin.seekg(0,ios_base::end);
    int tmp=dfin.tellg();
    if(tmp!=0){
        dfin.seekg(0,ios_base::beg);

        while(!dfin.eof())
        {
            getline(dfin,str);
            getline(dfin,temclie.name);     //读取客户姓名
            getline(dfin,str);
            getline(dfin,temclie.cli_pass_word);//读取客户密码
            getline(dfin,str);
            dfin>>temclie.client_identity;      //读取身份信息

            getline(dfin,str);
            getline(dfin,str);

            getline(dfin,temclie.institute);    //读取所在学院
            getline(dfin,str);
            dfin>>temclie.creat_time;           //读取账号创建时间
            getline(dfin,str);
            getline(dfin,str);
            dfin>>temclie.borrownum;            //读取借书数量
            getline(dfin,str);
            getline(dfin,str);
            if(temclie.borrownum>5||temclie.borrownum<-1)
                temclie.borrownum=0;
            for(int j=0; j<temclie.borrownum; j++)  //读取借书ID
            {
                getline(dfin,temclie.borrowid[j]);
            }
            getline(dfin,str);
            dfin>>temclie.orderbooknum;            //读取预约数量
            getline(dfin,str);
            getline(dfin,str);
            if(temclie.orderbooknum>5||temclie.orderbooknum<-1)
                temclie.orderbooknum=0;
            for(int j=0; j<temclie.orderbooknum; j++) //读取预约ID
               getline(dfin,temclie.orderbookid[j]);
            getline(dfin,str);
            dfin>>temclie.Arrears_money;          //读取客户借书欠款
            getline(dfin,str);
            getline(dfin,str);
            dfin>>temclie.honestlevel;            //读取诚信等级信息
            getline(dfin,str);
            getline(dfin,str);
            getline(dfin,temclie.clid);           //读取客户ID
            getline(dfin,str);
            suclient.push_back(temclie);
        }

    }
    dfin.clear();
    dfin.close();
    fstream gfin(".//document//log_file.txt");
    gfin.seekg(0,ios_base::end);
    int ewmp=gfin.tellg();
    if(ewmp!=0){
        gfin.seekg(0,ios_base::beg);

	borrow_mass temp_log;
	while (!gfin.eof())
	{
	    getline(gfin, str);
		getline(gfin, temp_log.bor_book_id);   //读取书的ID
		getline(gfin, str);
		getline(gfin, temp_log.bor_client_id); //读取借书用户/预约用户ID
		getline(gfin, str);
		gfin >> temp_log.bor_time;             //读取借书时间/预约时间
		getline(gfin, str);
		getline(gfin, str);
		gfin >> temp_log.bor_term;             //读取借书时长/预约生效时间
		getline(gfin, str);
		getline(gfin, str);
		getline(gfin, temp_log.bor_way);       //读取借书方式
		getline(gfin, str);
		gfin >> temp_log.bookfine;             //读取产生罚款
		getline(gfin, str);
		getline(gfin, str);
		gfin >> temp_log.retu_book;            //读取书的借还状态
		getline(gfin, str);
		getline(gfin, str);
		gfin >> temp_log.type_comm;            //读取保存类型，借书还是预约
		getline(gfin, str);
		getline(gfin, str);
		//if((temp_log.type_comm==2)&&(temp_log.bor_time-book_system_time>temp_log.bor_term))
        //{
        //    temp_log.retu_book=book_system_time;
        //    cout<<temp_log.bor_client_id<<"order"<<temp_log.bor_book_id<<"have over time!"<<endl;
        //}
		bor_record.push_back(temp_log);
	}

	gfin.clear();
	gfin.close();
    }
}


/*******************************************************************************************************************************/
sinbook & book_shelf::id_to_book(string bokide)        //书的id对应书结构
{
    for(int i=0;i<(int)booklib.size(); i++)
    {
        if(bokide==booklib[i].id)
            return booklib[i];
    }
    cout<<"no book!"<<endl;
}

boclient & book_shelf::id_to_client(string cli_gr)
{
    for(int i=0; i<(int)suclient.size(); i++)
    {
        if(cli_gr==suclient[i].clid)
            return suclient[i];
    }
    cout<<"no body!"<<endl;
}

int book_shelf::judg_ord_suc(string okid,string inid)
{
    for(int i=0; i<id_to_client(inid).orderbooknum; i++)
    {
        if(id_to_client(inid).orderbookid[i]==okid&&(id_to_book(okid).state==3))
            return 1;
    }
    return 0;
}

void book_shelf::statistic()                                       //统计所有信息
{
    int bonum,renum,unret,monu;//统计借书量，还书量，没换书的数目，营业额
    bonum=0;
    renum=0;
    unret=0;
    monu=0;
    for(int i=0;i<(int)bor_record.size();i++)
    {
        if((bor_record[i].type_comm==1)&&(book_system_time-bor_record[i].bor_time<300))
        {
            cout<<id_to_book(bor_record[i].bor_book_id).name<<"被借"<<endl;
            //cout<<bor_record[i].bor_book_id<<endl;
            cout<<"借书人ID："<<bor_record[i].bor_client_id<<endl;
            //cout<<"借书人姓名："<<library.id_to_client(bor_record[i].bor_client_id).name<<endl;
            ++bonum;
        }
        if((bor_record[i].type_comm==1)&&((book_system_time-bor_record[i].retu_book<300)))
        {
            cout<<id_to_book(bor_record[i].bor_book_id).name<<"被还"<<endl;
            //cout<<bor_record[i].bor_book_id<<endl;
            cout<<"还书人ID："<<bor_record[i].bor_client_id<<endl;
            //cout<<"还书人姓名："<<library.id_to_client(bor_record[i].bor_client_id).name<<endl;
            ++renum;
        }
        if(bor_record[i].retu_book==0)
        {
            cout<<id_to_book(bor_record[i].bor_book_id).name<<"未被还"<<endl;
            //cout<<bor_record[i].bor_book_id<<endl;
            cout<<"借书人ID："<<bor_record[i].bor_client_id<<endl;
            //cout<<"借书人姓名："<<library.id_to_client(bor_record[i].bor_client_id).name<<endl;
            ++unret;
        }
        monu=monu+bor_record[i].bookfine;
    }
    cout<<"本月被借走的书的数量:"<<bonum<<endl;
    cout<<"本月被还回的书的数量:"<<renum<<endl;
    cout<<"还未被还回的书的数量:"<<unret<<endl;
    cout<<"本月罚款收入:"<<monu<<endl;
}

void book_shelf::borr_book(string bookid,string clinid)
{
    if(id_to_client(clinid).honestlevel>5)                       //决策树
        cout<<"You are on the blacklist!"<<endl;
    else
    {
        if(id_to_client(clinid).Arrears_money>10.0)
        {
            cout<<"你已经欠了太多金额!还款输入1，任意输入退出"<<endl;//此处可以添加还钱链接！以后添加吧！并不是主要程序，不优先
            /*int temp=0;
            cin>>temp;
            if(temp==1)
            {
                library.renewclient(clinid,5);
            }
             */   //注释的原因是因为这里涉及到推出界面以后是继续还书还是推出页面，还书时需要用到goto语句
        }
        else
        {
            if(id_to_client(clinid).borrownum>4)
            {
                cout<<"你已经借了太多的书!"<<endl;//此处可以添加还书链接！
            }
            else
            {

                //
                if(id_to_book(bookid).state==1)
                {
                    if(id_to_book(bookid).borrowpermission==0&&id_to_client(clinid).client_identity==1)
                        cout<<"您没有权限借阅!"<<endl;
                    else
                    {
                        borrow_mass exml;
                        exml.bor_book_id=bookid;
                        exml.bor_client_id=clinid;
                        exml.bor_time=book_system_time;//系统当前时间
                        cout<<"请输入您的借阅时间（天）:";
                        cin>>exml.bor_term;  //可以加一个输入检查
                        exml.bor_term=exml.bor_term*10;
                        exml.bookfine=0;
						exml.type_comm = 1;//标明是借书
                        exml.retu_book = 0;//标明是没有换书
						if (Cur_log_denti == 1)
							exml.bor_way = "admin";//后期写登陆以后可以写服务类型//不得不承认时整个程序的失败之处
						else
							exml.bor_way = "yourself";
                        bor_record.push_back(exml);//填写借书记录完毕，开始修改信息

                        id_to_client(clinid).borrowid[id_to_client(clinid).borrownum]=bookid;
                        ++(id_to_client(clinid).borrownum);//修改完顾客信息

                        id_to_book(bookid).state=0;
                        cout<<"您已成功借阅此书, 享受生活，享受阅读!"<<endl;
                    }
                   //judg_ord_suc(bookid,clinid)=1;
                }
                else if(judg_ord_suc(bookid,clinid)==1)//预约成功
                {
                    borrow_mass exml;
                    exml.bor_book_id=bookid;
                    exml.bor_client_id=clinid;
                    exml.bor_time=book_system_time;
                    cout<<"please input the term you want borrow:";
                    cin>>exml.bor_term;//可以加一个输入检查
                    exml.bookfine=0;
                    exml.retu_book=0;
					exml.type_comm = 1;
					if (Cur_log_denti == 1)
						exml.bor_way = "admin";//后期写登陆以后可以写服务类型
					else
						exml.bor_way = "yourself";//后期写登陆以后可以写服务类型
                    bor_record.push_back(exml);//填写借书记录完毕，开始修改信息

                    for(int i=0;i<id_to_client(clinid).orderbooknum;i++)//从预约菜单中删除借的书
                    {
                        if(id_to_client(clinid).orderbookid[i]==bookid)
                            id_to_client(clinid).orderbookid[i]=id_to_client(clinid).orderbookid[id_to_client(clinid).orderbooknum];
                    }
                    --id_to_client(clinid).orderbooknum;
                    id_to_client(clinid).borrowid[id_to_client(clinid).borrownum]=bookid;
                    ++id_to_client(clinid).borrownum;//修改完顾客信息

                    id_to_book(bookid).state=0;
                    cout<<"您已成功借阅此书, 享受生活，享受阅读!"<<endl;
                }
                else
                    cout<<"对不起，此书不存在！"<<endl;
            }
        }
    }
}

void book_shelf::back_book(string bookid)
{
	int temp_c=0;
	for (int i = 0;i<(int)bor_record.size();i++)//
	{
		if (bor_record[i].bor_book_id == bookid&&bor_record[i].type_comm == 1&&bor_record[i].retu_book==0)
		{
			string temp_client = bor_record[i].bor_client_id;
			//修改人
			for (int j = 0;j < id_to_client(temp_client).borrownum;j++)
			{
				if (id_to_client(temp_client).borrowid[j] == bookid)
				{
					id_to_client(temp_client).borrowid[j] = id_to_client(temp_client).borrowid[id_to_client(temp_client).borrownum - 1];
					break;
				}
			}
			--(id_to_client(temp_client).borrownum);
			if (((book_system_time - bor_record[i].bor_time) - bor_record[i].bor_term) > 0)
			++(id_to_client(temp_client).honestlevel);
			id_to_client(temp_client).Arrears_money += ((book_system_time - bor_record[i].bor_time) - (bor_record[i].bor_term))*id_to_book(bookid).price / 50;
			//修改书
			id_to_book(bookid).state = 1;

			//修改记录
			bor_record[i].retu_book = book_system_time;
			temp_c=1;
			break;
		}
	}
	if(temp_c==0)
	cout<<"no information!"<<endl;
	else
        cout<<"good game! guy!"<<endl;
}

void book_shelf::delet_book(string bookid)
{
	vector<sinbook>::iterator it;
	int i = 0;
	for (it = booklib.begin();it != booklib.end();i++)
	{
		if (booklib[i].id == bookid)
		{
			it = booklib.erase(it);
			break;
		}
		++it;
	}
	cout << "success delete!" << endl;
}

void book_shelf::order_book(string bookid, string clinid)
{
	if (id_to_client(clinid).honestlevel>5)                       //决策树
		cout << "You are on the blacklist!" << endl;
	else
	{
		if (id_to_client(clinid).Arrears_money > 10.0)
		{
			cout << "You already owe too much money!" << endl;
		}
		else
		{
			if (id_to_book(bookid).state == 1)
			{
				cout << "The book you want to book is in the library,1:goto borrow,0:quit:";
				int temp;
				cin >> temp;
				if (temp == 1)
					borr_book(bookid, clinid);
			}
			else
			{
				if (id_to_book(bookid).state == 2)
					cout << "sorry,this book had been deleted!" << endl;
				else
				{
					id_to_client(clinid).orderbookid[id_to_client(clinid).orderbooknum] = bookid;
					++(id_to_client(clinid).orderbooknum);//对客户的影响

					borrow_mass exml;//产生一个预约记录
					exml.bor_book_id = bookid;
					exml.bor_client_id = clinid;
					exml.bor_time = book_system_time;
					exml.bor_term = 300;
					if (Cur_log_denti == 1)
						exml.bor_way = "admin";//后期写登陆以后可以写服务类型
					else
						exml.bor_way = "yourself";
					exml.bookfine = 0;
					exml.retu_book = 0;
					exml.type_comm = 2;
					bor_record.push_back(exml);//填写预约记录完毕
					cout << "order success!" << endl;
				}
			}
		}
	}
}

void book_shelf::order_dele_book(string clinid)
{
    if((int)id_to_client(clinid).orderbooknum==0)
        return;
    cout<<"你已经预约了以下书，以及他们现在的状态："<<endl;
    vector <int> reserve;
    string serbook[(int)id_to_client(clinid).orderbooknum];
    for(int i=0;i<(int)id_to_client(clinid).orderbooknum;i++)
    {
        cout<<"书名"<<id_to_book(id_to_client(clinid).orderbookid[i]).name;
        serbook[i]=id_to_client(clinid).orderbookid[i];
        if(id_to_book(id_to_client(clinid).orderbookid[i]).state==1)
        {
            cout<<"在馆！"<<endl;
            cout<<"输入1，借书，其他，忽略"<<endl;
            int tempp;
            cin>>tempp;
            if(tempp==1)
                borr_book(id_to_client(clinid).orderbookid[i],clinid);//人的记录最后清理
            for (int j = 0;j<(int)bor_record.size();j++)
            {
                if(bor_record[j].bor_book_id == id_to_client(clinid).orderbookid[j]&&bor_record[j].type_comm == 2&&bor_record[j].retu_book==0)
                {
                    bor_record[j].retu_book==book_system_time;
                    break;
                }
            }

        }
        else if(id_to_book(id_to_client(clinid).orderbookid[i]).state==0)
             {
                 cout<<"借出！"<<endl;
                 reserve.push_back(i);
             }
        else
            cout<<"书被删除！"<<endl;


        /*if(id_to_book(id_to_client(clinid).orderbookid[i]).state==1)
        {

            cout<<"you order book"<<id_to_client(clinid).orderbookid[i]<<"arrive,input 1 to borrow,others ignore:";
            //清理人

            int tempp;
            cin>>tempp;
            if(tempp==1)
                borr_book(id_to_client(clinid).orderbookid[i],clinid);
            string w;
            w=id_to_client(clinid).orderbookid[i];
            id_to_client(clinid).orderbookid[i]=id_to_client(clinid).orderbookid[id_to_client(clinid).orderbooknum-1];
            --id_to_client(clinid).orderbooknum;

            for(int j=0;j<(int)bor_record.size();j++)
            {
                if(bor_record[j].type_comm==2&&bor_record[j].bor_book_id==w)
                    bor_record[j].retu_book=book_system_time;
            }//销毁所有有关的图书记录
        }
        */
    }
    for(int i=0;i<(int)reserve.size();i++)
    {
        id_to_client(clinid).orderbookid[i]=serbook[reserve[i]];
    }
    id_to_client(clinid).orderbooknum=(int)reserve.size();
    return;
}

void book_shelf::displaybook(sinbook boid)
{
    cout<<"\ntype:"<<boid.type<<"\tbuytime:"<<boid.buytime
        <<"\tname:"<<boid.name<<"\tauthor:"<<boid.author
        <<"\tpress:"<<boid.press<<"\tprice:"<<boid.price
        <<"\tbookid:"<<boid.id<<endl;
}

void book_shelf::displaybook()
{
    int i=0;
    for(i;i<(int)booklib.size();i++)
    {
        displaybook(booklib[i]);
    }
}

void book_shelf::display_client(boclient cl_id)
{
    cout<<"\nname:"<<cl_id.name;
    if(cl_id.client_identity==0)
        cout<<"\ttype:teacher";
    else if(cl_id.client_identity==2)
        cout<<"\ttype:manager";
    else
        cout<<"\ttype:student";
    cout<<"\tinstitute:"<<cl_id.institute<<"\tcreattime:"<<cl_id.creat_time
        <<"\tid:"<<cl_id.clid<<"\thonest tevel:"<<cl_id.honestlevel;
        if(cl_id.Arrears_money<0)
            cout<<"\tmoney:0"<<"   您还有："<<0-cl_id.Arrears_money<<"RMB"<<endl;
        else
            cout<<"\tmoney:"<<cl_id.Arrears_money<<endl;
    if(cl_id.borrownum>0)
    {
        cout<<"you have borrowed "<<cl_id.borrownum<<"book,interesting!"<<endl;
        for(int i=0; i<cl_id.borrownum; i++)
            {//displaybook(id_to_book(cl_id.borrowid[i]));
            cout<<cl_id.borrowid[i]<<endl;}
    }
    else
        cout<<"no borrow information!"<<endl;
    if(cl_id.orderbooknum==0)
        cout<<"no order book information!"<<endl;
    else
    {
        cout<<"you have ordered "<<cl_id.orderbooknum<<"book,interesting!"<<endl;
        for(int i=0; i<cl_id.orderbooknum; i++)
        {
            if(id_to_book(cl_id.orderbookid[i]).state==1)
                cout<<"your order book"<<id_to_book(cl_id.orderbookid[i]).name<<"are ready!"<<endl;
            else if(id_to_book(cl_id.orderbookid[i]).state==2)
                cout<<"your order book"<<id_to_book(cl_id.orderbookid[i]).name<<"have been delete!"<<endl;
            else if(id_to_book(cl_id.orderbookid[i]).state==0)
                cout<<"your order book"<<id_to_book(cl_id.orderbookid[i]).name<<"have been borrow by others!"<<endl;
        }
    }
}

void book_shelf::display_client()
{
    int i=0;
    for(i;i<(int)suclient.size();i++)
    {
        display_client(suclient[i]);
    }
}

unsigned int RSHash(string mas)              //hash函数
{
    const char *str = mas.c_str();
    unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;

    while (*str)
    {
        hash = hash * a + (*str++);
        a *= b;
    }

    return (hash  & 0x3FFF);
}

string code(sinbook bbkk)                    //最大允许有10本相同的书
{
    string exmname;
    exmname=bbkk.name;
    string exmpress;
    exmpress=bbkk.press;
    fstream fin(".//document//code_dictionary.txt");
    int namecode=0;
    while(!fin.eof())
    {
        string rubbish2;
        string ename;
        string epress;
        string eauthor;
        getline(fin,ename);
        getline(fin,epress);
        getline(fin,eauthor);
        if(ename==exmname&&epress==exmpress&&eauthor==bbkk.author)
        {
            string enumber;
            getline(fin,enumber);
            namecode=stringtoint(enumber)-(stringtoint(enumber)/10)*10+1;
            getline(fin,rubbish2);
        }
        else
            getline(fin,rubbish2);
    }
    fin.close();
    bbkk.id=inttostring(RSHash(exmname))+inttostring(RSHash(exmpress))+inttostring(namecode);
    ofstream fout(".//document//code_dictionary.txt",ios::out|ios::app);
    fout<<bbkk.name<<endl;
    fout<<bbkk.press<<endl;
    fout<<bbkk.author<<endl;
    fout<<bbkk.id<<endl;
    fout.close();
    return bbkk.id;
}

string codclient(boclient boktemp)           //人员编码函数
{
    string exmname;
    exmname=boktemp.name;//kehuxingming
    string exmins;
    exmins=boktemp.institute;//kehuxueyuan
    fstream fin(".//document//code_dic_cli.txt");
    int namecode=0;
    while(!fin.eof())
    {
        string rubbish;
        string ename;
        string epress;
        getline(fin,ename);
        getline(fin,epress);
        if(ename==exmname&&epress==exmins)
        {
            string enumber;
            getline(fin,enumber);
            namecode=stringtoint(enumber)-(stringtoint(enumber)/10)*10+1;
        }
        else
            getline(fin,rubbish);
    }
    fin.close();
    boktemp.clid=inttostring(RSHash(exmname))+inttostring(RSHash(exmins))+inttostring(namecode);
    ofstream fout(".//document//code_dic_cli.txt",ios::out|ios::app);
    fout<<boktemp.name<<endl;
    fout<<boktemp.institute<<endl;
    fout<<boktemp.clid<<endl;
    fout.close();
    return boktemp.clid;
}

void book_shelf::buybook()                            //买书会存书
{
    sinbook temp_book;
    cout<<"Please input book type:";
    cin>>temp_book.type;
    cout<<"\nplease input name:";
    cin>>temp_book.name;
    cout<<"\nplease input author:";
    cin>>temp_book.author;
    cout<<"\nplease input press:";
    cin>>temp_book.press;
    cout<<"\nplease input price:";
    cin>>setprecision(2)>>temp_book.price;
    cout<<"\nplease input borrowpermission:";
    cin>>temp_book.borrowpermission;
    temp_book.state=1;
    temp_book.id=code(temp_book);
    temp_book.buytime=book_system_time;

    booklib.push_back(temp_book);                  //add vector
    ofstream fout(".//document//buy_information.txt",ios::out|ios::app);//买书记录
    fout<<temp_book.type<<endl;
    fout<<temp_book.buytime<<endl;
    fout<<temp_book.name<<endl;
    fout<<temp_book.author<<endl;
    fout<<temp_book.press<<endl;
    fout<<temp_book.price<<endl;
    fout<<temp_book.borrowpermission<<endl;
    fout<<temp_book.state<<endl;
    fout<<temp_book.id<<endl;
    fout.close();
}

void book_shelf::new_client()                         //新建人员信息
{
    boclient tempcli;
    cout<<"please input the client name:";
    cin>>tempcli.name;
    cout<<"please input the client password:";
    cin>>tempcli.cli_pass_word;
    cout<<"please input the client client_identity:";
    cin>>tempcli.client_identity;
    cout<<"please input the client institute:";
    cin>>tempcli.institute;
    tempcli.creat_time=book_system_time;
    tempcli.borrownum=0;
    tempcli.orderbooknum=0;
    tempcli.Arrears_money=0.0;
    tempcli.honestlevel=1;
    tempcli.clid=codclient(tempcli);
    cout<<tempcli.clid<<endl;
    suclient.push_back(tempcli);
    ofstream fout(".//document//client_lar_shelf.txt",ios::out|ios::app);//买书记录
    fout<<tempcli.name<<endl;
    fout<<tempcli.client_identity<<endl;
    fout<<tempcli.institute<<endl;
    fout<<tempcli.creat_time<<endl;
    fout<<tempcli.borrownum<<endl;
    fout<<tempcli.orderbooknum<<endl;
    fout<<tempcli.Arrears_money<<endl;
    fout<<tempcli.honestlevel<<endl;
    fout<<tempcli.clid<<endl;
    fout.close();
}


void book_shelf::renewbook(string renewid,int renew_choice)               //更新图书信息
{
    int searbookinf=-1;
    for(int i=0; (i<(int)booklib.size())&&searbookinf==-1; i++)
    {
        if(booklib[i].id==renewid)
            searbookinf=i;
    }
    if(searbookinf!=-1)
    {
        switch (renew_choice)
        {
        case 1:
        {
            cout<<"请输入新的类型:";
            cin>>booklib[searbookinf].type;
            break;
        }
        case 2:
        {
            cout<<"请输入新的名字:";
            cin>>booklib[searbookinf].name;
            break;

        }
        case 3:
        {
            cout<<"请输入新的作者:";
            cin>>booklib[searbookinf].author;
            break;

        }
        case 4:
        {
            cout<<"请输入新的出版社:";
            cin>>booklib[searbookinf].press;
            break;

        }
        case 5:
        {
            cout<<"请输入新的价格:";
            cin>>booklib[searbookinf].price;
            break;
        }
        }
    }
    else
        cout<<"输入了错误的ID！"<<endl;
}

void book_shelf::renewclient(string renewid,int renew_choice)
{
    int searcliinf=-1;
    for(int i=0; (i<(int)suclient.size())&&(searcliinf==-1); i++)
    {
        if(suclient[i].clid==renewid)
            searcliinf=i;
    }
    if(searcliinf!=-1)
    {
        switch (renew_choice)//有不同的功能
        {
        case 1:
        {
            cout<<"请输入新姓名:";
            cin>>suclient[searcliinf].name;
            cout<<"修改成功！"<<endl;
            break;
        }
        case 2:
        {
            cout<<"请输入新学院:";
            cin>>suclient[searcliinf].institute;
            cout<<"修改成功！"<<endl;
            break;

        }
        case 5:                                //还款，特殊功能
        {
            cout<<"请输入充值金额:";
            int num;
            cin>>num;

            suclient[searcliinf].Arrears_money=suclient[searcliinf].Arrears_money-num;
            cout<<"充值成功！"<<endl;
            break;
        }
        case 4:
        {
            cout<<"请输入新密码:";
            cin>>suclient[searcliinf].cli_pass_word;
            cout<<"修改成功！"<<endl;
            break;
        }
        case 3:
            {
                cout<<"请输入新ID:";
                cin>>suclient[searcliinf].clid;
                cout<<"修改成功！";
            }
        }
    }
    else
        cout<<"错误的ID"<<endl;
}


void book_shelf::search_book_shelf(int num,string inf)
{
    switch (num)
    {
    case 1:           //查询类型                               按书的类型查询
    {
        int j=0;
        for(int i=0; i<(int)booklib.size(); i++)
        {
            if(booklib[i].type==inf)
            {
                ++j;
                cout<<booklib[i].id<<endl;
                cout<<booklib[i].name<<endl;
            }
        }
        if(j)
            cout<<"查询成功！"<<endl;
        else
            cout<<"查询失败，该信息不存在。"<<endl;
    }break;
    case 2:                                          //按书的购入时间查询
    {
        int j=0;
        for(int i=0; i<(int)booklib.size(); i++)
        {
            if(booklib[i].buytime==stringtoint(inf))
            {
                ++j;
                cout<<booklib[i].id<<endl;
                cout<<booklib[i].name<<endl;
            }
        }
        if(j)
            cout<<"查询成功！"<<endl;
        else
            cout<<"查询失败，该信息不存在。"<<endl;
    }break;
    case 3:                                                 //按书的名字查询
    {
        int j=0;
        for(int i=0; i<(int)booklib.size(); i++)
        {
            if(str_dist(booklib[i].name,inf)<=4)
            {
                ++j;
                cout<<"ID: "<<booklib[i].id<<"书名："<<booklib[i].name<<endl;
            }
            /*if(booklib[i].name==inf)
            {
                ++j;
                cout<<booklib[i].id<<endl;
            }*/
        }
        if(j)
            cout<<"查询成功！"<<endl;
        else
            cout<<"查询失败，该信息不存在。"<<endl;
    }break;
    case 4:                                                   //按书的作者查询
    {
        int j=0;
        for(int i=0; i<(int)booklib.size(); i++)
        {
            if(booklib[i].author==inf)
            {
                ++j;
                cout<<booklib[i].id<<endl;
                cout<<booklib[i].name<<endl;
            }
        }
        if(j)
            cout<<"查询成功！"<<endl;
        else
            cout<<"查询失败，该信息不存在。"<<endl;
    }break;
    case 5:                                         //按书的出版社查询
    {
        int j=0;
        for(int i=0; i<(int)booklib.size(); i++)
        {
            if(booklib[i].press==inf)
            {
                ++j;
                cout<<booklib[i].id<<endl;
                cout<<booklib[i].name<<endl;
            }
        }
        if(j)
            cout<<"查询成功！"<<endl;
        else
            cout<<"查询失败，该信息不存在。"<<endl;
    }break;
    case 6:                                      //按书的价格查询
    {
        int j=0;
        for(int i=0; i<(int)booklib.size(); i++)
        {
            if(booklib[i].price==stringtoint(inf))
            {
                ++j;
                cout<<booklib[i].id<<endl;
                cout<<booklib[i].name<<endl;
            }
        }
        if(j)
            cout<<"查询成功！"<<endl;
        else
            cout<<"查询失败，该信息不存在。"<<endl;
    }break;
    default:
        cout<<"输入错误！"<<endl;
        break;
    }

    //可以构建查询记录，构建热搜榜，文件
}

void book_shelf::search_client_inf(int num,string inf)
{
    switch (num)
    {
    case 1:
    {
        for(int i=0; i<(int)suclient.size(); i++)
        {
            if(suclient[i].name==inf)
                cout<<suclient[i].clid<<endl;
        }
    }
    case 2:
    {
        for(int i=0; i<(int)suclient.size(); i++)
        {
            if(suclient[i].institute==inf)
                cout<<suclient[i].clid<<endl;
        }
    }
    default:
        cout<<"error choice!"<<endl;
    }
}

typedef struct __THREAD_DATA
{
    int localtime;
}THREAD_DATA;

HANDLE g_hMutex = NULL;

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    while(true)
    {
        WaitForSingleObject(g_hMutex, INFINITE);
		book_system_time++;
        Sleep(1000);
        ReleaseMutex(g_hMutex);
    }
    return 0L;
}

int main(void)
{
    book_shelf library;
    int acc;
    string pasword;
    cout<<"                           欢迎来到图书管理系统"<<endl;

	//线程隔离区，登陆在前，操作在while循环中
	g_hMutex = CreateMutex(NULL, FALSE, NULL);

	fstream fin(".//document//time_single.txt");
	string book_system_time1;
	getline(fin, book_system_time1);
	stringstream ss(book_system_time1);
	ss >> book_system_time;
	fin.close();
	THREAD_DATA threadData;
	threadData.localtime=0;

	HANDLE hThread1 = CreateThread(NULL, 0, ThreadProc, &threadData, 0, NULL);//线程启动，时间运行
	CloseHandle(hThread1);
	//xianchenggeli
	/*cout<<"do you want to add new id?1: add,others: no"<<endl;
	int temp_num_sta;
	cin>>temp_num_sta;
	if(temp_num_sta==1)
	library.new_client();*/
reload_systerm:
    while(true)
    {
        cout<<"请输入您的ID:";
        cin.clear();
        cin.sync();
        cin>>acc;

        if (acc == -1)
            return 0;//直接退出程序
        cout<<"请输入您的密码:";
        cin>>pasword;
        string exm_name;
        exm_name=inttostring(acc);
        int judg_temp=0;
        for(int i=0;i<(int)library.suclient.size();i++)
        {
            if(exm_name==library.suclient[i].clid)
                if(pasword==library.suclient[i].cli_pass_word)
                    {
					pasword = library.suclient[i].clid;
                        judg_temp=1;
                        break;//跳出登陆循环
                    }
        }
        if(judg_temp==1)
            break;
        cout<<"用户名或密码错误！请重新输入。退出系统请输入-1."<<endl;
    }
    if(library.id_to_client(pasword).client_identity==2)
    {
        Cur_log_denti=1;
        cout<<"您是该系统管理员!"<<endl;
    }
    else
        Cur_log_denti=stringtoint(pasword);//成功赋值当前登陆人员，
	if (Cur_log_denti == 1)//管理员的登陆
	{
		int choice_syst=0;

		while (true)
		{
		    WaitForSingleObject(g_hMutex, INFINITE);
			cout << "\tcin>>1.所有图书 " << endl;
			cout << "\tcin>>2.查询图书 " << endl;
			cout << "\tcin>>3.增加图书 " << endl;
			cout << "\tcin>>4.删除图书 " << endl;
			cout << "\tcin>>5.借阅图书 " << endl;
			cout << "\tcin>>6.归还图书 " << endl;
			cout << "\tcin>>7.修改图书 " << endl;
			cout << "\tcin>>8.本月统计 " << endl;//300次sleep后算一个月
			cout << "\tcin>>9.退出登录，重新登陆" << endl;
			cout << "\tcin>>10.退出登录，关闭系统" << endl;
			cout << "\tcin>>11.创建账户 " << endl;
			cout << "\tcin>>12.更改账户 " << endl;
			cout << "\tcin>>13.充值账户 " << endl;
			cout << "\tcin>>14.display账户 " << endl;
			cout<<"请选择服务类型：";
			cin >> choice_syst;
			if(choice_syst>15||choice_syst<1)
			 choice_syst=1;

			switch (choice_syst)
			{
			case 1:
			{
				library.displaybook();
				break;
			}
			case 2://查询
			{
				cout << "请输入查询类型：" << endl;
				int temp_choice;
				cout<<"1.按书的类型查询    2.按书的购入时间查询   3.按书名查询"<<endl
				<<"4.按作者查询        5.按出版社查询         6.按价格查询"<<endl;
				cin >> temp_choice;
				cout<<"请输入查询信息："<<endl;
				string temp_inf;
				cin >> temp_inf;
				library.search_book_shelf(temp_choice, temp_inf);
				break;
            }
			case 3://增加图书
			{
				library.buybook();
				break;
			}
			case 4://删除图书
			{
				string temp_nam_book;
				cout << "请输入你想删除的书的ID!：" << endl;
				cin>> temp_nam_book;
				library.delet_book(temp_nam_book);
				break;
			}
			case 5:
			{
				string temp_b,temp_c;
				cout<<"请输入书的ID：";
				cin >> temp_b;
                cin.clear();
                cout<<"请输入客户的ID：";
				cin >> temp_c;
				library.borr_book(temp_b,temp_c);
                break;
			}
			case 6:
			{
				cout << "请输入你要返回的书的ID：";
				string temp_b;
				cin>>temp_b;
				library.back_book(temp_b);
                break;
			}
			case 7:
			{
				int temp_cho;
				string temp_b;
				cout<<"请输入要修改书的ID：";
				cin >> temp_b;
				cout<<"请选择修改类型：1.书类型  2.名字   3.作者   4.出版社   5.价格"<<endl;
				cin >> temp_cho;
				library.renewbook(temp_b,temp_cho);
				break;
			}
			case  8:
			{
				library.statistic();
				break;
			}
			case 9:
			{
			    ReleaseMutex(g_hMutex);
			    cout<<"当前时间（天）："<<book_system_time/10<<endl;
				goto reload_systerm;
				break;
			}
			case 10:
			{
			    cout<<"当前时间（天）："<<book_system_time/10<<endl;
				return 0;
				break;
			}
			case 11:
                {
				library.new_client();
				break;
                }
            case 12:
                {
                    cout<<"请输入ID:";
                    string temp_cli;
                    cin>>temp_cli;
                    cout<<"请选择更改的信息:";
                    cout<<"1:姓名  2.学院  3.ID 4.密码"<<endl;
                    int num;
                    cin>>num;
				    library.renewclient(temp_cli,num);
				    break;
                }
            case 13:
                {
                    cout<<"请输入充值ID：:";
                    string temp_cli;
                    cin>>temp_cli;
                    library.renewclient(temp_cli,5);
                    break;
                }
            case 14:
                {
                    cout<<"展示所有人的信息？  1.是   0.不是"<<endl;
                    int temp_ttt;
                    cin>>temp_ttt;
                    if(temp_ttt==1)
                        library.display_client();
                    else
                    {
                        cout<<"请输入要展示的客户ID：";
                        string ClientId;
                        cin>>ClientId;
                        boclient client=library.id_to_client(ClientId);
                        library.display_client(client);
                    }

                    break;
                }
			default:
			{
				cout << "Please re-enter" << endl;
				break;
			}
			}
		}
	}
	else {
        library.order_dele_book(inttostring(Cur_log_denti));
		while (true)
		{
			cout << "\tcin>>1.所有图书目录 " << endl;
			cout << "\tcin>>2.查询图书 " << endl;
			cout << "\tcin>>3.借阅图书 " << endl;
			cout << "\tcin>>4.归还图书 " << endl;
			cout << "\tcin>>5.预约图书 " << endl;
			cout << "\tcin>>6.退出登录，重新登陆" << endl;
			cout << "\tcin>>7.退出登录，关闭系统" << endl;
			cout << "\tcin>>8.查询个人信息"<<endl;
			cout<<"请选择服务类型：";
			int choice_syst;
			cin >> choice_syst;
			switch (choice_syst)
			{
			case 1:
			{
				library.displaybook();
				break;
			}
			case 2:
			{
				cout << "请输入查询类型：";
				int temp_choice;
				cout<<"1.按书的类型查询    2.按书的购入时间查询   3.按书名查询"<<endl
				<<"4.按作者查询        5.按出版社查询         6.按价格查询"<<endl;
				cin >> temp_choice;
				cout<<"请输入查询信息：";
				string temp_inf;
				cin >> temp_inf;
				library.search_book_shelf(temp_choice, temp_inf);
				break;
			}
			case 3:
			{
				cout << "请输入你想要借的书的ID：";
				string temp_c;
				cin >> temp_c;
				library.borr_book(temp_c,inttostring(Cur_log_denti));
				break;
			}
			case 4:
			{
				cout << "请输入你要还的书的ID：";
				string temp_b;
				cin>>temp_b;
				library.back_book(temp_b);
				break;
			}
			case 5:
			{
				cout << "请输入你要预约的书的ID：";
				string temp_b;
				cin >> temp_b;
				library.order_book(temp_b, inttostring(Cur_log_denti));
				break;
			}
			case 6:
			{
			    ReleaseMutex(g_hMutex);
			    cout<<"当前时间（天）："<<book_system_time/10<<endl;
				goto reload_systerm;
				break;
			}
			case 7:
            {
                cout<<"当前时间（天）："<<book_system_time/10<<endl;
                return 0;
				break;
            }
            case 8:
            {
                boclient client=library.id_to_client(inttostring(Cur_log_denti));
                library.display_client(client);
                break;
            }
			default:
			{
				cout << "Please re-enter" << endl;
				break;
			}
			}
		}
	}
    return 0;
}
