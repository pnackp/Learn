#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct hash{
  char *key;
  int val;
}hash;

hash * hashtable[TABLE_SIZE];

unsigned int hashkey(const char* key) {
    unsigned int hashk = 0;
    while (*key) {
        hashk = (hashk * 31) + *key++;
    }
    return hashk % TABLE_SIZE;
}

void insert(const char *key,int val){
  int x = hashkey(key);

  while(hashtable[x] != NULL && strcmp(hashtable[x]->key,key) != 0){
    x = (x+1) % TABLE_SIZE;
  }
  if(hashtable[x] != NULL){
    free(hashtable[x]->key);
  }else {
    hashtable[x] = malloc(sizeof(hash));
  }
  hashtable[x]->key = strdup(key);
  hashtable[x]->val = val;
  return ;
}

int search(const char*key){
  for(int i = 0 ; i < TABLE_SIZE ; i++){
    if(hashtable[i] != NULL){
      if(strcmp(hashtable[i]->key,key) == 0){
        printf("[%d] %s: %d\n", i, hashtable[i]->key, hashtable[i]->val);
        return hashtable[i]->val;
      }
    }
  }
  printf("Not Found\n");
  return 0;
}

void printTable(){
  for(int i = 0 ; i< TABLE_SIZE ; i++){
    if (hashtable[i] != NULL) {
      printf("[%d] %s: %d\n", i, hashtable[i]->key, hashtable[i]->val);
    } else {
      printf("[%d] free\n", i);
    }
  }
}

void freeTable(){
  for(int i = 0 ;i < TABLE_SIZE; i++){
    if(hashtable[i] != NULL){
      free(hashtable[i]->key);
      free(hashtable[i]);
    }
  }
}

int main() {
    insert("apple", 50);
    insert("banana", 100);
    insert("cherry", 200);

    printTable();

    printf("\nค้นหา banana: %d\n", search("banana"));
    printf("ค้นหา grape: %d\n", search("grape"));

    freeTable();
    return 0;
}

