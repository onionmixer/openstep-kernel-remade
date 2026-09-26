
void _vm_fault_wire(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = *(uint *)(param_2 + 0xc);
  _pmap_pageable(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_2 + 8),uVar1,0);
  for (uVar2 = *(uint *)(param_2 + 8); uVar2 < uVar1; uVar2 = _page_size + uVar2) {
    iVar3 = _vm_fault_wire_fast(param_1,uVar2,param_2);
    if (iVar3 != 0) {
      _vm_fault(param_1,uVar2,0,1,0);
    }
  }
  return;
}

