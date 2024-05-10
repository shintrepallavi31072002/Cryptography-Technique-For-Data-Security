#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;
string message;
int cencrypt(string message);
int cdecrypt();
int poly(string message);
char hencrypt(string message);
int hdecrypt();
char monocipher_encr(char);
char monocipher_decr(char);
char monoalphabetic();
char mono(char message1[100]);
char mono1(char str2[100]);
char message1[100];
char alpha[27][3] = { { 'a', 'f' }, { 'b', 'a' }, { 'c', 'g' }, { 'd', 'u' }, {
        'e', 'n' }, { 'f', 'i' }, { 'g', 'j' }, { 'h', 'k' }, { 'i', 'l' }, {
        'j', 'm' }, { 'k', 'o' }, { 'l', 'p' }, { 'm', 'q' }, { 'n', 'r' }, {
        'o', 's' }, { 'p', 't' }, { 'q', 'v' }, { 'r', 'w' }, { 's', 'x' }, {
        't', 'y' }, { 'u', 'z' }, { 'v', 'b' }, { 'w', 'c' }, { 'x', 'd' }, {
        'y', 'e' }, { 'z', 'h' } };
        char alpha1[27][3] = { { 'f', 'a' }, { 'a', 'b' }, { 'g', 'c' }, { 'u', 'd' }, {
        'n', 'e' }, { 'i', 'f' }, { 'j', 'g' }, { 'k', 'h' }, { 'l', 'i' }, {
        'm', 'j' }, { 'o', 'k' }, { 'p', 'l' }, { 'q', 'm' }, { 'r', 'n' }, {
        's', 'o' }, { 't', 'p' }, { 'v', 'q' }, { 'w', 'r' }, { 'x', 's' }, {
        'y', 't' }, { 'z', 'u' }, { 'b', 'v' }, { 'c', 'w' }, { 'd', 'x' }, {
        'e', 'y' }, { 'h', 'z' } };
char str2[100];
int main()
{


    int choice,j;
    cout<<"\n________________________________________________CRYPTOGRAPHY TECHNIQUE_________________________________________________\n";
    do{
    cout<<"                   \n     1.MONO-ALPHABETIC CIPHER\n     2.CAESER CIPHER\n     3.POLY-ALPHABETIC CIPHER\n     4.Hill Cipher                 \n";
    cout<<"\n___________________________________________*********************************____________________________________________\n";
	cout<<"\n   Enter Choice :";
    cin>>choice;
    
    switch(choice)
    {

    case 1:
        fflush(stdin);
        monoalphabetic();
        break;
    case 2:
        cout<<"\n   Enter Message  :";
        cin>>message;
    	cencrypt(message);
    	cdecrypt();
        break;
    case 3:
        cout<<"\n   Enter Message  :";
        cin>>message;
        poly(message);
        break;
    case 4:
        cout<<"\n   Enter Message  :";
        cin>>message;
        hencrypt(message);
        hdecrypt();
    	break;
    	
    default:
        cout<<"   wrong choice\nEnter choice 1-4";

    }
        cout<<"\n   Press 1 for contine and 0 for exit ";
        cin>>j;
        fflush(stdin);
}while(j!=0);
	
    return 0;
}

//Mono alphabet Cipher        
char monoalphabetic()
{
	printf("\n   Enter Message  :");
    gets(message1);
	mono(message1);
	mono1(str2);
}
//encryption
char mono(char message1[100]) 
{
    int i;
    for (i = 0; message1[i]; i++) {
        str2[i] = monocipher_encr(message1[i]);
    }
    str2[i] = '\0';
    printf("\n   Before encryption  :  %s\n", message1);
    fflush(stdin);
    printf("\n   After encryption   :  %s\n", str2);
    fflush(stdin);
}
char monocipher_encr(char a) {
    int i;
    for (i = 0; i < 27; i++) {
        if (a == alpha[i][0])
            break;
    }
    return alpha[i][1];
}
//decryption
char mono1(char str2[100]) 
{
    char str3[20];
    int i;
    for (i = 0; str2[i]; i++) {
        str3[i] = monocipher_decr(str2[i]);
    }
    str3[i] = '\0';
    fflush(stdin);
    printf("\n   After decryption   :  %s\n", str3);
    //fflush(stdin);
}
char monocipher_decr(char a) {
    int i;
    for (i = 0; i < 27; i++) {
        if (a == alpha1[i][0])
            break;
    }
    return alpha1[i][1];
}
//cout<<"_________________________________________________________________________________________________________________________";


//ceaser
int cencrypt(string message)
{

    int i,j,k;
    string t;
    int key;
    cout<<"\n   Enter the key(1-25) :";
    cin>>key;
    for(i=0;i<message.size();i++)
	{
        t+=(message[i]-'a'+key)%26+'a';
    }
    cout<<"\n   Encrypted message is : "<<t<<'\n';
    return 0;
}
int cdecrypt()
{
	int i,j,k;
    int key;
    string t,t1;
    cout<<"\n   Enter message to decrypt : ";
    cin>>t;
    cout<<"\n   Enter the key(1-25) :";
    cin>>key;
    for(i=0;i<t.size();i++)
	{
        t1+=(t[i]-'a'-key+26)%26+'a';
    }
    cout<<"\n   Decrypted message is "<<t1<<'\n';
    return 0;
}
//cout<<"_________________________________________________________________________________________________________________________";


