int judgedirection(int inpoint[2],int outpoint[2]);                 //�����жϺ���
void judge();                                                //judge function
int judgestation(int x,int y,int stationinf [12][3],int stationnum);//�жϺ���
int judgecomment(int x,int y);                                      //�жϻ��ǲ����ڹ������
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
        int speed;   // ���ٶ�
        int starttime; //  ����ʼʱ��
        int X;
        int Y;   //  X,Y����ʼλ������
        int inpoint[2]; //  ���ǽ�վ̽���λ�ã����������Ƿֱ���X���Y��
        int outpoint[2];  // ��վ��λ��
        int stationnum;  //վ̨��
        int stationinf [12] [3];                                    // stationinf [stationnum] [0]//��վ̨������
                                                                    //stationinf [stationnum] [1]//վ̨������
                                                                    //stationinf [stationnum] [2]//��վ̨ͣ��ʱ��
    };
