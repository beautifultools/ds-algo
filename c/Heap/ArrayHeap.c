#include "ArrayHeap.h"

Heap* make_init_heap() {
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	heap->inx = 0;
	return heap;
};

int push_heap(Heap* heap, h_data data) {
	if (is_full(heap))
		return (void*)0;

	h_data* tmp_arr = heap->h_arr;
	tmp_arr[++(heap->inx)] = data;
	int tmp_inx_chd = (heap->inx);


	while (tmp_inx_chd > 1) {
		int tmp_inx_prt = tmp_inx_chd / 2;
		h_data p_data = tmp_arr[tmp_inx_prt];
		h_data c_data = tmp_arr[tmp_inx_chd];
		if (cmp_hdata(p_data, c_data))
			break;
		tmp_arr[tmp_inx_prt] = c_data;
		tmp_arr[tmp_inx_chd] = p_data;
		tmp_inx_chd = tmp_inx_prt;
	}
};


h_data peek_heap(Heap* heap) {
	if (is_empty(heap))
		return (void*)0;
	return (heap->h_arr)[1];
};

h_data pop_heap(Heap* heap) {
	if (is_empty(heap))
		return (void*)0;

	h_data* tmp_heap = heap->h_arr;
	int inx = heap->inx--;
	h_data pop_data = tmp_heap[1];
	tmp_heap[1] = tmp_heap[inx];

	int i = 1;
	while (i * 2 <= inx) {
		if (cmp_hdata(tmp_heap[i], tmp_heap[i * 2]) && cmp_hdata(tmp_heap[i], tmp_heap[i * 2 + 1])) {
			break;
		}

		int tmp_inx_chd = i * 2;

		if (!cmp_hdata(tmp_heap[i * 2], tmp_heap[i * 2 + 1])) {
			tmp_inx_chd += 1;
		}

		tmp_heap[i] = tmp_heap[i] + tmp_heap[tmp_inx_chd];
		tmp_heap[tmp_inx_chd] = tmp_heap[i] - tmp_heap[tmp_inx_chd];
		tmp_heap[i] = tmp_heap[i] - tmp_heap[tmp_inx_chd];
		i = tmp_inx_chd;
	}
	return pop_data;
};

int is_empty(Heap* heap) {
		return (heap->inx) <= 0;
	};

	int is_full(Heap* heap) {
		return (heap->inx) >= MAX_SIZE_HEAP - 1;
	};

	int cmp_hdata(h_data p_data, h_data c_data) {
		return p_data > c_data;
	};

	int destroy_heap(Heap* heap) {
		free(heap);
	};
