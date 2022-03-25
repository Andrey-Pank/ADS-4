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
    int counter = 0;
    for (int i = 0; i < len-1; i++) {
         for (int j = i+1; j < len; j++) {
             if (value == arr[i] + arr[j]) {
                 counter += 1;
             }
         }
    }
    return counter;
}
int countPairs2(int *arr, int len, int value) {
    int counter = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (value >= arr[i]) {
            for (int j = i + 1; j < len; j++) {
                if (value == arr[i] + arr[j]) {
                    counter += 1;
                }
            }
        }
    }
    return counter;
}

int cbinsearch(int *arr, int size, int value, int index) {
    int cnt = 0;
    int i = index;
    int j = size;
    while (i < j-1) {
        int mid = (i + j) / 2;
        if (arr[mid] > value) {
            j = mid;
        } else if (arr[mid] < value) {
            i = mid;
        } else {
            cnt += 1;
            int temp = mid + 1;
            while ((arr[temp] == value) && (temp < j)) {
                cnt += 1;
                temp += 1;
            }
            temp = mid - 1;
            while ((arr[temp] == value) && (temp > i)) {
                cnt += 1;
                temp -= 1;
            }
            break;
        }
    }
    return cnt;
}

int countPairs3(int *arr, int len, int value) {
    mysort(arr, len);
    int counter = 0;
    for (int i = 0; i < len; i++) {
       int ost = value - arr[i];
       counter += cbinsearch(arr, len, ost, i);
    }
    return counter;
}
