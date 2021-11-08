#pragma once

bool ascend(int x, int y);
bool descend(int x, int y);
void flip_vals(int& px, int& py);
void sort1(int* arr, int arraySize, bool (*sort_criteria)(int, int));