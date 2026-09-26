
undefined4 _map_addr(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  
  if (_slot_id <= param_1) {
    if (_dma_chip == 0x139) {
      if (_machine_type == '\x03') {
        uVar1 = _slot_id + 0x6000000;
      }
      else {
        uVar1 = _slot_id + 0x8000000;
      }
    }
    else {
      uVar1 = _slot_id + 0xc000000;
    }
    if (param_1 < uVar1) {
      return 0;
    }
  }
  iVar2 = _kmem_alloc_pageable(_kernel_map,&uStack_8,param_2);
  if (iVar2 == 0) {
    uVar3 = _ioaccess(param_1,uStack_8,param_2);
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aMapAddrNoMemor);
}

