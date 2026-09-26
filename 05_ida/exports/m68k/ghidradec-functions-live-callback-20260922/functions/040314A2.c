
undefined4 sub_40314A2(undefined4 *param_1)

{
  word wVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  
  if (_fifo_alloc < dword_40AF744) {
    _fifo_alloc = dword_40AF740 + _fifo_alloc;
    _kmem_alloc_wired(_kernel_map,&uStack_8,dword_40AF740);
    *(sword *)(param_1 + 0x22) = *(sword *)(param_1 + 0x22) + 1;
  }
  else {
    wVar1 = *(word *)((int)param_1 + 0x3e);
    *(word *)((int)param_1 + 0x3e) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)((int)param_1 + 0x3e) = wVar1 & 0xffee;
      _wakeup(param_1);
    }
    uVar3 = 0x1a;
    puVar2 = &_fifo_alloc;
    while( true ) {
      _sleep(puVar2,uVar3);
      if ((*(word *)((int)param_1 + 0x3e) & 1) == 0) break;
      *(word *)((int)param_1 + 0x3e) = *(word *)((int)param_1 + 0x3e) | 0x10;
      uVar3 = 10;
      puVar2 = param_1;
    }
    *(word *)((int)param_1 + 0x3e) = *(word *)((int)param_1 + 0x3e) | 1;
    uStack_8 = 0;
  }
  return uStack_8;
}

