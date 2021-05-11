#include "UsefulHeap.h"

void HeapInit(Heap* ph, PriorityComp pc) {
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap* ph) {
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) {
	return idx / 2;
}

int GetLChildrenIDX(int idx) {
	return idx * 2;
}

int GetRChildrenIDX(int idx) {
	return GetLChildrenIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap* ph, int idx) {
	if (GetLChildrenIDX(idx) > ph->numOfData)
		return 0;
	else if (GetLChildrenIDX(idx) == ph->numOfData)
		return GetLChildrenIDX(idx);
	else {
		if (ph->comp(ph->heapArr[GetLChildrenIDX(idx)], ph->heapArr[GetRChildrenIDX(idx)]) < 0)
			return GetRChildrenIDX(idx);
		else
			return GetLChildrenIDX(idx);
	}
}

void HInsert(Heap* ph, HData data) {
	int idx = ph->numOfData + 1;
	while (idx != 1) {
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)])) {
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		} else {
			break;
		}
	}

	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}

HData Hdelete(Heap* ph) {
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {
		if (ph->comp(lastElem, ph->heapArr[childIdx]))
			break;
		
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData -= 1;
	return retData;
}