
/* WARNING: Removing unreachable block (ram,0xf0062eb0) */
/* WARNING: Removing unreachable block (ram,0xf0062f0c) */
/* WARNING: Removing unreachable block (ram,0xf0062e8c) */

undefined8 _port_translate_compat(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  iVar1 = param_1;
  _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 == 0) {
    iVar1 = param_1;
    _ipc_right_info(param_1,param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                    (undefined *)((int)register0x00000038 + -0x10),
                    (undefined *)((int)register0x00000038 + -0x14));
    uVar3 = *(uint *)((int)register0x00000038 + -0x10);
    if (iVar1 == 0) {
      if ((uVar3 & 0x20000) == 0) {
        *(undefined4 *)(param_1 + 8) = 0;
        uVar4 = 4;
        if ((uVar3 & 0x170000) != 0) {
          uVar4 = 7;
        }
      }
      else {
        param_2 = *(int **)(*(int *)((int)register0x00000038 + -0xc) + 4);
        do {
          do {
          } while (*param_2 != 0);
          piVar2 = param_2;
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
        *(undefined4 *)(param_1 + 8) = 0;
        *param_3 = param_2;
        uVar4 = 0;
      }
    }
    else {
      uVar4 = 4;
    }
  }
  else {
    uVar4 = 4;
  }
  return CONCAT44(param_2,uVar4);
}

