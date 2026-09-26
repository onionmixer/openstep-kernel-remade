
int _ufavail(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    if ((iVar2 < *(int *)(_active_u + 0x152)) &&
       (*(int *)(*(int *)(_active_u + 0x146) + iVar2 * 4) == 0)) {
      iVar1 = iVar1 + 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x100);
  return iVar1;
}

