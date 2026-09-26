
/* WARNING: Removing unreachable block (ram,0xf005cc48) */
/* WARNING: Removing unreachable block (ram,0xf005cc04) */
/* WARNING: Removing unreachable block (ram,0xf005cbcc) */
/* WARNING: Removing unreachable block (ram,0xf005c940) */
/* WARNING: Removing unreachable block (ram,0xf005c92c) */
/* WARNING: Removing unreachable block (ram,0xf005c89c) */
/* WARNING: Removing unreachable block (ram,0xf005c9ec) */
/* WARNING: Removing unreachable block (ram,0xf005c9bc) */
/* WARNING: Removing unreachable block (ram,0xf005c838) */
/* WARNING: Removing unreachable block (ram,0xf005c808) */
/* WARNING: Removing unreachable block (ram,0xf005ca20) */
/* WARNING: Removing unreachable block (ram,0xf005cab8) */
/* WARNING: Removing unreachable block (ram,0xf005c820) */
/* WARNING: Removing unreachable block (ram,0xf005c980) */
/* WARNING: Removing unreachable block (ram,0xf005c9e0) */
/* WARNING: Removing unreachable block (ram,0xf005c880) */
/* WARNING: Removing unreachable block (ram,0xf005c914) */
/* WARNING: Removing unreachable block (ram,0xf005c938) */
/* WARNING: Removing unreachable block (ram,0xf005cb3c) */
/* WARNING: Removing unreachable block (ram,0xf005cbec) */
/* WARNING: Removing unreachable block (ram,0xf005cc24) */
/* WARNING: Removing unreachable block (ram,0xf005cc5c) */
/* WARNING: Removing unreachable block (ram,0xf005cc70) */

