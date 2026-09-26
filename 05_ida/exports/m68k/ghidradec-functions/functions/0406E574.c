
int _ts_greater(uint *param_1,uint *param_2)

{
  bool bVar1;
  
  bVar1 = param_2[1] < param_1[1];
  if (param_2[1] == param_1[1]) {
    bVar1 = *param_2 < *param_1;
  }
  return -(int)(char)-bVar1;
}
