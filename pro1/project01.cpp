#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class method{
    public:
        int i,j,k;
        int pivot;
        float temp;

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
        pivotmatrix(arr,row,n);
        for (k=1;k<n;k++){
            for (i=k+1;i<=n;i++){
                temp = arr[i][k]/arr[k][k];
                for (j=1;j<=n;j++){
                    arr[i][j] = arr[i][j]-(temp*(arr[k][j]));
                }
                row[i]= row[i] - (temp*row[k]);
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
        pivotmatrix(arr,row,n);

        for (i=1;i<=n;i++){
            temp=arr[i][i];
            for(k=1;k<=n;k++){
                arr[i][k] = arr[i][k]/temp;
            }
            row[i] = row[i]/temp;
            for(j=1;j<=n;j++){
                if (j!=i){
                    temp = arr[j][i];
                    for(k=1;k<=n;k++){
                        arr[j][k]= arr[j][k] - (temp*arr[i][k]);
                    }
                    row[j] = row[j]-(temp*row[i]);
                }
            }
        }
        for (i=1;i<=n;i++){
            x[i]=row[i];
        }
        display(n,arr,row,x);
    }
    void lufactor(int n ,float arr[15][15],float row[15],float x[15]){
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
        cout << "U matrix : " << endl;
        display(n,arr,row,x);
    }
    void inverse(int n,float arr[15][15]){
        float c[15][15];
        
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if (i==j){
                    c[i][j] = 1;
                }
                else {
                    c[i][j] = 0;
                }
            }
        }
        for (i=1;i<=n;i++){
            temp = arr[i][i];
            for (j=1;j<=n;j++){
                arr[i][j] = arr[i][j]/temp;
                c[i][j] = c[i][j]/temp;
            }
            for (j=1;j<=n;j++){
                if (i!=j){
                    temp = arr[j][i];
                    for (k=1;k<=n;k++){
                        arr[j][k] -= (temp*arr[i][k]);
                        c[j][k] -= (temp*c[i][k]);
                    }
                }
            }
        }
        cout << "Inverse Matrix A :" << endl;
        for (i=1;i<=n;i++){
            for (j=1;j<=n;j++){
                cout << setw(6) << setprecision(3) << c[i][j]<< " ";
            }
            cout << endl;
        }
    }
};

int main(){
    int n,i,j,choice;
    cout << "Input Matrix size : " ;
    cin >> n ; 
    method Mt;

    cout << "1.Gauss Elimination with Pivot" << endl << "2.Gauss Jordan Elimination" << endl << "3.LU Factorization" << endl << "4.Inverse Matrix" << endl << "Select choice (1,2,3,4): ";
    cin >> choice ;
    while (choice!=4 && choice!=3 && choice!=2 && choice!=1){
        cout <<  "Select choice (1,2,3,4): ";
        cin >> choice;
    }
    cout << "Input Matrix A :" << endl;
    
    // float a[15][15]={{0,0,0,0},{0,1,2,3},{0,2,5,3},{0,1,0,8}},row[15]={0,1,2,3},x[15];
    float a[15][15],row[15],x[15];
    for (i=1;i<=n;i++){
        for (j=1;j<=n;j++){
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        if (choice!=4){
            cout << "result row " << i << " : " ;
            cin >> row[i];
        }
    }
    cout << "Matrix A :" << endl;
    for (i=1;i<=n;i++){
        for (j=1;j<=n;j++){
            cout << setw(6) << setprecision(3) << a[i][j]<< " ";
            }
        if (choice!=4){
                cout << setw(3) << "| " << row[i];
        }
        cout << endl;
    }
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
        Mt.inverse(n,a);
        break;
    }
}