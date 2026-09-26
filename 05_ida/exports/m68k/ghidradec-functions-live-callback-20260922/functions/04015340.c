
void _recvmsg(void)

{
  undefined4 *puVar1;
  undefined uVar3;
  int iVar2;
  undefined auStack_9c [128];
  undefined auStack_1c [8];
  undefined *puStack_14;
  uint uStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar3 = _copyinmsg(puVar1[1],auStack_1c,0x18);
  *(undefined *)(dword_40B57D4 + 100) = uVar3;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    if (uStack_10 < 0x10) {
      uVar3 = _copyinmsg(puStack_14,auStack_9c,uStack_10 << 3);
      *(undefined *)(dword_40B57D4 + 100) = uVar3;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        puStack_14 = auStack_9c;
        if ((iStack_c != 0) && (iVar2 = _useracc(iStack_c,uStack_8,0), iVar2 == 0)) {
          *(undefined *)(dword_40B57D4 + 100) = 0xe;
          return;
        }
        _recvit(*puVar1,auStack_1c,puVar1[2],puVar1[1] + 4,puVar1[1] + 0x14);
      }
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x28;
    }
  }
  return;
}

