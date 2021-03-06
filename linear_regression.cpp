
#include <iostream>
using namespace std;
float mean(float arg[],int len){
    float sum_mean = 0;
    for (int m = 0; m <= len;m++){
        sum_mean += arg[m];
    }
    return sum_mean/len;
}
float covariance(float x[],float y[],int len){
    float sum_cov = 0;
    for (int c = 0; c<= len;c++){
        sum_cov += ((x[c] - mean(x,len))*(y[c] - mean(y,len)));
    }
    return sum_cov/(len-1);
}
float variance(float x[],int len){
    float sum_var = 0;
    for (int v = 0; v <= len;v++){
        sum_var += ((x[v]-mean(x,len))*(x[v]-mean(x,len)));
    }
    return sum_var/(len-1);
}
float linear_regression(float x[],float y[],int len){
    float beta = covariance(x,y,len)/variance(x,len);
    float alpha = mean(y,len) - beta * mean(x,len);
    float equation[] = {beta,alpha};
    return equation[0];
}
float predict(float alpha, float beta, float x){
    float y = beta * x + alpha;
    return y;
}
int main() {
    float x[] = {15.00,3.82,13.60,5.10,10.90};
    float y[] = {47.12,11.25,41.00,16.50,35.00};
    cout << linear_regression(x,y,4);
}
