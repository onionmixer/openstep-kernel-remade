
void _readlink(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined4 uStack_26;
  undefined4 uStack_22;
  int iStack_1e;
  undefined4 *puStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar2 = _lookupname(*puVar1,0,0,0,&iStack_1e);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    if (*(int *)(iStack_1e + 0x28) == 5) {
      uStack_26 = puVar1[1];
      uStack_22 = puVar1[2];
      puStack_1a = &uStack_26;
      uStack_16 = 1;
      uStack_12 = 0;
      uStack_e = 0;
      iStack_8 = puVar1[2];
      uVar2 = (**(code **)(*(int *)(iStack_1e + 0x1c) + 0x44))
                        (iStack_1e,&puStack_1a,*(undefined4 *)(_active_u + 0x1a));
      *(undefined *)(dword_40B57D4 + 100) = uVar2;
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
    _vn_rele(iStack_1e);
    *(int *)(dword_40B57D4 + 0x5c) = puVar1[2] - iStack_8;
  }
  return;
}
