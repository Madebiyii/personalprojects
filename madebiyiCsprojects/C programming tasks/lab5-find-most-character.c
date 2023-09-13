#include <stdio.h>
#include <string.h>

int countOccurences(char* str, char target);


int main(int argc, char* argv[]) {
	char* str = argv[1];
	char* pMax = str;
	int maxCount = 0;

	for (char* p=str; *p!='\0'; p++){
		if ('a'<*p && *p<'z'){
			int count = countOccurences(argv[1], *p);
			if (count > maxCount){
				pMax = p;
				maxCount = count;
			}
		}
	}
	printf("%c\n", *pMax);
	return 0;
}

int countOccurences(char* str, char target){
	char* pStr;
	int count = 0;
	int* pCount = &count;

	pStr = strchr(str, target);
	while (pStr){
		++*pCount;
		pStr = strchr(pStr+1, target);
	}
	return *pCount;
}
