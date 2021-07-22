#include <fstream>
#include"ConvexHull.h"
void outputData_Brutal(vector<Point> &input, vector<Point> &output);
void outputData_Jarvis(vector<Point> &input, vector<Point> &output);
void GetFileData(vector<Point> &input);
void DrawPoints(const vector<Point> &input);
void DrawLines(const vector<Point> &input);
int main() {
    vector<Point> input;
    vector<Point> outputBrutal;
    vector<Point> outputJarvis;
    GetFileData(input);
    ConvexHull convexhull;
    convexhull.FindConvexHull_brutal(input,outputBrutal);
    convexhull.FindConvexHull_Jarvis(input,outputJarvis);
    cout<<"Brutal:"<<endl;
    outputData_Brutal(input,outputBrutal);
    cout<<"Jarvis"<<endl;
    outputData_Jarvis(input,outputJarvis);
}
void DrawPoints(const vector<Point> &input){
    cout<<input.size()<<endl;
    for(int i = 0 ; i < input.size(); i++){
        cout<<input[i].getX()<<" "<<input[i].getY()<<endl;
    }
}
void DrawLines(const vector<Point> &input){
    cout<<input.size()<<endl;
    for(int i = 0 ; i < input.size(); i++){
        cout<<input[i].getX()<<" "<<input[i].getY()<<endl;
    }
}

void outputData_Jarvis(vector<Point>&input, vector<Point> &output){
    ofstream OutputStream_Jarvis;
    const char outputBrutal[] = "Output_Jarvis.txt";
    OutputStream_Jarvis.open(outputBrutal,ios::in);
    int i = 0, j, k = 0, insideConvexHull;
    vector<Point> outputPoints;
    insideConvexHull = input.size()-output.size();
    OutputStream_Jarvis<<insideConvexHull<<endl;
    while(i < input.size()){
        j = 0;
        while(j < output.size()){
            if(!(input.at(i) == output.at(j) ))
                j++;
            else
                break;
        }
        if(j == output.size()){
            outputPoints.push_back(input[i]);
            OutputStream_Jarvis<<outputPoints[k].getX()<<" "<<outputPoints[k].getY()<<endl;
            k++;
        }
        i++;
    }
    i = 0;
    DrawPoints(outputPoints);
    cout<<endl;
    OutputStream_Jarvis<<endl;
    OutputStream_Jarvis<<output.size()<<endl;
    while(i<output.size()){
        OutputStream_Jarvis<<output[i].getX()<<" "<<output[i].getY()<<endl;
        i++;
    }
    DrawLines(output);

}
void outputData_Brutal(vector<Point>&input,vector<Point> &output){
    ofstream OutputStream_brutal;
    const char outputBrutal[] = "Output_brutal.txt";
    OutputStream_brutal.open(outputBrutal,ios::in);

    int i = 0, j, k = 0, insideConvexHull;
    vector<Point> outputPoints;
    insideConvexHull = input.size()-output.size();
    OutputStream_brutal<<insideConvexHull<<endl;
    while(i < input.size()){
        j = 0;
        while(j < output.size()){
            if(!(input.at(i) == output.at(j) ))
                j++;
            else
                break;
        }
        if(j == output.size()){
            outputPoints.push_back(input[i]);
            OutputStream_brutal<<outputPoints[k].getX()<<" "<<outputPoints[k].getY()<<endl;
            k++;
        }
        i++;
    }
    i = 0;
    DrawPoints(outputPoints);
    cout<<endl;
    OutputStream_brutal<<endl;
    OutputStream_brutal<<output.size()<<endl;
    while(i<output.size()){
        OutputStream_brutal<<output[i].getX()<<" "<<output[i].getY()<<endl;
        i++;
    }
    DrawLines(output);

}
void GetFileData(vector<Point> &input) {
    const char File_name[] = "input.txt";
    ifstream InputStream;
    InputStream.open(File_name, ios::in);
    int PointNum;
    InputStream >> PointNum;
    if(input.max_size()<PointNum)
        input.resize(PointNum);
    int i = 0;
    while(i < PointNum){
        double x,y;
        InputStream >> x >> y;
        Point p(x,y);
        input.push_back(p);
        i++;
    }
}