#include "Que.h"
#include <stdio.h>

int main()
{
	Que* que = make_init_que();
	push_que(que, 1);
	push_que(que, 3);
	push_que(que, 5);

	printf("%d", pop_que(que));
	printf("%d", pop_que(que));
	printf("%d", pop_que(que));
	printf("%d", pop_que(que));
}