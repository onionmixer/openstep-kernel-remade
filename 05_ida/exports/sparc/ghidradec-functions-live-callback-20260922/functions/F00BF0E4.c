
/* WARNING: Removing unreachable block (ram,0xf00bf17c) */
/* WARNING: Removing unreachable block (ram,0xf00bf14c) */
/* WARNING: Removing unreachable block (ram,0xf00bf168) */
/* WARNING: Removing unreachable block (ram,0xf00bf184) */
/* WARNING: Removing unreachable block (ram,0xf00bf128) */

undefined8
_destroyEventShmem(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined4 unaff_l0;
  uint uVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  uint uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (param_2 == 0) {
    iVar2 = 4;
  }
  else {
    uVar3 = 0;
    uVar1 = param_3 + _page_mask & ~_page_mask;
    if (uVar1 != 0) {
      do {
        _pmap_remove(*(undefined4 *)(param_2 + 0x24),param_4 + uVar3,param_4 + uVar3 + _page_size);
        uVar3 = uVar3 + _page_size;
      } while (uVar3 < uVar1);
    }
    iVar2 = param_2;
    _vm_map_remove(param_2,param_4,param_4 + uVar1);
    if (iVar2 != 0) {
      _printf(aDestroyeventsh,iVar2);
    }
    _kmem_free(_kernel_map,param_5,uVar1);
    _vm_map_deallocate(param_2);
  }
  return CONCAT44(param_2,iVar2);
}

