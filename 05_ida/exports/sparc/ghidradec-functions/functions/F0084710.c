
/* WARNING: Removing unreachable block (ram,0xf00847e0) */
/* WARNING: Removing unreachable block (ram,0xf00847d4) */
/* WARNING: Removing unreachable block (ram,0xf0084714) */

undefined8 __vm_map_clip_start(int *param_1,int *param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  piVar1 = param_1;
  __vm_map_entry_create();
  *piVar1 = *param_2;
  piVar1[1] = param_2[1];
  piVar1[2] = param_2[2];
  piVar1[3] = param_2[3];
  piVar1[4] = param_2[4];
  piVar1[5] = param_2[5];
  piVar1[6] = param_2[6];
  piVar1[7] = param_2[7];
  piVar1[8] = param_2[8];
  piVar1[9] = param_2[9];
  piVar1[10] = param_2[10];
  piVar1[3] = param_3;
  param_2[5] = param_2[5] + (param_3 - param_2[2]);
  param_2[2] = param_3;
  param_1[4] = param_1[4] + 1;
  *piVar1 = *param_2;
  piVar2 = *(int **)(*param_2 + 4);
  iVar3 = *piVar1;
  piVar1[1] = (int)piVar2;
  *piVar2 = (int)piVar1;
  *(int **)(iVar3 + 4) = piVar1;
  if ((param_2[6] & 0xa0000000U) == 0) {
    _vm_object_reference(piVar1[4]);
  }
  else {
    _vm_map_reference(piVar1[4]);
  }
  return CONCAT44(param_2,param_1);
}
