
void _vm_fault_unwire(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar1 = *(uint *)(param_2 + 0xc);
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  uVar3 = *(uint *)(param_2 + 8);
  while( true ) {
    if (uVar1 <= uVar3) {
      _pmap_pageable(uVar2,*(undefined4 *)(param_2 + 8),uVar1,1);
      return;
    }
    iVar4 = _pmap_extract(uVar2,uVar3);
    if (iVar4 == 0) break;
    _pmap_change_wiring(uVar2,uVar3,0);
    uVar5 = _vm_phys_to_vm_page(iVar4);
    _vm_page_unwire(uVar5);
    uVar3 = _page_size + uVar3;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aUnwirePageNotI);
}
