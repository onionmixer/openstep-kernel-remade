
/* WARNING: Removing unreachable block (ram,0xf005c6bc) */
/* WARNING: Removing unreachable block (ram,0xf005c678) */
/* WARNING: Removing unreachable block (ram,0xf005c640) */
/* WARNING: Removing unreachable block (ram,0xf005c5bc) */
/* WARNING: Removing unreachable block (ram,0xf005c580) */
/* WARNING: Removing unreachable block (ram,0xf005c530) */
/* WARNING: Removing unreachable block (ram,0xf005c76c) */
/* WARNING: Removing unreachable block (ram,0xf005c55c) */
/* WARNING: Removing unreachable block (ram,0xf005c58c) */
/* WARNING: Removing unreachable block (ram,0xf005c504) */
/* WARNING: Removing unreachable block (ram,0xf005c660) */
/* WARNING: Removing unreachable block (ram,0xf005c698) */
/* WARNING: Removing unreachable block (ram,0xf005c6d0) */
/* WARNING: Removing unreachable block (ram,0xf005c6f8) */

undefined8 _ipc_right_dealloc(int param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 *puVar4;
  undefined4 unaff_l1;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l3;
  int iVar7;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
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
  uVar6 = *param_3;
  uVar2 = uVar6 & 0x1f0000;
  iVar3 = 0;
  if (uVar2 == 0x30000) {
    iVar5 = 0;
    param_2 = (int *)param_3[1];
    do {
      do {
      } while (*param_2 != 0);
      piVar1 = param_2;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    uVar2 = uVar6 - 1;
    if ((uVar6 & 0xffff) == 1) {
      iVar7 = param_2[7];
      param_2[7] = iVar7 + -1;
      if ((iVar7 + -1 == 0) && (iVar3 = param_2[9], iVar3 != 0)) {
        param_2[9] = 0;
        iVar5 = param_2[6];
      }
      uVar2 = uVar6 & 0xfffe0000;
    }
    *param_3 = uVar2;
    *param_2 = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    if (iVar3 != 0) {
      _ipc_notify_no_senders(iVar3,iVar5);
      uVar8 = 0;
      goto locret_F005C798;
    }
  }
  else {
    if (uVar2 < 0x30001) {
      iVar3 = 0;
      if (uVar2 != 0x10000) {
loc_F005C77C:
        *(undefined4 *)(param_1 + 8) = 0;
        uVar8 = 0x11;
        goto locret_F005C798;
      }
      iVar7 = 0;
      uVar8 = 0;
      puVar4 = (undefined4 *)param_3[1];
      iVar5 = param_1;
      _ipc_right_check(param_1,puVar4,param_2,param_3);
      if (iVar5 != 0) {
loc_F005C5D0:
        if ((uVar6 & 0x400000) != 0) {
          *(undefined4 *)(param_1 + 8) = 0;
          uVar8 = 0xf;
          goto locret_F005C798;
        }
        uVar6 = *param_3;
loc_F005C4E4:
        if ((uVar6 & 0xffff) == 1) {
          _ipc_entry_dealloc(param_1,param_2,param_3);
        }
        else {
          *param_3 = uVar6 - 1;
        }
        *(undefined4 *)(param_1 + 8) = 0;
        uVar8 = 0;
        goto locret_F005C798;
      }
      if ((uVar6 & 0xffff) == 1) {
        iVar3 = puVar4[7];
        puVar4[7] = iVar3 + -1;
        if (iVar3 + -1 == 0) {
          iVar7 = puVar4[9];
          if (iVar7 != 0) {
            puVar4[9] = 0;
            uVar8 = puVar4[6];
            goto loc_F005C628;
          }
          uVar2 = param_3[2];
        }
        else {
loc_F005C628:
          uVar2 = param_3[2];
        }
        if (uVar2 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = param_1;
          _ipc_right_dncancel(param_1,puVar4,param_2,param_3);
        }
        _ipc_hash_delete(param_1,puVar4,param_2,param_3);
        if ((uVar6 & 0x200000) != 0) {
          _ipc_marequest_cancel(param_1,param_2);
        }
        puVar4[1] = puVar4[1] + -1;
        param_3[1] = 0;
        _ipc_entry_dealloc(param_1,param_2,param_3);
      }
      else {
        *param_3 = uVar6 - 1;
      }
      *puVar4 = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      if (iVar7 != 0) {
        _ipc_notify_no_senders(iVar7,uVar8);
      }
    }
    else {
      if (uVar2 != 0x40000) {
        if (uVar2 == 0x100000) goto loc_F005C4E4;
        goto loc_F005C77C;
      }
      puVar4 = (undefined4 *)param_3[1];
      iVar3 = param_1;
      _ipc_right_check(param_1,puVar4,param_2,param_3);
      if (iVar3 != 0) goto loc_F005C5D0;
      if (param_3[2] == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = param_1;
        _ipc_right_dncancel(param_1,puVar4,param_2,param_3);
      }
      *puVar4 = 0;
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
      *(undefined4 *)(param_1 + 8) = 0;
      _ipc_notify_send_once(puVar4);
    }
    if (iVar3 != 0) {
      _ipc_notify_port_deleted(iVar3,param_2);
      uVar8 = 0;
      goto locret_F005C798;
    }
  }
  uVar8 = 0;
locret_F005C798:
  return CONCAT44(param_2,uVar8);
}

