#include<iostream>
using namespace std;
int main(void){
    int t;
    long long tmp=916312070471295267;
    long long n;
    long long a[]={2,3,6,10,20,35,70,126,252,462,924,1716,3432,6435,12870,24310,48620,92378,184756,352716,705432,1352078,2704156,5200300,10400600,20058300,40116600,77558760,155117520,300540195,601080390,1166803110,2333606220,4537567650,9075135300,17672631900,35345263800,68923264410,137846528820,269128937220,538257874440,1052049481860,2104098963720,4116715363800,8233430727600,16123801841550,32247603683100 ,63205303218876, 126410606437752, 247959266474052 ,495918532948104 ,973469712824056 , 1946939425648112,3824345300380220,7648690600760440,15033633249770520 ,30067266499541040,59132290782430712,118264581564861424 ,232714176627630544,465428353255261088,916312070471295267};
    cin>>t;
    while(t){
        cin>>n;
        if(n==2){
            cout<<"2"<<endl;
        }
        else if(n>tmp)
            cout<<"64\n";
        else{
            for(int i=0;i<61;i++){
            if(n>a[i]&&n<=a[i+1]){
                cout<<i+3<<endl;
                break;
            }
        }
        }
        t--;
    }
    return 0;
}
