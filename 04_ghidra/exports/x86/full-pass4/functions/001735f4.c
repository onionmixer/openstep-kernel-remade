/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001735f4 */

void _vm_fault_unwire(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar1 = *(uint *)(param_2 + 0xc);
  uVar2 = *(undefined4 *)(param_1 + 0x24);
  do {
  } while (_vm_page_queue_lock != 0);
  LOCK();
  _vm_page_queue_lock = 1;
  UNLOCK();
  uVar5 = *(uint *)(param_2 + 8);
  while( true ) {
    if (uVar1 <= uVar5) {
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      _pmap_pageable(uVar2,*(undefined4 *)(param_2 + 8),uVar1,1);
      return;
    }
    iVar3 = _pmap_extract(uVar2,uVar5);
    if (iVar3 == 0) break;
    _pmap_change_wiring(uVar2,uVar5,0);
    uVar4 = _vm_phys_to_vm_page(iVar3);
    _vm_page_unwire(uVar4);
    uVar5 = uVar5 + _page_size;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_unwire__page_not_in_pmap_001e09c1);
}

