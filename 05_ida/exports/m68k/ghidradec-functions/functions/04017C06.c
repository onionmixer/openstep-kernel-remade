
undefined4 _incore(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = param_2;
  if (param_2 < 0) {
    iVar2 = param_2 + 7;
  }
  iVar2 = (param_1 + (iVar2 >> 3) & 0xfU) * 0xc;
  puVar1 = *(undefined **)(_bufhash + iVar2 + 4);
  while( true ) {
    if (_bufhash + iVar2 == puVar1) {
      return 0;
    }
    if (((param_2 == *(int *)(puVar1 + 0x24)) && (param_1 == *(int *)(puVar1 + 0x40))) &&
       ((puVar1[1] & 1) == 0)) break;
    puVar1 = *(undefined **)(puVar1 + 4);
  }
  return 1;
}
