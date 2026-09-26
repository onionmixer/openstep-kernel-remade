
/* WARNING: Removing unreachable block (ram,0xf005dddc) */
/* WARNING: Removing unreachable block (ram,0xf005dda8) */
/* WARNING: Removing unreachable block (ram,0xf005dd84) */
/* WARNING: Removing unreachable block (ram,0xf005dc7c) */
/* WARNING: Removing unreachable block (ram,0xf005dd60) */
/* WARNING: Removing unreachable block (ram,0xf005dd8c) */
/* WARNING: Removing unreachable block (ram,0xf005ddc4) */
/* WARNING: Removing unreachable block (ram,0xf005dcd4) */
/* WARNING: Removing unreachable block (ram,0xf005dd24) */

undefined8
_ipc_right_copyin_header
          (int param_1,undefined4 *param_2,uint *param_3,undefined4 *param_4,undefined4 *param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
  undefined4 unaff_i1;
  undefined4 *puVar7;
  undefined4 unaff_i2;
  int *piVar8;
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
  uVar3 = uVar4 & 0x1f0000;
  if (uVar3 == 0x30000) {
loc_F005DCC8:
    puVar7 = (undefined4 *)param_3[1];
    iVar5 = param_1;
    _ipc_right_check(param_1,puVar7,param_2,param_3);
    param_2 = puVar7;
    if (iVar5 != 0) {
loc_F005DD38:
      if ((uVar4 & 0x400000) != 0) {
        *(undefined4 *)(param_1 + 8) = 0;
        uVar6 = 0xf;
        goto locret_F005DE00;
      }
      goto loc_F005DDEC;
    }
    *(undefined4 *)(param_1 + 8) = 0;
    puVar7[7] = puVar7[7] + 1;
    puVar7[1] = puVar7[1] + 1;
    *puVar7 = 0;
    *param_4 = puVar7;
loc_F005DD0C:
    *param_5 = 0x11;
  }
  else {
    if (uVar3 < 0x30001) {
      if (uVar3 == 0x10000) goto loc_F005DCC8;
      if (uVar3 != 0x20000) goto loc_F005DDDC;
      piVar8 = (int *)param_3[1];
      do {
        do {
        } while (*piVar8 != 0);
        piVar1 = piVar8;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      *(undefined4 *)(param_1 + 8) = 0;
      piVar8[6] = piVar8[6] + 1;
      piVar8[7] = piVar8[7] + 1;
      piVar8[1] = piVar8[1] + 1;
      *piVar8 = 0;
      *param_4 = piVar8;
      goto loc_F005DD0C;
    }
    if (uVar3 == 0x80000) {
loc_F005DDEC:
      *(undefined4 *)(param_1 + 8) = 0;
      uVar6 = 0x11;
      goto locret_F005DE00;
    }
    if (0x80000 < uVar3) {
      if (uVar3 != 0x100000) goto loc_F005DDDC;
      goto loc_F005DDEC;
    }
    if (uVar3 == 0x40000) {
      puVar7 = (undefined4 *)param_3[1];
      iVar5 = param_1;
      _ipc_right_check(param_1,puVar7,param_2,param_3);
      if (iVar5 != 0) goto loc_F005DD38;
      if (param_3[2] == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = param_1;
        _ipc_right_dncancel(param_1,puVar7,param_2,param_3);
      }
      *puVar7 = 0;
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
      iVar2 = *(int *)(param_1 + 0x44);
      _ipc_port_copy_send();
      *(undefined4 *)(param_1 + 8) = 0;
      if (iVar5 != 0) {
        _ipc_notify_port_deleted(iVar5,param_2);
      }
      if ((iVar2 != 0) && (iVar2 != -1)) {
        _ipc_notify_port_deleted_compat(iVar2,param_2);
      }
      *param_4 = puVar7;
      *param_5 = 0x12;
    }
    else {
loc_F005DDDC:
      _panic(aIpcRightCopyin_2);
    }
  }
  uVar6 = 0;
locret_F005DE00:
  return CONCAT44(param_2,uVar6);
}
