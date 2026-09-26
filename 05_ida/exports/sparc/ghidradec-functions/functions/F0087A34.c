
/* WARNING: Removing unreachable block (ram,0xf0087a78) */
/* WARNING: Removing unreachable block (ram,0xf0087ad4) */
/* WARNING: Removing unreachable block (ram,0xf0087a64) */

undefined8
_vm_object_coalesce(int param_1,int *param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  uint uVar3;
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
  if (param_2 == (int *)0x0) {
    param_2 = (int *)(param_1 + 0x10);
    if (param_1 != 0) {
      do {
        do {
        } while (*param_2 != 0);
        piVar1 = param_2;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      _vm_object_collapse(param_1);
      if ((((1 < *(sword *)(param_1 + 0x18)) || (*(int *)(param_1 + 0x28) != 0)) ||
          (*(int *)(param_1 + 0x20) != 0)) || (*(int *)(param_1 + 0x1c) != 0)) {
        *(undefined4 *)(param_1 + 0x10) = 0;
        uVar2 = 0;
        goto locret_F0087AF4;
      }
      uVar3 = param_3 + param_5 + param_6;
      _vm_object_page_remove(param_1,param_3 + param_5,uVar3);
      if (*(uint *)(param_1 + 0x14) < uVar3) {
        *(uint *)(param_1 + 0x14) = uVar3;
      }
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
locret_F0087AF4:
  return CONCAT44(param_2,uVar2);
}
