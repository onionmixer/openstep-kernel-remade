
void sub_4088588(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(sword *)(*(int *)(param_1 + 0x10) + 4) * 0x166;
  _bzero(_st_std + iVar2,0x166);
  *(int *)(_st_std + iVar2) = param_1;
  *(uint *)(_st_std + iVar2 + 0x10) = iVar2 + 0x40c6856U & 0xfffffff0;
  *(uint *)(_st_std + iVar2 + 4) = iVar2 + 0x40c6805U & 0xfffffff0;
  *(uint *)(_st_std + iVar2 + 8) = iVar2 + 0x40c687fU & 0xfffffff0;
  *(uint *)(_st_std + iVar2 + 0xc) = iVar2 + 0x40c6896U & 0xfffffff0;
  *(undefined2 *)(_st_std + iVar2 + 0x66) = 0;
  iVar1 = iVar2 + 0x40c67ee;
  *(int *)(_st_std + iVar2 + 0x82) = iVar1;
  *(int *)iVar1 = iVar1;
  _st_std[iVar2 + 0x7d] = 0;
  return;
}

