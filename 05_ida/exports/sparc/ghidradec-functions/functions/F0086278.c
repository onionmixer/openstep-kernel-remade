
/* WARNING: Removing unreachable block (ram,0xf00862ec) */
/* WARNING: Removing unreachable block (ram,0xf0086318) */
/* WARNING: Removing unreachable block (ram,0xf00862c4) */

undefined8
_vm_move(undefined4 param_1,uint param_2,int param_3,int param_4,undefined4 param_5,int *param_6)

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
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar3;
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
  if (param_4 == 0) {
    *param_6 = 0;
    iVar2 = 0;
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    uVar1 = param_2 & ~_page_mask;
    iVar3 = (param_2 + param_4 + _page_mask & ~_page_mask) - uVar1;
    iVar2 = param_3;
    _vm_allocate(param_3,(undefined *)((int)register0x00000038 + -0xc),iVar3,1);
    if (iVar2 == 0) {
      iVar2 = param_3;
      _vm_map_copy(param_3,param_1,*(undefined4 *)((int)register0x00000038 + -0xc),iVar3,uVar1,0,
                   param_5);
      if (iVar2 == 0) {
        *param_6 = *(int *)((int)register0x00000038 + -0xc) + (param_2 - uVar1);
      }
      else {
        _vm_deallocate(param_3,*(undefined4 *)((int)register0x00000038 + -0xc),iVar3);
      }
    }
  }
  return CONCAT44(param_2,iVar2);
}
