#include <bits/stdc++.h>
using namespace std;

// global variable
vector<vector<char>> output;
int size = 0;

//functions
void permute(char arr[], int cas, char str[], int i2);
void print_output();

int main(){
  char input[26];
  printf("Input String Size: ");
  scanf("%d",&size);
  printf("String: ");
  for(int i=0; i<size; i++) scanf(" %c",&input[i]);

  char str[32];
  permute(input, size, str, 0);
  print_output();
    
  return 0;
}

//ca = current array, cas = current array size
//i2=index 2 = index fir str[]
void permute(char arr[], int cas, char str[], int i2) {
  if(cas==0){
    vector<char>str_vector;
    for (int i = 0; i < size; i++) str_vector.push_back(str[i]);
    output.push_back(str_vector);
    return;
  }
  
  for(int i=0; i<cas; i++){
    char c = arr[i]; 
    char ua[32],j=0;//ua=update array
    
    for(int i=0; i<cas; i++){
      if(arr[i]!=c){
	ua[j]=arr[i];
	j++;
      }
    }

    str[i2]=c;
    permute(ua, cas-1, str, i2+1);
  }
}

void print_output() {
  for(int i=0; i<output.size(); i++){
    for(int j=0; j<output[i].size(); j++) printf("%c",output[i][j]);
    printf("\n");
  }
}
