
void _mkdir(void)

{
  undefined4 *puVar1;
  undefined uVar2;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  word wStack_3a;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  _vattr_null(&uStack_3e);
  uStack_3e = 2;
  wStack_3a = ~*(word *)(_active_u + 0x164) & *(word *)((int)puVar1 + 6) & 0x1ff;
  uVar2 = _vn_create(*puVar1,0,&uStack_3e,1,0,&uStack_42);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    _vn_rele(uStack_42);
  }
  return;
}

