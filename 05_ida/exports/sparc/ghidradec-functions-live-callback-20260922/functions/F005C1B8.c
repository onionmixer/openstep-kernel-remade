
/* WARNING: Removing unreachable block (ram,0xf005c358) */
/* WARNING: Removing unreachable block (ram,0xf005c46c) */
/* WARNING: Removing unreachable block (ram,0xf005c40c) */
/* WARNING: Removing unreachable block (ram,0xf005c42c) */
/* WARNING: Removing unreachable block (ram,0xf005c38c) */
/* WARNING: Removing unreachable block (ram,0xf005c2d0) */
/* WARNING: Removing unreachable block (ram,0xf005c288) */
/* WARNING: Removing unreachable block (ram,0xf005c270) */
/* WARNING: Removing unreachable block (ram,0xf005c2b0) */
/* WARNING: Removing unreachable block (ram,0xf005c2e8) */
/* WARNING: Removing unreachable block (ram,0xf005c3ac) */
/* WARNING: Removing unreachable block (ram,0xf005c404) */
/* WARNING: Removing unreachable block (ram,0xf005c454) */
/* WARNING: Removing unreachable block (ram,0xf005c340) */
/* WARNING: Removing unreachable block (ram,0xf005c47c) */
/* WARNING: Removing unreachable block (ram,0xf005c238) */
/* WARNING: Removing unreachable block (ram,0xf005c258) */

undefined8 _ipc_right_destroy(int param_1,undefined4 param_2,uint *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l3;
  int iVar7;
  undefined4 unaff_l4;
  int iVar8;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar9;
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
  uVar5 = *param_3;
  uVar4 = uVar5 & 0x1f0000;
  if (uVar4 == 0x30000) {
loc_F005C298:
    iVar7 = 0;
    iVar8 = 0;
    piVar3 = (int *)param_3[1];
    if ((uVar5 & 0x200000) != 0) {
      _ipc_marequest_cancel(param_1,param_2);
    }
    if (uVar4 == 0x10000) {
      _ipc_hash_delete(param_1,piVar3,param_2,param_3);
    }
    do {
      do {
      } while (*piVar3 != 0);
      piVar1 = piVar3;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if (piVar3[2] < 0) {
      if (param_3[2] == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = param_1;
        _ipc_right_dncancel(param_1,piVar3,param_2,param_3);
      }
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
      *(undefined4 *)(param_1 + 8) = 0;
      if ((((uVar5 & 0x10000) != 0) && (iVar2 = piVar3[7], piVar3[7] = iVar2 + -1, iVar2 + -1 == 0))
         && (iVar7 = piVar3[9], iVar7 != 0)) {
        piVar3[9] = 0;
        iVar8 = piVar3[6];
      }
      if ((uVar5 & 0x20000) == 0) {
        if ((uVar5 & 0x40000) == 0) {
          piVar3[1] = piVar3[1] + -1;
          *piVar3 = 0;
        }
        else {
          *piVar3 = 0;
          _ipc_notify_send_once(piVar3);
        }
      }
      else {
        _ipc_port_clear_receiver(piVar3);
        _ipc_port_destroy(piVar3);
      }
      if (iVar7 != 0) {
        _ipc_notify_no_senders(iVar7,iVar8);
      }
      uVar9 = 0;
      if (iVar6 != 0) {
        _ipc_notify_port_deleted(iVar6,param_2);
        uVar9 = 0;
      }
      goto locret_F005C488;
    }
    iVar7 = piVar3[1];
    piVar3[1] = iVar7 + -1;
    *piVar3 = 0;
    if (iVar7 + -1 == 0) {
      _zfree((&_ipc_object_zones)[(piVar3[2] & 0x7fffffffU) >> 0x10],piVar3);
    }
    param_3[2] = 0;
    param_3[1] = 0;
    _ipc_entry_dealloc(param_1,param_2,param_3);
    *(undefined4 *)(param_1 + 8) = 0;
    uVar9 = 0xf;
    if ((uVar5 & 0x400000) != 0) goto locret_F005C488;
  }
  else {
    if (uVar4 < 0x30001) {
      if (uVar4 != 0x10000) {
        iVar7 = -0x20000;
loc_F005C210:
        if (uVar4 + iVar7 != 0) goto loc_F005C47C;
      }
      goto loc_F005C298;
    }
    if (uVar4 == 0x80000) {
      piVar3 = (int *)param_3[1];
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2);
      do {
        do {
        } while (*piVar3 != 0);
        piVar1 = piVar3;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      *(undefined4 *)(param_1 + 8) = 0;
      _ipc_pset_destroy(piVar3);
      uVar9 = 0;
      goto locret_F005C488;
    }
    if (uVar4 < 0x80001) {
      iVar7 = -0x40000;
      goto loc_F005C210;
    }
    if (uVar4 == 0x100000) {
      _ipc_entry_dealloc(param_1,param_2,param_3);
      *(undefined4 *)(param_1 + 8) = 0;
      uVar9 = 0;
      goto locret_F005C488;
    }
loc_F005C47C:
    _panic(aIpcRightDestro);
  }
  uVar9 = 0;
locret_F005C488:
  return CONCAT44(param_2,uVar9);
}

