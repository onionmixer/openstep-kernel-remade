
/* WARNING: Removing unreachable block (ram,0xf0056dbc) */
/* WARNING: Removing unreachable block (ram,0xf0056d10) */
/* WARNING: Removing unreachable block (ram,0xf0056d3c) */
/* WARNING: Removing unreachable block (ram,0xf0056dd0) */
/* WARNING: Removing unreachable block (ram,0xf0056cd0) */

undefined8 _ipc_kmsg_copyout_object(int param_1,int *param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
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
  if ((param_2 == (int *)0x0) || (param_2 == (int *)0xffffffff)) {
    *param_4 = param_2;
  }
  else {
    if (param_3 == 0x11) {
      do {
        do {
        } while (*(int *)(param_1 + 8) != 0);
        piVar1 = (int *)(param_1 + 8);
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      if (*(int *)(param_1 + 0xc) == 0) {
        *(undefined4 *)(param_1 + 8) = 0;
      }
      else {
        do {
          do {
          } while (*param_2 != 0);
          piVar1 = param_2;
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
        if ((param_2[2] < 0) &&
           (iVar2 = param_1,
           _ipc_hash_local_lookup
                     (param_1,param_2,param_4,(undefined *)((int)register0x00000038 + -0xc)),
           iVar2 != 0)) {
          param_2[7] = param_2[7] + -1;
          param_2[1] = param_2[1] + -1;
          *param_2 = 0;
          uVar3 = **(uint **)((int)register0x00000038 + -0xc) + 1;
          if ((uVar3 & 0xffff) < 0xffff) {
            **(uint **)((int)register0x00000038 + -0xc) = uVar3;
          }
          *(undefined4 *)(param_1 + 8) = 0;
          uVar4 = 0;
          goto locret_F0056E04;
        }
        *param_2 = 0;
        *(undefined4 *)(param_1 + 8) = 0;
      }
    }
    _ipc_object_copyout(param_1,param_2,param_3,1,param_4);
    if (param_1 != 0) {
      _ipc_object_destroy(param_2,param_3);
      if (param_1 != 0x14) {
        *param_4 = 0;
        uVar4 = 0x2000;
        if (param_1 == 6) {
          uVar4 = 0x800;
        }
        goto locret_F0056E04;
      }
      *param_4 = 0xffffffff;
    }
  }
  uVar4 = 0;
locret_F0056E04:
  return CONCAT44(param_2,uVar4);
}

