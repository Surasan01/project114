#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class method{
    public:
        int i,j;
        int pivot;

    void pivotrow(float matrix[15][15] ,float row[15],int r , int u,int size){
        float temp;
        for (j=1;j<=size;j++){
            temp = matrix[r][j];
            matrix[r][j] = matrix[u][j];
            matrix[u][j] = temp;
        }
        temp = row[r];
        row[r] = row[u];
        row[u] = temp;
    }
    void pivotmatrix(float matrix[15][15],float row[15],int size){
        for (i=1;i<=size;i++){
            pivot = i;
            for (j=i+1 ;j<=size;j++){
                if (fabs(matrix[j][i]) > fabs(matrix[pivot][i])){
                    pivot = j;
                }
            }
            pivotrow(matrix,row,i,pivot,size);
        }
    }
    void display(int n ,float arr[15][15],float row[15],float x[15]){
        for (i=1;i<=n;i++){
            for (j=1;j<=n;j++){
            cout << setw(6) << setprecision(3) << arr[i][j]<< " ";
            }
            cout << setw(3) << "| " << row[i] << endl;
        }
        cout << "Solution:\n";
        for (i = 1; i <= n; i++) {
            cout << "x[" << i << "] = " << x[i] << endl;
        }
    }

    void gauss(int n ,float arr[15][15],float row[15],float x[15]){
        int k;
        float m ;
        pivotmatrix(arr,row,n);
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
            x[i] = row[i];
            for (j=i+1;j<=n;j++){
                x[i] -= arr[i][j]*x[j];
            }
            x[i] = x[i]/arr[i][i];
        }
        display(n,arr,row,x);
    }
    void gaussjd(int n ,float arr[15][15],float row[15],float x[15]){
        float temp;
        int k,m;
        pivotmatrix(arr,row,n);

        for (i=1;i<=n;i++){
            temp=arr[i][i];
            for(k=1;k<=n;k++){
                arr[i][k] = arr[i][k]/temp;
            }
            row[i] = row[i]/temp;
            for(m=1;m<=n;m++){
                if (m!=i){
                    temp = arr[m][i];
                    for(j=1;j<=n;j++){
                        arr[m][j]= arr[m][j] - (temp*arr[i][j]);
                    }
                    row[m] = row[m]-(temp*row[i]);
                }
            }
        }
        for (i=1;i<=n;i++){
            x[i]=row[i];
        }
        display(n,arr,row,x);
    }
    void lufactor(int n ,float arr[15][15],float row[15],float x[15]){
        int k;
        float m[15][15],l[15][15]={0},y[15];
        for (i=1;i<=n;i++){
            l[i][i] = 1;
        }
        pivotmatrix(arr,row,n);
        for (k=1;k<n;k++){
            for (i=k+1;i<=n;i++){
                m[i][k] = arr[i][k]/arr[k][k];
                cout << "m[" << i << "][" << k << "] = " << m[i][k] << endl;
                for (j=1;j<=n;j++){
                    arr[i][j] = arr[i][j]-(m[i][k]*(arr[k][j]));
                }
            }
        }
        cout << endl << "L matrix : " << endl;
        for (i=2;i<=n;i++){
            for(j=1;j<i;j++){
               l[i][j] = m[i][j];
            }
        }
        for (i=1;i<=n;i++){
            for(j=1;j<=n;j++){
               cout << setw(6) << setprecision(3) << l[i][j]<< " ";
            }
            cout << endl;
        }
        cout << "U matrix : " << endl;
        for (i=1;i<=n;i++){
            for (j=1;j<=n;j++){
            cout << setw(6) << setprecision(3) << arr[i][j]<< " ";
            }
            cout << endl;
        }
        for (i=1;i<=n;i++){
            y[i]=row[i];
            for (j=1;j<i;j++)
                y[i] = y[i] - (l[i][i-j]*y[i-j]);
        }
        x[n] = y[n]/arr[n][n];
        for (i=n-1;i>=1;i--){
            x[i] = y[i];
            for (j=i+1;j<=n;j++){
                x[i] -= arr[i][j]*x[j];
            }
            x[i] = x[i]/arr[i][i];
        }
        cout << "Solution:\n";
        for (i = 1; i <= n; i++) {
            cout << "x[" << i << "] = " << x[i] << endl;
        }
    }
    void inverse(int n,float arr[15][15]){
        float c[15][15];
        for()
    }
};

int main(){
    int n,i,j; 
    cout << "Input Matrix size : " ;
    cin >> n ; 
    method Mt;
    float a[15][15]={{0,0,0,0},{0,1,2,6},{0,4,8,-1},{0,-2,3,5}},row[15]={0,1,2,3},x[15];
    for (i=1;i<=n;i++){
            for (j=1;j<=n;j++){
            cout << setw(6) << setprecision(3) << a[i][j]<< " ";
            }
            cout << setw(3) << "| " << row[i] << endl;
        }
    int choice;
    cout << "1.Gauss Elimination with Pivot" << endl << "2.Gauss Jordan Elimination" << endl << "3.LU Factorization" << endl << "4.Inverse Matrix" << endl << "Select choice (1,2,3,4): ";
    cin >> choice ;
    while (choice!=4 && choice!=3 && choice!=2 && choice!=1){
        cout <<  "Select choice (1,2,3,4): ";
        cin >> choice;
    }
    cout << "Input Matrix " << endl;
    // for (i=1;i<=n;i++){
    //     for (j=1;j<=n;j++){
    //         cout << "a[" << i << "][" << j << "] = ";
    //         cin >> a[i][j];
    //     }
    //     if (choice!=4){
    //         cout << "result row " << i << " : " ;
    //         cin >> row[i];
    //     }
    // }
    cout << endl;
    switch (choice){
    case 1:
        Mt.gauss(n,a,row,x);
        break;
    case 2:
        Mt.gaussjd(n,a,row,x);
        break;
    case 3:
        Mt.lufactor(n,a,row,x);
        break;
    case 4:

        break;
    }
}