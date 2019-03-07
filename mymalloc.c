#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"
#include <stddef.h>

typedef struct metadata {
  size_t blockSize;
  char free;
  struct metadata*next;
} Metadata;

 //convert the memory array into a void type and set head to be that value. converted to be able to store different type of data

void splitNode (Metadata* node, size_t sizeToAllocate){
   Metadata * newNode = (void*)((void*)node+sizeToAllocate+sizeof(Metadata));//allocate space for new node
   newNode ->blockSize = (node->blockSize)-sizeToAllocate-sizeof(Metadata);
   newNode ->free = 't';
   newNode ->next = node->next;
   node ->blockSize = sizeToAllocate;
   node->free ='f';
   node ->next = newNode;
}
void *mymalloc(size_t sizeToAllocate){
  Metadata * head = (void *)memoryBlock;
  if (sizeToAllocate <= 0 ){//check to make sure not trying to allocate negative bytes
      fprintf(stderr,"sorry you are trying to allocate invalid amount bytes of memory in %s at line %d\n", __FILE__,__LINE__);
      return NULL;
  }
  
  if((sizeof (Metadata)+sizeToAllocate)>4096){//check to make sure not trying to allocate bytes greater than given memory
   fprintf(stderr,"Sorry you are trying to allocate bytes more than the given memory in %s at line %d\n", __FILE__,__LINE__);
   return NULL;
  }


  void *chunckToReturn;
  Metadata* currentNode;
  
  if(head->blockSize==0)// checks to see if it is the first time calling malloc
     nodeCreator();
  currentNode = head;
  while ((currentNode ->blockSize <sizeToAllocate || currentNode->free =='f')&&currentNode ->next!=NULL){
      currentNode = currentNode -> next;
  }
   if (currentNode->blockSize == sizeToAllocate){//if the requested memory == to corresponding size
      currentNode ->free = 'f';// set node to be occupied
      currentNode->blockSize = sizeToAllocate;      
      chunckToReturn =  (void*)(++currentNode);

      return chunckToReturn;
   }
   else if (currentNode ->blockSize >(sizeToAllocate +sizeof(Metadata))){//if the requested memory is less than that memory should be stored in one node, split it.
   splitNode(currentNode, sizeToAllocate);
   chunckToReturn = (void *)(++currentNode);
   return chunckToReturn;   
   }
   else   
     return NULL;
}

void nodeCreator(){
   Metadata * head = (void *)memoryBlock;
   head->free ='t';
   head->blockSize = 4096-sizeof(Metadata);
   head ->next = NULL;
}
void free(void* memoryToFree){
  Metadata * head = (void *)memoryBlock;
  if(head->blockSize==0){
     fprintf(stderr,"sorry you are trying to free empty memory in %s at line %d\n", __FILE__,__LINE__); 
     return;
 }
  
  if (((void*)memoryBlock<=memoryToFree)&&(memoryToFree<=(void*)memoryBlock+4096)){
    Metadata * head = (void *)memoryBlock;
    Metadata * current = head;
    Metadata *freeingMemory;
    freeingMemory = memoryToFree;
    freeingMemory = freeingMemory-1;
    /*
    if (freeingMemory->free== 't'){
     fprintf(stderr,"sorry you are trying to free already freed memory in %s at line %d\n", __FILE__,__LINE__); 
     return;
    }*/
    while (current !=NULL){
       if (current == freeingMemory){

          if (freeingMemory->free== 't'){
            fprintf(stderr,"sorry you are trying to free already freed memory in %s at line %d\n", __FILE__,__LINE__); 
            return;
          }

          freeingMemory->free = 't';
          combineFreeSpace();
          break;
      }
     current = current->next;
   }

   if (current == NULL){ 
    fprintf(stderr, "Error you are trying to free memory that was not dynamically allocated in %s at line %d\n", __FILE__, __LINE__);
   }

  }
  else
    fprintf(stderr, "Error you are trying to free memory that was not dynamically allocated in %s at line %d\n", __FILE__, __LINE__);

}

void combineFreeSpace(){
  Metadata * head = (void *)memoryBlock;
  Metadata* nextNode;
  Metadata* currentNode;
  currentNode=head;
  nextNode = head->next;
  while (nextNode !=NULL){
    if(currentNode ->free =='t' && nextNode->free =='t'){
    //printf("I was able to combine free space here\n");
     while (nextNode ->free =='t'|| nextNode ==NULL){
        currentNode ->blockSize = currentNode ->blockSize + nextNode->blockSize + sizeof(Metadata);
        currentNode -> next = nextNode->next;
        nextNode = nextNode->next;
     }
     if (nextNode == NULL)
        break;
   }
   
  nextNode = nextNode->next;
  currentNode =currentNode->next;
 }

}

int main(int argc, char **argv){
  char *example;
  char *yes;
  char *no;
  int *number =NULL;
  free(number);
 // int what [] ={1,3,5};
  int x =sizeof(Metadata);
 printf("metadata %d\n",x);
  example = (char*) malloc (sizeof(char)*5);
  if (example == NULL){
    printf("loc refused to return something\n");
    return 0;
  }

 yes = (char *) malloc (sizeof(char)*4);
  if (yes == NULL){
    printf("sorry buddy malloc refused to return something\n");
    return 0;
  }
  no = (char *)malloc (sizeof (char)*3);
  no[0]='n';no[1]='o';no[2]='\0';
  for (int i=0;i <10; i++){
     number = (int*) malloc (sizeof(int)*10);
    if (number == NULL){
    printf("sorry malloc to return NULL\n");
    return 0;
  }
     number[i] =i*i;
     printf("%d\t",number[i]);
  }
  Metadata * head = (void *)memoryBlock;
  Metadata *current =head;
  printf("\n");
  while (current !=NULL){
  printf("%d\t", (int) (current->blockSize));
  current = current->next;
  }
  printf("\n");
  yes[0]='y';
  yes[1]='e';
  yes[2] ='s';
  yes[3] ='\0';
  printf("%s\n",yes);
  example[0]='E';
  example[1]='x';
  example[2]='a';
  example[3]='m';
  example[4]='p';
  example[5]='l';
  example[6]='e';
  example[7]='\0';
  printf ("%s\n",example);
  free(example);
  free(yes);
  free(yes);
  free(no+2);
  //free(what);
  //printf ("%s\n",example);
return 0;
}
