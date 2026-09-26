
int _getf(uint param_1)

{
  int iVar1;
  
  if ((param_1 < *(uint *)(_active_u + 0x152)) &&
     (iVar1 = *(int *)(*(int *)(_active_u + 0x146) + param_1 * 4), iVar1 != 0)) {
    if (iVar1 == -0x10000) {
      *(undefined *)(dword_40B57D4 + 100) = 9;
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 9;
    iVar1 = 0;
  }
  return iVar1;
}

