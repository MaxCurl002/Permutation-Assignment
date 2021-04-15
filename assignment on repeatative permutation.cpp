#include <bits/stdc++.h>
using namespace std;

// global variable
vector<vector<char>> output;
int size = 0;

//functions
void permute(char arr[], int cas, char str[], int i2, int depth);
void print_output();
void remove_repeatations();

int main(){
  char input[26];
  int depth;
  printf("Input String Size: ");
  scanf("%d%d",&size,&depth);
  printf("String: ");
  for(int i=0; i<size; i++) scanf(" %c",&input[i]);

  char str[32];
  permute(input, size, str, 0, depth);
  //print_output();
  remove_repeatations();
  printf("Without Repeatations: \n");
  print_output();
  return 0;
}

//ca = current array, cas = current array size
//i2=index 2 = index fir str[]
void permute(char arr[], int cas, char str[], int i2, int depth) {
  if(cas==0 || depth==0){
    vector<char>str_vector;
    for (int i = 0; i < size; i++) str_vector.push_back(str[i]);
    output.push_back(str_vector);
    return;
  }
  
  for(int i=0; i<cas; i++){
    char c = arr[i]; 
    char ua[32],j=0;//ua=update array
    
    for(int i3=0; i3<cas; i3++){
      if(i3!=i){
	ua[j]=arr[i3];
	j++;
      }
    }

    str[i2]=c;
    permute(ua, cas-1, str, i2+1, depth-1);
  }
}

void print_output() {
  for(int i=0; i<output.size(); i++){
    for(int j=0; j<output[i].size(); j++) printf("%c",output[i][j]);
    printf("\n");
  }
}

bool isEqual(vector<char> a, vector<char> b) {
  if(a.size()!=b.size()) return false;
  for(int i=0; i<a.size(); i++){
    if(a[i]!=b[i]) return false;
  }
  return true;
}

void remove_repeatations() {
  vector<char>cnull;
  for(int i=0; i<output.size(); i++){
    for(int j=i+1; j<output.size(); j++){
      if(isEqual(output[i],output[j])){
	output[j]=cnull;
      }
    }
  }

  vector<vector<char>>temp;
  for(int i=0; i<output.size(); i++){
    if(output[i].size()!=0) temp.push_back(output[i]);
  }

  output.clear();
  for(int i=0; i<temp.size(); i++) output.push_back(temp[i]);
}
