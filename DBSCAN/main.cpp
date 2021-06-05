#include <iostream>
#include <fstream>
#include "dbscan.h"

using namespace std;

int main() {
    vector<Point> dataset;
    ifstream in("/Users/wenjun/Codes/ecarx/DBSCAN/1290.txt");

    if(in){
        float x , y;
        while (in>>x>>y) {
            Point p;
            p.x = x;
            p.y = y;
            p.label = -1;
            dataset.push_back(p);
        }
    }
    else{
        cout<<"No such file"<<endl;
    }


    int c =  dbscan(dataset, 60, 5);
    cout<< "(x," << "\t" << "y)" << "\t\t\t" << "label" <<endl;

    for (int i=0; i<dataset.size(); i++) {
        cout<<"("<<dataset[i].x<<","<<"\t"<<dataset[i].y<<")"<<"\t"<<dataset[i].label<<endl;
        if(dataset[i].label != 1 && dataset[i].label != 2 && dataset[i].label != 3){
            cout<<"check this..................."<<endl;
        }
    }



    /// total_cluster_num & each_cluster_num
    int total_cluster_num = get_cluster_num(dataset);
    cout<<"there are "<< total_cluster_num << " clusters; ";


    /// total number of points in the dataset
    int total_point_num = get_point_num_total(dataset);
    cout<<"there are total "<< total_point_num << " points in the dataset." <<endl;


    /// number of points in each cluster
    int num_1 = get_point_num_this(dataset, 1);
    cout<<"there are "<< num_1 << " points in cluster_"<< 1 <<endl;

    int num_2 = get_point_num_this(dataset, 2);
    cout<<"there are "<< num_2 << " points in cluster_"<< 2 <<endl;

    int num_3 = get_point_num_this(dataset, 3);
    cout<<"there are "<< num_3 << " points in cluster_"<< 3 <<endl;




    return 0;
}
