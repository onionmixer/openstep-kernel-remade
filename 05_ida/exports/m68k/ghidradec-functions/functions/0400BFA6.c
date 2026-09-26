
void _readv(void)

{
  int iVar1;
  undefined uVar2;
  undefined auStack_9a [128];
  undefined *puStack_1a;
  undefined4 uStack_16;
  
  iVar1 = *(int *)(dword_40B57D4 + 0x24);
  if (*(uint *)(iVar1 + 8) < 0x11) {
    puStack_1a = auStack_9a;
    uStack_16 = *(undefined4 *)(iVar1 + 8);
    uVar2 = _copyinmsg(*(undefined4 *)(iVar1 + 4),puStack_1a,*(int *)(iVar1 + 8) << 3);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      _rwuio(&puStack_1a,0);
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
