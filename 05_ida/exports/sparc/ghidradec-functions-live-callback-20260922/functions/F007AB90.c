
/* WARNING: Removing unreachable block (ram,0xf007ac64) */
/* WARNING: Removing unreachable block (ram,0xf007ac40) */
/* WARNING: Removing unreachable block (ram,0xf007ac24) */
/* WARNING: Removing unreachable block (ram,0xf007abe8) */
/* WARNING: Removing unreachable block (ram,0xf007abc8) */
/* WARNING: Removing unreachable block (ram,0xf007ac08) */
/* WARNING: Removing unreachable block (ram,0xf007ac30) */
/* WARNING: Removing unreachable block (ram,0xf007ac48) */
/* WARNING: Removing unreachable block (ram,0xf007ac84) */
/* WARNING: Removing unreachable block (ram,0xf007abac) */

undefined8 sub_F007AB90(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int *piVar2;
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
  uVar1 = (param_1[10] - param_1[9]) + _page_mask;
  uVar4 = uVar1 & ~_page_mask;
  _splusclock();
  do {
    do {
    } while (*param_1 != 0);
    piVar2 = param_1;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  *param_1 = 0;
  iVar3 = param_1[6];
  param_1[6] = 0;
  _splx(uVar1);
  if (iVar3 != 0) {
    _vm_read_EXTERNAL(param_1[0x133],param_1[9],uVar4,(undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x10));
    _kern_serv_log_data(iVar3,*(undefined4 *)((int)register0x00000038 + -0xc),
                        param_1[10] - param_1[9] >> 5);
    _port_deallocate_EXTERNAL(param_1[2],iVar3);
    iVar3 = param_1[2];
    _vm_deallocate_EXTERNAL(iVar3,*(undefined4 *)((int)register0x00000038 + -0xc),uVar4);
    _splusclock();
    do {
      do {
      } while (*param_1 != 0);
      piVar2 = param_1;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    *param_1 = 0;
    param_1[10] = param_1[9];
    _splx(iVar3);
  }
  return CONCAT44(param_2,param_1);
}

