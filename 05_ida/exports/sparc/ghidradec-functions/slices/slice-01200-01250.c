/* GHIDRADEC_FUNCTION index=1200 start=0xf005d880 */

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
/* GHIDRADEC_FUNCTION index=1201 start=0xf005dbe4 */

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
/* GHIDRADEC_FUNCTION index=1202 start=0xf005de08 */

/* WARNING: Removing unreachable block (ram,0xf005de1c) */

undefined8 _ipc_space_reference(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  do {
    do {
    } while (*param_1 != 0);
    piVar1 = param_1;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  *param_1 = 0;
  param_1[1] = param_1[1] + 1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1203 start=0xf005de48 */

/* WARNING: Removing unreachable block (ram,0xf005de90) */
/* WARNING: Removing unreachable block (ram,0xf005de5c) */

undefined8 _ipc_space_release(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  do {
    do {
    } while (*param_1 != 0);
    piVar1 = param_1;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  iVar2 = param_1[1];
  *param_1 = 0;
  param_1[1] = iVar2 + -1;
  if (iVar2 + -1 == 0) {
    _zfree(_ipc_space_zone,param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1204 start=0xf005dea0 */

/* WARNING: Removing unreachable block (ram,0xf005def0) */
/* WARNING: Removing unreachable block (ram,0xf005dec4) */
/* WARNING: Removing unreachable block (ram,0xf005dedc) */
/* WARNING: Removing unreachable block (ram,0xf005df5c) */
/* WARNING: Removing unreachable block (ram,0xf005dea8) */

undefined8 _ipc_space_create(uint *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  puVar1 = _ipc_space_zone;
  _zalloc();
  if (puVar1 == (undefined4 *)0x0) {
    uVar6 = 6;
  }
  else {
    iVar2 = *param_1 << 4;
    _ipc_table_alloc();
    if (iVar2 == 0) {
      _zfree(_ipc_space_zone,puVar1);
      uVar6 = 6;
    }
    else {
      uVar5 = *param_1;
      _bzero(iVar2,uVar5 << 4);
      uVar4 = 0;
      if (uVar5 != 0) {
        do {
          iVar3 = uVar4 * 0x10;
          *(undefined4 *)(iVar2 + iVar3) = 0xff000000;
          uVar4 = uVar4 + 1;
          *(uint *)(iVar2 + iVar3 + 8) = uVar4;
        } while (uVar4 < uVar5);
      }
      *(undefined4 *)(uVar5 * 0x10 + iVar2 + -8) = 0;
      *puVar1 = 0;
      puVar1[1] = 2;
      puVar1[2] = 0;
      puVar1[3] = 1;
      puVar1[4] = 0;
      puVar1[5] = iVar2;
      puVar1[6] = uVar5;
      puVar1[7] = param_1 + 1;
      _ipc_splay_tree_init(puVar1 + 8);
      puVar1[0xe] = 0;
      puVar1[0xf] = 0;
      puVar1[0x10] = 0;
      puVar1[0x11] = 0;
      *param_2 = puVar1;
      uVar6 = 0;
    }
  }
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=1205 start=0xf005df84 */

/* WARNING: Removing unreachable block (ram,0xf005df8c) */

undefined8 _ipc_space_create_special(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  puVar1 = _ipc_space_zone;
  _zalloc();
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 6;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 1;
    puVar1[2] = 0;
    puVar1[3] = 0;
    *param_1 = puVar1;
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1206 start=0xf005dfc4 */

/* WARNING: Removing unreachable block (ram,0xf005e18c) */
/* WARNING: Removing unreachable block (ram,0xf005e158) */
/* WARNING: Removing unreachable block (ram,0xf005e13c) */
/* WARNING: Removing unreachable block (ram,0xf005e0f8) */
/* WARNING: Removing unreachable block (ram,0xf005e068) */
/* WARNING: Removing unreachable block (ram,0xf005e044) */
/* WARNING: Removing unreachable block (ram,0xf005e01c) */
/* WARNING: Removing unreachable block (ram,0xf005e050) */
/* WARNING: Removing unreachable block (ram,0xf005e0d4) */
/* WARNING: Removing unreachable block (ram,0xf005e100) */
/* WARNING: Removing unreachable block (ram,0xf005e14c) */
/* WARNING: Removing unreachable block (ram,0xf005e16c) */
/* WARNING: Removing unreachable block (ram,0xf005e194) */
/* WARNING: Removing unreachable block (ram,0xf005dfdc) */

undefined8 _ipc_space_destroy(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
  uint uVar5;
  undefined4 unaff_l3;
  uint *puVar6;
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
  do {
    do {
    } while (*(int *)(param_1 + 8) != 0);
    piVar1 = (int *)(param_1 + 8);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  iVar2 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (iVar2 != 0) {
    do {
      do {
      } while (*(int *)(param_1 + 8) != 0);
      piVar1 = (int *)(param_1 + 8);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if (*(int *)(param_1 + 0x10) != 0) {
      do {
        _assert_wait(param_1,0);
        *(undefined4 *)(param_1 + 8) = 0;
        _thread_block_with_continuation(0);
        do {
          do {
          } while (*(int *)(param_1 + 8) != 0);
          piVar1 = (int *)(param_1 + 8);
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
      } while (*(int *)(param_1 + 0x10) != 0);
    }
    *(undefined4 *)(param_1 + 8) = 0;
    uVar5 = *(uint *)(param_1 + 0x18);
    uVar4 = 0;
    puVar6 = *(uint **)(param_1 + 0x14);
    puVar3 = puVar6;
    if (uVar5 != 0) {
      do {
        if ((*puVar3 & 0x1f0000) != 0) {
          _ipc_right_clean(param_1,uVar4 << 8 | *puVar3 >> 0x18,puVar3);
        }
        uVar4 = uVar4 + 1;
        puVar3 = puVar3 + 4;
      } while (uVar4 < uVar5);
    }
    _ipc_table_free(*(int *)(*(int *)(param_1 + 0x1c) + -4) << 4,puVar6);
    puVar3 = (uint *)(param_1 + 0x20);
    _ipc_splay_traverse_start();
    if (puVar3 != (uint *)0x0) {
      uVar4 = *puVar3;
      while( true ) {
        uVar5 = puVar3[4];
        if ((uVar4 & 0x1f0000) == 0x10000) {
          _ipc_hash_global_delete(param_1,puVar3[1],uVar5,puVar3);
        }
        _ipc_right_clean(param_1,uVar5,puVar3);
        puVar3 = (uint *)(param_1 + 0x20);
        _ipc_splay_traverse_next(puVar3,1);
        if (puVar3 == (uint *)0x0) break;
        uVar4 = *puVar3;
      }
    }
    _ipc_splay_traverse_finish(param_1 + 0x20);
    if ((*(int *)(param_1 + 0x44) != 0) && (*(int *)(param_1 + 0x44) != -1)) {
      _ipc_port_release_send();
    }
    _ipc_space_release(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1207 start=0xf005e2f4 */

undefined8 _ipc_splay_tree_init(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  *(undefined4 *)(param_1 + 4) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1208 start=0xf005e304 */

undefined8 _ipc_splay_tree_pick(int param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    *param_2 = *(undefined4 *)(iVar1 + 0x10);
    *param_3 = iVar1;
  }
  return CONCAT44(param_2,(uint)(iVar1 != 0));
}
/* GHIDRADEC_FUNCTION index=1209 start=0xf005e330 */

/* WARNING: Removing unreachable block (ram,0xf005e38c) */
/* WARNING: Removing unreachable block (ram,0xf005e368) */

undefined8 _ipc_splay_tree_lookup(int *param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  iVar1 = param_1[1];
  *(int *)((int)register0x00000038 + -0xc) = iVar1;
  if (iVar1 != 0) {
    if (*param_1 != param_2) {
      sub_F005E2C8(iVar1,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
      sub_F005E1A4(param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                   (undefined *)((int)register0x00000038 + -0xc),param_1 + 2,param_1 + 3,param_1 + 4
                   ,param_1 + 5);
      iVar1 = *(int *)((int)register0x00000038 + -0xc);
      *param_1 = param_2;
      param_1[1] = iVar1;
    }
    if (param_2 != *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x10)) {
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    }
  }
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
}
/* GHIDRADEC_FUNCTION index=1210 start=0xf005e3c0 */

/* WARNING: Removing unreachable block (ram,0xf005e428) */
/* WARNING: Removing unreachable block (ram,0xf005e404) */

undefined8 _ipc_splay_tree_insert(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  uVar1 = param_1[1];
  *(uint *)((int)register0x00000038 + -0xc) = uVar1;
  if (uVar1 == 0) {
    *(undefined4 *)(param_3 + 0x18) = 0;
    *(undefined4 *)(param_3 + 0x1c) = 0;
  }
  else {
    if (*param_1 != param_2) {
      sub_F005E2C8(uVar1,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
      sub_F005E1A4(param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                   (undefined *)((int)register0x00000038 + -0xc),param_1 + 2,param_1 + 3,param_1 + 4
                   ,param_1 + 5);
    }
    if (param_2 < *(uint *)(*(int *)((int)register0x00000038 + -0xc) + 0x10)) {
      *(int *)param_1[3] = 0;
      *(undefined4 *)param_1[5] = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
    else {
      *(int *)param_1[3] = *(int *)((int)register0x00000038 + -0xc);
      *(undefined4 *)param_1[5] = 0;
    }
    *(uint *)(param_3 + 0x18) = param_1[2];
    *(uint *)(param_3 + 0x1c) = param_1[4];
  }
  *(uint *)(param_3 + 0x10) = param_2;
  param_1[1] = param_3;
  *param_1 = param_2;
  param_1[3] = (uint)(param_1 + 2);
  param_1[5] = (uint)(param_1 + 4);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1211 start=0xf005e498 */

/* WARNING: Removing unreachable block (ram,0xf005e568) */
/* WARNING: Removing unreachable block (ram,0xf005e4ec) */
/* WARNING: Removing unreachable block (ram,0xf005e51c) */
/* WARNING: Removing unreachable block (ram,0xf005e580) */
/* WARNING: Removing unreachable block (ram,0xf005e4c8) */

undefined8 _ipc_splay_tree_delete(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  iVar2 = param_1[1];
  iVar1 = *param_1;
  *(int *)((int)register0x00000038 + -0xc) = iVar2;
  if (iVar1 != param_2) {
    sub_F005E2C8(iVar2,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
    sub_F005E1A4(param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                 (undefined *)((int)register0x00000038 + -0xc),param_1 + 2,param_1 + 3,param_1 + 4,
                 param_1 + 5);
  }
  *(undefined4 *)param_1[3] = *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x18);
  *(undefined4 *)param_1[5] = *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c);
  _zfree(_ipc_tree_entry_zone,*(undefined4 *)((int)register0x00000038 + -0xc));
  iVar1 = param_1[2];
  iVar2 = param_1[4];
  *(int *)((int)register0x00000038 + -0xc) = iVar1;
  if (iVar1 == 0) {
    *(int *)((int)register0x00000038 + -0xc) = iVar2;
  }
  else if (iVar2 != 0) {
    sub_F005E1A4(0xffffffff,iVar1,(undefined *)((int)register0x00000038 + -0xc),param_1 + 2,
                 param_1 + 3,param_1 + 4,param_1 + 5);
    sub_F005E2C8(*(undefined4 *)((int)register0x00000038 + -0xc),param_1 + 2,param_1[3],param_1 + 4,
                 param_1[5]);
    *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c) = iVar2;
  }
  iVar1 = *(int *)((int)register0x00000038 + -0xc);
  param_1[1] = iVar1;
  if (iVar1 != 0) {
    *param_1 = *(int *)(iVar1 + 0x10);
    param_1[3] = (int)(param_1 + 2);
    param_1[5] = (int)(param_1 + 4);
  }
  return CONCAT44(iVar2,param_1);
}
/* GHIDRADEC_FUNCTION index=1212 start=0xf005e5c0 */

/* WARNING: Removing unreachable block (ram,0xf005e600) */
/* WARNING: Removing unreachable block (ram,0xf005e624) */
/* WARNING: Removing unreachable block (ram,0xf005e5c4) */

undefined8 _ipc_splay_tree_split(uint *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  _ipc_splay_tree_init(param_3);
  uVar1 = param_1[1];
  *(uint *)((int)register0x00000038 + -0xc) = uVar1;
  if (uVar1 != 0) {
    if (*param_1 != param_2) {
      sub_F005E2C8(uVar1,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
      sub_F005E1A4(param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                   (undefined *)((int)register0x00000038 + -0xc),param_1 + 2,param_1 + 3,param_1 + 4
                   ,param_1 + 5);
    }
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    if (*(uint *)(iVar2 + 0x10) < param_2) {
      *(undefined4 *)param_1[3] = *(undefined4 *)(iVar2 + 0x18);
      *(undefined4 *)param_1[5] = 0;
      iVar2 = *(int *)((int)register0x00000038 + -0xc);
      *(uint *)(iVar2 + 0x18) = param_1[2];
      param_3[1] = iVar2;
      *param_3 = *(undefined4 *)(iVar2 + 0x10);
      param_3[3] = param_3 + 2;
      param_3[5] = param_3 + 4;
      uVar1 = param_1[4];
      *(uint *)((int)register0x00000038 + -0xc) = uVar1;
      param_1[1] = uVar1;
      if (uVar1 != 0) {
        *param_1 = *(uint *)(uVar1 + 0x10);
        param_1[3] = (uint)(param_1 + 2);
        param_1[5] = (uint)(param_1 + 4);
      }
    }
    else {
      *(undefined4 *)param_1[3] = *(undefined4 *)(iVar2 + 0x18);
      uVar1 = *(uint *)((int)register0x00000038 + -0xc);
      *(undefined4 *)(uVar1 + 0x18) = 0;
      param_1[1] = uVar1;
      *param_1 = param_2;
      uVar1 = param_1[2];
      param_1[3] = (uint)(param_1 + 2);
      *(uint *)((int)register0x00000038 + -0xc) = uVar1;
      param_3[1] = uVar1;
      if (uVar1 != 0) {
        *param_3 = *(undefined4 *)(uVar1 + 0x10);
        param_3[3] = param_3 + 2;
        param_3[5] = param_3 + 4;
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1213 start=0xf005e6fc */

/* WARNING: Removing unreachable block (ram,0xf005e794) */
/* WARNING: Removing unreachable block (ram,0xf005e770) */
/* WARNING: Removing unreachable block (ram,0xf005e7ac) */
/* WARNING: Removing unreachable block (ram,0xf005e71c) */

undefined8 _ipc_splay_tree_join(int *param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
  undefined4 unaff_l3;
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
  iVar2 = *(int *)(param_2 + 4);
  if (iVar2 != 0) {
    sub_F005E2C8(iVar2,param_2 + 8,*(undefined4 *)(param_2 + 0xc),param_2 + 0x10,
                 *(undefined4 *)(param_2 + 0x14));
    *(undefined4 *)(param_2 + 4) = 0;
    iVar1 = param_1[1];
    *(int *)((int)register0x00000038 + -0xc) = iVar1;
    if (iVar1 == 0) {
      *(int *)((int)register0x00000038 + -0xc) = iVar2;
    }
    else {
      if (*param_1 != 0) {
        sub_F005E2C8(iVar1,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
        sub_F005E1A4(0,*(undefined4 *)((int)register0x00000038 + -0xc),
                     (undefined *)((int)register0x00000038 + -0xc),param_1 + 2,param_1 + 3,
                     param_1 + 4,param_1 + 5);
      }
      sub_F005E2C8(*(undefined4 *)((int)register0x00000038 + -0xc),param_1 + 2,param_1[3],
                   param_1 + 4,param_1[5]);
      *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18) = iVar2;
    }
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    param_1[1] = iVar2;
    *param_1 = *(int *)(iVar2 + 0x10);
    param_1[3] = (int)(param_1 + 2);
    param_1[5] = (int)(param_1 + 4);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1214 start=0xf005e7e4 */

/* WARNING: Removing unreachable block (ram,0xf005e850) */
/* WARNING: Removing unreachable block (ram,0xf005e82c) */

undefined8 _ipc_splay_tree_bounds(uint *param_1,uint param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  uVar2 = param_1[1];
  *(uint *)((int)register0x00000038 + -0xc) = uVar2;
  if (uVar2 == 0) {
    *param_3 = 0xffffffff;
    *param_4 = 0;
  }
  else {
    if (*param_1 != param_2) {
      sub_F005E2C8(uVar2,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
      sub_F005E1A4(param_2,*(undefined4 *)((int)register0x00000038 + -0xc),
                   (undefined *)((int)register0x00000038 + -0xc),param_1 + 2,param_1 + 3,param_1 + 4
                   ,param_1 + 5);
      uVar2 = *(uint *)((int)register0x00000038 + -0xc);
      *param_1 = param_2;
      param_1[1] = uVar2;
    }
    uVar2 = *(uint *)(*(int *)((int)register0x00000038 + -0xc) + 0x10);
    if (param_2 < uVar2) {
      if ((uint *)param_1[3] == param_1 + 2) {
        uVar1 = 0xffffffff;
      }
      else {
        uVar1 = ((uint *)param_1[3])[-3];
      }
      *param_3 = uVar1;
    }
    else {
      *param_3 = uVar2;
    }
    if (uVar2 < param_2) {
      if ((uint *)param_1[5] == param_1 + 4) {
        *param_4 = 0;
      }
      else {
        *param_4 = ((uint *)param_1[5])[-2];
      }
    }
    else {
      *param_4 = uVar2;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1215 start=0xf005e8d0 */

/* WARNING: Removing unreachable block (ram,0xf005e8f4) */

undefined8 _ipc_splay_traverse_start(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  iVar3 = *(int *)(param_1 + 4);
  if (iVar3 != 0) {
    sub_F005E2C8(iVar3,param_1 + 8,*(undefined4 *)(param_1 + 0xc),param_1 + 0x10,
                 *(undefined4 *)(param_1 + 0x14));
    iVar2 = 0;
    if (*(int *)(iVar3 + 0x18) != 0) {
      iVar1 = *(int *)(iVar3 + 0x18);
      *(undefined4 *)(iVar3 + 0x18) = 0;
      iVar2 = iVar3;
      while (iVar3 = iVar1, iVar1 = *(int *)(iVar3 + 0x18), iVar1 != 0) {
        *(int *)(iVar3 + 0x18) = iVar2;
        iVar2 = iVar3;
      }
    }
    *(int *)(param_1 + 8) = iVar3;
    *(int *)(param_1 + 0x10) = iVar2;
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=1216 start=0xf005e93c */

/* WARNING: Removing unreachable block (ram,0xf005e9b0) */
/* WARNING: Removing unreachable block (ram,0xf005e988) */
/* WARNING: Removing unreachable block (ram,0xf005ea60) */
/* WARNING: Removing unreachable block (ram,0xf005ea7c) */
/* WARNING: Removing unreachable block (ram,0xf005e9d0) */
/* WARNING: Removing unreachable block (ram,0xf005e9f4) */
/* WARNING: Removing unreachable block (ram,0xf005ea48) */
/* WARNING: Removing unreachable block (ram,0xf005ea1c) */

undefined8 _ipc_splay_traverse_next(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_i1;
  int iVar5;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar6;
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
  iVar3 = *(int *)(param_1 + 8);
  iVar5 = *(int *)(param_1 + 0x10);
  *(int *)((int)register0x00000038 + -0xc) = iVar3;
  if (param_2 == 0) {
    iVar3 = *(int *)((int)register0x00000038 + -0xc);
loc_F005EABC:
    iVar1 = *(int *)(iVar3 + 0x1c);
    bVar6 = iVar5 == 0;
    if (iVar1 == 0) goto loc_F005EAE0;
    *(int *)(iVar3 + 0x1c) = iVar5;
    goto loc_F005EA8C;
  }
  iVar2 = *(int *)(iVar3 + 0x18);
  iVar1 = *(int *)(iVar3 + 0x1c);
  if (iVar2 != 0) {
    if (iVar1 == 0) {
      *(int *)((int)register0x00000038 + -0xc) = iVar2;
      _zfree(_ipc_tree_entry_zone,iVar3);
      bVar6 = iVar5 == 0;
      goto loc_F005EAE0;
    }
    sub_F005E1A4(0xffffffff,iVar2,(undefined *)((int)register0x00000038 + -0xc),
                 (undefined *)((int)register0x00000038 + -0x10),
                 (undefined *)((int)register0x00000038 + -0x14),
                 (undefined *)((int)register0x00000038 + -0x18),
                 (undefined *)((int)register0x00000038 + -0x1c));
    sub_F005E2C8(*(undefined4 *)((int)register0x00000038 + -0xc),
                 (undefined *)((int)register0x00000038 + -0x10),
                 *(undefined4 *)((int)register0x00000038 + -0x14),
                 (undefined *)((int)register0x00000038 + -0x18),
                 *(undefined4 *)((int)register0x00000038 + -0x1c));
    uVar4 = _ipc_tree_entry_zone;
    *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c) = *(undefined4 *)(iVar3 + 0x1c)
    ;
    _zfree(uVar4);
    iVar3 = *(int *)((int)register0x00000038 + -0xc);
    goto loc_F005EABC;
  }
  if (iVar1 == 0) {
    if (iVar5 == 0) {
      _zfree(_ipc_tree_entry_zone,iVar3);
      *(undefined4 *)(param_1 + 4) = 0;
      uVar4 = 0;
      goto locret_F005EB2C;
    }
    if (*(uint *)(iVar3 + 0x10) < *(uint *)(iVar5 + 0x10)) {
      _zfree(_ipc_tree_entry_zone,iVar3);
      *(int *)((int)register0x00000038 + -0xc) = iVar5;
      iVar3 = *(int *)(iVar5 + 0x18);
      *(undefined4 *)(iVar5 + 0x18) = 0;
    }
    else {
      _zfree(_ipc_tree_entry_zone,iVar3);
      *(int *)((int)register0x00000038 + -0xc) = iVar5;
      iVar3 = *(int *)(iVar5 + 0x1c);
      *(undefined4 *)(iVar5 + 0x1c) = 0;
      while( true ) {
        bVar6 = iVar3 == 0;
        iVar5 = iVar3;
loc_F005EAE0:
        iVar1 = *(int *)((int)register0x00000038 + -0xc);
        if (bVar6) {
          uVar4 = 0;
          *(undefined4 *)(param_1 + 4) = *(undefined4 *)((int)register0x00000038 + -0xc);
          goto locret_F005EB2C;
        }
        if (*(uint *)(iVar1 + 0x10) < *(uint *)(iVar5 + 0x10)) break;
        *(int *)((int)register0x00000038 + -0xc) = iVar5;
        iVar3 = *(int *)(iVar5 + 0x1c);
        *(int *)(iVar5 + 0x1c) = iVar1;
      }
      *(int *)((int)register0x00000038 + -0xc) = iVar5;
      iVar3 = *(int *)(iVar5 + 0x18);
      *(int *)(iVar5 + 0x18) = iVar1;
    }
    uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  else {
    *(int *)((int)register0x00000038 + -0xc) = iVar1;
    _zfree(_ipc_tree_entry_zone,iVar3);
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    iVar3 = iVar5;
    while( true ) {
      iVar1 = *(int *)(iVar2 + 0x18);
      uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
      if (iVar1 == 0) break;
      *(int *)(iVar2 + 0x18) = iVar3;
      iVar3 = iVar2;
loc_F005EA8C:
      *(int *)((int)register0x00000038 + -0xc) = iVar1;
      iVar2 = *(int *)((int)register0x00000038 + -0xc);
    }
  }
  *(int *)(param_1 + 0x10) = iVar3;
  *(undefined4 *)(param_1 + 8) = uVar4;
  iVar5 = iVar3;
locret_F005EB2C:
  return CONCAT44(iVar5,uVar4);
}
/* GHIDRADEC_FUNCTION index=1217 start=0xf005eb34 */

undefined8 _ipc_splay_traverse_finish(undefined4 *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  if (param_1[1] != 0) {
    *param_1 = *(undefined4 *)(param_1[1] + 0x10);
    param_1[3] = param_1 + 2;
    param_1[5] = param_1 + 4;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1218 start=0xf005eb68 */

/* WARNING: Removing unreachable block (ram,0xf005ebb0) */
/* WARNING: Removing unreachable block (ram,0xf005ec00) */
/* WARNING: Removing unreachable block (ram,0xf005eb70) */

undefined8 _ipc_table_fill(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l3;
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
  bool bVar7;
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
  .umul(param_3,param_4);
  uVar6 = 0;
  uVar3 = 1;
  uVar1 = _page_size;
  if (param_2 != 0) {
    iVar4 = 0;
    do {
      uVar1 = _page_size;
      if (_page_size <= uVar3) break;
      bVar7 = uVar6 < param_2;
      if (!bVar7) {
        uVar1 = uVar3;
        .udiv(uVar3,param_4);
        *(uint *)(iVar4 + param_1) = uVar1;
        iVar4 = iVar4 + 4;
        uVar6 = uVar6 + 1;
        bVar7 = uVar6 < param_2;
      }
      uVar3 = uVar3 << 1;
      uVar1 = _page_size;
    } while (bVar7);
  }
  do {
    if (param_2 <= uVar6) {
      return CONCAT44(param_2,param_1);
    }
    uVar5 = 0;
    iVar4 = uVar6 << 2;
    do {
      if (param_2 <= uVar6) break;
      if (param_3 <= uVar3) {
        uVar2 = uVar3;
        .udiv(uVar3,param_4);
        *(uint *)(iVar4 + param_1) = uVar2;
        iVar4 = iVar4 + 4;
        uVar6 = uVar6 + 1;
      }
      uVar5 = uVar5 + 1;
      uVar3 = uVar3 + uVar1;
    } while (uVar5 < 0xf);
    uVar1 = uVar1 << 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1219 start=0xf005ec38 */

/* WARNING: Removing unreachable block (ram,0xf005ec88) */
/* WARNING: Removing unreachable block (ram,0xf005ec60) */
/* WARNING: Removing unreachable block (ram,0xf005eca4) */
/* WARNING: Removing unreachable block (ram,0xf005ec44) */

undefined8 _ipc_table_init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  iVar1 = _ipc_table_entries_size << 2;
  _kalloc();
  _ipc_table_entries = iVar1;
  _ipc_table_fill();
  iVar2 = _ipc_table_entries_size * 4 + _ipc_table_entries;
  iVar1 = _ipc_table_dnrequests_size << 2;
  *(undefined4 *)(iVar2 + -4) = *(undefined4 *)(iVar2 + -8);
  _kalloc();
  _ipc_table_dnrequests = iVar1;
  _ipc_table_fill();
  *(undefined4 *)(_ipc_table_dnrequests_size * 4 + _ipc_table_dnrequests + -4) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1220 start=0xf005ecc8 */

/* WARNING: Removing unreachable block (ram,0xf005ece4) */
/* WARNING: Removing unreachable block (ram,0xf005ecf8) */

undefined8 _ipc_table_alloc(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  if (param_1 < _page_size) {
    _kalloc();
    *(uint *)((int)register0x00000038 + -0xc) = param_1;
  }
  else {
    iVar1 = _kalloc_map;
    _kmem_alloc(_kalloc_map,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 != 0) {
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    }
  }
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
}
/* GHIDRADEC_FUNCTION index=1221 start=0xf005ed18 */

/* WARNING: Removing unreachable block (ram,0xf005ed30) */

undefined8 _ipc_table_realloc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  iVar1 = _kalloc_map;
  _kmem_realloc(_kalloc_map,param_2,param_1,(undefined *)((int)register0x00000038 + -0xc),param_3);
  if (iVar1 != 0) {
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  }
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
}
/* GHIDRADEC_FUNCTION index=1222 start=0xf005ed50 */

/* WARNING: Removing unreachable block (ram,0xf005ed70) */
/* WARNING: Removing unreachable block (ram,0xf005ed80) */

undefined8 _ipc_table_free(uint param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  if (param_1 < _page_size) {
    _kfree(param_2,param_1);
  }
  else {
    _kmem_free(_kalloc_map);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1223 start=0xf005ed90 */

undefined8 _ipc_thread_enqueue(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  iVar2 = *param_1;
  if (iVar2 == 0) {
    *param_1 = param_2;
  }
  else {
    iVar1 = *(int *)(iVar2 + 0x94);
    *(int *)(param_2 + 0x90) = iVar2;
    *(int *)(param_2 + 0x94) = iVar1;
    *(int *)(iVar2 + 0x94) = param_2;
    *(int *)(iVar1 + 0x90) = param_2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1224 start=0xf005edc4 */

undefined8 _ipc_thread_dequeue(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  iVar3 = *param_1;
  if (iVar3 != 0) {
    iVar2 = *(int *)(iVar3 + 0x90);
    if (iVar2 == iVar3) {
      *param_1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar3 + 0x94);
      *param_1 = iVar2;
      *(int *)(iVar2 + 0x94) = iVar1;
      *(int *)(iVar1 + 0x90) = iVar2;
      *(int *)(iVar3 + 0x90) = iVar3;
      *(int *)(iVar3 + 0x94) = iVar3;
    }
  }
  return CONCAT44(param_1,iVar3);
}
/* GHIDRADEC_FUNCTION index=1225 start=0xf005ee10 */

undefined8 _ipc_thread_rmqueue(int *param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar2;
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
  iVar1 = *(int *)(param_2 + 0x90);
  iVar2 = *(int *)(param_2 + 0x94);
  if (iVar1 == param_2) {
    *param_1 = 0;
  }
  else {
    if (*param_1 == param_2) {
      *param_1 = iVar1;
    }
    *(int *)(iVar1 + 0x94) = iVar2;
    *(int *)(iVar2 + 0x90) = iVar1;
    *(int *)(param_2 + 0x90) = param_2;
    *(int *)(param_2 + 0x94) = param_2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1226 start=0xf005ee54 */

/* WARNING: Removing unreachable block (ram,0xf005ee70) */

undefined8 _mach_port_get_srights(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  if (param_1 == 0) {
    param_1 = 0x10;
  }
  else {
    _ipc_object_translate(param_1,param_2,1,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == 0) {
      puVar1 = *(undefined4 **)((int)register0x00000038 + -0xc);
      param_1 = 0;
      *puVar1 = 0;
      *param_3 = puVar1[7];
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1227 start=0xf005eea0 */

/* WARNING: Removing unreachable block (ram,0xf005eef4) */
/* WARNING: Removing unreachable block (ram,0xf005efb4) */
/* WARNING: Removing unreachable block (ram,0xf005ef90) */
/* WARNING: Removing unreachable block (ram,0xf005ef50) */
/* WARNING: Removing unreachable block (ram,0xf005ef14) */
/* WARNING: Removing unreachable block (ram,0xf005eecc) */

undefined8 _host_ipc_hash_info(int param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
  uint uVar6;
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
  uVar4 = 0;
  if (param_1 == 0) {
    uVar5 = 0x16;
    goto locret_F005EFCC;
  }
  uVar3 = *param_2;
  uVar6 = *param_3;
  while( true ) {
    uVar1 = uVar3;
    _ipc_hash_info(uVar3,uVar6);
    if (uVar1 <= uVar6) break;
    if (uVar3 != *param_2) {
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar4);
    }
    uVar4 = uVar1 * 4 + _page_mask & ~_page_mask;
    iVar2 = _ipc_kernel_map;
    _kmem_alloc_pageable(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar4);
    uVar3 = *(uint *)((int)register0x00000038 + -0xc);
    if (iVar2 != 0) {
      uVar5 = 6;
      goto locret_F005EFCC;
    }
    uVar6 = uVar4 >> 2;
  }
  if (uVar3 == *param_2) {
loc_F005EFC4:
    *param_3 = uVar1;
  }
  else {
    if (uVar1 != 0) {
      uVar3 = uVar1 * 4 + _page_mask & ~_page_mask;
      if (uVar3 != uVar4) {
        _kmem_free(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc) + uVar3,uVar4 - uVar3);
      }
      _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),_ipc_soft_map,uVar3,1
               ,(undefined *)((int)register0x00000038 + -0x10));
      *param_2 = *(uint *)((int)register0x00000038 + -0x10);
      goto loc_F005EFC4;
    }
    _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar4);
    *param_3 = 0;
  }
  uVar5 = 0;
locret_F005EFCC:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=1228 start=0xf005efd4 */

/* WARNING: Removing unreachable block (ram,0xf005f02c) */
/* WARNING: Removing unreachable block (ram,0xf005f0ec) */
/* WARNING: Removing unreachable block (ram,0xf005f0c8) */
/* WARNING: Removing unreachable block (ram,0xf005f088) */
/* WARNING: Removing unreachable block (ram,0xf005f04c) */
/* WARNING: Removing unreachable block (ram,0xf005f004) */

undefined8 _host_ipc_marequest_info(int param_1,uint param_2,int *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
  uint uVar6;
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
  uVar4 = 0;
  if (param_1 == 0) {
    uVar5 = 0x16;
    goto locret_F005F104;
  }
  iVar3 = *param_3;
  uVar6 = *param_4;
  while( true ) {
    uVar1 = param_2;
    _ipc_marequest_info(param_2,iVar3,uVar6);
    if (uVar1 <= uVar6) break;
    if (iVar3 != *param_3) {
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar4);
    }
    uVar4 = uVar1 * 4 + _page_mask & ~_page_mask;
    iVar2 = _ipc_kernel_map;
    _kmem_alloc_pageable(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar4);
    iVar3 = *(int *)((int)register0x00000038 + -0xc);
    if (iVar2 != 0) {
      uVar5 = 6;
      goto locret_F005F104;
    }
    uVar6 = uVar4 >> 2;
  }
  if (iVar3 == *param_3) {
loc_F005F0FC:
    *param_4 = uVar1;
  }
  else {
    if (uVar1 != 0) {
      uVar6 = uVar1 * 4 + _page_mask & ~_page_mask;
      if (uVar6 != uVar4) {
        _kmem_free(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc) + uVar6,uVar4 - uVar6);
      }
      _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),_ipc_soft_map,uVar6,1
               ,(undefined *)((int)register0x00000038 + -0x10));
      *param_3 = *(int *)((int)register0x00000038 + -0x10);
      goto loc_F005F0FC;
    }
    _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar4);
    *param_4 = 0;
  }
  uVar5 = 0;
locret_F005F104:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=1229 start=0xf005f10c */

/* WARNING: Removing unreachable block (ram,0xf005f1a8) */
/* WARNING: Removing unreachable block (ram,0xf005f30c) */
/* WARNING: Removing unreachable block (ram,0xf005f298) */
/* WARNING: Removing unreachable block (ram,0xf005f238) */
/* WARNING: Removing unreachable block (ram,0xf005f5c4) */
/* WARNING: Removing unreachable block (ram,0xf005f624) */
/* WARNING: Removing unreachable block (ram,0xf005f504) */
/* WARNING: Removing unreachable block (ram,0xf005f560) */
/* WARNING: Removing unreachable block (ram,0xf005f4d0) */
/* WARNING: Removing unreachable block (ram,0xf005f3f4) */
/* WARNING: Removing unreachable block (ram,0xf005f4bc) */
/* WARNING: Removing unreachable block (ram,0xf005f548) */
/* WARNING: Removing unreachable block (ram,0xf005f584) */
/* WARNING: Removing unreachable block (ram,0xf005f60c) */
/* WARNING: Removing unreachable block (ram,0xf005f648) */
/* WARNING: Removing unreachable block (ram,0xf005f210) */
/* WARNING: Removing unreachable block (ram,0xf005f26c) */
/* WARNING: Removing unreachable block (ram,0xf005f2c8) */
/* WARNING: Removing unreachable block (ram,0xf005f2f4) */
/* WARNING: Removing unreachable block (ram,0xf005f1c4) */
/* WARNING: Removing unreachable block (ram,0xf005f168) */

undefined8
_mach_port_space_info
          (int param_1,uint *param_2,undefined4 param_3,undefined4 param_4,int *param_5,
          uint *param_6)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar7;
  uint uVar8;
  undefined4 unaff_l3;
  uint uVar9;
  undefined4 unaff_l4;
  uint uVar10;
  undefined4 unaff_l5;
  uint uVar11;
  undefined4 unaff_l6;
  uint uVar12;
  undefined4 unaff_l7;
  uint uVar13;
  undefined4 unaff_i0;
  undefined4 uVar14;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar15;
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
  *(uint **)((int)register0x00000038 + -0x1c) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x24) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = param_4;
  uVar9 = 0;
  uVar13 = 0;
  if (param_1 == 0) {
loc_F005F12C:
    uVar14 = 0x10;
  }
  else {
    iVar15 = *param_5;
    uVar10 = *param_6;
    param_2 = (uint *)**(undefined4 **)((int)register0x00000038 + -0x24);
    uVar12 = **(uint **)((int)register0x00000038 + -0x2c);
loc_F005F158:
    do {
      do {
        do {
        } while (*(int *)(param_1 + 8) != 0);
        piVar2 = (int *)(param_1 + 8);
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      if (*(int *)(param_1 + 0xc) == 0) {
        piVar2 = *(int **)((int)register0x00000038 + -0x24);
        *(undefined4 *)(param_1 + 8) = 0;
        if (param_2 != (uint *)*piVar2) {
          _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar9);
        }
        if (iVar15 == *param_5) goto loc_F005F12C;
        _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),uVar13);
        uVar14 = 0x10;
        goto locret_F005F660;
      }
      uVar11 = *(uint *)(param_1 + 0x18);
      uVar8 = *(uint *)(param_1 + 0x38);
      if ((uVar11 <= uVar12) &&
         (puVar1 = *(undefined4 **)((int)register0x00000038 + -0x1c), uVar8 <= uVar10)) {
        *puVar1 = 0xff;
        puVar1[1] = *(undefined4 *)(param_1 + 0x18);
        puVar1[2] = **(undefined4 **)(param_1 + 0x1c);
        puVar1[3] = *(undefined4 *)(param_1 + 0x38);
        puVar1[4] = *(undefined4 *)(param_1 + 0x3c);
        puVar1[5] = *(undefined4 *)(param_1 + 0x40);
        uVar12 = *(uint *)(param_1 + 0x18);
        uVar10 = 0;
        puVar5 = *(uint **)(param_1 + 0x14);
        puVar4 = param_2;
        if (uVar12 != 0) {
          do {
            uVar6 = *puVar5;
            *puVar4 = uVar10 << 8 | uVar6 >> 0x18;
            puVar4[1] = uVar6 >> 0x17 & 1;
            puVar4[2] = uVar6 >> 0x16 & 1;
            puVar4[3] = uVar6 >> 0x15 & 1;
            puVar4[4] = uVar6 & 0x1f0000;
            puVar4[5] = uVar6 & 0xffff;
            puVar4[6] = puVar5[1];
            uVar10 = uVar10 + 1;
            puVar4[7] = puVar5[2];
            puVar4[8] = puVar5[3];
            puVar5 = puVar5 + 4;
            puVar4 = puVar4 + 9;
          } while (uVar10 < uVar12);
        }
        puVar4 = (uint *)(param_1 + 0x20);
        _ipc_splay_traverse_start();
        if (puVar4 != (uint *)0x0) {
          iVar7 = 0;
          uVar12 = *puVar4;
          iVar3 = iVar15;
          while( true ) {
            *(uint *)(iVar15 + iVar7) = puVar4[4];
            *(uint *)(iVar3 + 4) = uVar12 >> 0x17 & 1;
            *(uint *)(iVar3 + 8) = uVar12 >> 0x16 & 1;
            *(uint *)(iVar3 + 0xc) = uVar12 >> 0x15 & 1;
            *(uint *)(iVar3 + 0x10) = uVar12 & 0x1f0000;
            *(uint *)(iVar3 + 0x14) = uVar12 & 0xffff;
            *(uint *)(iVar3 + 0x18) = puVar4[1];
            *(uint *)(iVar3 + 0x1c) = puVar4[2];
            iVar7 = iVar7 + 0x2c;
            *(uint *)(iVar3 + 0x20) = puVar4[3];
            if (puVar4[6] == 0) {
              *(undefined4 *)(iVar3 + 0x24) = 0;
            }
            else {
              *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(puVar4[6] + 0x10);
            }
            if (puVar4[7] == 0) {
              *(undefined4 *)(iVar3 + 0x28) = 0;
            }
            else {
              *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(puVar4[7] + 0x10);
            }
            puVar4 = (uint *)(param_1 + 0x20);
            _ipc_splay_traverse_next(puVar4,0);
            if (puVar4 == (uint *)0x0) break;
            uVar12 = *puVar4;
            iVar3 = iVar3 + 0x2c;
          }
        }
        _ipc_splay_traverse_finish(param_1 + 0x20);
        piVar2 = *(int **)((int)register0x00000038 + -0x24);
        *(undefined4 *)(param_1 + 8) = 0;
        if (param_2 == (uint *)*piVar2) {
loc_F005F598:
          **(uint **)((int)register0x00000038 + -0x2c) = uVar11;
        }
        else {
          if (uVar11 != 0) {
            param_2 = (uint *)(uVar11 * 0x24);
            uVar12 = (int)param_2 + _page_mask & ~_page_mask;
            if (uVar12 != uVar9) {
              _kmem_free(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc) + uVar12,
                         uVar9 - uVar12);
            }
            if ((int)param_2 - uVar12 != 0) {
              _bzero(*(int *)((int)register0x00000038 + -0xc) + (int)param_2,uVar12 + uVar11 * -0x24
                    );
            }
            _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),_ipc_soft_map,
                     uVar12,1,(undefined *)((int)register0x00000038 + -0x14));
            **(undefined4 **)((int)register0x00000038 + -0x24) =
                 *(undefined4 *)((int)register0x00000038 + -0x14);
            goto loc_F005F598;
          }
          _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar9);
          **(undefined4 **)((int)register0x00000038 + -0x2c) = 0;
        }
        if (iVar15 == *param_5) {
loc_F005F658:
          *param_6 = uVar8;
        }
        else {
          if (uVar8 != 0) {
            param_2 = (uint *)(uVar8 * 0x2c);
            uVar9 = (int)param_2 + _page_mask & ~_page_mask;
            if (uVar9 != uVar13) {
              _kmem_free(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0x10) + uVar9,
                         uVar13 - uVar9);
            }
            if ((int)param_2 - uVar9 != 0) {
              _bzero(*(int *)((int)register0x00000038 + -0x10) + (int)param_2,uVar9 + uVar8 * -0x2c)
              ;
            }
            _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),_ipc_soft_map,
                     uVar9,1,(undefined *)((int)register0x00000038 + -0x18));
            *param_5 = *(int *)((int)register0x00000038 + -0x18);
            goto loc_F005F658;
          }
          _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),uVar13);
          *param_6 = 0;
        }
        uVar14 = 0;
        goto locret_F005F660;
      }
      *(undefined4 *)(param_1 + 8) = 0;
      if (uVar12 < uVar11) {
        if (param_2 != (uint *)**(int **)((int)register0x00000038 + -0x24)) {
          _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar9);
        }
        uVar9 = uVar11 * 0x24 + _page_mask & ~_page_mask;
        iVar3 = _ipc_kernel_map;
        _kmem_alloc(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar9);
        param_2 = *(uint **)((int)register0x00000038 + -0xc);
        if (iVar3 != 0) {
          if (iVar15 == *param_5) goto loc_F005F2FC;
          uVar14 = *(undefined4 *)((int)register0x00000038 + -0x10);
          uVar9 = uVar13;
          goto loc_F005F2F4;
        }
        uVar12 = uVar9;
        .udiv(uVar9,0x24);
      }
    } while (uVar8 <= uVar10);
    if (iVar15 != *param_5) {
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),uVar13);
    }
    uVar13 = uVar8 * 0x2c + _page_mask & ~_page_mask;
    iVar15 = _ipc_kernel_map;
    _kmem_alloc(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0x10),uVar13);
    if (iVar15 == 0) {
      iVar15 = *(int *)((int)register0x00000038 + -0x10);
      uVar10 = uVar13;
      .udiv(uVar13,0x2c);
      goto loc_F005F158;
    }
    if (param_2 != (uint *)**(int **)((int)register0x00000038 + -0x24)) {
      uVar14 = *(undefined4 *)((int)register0x00000038 + -0xc);
loc_F005F2F4:
      _kmem_free(_ipc_kernel_map,uVar14,uVar9);
    }
loc_F005F2FC:
    uVar14 = 6;
  }
locret_F005F660:
  return CONCAT44(param_2,uVar14);
}
/* GHIDRADEC_FUNCTION index=1230 start=0xf005f668 */

/* WARNING: Removing unreachable block (ram,0xf005f684) */

undefined8 _mach_port_dnrequest_info(int param_1,undefined4 param_2,uint *param_3,int *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  if (param_1 == 0) {
    param_1 = 0x10;
  }
  else {
    _ipc_object_translate(param_1,param_2,1,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == 0) {
      puVar1 = *(undefined4 **)((int)register0x00000038 + -0xc);
      iVar3 = puVar1[0xb];
      if (iVar3 == 0) {
        uVar5 = 0;
        iVar4 = 0;
      }
      else {
        uVar2 = 1;
        uVar5 = **(uint **)(iVar3 + 4);
        iVar4 = 0;
        if (1 < uVar5) {
          do {
            if (*(int *)(iVar3 + 0xc) != 0) {
              iVar4 = iVar4 + 1;
            }
            uVar2 = uVar2 + 1;
            iVar3 = iVar3 + 8;
          } while (uVar2 < uVar5);
        }
        puVar1 = *(undefined4 **)((int)register0x00000038 + -0xc);
      }
      param_1 = 0;
      *puVar1 = 0;
      *param_3 = uVar5;
      *param_4 = iVar4;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1231 start=0xf005f70c */

/* WARNING: Removing unreachable block (ram,0xf005f764) */
/* WARNING: Removing unreachable block (ram,0xf005f718) */

undefined8 _mach_port_kernel_object(int param_1,int *param_2,uint *param_3,int *param_4)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  iVar2 = param_1;
  _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar2 == 0) {
    if ((**(uint **)((int)register0x00000038 + -0xc) & 0x30000) == 0) {
      *(undefined4 *)(param_1 + 8) = 0;
      iVar2 = 0x11;
    }
    else {
      param_2 = (int *)(*(uint **)((int)register0x00000038 + -0xc))[1];
      do {
        do {
        } while (*param_2 != 0);
        piVar1 = param_2;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      *(undefined4 *)(param_1 + 8) = 0;
      if (param_2[2] < 0) {
        *param_3 = param_2[2] & 0xffff;
        *param_4 = param_2[5];
        *param_2 = 0;
        iVar2 = 0;
      }
      else {
        *param_2 = 0;
        iVar2 = 0x11;
      }
    }
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1232 start=0xf005f7bc */

/* WARNING: Removing unreachable block (ram,0xf005f928) */
/* WARNING: Removing unreachable block (ram,0xf005f8d0) */
/* WARNING: Removing unreachable block (ram,0xf005f910) */
/* WARNING: Removing unreachable block (ram,0xf005f88c) */
/* WARNING: Removing unreachable block (ram,0xf005f8f0) */
/* WARNING: Removing unreachable block (ram,0xf005f944) */
/* WARNING: Removing unreachable block (ram,0xf005f7e4) */
/* WARNING: Removing unreachable block (ram,0xf005f83c) */

undefined8 _mach_msg_send(uint param_1,uint param_2,undefined4 param_3,uint param_4,int param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 uVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar6;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar7;
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
  uVar6 = *(uint *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar5 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  uVar3 = param_1;
  _ipc_kmsg_get(param_1,param_3,0,(undefined *)((int)register0x00000038 + -0xc));
  if (uVar3 != 0) goto locret_F005F94C;
  if ((param_2 & 0x80) == 0) {
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    iVar2 = 0;
loc_F005F83C:
    _ipc_kmsg_copyin(iVar1,uVar6,uVar5,iVar2);
  }
  else {
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    iVar2 = param_5;
    if (param_5 != 0) goto loc_F005F83C;
    iVar1 = 0x1000000b;
  }
  iVar2 = *(int *)((int)register0x00000038 + -0xc);
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar2 + 8);
    if (iVar1 < 1) {
      _ipc_kmsg_free();
      return CONCAT44(iVar1,iVar2);
    }
    _kfree();
    return CONCAT44(iVar1,iVar2);
  }
  if ((param_2 & 0x20) == 0) {
    uVar3 = *(uint *)((int)register0x00000038 + -0xc);
    _ipc_mqueue_send(uVar3,param_2 & 0x10,param_4,0);
    bVar7 = uVar3 == 0;
  }
  else {
    uVar3 = *(uint *)((int)register0x00000038 + -0xc);
    _ipc_mqueue_send(uVar3,0x10,param_4 & -(uint)((param_2 & 0x10) != 0),0);
    bVar7 = uVar3 == 0;
    if (uVar3 == 0x10000004) {
      if (param_5 == 0) {
        uVar3 = 0x1000000b;
      }
      else {
        uVar3 = uVar6;
        _ipc_marequest_create
                  (uVar6,*(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c),param_5,
                   *(int *)((int)register0x00000038 + -0xc) + 0xc);
      }
      bVar7 = false;
      if (uVar3 == 0) {
        _ipc_mqueue_send(*(undefined4 *)((int)register0x00000038 + -0xc),0x10000,0,0);
        uVar3 = 0x10000005;
        goto locret_F005F94C;
      }
    }
  }
  if (!bVar7) {
    uVar4 = *(uint *)((int)register0x00000038 + -0xc);
    _ipc_kmsg_copyout_pseudo(uVar4,uVar6,uVar5);
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    uVar3 = uVar3 | uVar4;
    _ipc_kmsg_put(param_1,iVar2,*(int *)(iVar2 + 0x18) + *(int *)(iVar2 + 0x10));
  }
locret_F005F94C:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1233 start=0xf005f954 */

/* WARNING: Removing unreachable block (ram,0xf005fb50) */
/* WARNING: Removing unreachable block (ram,0xf005fb6c) */
/* WARNING: Removing unreachable block (ram,0xf005fa18) */
/* WARNING: Removing unreachable block (ram,0xf005f9dc) */
/* WARNING: Removing unreachable block (ram,0xf005fa90) */
/* WARNING: Removing unreachable block (ram,0xf005fa58) */
/* WARNING: Removing unreachable block (ram,0xf005fa64) */
/* WARNING: Removing unreachable block (ram,0xf005faa0) */
/* WARNING: Removing unreachable block (ram,0xf005f9e8) */
/* WARNING: Removing unreachable block (ram,0xf005faf4) */
/* WARNING: Removing unreachable block (ram,0xf005fb40) */
/* WARNING: Removing unreachable block (ram,0xf005fb34) */
/* WARNING: Removing unreachable block (ram,0xf005f97c) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf005f97c */
/* WARNING: Restarted to delay deadcode elimination for space: register */

uint _mach_msg_receive(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  qword in_o0_1;
  undefined8 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
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
  
  iVar4 = _active_threads;
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
  uVar1 = (uint)(in_o0_1 >> 0x20);
  uVar5 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  _ipc_mqueue_copyin(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88),(int)in_o0_1,
                     (undefined *)((int)register0x00000038 + -0xc),
                     (undefined *)((int)register0x00000038 + -0x10));
  if (uVar1 != 0) {
    return uVar1;
  }
  *(undefined4 *)(iVar4 + 0xc4) = 0;
  *(int *)(iVar4 + 200) = (int)in_o0_1;
  *(uint *)(iVar4 + 0xcc) = param_1;
  *(undefined4 *)(iVar4 + 0xd0) = param_3;
  *(int *)(iVar4 + 0xd4) = param_4;
  uVar2 = *(undefined8 *)((int)register0x00000038 + -0x10);
  uVar1 = (uint)((qword)uVar2 >> 0x20);
  *(uint *)(iVar4 + 0xd8) = uVar1;
  uVar3 = (undefined4)uVar2;
  *(undefined4 *)(iVar4 + 0xdc) = uVar3;
  if ((in_o0_1 & 0x800) == 0) {
    _ipc_mqueue_receive(uVar3,uVar3,0xffffffff,param_3,0,_mach_msg_receive_continue);
    _ipc_object_release(*(undefined4 *)((int)register0x00000038 + -0x10));
    iVar4 = *(int *)((int)register0x00000038 + -0x14);
    if (uVar1 != 0) {
      return uVar1;
    }
    *(undefined4 *)(iVar4 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x18);
    if (param_1 < *(uint *)(iVar4 + 0x18)) {
      _ipc_kmsg_copyout_dest(iVar4);
      _ipc_kmsg_put(0,uVar3,0x18);
      return 0x10004004;
    }
  }
  else {
    _ipc_mqueue_receive(uVar3,uVar3,param_1,param_3,0,_mach_msg_receive_continue);
    _ipc_object_release(*(undefined4 *)((int)register0x00000038 + -0x10));
    if (uVar1 != 0) {
      if (uVar1 != 0x10004004) {
        return uVar1;
      }
      *(undefined4 *)((int)register0x00000038 + -0x1c) =
           *(undefined4 *)((int)register0x00000038 + -0x14);
      _copyout((undefined *)((int)register0x00000038 + -0x1c),uVar3,4);
      return 0x10004004;
    }
    uVar2 = *(undefined8 *)((int)register0x00000038 + -0x18);
    *(int *)((int)uVar2 + 0x24) = (int)((qword)uVar2 >> 0x20);
  }
  uVar3 = (undefined4)uVar2;
  uVar1 = (uint)((qword)uVar2 >> 0x20);
  if ((in_o0_1 & 0x200) == 0) {
    param_4 = 0;
  }
  else if (param_4 == 0) {
    uVar6 = 0x10004007;
    goto loc_F005FB00;
  }
  _ipc_kmsg_copyout(uVar1,uVar3,uVar5,param_4);
  uVar6 = uVar1;
loc_F005FB00:
  if (uVar6 == 0) {
    _ipc_kmsg_put(0,uVar3,*(int *)(*(int *)((int)register0x00000038 + -0x14) + 0x18) +
                          *(int *)(*(int *)((int)register0x00000038 + -0x14) + 0x10));
  }
  else {
    uVar1 = uVar6;
    if ((uVar6 & 0xffffc3ff) == 0x1000400c) {
      _ipc_kmsg_put(0,uVar3,*(int *)(*(int *)((int)register0x00000038 + -0x14) + 0x18) +
                            *(int *)(*(int *)((int)register0x00000038 + -0x14) + 0x10));
    }
    else {
      _ipc_kmsg_copyout_dest();
      _ipc_kmsg_put(0,uVar3,0x18);
    }
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1234 start=0xf005fb80 */

/* WARNING: Removing unreachable block (ram,0xf005fd80) */
/* WARNING: Removing unreachable block (ram,0xf005fd60) */
/* WARNING: Removing unreachable block (ram,0xf005fd04) */
/* WARNING: Removing unreachable block (ram,0xf005fc1c) */
/* WARNING: Removing unreachable block (ram,0xf005fbe0) */
/* WARNING: Removing unreachable block (ram,0xf005fcb0) */
/* WARNING: Removing unreachable block (ram,0xf005fc7c) */
/* WARNING: Removing unreachable block (ram,0xf005fc68) */
/* WARNING: Removing unreachable block (ram,0xf005fca0) */
/* WARNING: Removing unreachable block (ram,0xf005fcbc) */
/* WARNING: Removing unreachable block (ram,0xf005fbec) */
/* WARNING: Removing unreachable block (ram,0xf005fc24) */
/* WARNING: Removing unreachable block (ram,0xf005fd4c) */
/* WARNING: Removing unreachable block (ram,0xf005fd68) */
/* WARNING: Removing unreachable block (ram,0xf005fd88) */
/* WARNING: Removing unreachable block (ram,0xf005fc5c) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf005fc5c */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int _mach_msg_receive_continue(void)

{
  int iVar1;
  undefined8 in_o0_1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 uVar5;
  undefined4 unaff_l3;
  undefined4 uVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar7;
  undefined4 unaff_l6;
  int iVar8;
  undefined4 unaff_l7;
  undefined4 uVar9;
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
  undefined auStackX_0 [92];
  
  iVar1 = (int)((qword)in_o0_1 >> 0x20);
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
  uVar5 = *(undefined4 *)(_active_threads + 0xc4);
  uVar4 = *(uint *)(_active_threads + 200);
  uVar7 = *(uint *)(_active_threads + 0xcc);
  iVar8 = *(int *)(_active_threads + 0xd4);
  uVar6 = *(undefined4 *)(_active_threads + 0xd8);
  uVar9 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  uVar2 = (undefined4)in_o0_1;
  if ((uVar4 & 0x800) == 0) {
    _ipc_mqueue_receive(*(undefined4 *)(_active_threads + 0xdc),uVar2,0xffffffff,
                        *(undefined4 *)(_active_threads + 0xd0),1,_mach_msg_receive_continue);
    _ipc_object_release(uVar6);
    iVar3 = *(int *)((int)register0x00000038 + -0xc);
    if (iVar1 != 0) {
      _thread_syscall_return(iVar1);
      iVar3 = *(int *)((int)register0x00000038 + -0xc);
    }
    *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x10);
    if (uVar7 < *(uint *)(iVar3 + 0x18)) {
      _ipc_kmsg_copyout_dest(iVar3);
      _ipc_kmsg_put(uVar5,uVar2,0x18);
      _thread_syscall_return(0x10004004);
    }
  }
  else {
    _ipc_mqueue_receive(*(undefined4 *)(_active_threads + 0xdc),uVar2,uVar7,
                        *(undefined4 *)(_active_threads + 0xd0),1,_mach_msg_receive_continue);
    _ipc_object_release(uVar6);
    if (iVar1 != 0) {
      if (iVar1 == 0x10004004) {
        *(undefined4 *)((int)register0x00000038 + -0x14) =
             *(undefined4 *)((int)register0x00000038 + -0xc);
        _copyout((undefined *)((int)register0x00000038 + -0x14),uVar2,4);
      }
      _thread_syscall_return(iVar1);
    }
    in_o0_1 = *(undefined8 *)((int)register0x00000038 + -0x10);
    *(int *)((int)in_o0_1 + 0x24) = (int)((qword)in_o0_1 >> 0x20);
  }
  uVar2 = (undefined4)in_o0_1;
  if ((uVar4 & 0x200) == 0) {
    iVar8 = 0;
  }
  else if (iVar8 == 0) {
    uVar4 = 0x10004007;
    goto loc_F005FD10;
  }
  uVar4 = (uint)((qword)in_o0_1 >> 0x20);
  _ipc_kmsg_copyout(uVar4,uVar2,uVar9,iVar8);
loc_F005FD10:
  if (uVar4 != 0) {
    if ((uVar4 & 0xffffc3ff) == 0x1000400c) {
      iVar8 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18) +
              *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x10);
    }
    else {
      _ipc_kmsg_copyout_dest(*(undefined4 *)((int)register0x00000038 + -0xc));
      iVar8 = 0x18;
    }
    _ipc_kmsg_put(uVar5,uVar2,iVar8);
    _thread_syscall_return(uVar4);
  }
  _ipc_kmsg_put(uVar5,uVar2,
                *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18) +
                *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x10));
  _thread_syscall_return();
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1235 start=0xf005fd98 */

/* WARNING: Removing unreachable block (ram,0xf0061038) */
/* WARNING: Removing unreachable block (ram,0xf0060dc4) */
/* WARNING: Removing unreachable block (ram,0xf00608c4) */
/* WARNING: Removing unreachable block (ram,0xf0060db0) */
/* WARNING: Removing unreachable block (ram,0xf0060d94) */
/* WARNING: Removing unreachable block (ram,0xf0060d30) */
/* WARNING: Removing unreachable block (ram,0xf0060d14) */
/* WARNING: Removing unreachable block (ram,0xf0060890) */
/* WARNING: Removing unreachable block (ram,0xf0060830) */
/* WARNING: Removing unreachable block (ram,0xf00606f0) */
/* WARNING: Removing unreachable block (ram,0xf00605f8) */
/* WARNING: Removing unreachable block (ram,0xf0060ce0) */
/* WARNING: Removing unreachable block (ram,0xf0060cc0) */
/* WARNING: Removing unreachable block (ram,0xf0060c60) */
/* WARNING: Removing unreachable block (ram,0xf0060548) */
/* WARNING: Removing unreachable block (ram,0xf0060af8) */
/* WARNING: Removing unreachable block (ram,0xf0060c4c) */
/* WARNING: Removing unreachable block (ram,0xf0060c28) */
/* WARNING: Removing unreachable block (ram,0xf00604fc) */
/* WARNING: Removing unreachable block (ram,0xf0060370) */
/* WARNING: Removing unreachable block (ram,0xf00602cc) */
/* WARNING: Removing unreachable block (ram,0xf0060220) */
/* WARNING: Removing unreachable block (ram,0xf0060aa0) */
/* WARNING: Removing unreachable block (ram,0xf00609b4) */
/* WARNING: Removing unreachable block (ram,0xf006097c) */
/* WARNING: Removing unreachable block (ram,0xf0060958) */
/* WARNING: Removing unreachable block (ram,0xf005ff0c) */
/* WARNING: Removing unreachable block (ram,0xf00601d4) */
/* WARNING: Removing unreachable block (ram,0xf0060184) */
/* WARNING: Removing unreachable block (ram,0xf0060044) */
/* WARNING: Removing unreachable block (ram,0xf0060914) */
/* WARNING: Removing unreachable block (ram,0xf005fe14) */
/* WARNING: Removing unreachable block (ram,0xf0060fe0) */
/* WARNING: Removing unreachable block (ram,0xf0060ffc) */
/* WARNING: Removing unreachable block (ram,0xf0060f68) */
/* WARNING: Removing unreachable block (ram,0xf0060f28) */
/* WARNING: Removing unreachable block (ram,0xf0060e7c) */
/* WARNING: Removing unreachable block (ram,0xf0060e50) */
/* WARNING: Removing unreachable block (ram,0xf0060e18) */
/* WARNING: Removing unreachable block (ram,0xf0060e64) */
/* WARNING: Removing unreachable block (ram,0xf0060f1c) */
/* WARNING: Removing unreachable block (ram,0xf0060f58) */
/* WARNING: Removing unreachable block (ram,0xf0060f88) */
/* WARNING: Removing unreachable block (ram,0xf0060fcc) */
/* WARNING: Removing unreachable block (ram,0xf005fdf0) */
/* WARNING: Removing unreachable block (ram,0xf0060900) */
/* WARNING: Removing unreachable block (ram,0xf0060928) */
/* WARNING: Removing unreachable block (ram,0xf00600bc) */
/* WARNING: Removing unreachable block (ram,0xf0060154) */
/* WARNING: Removing unreachable block (ram,0xf005fe74) */
/* WARNING: Removing unreachable block (ram,0xf005ff30) */
/* WARNING: Removing unreachable block (ram,0xf0060938) */
/* WARNING: Removing unreachable block (ram,0xf0060984) */
/* WARNING: Removing unreachable block (ram,0xf0060a2c) */
/* WARNING: Removing unreachable block (ram,0xf005fff0) */
/* WARNING: Removing unreachable block (ram,0xf006029c) */
/* WARNING: Removing unreachable block (ram,0xf006034c) */
/* WARNING: Removing unreachable block (ram,0xf006023c) */
/* WARNING: Removing unreachable block (ram,0xf0060c04) */
/* WARNING: Removing unreachable block (ram,0xf0060c44) */
/* WARNING: Removing unreachable block (ram,0xf0060ad0) */
/* WARNING: Removing unreachable block (ram,0xf0060b5c) */
/* WARNING: Removing unreachable block (ram,0xf0060ba4) */
/* WARNING: Removing unreachable block (ram,0xf0060c74) */
/* WARNING: Removing unreachable block (ram,0xf0060ccc) */
/* WARNING: Removing unreachable block (ram,0xf00605d4) */
/* WARNING: Removing unreachable block (ram,0xf006061c) */
/* WARNING: Removing unreachable block (ram,0xf00607d0) */
/* WARNING: Removing unreachable block (ram,0xf0060870) */
/* WARNING: Removing unreachable block (ram,0xf006073c) */
/* WARNING: Removing unreachable block (ram,0xf0060d24) */
/* WARNING: Removing unreachable block (ram,0xf0060d50) */
/* WARNING: Removing unreachable block (ram,0xf0060da8) */
/* WARNING: Removing unreachable block (ram,0xf006079c) */
/* WARNING: Removing unreachable block (ram,0xf00608f0) */
/* WARNING: Removing unreachable block (ram,0xf0061018) */
/* WARNING: Removing unreachable block (ram,0xf0061068) */
/* WARNING: Removing unreachable block (ram,0xf0060ec8) */
/* WARNING: Removing unreachable block (ram,0xf0060e2c) */
/* WARNING: Removing unreachable block (ram,0xf0060dfc) */

undefined8
_mach_msg_trap(undefined4 param_1,uint param_2,uint param_3,uint param_4,uint param_5,
              undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  code *pcVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined4 unaff_l0;
  int *piVar13;
  uint *puVar14;
  undefined4 unaff_l1;
  int *piVar15;
  undefined4 *puVar16;
  undefined4 uVar17;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int *piVar18;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  uint uVar19;
  undefined4 unaff_i0;
  int iVar20;
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
  
  uVar7 = _ipc_kmsg_cache;
  iVar9 = _active_threads;
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
  *(undefined4 *)((int)register0x00000038 + -0x34) = param_1;
  if (param_2 == 3) {
    iVar20 = *(int *)(*(int *)(_active_threads + 0xc) + 0x88);
    if (0xd4 < param_3 - 0x18) goto loc_F0060908;
    iVar1 = *(int *)((int)register0x00000038 + -0x34);
    if ((param_3 & 3) == 0) {
      iVar1 = _ipc_kmsg_cache + 0x14;
      if (_ipc_kmsg_cache == 0) {
loc_F0060908:
        iVar1 = *(int *)((int)register0x00000038 + -0x34);
        goto loc_F006090C;
      }
      _ipc_kmsg_cache = 0;
      *(undefined4 *)(uVar7 + 0x10) = 0;
      iVar2 = *(int *)((int)register0x00000038 + -0x34);
      _copyinmsg(iVar2,iVar1,param_3);
      if (iVar2 != 0) {
        if (*(int *)(uVar7 + 8) < 1) {
          _ipc_kmsg_free(uVar7);
          iVar1 = *(int *)((int)register0x00000038 + -0x34);
          goto loc_F006090C;
        }
        _kfree(uVar7);
        goto loc_F0060908;
      }
      *(undefined4 *)(uVar7 + 0x10) = 0;
      *(uint *)(uVar7 + 0x18) = param_3;
    }
    else {
loc_F006090C:
      _ipc_kmsg_get(iVar1,param_3,0,(undefined *)((int)register0x00000038 + -0xc));
      uVar7 = *(uint *)((int)register0x00000038 + -0xc);
      if (iVar1 != 0) {
        _thread_syscall_return();
        uVar7 = *(uint *)((int)register0x00000038 + -0xc);
      }
    }
    if (*(int *)(uVar7 + 0x14) == 0x12) {
      if (*(int *)(uVar7 + 0x20) != 0) goto loc_F0060944;
      do {
        do {
        } while (*(int *)(iVar20 + 8) != 0);
        piVar15 = (int *)(iVar20 + 8);
        _simple_lock_try();
      } while (piVar15 == (int *)0x0);
      uVar19 = *(uint *)(iVar20 + 0x18);
      iVar1 = *(int *)(iVar20 + 0x14);
      uVar11 = *(uint *)(uVar7 + 0x1c) >> 8;
      uVar10 = *(uint *)(uVar7 + 0x1c) << 0x18;
      if (((uVar19 <= uVar11) ||
          (puVar14 = (uint *)(iVar1 + uVar11 * 0x10),
          (*(uint *)(iVar1 + uVar11 * 0x10) & 0xff840000) != (uVar10 | 0x40000))) ||
         (puVar14[2] != 0)) goto loc_F00601F4;
      piVar15 = (int *)puVar14[1];
      do {
        do {
        } while (*piVar15 != 0);
        piVar13 = piVar15;
        _simple_lock_try();
      } while (piVar13 == (int *)0x0);
      if (-1 < piVar15[2]) {
loc_F00600E0:
        *piVar15 = 0;
        goto loc_F00601F4;
      }
      puVar14[2] = *(uint *)(iVar1 + 8);
      *(uint *)(iVar1 + 8) = uVar11;
      *puVar14 = uVar10;
      puVar14[1] = 0;
      *(undefined4 *)(uVar7 + 0x14) = 0x12;
      *(int **)(uVar7 + 0x1c) = piVar15;
      if (param_5 >> 8 < uVar19) {
        iVar2 = (param_5 >> 8) * 0x10;
        uVar11 = *(uint *)(iVar1 + iVar2);
        iVar1 = iVar1 + iVar2;
        if ((uVar11 & 0xff000000) + param_5 * -0x1000000 == 0) {
          if ((uVar11 & 0x80000) != 0) {
            piVar13 = *(int **)(iVar1 + 4);
            do {
              do {
              } while (*piVar13 != 0);
              piVar3 = piVar13;
              _simple_lock_try();
            } while (piVar3 == (int *)0x0);
            piVar3 = piVar13 + 4;
loc_F00601B4:
            *(undefined4 *)(iVar20 + 8) = 0;
            piVar13[1] = piVar13[1] + 1;
            do {
              do {
              } while (*piVar3 != 0);
              piVar18 = piVar3;
              _simple_lock_try();
            } while (piVar18 == (int *)0x0);
            *piVar13 = 0;
            iVar1 = piVar15[0xc];
            goto loc_F0060210;
          }
          if ((uVar11 & 0x20000) != 0) {
            piVar13 = *(int **)(iVar1 + 4);
            piVar3 = piVar13;
            _simple_lock_try();
            if (piVar3 != (int *)0x0) {
              if (piVar13[0xc] == 0) {
                piVar3 = piVar13 + 0x10;
                goto loc_F00601B4;
              }
              *piVar13 = 0;
            }
          }
        }
      }
      *piVar15 = 0;
      *(undefined4 *)(iVar20 + 8) = 0;
      goto loc_F0060BFC;
    }
    if ((*(int *)(uVar7 + 0x14) == 0x1513) && (*(uint *)(uVar7 + 0x20) == param_5)) {
      do {
        do {
        } while (*(int *)(iVar20 + 8) != 0);
        piVar15 = (int *)(iVar20 + 8);
        _simple_lock_try();
      } while (piVar15 == (int *)0x0);
      iVar1 = *(int *)(iVar20 + 0x14);
      if ((*(uint *)(iVar20 + 0x18) <= param_5 >> 8) ||
         (iVar2 = (param_5 >> 8) * 0x10,
         (*(uint *)(iVar1 + iVar2) & 0xff020000) != (param_5 << 0x18 | 0x20000))) {
loc_F00601F4:
        *(undefined4 *)(iVar20 + 8) = 0;
        goto loc_F0060944;
      }
      piVar13 = *(int **)(iVar1 + iVar2 + 4);
      uVar11 = *(uint *)(uVar7 + 0x1c) >> 8;
      if ((*(uint *)(iVar20 + 0x18) <= uVar11) ||
         (iVar2 = uVar11 * 0x10,
         (*(uint *)(iVar1 + iVar2) & 0xff010000) != (*(uint *)(uVar7 + 0x1c) << 0x18 | 0x10000)))
      goto loc_F00601F4;
      piVar15 = *(int **)(iVar1 + iVar2 + 4);
      do {
        do {
        } while (*piVar15 != 0);
        piVar3 = piVar15;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      if ((-1 < piVar15[2]) || (piVar3 = piVar13, _simple_lock_try(), piVar3 == (int *)0x0))
      goto loc_F00600E0;
      *(undefined4 *)(iVar20 + 8) = 0;
      piVar15[7] = piVar15[7] + 1;
      piVar15[1] = piVar15[1] + 1;
      piVar13[8] = piVar13[8] + 1;
      piVar13[1] = piVar13[1] + 1;
      *(undefined4 *)(uVar7 + 0x14) = 0x1211;
      *(int **)(uVar7 + 0x1c) = piVar15;
      *(int **)(uVar7 + 0x20) = piVar13;
      if (piVar15[3] == _ipc_space_kernel) {
        *piVar13 = 0;
        *piVar15 = 0;
        goto loc_F0060AD0;
      }
      if (((uint)piVar15[0xf] <= (uint)piVar15[0xe]) || (piVar13[0xc] != 0)) {
        *piVar15 = 0;
        *piVar13 = 0;
        goto loc_F0060BFC;
      }
      piVar13[1] = piVar13[1] + 1;
      piVar3 = piVar13 + 0x10;
      do {
        do {
        } while (*piVar3 != 0);
        piVar18 = piVar3;
        _simple_lock_try();
      } while (piVar18 == (int *)0x0);
      *piVar13 = 0;
      iVar1 = piVar15[0xc];
loc_F0060210:
      piVar18 = (int *)(iVar1 + 0x10);
      if (iVar1 == 0) {
        piVar18 = piVar15 + 0x10;
      }
      piVar4 = piVar18;
      _simple_lock_try();
      if (piVar4 == (int *)0x0) {
loc_F0060234:
        *piVar15 = 0;
        *piVar3 = 0;
        _ipc_object_release(piVar13);
        goto loc_F0060BFC;
      }
      iVar1 = piVar18[2];
      if ((iVar1 == 0) || (piVar3[1] != 0)) {
loc_F006044C:
        *piVar18 = 0;
        goto loc_F0060234;
      }
      *(uint *)(iVar9 + 0xcc) = param_4;
      *(int **)(iVar9 + 0xd8) = piVar13;
      *(int **)(iVar9 + 0xdc) = piVar3;
      *(undefined4 *)(iVar9 + 0xc4) = *(undefined4 *)((int)register0x00000038 + -0x34);
      pcVar8 = *(code **)(iVar1 + 0x34);
      if (pcVar8 != _mach_msg_continue) {
loc_F00602B4:
        if (pcVar8 == _exception_raise_continue) {
          iVar2 = iVar9;
          _thread_handoff(iVar9,_mach_msg_continue,iVar1);
          if (iVar2 != 0) {
            iVar20 = piVar3[2];
            if (iVar20 == 0) {
              piVar3[2] = iVar9;
            }
            else {
              iVar2 = *(int *)(iVar20 + 0x94);
              *(int *)(iVar9 + 0x90) = iVar20;
              *(int *)(iVar9 + 0x94) = iVar2;
              *(int *)(iVar20 + 0x94) = iVar9;
              *(int *)(iVar2 + 0x90) = iVar9;
            }
            *(undefined4 *)(iVar9 + 0x98) = 0x10004001;
            *(undefined4 *)(iVar9 + 0x9c) = 0xffffffff;
            *piVar3 = 0;
            iVar9 = *(int *)(iVar1 + 0x90);
            if (iVar9 == iVar1) {
              piVar18[2] = 0;
            }
            else {
              iVar20 = *(int *)(iVar1 + 0x94);
              piVar18[2] = iVar9;
              *(int *)(iVar9 + 0x94) = iVar20;
              *(int *)(iVar20 + 0x90) = iVar9;
              *(int *)(iVar1 + 0x90) = iVar1;
              *(int *)(iVar1 + 0x94) = iVar1;
            }
            *piVar18 = 0;
            _exception_raise_continue_fast(piVar15,uVar7);
            uVar7 = 0;
            goto locret_F0061080;
          }
          uVar11 = *(uint *)(iVar1 + 0x9c);
        }
        else {
          uVar11 = *(uint *)(iVar1 + 0x9c);
        }
        if ((param_3 <= uVar11) &&
           (iVar2 = iVar9, _thread_handoff(iVar9,_mach_msg_continue,iVar1), iVar2 != 0)) {
          if (*(code **)(iVar1 + 0x34) == _mach_msg_receive_continue) {
            if ((*(uint *)(iVar1 + 200) & 0x200) == 0) goto loc_F0060454;
            iVar20 = piVar15[0xe];
          }
          else {
            iVar20 = piVar15[0xe];
          }
          *piVar15 = 0;
          piVar15[0xe] = iVar20 + 1;
          iVar20 = piVar3[2];
          if (iVar20 == 0) {
            piVar3[2] = iVar9;
          }
          else {
            iVar2 = *(int *)(iVar20 + 0x94);
            *(int *)(iVar9 + 0x90) = iVar20;
            *(int *)(iVar9 + 0x94) = iVar2;
            *(int *)(iVar20 + 0x94) = iVar9;
            *(int *)(iVar2 + 0x90) = iVar9;
          }
          *(undefined4 *)(iVar9 + 0x98) = 0x10004001;
          *(undefined4 *)(iVar9 + 0x9c) = 0xffffffff;
          *piVar3 = 0;
          iVar9 = *(int *)(iVar1 + 0x90);
          if (iVar9 == iVar1) {
            piVar18[2] = 0;
          }
          else {
            iVar20 = *(int *)(iVar1 + 0x94);
            piVar18[2] = iVar9;
            *(int *)(iVar9 + 0x94) = iVar20;
            *(int *)(iVar20 + 0x90) = iVar9;
            *(int *)(iVar1 + 0x90) = iVar1;
            *(int *)(iVar1 + 0x94) = iVar1;
          }
          *(undefined4 *)(iVar1 + 0x98) = 0;
          *(uint *)(iVar1 + 0x9c) = uVar7;
          iVar9 = piVar15[0xd];
          piVar15[0xd] = iVar9 + 1;
          *(int *)(iVar1 + 0xa0) = iVar9;
          *piVar18 = 0;
          *(undefined4 *)(iVar1 + 0x44) = 0;
          (**(code **)(iVar1 + 0x34))();
          uVar7 = 0;
          goto locret_F0061080;
        }
        goto loc_F006044C;
      }
      iVar2 = iVar9;
      _thread_handoff(iVar9,_mach_msg_continue,iVar1);
      if (iVar2 == 0) {
        pcVar8 = *(code **)(iVar1 + 0x34);
        goto loc_F00602B4;
      }
loc_F0060454:
      *piVar15 = 0;
      iVar20 = piVar3[2];
      if (iVar20 == 0) {
        piVar3[2] = iVar9;
      }
      else {
        iVar2 = *(int *)(iVar20 + 0x94);
        *(int *)(iVar9 + 0x90) = iVar20;
        *(int *)(iVar9 + 0x94) = iVar2;
        *(int *)(iVar20 + 0x94) = iVar9;
        *(int *)(iVar2 + 0x90) = iVar9;
      }
      *(undefined4 *)(iVar9 + 0x98) = 0x10004001;
      *(undefined4 *)(iVar9 + 0x9c) = 0xffffffff;
      *piVar3 = 0;
      iVar9 = *(int *)(iVar1 + 0x90);
      if (iVar9 == iVar1) {
        piVar18[2] = 0;
      }
      else {
        iVar20 = *(int *)(iVar1 + 0x94);
        piVar18[2] = iVar9;
        *(int *)(iVar9 + 0x94) = iVar20;
        *(int *)(iVar20 + 0x90) = iVar9;
        *(int *)(iVar1 + 0x90) = iVar1;
        *(int *)(iVar1 + 0x94) = iVar1;
      }
      iVar9 = piVar15[0xd];
      piVar15[0xd] = iVar9 + 1;
      *(int *)(uVar7 + 0x24) = iVar9;
      *piVar18 = 0;
      param_4 = *(uint *)(iVar1 + 0xcc);
      piVar13 = *(int **)(iVar1 + 0xd8);
      iVar9 = *(int *)(iVar1 + 0xc);
      *(undefined4 *)((int)register0x00000038 + -0x34) = *(undefined4 *)(iVar1 + 0xc4);
      iVar20 = *(int *)(iVar9 + 0x88);
      do {
        do {
        } while (*piVar13 != 0);
        piVar3 = piVar13;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      iVar9 = piVar13[1];
      piVar13[1] = iVar9 + -1;
      *piVar13 = 0;
      if (iVar9 + -1 == 0) {
        uVar5 = (&_ipc_object_zones)[(piVar13[2] & 0x7fffffffU) >> 0x10];
loc_F0060548:
        _zfree(uVar5,piVar13);
      }
    }
    else {
loc_F0060944:
      uVar11 = uVar7;
      _ipc_kmsg_copyin(uVar7,iVar20,*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc),0);
      if (uVar11 == 0) {
        uVar11 = *(uint *)(uVar7 + 0x14);
      }
      else {
        if (*(int *)(uVar7 + 8) < 1) {
          _ipc_kmsg_free(uVar7);
        }
        else {
          _kfree(uVar7);
        }
        _thread_syscall_return(uVar11);
        uVar11 = *(uint *)(uVar7 + 0x14);
      }
      if ((uVar11 & 0x40000000) == 0) {
        piVar15 = *(int **)(uVar7 + 0x1c);
        do {
          do {
          } while (*piVar15 != 0);
          piVar13 = piVar15;
          _simple_lock_try();
        } while (piVar13 == (int *)0x0);
        if (piVar15[3] != _ipc_space_kernel) {
          if (piVar15[2] < 0) {
            if ((uint)piVar15[0xe] < (uint)piVar15[0xf]) {
              piVar13 = *(int **)(uVar7 + 0x20);
            }
            else {
              if (*(char *)(uVar7 + 0x17) != '\x12') goto loc_F0060AC4;
              piVar13 = *(int **)(uVar7 + 0x20);
            }
            if (((piVar13 != (int *)0x0) && (piVar13 != (int *)0xffffffff)) &&
               (piVar3 = piVar13, _simple_lock_try(), piVar3 != (int *)0x0)) {
              if (((piVar13[2] < 0) && (piVar13[3] == iVar20)) &&
                 ((piVar13[4] == param_5 && (piVar13[0xc] == 0)))) {
                piVar13[1] = piVar13[1] + 1;
                piVar3 = piVar13 + 0x10;
                do {
                  do {
                  } while (*piVar3 != 0);
                  piVar18 = piVar3;
                  _simple_lock_try();
                } while (piVar18 == (int *)0x0);
                *piVar13 = 0;
                iVar1 = piVar15[0xc];
                goto loc_F0060210;
              }
              *piVar13 = 0;
            }
          }
loc_F0060AC4:
          *piVar15 = 0;
          goto loc_F0060BFC;
        }
        *piVar15 = 0;
loc_F0060AD0:
        _ipc_kobject_server();
        if (uVar7 != 0) {
          piVar13 = *(int **)(uVar7 + 0x1c);
          do {
            do {
            } while (*piVar13 != 0);
            piVar15 = piVar13;
            _simple_lock_try();
          } while (piVar15 == (int *)0x0);
          if (((piVar13[2] < 0) && (piVar13[3] == iVar20)) &&
             ((piVar13[4] == param_5 && (piVar15 = piVar13 + 0x10, piVar13[0xc] == 0)))) {
            do {
              do {
              } while (*piVar15 != 0);
              piVar3 = piVar15;
              _simple_lock_try();
            } while (piVar3 == (int *)0x0);
            if ((piVar13[0x12] != 0) || (piVar13[0x11] != 0)) {
              *piVar15 = 0;
              goto loc_F0060B94;
            }
            iVar9 = piVar13[0xd];
            piVar13[0xd] = iVar9 + 1;
            *(int *)(uVar7 + 0x24) = iVar9;
            *piVar15 = 0;
            *piVar13 = 0;
            piVar15 = piVar13;
            if (piVar13[1] == 0) {
              uVar5 = (&_ipc_object_zones)[(piVar13[2] & 0x7fffffffU) >> 0x10];
              goto loc_F0060548;
            }
            goto loc_F0060550;
          }
loc_F0060B94:
          *piVar13 = 0;
          _ipc_mqueue_send(uVar7,0x10000,0,0);
        }
      }
      else {
loc_F0060BFC:
        uVar11 = uVar7;
        _ipc_mqueue_send(uVar7,0,0,0);
        if (uVar11 != 0) {
          uVar10 = uVar7;
          _ipc_kmsg_copyout_pseudo
                    (uVar7,iVar20,*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc));
          _ipc_kmsg_put(*(undefined4 *)((int)register0x00000038 + -0x34),uVar7,
                        *(int *)(uVar7 + 0x18) + *(int *)(uVar7 + 0x10));
          _thread_syscall_return(uVar11 | uVar10);
        }
      }
      iVar1 = iVar20;
      _ipc_mqueue_copyin(iVar20,param_5,(undefined *)((int)register0x00000038 + -0x10),
                         (undefined *)((int)register0x00000038 + -0x14));
      if (iVar1 == 0) {
        *(uint *)(iVar9 + 0xcc) = param_4;
      }
      else {
        _thread_syscall_return();
        *(uint *)(iVar9 + 0xcc) = param_4;
      }
      uVar5 = *(undefined4 *)((int)register0x00000038 + -0x14);
      iVar1 = *(int *)((int)register0x00000038 + -0x10);
      *(undefined4 *)(iVar9 + 0xc4) = *(undefined4 *)((int)register0x00000038 + -0x34);
      *(undefined4 *)(iVar9 + 0xd8) = uVar5;
      *(int *)(iVar9 + 0xdc) = iVar1;
      _ipc_mqueue_receive(iVar1,0,0xffffffff,0,0,_mach_msg_continue,
                          (undefined *)((int)register0x00000038 + -0xc),
                          (undefined *)((int)register0x00000038 + -0x18));
      _ipc_object_release(uVar5);
      uVar7 = *(uint *)((int)register0x00000038 + -0xc);
      if (iVar1 != 0) {
        _thread_syscall_return(iVar1);
        uVar7 = *(uint *)((int)register0x00000038 + -0xc);
      }
      *(undefined4 *)(uVar7 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x18);
      piVar15 = *(int **)(uVar7 + 0x1c);
    }
loc_F0060550:
    iVar9 = *(int *)(uVar7 + 0x18);
    uVar11 = iVar9 + *(int *)(uVar7 + 0x10);
    if (param_4 < uVar11) {
loc_F0060D00:
      uVar11 = iVar9 + *(int *)(uVar7 + 0x10);
      if (param_4 < uVar11) {
        _ipc_kmsg_copyout_dest(uVar7,iVar20);
        _ipc_kmsg_put(*(undefined4 *)((int)register0x00000038 + -0x34),uVar7,0x18);
        _thread_syscall_return(0x10004004);
      }
      uVar10 = uVar7;
      _ipc_kmsg_copyout(uVar7,iVar20,*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc),0);
      if (uVar10 == 0) goto loc_F00608A8;
      if ((uVar10 & 0xffffc3ff) == 0x1000400c) {
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x34);
        iVar9 = *(int *)(uVar7 + 0x18) + *(int *)(uVar7 + 0x10);
      }
      else {
        _ipc_kmsg_copyout_dest(uVar7,iVar20);
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x34);
        iVar9 = 0x18;
      }
      _ipc_kmsg_put(uVar5,uVar7,iVar9);
      _thread_syscall_return(uVar10);
      *(undefined4 *)(uVar7 + 0x10) = 0;
    }
    else {
      uVar10 = *(uint *)(uVar7 + 0x14);
      if (uVar10 == 0x1211) {
        puVar16 = *(undefined4 **)(uVar7 + 0x20);
        if ((puVar16 == (undefined4 *)0x0) || (puVar16 == (undefined4 *)0xffffffff)) {
          iVar9 = *(int *)(uVar7 + 0x18);
        }
        else {
          do {
            do {
            } while (*(int *)(iVar20 + 8) != 0);
            piVar13 = (int *)(iVar20 + 8);
            _simple_lock_try();
          } while (piVar13 == (int *)0x0);
          do {
            do {
            } while (*piVar15 != 0);
            piVar13 = piVar15;
            _simple_lock_try();
          } while (piVar13 == (int *)0x0);
          if ((piVar15[2] < 0) &&
             (puVar6 = puVar16, _simple_lock_try(), puVar6 != (undefined4 *)0x0)) {
            if ((int)puVar16[2] < 0) {
              *puVar16 = 0;
              iVar1 = *(int *)(iVar20 + 0x14);
              iVar2 = *(int *)(iVar1 + 8);
              iVar9 = iVar2 * 0x10;
              if (iVar2 != 0) {
                iVar12 = iVar1 + iVar9;
                *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar12 + 8);
                *(undefined4 *)(iVar12 + 8) = 0;
                uVar10 = *(int *)(iVar1 + iVar9) + 0x1000000;
                *(uint *)(iVar1 + iVar9) = uVar10 | 0x40001;
                *(undefined4 **)(iVar12 + 4) = puVar16;
                *(undefined4 *)(iVar20 + 8) = 0;
                piVar15[1] = piVar15[1] + -1;
                iVar9 = 0;
                if (piVar15[3] == iVar20) {
                  iVar9 = piVar15[4];
                }
                iVar20 = piVar15[7];
                piVar15[7] = iVar20 + -1;
                if ((iVar20 + -1 == 0) && (iVar20 = piVar15[9], iVar20 != 0)) {
                  piVar15[9] = 0;
                  *piVar15 = 0;
                  _ipc_notify_no_senders(iVar20,piVar15[6]);
                }
                else {
                  *piVar15 = 0;
                }
                *(undefined4 *)(uVar7 + 0x14) = 0x1112;
                *(uint *)(uVar7 + 0x1c) = iVar2 << 8 | uVar10 >> 0x18;
                *(int *)(uVar7 + 0x20) = iVar9;
                goto loc_F00608A8;
              }
            }
            else {
              *puVar16 = 0;
            }
          }
          *piVar15 = 0;
          *(undefined4 *)(iVar20 + 8) = 0;
          iVar9 = *(int *)(uVar7 + 0x18);
        }
        goto loc_F0060D00;
      }
      if (0x1211 < uVar10) {
        if (uVar10 == 0x80000012) {
          do {
            do {
            } while (*piVar15 != 0);
            piVar13 = piVar15;
            _simple_lock_try();
          } while (piVar13 == (int *)0x0);
          if (piVar15[2] < 0) {
            if (piVar15[3] == iVar20) {
              piVar15[1] = piVar15[1] + -1;
              piVar15[8] = piVar15[8] + -1;
              iVar9 = piVar15[4];
              *piVar15 = 0;
            }
            else {
              *piVar15 = 0;
              _ipc_notify_send_once(piVar15);
              iVar9 = 0;
            }
            *(undefined4 *)(uVar7 + 0x14) = 0x80001200;
            *(undefined4 *)(uVar7 + 0x1c) = 0;
            *(int *)(uVar7 + 0x20) = iVar9;
            uVar10 = uVar7 + 0x2c;
            _ipc_kmsg_copyout_body
                      (uVar10,uVar7 + *(int *)(uVar7 + 0x18) + 0x14,iVar20,
                       *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc));
            if (uVar10 != 0) {
              _ipc_kmsg_put(*(undefined4 *)((int)register0x00000038 + -0x34),uVar7,
                            *(int *)(uVar7 + 0x18) + *(int *)(uVar7 + 0x10));
              uVar7 = uVar10 | 0x1000400c;
              goto locret_F0061080;
            }
            goto loc_F00608A8;
          }
          iVar9 = *(int *)(uVar7 + 0x18);
        }
        else {
          iVar9 = *(int *)(uVar7 + 0x18);
        }
        goto loc_F0060D00;
      }
      if (uVar10 != 0x12) {
        iVar9 = *(int *)(uVar7 + 0x18);
        goto loc_F0060D00;
      }
      do {
        do {
        } while (*piVar15 != 0);
        piVar13 = piVar15;
        _simple_lock_try();
      } while (piVar13 == (int *)0x0);
      if (-1 < piVar15[2]) {
        iVar9 = *(int *)(uVar7 + 0x18);
        goto loc_F0060D00;
      }
      if (piVar15[3] == iVar20) {
        piVar15[1] = piVar15[1] + -1;
        piVar15[8] = piVar15[8] + -1;
        iVar9 = piVar15[4];
        *piVar15 = 0;
      }
      else {
        *piVar15 = 0;
        _ipc_notify_send_once(piVar15);
        iVar9 = 0;
      }
      *(undefined4 *)(uVar7 + 0x14) = 0x1200;
      *(undefined4 *)(uVar7 + 0x1c) = 0;
      *(int *)(uVar7 + 0x20) = iVar9;
loc_F00608A8:
      *(undefined4 *)(uVar7 + 0x10) = 0;
    }
    uVar5 = *(undefined4 *)((int)register0x00000038 + -0x34);
    if (*(int *)(uVar7 + 8) == 0x100) {
      iVar9 = uVar7 + 0x14;
      _copyoutmsg(iVar9,*(undefined4 *)((int)register0x00000038 + -0x34),uVar11);
      uVar5 = *(undefined4 *)((int)register0x00000038 + -0x34);
      if ((iVar9 == 0) &&
         (uVar5 = *(undefined4 *)((int)register0x00000038 + -0x34), _ipc_kmsg_cache == 0)) {
        _ipc_kmsg_cache = uVar7;
        _thread_syscall_return(0);
        uVar7 = 0;
        goto locret_F0061080;
      }
    }
    _ipc_kmsg_put(uVar5,uVar7,uVar11);
loc_F0061018:
    _thread_syscall_return();
  }
  else {
    if (param_2 == 1) {
      uVar7 = *(uint *)((int)register0x00000038 + -0x34);
      uVar5 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88);
      uVar17 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
      _ipc_kmsg_get(uVar7,param_3,0,(undefined *)((int)register0x00000038 + -0x1c));
      uVar11 = *(uint *)((int)register0x00000038 + -0x1c);
      if (uVar7 != 0) goto locret_F0061080;
      _ipc_kmsg_copyin(uVar11,uVar5,uVar17,0);
      uVar10 = *(uint *)((int)register0x00000038 + -0x1c);
      if (uVar11 != 0) {
        uVar7 = uVar11;
        if (*(int *)(uVar10 + 8) < 1) {
          _ipc_kmsg_free();
        }
        else {
          _kfree();
        }
        goto locret_F0061080;
      }
      _ipc_mqueue_send(uVar10,0,0,0);
      uVar7 = 0;
      if (uVar10 == 0) goto locret_F0061080;
      uVar7 = *(uint *)((int)register0x00000038 + -0x1c);
      _ipc_kmsg_copyout_pseudo(uVar7,uVar5,uVar17);
      iVar9 = *(int *)((int)register0x00000038 + -0x1c);
      uVar7 = uVar10 | uVar7;
      uVar5 = *(undefined4 *)((int)register0x00000038 + -0x34);
      iVar20 = *(int *)(iVar9 + 0x18) + *(int *)(iVar9 + 0x10);
loc_F0060FE0:
      _ipc_kmsg_put(uVar5,iVar9,iVar20);
      goto locret_F0061080;
    }
    if (param_2 == 2) {
      uVar11 = *(uint *)(*(int *)(_active_threads + 0xc) + 0x88);
      uVar5 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
      uVar7 = uVar11;
      _ipc_mqueue_copyin(uVar11,param_5,(undefined *)((int)register0x00000038 + -0x20),
                         (undefined *)((int)register0x00000038 + -0x24));
      if (uVar7 != 0) goto locret_F0061080;
      *(uint *)(iVar9 + 0xcc) = param_4;
      uVar17 = *(undefined4 *)((int)register0x00000038 + -0x24);
      uVar7 = *(uint *)((int)register0x00000038 + -0x20);
      *(undefined4 *)(iVar9 + 0xc4) = *(undefined4 *)((int)register0x00000038 + -0x34);
      *(undefined4 *)(iVar9 + 0xd8) = uVar17;
      *(uint *)(iVar9 + 0xdc) = uVar7;
      _ipc_mqueue_receive(uVar7,0,0xffffffff,0,0,_mach_msg_continue,
                          (undefined *)((int)register0x00000038 + -0x28),
                          (undefined *)((int)register0x00000038 + -0x2c));
      _ipc_object_release(*(undefined4 *)((int)register0x00000038 + -0x24));
      if (uVar7 != 0) goto locret_F0061080;
      uVar7 = *(uint *)((int)register0x00000038 + -0x28);
      *(undefined4 *)(uVar7 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x2c);
      if (param_4 < *(uint *)(uVar7 + 0x18)) {
        _ipc_kmsg_copyout_dest(uVar7,uVar11);
        _ipc_kmsg_put(*(undefined4 *)((int)register0x00000038 + -0x34),
                      *(undefined4 *)((int)register0x00000038 + -0x28),0x18);
        uVar7 = 0x10004004;
        goto locret_F0061080;
      }
      _ipc_kmsg_copyout(uVar7,uVar11,uVar5,0);
      if (uVar7 == 0) {
        iVar9 = *(int *)((int)register0x00000038 + -0x28);
        uVar7 = *(uint *)((int)register0x00000038 + -0x34);
        _ipc_kmsg_put(uVar7,iVar9,*(int *)(iVar9 + 0x18) + *(int *)(iVar9 + 0x10));
        goto locret_F0061080;
      }
      if ((uVar7 & 0xffffc3ff) == 0x1000400c) {
        iVar9 = *(int *)((int)register0x00000038 + -0x28);
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x34);
        iVar20 = *(int *)(iVar9 + 0x18) + *(int *)(iVar9 + 0x10);
      }
      else {
        _ipc_kmsg_copyout_dest(*(undefined4 *)((int)register0x00000038 + -0x28),uVar11);
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x34);
        iVar9 = *(int *)((int)register0x00000038 + -0x28);
        iVar20 = 0x18;
      }
      goto loc_F0060FE0;
    }
    if (param_2 == 0) goto loc_F0061018;
  }
  if ((param_2 & 1) != 0) {
    uVar7 = *(uint *)((int)register0x00000038 + -0x34);
    _mach_msg_send(uVar7,param_2,param_3,param_6,*(undefined4 *)((int)register0x00000038 + 0x5c));
    if (uVar7 != 0) goto locret_F0061080;
  }
  if ((param_2 & 2) != 0) {
    uVar7 = *(uint *)((int)register0x00000038 + -0x34);
    _mach_msg_receive(uVar7,param_2,param_4,param_5,param_6,
                      *(undefined4 *)((int)register0x00000038 + 0x5c));
    if (uVar7 != 0) goto locret_F0061080;
  }
  uVar7 = 0;
locret_F0061080:
  return CONCAT44(param_2,uVar7);
}
/* GHIDRADEC_FUNCTION index=1236 start=0xf0061088 */

/* WARNING: Removing unreachable block (ram,0xf00611c0) */
/* WARNING: Removing unreachable block (ram,0xf00611a0) */
/* WARNING: Removing unreachable block (ram,0xf0061148) */
/* WARNING: Removing unreachable block (ram,0xf0061128) */
/* WARNING: Removing unreachable block (ram,0xf00610f4) */
/* WARNING: Removing unreachable block (ram,0xf00610e0) */
/* WARNING: Removing unreachable block (ram,0xf0061118) */
/* WARNING: Removing unreachable block (ram,0xf0061134) */
/* WARNING: Removing unreachable block (ram,0xf006118c) */
/* WARNING: Removing unreachable block (ram,0xf00611a8) */
/* WARNING: Removing unreachable block (ram,0xf00611c8) */
/* WARNING: Removing unreachable block (ram,0xf00610d4) */

undefined8 _mach_msg_continue(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 uVar3;
  undefined4 unaff_l1;
  undefined4 uVar4;
  undefined4 unaff_l3;
  undefined4 uVar5;
  undefined4 unaff_l4;
  uint uVar6;
  undefined4 unaff_l5;
  undefined4 uVar7;
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
  uVar5 = *(undefined4 *)(_active_threads + 0xc4);
  uVar6 = *(uint *)(_active_threads + 0xcc);
  uVar3 = *(undefined4 *)(_active_threads + 0xd8);
  uVar4 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar7 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  iVar1 = *(int *)(_active_threads + 0xdc);
  _ipc_mqueue_receive(iVar1,0,0xffffffff,0,1,_mach_msg_continue,
                      (undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x10));
  _ipc_object_release(uVar3);
  iVar2 = *(int *)((int)register0x00000038 + -0xc);
  if (iVar1 != 0) {
    _thread_syscall_return(iVar1);
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
  }
  *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x10);
  if (uVar6 < *(uint *)(iVar2 + 0x18)) {
    _ipc_kmsg_copyout_dest(iVar2,uVar4);
    _ipc_kmsg_put(uVar5,*(undefined4 *)((int)register0x00000038 + -0xc),0x18);
    _thread_syscall_return(0x10004004);
  }
  uVar6 = *(uint *)((int)register0x00000038 + -0xc);
  _ipc_kmsg_copyout(uVar6,uVar4,uVar7,0);
  if (uVar6 != 0) {
    if ((uVar6 & 0xffffc3ff) == 0x1000400c) {
      iVar1 = *(int *)((int)register0x00000038 + -0xc);
      iVar2 = *(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x10);
    }
    else {
      _ipc_kmsg_copyout_dest(*(undefined4 *)((int)register0x00000038 + -0xc),uVar4);
      iVar1 = *(int *)((int)register0x00000038 + -0xc);
      iVar2 = 0x18;
    }
    _ipc_kmsg_put(uVar5,iVar1,iVar2);
    _thread_syscall_return(uVar6);
  }
  iVar1 = *(int *)((int)register0x00000038 + -0xc);
  _ipc_kmsg_put(uVar5,iVar1,*(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x10));
  _thread_syscall_return();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1237 start=0xf00611d8 */

/* WARNING: Removing unreachable block (ram,0xf0061224) */
/* WARNING: Removing unreachable block (ram,0xf0061218) */
/* WARNING: Removing unreachable block (ram,0xf0061234) */
/* WARNING: Removing unreachable block (ram,0xf00611f0) */

undefined8 _mach_msg_interrupt(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  bool bVar3;
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
  piVar2 = *(int **)(param_1 + 0xdc);
  do {
    do {
    } while (*piVar2 != 0);
    piVar1 = piVar2;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  bVar3 = *(int *)(param_1 + 0x98) != 0x10004001;
  if (bVar3) {
    *piVar2 = 0;
  }
  else {
    _ipc_thread_rmqueue(piVar2 + 2,param_1);
    *piVar2 = 0;
    _ipc_object_release(*(undefined4 *)(param_1 + 0xd8));
    _thread_set_syscall_return(param_1,0x10004005);
    *(code **)(param_1 + 0x34) = _thread_exception_return;
  }
  return CONCAT44(param_2,(uint)!bVar3);
}
/* GHIDRADEC_FUNCTION index=1238 start=0xf0061260 */

/* WARNING: Removing unreachable block (ram,0xf0061448) */
/* WARNING: Removing unreachable block (ram,0xf0061438) */

undefined8 _msg_return_translate(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  uVar1 = param_1 & 0xffffc3ff;
  if ((int)uVar1 < 0x1000000f) {
    if (0x1000000c < (int)uVar1) {
      _printf(aMsgReturnTrans);
loc_F0061440:
      param_1 = 0xffffff94;
      goto locret_F0061450;
    }
    if (uVar1 == 0x10000006) {
      param_1 = 0xffffff96;
      goto locret_F0061450;
    }
    if ((int)uVar1 < 0x10000007) {
      if (uVar1 == 0x10000002) {
        param_1 = 0xffffff9b;
        goto locret_F0061450;
      }
      if (0x10000002 < (int)uVar1) {
        param_1 = 0xffffff99;
        if ((uVar1 != 0x10000004) && (param_1 = 0xffffff97, (int)uVar1 < 0x10000005)) {
          param_1 = 0xffffff9a;
        }
        goto locret_F0061450;
      }
      param_1 = 0;
      if (uVar1 == 0) goto locret_F0061450;
    }
    else if ((int)uVar1 < 0x1000000b) {
      param_1 = 0xffffff9a;
      if (0x10000008 < (int)uVar1) goto locret_F0061450;
      if (uVar1 == 0x10000007) goto loc_F0061440;
      param_1 = 0xffffff92;
      if (uVar1 == 0x10000008) goto locret_F0061450;
    }
    else if ((uVar1 != 0x1000000b) && (param_1 = 0xffffff9b, uVar1 == 0x1000000c))
    goto locret_F0061450;
  }
  else {
    param_1 = 0xffffff31;
    if (uVar1 == 0x10004005) goto locret_F0061450;
    if ((int)uVar1 < 0x10004006) {
      if (uVar1 != 0x10004001) {
        if (0x10004001 < (int)uVar1) {
          param_1 = 0xffffff35;
          if ((uVar1 != 0x10004003) && (param_1 = 0xffffff34, (int)uVar1 < 0x10004004)) {
            param_1 = 0xffffff36;
          }
          goto locret_F0061450;
        }
        param_1 = 0xffffff9a;
        if (uVar1 == 0x1000000f) goto locret_F0061450;
      }
    }
    else if ((int)uVar1 < 0x1000400b) {
      param_1 = 0xffffff36;
      if (0x10004008 < (int)uVar1) goto locret_F0061450;
      if (uVar1 != 0x10004007) {
        param_1 = 0xffffff37;
        if ((int)uVar1 < 0x10004008) {
          param_1 = 0xffffff30;
        }
        goto locret_F0061450;
      }
    }
  }
  _panic(aMsgReturnTrans_0);
locret_F0061450:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1239 start=0xf0061458 */

/* WARNING: Removing unreachable block (ram,0xf00614ec) */
/* WARNING: Removing unreachable block (ram,0xf00615e8) */
/* WARNING: Removing unreachable block (ram,0xf0061560) */
/* WARNING: Removing unreachable block (ram,0xf00615d4) */
/* WARNING: Removing unreachable block (ram,0xf00614c8) */
/* WARNING: Removing unreachable block (ram,0xf0061530) */
/* WARNING: Removing unreachable block (ram,0xf006157c) */
/* WARNING: Removing unreachable block (ram,0xf00614b4) */
/* WARNING: Removing unreachable block (ram,0xf00615f4) */
/* WARNING: Removing unreachable block (ram,0xf006149c) */

undefined8 _msg_send_trap(int param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  code *pcVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 uVar4;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar5;
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
  uVar1 = param_3 + 3U & 0xfffffffc;
  iVar3 = *(int *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar4 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  if (uVar1 < 0x2001) {
    _ipc_kmsg_get(param_1,uVar1,param_3 - uVar1,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == 0) {
      param_1 = *(int *)((int)register0x00000038 + -0xc);
      _ipc_kmsg_copyin_compat(param_1,iVar3,uVar4);
      if (param_1 == 0) {
        bVar5 = (param_2 & 0x20) == 0;
        if ((param_2 & 2) == 0) {
          if (bVar5) {
            param_1 = *(int *)((int)register0x00000038 + -0xc);
            iVar3 = (param_2 & 1) << 4;
            pcVar2 = (code *)0x0;
          }
          else {
            param_1 = *(int *)((int)register0x00000038 + -0xc);
            if ((param_2 & 1) == 0) {
              iVar3 = 0x20000;
            }
            else {
              iVar3 = 0x20010;
            }
            pcVar2 = _msg_send_switch_continue;
          }
          _ipc_mqueue_send(param_1,iVar3,param_4,pcVar2);
          bVar5 = param_1 == 0;
        }
        else {
          param_1 = *(int *)((int)register0x00000038 + -0xc);
          if (bVar5) {
            uVar4 = 0x10;
          }
          else {
            uVar4 = 0x20010;
          }
          _ipc_mqueue_send(param_1,uVar4,param_4 & -(param_2 & 1),0);
          bVar5 = param_1 == 0;
          if (param_1 == 0x10000004) {
            _ipc_marequest_create
                      (iVar3,*(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c),0,
                       *(int *)((int)register0x00000038 + -0xc) + 0xc);
            bVar5 = false;
            param_1 = iVar3;
            if (iVar3 == 0) {
              _ipc_mqueue_send(*(undefined4 *)((int)register0x00000038 + -0xc),0x10000,0,0);
              param_1 = -0x69;
              goto locret_F0061600;
            }
          }
        }
        if (!bVar5) {
          _ipc_kmsg_destroy(*(undefined4 *)((int)register0x00000038 + -0xc));
        }
      }
      else if (*(int *)(*(int *)((int)register0x00000038 + -0xc) + 8) < 1) {
        _ipc_kmsg_free();
      }
      else {
        _kfree();
      }
    }
    _msg_return_translate();
  }
  else {
    param_1 = -0x6d;
  }
locret_F0061600:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1240 start=0xf0061608 */

/* WARNING: Removing unreachable block (ram,0xf006160c) */

undefined8 _msg_send_switch_continue(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  _thread_syscall_return(0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1241 start=0xf006161c */

/* WARNING: Removing unreachable block (ram,0xf00616ec) */
/* WARNING: Removing unreachable block (ram,0xf0061714) */
/* WARNING: Removing unreachable block (ram,0xf00616b8) */
/* WARNING: Removing unreachable block (ram,0xf00616ac) */
/* WARNING: Removing unreachable block (ram,0xf0061748) */
/* WARNING: Removing unreachable block (ram,0xf0061730) */
/* WARNING: Removing unreachable block (ram,0xf0061738) */
/* WARNING: Removing unreachable block (ram,0xf0061640) */

undefined8
_msg_receive_trap(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 uVar6;
  undefined4 unaff_l3;
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
  iVar5 = *(int *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar6 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  iVar4 = iVar5;
  _ipc_mqueue_copyin(iVar5,param_4,(undefined *)((int)register0x00000038 + -0xc),
                     (undefined *)((int)register0x00000038 + -0x10));
  iVar2 = _active_threads;
  uVar1 = *(undefined4 *)((int)register0x00000038 + -0x10);
  if (iVar4 == 0) {
    iVar4 = *(int *)((int)register0x00000038 + -0xc);
    *(int *)(_active_threads + 0xc4) = param_1;
    *(uint *)(iVar2 + 200) = param_2;
    *(uint *)(iVar2 + 0xcc) = param_3;
    *(undefined4 *)(iVar2 + 0xd0) = param_5;
    *(undefined4 *)(iVar2 + 0xd8) = uVar1;
    *(int *)(iVar2 + 0xdc) = iVar4;
    uVar3 = 0xffffffff;
    if ((param_2 & 0x1000) != 0) {
      uVar3 = param_3;
    }
    _ipc_mqueue_receive(iVar4,param_2 & 0x100,uVar3,param_5,0,_msg_receive_continue,
                        (undefined *)((int)register0x00000038 + -0x14),
                        (undefined *)((int)register0x00000038 + -0x18));
    _ipc_object_release(*(undefined4 *)((int)register0x00000038 + -0x10));
    if (iVar4 == 0) {
      iVar2 = *(int *)((int)register0x00000038 + -0x14);
      if (param_3 < *(uint *)(iVar2 + 0x18)) {
        _ipc_kmsg_destroy(iVar2);
        iVar4 = -0xcc;
        goto locret_F0061754;
      }
      _ipc_kmsg_copyout_compat(iVar2,iVar5,uVar6);
      iVar2 = *(int *)((int)register0x00000038 + -0x14);
      *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + *(int *)(iVar2 + 0x10);
      _ipc_kmsg_put(param_1);
      iVar4 = param_1;
    }
    else if (iVar4 == 0x10004004) {
      *(undefined4 *)((int)register0x00000038 + -0x1c) =
           *(undefined4 *)((int)register0x00000038 + -0x14);
      _copyout((undefined *)((int)register0x00000038 + -0x1c),param_1 + 4,4);
    }
  }
  _msg_return_translate();
locret_F0061754:
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=1242 start=0xf006175c */

/* WARNING: Removing unreachable block (ram,0xf00617f0) */
/* WARNING: Removing unreachable block (ram,0xf0061cd4) */
/* WARNING: Removing unreachable block (ram,0xf0061b10) */
/* WARNING: Removing unreachable block (ram,0xf0061ca4) */
/* WARNING: Removing unreachable block (ram,0xf0061c40) */
/* WARNING: Removing unreachable block (ram,0xf0061bb4) */
/* WARNING: Removing unreachable block (ram,0xf0061b3c) */
/* WARNING: Removing unreachable block (ram,0xf0061938) */
/* WARNING: Removing unreachable block (ram,0xf0061884) */
/* WARNING: Removing unreachable block (ram,0xf0061a84) */
/* WARNING: Removing unreachable block (ram,0xf0061a0c) */
/* WARNING: Removing unreachable block (ram,0xf00619d4) */
/* WARNING: Removing unreachable block (ram,0xf0061a54) */
/* WARNING: Removing unreachable block (ram,0xf006181c) */
/* WARNING: Removing unreachable block (ram,0xf00617cc) */
/* WARNING: Removing unreachable block (ram,0xf0061834) */
/* WARNING: Removing unreachable block (ram,0xf00619a4) */
/* WARNING: Removing unreachable block (ram,0xf00619f0) */
/* WARNING: Removing unreachable block (ram,0xf0061a68) */
/* WARNING: Removing unreachable block (ram,0xf0061860) */
/* WARNING: Removing unreachable block (ram,0xf00618f0) */
/* WARNING: Removing unreachable block (ram,0xf0061ab8) */
/* WARNING: Removing unreachable block (ram,0xf0061b7c) */
/* WARNING: Removing unreachable block (ram,0xf0061bd0) */
/* WARNING: Removing unreachable block (ram,0xf0061c4c) */
/* WARNING: Removing unreachable block (ram,0xf0061c80) */
/* WARNING: Removing unreachable block (ram,0xf0061cb8) */
/* WARNING: Removing unreachable block (ram,0xf00617b8) */
/* WARNING: Removing unreachable block (ram,0xf0061cdc) */
/* WARNING: Removing unreachable block (ram,0xf00617a0) */

undefined8
_msg_rpc_trap(int *param_1,uint param_2,int param_3,uint param_4,uint param_5,undefined4 param_6)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int *piVar6;
  undefined4 uVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar8;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  uVar4 = param_3 + 3U & 0xfffffffc;
  piVar6 = *(int **)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar7 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  if (0x2000 < uVar4) {
    piVar8 = (int *)0xffffff93;
    goto locret_F0061CE8;
  }
  piVar8 = param_1;
  _ipc_kmsg_get(param_1,uVar4,param_3 - uVar4,(undefined *)((int)register0x00000038 + -0xc));
  if (piVar8 == (int *)0x0) {
    piVar8 = *(int **)((int)register0x00000038 + -0xc);
    _ipc_kmsg_copyin_compat(piVar8,piVar6,uVar7);
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    if (piVar8 == (int *)0x0) {
      piVar5 = *(int **)(iVar1 + 0x20);
      if ((piVar5 == (int *)0x0) || (piVar5 == (int *)0xffffffff)) {
loc_F0061974:
        bVar9 = (param_2 & 0x20) == 0;
        if ((param_2 & 2) == 0) {
          if (bVar9) {
            piVar8 = *(int **)((int)register0x00000038 + -0xc);
            iVar1 = (param_2 & 1) << 4;
          }
          else {
            piVar8 = *(int **)((int)register0x00000038 + -0xc);
            if ((param_2 & 1) == 0) {
              iVar1 = 0x20000;
            }
            else {
              iVar1 = 0x20010;
            }
          }
          _ipc_mqueue_send(piVar8,iVar1,param_5,0);
          bVar9 = piVar8 == (int *)0x0;
        }
        else {
          piVar8 = *(int **)((int)register0x00000038 + -0xc);
          if (bVar9) {
            uVar3 = 0x10;
          }
          else {
            uVar3 = 0x20010;
          }
          _ipc_mqueue_send(piVar8,uVar3,param_5 & -(param_2 & 1),0);
          bVar9 = piVar8 == (int *)0x0;
          if (piVar8 == (int *)0x10000004) {
            piVar8 = piVar6;
            _ipc_marequest_create
                      (piVar6,*(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0x1c),0,
                       *(int *)((int)register0x00000038 + -0xc) + 0xc);
            bVar9 = false;
            if (piVar8 == (int *)0x0) {
              _ipc_mqueue_send(*(undefined4 *)((int)register0x00000038 + -0xc),0x10000,0,0);
              if (piVar5 != (int *)0x0) {
                piVar8 = (int *)0xffffff97;
                if (piVar5 == (int *)0xffffffff) goto locret_F0061CE8;
                _ipc_object_release(piVar5);
              }
              piVar8 = (int *)0xffffff97;
              goto locret_F0061CE8;
            }
          }
        }
        if (bVar9) {
loc_F0061A98:
          if (piVar5 != (int *)0x0) {
            if (piVar5 == (int *)0xffffffff) {
              piVar8 = (int *)0xffffff36;
              goto locret_F0061CE8;
            }
            do {
              do {
              } while (*piVar5 != 0);
              piVar8 = piVar5;
              _simple_lock_try();
            } while (piVar8 == (int *)0x0);
            if ((int *)piVar5[3] == piVar6) {
              piVar8 = (int *)piVar5[0xc];
              if (piVar8 != (int *)0x0) {
                do {
                  do {
                  } while (*piVar8 != 0);
                  piVar2 = piVar8;
                  _simple_lock_try();
                } while (piVar2 == (int *)0x0);
                if (piVar8[2] < 0) {
                  *piVar8 = 0;
                  piVar5[1] = piVar5[1] + -1;
                  *piVar5 = 0;
                  goto loc_F0061B74;
                }
                _ipc_pset_remove(piVar8,piVar5);
                *piVar8 = 0;
                if (piVar8[1] == 0) {
                  _zfree((&_ipc_object_zones)[(piVar8[2] & 0x7fffffffU) >> 0x10],piVar8);
                }
              }
              do {
                do {
                  piVar8 = piVar5 + 0x10;
                } while (*piVar8 != 0);
                piVar2 = piVar8;
                _simple_lock_try();
              } while (piVar2 == (int *)0x0);
              *piVar5 = 0;
              iVar1 = _active_threads;
              *(int **)(_active_threads + 0xc4) = param_1;
              *(uint *)(iVar1 + 200) = param_2;
              *(uint *)(iVar1 + 0xcc) = param_4;
              *(undefined4 *)(iVar1 + 0xd0) = param_6;
              *(int **)(iVar1 + 0xd8) = piVar5;
              *(int **)(iVar1 + 0xdc) = piVar8;
              uVar4 = 0xffffffff;
              if ((param_2 & 0x1000) != 0) {
                uVar4 = param_4;
              }
              _ipc_mqueue_receive(piVar8,param_2 & 0x100,uVar4,param_6,0,_msg_receive_continue,
                                  (undefined *)((int)register0x00000038 + -0xc),
                                  (undefined *)((int)register0x00000038 + -0x10));
              _ipc_object_release(piVar5);
              if (piVar8 == (int *)0x0) {
                if (param_4 < *(uint *)(*(int *)((int)register0x00000038 + -0xc) + 0x18)) {
                  _ipc_kmsg_destroy(*(int *)((int)register0x00000038 + -0xc));
                  piVar8 = (int *)0xffffff34;
                  goto locret_F0061CE8;
                }
                goto loc_F0061CB4;
              }
              if (piVar8 == (int *)0x10004004) {
                *(undefined4 *)((int)register0x00000038 + -0x14) =
                     *(undefined4 *)((int)register0x00000038 + -0xc);
                _copyout((undefined *)((int)register0x00000038 + -0x14),param_1 + 1,4);
              }
              goto loc_F0061CDC;
            }
            iVar1 = piVar5[1];
            piVar5[1] = iVar1 + -1;
            *piVar5 = 0;
            if (iVar1 + -1 == 0) {
              _zfree((&_ipc_object_zones)[(piVar5[2] & 0x7fffffffU) >> 0x10],piVar5);
              piVar8 = (int *)0xffffff36;
              goto locret_F0061CE8;
            }
          }
loc_F0061B74:
          piVar8 = (int *)0xffffff36;
          goto locret_F0061CE8;
        }
        _ipc_kmsg_destroy(*(undefined4 *)((int)register0x00000038 + -0xc));
        if ((piVar5 != (int *)0x0) && (piVar5 != (int *)0xffffffff)) {
          _ipc_object_release(piVar5);
        }
      }
      else {
        piVar8 = *(int **)(iVar1 + 0x1c);
        _ipc_object_reference(piVar5);
        do {
          do {
          } while (*piVar8 != 0);
          piVar2 = piVar8;
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
        iVar1 = *(int *)((int)register0x00000038 + -0xc);
        if (piVar8[3] != _ipc_space_kernel) {
          *piVar8 = 0;
          goto loc_F0061974;
        }
        *piVar8 = 0;
        _ipc_kobject_server();
        *(int *)((int)register0x00000038 + -0xc) = iVar1;
        if (iVar1 == 0) goto loc_F0061A98;
        do {
          do {
          } while (*piVar5 != 0);
          piVar8 = piVar5;
          _simple_lock_try();
        } while (piVar8 == (int *)0x0);
        if ((((-1 < piVar5[2]) || ((int *)piVar5[3] != piVar6)) || (piVar5[0xc] != 0)) ||
           (piVar8 = piVar5 + 0x10,
           param_4 < (uint)(*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18) +
                           *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x10)))) {
loc_F0061928:
          *piVar5 = 0;
          _ipc_mqueue_send(*(undefined4 *)((int)register0x00000038 + -0xc),0x10000,0,0);
          goto loc_F0061A98;
        }
        do {
          do {
          } while (*piVar8 != 0);
          piVar2 = piVar8;
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
        if ((piVar5[0x12] != 0) || (piVar5[0x11] != 0)) {
          *piVar8 = 0;
          goto loc_F0061928;
        }
        piVar5[0xd] = piVar5[0xd] + 1;
        *piVar8 = 0;
        piVar5[1] = piVar5[1] + -1;
        *piVar5 = 0;
loc_F0061CB4:
        _ipc_kmsg_copyout_compat(*(undefined4 *)((int)register0x00000038 + -0xc),piVar6,uVar7);
        iVar1 = *(int *)((int)register0x00000038 + -0xc);
        *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x10);
        _ipc_kmsg_put(param_1);
        piVar8 = param_1;
      }
    }
    else if (*(int *)(iVar1 + 8) < 1) {
      _ipc_kmsg_free();
    }
    else {
      _kfree();
    }
  }
loc_F0061CDC:
  _msg_return_translate();
locret_F0061CE8:
  return CONCAT44(param_2,piVar8);
}
/* GHIDRADEC_FUNCTION index=1243 start=0xf0061cf0 */

/* WARNING: Removing unreachable block (ram,0xf0061dfc) */
/* WARNING: Removing unreachable block (ram,0xf0061dd8) */
/* WARNING: Removing unreachable block (ram,0xf0061db4) */
/* WARNING: Removing unreachable block (ram,0xf0061d90) */
/* WARNING: Removing unreachable block (ram,0xf0061d58) */
/* WARNING: Removing unreachable block (ram,0xf0061d88) */
/* WARNING: Removing unreachable block (ram,0xf0061d98) */
/* WARNING: Removing unreachable block (ram,0xf0061dbc) */
/* WARNING: Removing unreachable block (ram,0xf0061df4) */
/* WARNING: Removing unreachable block (ram,0xf0061e04) */
/* WARNING: Removing unreachable block (ram,0xf0061d4c) */

undefined8 _msg_receive_continue(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar3;
  uint uVar4;
  undefined4 unaff_l3;
  int iVar5;
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
  iVar5 = *(int *)(_active_threads + 0xc4);
  uVar4 = *(uint *)(_active_threads + 0xcc);
  uVar3 = *(undefined4 *)(_active_threads + 0xd8);
  iVar1 = *(int *)(_active_threads + 0xdc);
  uVar2 = 0xffffffff;
  if ((*(uint *)(_active_threads + 200) & 0x1000) != 0) {
    uVar2 = uVar4;
  }
  _ipc_mqueue_receive(iVar1,*(uint *)(_active_threads + 200) & 0x100,uVar2,
                      *(undefined4 *)(_active_threads + 0xd0),1,_msg_receive_continue,
                      (undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x10));
  _ipc_object_release(uVar3);
  if (iVar1 != 0) {
    if (iVar1 == 0x10004004) {
      *(undefined4 *)((int)register0x00000038 + -0x14) =
           *(undefined4 *)((int)register0x00000038 + -0xc);
      _copyout((undefined *)((int)register0x00000038 + -0x14),iVar5 + 4,4);
    }
    _msg_return_translate(iVar1);
    _thread_syscall_return();
  }
  if (uVar4 < *(uint *)(*(int *)((int)register0x00000038 + -0xc) + 0x18)) {
    _ipc_kmsg_destroy(*(int *)((int)register0x00000038 + -0xc));
    _thread_syscall_return(0xffffff34);
  }
  _ipc_kmsg_copyout_compat
            (*(undefined4 *)((int)register0x00000038 + -0xc),
             *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88),
             *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc));
  iVar1 = *(int *)((int)register0x00000038 + -0xc);
  *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x10);
  _ipc_kmsg_put(iVar5);
  _msg_return_translate();
  _thread_syscall_return();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1244 start=0xf0061e14 */

/* WARNING: Removing unreachable block (ram,0xf0061e40) */

undefined8
_mach_port_names_helper
          (int param_1,uint *param_2,undefined4 param_3,int param_4,int param_5,int *param_6)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  uint uVar6;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
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
  uVar6 = *param_2;
  uVar7 = param_2[2];
  if ((uVar6 & 0x50000) != 0) {
    param_2 = (uint *)param_2[1];
    do {
      do {
      } while (*param_2 != 0);
      puVar1 = param_2;
      _simple_lock_try();
    } while (puVar1 == (uint *)0x0);
    uVar3 = 0;
    if (-1 < (int)param_2[2]) {
      uVar3 = param_2[3] - param_1 >> 0x1f;
    }
    *param_2 = 0;
    if (uVar3 != 0) {
      if ((uVar6 & 0x400000) != 0) goto locret_F0061EFC;
      uVar6 = uVar6 & 0xffc0ffff | 0x100000;
      if (uVar7 != 0) {
        uVar6 = uVar6 + 1;
      }
      uVar7 = 0;
    }
  }
  uVar5 = uVar6 & 0x1f0000;
  uVar3 = 0x20000000;
  if (((uVar6 & 0x400000) != 0) || (uVar3 = 0x80000000, uVar7 != 0)) {
    uVar5 = uVar5 | uVar3;
  }
  if ((uVar6 & 0x200000) != 0) {
    uVar5 = uVar5 | 0x40000000;
  }
  iVar2 = *param_6;
  iVar4 = iVar2 * 4;
  *(undefined4 *)(param_4 + iVar4) = param_3;
  *(uint *)(param_5 + iVar4) = uVar5;
  *param_6 = iVar2 + 1;
locret_F0061EFC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1245 start=0xf0061f04 */

/* WARNING: Removing unreachable block (ram,0xf0062030) */
/* WARNING: Removing unreachable block (ram,0xf0062014) */
/* WARNING: Removing unreachable block (ram,0xf0061fe0) */
/* WARNING: Removing unreachable block (ram,0xf0062214) */
/* WARNING: Removing unreachable block (ram,0xf00621fc) */
/* WARNING: Removing unreachable block (ram,0xf00621c0) */
/* WARNING: Removing unreachable block (ram,0xf006218c) */
/* WARNING: Removing unreachable block (ram,0xf00620f0) */
/* WARNING: Removing unreachable block (ram,0xf00620c8) */
/* WARNING: Removing unreachable block (ram,0xf0062054) */
/* WARNING: Removing unreachable block (ram,0xf0061f70) */
/* WARNING: Removing unreachable block (ram,0xf0061f80) */
/* WARNING: Removing unreachable block (ram,0xf00620b0) */
/* WARNING: Removing unreachable block (ram,0xf00620e4) */
/* WARNING: Removing unreachable block (ram,0xf0062108) */
/* WARNING: Removing unreachable block (ram,0xf00621a0) */
/* WARNING: Removing unreachable block (ram,0xf00621dc) */
/* WARNING: Removing unreachable block (ram,0xf0062140) */
/* WARNING: Removing unreachable block (ram,0xf0061fd0) */
/* WARNING: Removing unreachable block (ram,0xf0061ff8) */
/* WARNING: Removing unreachable block (ram,0xf006215c) */
/* WARNING: Removing unreachable block (ram,0xf0062044) */
/* WARNING: Removing unreachable block (ram,0xf0061f38) */

undefined8
_mach_port_names(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  undefined4 unaff_l0;
  uint uVar6;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 uVar9;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar10;
  undefined4 unaff_i1;
  undefined4 *puVar11;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar12;
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
  if (param_1 == 0) {
loc_F0061F14:
    uVar10 = 0x10;
  }
  else {
    uVar6 = 0;
loc_F0061F28:
    do {
      do {
      } while (*(int *)(param_1 + 8) != 0);
      piVar1 = (int *)(param_1 + 8);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if (*(int *)(param_1 + 0xc) == 0) {
      *(undefined4 *)(param_1 + 8) = 0;
      if (uVar6 == 0) goto loc_F0061F14;
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar6);
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),uVar6);
      uVar10 = 0x10;
      goto locret_F0062240;
    }
    uVar2 = (*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x38)) * 4 + _page_mask;
    uVar7 = uVar2 & ~_page_mask;
    uVar10 = *(undefined4 *)((int)register0x00000038 + -0xc);
    if (uVar7 <= uVar6) {
      uVar9 = *(undefined4 *)((int)register0x00000038 + -0x10);
      *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
      _ipc_port_timestamp();
      uVar7 = 0;
      uVar8 = *(uint *)(param_1 + 0x18);
      puVar5 = *(uint **)(param_1 + 0x14);
      puVar11 = param_2;
      if (uVar8 != 0) {
        puVar11 = (undefined4 *)0x1f0000;
        do {
          if ((*puVar5 & 0x1f0000) != 0) {
            _mach_port_names_helper
                      (uVar2,puVar5,uVar7 << 8 | *puVar5 >> 0x18,uVar10,uVar9,
                       (undefined *)((int)register0x00000038 + -0x14));
          }
          uVar7 = uVar7 + 1;
          puVar5 = puVar5 + 4;
        } while (uVar7 < uVar8);
      }
      iVar3 = param_1 + 0x20;
      _ipc_splay_traverse_start();
      while (iVar3 != 0) {
        _mach_port_names_helper
                  (uVar2,iVar3,*(undefined4 *)(iVar3 + 0x10),uVar10,uVar9,
                   (undefined *)((int)register0x00000038 + -0x14));
        iVar3 = param_1 + 0x20;
        _ipc_splay_traverse_next(iVar3,0);
      }
      _ipc_splay_traverse_finish(param_1 + 0x20);
      iVar3 = *(int *)((int)register0x00000038 + -0x14);
      *(undefined4 *)(param_1 + 8) = 0;
      if (iVar3 == 0) {
        *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
        *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
        if (uVar6 != 0) {
          _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar6);
          iVar3 = *(int *)((int)register0x00000038 + -0x10);
loc_F0062214:
          _kmem_free(_ipc_kernel_map,iVar3,uVar6);
        }
      }
      else {
        uVar2 = iVar3 * 4 + _page_mask & ~_page_mask;
        _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc),
                         *(int *)((int)register0x00000038 + -0xc) + uVar2,1);
        _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0x10),
                         *(int *)((int)register0x00000038 + -0x10) + uVar2,1);
        _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),_ipc_soft_map,uVar2
                 ,1,(undefined *)((int)register0x00000038 + -0x18));
        _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),_ipc_soft_map,
                 uVar2,1,(undefined *)((int)register0x00000038 + -0x1c));
        bVar12 = uVar2 != uVar6;
        uVar6 = uVar6 - uVar2;
        if (bVar12) {
          _kmem_free(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc) + uVar2,uVar6);
          iVar3 = *(int *)((int)register0x00000038 + -0x10) + uVar2;
          goto loc_F0062214;
        }
      }
      *param_2 = *(undefined4 *)((int)register0x00000038 + -0x18);
      *param_3 = *(undefined4 *)((int)register0x00000038 + -0x14);
      *param_4 = *(undefined4 *)((int)register0x00000038 + -0x1c);
      uVar10 = 0;
      *param_5 = *(undefined4 *)((int)register0x00000038 + -0x14);
      param_2 = puVar11;
      goto locret_F0062240;
    }
    *(undefined4 *)(param_1 + 8) = 0;
    if (uVar6 != 0) {
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar6);
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),uVar6);
    }
    iVar3 = _ipc_kernel_map;
    _vm_allocate(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar7,1);
    if (iVar3 != 0) goto loc_F0062164;
    iVar3 = _ipc_kernel_map;
    _vm_allocate(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0x10),uVar7,1);
    iVar4 = *(int *)((int)register0x00000038 + -0xc);
    if (iVar3 == 0) {
      _vm_map_pageable(_ipc_kernel_map,iVar4,iVar4 + uVar7,0);
      _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0x10),
                       *(int *)((int)register0x00000038 + -0x10) + uVar7,0);
      uVar6 = uVar7;
      goto loc_F0061F28;
    }
    _kmem_free(_ipc_kernel_map,iVar4,uVar7);
