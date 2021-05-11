#include "linkedList.h"
#include <stdio.h>

int main()
{
	List* list = make_init_list();
	push_list(list, 3);
	push_list(list, 5);
	push_list_inx(list, 10, 1);
	push_list(list, 7);

	printf("%d", pop_list_inx(list,1));
	
	if (NULL) {
		printf("dlkjsdkfjsldkfjslkdjfslkdjfslkdjflksjdflksjdflksjdf%s", "1");
	}


	destroy_list(list);
	return 0;
}
