int judgedirection(int inpoint[2],int outpoint[2]);                 //方向判断函数
void judge();                                                //judge function
int judgestation(int x,int y,int stationinf [12][3],int stationnum);//判断函数
int judgecomment(int x,int y);                                      //判断火车是不是在公共轨道
void Control();                                                      //The biggest control program.
void choice_(int speed1,int speed2,int * command1,int * command2);
void tra1_move(int _command);                                        //train Run the function
void tra2_move(int _command);
void tra3_move(int _command);
void PrintState();
void init();
void READ();
void output_martix(); 
void draw(int a,int b,int c,int d,int e,int f); 
void Eggprogram(void);
void dongdan();
int transferx(int a);
int transfemy(int n);
void eggorder();

struct train
    {
        int speed;   // 火车速度
        int starttime; //  火车起始时间
        int X;
        int Y;   //  X,Y是起始位置坐标
        int inpoint[2]; //  这是进站探测点位置，包括两个是分别是X轴和Y轴
        int outpoint[2];  // 出站的位置
        int stationnum;  //站台数
        int stationinf [12] [3];                                    // stationinf [stationnum] [0]//是站台横坐标
                                                                    //stationinf [stationnum] [1]//站台纵坐标
                                                                    //stationinf [stationnum] [2]//该站台停靠时间
    };