//poly
string get_full_key(string pt, string k){
	if(k.size() >= pt.size())
		return k;
	else{
		int psize = pt.size()-k.size();
		int ksize = k.size(); 
		while(psize >= ksize){
			k += k;
			psize -= ksize;
		}

		k += k.substr(0, psize);
		return k;
	}
}
// Encryption Function
string get_encryption(string pt, string k){

	string ct = "";
	for(int i=0;i<pt.size();i++)
		ct += (char) (((int)pt[i]-'a' + (int)k[i]-'a') % 26) + 'a';

	return ct;
}

// Decryption Function
string get_decryption(string ct, string k){

	string pt = "";
	for(int i=0;i<ct.size();i++)
		pt += (char) ((((int)ct[i]- 'a' - (k[i] -'a')) + 26) % 26) + 'a';

	return pt;
}

int poly(string message)
{

	
	// The key
	string key;
	cout<<"\n   Enter the key(string) :";
	cin>>key;
	string plaintext=message;
	

	// Function call to extend the key size
	key = get_full_key(plaintext, key);

	cout<<"\n  The Plaintext : "<< plaintext <<endl;

	cout<<"\n  The Key: "<< key <<endl;

	// Function call to encode the data
	string ciphertext = get_encryption(plaintext, key);

	cout<<"\n  The Ciphertext : "<< ciphertext <<endl;

	// Function call to decode the data
	plaintext = get_decryption(ciphertext, key);

	cout<<"\n  The Decode Plaintext : "<< plaintext <<endl;

	return 0;
}
//cout<<"_________________________________________________________________________________________________________________________";
//Hill Cipher
//Encryption of hill cipher
char hencrypt(string message)
{
    int x,y,i,j,k,n;
    cout<<"\n   Enter the size key matrix  : \n";
    cin>>n;
    cout<<"\n   Enter the (2x2) key matrix(1-26) : \n";
    int a[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    

    int temp = (n-message.size()%n)%n;
    for(i=0;i<temp;i++){
        message+='x';
    }
    k=0;
    string ans="";
    while(k<message.size()){
        for(i=0;i<n;i++){
            int sum = 0;
            int temp = k;
            for(j=0;j<n;j++){
                sum += (a[i][j]%26*(message[temp++]-'a')%26)%26;
                sum = sum%26;
            }
            ans+=(sum+'a');
        }
        k+=n;
    }
    cout<<ans<<'\n';
    return 0;    
}
//Decryption hill cipher
int modInverse(int a, int m){ 
    a=a%m; 
    for(int x=-m;x<m;x++) 
       if((a*x)%m==1) 
          return x; 
} 
void getCofactor(vector<vector<int> > &a, vector<vector<int> > &temp, int p, int q, int n){ 
    int i=0,j=0; 
    for(int row=0;row<n;row++){ 
        for(int col=0;col<n;col++){ 
            if(row!=p&&col!=q){ 
                temp[i][j++] = a[row][col]; 
                if (j==n-1){ 
                    j=0; 
                    i++; 
                } 
            } 
        } 
    } 
}
int determinant(vector<vector<int> > &a, int n, int N){ 
    int D = 0;
    if(n==1) 
        return a[0][0]; 
    vector<vector<int> > temp(N, vector<int>(N));
    int sign = 1;
    for(int f=0;f<n;f++){ 
        getCofactor(a, temp, 0, f, n); 
        D += sign * a[0][f] * determinant(temp, n - 1, N); 
        sign = -sign; 
    }
    return D; 
} 
void adjoint(vector<vector<int> > &a,vector<vector<int> > &adj,int N){ 
    if(N == 1){ 
        adj[0][0] = 1; 
        return; 
    } 
    int sign = 1;
    vector<vector<int> > temp(N, vector<int>(N));
    for(int i=0;i<N;i++){ 
        for(int j=0;j<N;j++){ 
            getCofactor(a, temp, i, j, N); 
            sign = ((i+j)%2==0)? 1: -1; 
            adj[j][i] = (sign)*(determinant(temp, N-1 , N)); 
        } 
    } 
} 
bool inverse(vector<vector<int> > &a, vector<vector<int> > &inv, int N){ 
    int det = determinant(a, N, N); 
    if(det == 0){ 
        cout << "   Inverse does not exist "; 
        return false; 
    } 
    int invDet = modInverse(det,26);
    cout<<det%26<<' '<<invDet<<'\n';
    vector<vector<int> > adj(N, vector<int>(N));
    adjoint(a, adj, N);  
    for(int i=0;i<N;i++) 
        for(int j=0;j<N;j++) 
            inv[i][j] = (adj[i][j]*invDet)%26; 
    return true; 
} 
int hdecrypt(){
    int x,y,i,j,k,n;
    cout<<"   Enter the  size key matrix : \n";
    cin>>n;
    cout<<"\n   Enter the key(2x2) matrix(1-26) : \n";
    vector<vector<int> > a(n, vector<int>(n));
    vector<vector<int> > adj(n, vector<int>(n));
    vector<vector<int> > inv(n, vector<int>(n));
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    if(inverse(a,inv,n)){
        cout<<"  Inverse exist\n";
    }
    cout<<"\n   Enter the message to decrypt : ";
    string s;
    cin>>s;
    k=0;
    string ans;
    while(k<s.size()){
        for(i=0;i<n;i++){
            int sum = 0;
            int temp = k;
            for(j=0;j<n;j++){
                sum += ((inv[i][j] + 26)%26*(s[temp++]-'a')%26)%26;
                sum = sum%26;
            }
            ans+=(sum+'a');
        }
        k+=n;
    }
    //ans+='\0';
    int f=ans.size()-1;
    while(ans[f]=='x'){
        f--;
    }
    for(i=0;i<=f;i++){
        cout<<ans[i];
    }
    cout<<'\n';
    return 0;    
}
//cout<<"_________________________________________________________________________________________________________________________";



