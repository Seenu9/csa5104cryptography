#include<stdio.h>
#include<string.h>
int main(){
	char msg[500],key[500];
	printf("enter the message to be encrypted:");
	scanf("%s",msg);
	printf("enter the key message:");
	scanf("%s",key);
	int msglen=strlen(msg);
	int keylen=strlen(key),i,j;
	for(i=0;i<msglen;i++){
		msg[i]=toupper(msg[i]);
	}
	for(i=0;i<keylen;i++){
		key[i]=toupper(key[i]);
	}
	char newkey[msglen],encryptedmsg[msglen],decryptedmsg[msglen];
	for(i=0,j=0;i<msglen;i++,j++){
		if(j==keylen){
			j=0;
		}
		newkey[i]=key[j];
	}
	for(i=0;i<msglen;i++){
		encryptedmsg[i]=((msg[i]+newkey[i])%26)+'A';
	}
	for(i=0;i<msglen;i++){
		decryptedmsg[i]=(((encryptedmsg[i]-newkey[i])+26)%26)+'A';
	}
	printf("encrypted message:%s",encryptedmsg);
	printf("/ndecrypted message:%s",decryptedmsg);
}
