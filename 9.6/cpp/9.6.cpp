#include <iostream>
#include <cstdio>
using namespace std;
 
int search(int d[][5], int m, int n, int x){
        int r = 0, c = n-1;
        while(r<m && c>=0){
                if(d[r][c] == x) return (r * n + c);
                else if(d[r][c] < x) ++r;
                else --c;
        }
        return -1;
}
int main(){
        int d[5][5];
        int m=5, n=5;
        for(int i=0; i<m; ++i)
                for(int j=0; j<n; ++j)
                        d[i][j]= i*n+j+1;
 
        for(int i=0; i<m; ++i){
                for(int j=0; j<n; ++j)
                        cout << " " << d[i][j] << " ";
                cout << endl;
        }
        int k = search(d, m, n, 13);
        if(k == -1) cout<<"not found"<<endl;
        else cout<<"position: "<<k/n<<" "<<k%n<<endl;
        fclose(stdin);
        return 0;
}
