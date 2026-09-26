
void _reboot(void)

{
  int iVar1;
  undefined uVar2;
  undefined auStack_44 [64];
  
  auStack_44[0] = 0;
  iVar1 = _suser();
  if (iVar1 != 0) {
    if ((*(byte *)(*(int *)(dword_40B57D4 + 0x24) + 1) & 0x10) != 0) {
      uVar2 = _copyinstr(*(undefined4 *)(*(int *)(dword_40B57D4 + 0x24) + 4),auStack_44,0x40,0);
      *(undefined *)(dword_40B57D4 + 100) = uVar2;
    }
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      _boot(1,**(undefined4 **)(dword_40B57D4 + 0x24),auStack_44);
    }
  }
  return;
}
