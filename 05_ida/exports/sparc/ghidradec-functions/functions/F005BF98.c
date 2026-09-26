
/* WARNING: Removing unreachable block (ram,0xf005c188) */
/* WARNING: Removing unreachable block (ram,0xf005c138) */
/* WARNING: Removing unreachable block (ram,0xf005c0d8) */
/* WARNING: Removing unreachable block (ram,0xf005c060) */
/* WARNING: Removing unreachable block (ram,0xf005c1a8) */
/* WARNING: Removing unreachable block (ram,0xf005c0b8) */
/* WARNING: Removing unreachable block (ram,0xf005c160) */
/* WARNING: Removing unreachable block (ram,0xf005c140) */
/* WARNING: Removing unreachable block (ram,0xf005c19c) */
/* WARNING: Removing unreachable block (ram,0xf005c024) */
/* WARNING: Removing unreachable block (ram,0xf005c038) */

undefined8 _ipc_right_clean(int param_1,undefined4 param_2,uint *param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l3;
  int iVar7;
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
  uVar3 = *param_3;
  uVar5 = uVar3 & 0x1f0000;
  if (uVar5 == 0x30000) {
    piVar4 = (int *)param_3[1];
  }
  else {
    if (0x30000 < uVar5) {
      if (uVar5 == 0x80000) {
        piVar4 = (int *)param_3[1];
        do {
          do {
          } while (*piVar4 != 0);
          piVar1 = piVar4;
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
        _ipc_pset_destroy(piVar4);
        goto locret_F005C1B0;
      }
      if (uVar5 < 0x80001) {
        iVar6 = -0x40000;
        goto loc_F005BFF0;
      }
      if (uVar5 == 0x100000) goto locret_F005C1B0;
loc_F005C1A8:
      _panic(aIpcRightCleanS);
      goto locret_F005C1B0;
    }
    if (uVar5 == 0x10000) {
      piVar4 = (int *)param_3[1];
    }
    else {
      iVar6 = -0x20000;
loc_F005BFF0:
      if (uVar5 + iVar6 != 0) goto loc_F005C1A8;
      piVar4 = (int *)param_3[1];
    }
  }
  iVar6 = 0;
  iVar7 = 0;
  do {
    do {
    } while (*piVar4 != 0);
    piVar1 = piVar4;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (piVar4[2] < 0) {
    if (param_3[2] == 0) {
      param_1 = 0;
    }
    else {
      _ipc_right_dncancel(param_1,piVar4,param_2,param_3);
    }
    if ((((uVar3 & 0x10000) != 0) && (iVar2 = piVar4[7], piVar4[7] = iVar2 + -1, iVar2 + -1 == 0))
       && (iVar6 = piVar4[9], iVar6 != 0)) {
      piVar4[9] = 0;
      iVar7 = piVar4[6];
    }
    if ((uVar3 & 0x20000) == 0) {
      if ((uVar3 & 0x40000) == 0) {
        piVar4[1] = piVar4[1] + -1;
        *piVar4 = 0;
      }
      else {
        *piVar4 = 0;
        _ipc_notify_send_once(piVar4);
      }
    }
    else {
      _ipc_port_clear_receiver(piVar4);
      _ipc_port_destroy(piVar4);
    }
    if (iVar6 != 0) {
      _ipc_notify_no_senders(iVar6,iVar7);
    }
    if (param_1 != 0) {
      _ipc_notify_port_deleted(param_1,param_2);
    }
  }
  else {
    iVar6 = piVar4[1];
    piVar4[1] = iVar6 + -1;
    *piVar4 = 0;
    if (iVar6 + -1 == 0) {
      _zfree((&_ipc_object_zones)[(piVar4[2] & 0x7fffffffU) >> 0x10],piVar4);
    }
  }
locret_F005C1B0:
  return CONCAT44(param_2,param_1);
}
