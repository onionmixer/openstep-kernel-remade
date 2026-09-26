
int _scanc(int param_1,byte *param_2,int param_3,byte param_4)

{
  byte bVar1;
  byte *pbVar2;
  
  pbVar2 = param_2 + param_1;
  if (param_2 < pbVar2) {
    bVar1 = *(byte *)(param_3 + (uint)*param_2);
    while (((param_4 & bVar1) == 0 && (param_2 = param_2 + 1, param_2 < pbVar2))) {
      bVar1 = *(byte *)(param_3 + (uint)*param_2);
    }
  }
  return (int)pbVar2 - (int)param_2;
}
