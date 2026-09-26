
void _socketpair(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar4;
  int iVar3;
  int iStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _useracc(puVar1[3],8,0);
  if (iVar2 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 0xe;
    return;
  }
  uVar4 = _socreate(*puVar1,&uStack_8,puVar1[1],puVar1[2]);
  *(undefined *)(dword_40B57D4 + 100) = uVar4;
  if (*(char *)(dword_40B57D4 + 100) != '\0') {
    return;
  }
  uVar4 = _socreate(*puVar1,&uStack_c,puVar1[1],puVar1[2]);
  *(undefined *)(dword_40B57D4 + 100) = uVar4;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    iVar2 = _falloc();
    if (iVar2 != 0) {
      iStack_14 = *(int *)(dword_40B57D4 + 0x5c);
      *(undefined4 *)(iVar2 + 8) = 3;
      *(undefined2 *)(iVar2 + 0xc) = 2;
      *(undefined **)(iVar2 + 0x12) = _socketops;
      *(undefined4 *)(iVar2 + 0x16) = uStack_8;
      *(int *)(*(int *)(_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x5c) * 4) = iVar2;
      iVar3 = _falloc();
      if (iVar3 != 0) {
        *(undefined4 *)(iVar3 + 8) = 3;
        *(undefined2 *)(iVar3 + 0xc) = 2;
        *(undefined **)(iVar3 + 0x12) = _socketops;
        *(undefined4 *)(iVar3 + 0x16) = uStack_c;
        *(int *)(*(int *)(_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x5c) * 4) = iVar3;
        iStack_10 = *(int *)(dword_40B57D4 + 0x5c);
        uVar4 = _soconnect2(uStack_8,uStack_c);
        *(undefined *)(dword_40B57D4 + 100) = uVar4;
        if (*(char *)(dword_40B57D4 + 100) == '\0') {
          if (puVar1[1] != 2) {
loc_4014F4E:
            *(undefined4 *)(dword_40B57D4 + 0x5c) = 0;
            _copyoutmsg(&iStack_14,puVar1[3],8);
            return;
          }
          uVar4 = _soconnect2(uStack_c,uStack_8);
          *(undefined *)(dword_40B57D4 + 100) = uVar4;
          if (*(char *)(dword_40B57D4 + 100) == '\0') goto loc_4014F4E;
        }
        *(undefined2 *)(iVar3 + 0xe) = 0;
        *(undefined4 *)(*(int *)(_active_u + 0x146) + iStack_10 * 4) = 0;
      }
      *(undefined2 *)(iVar2 + 0xe) = 0;
      *(undefined4 *)(*(int *)(_active_u + 0x146) + iStack_14 * 4) = 0;
    }
    _soclose(uStack_c);
  }
  _soclose(uStack_8);
  return;
}

