
/* WARNING: Removing unreachable block (ram,0xf005f02c) */
/* WARNING: Removing unreachable block (ram,0xf005f0ec) */
/* WARNING: Removing unreachable block (ram,0xf005f0c8) */
/* WARNING: Removing unreachable block (ram,0xf005f088) */
/* WARNING: Removing unreachable block (ram,0xf005f04c) */
/* WARNING: Removing unreachable block (ram,0xf005f004) */

undefined8 _host_ipc_marequest_info(int param_1,uint param_2,int *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
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
    goto locret_F005F104;
  }
  iVar3 = *param_3;
  uVar6 = *param_4;
  while( true ) {
    uVar1 = param_2;
    _ipc_marequest_info(param_2,iVar3,uVar6);
    if (uVar1 <= uVar6) break;
    if (iVar3 != *param_3) {
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar4);
    }
    uVar4 = uVar1 * 4 + _page_mask & ~_page_mask;
    iVar2 = _ipc_kernel_map;
    _kmem_alloc_pageable(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar4);
    iVar3 = *(int *)((int)register0x00000038 + -0xc);
    if (iVar2 != 0) {
      uVar5 = 6;
      goto locret_F005F104;
    }
    uVar6 = uVar4 >> 2;
  }
  if (iVar3 == *param_3) {
loc_F005F0FC:
    *param_4 = uVar1;
  }
  else {
    if (uVar1 != 0) {
      uVar6 = uVar1 * 4 + _page_mask & ~_page_mask;
      if (uVar6 != uVar4) {
        _kmem_free(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc) + uVar6,uVar4 - uVar6);
      }
      _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),_ipc_soft_map,uVar6,1
               ,(undefined *)((int)register0x00000038 + -0x10));
      *param_3 = *(int *)((int)register0x00000038 + -0x10);
      goto loc_F005F0FC;
    }
    _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar4);
    *param_4 = 0;
  }
  uVar5 = 0;
locret_F005F104:
  return CONCAT44(param_2,uVar5);
}

