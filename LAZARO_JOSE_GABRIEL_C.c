/****************************************
  Name: LAZARO, JOSE GABRIEL R.
  Language: C PROGRAMMING
  Paradigm: IMPERATIVE PROGRAMMING PARADIGM
*****************************************/

#include<stdio.h>
#define MAX_VALUE 999
#define ARR_SIZE 50

//GLOBAL VAR FOR ARRAY
int arr[ARR_SIZE];

//FUNCTION PROTOTYPES
int merge(int arr[],int l,int m,int h);
int mergeSort(int arr[], int low, int high, int size);
void printIteration(int arr[], int size);
int getElems();

int main(){
  int nElements = 0, i = 0;

  nElements = getElems();

  for(i = 0; i < nElements; i++){
    scanf("%d",&arr[i]);
  }

  printf("\nSORTING...\n");
  mergeSort(arr, 0, nElements-1, nElements);  //CALL MERGE SORT
  
  printf("\nSORTED ARRAY\n");
  printIteration(arr, nElements); //PRINT SORTED ARRAY
  
  return 0;
}

int getElems(){
  int Elements = 0;
  printf("Input nuber of elements: ");  // GET THE NUMBER OF ELEMENTS IN THE ARRAY
  scanf("%d",&Elements);

  return Elements;
}

void printIteration(int arr[], int size){// PRINTS THE CURRENT ITERATION
  int i = 0;
  
  for(i = 0; i < size; i++)
    printf("%d ",arr[i]);
  printf("\n");

}

int merge(int arr[],int l,int m,int h){
  int LArr[ARR_SIZE/2], RArr[ARR_SIZE/2];  
  int LArr_size = m-l+1, RArr_size = h-m, //ARRAY SIZE OF L & R
      i = 0, j = 0, a = 0; //INIT VALUES

  for(i = 0; i < LArr_size; i++){ //PUSH VALUES 0 UNTIL FIRST HALF
    LArr[i] = arr[l+i];
  }

  for(j = 0; j < RArr_size; j++){ //PUSH VALUES SECOND HALF UNTIL END
    RArr[j] = arr[m+j+1];
  }

  LArr[i] = MAX_VALUE;  //INIT END OF ARRAY
  RArr[j] = MAX_VALUE;

  LArr_size = 0; //INIT SIZE OF COUNTER
  RArr_size = 0;
  for(a = l; a <= h; a++){  //COMBINE L&R 
    if(LArr[LArr_size] <= RArr[RArr_size])
      arr[a] = LArr[LArr_size++];
    else
      arr[a] = RArr[RArr_size++];
  }
  
  return 0;
}
int mergeSort(int arr[],int low,int high,int size) {
  int middle;
  
  if(low < high){
    middle = ((low + high)/2);//     -> GET MIDDLE OF SIZE
   // DIVIDE AND CONQUER STEP OF MERGE SORT
    mergeSort(arr, low, middle, size); //LArr -> HALF
    mergeSort(arr, middle+1, high, size);//RArr -> HALF
    
   // COMBINE STEP OF MERGE SORT
    merge(arr, low, middle, high);
    printIteration(arr, size); //PRINT EACH ITERATION OF MERGING
  }  
  return 0;
}
