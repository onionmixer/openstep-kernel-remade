
void _sendmsg(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined auStack_9c [128];
  undefined auStack_1c [8];
  undefined *puStack_14;
  uint uStack_10;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  uVar2 = _copyinmsg(puVar1[1],auStack_1c,0x18);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    if (uStack_10 < 0x10) {
      uVar2 = _copyinmsg(puStack_14,auStack_9c,uStack_10 << 3);
      *(undefined *)(dword_40B57D4 + 100) = uVar2;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        puStack_14 = auStack_9c;
        _sendit(*puVar1,auStack_1c,puVar1[2]);
      }
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x28;
    }
  }
  return;
}

