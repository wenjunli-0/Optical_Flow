//
// Created by 奶学霸 on 2019-06-13.
//

#ifndef DBSCAN_H
#define DBSCAN_H

#include <vector>

using namespace std;

struct Point{
    double x;
    double y;
    int label;  // -1 unvisited, 0 noise, >0 cluster index
};

double euclidean_distance(Point a, Point b);

int dbscan(vector<Point> &dataset, double eps, int min_pts);

int get_cluster_num(vector<Point> &dataset);

int get_point_num_this(vector<Point> &dataset, int cluster_label);

int get_point_num_total(vector<Point> &dataset);

#endif /*DBSCAN_H*/
