#include <bits/stdc++.h>
using namespace std;

#define M 3

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


int inverse(int b)
{
	int inv;
	int q, r, r1 = 26, r2 = b, t, t1 = 0, t2 = 1;

	while (r2 > 0) {
		q = r1 / r2;
		r = r1 - q * r2;
		r1 = r2;
		r2 = r;

		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}

	if (r1 == 1) {
		inv = t1;
		if (inv < 0)
			inv = inv + 26;
		return inv;
	}

	return -1;
}

void inverseMatrix(int key[][3], int inv[][3])
{
	int C[3][3]; // matrix for cofactors of  key[][]
	int A[3][3]; // matrix for adjoint of C[][]

	C[0][0] = key[1][1] * key[2][2] - key[2][1] * key[1][2];
	C[0][1] = -(key[1][0] * key[2][2] - key[2][0] * key[1][2]);
	C[0][2] = key[1][0] * key[2][1] - key[1][1] * key[2][0];
	C[1][0] = -(key[0][1] * key[2][2] - key[2][1] * key[0][2]);
	C[1][1] = key[0][0] * key[2][2] - key[2][0] * key[0][2];
	C[1][2] = -(key[0][0] * key[2][1] - key[2][0] * key[0][1]);
	C[2][0] = key[0][1] * key[1][2] - key[0][2] * key[1][1];
	C[2][1] = -(key[0][0] * key[1][2] - key[1][0] * key[0][2]);
	C[2][2] = key[0][0] * key[1][1] - key[1][0] * key[0][1];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			A[i][j] = C[j][i];
		}
	}

	int det = key[0][0] * C[0][0] + key[0][1] * C[0][1] + key[0][2] * C[0][2];

	if (det == 0 || det % 2 == 0 || det % 13 == 0) {
        cout<<"The text cannot be encrypted. Take valid key"<<endl;


	}

	int invs = inverse(det);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			inv[i][j] = A[i][j] * invs;
		}
	}

	//cout<<"\nInverse of a Key-\n"<<endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (inv[i][j] >= 0) {
				inv[i][j] = inv[i][j] % 26;
				//cout<<inv[i][j]<<" ";
			}
			else {
				for (int x = 0;; x++) {
					if (x * 26 + inv[i][j] > 0) {
						inv[i][j] = x * 26 + inv[i][j];
						break;
					}
				}
				//cout<<inv[i][j]<<" ";
			}
		}
		//cout<<endl;
	}
}


string decrypt(string s, string key)
{
    int keyMatrix[3][3];
    int k=0;
    //fill the KEYMATRIX with values of KEY
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            keyMatrix[i][j]=key[k]%65;
            k++;
        }
    }
    int inv[3][3];
	inverseMatrix(keyMatrix, inv);
	string d = "";
	k = 0;
	int input[3];

	while (k < s.length()) {
		input[0] = s[k++] - 65;
		input[1] = s[k++] - 65;
		input[2] = s[k++] - 65;

		for (int i = 0; i < 3; i++) {
			int decipher = 0;
			for (int j = 0; j < 3; j++) {
				decipher += inv[i][j] * input[j];
			}
			d += (decipher % 26) + 65;
		}
	}
	return d;
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
    cout << "\nDecrypted Text: " << decrypt(Rail_Fence_Decoded_Text, key);
    cout<<"\n";
    return 0;
}