undefined8 _ipc_right_delta(int param_1,int *param_2,uint *param_3,undefined4 param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 *puVar7;
  undefined4 unaff_l3;
  int iVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar9;
  undefined4 unaff_i1;
  int *piVar10;
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
  switch(param_4) {
  case :
    iVar6 = 0;
    iVar8 = 0;
    uVar9 = 0;
    if ((uVar5 & 0x10000) != 0) {
      uVar3 = uVar5 & 0xffff;
      if ((param_5 < 0) && (uVar3 <= (uint)-param_5 && -uVar3 != param_5)) goto loc_F005CC98;
      if ((0 < param_5) && ((uVar4 = uVar3 + param_5 + 1, uVar4 <= uVar3 + 1 || (0xffff < uVar4))))
      {
loc_F005CCA4:
        *(undefined4 *)(param_1 + 8) = 0;
        uVar9 = 0x13;
        goto locret_F005CCB8;
      }
      puVar7 = (undefined4 *)param_3[1];
      iVar2 = param_1;
      _ipc_right_check(param_1,puVar7,param_2,param_3);
      if (iVar2 != 0) goto loc_F005CB50;
      uVar4 = uVar5 + param_5;
      if (uVar3 + param_5 == 0) {
        iVar2 = puVar7[7];
        puVar7[7] = iVar2 + -1;
        if ((iVar2 + -1 == 0) && (iVar8 = puVar7[9], iVar8 != 0)) {
          puVar7[9] = 0;
          uVar9 = puVar7[6];
        }
        if ((uVar5 & 0x20000) != 0) {
          uVar4 = uVar5 & 0xfffe0000;
          goto loc_F005CC30;
        }
        if (param_3[2] == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = param_1;
          _ipc_right_dncancel(param_1,puVar7,param_2,param_3);
        }
        _ipc_hash_delete(param_1,puVar7,param_2,param_3);
        if ((uVar5 & 0x200000) != 0) {
          _ipc_marequest_cancel(param_1,param_2);
        }
        puVar7[1] = puVar7[1] + -1;
        param_3[1] = 0;
        _ipc_entry_dealloc(param_1,param_2,param_3);
      }
      else {
loc_F005CC30:
        *param_3 = uVar4;
      }
      *puVar7 = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      if (iVar8 != 0) {
        _ipc_notify_no_senders(iVar8,uVar9);
      }
joined_r0xf005c94c:
      if (iVar6 != 0) {
        _ipc_notify_port_deleted(iVar6,param_2);
        uVar9 = 0;
        goto locret_F005CCB8;
      }
loc_F005CC84:
      uVar9 = 0;
      goto locret_F005CCB8;
    }
    break;
  case :
    iVar6 = 0;
    if ((uVar5 & 0x20000) != 0) {
      if (param_5 != 0) {
        if (param_5 != -1) goto loc_F005CC98;
        if ((uVar5 & 0x200000) == 0) {
          piVar10 = (int *)param_3[1];
        }
        else {
          uVar5 = uVar5 & 0xffdfffff;
          _ipc_marequest_cancel(param_1,param_2);
          piVar10 = (int *)param_3[1];
        }
        do {
          do {
          } while (*piVar10 != 0);
          piVar1 = piVar10;
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
        if ((uVar5 & 0x400000) == 0) {
          if ((uVar5 & 0x10000) == 0) {
            iVar6 = 0;
            if (param_3[2] != 0) goto loc_F005C90C;
            goto loc_F005C920;
          }
          uVar5 = uVar5 & 0xffe0ffff | 0x100000;
          if (param_3[2] != 0) {
            param_3[2] = 0;
            uVar5 = uVar5 + 1;
          }
          *param_3 = uVar5;
          param_3[1] = 0;
        }
        else {
loc_F005C90C:
          iVar6 = param_1;
          _ipc_right_dncancel(param_1,piVar10,param_2,param_3);
loc_F005C920:
          param_3[1] = 0;
          _ipc_entry_dealloc(param_1,param_2,param_3);
        }
        *(undefined4 *)(param_1 + 8) = 0;
        _ipc_port_clear_receiver(piVar10);
        _ipc_port_destroy(piVar10);
        goto joined_r0xf005c94c;
      }
loc_F005CC80:
      *(undefined4 *)(param_1 + 8) = 0;
      goto loc_F005CC84;
    }
    break;
  case :
    if ((uVar5 & 0x40000) != 0) {
      if (1 < param_5 + 1U) goto loc_F005CC98;
      puVar7 = (undefined4 *)param_3[1];
      iVar6 = param_1;
      _ipc_right_check(param_1,puVar7,param_2,param_3);
      if (iVar6 != 0) {
loc_F005CB50:
        if ((uVar5 & 0x400000) != 0) goto loc_F005CCB0;
        break;
      }
      if (param_5 == 0) {
        *puVar7 = 0;
        goto loc_F005CC80;
      }
      if (param_3[2] == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = param_1;
        _ipc_right_dncancel(param_1,puVar7,param_2,param_3);
      }
      *puVar7 = 0;
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
      *(undefined4 *)(param_1 + 8) = 0;
      _ipc_notify_send_once(puVar7);
      goto joined_r0xf005c94c;
    }
    break;
  case :
    if ((uVar5 & 0x80000) != 0) {
      if (param_5 == 0) goto loc_F005CC80;
      if (param_5 == -1) {
        piVar10 = (int *)param_3[1];
        param_3[1] = 0;
        _ipc_entry_dealloc(param_1,param_2);
        do {
          do {
          } while (*piVar10 != 0);
          piVar1 = piVar10;
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
        *(undefined4 *)(param_1 + 8) = 0;
        _ipc_pset_destroy(piVar10);
        uVar9 = 0;
        param_2 = piVar10;
        goto locret_F005CCB8;
      }
loc_F005CC98:
      *(undefined4 *)(param_1 + 8) = 0;
      uVar9 = 0x12;
      goto locret_F005CCB8;
    }
    break;
  case :
    if ((uVar5 & 0x50000) == 0) {
      if ((uVar5 & 0x100000) != 0) goto loc_F005CA60;
    }
    else {
      puVar7 = (undefined4 *)param_3[1];
      iVar6 = param_1;
      _ipc_right_check(param_1,puVar7,param_2,param_3);
      if (iVar6 != 0) {
        if ((uVar5 & 0x400000) != 0) {
loc_F005CCB0:
          *(undefined4 *)(param_1 + 8) = 0;
          uVar9 = 0xf;
          goto locret_F005CCB8;
        }
        uVar5 = *param_3;
loc_F005CA60:
        uVar3 = uVar5 & 0xffff;
        if ((-1 < param_5) || ((uint)-param_5 < uVar3 || -uVar3 == param_5)) {
          if ((0 < param_5) && ((uVar3 + param_5 <= uVar3 || (0xffff < uVar3 + param_5))))
          goto loc_F005CCA4;
          if (uVar3 + param_5 == 0) {
            _ipc_entry_dealloc(param_1,param_2,param_3);
          }
          else {
            *param_3 = uVar5 + param_5;
          }
          goto loc_F005CC80;
        }
        goto loc_F005CC98;
      }
      *puVar7 = 0;
    }
    break;
  :
    _panic(aIpcRightDeltaS);
    uVar9 = 0;
    goto locret_F005CCB8;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  uVar9 = 0x11;
locret_F005CCB8:
  return CONCAT44(param_2,uVar9);
}
