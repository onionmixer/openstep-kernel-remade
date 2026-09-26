
/* WARNING: Removing unreachable block (ram,0xf00bf0d0) */
/* WARNING: Removing unreachable block (ram,0xf00bf0a8) */
/* WARNING: Removing unreachable block (ram,0xf00bf064) */
/* WARNING: Removing unreachable block (ram,0xf00bf01c) */
/* WARNING: Removing unreachable block (ram,0xf00bf040) */
/* WARNING: Removing unreachable block (ram,0xf00bf088) */
/* WARNING: Removing unreachable block (ram,0xf00bf0c8) */
/* WARNING: Removing unreachable block (ram,0xf00bf030) */
/* WARNING: Removing unreachable block (ram,0xf00bf000) */

undefined8
_createEventShmem(int param_1,int param_2,int *param_3,undefined4 *param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  uint uVar4;
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
  *param_3 = 0;
  _IOGetKernPort();
  if (param_1 == 0) {
    uVar3 = 4;
  }
  else {
    iVar1 = param_1;
    _convert_port_to_map();
    if (iVar1 == 0) {
      _port_release(param_1);
      uVar3 = 4;
    }
    else {
      _port_release(param_1);
      uVar4 = param_2 + _page_mask & ~_page_mask;
      iVar2 = _kernel_map;
      _kmem_alloc_wired(_kernel_map,param_5,uVar4);
      uVar3 = 0;
      if (iVar2 == 0) {
        _vm_object_special(0,sub_F00BEFD0,0,*param_5,uVar4);
        *param_4 = 0;
        iVar2 = iVar1;
        _vm_map_find(iVar1,uVar3,0,param_4,uVar4,1);
        if (iVar2 == 0) {
          *param_3 = iVar1;
          uVar3 = 0;
          goto locret_F00BF0DC;
        }
        _printf(DAT_f0120a88,iVar2);
      }
      _vm_map_deallocate(iVar1);
      uVar3 = 3;
    }
  }
locret_F00BF0DC:
  return CONCAT44(param_2,uVar3);
}

