
void _chroot(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _suser();
  if (iVar2 != 0) {
    uVar3 = _chdirec(*puVar1,&uStack_8);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      if (*(int *)(_active_u + 0x15a) != 0) {
        _vn_rele(*(int *)(_active_u + 0x15a));
      }
      *(undefined4 *)(_active_u + 0x15a) = uStack_8;
    }
  }
  return;
}
