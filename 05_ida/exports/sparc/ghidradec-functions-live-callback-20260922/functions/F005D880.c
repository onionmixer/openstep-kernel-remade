
/* WARNING: Removing unreachable block (ram,0xf005d95c) */
/* WARNING: Removing unreachable block (ram,0xf005d930) */
/* WARNING: Removing unreachable block (ram,0xf005d8f4) */
/* WARNING: Removing unreachable block (ram,0xf005d988) */
/* WARNING: Removing unreachable block (ram,0xf005daec) */
/* WARNING: Removing unreachable block (ram,0xf005da84) */
/* WARNING: Removing unreachable block (ram,0xf005da4c) */
/* WARNING: Removing unreachable block (ram,0xf005db90) */
/* WARNING: Removing unreachable block (ram,0xf005db78) */
/* WARNING: Removing unreachable block (ram,0xf005da20) */
/* WARNING: Removing unreachable block (ram,0xf005da70) */
/* WARNING: Removing unreachable block (ram,0xf005dacc) */
/* WARNING: Removing unreachable block (ram,0xf005db00) */
/* WARNING: Removing unreachable block (ram,0xf005d8c8) */
/* WARNING: Removing unreachable block (ram,0xf005d91c) */
/* WARNING: Removing unreachable block (ram,0xf005d944) */
/* WARNING: Removing unreachable block (ram,0xf005dbb8) */
/* WARNING: Removing unreachable block (ram,0xf005db34) */

undefined8
_ipc_right_copyin_compat
          (int param_1,undefined4 *param_2,uint *param_3,int param_4,int param_5,undefined4 *param_6
          )

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
  undefined4 unaff_i1;
  undefined4 *puVar6;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar7;
  int *piVar8;
  undefined4 unaff_i4;
  undefined4 *puVar9;
  int iVar10;
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
  if (param_4 == 5) {
    iVar7 = 0;
    if (param_5 == 0) {
      if ((uVar3 & 0x20000) != 0) {
        piVar8 = (int *)param_3[1];
        do {
          do {
          } while (*piVar8 != 0);
          piVar2 = piVar8;
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
        if ((uVar3 & 0x10000) == 0) {
          uVar3 = uVar3 | 0x10001;
          piVar8[7] = piVar8[7] + 1;
        }
        _ipc_hash_insert(param_1,piVar8,param_2,param_3);
        *param_3 = uVar3 & 0xfffdffff;
        *(undefined4 *)(param_1 + 8) = 0;
        _ipc_port_clear_receiver(piVar8);
        piVar8[4] = 0;
        piVar8[3] = 0;
        piVar8[1] = piVar8[1] + 1;
        *piVar8 = 0;
        goto loc_F005DBB0;
      }
    }
    else {
      iVar4 = 0;
      if ((uVar3 & 0x20000) != 0) {
        piVar8 = (int *)param_3[1];
        do {
          do {
          } while (*piVar8 != 0);
          piVar2 = piVar8;
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
        if (param_3[2] == 0) {
          iVar10 = 0;
        }
        else {
          iVar10 = param_1;
          _ipc_right_dncancel(param_1,piVar8,param_2,param_3);
        }
        if ((uVar3 & 0x200000) != 0) {
          _ipc_marequest_cancel(param_1,param_2);
        }
        param_3[1] = 0;
        _ipc_entry_dealloc(param_1,param_2,param_3);
        *(undefined4 *)(param_1 + 8) = 0;
        if ((((uVar3 & 0x10000) != 0) &&
            (iVar1 = piVar8[7], piVar8[7] = iVar1 + -1, iVar1 + -1 == 0)) &&
           (iVar7 = piVar8[9], iVar7 != 0)) {
          piVar8[9] = 0;
          iVar4 = piVar8[6];
        }
        _ipc_port_clear_receiver(piVar8);
        piVar8[4] = 0;
        piVar8[3] = 0;
        *piVar8 = 0;
        if (iVar7 != 0) {
          _ipc_notify_no_senders(iVar7,iVar4);
        }
        if (iVar10 != 0) {
          _ipc_notify_port_deleted(iVar10,param_2);
          *param_6 = piVar8;
          goto loc_F005DBC0;
        }
loc_F005DBB0:
        *param_6 = piVar8;
        goto loc_F005DBC0;
      }
    }
loc_F005DBC8:
    *(undefined4 *)(param_1 + 8) = 0;
    uVar5 = 0x11;
  }
  else {
    if (param_4 == 6) {
      if (param_5 == 0) {
        if ((uVar3 & 0x30000) != 0) {
          puVar6 = (undefined4 *)param_3[1];
          iVar7 = param_1;
          _ipc_right_check(param_1,puVar6,param_2,param_3);
          if (iVar7 != 0) goto loc_F005D99C;
          *(undefined4 *)(param_1 + 8) = 0;
          if ((uVar3 & 0x10000) == 0) {
            puVar6[6] = puVar6[6] + 1;
            iVar7 = puVar6[7];
          }
          else {
            iVar7 = puVar6[7];
          }
          puVar6[7] = iVar7 + 1;
          puVar6[1] = puVar6[1] + 1;
          *puVar6 = 0;
          *param_6 = puVar6;
          param_2 = puVar6;
          goto loc_F005DBC0;
        }
      }
      else if ((uVar3 & 0x1f0000) == 0x10000) {
        puVar9 = (undefined4 *)param_3[1];
        iVar7 = param_1;
        _ipc_right_check(param_1,puVar9,param_2,param_3);
        puVar6 = param_2;
        if (iVar7 == 0) {
          if (param_3[2] == 0) {
            iVar7 = 0;
          }
          else {
            iVar7 = param_1;
            _ipc_right_dncancel(param_1,puVar9,param_2,param_3);
          }
          *puVar9 = 0;
          if ((uVar3 & 0x200000) != 0) {
            _ipc_marequest_cancel(param_1,param_2);
          }
          _ipc_hash_delete(param_1,puVar9,param_2,param_3);
          param_3[1] = 0;
          _ipc_entry_dealloc(param_1,param_2,param_3);
          *(undefined4 *)(param_1 + 8) = 0;
          if (iVar7 != 0) {
            _ipc_notify_port_deleted(iVar7,param_2);
          }
          *param_6 = puVar9;
          goto loc_F005DBC0;
        }
loc_F005D99C:
        param_2 = puVar6;
        if ((uVar3 & 0x400000) != 0) {
          *(undefined4 *)(param_1 + 8) = 0;
          uVar5 = 0xf;
          goto locret_F005DBDC;
        }
      }
      goto loc_F005DBC8;
    }
    _panic(aIpcRightCopyin_1);
loc_F005DBC0:
    uVar5 = 0;
  }
locret_F005DBDC:
  return CONCAT44(param_2,uVar5);
}

