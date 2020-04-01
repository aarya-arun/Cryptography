#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <sys/time.h> 

using namespace std;

#define BYTE unsigned char


int len;

//encryption function
void encrypt(BYTE text[], BYTE key[])
{
    
    //bitwise XOR
    for(int i=0; i<len; i++)
    { text[i]^=key[i];}

   
    int p[10000];

   //displaying the ciphertext in readable format
   for(int i=0; i<len; i++)
   { p[i]=text[i] + 33;}


   for(int i=0; i<len; i++)
   { cout<<(char)p[i];}

    cout<<endl;


}


//decrypt function
void decrypt(BYTE text[], BYTE key[])
{

    //as we previously added 33 to ensure readability, we subtract 33
    for(int i=0; i<len; i++)
    { text[i]=text[i]-33;}

    
    //bitwise XOR
    for(int i=0; i<len; i++)
    { text[i]^=key[i];}

   
    int p[10000];

    //priting the decrypted text in readable format
   for(int i=0; i<len; i++)
   { p[i]=text[i];}


   for(int i=0; i<len; i++)
   { cout<<(char)p[i];}

    cout<<endl;


}


int main(int argc, char* argv[]) 
{
    //Whether to encrypt or decrypt

    char availableOpt[2] = {'d', 'e'};
    char mode;

    cout<<"Enter mode:";
    cin>>mode;

    cout<<endl<<endl;

    if(mode!=availableOpt[0] && mode!=availableOpt[1])
    {
        printf("\nWrong input. Please give correct arguments.");
        return 0;
    }




    //Input values from users

    char key1[10000], msg1[10000];

    printf("\n\nEnter message: ");
    fflush(stdin);
    gets(msg1);

    printf("\n\nEnter key: ");
    fflush(stdin);
    gets(key1);




    //Check if key and message have the same length
    if(strlen(key1)<strlen(msg1))
    {
        printf("\nKey length cannot be less than the length of text. Please try again.");
        return 0;
    }
    


    //Unsigned char variables
    BYTE text[10000], key[10000];

    
    //Global variable
    len=strlen(msg1);



    //Convert signed to unsigned
    for(int i=0; i<len; i++)
     {   

            text[i]=(unsigned char)msg1[i];
            key[i]=(unsigned char)key1[i];

        
     }



    //Outputs the plaintext
     for(int i=0; i<len; i++)
        cout<<text[i];

     cout<<endl<<endl;
   


    //Decides which function to call based on arguments
    if(mode == availableOpt[1])
        encrypt(text, key);
    else
        decrypt(text, key);




   


}
   
    
