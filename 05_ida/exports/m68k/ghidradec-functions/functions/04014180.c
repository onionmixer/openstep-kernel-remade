
undefined4 _sbreserve(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 < 0xcccd) {
    *(sword *)(param_1 + 2) = (sword)param_2;
    iVar2 = param_2 * 2;
    if (0xffff < iVar2) {
      iVar2 = 0xffff;
    }
    *(sword *)(param_1 + 6) = (sword)iVar2;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
