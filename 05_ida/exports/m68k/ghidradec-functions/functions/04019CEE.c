
void _chdir(void)

{
  undefined uVar1;
  undefined4 uStack_8;
  
  uVar1 = _chdirec(**(undefined4 **)(dword_40B57D4 + 0x24),&uStack_8);
  *(undefined *)(dword_40B57D4 + 100) = uVar1;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    _vn_rele(*(undefined4 *)(_active_u + 0x156));
    *(undefined4 *)(_active_u + 0x156) = uStack_8;
  }
  return;
}
