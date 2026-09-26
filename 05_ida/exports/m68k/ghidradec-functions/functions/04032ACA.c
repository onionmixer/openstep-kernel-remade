
void sub_4032ACA(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  if ((*(byte *)(iVar1 + 0x75) & 1) != 0) {
    do {
      *(byte *)(iVar1 + 0x75) = *(byte *)(iVar1 + 0x75) | 2;
      _sleep((byte *)(iVar1 + 0x75),10);
    } while ((*(byte *)(iVar1 + 0x75) & 1) != 0);
  }
  *(byte *)(iVar1 + 0x75) = *(byte *)(iVar1 + 0x75) | 1;
  return;
}
