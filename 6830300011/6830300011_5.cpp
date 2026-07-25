#include <iostream>
using namespace std;

    char a[4][4]={
{'T','H','I','S'},
{'W','A','T','S'},
{'O','A','H','G'},
{'F','G','D','T'}
};

    string db[]={
"IS","THIS","HIS","AT","YOU","HI","IT","TWO",
"OF","FAT","THAT","HAT","GOD","CAT","HAT","AN","FOUR"
    };
    
    
    bool visit[4][4];

    void dfs (int i,int j,string word){
        
        if(i < 0 || i>=4 || j < 0 || j >= 4)
            return;
        
        
        if(visit[i][j]){
            return;
        }
        
        word += a[i][j];
        if(word.length() > 4)
        {
        visit[i][j] = false;
            return;
            }
        visit[i][j] = true;
        
        cout << word;
        
        for(int i = 0 ; i <17;i++){
            if(word == db[i]){
                cout << " found" <<i+1 ;
                break;
            }
           
        }
        cout << endl;
        
        int row[8]   = {-1,-1,-1,0,0,1,1,1};
        int colum[8] = {-1,0,1,-1,1,-1,0,1};
        
        
        for(int k = 0;k<8;k++){
            dfs(i+row[k],j+colum[k],word);
        }
         visit[i][j] = false;
    }

int main()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            dfs(i,j,"");

    return 0;
}