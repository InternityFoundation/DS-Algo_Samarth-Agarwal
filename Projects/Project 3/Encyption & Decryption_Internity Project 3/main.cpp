#include <bits/stdc++.h>
using namespace std;

string HillCipher_Encode(string message,string key)
{
    int n=message.size();
    int keyMatrix[n][n];
    int k=0;
    //fill the KEYMATRIX with values of KEY
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            keyMatrix[i][j]=key[k]%65;
            k++;
        }
    }

    //create MESSAGE VECTOR
    int messageVector[n][1];
    for(int i=0;i<n;i++)
        messageVector[i][0]=(message[i])%65;

    //Create cipherMatrix= product of keyMatrix & messageVector
    int cipherMatrix[n][1];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<1;j++)
        {
            cipherMatrix[i][j]=0;
            for(int x=0;x<n;x++)
            {
                cipherMatrix[i][j]+=keyMatrix[i][x]*messageVector[x][j];
            }
            cipherMatrix[i][j]=cipherMatrix[i][j]%26;
        }
    }

    //Just to print
    cout<<"\n";
    cout<<"keyMatrix\tmessageVector \t cipherMatrix\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<keyMatrix[i][j]<<" ";
        }
        cout<<" \t";
        cout<<messageVector[i][0]<<"\t\t    "<<cipherMatrix[i][0]<<endl;
    }


    //store  matrix to a string
    string cipher_Text;

    for(int i=0;i<n;i++)
        cipher_Text+=cipherMatrix[i][0]+65;

	return cipher_Text;
}

string RailFence_Encode(string message,int key)
{
    int n=message.size();
    char rail[key][(message.size())];

    //storing * at all places
    for(int i=0;i<key;i++)
    {
        for(int j=0;j<n;j++)
        {
            rail[i][j]='*';
        }
    }

    //store messasge values in zigzag manner
    bool dir_down=false;
    int row=0,col=0;

    for(int i=0;i<n;i++)
    {
        if(row==0 || row==key-1)
            dir_down=!dir_down;

        rail[row][col++]=message[i];

        dir_down?row++:row--;
    }
    cout<<"\n";
    //Just to display rail vector
    for(int i=0;i<key;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<rail[i][j]<<" ";
        }
        cout<<"\n";
    }

    //store matrix in string row wise
    string result;
    for(int i=0;i<key;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(rail[i][j]!='*')
                result.push_back(rail[i][j]);
        }
    }
    return result;
}


string RAIL_FENCE_DECRYPT(string cipher, int key)
{
    int n=cipher.length();
	char rail[key][n];

    for (int i=0; i < key; i++)
        for (int j=0; j < n; j++)
            rail[i][j] = '\n';

    bool dir_down;

    int row = 0, col = 0;

    for (int i=0; i < n; i++)
    {
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;

        rail[row][col++] = '*';

        dir_down?row++ : row--;
    }

    int index = 0;
    for (int i=0; i<key; i++)
        for (int j=0; j<n; j++)
            if (rail[i][j] == '*' && index<n)
                rail[i][j] = cipher[index++];


    string result;

    row = 0, col = 0;
    for (int i=0; i< n; i++)
    {
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;

        if (rail[row][col] != '*')
            result.push_back(rail[row][col++]);

        dir_down?row++: row--;
    }
    return result;
}

void getCofactor(int A[100][100], int temp[100][100], int p, int q, int n){
    int i=0, j=0;
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            if(row!=p && col!=q){
                temp[i][j++]=A[row][col];
                if(j==n-1){
                    j=0;
                    i++;
                }
            }
        }
    }
}
int determinant(int A[100][100], int n){
    int D=0;
    if(n==1){
        return A[0][0];
    }
    int temp[100][100];
    int sign=1;
    for(int f=0; f<n; f++){
        getCofactor(A,temp,0,f,n);
        D+=sign * A[0][f] * determinant(temp,n-1);

        sign = - sign;
    }
    return D;
}
void adjoint(int A[100][100], int adj[100][100], int n){
    if(n==1){
        adj[0][0]=1;
        return;
    }

    int sign=1, temp[100][100];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            getCofactor(A,temp,i,j,n);
            sign=((i+j)%2==0)? 1: -1;
            adj[j][i]=(sign)*(determinant(temp,n-1));
        }
    }
}

void getKeyMatrix(string key, int keyMatrix[100][100], int n){
    int k=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            keyMatrix[i][j]=key[k]%65;
            k++;
        }
    }
}
void inverse(int keyMatrix[100][100], int n){
    int det= determinant(keyMatrix,n);
    int adj[100][100];
    adjoint(keyMatrix,adj,n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            keyMatrix[i][j]=adj[i][j]/det;
        }
    }
}
void decrypt(int cipherMatrix[100][1], int keyMatrix[100][100], int messageVector[100][1], int n){
    inverse(keyMatrix,n);
    for(int i=0; i<n; i++){
        for(int j=0; j<1; j++){
            cipherMatrix[i][j]=0;
            for(int x=0; x<n; x++){
                cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
            }
            cipherMatrix[i][j]=cipherMatrix[i][j]%26;
        }
    }
}
void Hilldecode(string message, string key){
    int keyMatrix[100][100];
    int n= message.length();
    getKeyMatrix(key, keyMatrix, n);
    int messageVector[100][1];
    for(int i=0; i<n; i++){
        messageVector[i][0]=(message[i])%65;
    }
    int cipherMatrix[100][1];
    decrypt(cipherMatrix,keyMatrix,messageVector,n);
    string ciphertext;
    for(int i=0; i<n; i++){
        ciphertext += cipherMatrix[i][0] + 65;
    }
    cout<<"Decoded text after Hill Cipher decryption: "<<ciphertext;
}




int main()
{
//Hill Cipher Encoding
    string message,key;
    cout<<"Enter message\n";
    cin>>message;
    cout<<"\nEnter Key of size "<<pow(message.size(),2)<<endl;
    cin>>key;

    string Hill_Cipher_Encoded_Text=HillCipher_Encode(message,key);
    cout<<"\nEncoded Text after Hill Cipher: "<<Hill_Cipher_Encoded_Text<<endl;

/*------------------------------------********-----------------------------------------------*/
//Rail Fence Encoding
    int key2;
    cout<<"\nEnter integer key for rail fence encode of size<"<<Hill_Cipher_Encoded_Text.size()<<endl;
    cin>>key2;
    string Rail_Fence_Text=RailFence_Encode(Hill_Cipher_Encoded_Text,key2);
    cout<<"\nEncoded Text after Rail Fence Encode: "<<Rail_Fence_Text<<endl;

/*------------------------------------********-----------------------------------------------*/

  //decryption of rail fence
  //HERE We pass KEY2 as key and decode text of rail fence cipher (which was previously encoded by hill cipher)
  string Rail_Fence_Decoded_Text=RAIL_FENCE_DECRYPT(Rail_Fence_Text,key2);
  cout<<"\nDecoded Text after Rail Fence decode: "<<Rail_Fence_Decoded_Text<<endl;

/*------------------------------------********-----------------------------------------------*/

    //decoding of Hill Cipher
    cout<<"\n";
    Hilldecode(Rail_Fence_Decoded_Text, key);
    cout<<"\n";
    return 0;
}
