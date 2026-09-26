
/* WARNING: Removing unreachable block (ram,0xf006f390) */
/* WARNING: Removing unreachable block (ram,0xf006f40c) */

undefined8
_processor_set_info(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,uint *param_5)

{
  uint uVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  if (param_1 == 0) {
loc_F006F450:
    uVar3 = 4;
  }
  else {
    if (param_2 == 1) {
      if (*param_5 < 5) {
loc_F006F3F4:
        uVar3 = 5;
        goto locret_F006F454;
      }
      do {
        do {
        } while (*(int *)(param_1 + 0x158) != 0);
        piVar2 = (int *)(param_1 + 0x158);
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      *param_4 = *(undefined4 *)(param_1 + 0x124);
      param_4[1] = *(undefined4 *)(param_1 + 0x134);
      param_4[2] = *(undefined4 *)(param_1 + 0x140);
      param_4[4] = *(undefined4 *)(param_1 + 0x170);
      param_4[3] = *(undefined4 *)(param_1 + 0x174);
      *(undefined4 *)(param_1 + 0x158) = 0;
      uVar1 = 5;
    }
    else {
      if (param_2 != 2) {
        *param_3 = 0;
        goto loc_F006F450;
      }
      if (*param_5 < 2) goto loc_F006F3F4;
      do {
        do {
        } while (*(int *)(param_1 + 0x158) != 0);
        piVar2 = (int *)(param_1 + 0x158);
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      *param_4 = *(undefined4 *)(param_1 + 0x168);
      param_4[1] = *(undefined4 *)(param_1 + 0x164);
      *(undefined4 *)(param_1 + 0x158) = 0;
      uVar1 = 2;
    }
    uVar3 = 0;
    *param_5 = uVar1;
    *param_3 = &_realhost;
  }
locret_F006F454:
  return CONCAT44(param_2,uVar3);
}
