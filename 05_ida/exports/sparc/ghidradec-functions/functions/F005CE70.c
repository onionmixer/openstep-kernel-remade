
/* WARNING: Removing unreachable block (ram,0xf005cfb4) */
/* WARNING: Removing unreachable block (ram,0xf005cfe4) */
/* WARNING: Removing unreachable block (ram,0xf005d19c) */
/* WARNING: Removing unreachable block (ram,0xf005d168) */
/* WARNING: Removing unreachable block (ram,0xf005d264) */
/* WARNING: Removing unreachable block (ram,0xf005d06c) */
/* WARNING: Removing unreachable block (ram,0xf005cf30) */
/* WARNING: Removing unreachable block (ram,0xf005cedc) */
/* WARNING: Removing unreachable block (ram,0xf005d20c) */
/* WARNING: Removing unreachable block (ram,0xf005d0fc) */
/* WARNING: Removing unreachable block (ram,0xf005d180) */
/* WARNING: Removing unreachable block (ram,0xf005cf8c) */
/* WARNING: Removing unreachable block (ram,0xf005d008) */
/* WARNING: Removing unreachable block (ram,0xf005d020) */
/* WARNING: Removing unreachable block (ram,0xf005d29c) */

undefined8
_ipc_right_copyin(int param_1,undefined4 param_2,uint *param_3,undefined4 param_4,int param_5,
                 undefined4 *param_6)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  int iVar4;
  int *piVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int *piVar8;
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
  uVar3 = *param_3;
  piVar5 = *(int **)((int)register0x00000038 + 0x5c);
  switch(param_4) {
  case :
    iVar4 = 0;
    if ((uVar3 & 0x20000) == 0) goto loc_F005D2FC;
    piVar8 = (int *)param_3[1];
    do {
      do {
      } while (*piVar8 != 0);
      piVar1 = piVar8;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if ((uVar3 & 0x10000) == 0) {
      if (param_3[2] == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = param_1;
        _ipc_right_dncancel(param_1,piVar8,param_2,param_3);
      }
      if ((uVar3 & 0x200000) != 0) {
        _ipc_marequest_cancel(param_1,param_2);
      }
      param_3[1] = 0;
    }
    else {
      _ipc_hash_insert(param_1,piVar8,param_2,param_3);
      piVar8[1] = piVar8[1] + 1;
    }
    *param_3 = uVar3 & 0xfffdffff;
    _ipc_port_clear_receiver(piVar8);
    piVar8[4] = 0;
    piVar8[3] = 0;
    *piVar8 = 0;
    *param_6 = piVar8;
    *piVar5 = iVar4;
    goto loc_F005D2F4;
  case :
    iVar4 = 0;
    if ((uVar3 & 0x100000) == 0) {
      if ((uVar3 & 0x50000) == 0) goto loc_F005D2FC;
      puVar6 = (undefined4 *)param_3[1];
      iVar2 = param_1;
      _ipc_right_check(param_1,puVar6,param_2,param_3);
      if (iVar2 == 0) {
        if ((uVar3 & 0x10000) == 0) {
loc_F005D244:
          *puVar6 = 0;
          uVar7 = 0x11;
          goto locret_F005D300;
        }
        if ((uVar3 & 0xffff) == 1) {
          if ((uVar3 & 0x20000) == 0) {
            if (param_3[2] != 0) {
              iVar4 = param_1;
              _ipc_right_dncancel(param_1,puVar6,param_2,param_3);
            }
            _ipc_hash_delete(param_1,puVar6,param_2,param_3);
            if ((uVar3 & 0x200000) == 0) {
              param_3[1] = 0;
            }
            else {
              _ipc_marequest_cancel(param_1,param_2);
              param_3[1] = 0;
            }
          }
          else {
            puVar6[1] = puVar6[1] + 1;
          }
          uVar3 = uVar3 & 0xfffe0000;
        }
        else {
          puVar6[7] = puVar6[7] + 1;
          puVar6[1] = puVar6[1] + 1;
          uVar3 = uVar3 - 1;
        }
        *param_3 = uVar3;
        *puVar6 = 0;
        *param_6 = puVar6;
        *piVar5 = iVar4;
        goto loc_F005D2F4;
      }
loc_F005D220:
      uVar7 = 0xf;
      if ((uVar3 & 0x400000) != 0) goto locret_F005D300;
      uVar3 = *param_3;
    }
    break;
  case :
    if ((uVar3 & 0x100000) == 0) {
      if ((uVar3 & 0x50000) == 0) goto loc_F005D2FC;
      puVar6 = (undefined4 *)param_3[1];
      iVar4 = param_1;
      _ipc_right_check(param_1,puVar6,param_2,param_3);
      if (iVar4 != 0) goto loc_F005D220;
      if ((uVar3 & 0x40000) == 0) goto loc_F005D244;
      if (param_3[2] == 0) {
        param_1 = 0;
      }
      else {
        _ipc_right_dncancel(param_1,puVar6,param_2,param_3);
      }
      *puVar6 = 0;
      param_3[1] = 0;
      *param_3 = uVar3 & 0xfffbffff;
      *param_6 = puVar6;
      *piVar5 = param_1;
      goto loc_F005D2F4;
    }
    break;
  case :
    if ((uVar3 & 0x100000) != 0) {
loc_F005D2AC:
      uVar7 = 0x11;
      if (param_5 == 0) goto locret_F005D300;
      goto loc_F005D2EC;
    }
    if ((uVar3 & 0x50000) == 0) goto loc_F005D2FC;
    puVar6 = (undefined4 *)param_3[1];
    _ipc_right_check(param_1,puVar6,param_2,param_3);
    if (param_1 != 0) {
      uVar7 = 0xf;
      if ((uVar3 & 0x400000) != 0) goto locret_F005D300;
      goto loc_F005D2AC;
    }
    if ((uVar3 & 0x10000) == 0) {
      *puVar6 = 0;
      uVar7 = 0x11;
      goto locret_F005D300;
    }
    puVar6[7] = puVar6[7] + 1;
    puVar6[1] = puVar6[1] + 1;
    *puVar6 = 0;
    *param_6 = puVar6;
    goto loc_F005D2F0;
  case :
    uVar7 = 0x11;
    if ((uVar3 & 0x20000) == 0) goto locret_F005D300;
    piVar8 = (int *)param_3[1];
    do {
      do {
      } while (*piVar8 != 0);
      piVar1 = piVar8;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    piVar8[6] = piVar8[6] + 1;
    piVar8[7] = piVar8[7] + 1;
    goto loc_F005CF50;
  case :
    uVar7 = 0x11;
    if ((uVar3 & 0x20000) == 0) goto locret_F005D300;
    piVar8 = (int *)param_3[1];
    do {
      do {
      } while (*piVar8 != 0);
      piVar1 = piVar8;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    piVar8[8] = piVar8[8] + 1;
loc_F005CF50:
    piVar8[1] = piVar8[1] + 1;
    *piVar8 = 0;
    *param_6 = piVar8;
    goto loc_F005D2F0;
  :
    _panic(aIpcRightCopyin_0);
    uVar7 = 0;
    goto locret_F005D300;
  }
  if (param_5 == 0) {
loc_F005D2FC:
    uVar7 = 0x11;
  }
  else {
    if ((uVar3 & 0xffff) == 1) {
      uVar3 = uVar3 & 0xffefffff;
    }
    else {
      uVar3 = uVar3 - 1;
    }
    *param_3 = uVar3;
loc_F005D2EC:
    *param_6 = 0xffffffff;
loc_F005D2F0:
    *piVar5 = 0;
loc_F005D2F4:
    uVar7 = 0;
  }
locret_F005D300:
  return CONCAT44(param_2,uVar7);
}
