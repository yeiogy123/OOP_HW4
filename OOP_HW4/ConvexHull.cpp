//
// Created by User on 2021/5/3.
//

#include "ConvexHull.h"
void ConvexHull::FindConvexHull_brutal(const vector<Point> &input, vector<Point> &output) {
    clock_t start,end;
    start = clock();
    vector<Point> unsortOutput;
    for(int i = 0; i < input.size(); i++ ) {
        Point p = input[i];
        for (int j = 0; j < input.size(); j++) {
            Point q = input[j];
            bool status = true;
            if (!(p == q)) {

                //cout << p.getX() << " " << p.getY() << " ";
                //cout << q.getX() << " " << q.getY() << " ";
                for (int k = 0; k < input.size(); k++) {
                    Point r = input[k];
                    //cout<<"["<<k<<"]";
                    if ((!(r == p)) && (!(r == q))) {
                        //cout << r.getX() << " " << r.getY() << " ";
                        if (!isOnRight(p, q, r)) {
                            //cout << "[[[[[[[[break]]]]]]]]]"<<endl;
                            status = false;
                            break;
                        }
                    }
                }
                if (status) {
                    /*cout<<"[push]!!!!!"<<endl;
                    cout << p.getX() << " " << p.getY() << " ";
                    cout << q.getX() << " " << q.getY() << " "<<endl;*/
                    vector<Point>::iterator it = find(unsortOutput.begin(),unsortOutput.end(), p);
                    vector<Point>::iterator it2 = find(unsortOutput.begin(), unsortOutput.end(), q);
                    if (it == unsortOutput.end())
                        unsortOutput.push_back(p);
                    if(it2 == unsortOutput.end())
                        unsortOutput.push_back(q);
                    }
                }
            }
        }
    brutalSort(unsortOutput,output);
    end = clock();
    cout<<"Brutal time:"<<(double)(end-start)<<"ms"<<endl;

}
void ConvexHull::brutalSort(vector<Point>&input,vector<Point>&output) {
    double angle[input.size()];
    for(int i = 1 ; i < input.size();i++)
        angle[i] = computeAngle(input[0], input[i]);
    double temp;
    for(int i = 1 ; i < input.size(); i++){
        for(int j = 1; j < input.size() ; j++){
            if(angle[i] < angle[j])
                SWAP(angle[i],angle[j],temp);
        }
    }
    output.resize(input.size());
    output.at(0)=(input[0]);
    for(int i = 1 ; i < input.size(); i++){
        for(int j = 1; j < input.size() ; j++) {
            if(angle[j] == computeAngle(input[0],input[i])){
                output.at(j) = input[i];
            }
        }
    }
}
double ConvexHull::computeAngle(Point &o, Point &src){
    double angle;
    angle = -atan2(src.getX()-o.getX(),-(src.getY()-o.getY())) / PI * 180;
    return angle;
}
Line ConvexHull::FindLine(const Point &p, const Point &q){
    double ia = q.getY() - p.getY();
    double ib = -1*(q.getX() - p.getX());
    double ic = ((ia * p.getX()) + (ib * p.getY()));
    Line Line(ia,ib,ic);
    //cout<<"Line: "<<ia<<" "<<ib<<" "<<ic<<endl;
    return Line;
}
bool ConvexHull::isOnRight(const Point &p, const Point &q, const Point &r) {
    Line line = FindLine(p,q);
    double val = line.getA()*r.getX()+line.getB()*r.getY()+line.getC();
    //cout<<"r value: "<<r.getX()<<" "<<r.getY()<<" "<<val<<endl;
    double ori = line.getA()*p.getX()+line.getB()*p.getY()+line.getC();
    //cout<<"ori value"<<ori<<endl;
    if(val > ori)
        return true;
    else
        return false;
}
void ConvexHull::FindConvexHull_Jarvis(const vector<Point> &input, vector<Point> &output){
    clock_t start,end;
    start = clock();
    Point q = FindLowestPoint(const_cast<vector<Point>&>(input));
    double MIN_IntData = input[0].getX() ;
    for(int i = 1 ; i < input.size() ; i++){
        if(MIN_IntData >= input[i].getX())
            MIN_IntData = input[i].getX();
    }
    MIN_IntData -=1;
    Point p(MIN_IntData,q.getY()) ;
    Point r = input[0];
    int i = 1;
    while(r == q){
        r = input[i];
        i++;
    }

    /*cout<<"pData is"<<p.getX()<<" "<<p.getY()<<endl;
    cout<<"qDAta is"<<q.getX()<<" "<<q.getY()<<endl;
    cout<<"rData is "<<r.getX()<<" "<<r.getY()<<endl;*/

    // output.push_back(q);
    Point iq = q;
    while(!(r == iq)){
        double maxAngle = -1;
        int indexMaxR;
        Point storeR;
        for(int i = 0 ; i < input.size() ; i++){
            if(q == input[i] || p == input[i])
                continue;
            /*cout<<"["<<i<<"]"<<endl;
            cout<<"pData is"<<p.getX()<<" "<<p.getY()<<endl;
            cout<<"qDAta is"<<q.getX()<<" "<<q.getY()<<endl;
            cout<<"rData is "<<input[i].getX()<<" "<<input[i].getY()<<endl;*/
            if(maxAngle <= ComputeAngle(p,q,input[i])) {
                if(maxAngle == ComputeAngle(p,q,input[i])){
                        double v1 = length(q,input[i]);
                        double v2 = length(q,input[indexMaxR]);
                        if(v1>v2){
                            indexMaxR = i;
                            storeR = input[i];
                        }
                }else {
                    maxAngle = ComputeAngle(p, q, input[i]);
                    //cout << "Angle=" << maxAngle << endl;
                    indexMaxR = i;
                    storeR = input[i];
                }
            }
            /*cout<<"angle = "<<maxAngle<<endl;*/
        }
        r = input[indexMaxR];
        //cout<<input[indexMaxR].getX()<<" "<<input[indexMaxR].getY()<<endl;
        output.push_back(q);
        p = q;
        q = r;
    }
    end = clock();
    cout<<"Jarvis time:"<<(double)(end-start)<<"ms"<<endl;
}
Point ConvexHull::FindLowestPoint(vector<Point> &input) {
    Point lowestY = input[0];
    for(int i = 0 ; i < input.size() ; i++){
        if(lowestY.getY() == input[i].getY() && lowestY.getX( )> input[i].getX()) {
            lowestY = input[i];
        }else if(lowestY.getY() > input[i].getY())
            lowestY = input[i];
    }
    Point q = lowestY;
    return q;

}
inline double length(const Point &p, const Point &q){
    return sqrt(pow(abs(p.getX()-q.getX()),2)+pow(abs(p.getY()-q.getY()),2));
}
double ConvexHull::ComputeAngle(const Point &p, const Point &q, const Point &r) {
    //cout<<p.getX()<<" "<<p.getY()<<" "<<q.getX()<<" "<<q.getY()<<" "<<r.getX()<<" "<<r.getY()<<endl;
    double val = (p.getX() - q.getX()) * (r.getX() - q.getX()) + (p.getY() - q.getY()) * (r.getY() - q.getY());
    double c = length(p,r);
    double b = length(p,q);
    double a = length(q,r);
    double cos = (pow(a,2)+pow(b,2)-pow(c,2))/(2*b*a);
    //cout<<"cos = "<<cos<<endl;
    double theta;
    theta= acos(cos) / PI * 180;
    //cout<<"theta = "<<theta<<endl;
    return theta;
}
double ConvexHull::orientation(const Point &p, const Point &q, const Point &r){
    double val = (q.getY()-p.getY())*(r.getX()-q.getX())-((q.getX()-p.getX())*(r.getY()-q.getY()));
    if(val == 0) return 0;
    return val>0 ? 1:2;
}