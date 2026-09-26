
undefined sub_406197E(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined uVar4;
  
  iVar3 = *(int *)(param_1 + 0x24);
  if (((*(byte *)(param_2 + 0x1e) & 4) == 0) ||
     (iVar2 = _pmap_is_modified(*(undefined4 *)(param_2 + 0x22)), iVar2 != 0)) {
    if ((char)*(byte *)(param_2 + 0x20) < '\0') {
      *(byte *)(param_2 + 0x20) = *(byte *)(param_2 + 0x20) | 0x40;
      _assert_wait(param_2,0);
      _thread_block();
      uVar4 = 2;
    }
    else {
      *(sword *)(param_1 + 0x40) = *(sword *)(param_1 + 0x40) + 1;
      *(byte *)(param_2 + 0x20) = *(byte *)(param_2 + 0x20) | 0x80;
      if (*(char *)(param_2 + 0x1e) < '\0') {
        _vm_page_activate(param_2);
      }
      _vm_page_deactivate(param_2);
      _pmap_remove_all(*(undefined4 *)(param_2 + 0x22));
      dword_40C2400 = dword_40C2400 + 1;
      if (iVar3 == 0) {
        *(sword *)(param_1 + 0x40) = *(sword *)(param_1 + 0x40) + -1;
        uVar4 = 1;
      }
      else {
        iVar3 = _vm_pager_put(iVar3,param_2);
        uVar4 = iVar3 != 0;
        bVar1 = *(byte *)(param_2 + 0x20);
        *(byte *)(param_2 + 0x20) = bVar1 & 0x7f;
        *(byte *)(param_2 + 0x20) = bVar1 & 0x7f;
        if ((bVar1 & 0x40) != 0) {
          *(byte *)(param_2 + 0x20) = bVar1 & 0x3f;
          _thread_wakeup_prim(param_2,0,0);
        }
        *(sword *)(param_1 + 0x40) = *(sword *)(param_1 + 0x40) + -1;
      }
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}
