
void _ustat(void)

{
  int iVar1;
  undefined uVar2;
  int iStack_5c;
  int iStack_58;
  undefined4 uStack_54;
  undefined auStack_44 [4];
  int iStack_40;
  int iStack_34;
  undefined4 uStack_2c;
  
  iVar1 = *(int *)(dword_40B57D4 + 0x24);
  uVar2 = _vafsidtovfs(*(undefined2 *)(iVar1 + 2),&iStack_5c);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    uVar2 = (**(code **)(*(int *)(iStack_5c + 4) + 0xc))(iStack_5c,auStack_44);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      _bzero(&iStack_58,0x14);
      iStack_58 = iStack_40 * iStack_34 + 0x1ff;
      if (iStack_58 < 0) {
        iStack_58 = iStack_40 * iStack_34 + 0x3fe;
      }
      iStack_58 = iStack_58 >> 9;
      uStack_54 = uStack_2c;
      uVar2 = _copyoutmsg(&iStack_58,*(undefined4 *)(iVar1 + 4),0x14);
      *(undefined *)(dword_40B57D4 + 100) = uVar2;
    }
  }
  return;
}

