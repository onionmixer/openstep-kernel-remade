
int sub_F00F2420(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (dword_F012F128 != 0) {
    iVar1 = 0;
    do {
      iVar1 = *(int *)(dword_F012F124 + (iVar1 + uVar2) * 8);
      uVar2 = uVar2 + 1;
      if (*(int *)(iVar1 + 0xc) != 3) {
        return iVar1;
      }
      iVar1 = uVar2 * 2;
    } while (uVar2 < dword_F012F128);
  }
  return 0;
}

