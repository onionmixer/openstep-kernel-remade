
undefined4 _canSwap(uint param_1)

{
  int iVar1;
  
  param_1 = param_1 & ~_page_mask;
  iVar1 = 0;
  if (0 < dword_40B371E) {
    do {
      if (*(int *)(param_1 + 8) == 2) {
        return 0;
      }
      param_1 = dword_40B371A + param_1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < dword_40B371E);
  }
  return 1;
}
