
/* WARNING: Removing unreachable block (ram,0xf00571f0) */
/* WARNING: Removing unreachable block (ram,0xf0057188) */
/* WARNING: Removing unreachable block (ram,0xf00571cc) */
/* WARNING: Removing unreachable block (ram,0xf005723c) */
/* WARNING: Removing unreachable block (ram,0xf0057158) */

undefined8 _ipc_kmsg_copyout_dest(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l3;
  uint uVar6;
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
  piVar3 = *(int **)(param_1 + 0x1c);
  uVar5 = *(uint *)(param_1 + 0x14);
  iVar4 = *(int *)(param_1 + 0x20);
  uVar6 = (uVar5 & 0xff00) >> 8;
  do {
    do {
    } while (*piVar3 != 0);
    piVar1 = piVar3;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (piVar3[2] < 0) {
    _ipc_object_copyout_dest
              (param_2,piVar3,uVar5 & 0xff,(undefined *)((int)register0x00000038 + -0xc));
  }
  else {
    iVar2 = piVar3[1];
    piVar3[1] = iVar2 + -1;
    *piVar3 = 0;
    if (iVar2 + -1 == 0) {
      _zfree((&_ipc_object_zones)[(piVar3[2] & 0x7fffffffU) >> 0x10],piVar3);
    }
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0xffffffff;
  }
  if ((iVar4 != 0) && (iVar4 != -1)) {
    _ipc_object_destroy(iVar4,uVar6);
    iVar4 = 0;
  }
  *(uint *)(param_1 + 0x14) = uVar5 & 0xffff0000 | uVar6 | (uVar5 & 0xff) << 8;
  *(int *)(param_1 + 0x1c) = iVar4;
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)((int)register0x00000038 + -0xc);
  if ((int)uVar5 < 0) {
    _ipc_kmsg_clean_body(param_1 + 0x2c,param_1 + *(int *)(param_1 + 0x18) + 0x14);
  }
  return CONCAT44(param_2,param_1);
}

