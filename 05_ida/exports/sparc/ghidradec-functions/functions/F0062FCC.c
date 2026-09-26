
/* WARNING: Removing unreachable block (ram,0xf0063054) */
/* WARNING: Removing unreachable block (ram,0xf00630ac) */
/* WARNING: Removing unreachable block (ram,0xf006302c) */
/* WARNING: Removing unreachable block (ram,0xf0063090) */
/* WARNING: Removing unreachable block (ram,0xf00630e0) */
/* WARNING: Removing unreachable block (ram,0xf0063074) */
/* WARNING: Removing unreachable block (ram,0xf0062fe0) */

undefined8
_port_names(int param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,int *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 *puVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  _mach_port_names(param_1,param_2,param_3,param_4,param_5);
  if (param_1 == 0) {
    puVar5 = (undefined4 *)*param_5;
    uVar3 = *param_4;
    *(undefined4 *)((int)register0x00000038 + -0x10) = uVar3;
    uVar4 = (int)puVar5 * 4 + _page_mask & ~_page_mask;
    iVar1 = _ipc_soft_map;
    _vm_move(_ipc_soft_map,uVar3,_ipc_kernel_map,uVar4,0,
             (undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 == 0) {
      param_2 = (undefined4 *)0x0;
      _vm_deallocate(_ipc_soft_map,*(undefined4 *)((int)register0x00000038 + -0x10),uVar4);
      puVar2 = *(undefined4 **)((int)register0x00000038 + -0xc);
      if (puVar5 != (undefined4 *)0x0) {
        do {
          uVar3 = *puVar2;
          param_2 = (undefined4 *)((int)param_2 + 1);
          _convert_port_type();
          *puVar2 = uVar3;
          puVar2 = puVar2 + 1;
        } while (param_2 < puVar5);
      }
      param_1 = _ipc_kernel_map;
      _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),_ipc_soft_map,uVar4,1
               ,(undefined *)((int)register0x00000038 + -0x10));
      *param_4 = *(undefined4 *)((int)register0x00000038 + -0x10);
    }
    else {
      _kmem_free(_ipc_soft_map,*param_4,*param_5 * 4 + _page_mask & ~_page_mask);
      _kmem_free(_ipc_soft_map,*param_2,*param_3 * 4 + _page_mask & ~_page_mask);
      param_1 = 6;
    }
  }
  else if (param_1 != 6) {
    param_1 = 4;
  }
  return CONCAT44(param_2,param_1);
}
