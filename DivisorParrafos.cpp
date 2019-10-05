#include <fstream>
#include<ctime>
#include <chrono>
#include <iomanip>
#include <queue>
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#include "time.h"
using namespace std;

void printwrap(const char *s, int lineSize, const char *prefix) {
	const char *head = s;
	int pos, lastSpace;
	
	pos = lastSpace = 0;
	while(head[pos]!=0) {
		int isLf = (head[pos]=='\n');
		if (isLf || pos==lineSize) {
			if (isLf || lastSpace == 0) { lastSpace = pos; } // just cut it
			if (prefix!=NULL) { printf("%s", prefix); }
			while(*head!=0 && lastSpace-- > 0) { printf("%c", *head++); }
			printf("\n");
			if (isLf) { head++; } // jump the line feed
			while (*head!=0 && *head==' ') { head++; } // clear the leading space
			lastSpace = pos = 0;
		} else { 
			if (head[pos]==' ') { lastSpace = pos; }
			pos++;
		}
	}
	printf("%s\n", head);
}

int main(){
	int i;
	char *text = "Hola como te encuentras, yo me encuentro muy bien ahora que estoy en mi casa por que la vida es mejor estando en mi pueblo tepotzotlan.\n";
	printwrap(text, 30, ">\t");
	return 0;
}
