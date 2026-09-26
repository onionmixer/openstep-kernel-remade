
void _chmod(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined auStack_3e [4];
  word wStack_3a;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  _vattr_null(auStack_3e);
  wStack_3a = *(word *)((int)puVar1 + 6) & 0xfff;
  uVar2 = _namesetattr(*puVar1,1,auStack_3e);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  return;
}

