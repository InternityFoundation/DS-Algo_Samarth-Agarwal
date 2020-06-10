#include<bits/stdc++.h>
using namespace std;

//Function to chech string is binary or not
int isBinary(string A)
{
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='0' || A[i]=='1' || A[i]=='.')
            continue;
        else
            return 0;
    }
    return 1;
}

int checkBinary(int N)
{
    while(N>0)
    {
        int rem=N%10;
        if(rem==0 || rem==1)
            N=N/10;
        else
            return 0;
    }
    return 1;
}

//function for 1
void binary_to_decimal(int n)
{
	int result=0;
	int base =1;
	while(n)
	{
		int digit=n%10;
		n=n/10;
		result+=digit*base;

		base=base*2;
	}
	cout<<"Decimal number is"<<endl;
	cout<<result<<endl;
}
//function for 2
void decimal_to_binary(int n)
{
	int a[100];
	int i=0;
	while(n>0)
	{
		a[i]=n%2;
		n=n/2;
		i++;
	}
	cout<<"Binary number is"<<endl;
	for(int j=i-1;j>=0;j--)
	cout<<a[j];
	cout<<endl;
}
//function for 3
void decimal_to_octal(int n)
{
	int a[1000];
	int i=0;
	while(n>0)
	{
		a[i]=n%8;
		n=n/8;
		i++;
	}
	cout<<"octal number is"<<endl;
	for(int j=i-1;j>=0;j--)
	cout<<a[j];
	cout<<endl;
}
//function for 4
void octal_to_decimal(int n)
{
	int result=0;
	int base=1;
	while(n>0)
	{
		int digit=n%10;
		n=n/10;
		result+=digit*base;
		base=base*8;
	}
	cout<<"Decimal number is"<<endl;
	cout<<result<<endl;
}

//Function for 5
void decimalToHexadecimal(int N)
{
    char A[100];
    int len=0;
    while(N!=0)
    {
        int rem=N%16;
        if(rem<10)
            A[len]=48+rem;
        else
            A[len]=55+rem;

        len++;
        N=N/16;
    }
    cout<<"Hexadecimal number is:"<<endl;
    for(int i=len-1;i>=0;i--)
        cout<<A[i];
    cout<<"\n";
}

//Function for 6
void hexadecimalToDecimal(string str)
{
    int base=1,sum=0;
    int len=str.size();
    for(int i=len-1;i>=0;i--)
    {
        if(str[i]>='0' && str[i]<='9')
            sum+=(str[i]-48)*base;
        else if(str[i]>='A' && str[i]<='F')
            sum+=(str[i]-55)*base;
        base*=16;
    }
    cout<<"Decimal number is:"<<endl;
    cout<<sum<<endl;
}

//Function for 7
void binaryToOctal(string str)
{
    int len=str.size();
    int t = str.find_first_of('.');
    int i;
    //length before "."
    int left = t != -1 ? t : len;
    // add min 0's in the beginning to make left substring length divisible by 3
    for (i=1;i<=(3-left%3)%3;i++)
        str = '0' + str;

    if (t!=-1) // if decimal point exists
    {
        // length of string after '.'
        int right = len - left - 1;

        // add min 0's in the end to make right substring length divisible by 3
        for (i = 1; i <= (3 - right % 3) % 3; i++)
            str = str + '0';
    }

    unordered_map<string, char> m;
    m["000"]='0';
    m["001"]='1';
    m["010"]='2';
    m["011"]='3';
    m["100"]='4';
    m["101"]='5';
    m["110"]='6';
    m["111"]='7';

    i=0;
    string sum="";

    while(1)
    {
        // one by one extract from left, substring of size 3 and add its octal code
        sum += m[str.substr(i, 3)];
        i += 3;
        if (i == str.size())
            break;
        if (str.at(i) == '.')
        {
            sum += '.';
            i++;
        }
    }
    cout<<"Octal number is:"<<endl;
    cout<<sum<<endl;
}

