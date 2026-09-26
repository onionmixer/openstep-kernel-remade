
undefined4 _xdrmbuf_putbytes(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  while( true ) {
    iVar1 = *(int *)(param_1 + 0x14) - param_3;
    *(int *)(param_1 + 0x14) = iVar1;
    if (-1 < iVar1) {
      _bcopy(param_2,*(undefined4 *)(param_1 + 0xc),param_3);
      *(int *)(param_1 + 0xc) = param_3 + *(int *)(param_1 + 0xc);
      return 1;
    }
    iVar1 = param_3 + *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1;
    if (0 < iVar1) {
      _bcopy(param_2,*(undefined4 *)(param_1 + 0xc),iVar1);
      param_2 = *(int *)(param_1 + 0x14) + param_2;
      param_3 = param_3 - *(int *)(param_1 + 0x14);
    }
    if (*(int **)(param_1 + 0x10) == (int *)0x0) break;
    iVar1 = **(int **)(param_1 + 0x10);
    *(int *)(param_1 + 0x10) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
    *(int *)(param_1 + 0xc) = *(int *)(iVar1 + 4) + iVar1;
    *(int *)(param_1 + 0x14) = (int)*(sword *)(iVar1 + 8);
  }
  return 0;
}

