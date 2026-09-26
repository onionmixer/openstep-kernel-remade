
int _skpc(char param_1,int param_2,char *param_3)

{
  char *pcVar1;
  
  pcVar1 = param_3 + param_2;
  for (; (param_3 < pcVar1 && (param_1 == *param_3)); param_3 = param_3 + 1) {
  }
  return (int)pcVar1 - (int)param_3;
}