loc_F0062164:
    uVar10 = 6;
  }
locret_F0062240:
  return CONCAT44(param_2,uVar10);
}
/* GHIDRADEC_FUNCTION index=1246 start=0xf0062248 */

/* WARNING: Removing unreachable block (ram,0xf0062288) */
/* WARNING: Removing unreachable block (ram,0xf0062264) */

undefined8 _mach_port_type(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = param_1;
    _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
    if ((iVar1 == 0) &&
       (iVar1 = param_1,
       _ipc_right_info(param_1,param_2,*(undefined4 *)((int)register0x00000038 + -0xc),param_3,
                       (undefined *)((int)register0x00000038 + -0x10)), iVar1 == 0)) {
      *(undefined4 *)(param_1 + 8) = 0;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1247 start=0xf00622a8 */

/* WARNING: Removing unreachable block (ram,0xf00622e4) */

undefined8 _mach_port_rename(int param_1,undefined4 param_2,int param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  if (param_1 == 0) {
    param_1 = 0x10;
  }
  else if ((param_3 == 0) || (param_3 == -1)) {
    param_1 = 0x12;
  }
  else {
    _ipc_object_rename(param_1,param_2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1248 start=0xf00622f8 */

/* WARNING: Removing unreachable block (ram,0xf0062388) */
/* WARNING: Removing unreachable block (ram,0xf0062350) */
/* WARNING: Removing unreachable block (ram,0xf006236c) */

undefined8 _mach_port_allocate_name(int param_1,uint param_2,int param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else if ((param_3 == 0) || (param_3 == -1)) {
    iVar1 = 0x12;
  }
  else if (param_2 == 3) {
    _ipc_pset_alloc_name(param_1,param_3,(undefined *)((int)register0x00000038 + -0x10));
    iVar1 = param_1;
    if (param_1 == 0) {
      **(undefined4 **)((int)register0x00000038 + -0x10) = 0;
    }
  }
  else if (param_2 < 4) {
    iVar1 = 0x12;
    if (param_2 == 1) {
      _ipc_port_alloc_name(param_1,param_3,(undefined *)((int)register0x00000038 + -0xc));
      iVar1 = param_1;
      if (param_1 == 0) {
        **(undefined4 **)((int)register0x00000038 + -0xc) = 0;
      }
    }
  }
  else {
    iVar1 = 0x12;
    if (param_2 == 4) {
      _ipc_object_alloc_dead_name();
      iVar1 = param_1;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1249 start=0xf00623a4 */

/* WARNING: Removing unreachable block (ram,0xf0062428) */
/* WARNING: Removing unreachable block (ram,0xf00623f0) */
/* WARNING: Removing unreachable block (ram,0xf006240c) */

undefined8 _mach_port_allocate(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else if (param_2 == 3) {
    _ipc_pset_alloc(param_1,param_3,(undefined *)((int)register0x00000038 + -0x10));
    iVar1 = param_1;
    if (param_1 == 0) {
      **(undefined4 **)((int)register0x00000038 + -0x10) = 0;
    }
  }
  else if (param_2 < 4) {
    iVar1 = 0x12;
    if (param_2 == 1) {
      _ipc_port_alloc(param_1,param_3,(undefined *)((int)register0x00000038 + -0xc));
      iVar1 = param_1;
      if (param_1 == 0) {
        **(undefined4 **)((int)register0x00000038 + -0xc) = 0;
      }
    }
  }
  else if (param_2 == 4) {
    _ipc_object_alloc_dead();
    iVar1 = param_1;
  }
  else {
    iVar1 = 0x12;
  }
  return CONCAT44(param_2,iVar1);
}

