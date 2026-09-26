
void _chown(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined auStack_3e [6];
  undefined2 uStack_38;
  undefined2 uStack_36;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  _vattr_null(auStack_3e);
  uStack_38 = *(undefined2 *)((int)puVar1 + 6);
  uStack_36 = *(undefined2 *)((int)puVar1 + 10);
  uVar2 = _namesetattr(*puVar1,0,auStack_3e);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  return;
}
