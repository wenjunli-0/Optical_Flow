//
// Created by 奶学霸 on 2019-06-13.
//

#include "dbscan.h"
#include <math.h>
#include <queue>
using namespace std;


// calculate eculidean distance of two 2-D points
double euclidean_distance(Point a, Point b)
{
    double x = a.x-b.x;
    double y = a.y-b.y;
    return sqrt(x*x+y*y);
}

// get neighborhood of point p and add it to neighborhood queue
int region_query( vector<Point> &dataset, int p, queue<int> &neighborhood, double eps)
{
    for (int i = 0; i < dataset.size(); i++) {
        if(i!=p){
            int dist = euclidean_distance(dataset[p],dataset[i]);
            if ( dist< eps) {
                neighborhood.push(i);
            }
        }
    }
    return (int)neighborhood.size();
}

// expand cluster formed by p, which works in a way of bfs.
bool expand_cluster( vector<Point> &dataset, int p, int c, double eps, int min_pts){
    queue<int> neighbor_pts;
    dataset[p].label = c;

    region_query(dataset, p, neighbor_pts, eps);

    while (!neighbor_pts.empty()) {

        int neighbor = neighbor_pts.front();
        queue<int> neighbor_pts1;
        region_query(dataset, neighbor, neighbor_pts1, eps);

        if(neighbor_pts1.size()>=min_pts-1)
        {
            while (!neighbor_pts1.empty()) {

                int pt = neighbor_pts1.front();
                if(dataset[pt].label ==-1){
                    neighbor_pts.push(pt);
                }
                neighbor_pts1.pop();
            }
        }
        dataset[neighbor].label = c;
        neighbor_pts.pop();

    }
    return  true;
}

// doing dbscan, given radius and minimum number of neighborhoods.
int dbscan(vector<Point> &dataset, double eps, int min_pts)
{
    int c = 0;  // cluster lable

    for (int p = 0; p<dataset.size(); p++) {
        queue<int> neighborhood;
        region_query(dataset, p, neighborhood, eps);

        if (neighborhood.size()+1 < min_pts) {
            // mark as noise
            dataset[p].label = 0;
        }else
        {

            if(dataset[p].label==-1){
                c++;
                expand_cluster(dataset, p,c, eps, min_pts);
            }
        }
    }

    return c;
}

// return the total number of clusters
int get_cluster_num(vector<Point> &dataset){
    int cluster_num = 0;
    int temp = 0;
    int flag_zero = 0;
    int flag_minus_one = -1;


    // sort... from small label to large label
    for(int i=0; i<dataset.size()-1; i++) {
        for(int j=0; j<dataset.size()-i-1; j++){
            if(dataset[j].label > dataset[j+1].label){
                float x = dataset[j+1].x;
                float y = dataset[j+1].y;
                int label = dataset[j+1].label;

                dataset[j+1] = dataset[j];

                dataset[j].x = x;
                dataset[j].y = y;
                dataset[j].label = label;
            }
        }
    }


    // check if there is point with label-(0)
    for(int i=0; i<dataset.size(); i++) {
        if(flag_zero == dataset[i].label){
            flag_zero = 1;
            break;
        }
    }

    // check if there is point with label-(-1)
    for(int i=0; i<dataset.size(); i++) {
        if(flag_minus_one == dataset[i].label){
            flag_minus_one = 1;
            break;
        }
    }


    for(int i=0; i<dataset.size(); i++) {
        if(temp != dataset[i].label){
            cluster_num++;
            temp = dataset[i].label;
        }
    }


    if(flag_zero == 1){
        cluster_num += 1;
    }

    if(flag_minus_one == 1){
        cluster_num -= 1;
    }

    return cluster_num;
}


// return the number of points in each cluster
int get_point_num_this(vector<Point> &dataset, int cluster_label){
    int point_num = 0;

    for(int i=0; i<dataset.size(); i++){
        if(dataset[i].label == cluster_label){
            point_num++;
        }
    }

    return point_num;
}


// return the total number of points in the dataset
int get_point_num_total(vector<Point> &dataset){
    return dataset.size();
}