//Function for 8
void octalToBinary(string str)
{
    int len=str.size();
    string binary="";
    for(int i=0;i<len;i++)
    {
        switch(str[i])
        {
            case '0':
                binary += "000";
                break;
            case '1':
                binary += "001";
                break;
            case '2':
                binary += "010";
                break;
            case '3':
                binary += "011";
                break;
            case '4':
                binary += "100";
                break;
            case '5':
                binary += "101";
                break;
            case '6':
                binary += "110";
                break;
            case '7':
                binary += "111";
                break;
            default:
                cout << "\nInvalid Octal Digit "<<str[i]<<endl;
                break;
        }
    }
    cout<<"Binary number is:"<<endl;
    cout<<binary<<endl;
}
//Function for 9
void createMap(unordered_map<string, char> *um)
{
	(*um)["0000"] = '0';
	(*um)["0001"] = '1';
	(*um)["0010"] = '2';
	(*um)["0011"] = '3';
	(*um)["0100"] = '4';
	(*um)["0101"] = '5';
	(*um)["0110"] = '6';
	(*um)["0111"] = '7';
	(*um)["1000"] = '8';
	(*um)["1001"] = '9';
	(*um)["1010"] = 'A';
	(*um)["1011"] = 'B';
	(*um)["1100"] = 'C';
	(*um)["1101"] = 'D';
	(*um)["1110"] = 'E';
	(*um)["1111"] = 'F';
}


void convertBinToHex(string bin)
{
	int l = bin.size();
	int t = bin.find_first_of('.');

	int len_left = t != -1 ? t : l;


	for (int i = 1; i <= (4 - len_left % 4) % 4; i++)
		bin = '0' + bin;


	if (t != -1)
	{

		int len_right = l - len_left - 1;


		for (int i = 1; i <= (4 - len_right % 4) % 4; i++)
			bin = bin + '0';
	}


	unordered_map<string, char> bin_hex_map;
	createMap(&bin_hex_map);

	int i = 0;
	string hex = "";

	while (true)
	{

		hex += bin_hex_map[bin.substr(i, 4)];
		i += 4;
		if (i == bin.size())
			break;


		if (bin.at(i) == '.')
		{
			hex += '.';
			i++;
		}
	}


	cout<< hex<<endl;
}

//function for 10
void HexToBin(string hexdec)
{
    long int i = 0;

    while (hexdec[i]) {

        switch (hexdec[i]) {
        case '0':
            cout << "0000";
            break;
        case '1':
            cout << "0001";
            break;
        case '2':
            cout << "0010";
            break;
        case '3':
            cout << "0011";
            break;
        case '4':
            cout << "0100";
            break;
        case '5':
            cout << "0101";
            break;
        case '6':
            cout << "0110";
            break;
        case '7':
            cout << "0111";
            break;
        case '8':
            cout << "1000";
            break;
        case '9':
            cout << "1001";
            break;
        case 'A':
        case 'a':
            cout << "1010";
            break;
        case 'B':
        case 'b':
            cout << "1011";
            break;
        case 'C':
        case 'c':
            cout << "1100";
            break;
        case 'D':
        case 'd':
            cout << "1101";
            break;
        case 'E':
        case 'e':
            cout << "1110";
            break;
        case 'F':
        case 'f':
            cout << "1111";
            break;
        case '.':
            cout<<'.';
            break;
        default:
            cout << "\nInvalid hexadecimal digit "
                 << hexdec[i];
        }
        i++;
    }
    cout<<endl;
}

