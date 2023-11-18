#include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef struct cacheA {
	int value;
	int key;
	struct cacheA * next;
	struct cacheA * prev;
	struct cacheA * hashNext;
}cacheA;

cacheA *head = NULL;
cacheA *tail = NULL;
cacheA *array = NULL;
cacheA *hash[2];
int count = 0;
int maxCap = 0;

void cache(int capacity) {

    array = malloc(capacity* sizeof(cacheA));  
    memset(array,0, capacity*sizeof(cacheA));
    memset(hash, 0,sizeof(hash));
    count = 0;
    maxCap = capacity;
    head = NULL;
    tail = NULL;
}

cacheA *getKey(int key) {
	cacheA *current = hash[key];

	while (current) {
		if (current->key == key) {
			break;
		} 
		else {
		current = current->hashNext;
		}
	}

	if (current) {
		if (head != current) {
			if (current->prev){
				current->prev->next = current->next;
			}

			if (tail == current){
				tail = current->prev;
				current->next = head;
				head->prev = current;
				current->prev = NULL;
				head = current;
			}
		}
		return current;
	}
	return NULL;
}

int get(int key) {
    cacheA * current = getKey(key);

    if (current){
        return current->value;
	}
    
	return -1;
}

void put(int key, int value) {
    cacheA * current = getKey(key);
    cacheA * hash_head = NULL;
    cacheA * new_hash = NULL;
    cacheA * prev = NULL;

    if (current) {
		current->value = value;
		return;
    }

    if (count < maxCap) {
		new_hash = (array + count);
		new_hash->hashNext = hash[key];;
		hash[key] = new_hash;

		if (!tail) {
			tail = new_hash;
			head = new_hash;
		} 
		else {
			new_hash->next = head;
			head->prev = new_hash;
			new_hash->prev = NULL;
			head = new_hash;
		}
		new_hash->key = key;
		new_hash->value = value;

		count++;
		return;
    }

    current = hash[tail->key];

    if (current->key == tail->key) {
		hash[tail->key] = current->hashNext;
    } 
	else {
        prev = current;
        while(current && current->key != tail->key) {
            prev = current;
            current = current->hashNext;
       }
       prev->hashNext = current->hashNext;
    }
    current->key = key;
    current->value = value;
    current->hashNext =  hash[key];
    hash[key] = current;
    current = getKey(key);
}
void main()
{
	cache(2);

	put(1, 10);
	put(2, 20);
	printf("%d\n", get(1));
	put(3, 30);
	printf("%d\n", get(2));
    put(4, 40);
	printf("%d\n", get(1));
	printf("%d\n", get(3));
	printf("%d\n", get(4));
	put(5, 50);
}
