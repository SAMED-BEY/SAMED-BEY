#include <vector>
#include <iostream>

using namespace std;


int main() {

    vector<vector<int>>my_vec;    // 2D vector create

    int n,q,i,temp,a,b;           // 

    cin>>n>>q;                    //n: how many row  q: how many question


    for(int x=0; x<n;x++)
    {
        vector<int>temp_v;      // temp vector is to assign to a 2d vector 
                                //deleted and regenerated every cycle
      
        cin>>i;                 //  how many column
        for(int r=0;r<i;r++)
        {
            cin>>temp;          
            temp_v.push_back(temp); // add temp vector
        }
        my_vec.push_back(temp_v);   // temp is add to main vector

    }
   for(int x=0 ; x<q; x++)
   {
       cin>>a>>b;                 // what row column
       cout<<my_vec[a][b]<<endl;

   }
    return 0;
}

/* temp input
2 2
3 1 5 4
5 1 2 8 9 3
0 1
1 3
*/
