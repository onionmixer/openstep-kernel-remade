
void _getdirentries(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined4 uStack_26;
  undefined4 uStack_22;
  int iStack_1e;
  undefined4 *puStack_1a;
  undefined4 uStack_16;
  int iStack_12;
  undefined4 uStack_e;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar2 = _getvnodefp(*puVar1,&iStack_1e);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    if ((*(byte *)(iStack_1e + 0xb) & 1) == 0) {
      *(undefined *)(dword_40B57D4 + 100) = 9;
    }
    else {
      while( true ) {
        uStack_26 = puVar1[1];
        uStack_22 = puVar1[2];
        puStack_1a = &uStack_26;
        uStack_16 = 1;
        iStack_12 = *(int *)(iStack_1e + 0x1a);
        uStack_e = 0;
        iStack_8 = puVar1[2];
        if (iStack_12 < 0) break;
        uVar2 = (**(code **)(*(int *)(*(int *)(iStack_1e + 0x16) + 0x1c) + 0x3c))
                          (*(int *)(iStack_1e + 0x16),&puStack_1a,*(undefined4 *)(iStack_1e + 0x1e))
        ;
        *(undefined *)(dword_40B57D4 + 100) = uVar2;
        if (puVar1[2] != iStack_8) goto loc_401A408;
        *(undefined4 *)(iStack_1e + 0x1a) = 0xfffffc00;
      }
      uVar2 = _getfakedirentries(*(undefined4 *)(iStack_1e + 0x16),&puStack_1a,
                                 *(undefined4 *)(iStack_1e + 0x1e));
      *(undefined *)(dword_40B57D4 + 100) = uVar2;
loc_401A408:
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        uVar2 = _copyoutmsg(iStack_1e + 0x1a,puVar1[3],4);
        *(undefined *)(dword_40B57D4 + 100) = uVar2;
        *(int *)(dword_40B57D4 + 0x5c) = puVar1[2] - iStack_8;
        *(int *)(iStack_1e + 0x1a) = iStack_12;
      }
    }
  }
  return;
}
