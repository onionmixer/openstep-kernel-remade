
/* WARNING: Removing unreachable block (ram,0xf005be5c) */
/* WARNING: Removing unreachable block (ram,0xf005be48) */
/* WARNING: Removing unreachable block (ram,0xf005be64) */
/* WARNING: Removing unreachable block (ram,0xf005be08) */

undefined8 _ipc_right_inuse(int param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  uVar4 = *param_3;
  uVar1 = uVar4 & 0x1f0000;
  if (uVar1 == 0) {
    uVar5 = 0;
  }
  else {
    if (((uVar4 & 0x400000) != 0) && ((uVar1 == 0x10000 || (uVar1 == 0x40000)))) {
      piVar3 = (int *)param_3[1];
      do {
        do {
        } while (*piVar3 != 0);
        piVar2 = piVar3;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      *piVar3 = 0;
      if (-1 < piVar3[2]) {
        if (uVar1 == 0x10000) {
          if ((uVar4 & 0x200000) != 0) {
            _ipc_marequest_cancel(param_1,param_2);
          }
          _ipc_hash_delete(param_1,piVar3,param_2,param_3);
        }
        _ipc_object_release(piVar3);
        param_3[2] = 0;
        param_3[1] = 0;
        uVar5 = 0;
        *param_3 = *param_3 & 0xff800000;
        goto locret_F005BE9C;
      }
    }
    *(undefined4 *)(param_1 + 8) = 0;
    uVar5 = 1;
  }
locret_F005BE9C:
  return CONCAT44(param_2,uVar5);
}

