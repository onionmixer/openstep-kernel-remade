
void _mknod(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  word wStack_3a;
  undefined2 uStack_a;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  if ((puVar1[1] & 0xf000) == 0) {
    puVar1[1] = puVar1[1] | 0x8000;
  }
  if (((puVar1[1] & 0xf000) == 0x1000) || (iVar2 = _suser(), iVar2 != 0)) {
    _vattr_null(&uStack_3e);
    uStack_3e = *(undefined4 *)(_mftovt_tab + (*(uint *)((int)puVar1 + 6) >> 0x1d) * 4);
    wStack_3a = ~*(word *)(_active_u + 0x164) & *(word *)((int)puVar1 + 6) & 0xfff;
    switch(uStack_3e) {
    case :
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
      break;
    case :
      *(undefined *)(dword_40B57D4 + 100) = 0x15;
      break;
    case :
    case :
    case :
    case :
      uStack_a = *(undefined2 *)((int)puVar1 + 10);
    :
      uVar3 = _vn_create(*puVar1,0,&uStack_3e,1,0,&uStack_42);
      *(undefined *)(dword_40B57D4 + 100) = uVar3;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        _vn_rele(uStack_42);
      }
    }
  }
  return;
}
