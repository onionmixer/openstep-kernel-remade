/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017358c */

void _vm_fault_wire(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_2 + 0xc);
  _pmap_pageable(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_2 + 8),uVar1,0);
  for (uVar3 = *(uint *)(param_2 + 8); uVar3 < uVar1; uVar3 = uVar3 + _page_size) {
    iVar2 = _vm_fault_wire_fast(param_1,uVar3,param_2);
    if (iVar2 != 0) {
      _vm_fault(param_1,uVar3,0,1,0);
    }
  }
  return;
}

