#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"
#include <stddef.h>

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



void *mymalloc(size_t sizeToAllocate, const char *File,int lineNumber){
  Metadata * head = (void *)memoryBlock;
  if (sizeToAllocate <= 0 ){//check to make sure not trying to allocate negative bytes
      fprintf(stderr,"sorry you are trying to allocate invalid amount bytes of memory in %s at line %d\n", File,lineNumber);
      return NULL;
  }
  

  if((sizeof (Metadata)+sizeToAllocate)>4096){//check to make sure not trying to allocate bytes greater than given memory
   fprintf(stderr,"Sorry you are trying to allocate bytes more than the given memory in %s at line %d\n", File,lineNumber);
   return NULL;
  }
  short * magicNumberTest = (short*)memoryBlock;
  short magicNumber = 3;
  void *chunckToReturn;
  Metadata* currentNode;
  

  if(*magicNumberTest == magicNumber)// checks to see if it is the first time calling malloc
     nodeCreator();

  currentNode = head;
  while ((currentNode ->blockSize <sizeToAllocate || currentNode->free =='f')&&currentNode ->next!=NULL){
      currentNode = currentNode -> next;
  }//end of while loop
   if (currentNode->blockSize == sizeToAllocate){//if the requested memory == to corresponding size
      currentNode ->free = 'f';// set node to be occupied
      currentNode->blockSize = sizeToAllocate;      
      chunckToReturn =  (void*)(++currentNode);

      return chunckToReturn;
   }//end of if statement

   else if (currentNode ->blockSize >(sizeToAllocate +sizeof(Metadata))){
//if the requested memory is less than that memory should be stored in one node, split it.
   splitNode(currentNode, sizeToAllocate);
   chunckToReturn = (void *)(++currentNode);
   return chunckToReturn;   
   }//end of else if
   else   
     return NULL;
}

void nodeCreator(){
   Metadata * head = (void *)memoryBlock;
   head->free ='t';
   head->blockSize = 4096-sizeof(Metadata);
   head ->next = NULL;
} //end of node creator

void myfree(void* memoryToFree,const char *File,int lineNumber){
  Metadata * head = (void *)memoryBlock;
   short * magicNumberTest = (short*)memoryBlock;
  short magicNumber = 3;
  if(*magicNumberTest == magicNumber){
     fprintf(stderr,"sorry you are trying to free empty memory in %s at line %d\n", File,lineNumber); 
     return;
 }//end of if statement
  
  if (((void*)memoryBlock<=memoryToFree)&&(memoryToFree<=(void*)memoryBlock+4096)){
    Metadata * current = head;
    Metadata *freeingMemory;
    freeingMemory = memoryToFree;
    freeingMemory = freeingMemory-1;

    while (current !=NULL){
       if (current == freeingMemory){

          if (freeingMemory->free== 't'){
            fprintf(stderr,"sorry you are trying to free already freed memory in %s at line %d\n", File,lineNumber); 
            return;
          }

          freeingMemory->free = 't';
          //printf("breaks right before combine space\n");
          combineFreeSpace();
          //printf("breaks right before after space\n");
          break;
      }
     current = current->next;
   }//end of while loop

   if (current == NULL){ 
    fprintf(stderr, "Error you are trying to free memory that was not dynamically allocated in %s at line %d\n", File, lineNumber);
   }

  }
  else
    fprintf(stderr, " free memory that was not dynamically allocated in %s at line %d\n", File, lineNumber);

}

void combineFreeSpace(){
  Metadata * head = (void *)memoryBlock;
  Metadata* nextNode;
  Metadata* currentNode;
  currentNode=head;
  nextNode = head->next;
  while ( nextNode!=NULL){
    if(currentNode ->free =='t' && nextNode->free =='t'){
     while (nextNode ->free =='t'&& nextNode !=NULL){
        currentNode ->blockSize = currentNode ->blockSize + nextNode->blockSize + sizeof(Metadata);
        currentNode -> next = nextNode->next;
        nextNode = nextNode->next;
        if (nextNode == NULL)
        return;
     }//end of inner while

   }
  nextNode = nextNode->next;
  currentNode =currentNode->next;
 }//end of while loop

}

