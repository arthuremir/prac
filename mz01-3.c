#include <stdio.h>
#include <stdlib.h>

struct Pair {
    int key;
    int value;
};

void merge(struct Pair *data, int l, int m, int r);

void mergeSort(struct Pair *data, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(data, l, m);
        mergeSort(data, m + 1, r);
        merge(data, l, m, r);
    }
}

void merge(struct Pair *data, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    struct Pair L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = data[l + i];
    for (j = 0; j < n2; j++)
        R[j] = data[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i].key <= R[j].key) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}


void process(struct Pair *data, size_t size) {
    mergeSort(data, 0, (int) size - 1);
}

#define si 50
#define max_number 5
#define minimum_number -5

int
main(void) {

    struct Pair p[si];

    for (int i = 0; i < si; i++) {
        //scanf("%d%d", &p[i].key, &p[i].value);
        p[i].key = rand() % (max_number + 1 - minimum_number) + minimum_number;
        p[i].value = rand() % (max_number + 1 - minimum_number) + minimum_number;
        printf("key: %d, value: %d\n", p[i].key, p[i].value);
    }

    process(p, si);
    printf("SORTED:\n");
    for (int i = 0; i < si; i++) {
        printf("key: %d, value: %d\n", p[i].key, p[i].value);
    }
    //free(p);
    return 0;
}

/*void process(struct Pair *data, size_t size){
    struct Pair temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (data[j].value > data[j + 1].value)
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}*/