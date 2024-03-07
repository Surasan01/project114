#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class method{
    public:
        int i,j;
        int pivot;
        float sum;

    void pivotrow(float matrix[15][15] ,int r , int u,int size){
        float temp;
        for (j=1;j<=size;j++){
            temp = matrix[r][j];
            matrix[r][j] = matrix[u][j];
            matrix[u][j] = temp;
        }
    }

    void gauss(int n ,float arr[15][15],float row[15],float x[15]){
        int k;
        float m ;
        for (i=1;i<=n;i++){
            pivot = i;
            for (j=i+1 ;j<=n;j++){
                if (fabs(arr[j][i]) > fabs(arr[pivot][i])){
                    pivot = j;
                }
            }
            pivotrow(arr,i,pivot,n);
        }
        for (k=1;k<n;k++){
            for (i=k+1;i<=n;i++){
                m = arr[i][k]/arr[k][k];
                for (j=1;j<=n;j++){
                    arr[i][j] = arr[i][j]-(m*(arr[k][j]));
                }
                row[i]= row[i] - (m*row[k]);
            }
        }

        x[n] = row[n]/arr[n][n];
        for (i=n-1;i>=1;i--){
            sum = row[i];
            for (j=i+1;j<=n;j++){
                sum -= arr[i][j]*x[j];
            }
            x[i] = sum/arr[i][i];
        }
        
        for (i=1;i<=n;i++){
            for (j=1;j<=n;j++){
            cout << setprecision(3) << arr[i][j]<< " ";
            }
            cout << setw(3) << "| " << row[i] << endl;
        }
        cout << "Solution:\n";
        for (i = 1; i <= n; i++) {
            cout << "x[" << i << "] = " << x[i] << endl;
        }
    }
};


int main(){
    int n,i,j; 
    cout << "Input Matrix size : " ;
    cin >> n ; 
    method Mt;
    float a[15][15]={0},row[15],x[15];
    int choice;
    cout << "Gauss Elimination with" << "Select choice : " << endl;
    while (choice>4 && choice<1){
        
    }
    
    cout << "Input Matrix " << endl;
    for (i=1;i<=n;i++){
        for (j=1;j<=n;j++){
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << "result row " << i << " : " ;
        cin >> row[i];
    }
    cout << endl;
    
    Mt.gauss(n,a,row,x);
}