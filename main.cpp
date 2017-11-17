#include <iostream>
#include <cstring>
using namespace std;

int  check(char chh[3][3]){

   if(chh[0][0]=='X' && chh[0][1]=='X' && chh[0][2]=='X' && chh[0][0]!='.'){
    return 1;
   }
   else if(chh[1][0]=='X' && chh[1][1]=='X' && chh[1][2]=='X' && chh[1][0]!='.'){
    return 1;
   }
   else if(chh[2][0]=='X' && chh[2][1]=='X' && chh[2][2]=='X' && chh[2][0]!='.'){
    return 1;
   }
   else if(chh[0][0]=='X' && chh[1][0]=='X' && chh[2][0]=='X' &&  chh[0][0]!='.'){
    return 1;
   }
   else if(chh[0][1]=='X' && chh[1][1]=='X' && chh[2][1]=='X'  && chh[0][1]!='.'){
    return 1;
   }
    else if(chh[0][2]=='X' && chh[1][2]=='X' && chh[2][2]=='X' && chh[0][2]!='.'){
    return 1;
   }
   else if(chh[0][0]=='X' && chh[1][1]=='X' && chh[2][2]=='X' && chh[0][0]!='.'){
    return 1;
   }
   else if(chh[2][0]=='X' && chh[1][1]=='X' && chh[0][2]=='X' && chh[2][0]!='.'){
    return 1;
   }

   else if(chh[0][0]=='0' && chh[0][1]=='0' && chh[0][2]=='0' && chh[0][0]!='.'){
    return 2;
   }
   else if(chh[1][0]=='0' && chh[1][1]=='0' && chh[1][2]=='0' && chh[1][0]!='.'){
    return 2;
   }
   else if(chh[2][0]=='0' && chh[2][1]=='0' && chh[2][2]=='0' && chh[2][0]!='.'){
    return 2;
   }
   else if(chh[0][0]=='0' && chh[1][0]=='0' && chh[2][0]=='0' && chh[0][0]!='.'){
    return 2;
   }
   else if(chh[0][1]=='0' && chh[1][1]=='0' && chh[2][1]=='0' && chh[0][1]!='.'){
    return 2;
   }
    else if(chh[0][2]=='0' && chh[1][2]=='0' && chh[2][2]=='0' && chh[0][2]!='.'){
    return 2;
   }
   else if(chh[0][0]=='0' && chh[1][1]=='0' && chh[2][2]=='0' && chh[0][0]!='.'){
    return 2;
   }
   else if(chh[2][0]=='0' && chh[1][1]=='0' && chh[0][2]=='0' && chh[2][0]!='.'){
    return 2;
   }
   else {
    return 0;
   }



}




int main()
{
    cout << "Hello world!" << endl;
    top:
    char arr[3][3];
    char again;
    int flag=0,i,j,count,r,c,value;
    string s1,s2,s3;

    cout<<"*********************************    TIC-TAC-TOE   ********************************************\n";
    cout<<"\n\n enter the name of X student ->> ";
    getline(cin,s1);
    cout<<" enter the name of o student ->> ";
    getline(cin,s2);
    cout<<"\n\n";
    cout<<" who plays first, "<<s1<<" "<<s2<<"?\n";
    getline(cin,s3);
    while(s3.compare(s1)!=0 && s3.compare(s2)!=0){
        cout<<s3<<" is not a registered player\n";
        cout<<" who plays first, "<<s1<<" "<<s2<<"?\n";
        getline(cin,s3);
    }
    if(s3==s1){
        flag=1;
    }
    else{
        flag=2;
    }

    cout<<"\nInitial state of grid ->> \n";
    for(i=0 ; i<3 ; i++){
        for(j=0 ; j<3 ; j++){
           arr[i][j]='.';

        }
    }
    for(i=0 ; i<3 ; i++){
             for(j=0 ; j<3 ; j++){
              cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
    }


    count=0;
    while(count<9){
        r=-1;
        c=-1;
        count++;

        if(flag==1){
            cout<<"player of current turn "<<s1<<"\n";
        }
        else{
            cout<<"player of current turn "<<s2<<"\n";
        }


        // enter row

        cout<<"choose a row number (0 to 2): ";
        cin>>r;
        while(r>2 || r<0){
            cout<<r<<" is not a valid row \n";
            cout<<"choose a row number (0 to 2): ";
            cin>>r;
        }

        // enter column

        cout<<"choose a column number (0 to 2): ";
        cin>>c;
        while(c>2 || c<0){
            cout<<c<<" is not a valid row \n";
            cout<<"choose a column number (0 to 2): ";
            cin>>c;
        }

        cout<<"\n\n";
        cout<<"choose a row number (0 to 2) : "<<r<<"\n";
        cout<<"choose a column number (0 to 2) : "<<c<<"\n";

        if(flag==1){
            arr[r][c]='X';
            flag=2;
        }
        else{
            arr[r][c]='0';
            flag=1;
        }

        for(i=0 ; i<3 ; i++){
             for(j=0 ; j<3 ; j++){
              cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }


        cout<<"\n\n";

        value=0;
        value=check(arr);
        if(value==1){
            cout<<"GAME IS OVER\n";
            cout<<s1<<" wins!\n";
            break;
        }
        else if(value==2){
            cout<<"GAME IS OVER\n";
            cout<<s2<<" wins!\n";
            break;
        }


        cout<<"\n";


    }
    if(count>=9){
        value=check(arr);
        if(value==1){
            cout<<"GAME IS OVER\n";
            cout<<s1<<" wins! \n ";

        }
        else if(value==2){
            cout<<"GAME IS OVER\n";
            cout<<s2<<" wins!\n";

        }
        else{
            cout<<"GAME IS OVER\n";
            cout<<"it is tie\n";
        }
    }

    cout<<"would you like to play again ?(y/n)\n";
    cin>>again;
    while(again!='y' && again!='n'){
        cout<<"would you like to play again ?(y/n)\n";
        cin>>again;
    }

    if(again=='y'){
        goto top;
    }
    else{

        cout<<"\n THANK YOU \n";

    }



    return 0;
}