//function for 11
void octaltohexa(char s[]){
    int a[20], b[20], rev[20];
    int h, i, j, k, l, x, fra, flag, rem, num1, num3;
    float rem1, num2, num4, dno;
    x = fra = flag = rem = 0;
    rem1 = 0.0;
    for(i=0,j=0,k=0; i<strlen(s); i++)
        {
                if(s[i]=='.')
                {
                        flag=1;
                }
                else if(flag==0)
                {
                        a[j++]=s[i]-48;
                }
                else if(flag==1)
                {
                        b[k++]=s[i]-48;
                }
        }
        x=j;
        fra=k;
        for(j=0,i=x-1; j<x; j++,i--)
        {
                rem = rem +(a[j] * pow(8,i));
        }
        for(k=0,i=1; k<fra; k++,i++)
        {
                rem1 = rem1 +(b[k] / pow(8,i));
        }
        rem1 = rem + rem1;
        dno = rem1;
        num1 = (int)dno;
        num2 = dno - num1;

        i=0;
        while(num1!=0)
        {
                rem = num1 % 16;
                rev[i] = rem;
                num1 = num1 /16;
                i++;
        }
        j=0;
        while(num2!=0.0)
        {
                num2 = num2 * 16;
                num3 = (int)num2;
                num4 = num2 - num3;
                num2 = num4;
                a[j] = num3;
                j++;
                if(j==4)
                {
                        break;
                }
        }
        l=i;

        for(i=l-1; i>=0; i--)
        {
                if(rev[i]==10)
                {
                        cout<<"A";
                }
                else if(rev[i]==11)
                {
                        cout<<"B";
                }
                else if(rev[i]==12)
                {
                        cout<<"C";
                }
                else if(rev[i]==13)
                {
                        cout<<"D";
                }
                else if(rev[i]==14)
                {
                        cout<<"E";
                }
                else if(rev[i]==15)
                {
                        cout<<"F";
                }
                else
                {
                        cout<<rev[i];
                }
        }
        h=j;
        cout<<".";
        for(k=0; k<h; k++)
        {
                if(a[k]==10)
                {
                        cout<<"A";
                }
                else if(a[k]==11)
                {
                        cout<<"B";
                }
                else if(a[k]==12)
                {
                        cout<<"C";
                }
                else if(a[k]==13)
                {
                        cout<<"D";
                }
                else if(a[k]==14)
                {
                        cout<<"E";
                }
                else if(a[k]==15)
                {
                        cout<<"F";
                }
                else
                {
                        cout<<a[k];
                }
        }
        cout<<endl;
}
//function for 12
long long int hex_to_bin(char hex[])
{
	long long int bin, place;
	int i = 0, rem, val;

	bin = 0ll;
	place = 0ll;

	for (i = 0; hex[i] != '\0'; i++) {
		bin = bin * place;

		switch (hex[i]) {
		case '0':
			bin += 0;
			break;
		case '1':
			bin += 1;
			break;
		case '2':
			bin += 10;
			break;
		case '3':
			bin += 11;
			break;
		case '4':
			bin += 100;
			break;
		case '5':
			bin += 101;
			break;
		case '6':
			bin += 110;
			break;
		case '7':
			bin += 111;
			break;
		case '8':
			bin += 1000;
			break;
		case '9':
			bin += 1001;
			break;
		case 'a':
		case 'A':
			bin += 1010;
			break;
		case 'b':
		case 'B':
			bin += 1011;
			break;
		case 'c':
		case 'C':
			bin += 1100;
			break;
		case 'd':
		case 'D':
			bin += 1101;
			break;
		case 'e':
		case 'E':
			bin += 1110;
			break;
		case 'f':
		case 'F':
			bin += 1111;
			break;

		default:
			cout << "Invalid hexadecimal input.";
		}

		place = 10000;
	}

	return bin;
}


long long int bin_to_oct(long long bin)
{
	long long int octal, place;
	int i = 0, rem, val;

	octal = 0ll;
	place = 0ll;

	place = 1;


	while (bin > 0) {
		rem = bin % 1000;

		switch (rem) {
		case 0:
			val = 0;
			break;
		case 1:
			val = 1;
			break;
		case 10:
			val = 2;
			break;
		case 11:
			val = 3;
			break;
		case 100:
			val = 4;
			break;
		case 101:
			val = 5;
			break;
		case 110:
			val = 6;
			break;
		case 111:
			val = 7;
			break;

		}

		octal = (val * place) + octal;
		bin /= 1000;

		place *= 10;
	}

	return octal;
}


