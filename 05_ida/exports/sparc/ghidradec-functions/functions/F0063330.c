
/* WARNING: Removing unreachable block (ram,0xf006341c) */
/* WARNING: Removing unreachable block (ram,0xf00633c0) */
/* WARNING: Removing unreachable block (ram,0xf006336c) */
/* WARNING: Removing unreachable block (ram,0xf00633f8) */
/* WARNING: Removing unreachable block (ram,0xf0063450) */
/* WARNING: Removing unreachable block (ram,0xf0063348) */

undefined8
_port_status(int param_1,int *param_2,int *param_3,int *param_4,int *param_5,undefined4 *param_6)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 *puVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
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
  puVar6 = *(undefined4 **)((int)register0x00000038 + 0x5c);
  if (param_1 == 0) {
loc_F0063398:
    uVar7 = 4;
    goto locret_F00634BC;
  }
  iVar4 = param_1;
  _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar4 != 0) {
    uVar7 = 4;
    goto locret_F00634BC;
  }
  iVar4 = param_1;
  _ipc_right_info(param_1,param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                  (undefined *)((int)register0x00000038 + -0x10),
                  (undefined *)((int)register0x00000038 + -0x14));
  if (iVar4 != 0) {
    uVar7 = 4;
    goto locret_F00634BC;
  }
  if ((*(uint *)((int)register0x00000038 + -0x10) & 0x170000) == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    goto loc_F0063398;
  }
  if ((*(uint *)((int)register0x00000038 + -0x10) & 0x20000) == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    *param_6 = 0;
    *puVar6 = 0;
    *param_3 = 0;
    *param_4 = -1;
    *param_5 = 0;
  }
  else {
    param_2 = *(int **)(*(int *)((int)register0x00000038 + -0xc) + 4);
    do {
      do {
      } while (*param_2 != 0);
      piVar1 = param_2;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    *(undefined4 *)(param_1 + 8) = 0;
    piVar1 = (int *)param_2[0xc];
    if (piVar1 == (int *)0x0) {
loc_F0063474:
      iVar5 = 0;
      iVar4 = param_2[0xf];
    }
    else {
      do {
        do {
        } while (*piVar1 != 0);
        piVar2 = piVar1;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      if (-1 < piVar1[2]) {
        _ipc_pset_remove(piVar1,param_2);
        *piVar1 = 0;
        if (piVar1[1] == 0) {
          _zfree((&_ipc_object_zones)[(piVar1[2] & 0x7fffffffU) >> 0x10],piVar1);
        }
        goto loc_F0063474;
      }
      iVar5 = piVar1[3];
      *piVar1 = 0;
      iVar4 = param_2[0xf];
    }
    *param_2 = 0;
    iVar3 = param_2[0xe];
    *param_6 = 1;
    *puVar6 = 1;
    *param_3 = iVar5;
    *param_4 = iVar3;
    *param_5 = iVar4;
  }
  uVar7 = 0;
locret_F00634BC:
  return CONCAT44(param_2,uVar7);
}
