// Copyright 2021 NNTU-CS

void mysort(int *arr, int len) {
    int temp = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int countPairs1(int *arr, int len, int value) {
    mysort(arr, len);
    int counter = 0;
    for (int i = 0; i < len; i++) {
        if (value < arr[i]) {
            break;
        } else {
            for (int j = i+1; j < len-1; j++) {
                if ((value - arr[i]) < arr[j]) {
                    break;
                } else {
                    int sum = arr[i] + arr[j];
                    if (sum == value) {
                        counter += 1;
                    }
                }
            }
        }
    }
    return counter;
}
int countPairs2(int *arr, int len, int value) {
    mysort(arr, len);
    int counter = 0;
    for (int i = 0; i < len; i++) {
        if (value < arr[i]) {
            break;
        } else {
            for (int j = len; j > i; j--) {
                if (value < arr[j]) {
                    continue;
                } else {
                    int sum = arr[i] + arr[j];
                    if (sum == value) {
                        counter += 1;
                    }
                }
            }
        }
    }
    return counter;
}

int cbinsearch(int *arr, int size, int value) {
    int j = size - 1;
    int mid = j/2;
    int cnt = 0;
    if (value == arr[mid]) {
        if (arr[mid] == arr[mid-1]) {
            for (int i = mid; i >= 0; i--) {
                if (arr[i] == value) {
                    cnt += 1;
                } else {
                    break;
                }
            }
        }
        if (arr[mid] == arr[mid+1]) {
            int i = mid;
            if (0 != cnt) {
                i += 1;
            }
            for (; i < size; i++) {
                if (arr[i] == value) {
                    cnt += 1;
                } else {
                    break;
                }
            }
        }
    } else if (value < arr[mid]) {
        for (int i = mid; i >= 0; i--) {
            if (arr[i] == value) {
                cnt += 1;
            }
            if (arr[i] == value && arr[i-1] != value) {
                break;
            }
        }
    } else if (value > arr[mid]) {
        for (int i = mid; i < size; i++) {
            if (arr[i] == value) {
                cnt += 1;
            }
            if (arr[i] == value && arr[i+1] != value) {
                break;
            }
        }
    }
    return cnt;
}

int countPairs3(int *arr, int len, int value) {
    mysort(arr, len);
    int counter = 0;
    for (int i = 0; i < len; i++) {
        if (value < arr[i]) {
            break;
        } else {
            int ost = value - arr[i];
            counter += cbinsearch(arr, len, ost);
        }
    }
    return counter;
}
