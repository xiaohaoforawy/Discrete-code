/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package minweighttriangulation;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;

/**
 *
 * @author lenovo
 */
public class MinWeightTriangulation {

    /**
     * @param args the command line arguments
     */
    
    final static double EARTH_RADIUS = 6378.137;
    static int [][] s1 = new int [21][21];
    static int [][] s2 = new int [29][29];
    public static void main(String[] args) throws FileNotFoundException, IOException {
        double [][] a1 = new double [21][3];
        double [][] a2 = new double [29][3];
        double [][][] w1 = new double [21][21][21];
        double [][][] w2 = new double [29][29][29];
        double [][] t1 = new double [21][21];
        double [][] t2 = new double [29][29];
        //int [][] s1 = new int [21][21];
        //int [][] s2 = new int [29][29];
        RandomAccessFile file = new RandomAccessFile("minweighttriangulation.txt","r");
        String str;
        int i = 1, m=0, n=0, l=0, x=0, y=0, z=0;
        while((str = file.readLine()) != null){                        //文件读取
            if(i >= 2 && i < 23){
                a1[m][0] = Double.parseDouble(str);
                ++m;
            }
            if(i >= 24 && i < 45){
                a1[n][1] = Double.parseDouble(str);
                ++n;
            }
            if(i >= 46 && i < 67){
                a1[l][2] = Double.parseDouble(str);
                ++l;
            }
            if(i >= 68 && i < 97){
                a2[x][0] = Double.parseDouble(str);
                ++x;
            }
            if(i >= 98 && i < 127){
                a2[y][1] = Double.parseDouble(str);
                ++y;
            }
            if(i >= 128 && i < 157){
                a2[z][2] = Double.parseDouble(str);
                ++z;
            }
            ++i;
        }
        
        /*for(i  = 0; i <= 20; ++i){
            for(int j = 0; j<=2;++j){
                System.out.println(a1[i][j]);
            }
        }*/
        
        //构造三角形的权函数
        for(i = 0;i<=20;++i){
            for(int j = 0;j<=20;++j){
                for(int k=0;k<=20;++k){
                    w1[i][j][k] = dist(a1[i],a1[j]) + dist(a1[i],a1[k]) + dist(a1[j],a1[k]);
                }
            }
        }
        
        for(i = 0;i<=28;++i){
            for(int j = 0;j<=28;++j){
                for(int k=0;k<=28;++k){
                    w2[i][j][k] = dist(a2[i],a2[j]) + dist(a2[i],a2[k]) + dist(a2[j],a2[k]);
                }
            }
        }
        
        minWeightTriangulation(20,t1,s1,w1);
        System.out.println("21站点最小边长弦长总和为：");
        System.out.println(t1[1][20]);
        System.out.println();
        System.out.println("29站点的最小弦长总和为：");
        minWeightTriangulation(28,t2,s2,w2);
        System.out.println(t2[1][28]);
        System.out.println();
        System.out.println("21站点的所有三角形为：");
        back_track1(1,20);
        System.out.println();
        System.out.println("29站点的所有三角形为：");
        back_track2(1,28);
    }
    
    
    
    public static double dist(double a[],double b[]){
        double radLat1 = a[1]*Math.PI/180.0;
        double radLat2 = b[1]*Math.PI/180.0;
        double radlng1 = a[0]*Math.PI/180.0;
        double radlng2 = b[0]*Math.PI/180.0;
        
        double s = Math.acos(Math.cos(radLat1) * Math.cos(radLat2) * Math.cos(radlng1 - radlng2) + Math.sin(radLat1) * Math.sin(radLat2));
        s = s*EARTH_RADIUS;
        
        return s*1000;
    }
    
    public static void minWeightTriangulation(int n,double [][]t,int [][]s,double [][][]w){
        for(int i =1;i<=n;i++) t[i][i]=0;
        for(int r=2;r<=n;r++)
            for(int i=1;i<=n-r+1;i++){
                int j =i+r-1;
                t[i][j]=t[i+1][j]+w[i-1][i][j];
                s[i][j]=i;
                for(int k=i+1;k<i+r-1;++k){
                    double u=t[i][k]+t[k+1][j]+w[i-1][k][j];
                    if(u<t[i][j]){
                        t[i][j]=u;
                        s[i][j]=k;
                    }
                }
            }
    }
    
    public static void back_track1(int a, int b)
    {
        if (a == b) return;
        back_track1(a,s1[a][b]);
        back_track1(s1[a][b]+1,b);    //记得这是要加一
        System.out.println((a-1)+"  "+s1[a][b]+"  "+b);
    }
    
    public static void back_track2(int a, int b)
    {
        if (a == b) return;
        back_track2(a,s2[a][b]);
        back_track2(s2[a][b]+1,b);    //记得这是要加一
        System.out.println((a-1)+"  "+s2[a][b]+"  "+b);
    }
}
