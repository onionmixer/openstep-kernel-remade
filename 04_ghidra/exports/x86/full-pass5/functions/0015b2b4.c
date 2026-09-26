/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015b2b4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _swapinStack(uint param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  piVar6 = (int *)(param_1 & ~_page_mask);
  _DAT_001f63bc = _DAT_001f63bc + -1;
  _vm_map_pageable(_kernel_map,piVar6,(int)piVar6 + _page_mask + DAT_001e5ba0 & ~_page_mask,0);
  _lock_write(&_stack_queue_lock);
  *(undefined4 *)(param_1 - 4) = 2;
  if (*piVar6 == -0x1120532) {
    *piVar6 = 0;
    iVar2 = DAT_001e5ba4;
    iVar1 = DAT_001e5ba0;
    _DAT_001f63c0 = _DAT_001f63c0 + -1;
    iVar5 = 0;
    if (0 < DAT_001e5ba4) {
      piVar4 = piVar6 + 1;
      do {
        if (piVar4[1] == 0) {
          piVar4[1] = piVar4[1];
          piVar3 = piVar6;
          if ((int **)DAT_001e5b9c != &DAT_001e5b98) {
            *DAT_001e5b9c = (int)piVar6;
            piVar3 = DAT_001e5b98;
          }
          DAT_001e5b98 = piVar3;
          *piVar4 = (int)DAT_001e5b9c;
          *piVar6 = (int)&DAT_001e5b98;
          DAT_001ded68 = DAT_001ded68 + 1;
          _DAT_001f63b8 = _DAT_001f63b8 + 1;
          DAT_001e5b9c = piVar6;
        }
        piVar4 = (int *)((int)piVar4 + iVar1);
        piVar6 = (int *)((int)piVar6 + iVar1);
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar2);
    }
  }
  _lock_done(&_stack_queue_lock);
  return;
}