long long int hex_to_oct(char hex[])
{
	long long int octal, bin;


	bin = hex_to_bin(hex);


	octal = bin_to_oct(bin);

	return octal;
}

int main()
{
	while(1)
	{
        int ch;
        cout<<"Enter 0 to exit"<<endl;
        cout<<"Enter 1 for Binary to Decimal Conversion"<<endl;
        cout<<"Enter 2 for Decimal to Binary Conversion"<<endl;
        cout<<"Enter 3 for Decimal to Octal Conversion"<<endl;
        cout<<"enter 4 for Octal to Decimal Conversion"<<endl;
        cout<<"Enter 5 for Decimal to Hexadecimal conversion"<<endl;
        cout<<"Enter 6 for Hexadecimal to Decimal conversion"<<endl;
        cout<<"Enter 7 for Binary to Octal conversion"<<endl;
        cout<<"Enter 8 for Octal to Binary conversion"<<endl;
        cout<<"Enter 9 for Binary to Hexadecimal Conversion"<<endl;
        cout<<"Enter 10 for Hexadecimal to Binary Conversion"<<endl;
        cout<<"Enter 11 for Octal to Hexadecimal Conversion"<<endl;
        cout<<"Enter 12 for Hexadecimal to Octal Conversion"<<endl;
        cin>>ch;
        string str;
        int N;
        switch(ch)
        {
            case 0:
                cout<<"You have opted to EXIT"<<endl;
                exit(0);
            case 1:
                cout<<"Enter a binary number"<<endl;
                cin>>N;
                //cout<<checkBinary(N)<<" ";
                if(checkBinary(N)==1)
                    binary_to_decimal(N);
                else
                    cout<<"Not a binary number\n";
                break;
            case 2:
                cout<<"Enter a decimal number"<<endl;
                cin>>N;
                decimal_to_binary(N);
                break;
            case 3:
                cout<<"Enter a decimal number"<<endl;
                cin>>N;
                decimal_to_octal(N);
                break;
            case 4:
                cout<<"Enter a octal number"<<endl;
                cin>>N;
                octal_to_decimal(N);
                break;
            case 5:
                cout<<"Enter a decimal number"<<endl;
                cin>>N;
                decimalToHexadecimal(N);
                break;
            case 6:
                cout<<"Enter a Hexadecimal number"<<endl;
                cin>>str;
                hexadecimalToDecimal(str);
                break;
            case 7:
                cout<<"Enter a Binary number"<<endl;
                cin>>str;
                if(isBinary(str)==1)
                    binaryToOctal(str);
                else
                    cout<<"It is not a binary number"<<endl;
                break;
            case 8:
                cout<<"Enter a Octal number"<<endl;
                cin>>str;
                octalToBinary(str);
                break;
            case 9:
                {cout<<"Enter a binary number"<<endl;
                string bin;
                cin>>bin;
                if(isBinary(bin)==1)
                {
                    cout << "Hexadecimal number = ";
                    convertBinToHex(bin);
                }
                else
                    cout<<"It is not a binary number"<<endl;
                }
                break;
            case 10:
                {cout<<"Enter a hexadecimal number"<<endl;
                string s;
                cin>>s;


                cout << "\nEquivalent Binary value is : ";
                HexToBin(s);}
                break;
            case 11:
                {cout<<"Enter a octal number"<<endl;
                char s[20];
                cin>>s;
                cout<<"\n Equivalent Hexadecimal value ";
                octaltohexa(s);}
                break;
            case 12:
                {cout<<"Enter a hexadecimal number";
                char hex[20];
                cin>>hex;


                cout << "\nEquivalent Octal Value = " << hex_to_oct(hex); }
                break;
            default:
                {cout<<"Invalid number"<<endl;}
        }
    }
    return 0;
}
