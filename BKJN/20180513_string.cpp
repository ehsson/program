#include <stdio.h>

int main(void)
{
	char arr[501];

	printf("영문 10글자 이하를 입력하세요.\n");
	scanf_s("%s", arr, 10);

	printf("입력한 영문자를 모두 소문자로 바꿨습니다.\n");

	for (int k = 0; k < 501; k++) 
	{
		if (arr[k] == 0) break;

		if ( arr[k] >= 'A' && arr[k] <= 'Z')
		{
			arr[k] = arr[k] + ('a' - 'A');
		}

	}

	printf("%s\n", arr);

	return 0;
}