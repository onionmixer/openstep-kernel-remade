
undefined4 _soqremque(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar3 = iVar1;
  while( true ) {
    if (param_2 == 0) {
      iVar2 = *(int *)(iVar3 + 0x14);
    }
    else {
      iVar2 = *(int *)(iVar3 + 0x1a);
    }
    if (param_1 == iVar2) break;
    iVar3 = iVar2;
    if (iVar1 == iVar2) {
      return 0;
    }
  }
  if (param_2 == 0) {
    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar2 + 0x14);
    *(sword *)(iVar1 + 0x18) = *(sword *)(iVar1 + 0x18) + -1;
  }
  else {
    *(undefined4 *)(iVar3 + 0x1a) = *(undefined4 *)(iVar2 + 0x1a);
    *(sword *)(iVar1 + 0x1e) = *(sword *)(iVar1 + 0x1e) + -1;
  }
  *(undefined4 *)(iVar2 + 0x1a) = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  return 1;
}
