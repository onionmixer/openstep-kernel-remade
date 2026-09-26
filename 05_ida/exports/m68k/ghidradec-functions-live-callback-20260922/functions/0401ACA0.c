
void _truncate(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined auStack_3e [20];
  undefined4 uStack_2a;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  if ((int)puVar1[1] < 0) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  else {
    _vattr_null(auStack_3e);
    uStack_2a = puVar1[1];
    uVar2 = _namesetattr(*puVar1,1,auStack_3e);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
  }
  return;
}

