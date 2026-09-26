
/* WARNING: Removing unreachable block (ram,0xf005eef4) */
/* WARNING: Removing unreachable block (ram,0xf005efb4) */
/* WARNING: Removing unreachable block (ram,0xf005ef90) */
/* WARNING: Removing unreachable block (ram,0xf005ef50) */
/* WARNING: Removing unreachable block (ram,0xf005ef14) */
/* WARNING: Removing unreachable block (ram,0xf005eecc) */

undefined8 _host_ipc_hash_info(int param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
  uint uVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  uVar4 = 0;
  if (param_1 == 0) {
    uVar5 = 0x16;
    goto locret_F005EFCC;
  }
  uVar3 = *param_2;
  uVar6 = *param_3;
  while( true ) {
    uVar1 = uVar3;
    _ipc_hash_info(uVar3,uVar6);
    if (uVar1 <= uVar6) break;
    if (uVar3 != *param_2) {
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar4);
    }
    uVar4 = uVar1 * 4 + _page_mask & ~_page_mask;
    iVar2 = _ipc_kernel_map;
    _kmem_alloc_pageable(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar4);
    uVar3 = *(uint *)((int)register0x00000038 + -0xc);
    if (iVar2 != 0) {
      uVar5 = 6;
      goto locret_F005EFCC;
    }
    uVar6 = uVar4 >> 2;
  }
  if (uVar3 == *param_2) {
loc_F005EFC4:
    *param_3 = uVar1;
  }
  else {
    if (uVar1 != 0) {
      uVar3 = uVar1 * 4 + _page_mask & ~_page_mask;
      if (uVar3 != uVar4) {
        _kmem_free(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc) + uVar3,uVar4 - uVar3);
      }
      _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),_ipc_soft_map,uVar3,1
               ,(undefined *)((int)register0x00000038 + -0x10));
      *param_2 = *(uint *)((int)register0x00000038 + -0x10);
      goto loc_F005EFC4;
    }
    _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar4);
    *param_3 = 0;
  }
  uVar5 = 0;
locret_F005EFCC:
  return CONCAT44(param_2,uVar5);
}

