
void _recvfrom(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  if (puVar1[5] != 0) {
    uVar2 = _copyinmsg(puVar1[5],&uStack_20,4);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
  }
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    uStack_1c = puVar1[4];
    uStack_18 = uStack_20;
    puStack_14 = &uStack_28;
    uStack_10 = 1;
    uStack_28 = puVar1[1];
    uStack_24 = puVar1[2];
    uStack_c = 0;
    uStack_8 = 0;
    _recvit(*puVar1,&uStack_1c,puVar1[3],puVar1[5],0);
  }
  return;
}

