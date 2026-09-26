/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00173c0c */

bool _kmem_realloc(undefined4 param_1,uint param_2,int param_3,int *param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  int local_10;
  int local_c;
  int local_8;
  
  uVar5 = ~_page_mask;
  iVar3 = (param_2 + param_3 + _page_mask & uVar5) - (uVar5 & param_2);
  uVar6 = uVar5 & _page_mask + param_5;
  iVar4 = _vm_map_find(param_1,0,0,&local_8,uVar6,1);
  bVar7 = iVar4 != 0;
  if (!bVar7) {
    _vm_map_lookup_entry(param_1,local_8,&local_c);
    iVar4 = _vm_map_lookup_entry(param_1,uVar5 & param_2,&local_10);
    if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_kmem_realloc_001e09fc);
    }
    iVar4 = *(int *)(local_10 + 0x10);
    _vm_object_reference(iVar4);
    piVar1 = (int *)(iVar4 + 0x10);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    if (*(int *)(iVar4 + 0x14) != iVar3) {
                    /* WARNING: Subroutine does not return */
      _panic(s_kmem_realloc_001e0a09);
    }
    *(uint *)(iVar4 + 0x14) = uVar6;
    LOCK();
    *(undefined4 *)(iVar4 + 0x10) = 0;
    UNLOCK();
    *(int *)(local_c + 0x10) = iVar4;
    *(undefined4 *)(local_c + 0x14) = 0;
    _lock_done(param_1);
    FUN_00173ebc(iVar4,iVar3,uVar6,1);
    _vm_map_pageable(param_1,local_8,uVar6 + local_8,0);
    *param_4 = local_8;
    bVar7 = false;
  }
  return bVar7;
}

