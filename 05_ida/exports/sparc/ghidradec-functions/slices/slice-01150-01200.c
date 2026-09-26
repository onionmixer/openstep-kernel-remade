/* GHIDRADEC_FUNCTION index=1150 start=0xf005a55c */

/* WARNING: Removing unreachable block (ram,0xf005a700) */
/* WARNING: Removing unreachable block (ram,0xf005a654) */
/* WARNING: Removing unreachable block (ram,0xf005a5d4) */
/* WARNING: Removing unreachable block (ram,0xf005a6f0) */
/* WARNING: Removing unreachable block (ram,0xf005a5b4) */
/* WARNING: Removing unreachable block (ram,0xf005a5a0) */

undefined8 _ipc_port_dngrow(int *param_1,undefined4 param_2)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint *puVar8;
  undefined4 unaff_l4;
  uint *puVar9;
  undefined4 unaff_l5;
  uint *puVar10;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar11;
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
  puVar8 = (uint *)param_1[0xb];
  puVar10 = _ipc_table_dnrequests;
  if (puVar8 != (uint *)0x0) {
    puVar10 = (uint *)(puVar8[1] + 4);
  }
  param_1[1] = param_1[1] + 1;
  *param_1 = 0;
  if (*puVar10 != 0) {
    puVar1 = (uint *)(*puVar10 << 3);
    _ipc_table_alloc();
    if (puVar1 != (uint *)0x0) {
      do {
        do {
        } while (*param_1 != 0);
        piVar2 = param_1;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      param_1[1] = param_1[1] + -1;
      if (param_1[2] < 0) {
        if ((uint *)param_1[0xb] != puVar8) {
          iVar3 = param_1[1];
          goto loc_F005A6C8;
        }
        puVar9 = (uint *)0x0;
        if (puVar8 == (uint *)0x0) {
loc_F005A664:
          uVar4 = 1;
          uVar7 = 0;
          uVar6 = *puVar10;
        }
        else {
          if ((uint *)(puVar8[1] + 4) != puVar10) {
            iVar3 = param_1[1];
            goto loc_F005A6C8;
          }
          if (puVar8 == (uint *)0x0) goto loc_F005A664;
          puVar9 = (uint *)puVar8[1];
          uVar4 = *puVar9;
          uVar7 = *puVar8;
          _bcopy(puVar8 + 2,puVar1 + 2,(uVar4 - 1) * 8);
          uVar6 = *puVar10;
        }
        if (uVar4 < uVar6) {
          do {
            uVar5 = uVar4;
            puVar1[uVar5 * 2 + 1] = 0;
            puVar1[uVar5 * 2] = uVar7;
            uVar4 = uVar5 + 1;
            uVar7 = uVar5;
          } while (uVar5 + 1 < uVar6);
          *puVar1 = uVar5;
        }
        else {
          *puVar1 = uVar7;
        }
        puVar1[1] = (uint)puVar10;
        param_1[0xb] = (int)puVar1;
        *param_1 = 0;
        if (puVar8 != (uint *)0x0) {
          uVar4 = *puVar9;
          goto loc_F005A700;
        }
      }
      else {
        iVar3 = param_1[1];
loc_F005A6C8:
        *param_1 = 0;
        if (iVar3 == 0) {
          _zfree((&_ipc_object_zones)[(param_1[2] & 0x7fffffffU) >> 0x10],param_1);
        }
        uVar4 = *puVar10;
        puVar8 = puVar1;
loc_F005A700:
        _ipc_table_free(uVar4 << 3,puVar8);
      }
      uVar11 = 0;
      goto locret_F005A70C;
    }
  }
  _ipc_object_release(param_1);
  uVar11 = 6;
locret_F005A70C:
  return CONCAT44(param_2,uVar11);
}
/* GHIDRADEC_FUNCTION index=1151 start=0xf005a714 */

undefined8 _ipc_port_dncancel(int param_1,undefined4 param_2,int param_3)

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
  piVar1 = *(int **)(param_1 + 0x2c);
  iVar2 = piVar1[param_3 * 2];
  piVar1[param_3 * 2 + 1] = 0;
  piVar1[param_3 * 2] = *piVar1;
  *piVar1 = param_3;
  return CONCAT44(param_3 * 8,iVar2);
}
/* GHIDRADEC_FUNCTION index=1152 start=0xf005a740 */

undefined8 _ipc_port_pdrequest(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
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
  uVar1 = param_1[10];
  *param_1 = 0;
  param_1[10] = param_2;
  *param_3 = uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1153 start=0xf005a75c */

/* WARNING: Removing unreachable block (ram,0xf005a790) */

undefined8 _ipc_port_nsrequest(undefined4 *param_1,uint param_2,int param_3,undefined4 *param_4)

{
  undefined4 unaff_l0;
  undefined4 uVar1;
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
  uVar1 = param_1[9];
  if ((param_1[7] == 0) && (param_2 <= (uint)param_1[6])) {
    if (param_3 != 0) {
      param_1[9] = 0;
      *param_1 = 0;
      _ipc_notify_no_senders(param_3);
      *param_4 = uVar1;
      goto locret_F005A7AC;
    }
    param_1[9] = 0;
  }
  else {
    param_1[9] = param_3;
  }
  *param_1 = 0;
  *param_4 = uVar1;
locret_F005A7AC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1154 start=0xf005a7b4 */

/* WARNING: Removing unreachable block (ram,0xf005a7f0) */
/* WARNING: Removing unreachable block (ram,0xf005a7dc) */

undefined8 _ipc_port_set_qlimit(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint uVar3;
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
  uVar1 = *(uint *)(param_1 + 0x3c);
  if (uVar1 < param_2) {
    uVar3 = 0;
    if (param_2 == uVar1) {
      *(uint *)(param_1 + 0x3c) = param_2;
    }
    else {
      do {
        iVar2 = param_1 + 0x4c;
        _ipc_thread_dequeue();
        if (iVar2 == 0) {
          *(uint *)(param_1 + 0x3c) = param_2;
          goto locret_F005A80C;
        }
        *(undefined4 *)(iVar2 + 0x98) = 0;
        _thread_go();
        uVar3 = uVar3 + 1;
      } while (uVar3 < param_2 - uVar1);
      *(uint *)(param_1 + 0x3c) = param_2;
    }
  }
  else {
    *(uint *)(param_1 + 0x3c) = param_2;
  }
locret_F005A80C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1155 start=0xf005a814 */

/* WARNING: Removing unreachable block (ram,0xf005a8d0) */
/* WARNING: Removing unreachable block (ram,0xf005a878) */
/* WARNING: Removing unreachable block (ram,0xf005a898) */
/* WARNING: Removing unreachable block (ram,0xf005a8ec) */
/* WARNING: Removing unreachable block (ram,0xf005a840) */

undefined8 _ipc_port_lock_mqueue(int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
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
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    do {
      do {
      } while (*piVar1 != 0);
      piVar2 = piVar1;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    if (piVar1[2] < 0) {
      do {
        do {
        } while (piVar1[4] != 0);
        piVar2 = piVar1 + 4;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      *piVar1 = 0;
      piVar1 = piVar1 + 4;
      goto locret_F005A904;
    }
    _ipc_pset_remove(piVar1,param_1);
    *piVar1 = 0;
    if (piVar1[1] == 0) {
      _zfree((&_ipc_object_zones)[(piVar1[2] & 0x7fffffffU) >> 0x10],piVar1);
    }
  }
  do {
    do {
      piVar1 = (int *)(param_1 + 0x40);
    } while (*piVar1 != 0);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  piVar1 = (int *)(param_1 + 0x40);
locret_F005A904:
  return CONCAT44(param_2,piVar1);
}
/* GHIDRADEC_FUNCTION index=1156 start=0xf005a90c */

/* WARNING: Removing unreachable block (ram,0xf005a910) */

undefined8 _ipc_port_set_seqno(undefined4 *param_1,undefined4 param_2)

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
  puVar1 = param_1;
  _ipc_port_lock_mqueue();
  param_1[0xd] = param_2;
  *puVar1 = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1157 start=0xf005a928 */

/* WARNING: Removing unreachable block (ram,0xf005a9d0) */
/* WARNING: Removing unreachable block (ram,0xf005a998) */
/* WARNING: Removing unreachable block (ram,0xf005a960) */
/* WARNING: Removing unreachable block (ram,0xf005a9b8) */
/* WARNING: Removing unreachable block (ram,0xf005a9f4) */
/* WARNING: Removing unreachable block (ram,0xf005a94c) */

undefined8 _ipc_port_clear_receiver(int param_1,undefined4 param_2)

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
  piVar2 = *(int **)(param_1 + 0x30);
  if (piVar2 == (int *)0x0) {
    do {
      do {
      } while (*(int *)(param_1 + 0x40) != 0);
      piVar2 = (int *)(param_1 + 0x40);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    _ipc_mqueue_changed(param_1 + 0x40,0x10004009);
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else {
    do {
      do {
      } while (*piVar2 != 0);
      piVar1 = piVar2;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    _ipc_pset_remove(piVar2,param_1);
    *piVar2 = 0;
    if (piVar2[1] == 0) {
      _zfree((&_ipc_object_zones)[(piVar2[2] & 0x7fffffffU) >> 0x10],piVar2);
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
  }
  do {
    do {
    } while (*(int *)(param_1 + 0x40) != 0);
    piVar2 = (int *)(param_1 + 0x40);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1158 start=0xf005aa18 */

/* WARNING: Removing unreachable block (ram,0xf005aa50) */

undefined8 _ipc_port_init(int param_1,undefined4 param_2,undefined4 param_3)

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
  *(undefined4 *)(param_1 + 0xc) = param_2;
  *(undefined4 *)(param_1 + 0x10) = param_3;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 5;
  _ipc_mqueue_init(param_1 + 0x40);
  *(undefined4 *)(param_1 + 0x4c) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1159 start=0xf005aa64 */

/* WARNING: Removing unreachable block (ram,0xf005aa98) */
/* WARNING: Removing unreachable block (ram,0xf005aa7c) */

undefined8 _ipc_port_alloc(int param_1,undefined4 *param_2,undefined4 *param_3)

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
  iVar1 = param_1;
  _ipc_object_alloc(param_1,0,0x20000,0,(undefined *)((int)register0x00000038 + -0xc),
                    (undefined *)((int)register0x00000038 + -0x10));
  if (iVar1 == 0) {
    _ipc_port_init(*(undefined4 *)((int)register0x00000038 + -0x10),param_1,
                   *(undefined4 *)((int)register0x00000038 + -0xc));
    *param_2 = *(undefined4 *)((int)register0x00000038 + -0xc);
    iVar1 = 0;
    *param_3 = *(undefined4 *)((int)register0x00000038 + -0x10);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1160 start=0xf005aabc */

/* WARNING: Removing unreachable block (ram,0xf005aaf0) */
/* WARNING: Removing unreachable block (ram,0xf005aad4) */

undefined8 _ipc_port_alloc_name(int param_1,undefined4 param_2,undefined4 *param_3)

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
  iVar1 = param_1;
  _ipc_object_alloc_name(param_1,0,0x20000,0,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 == 0) {
    _ipc_port_init(*(undefined4 *)((int)register0x00000038 + -0xc),param_1,param_2);
    iVar1 = 0;
    *param_3 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1161 start=0xf005ab0c */

/* WARNING: Removing unreachable block (ram,0xf005ab7c) */
/* WARNING: Removing unreachable block (ram,0xf005ab3c) */
/* WARNING: Removing unreachable block (ram,0xf005ab50) */
/* WARNING: Removing unreachable block (ram,0xf005ab84) */
/* WARNING: Removing unreachable block (ram,0xf005ab18) */

undefined8 _ipc_port_delete_compat(int param_1,int param_2,undefined4 param_3)

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
  iVar1 = param_2;
  _ipc_right_lookup_write(param_2,param_3,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 == 0) {
    if (*(int *)(*(int *)((int)register0x00000038 + -0xc) + 4) == param_1) {
      param_1 = *(int *)(param_2 + 0x44);
      _ipc_port_copy_send();
      _ipc_right_destroy(param_2,param_3,*(undefined4 *)((int)register0x00000038 + -0xc));
    }
    else {
      *(undefined4 *)(param_2 + 8) = 0;
      param_1 = 0;
    }
    if ((param_1 != 0) && (param_1 != -1)) {
      _ipc_notify_port_deleted_compat(param_1,param_3);
    }
  }
  _ipc_space_release(param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1162 start=0xf005ab94 */

/* WARNING: Removing unreachable block (ram,0xf005acf0) */
/* WARNING: Removing unreachable block (ram,0xf005accc) */
/* WARNING: Removing unreachable block (ram,0xf005adac) */
/* WARNING: Removing unreachable block (ram,0xf005ad58) */
/* WARNING: Removing unreachable block (ram,0xf005acb4) */
/* WARNING: Removing unreachable block (ram,0xf005ac88) */
/* WARNING: Removing unreachable block (ram,0xf005ac40) */
/* WARNING: Removing unreachable block (ram,0xf005abe8) */
/* WARNING: Removing unreachable block (ram,0xf005abc8) */
/* WARNING: Removing unreachable block (ram,0xf005ac08) */
/* WARNING: Removing unreachable block (ram,0xf005ac14) */
/* WARNING: Removing unreachable block (ram,0xf005abdc) */
/* WARNING: Removing unreachable block (ram,0xf005ac2c) */
/* WARNING: Removing unreachable block (ram,0xf005ac68) */
/* WARNING: Removing unreachable block (ram,0xf005aca0) */
/* WARNING: Removing unreachable block (ram,0xf005ad6c) */
/* WARNING: Removing unreachable block (ram,0xf005ad8c) */
/* WARNING: Removing unreachable block (ram,0xf005adb4) */
/* WARNING: Removing unreachable block (ram,0xf005acd8) */
/* WARNING: Removing unreachable block (ram,0xf005ac54) */
/* WARNING: Removing unreachable block (ram,0xf005abf4) */

undefined8 _ipc_port_destroy(int *param_1,undefined4 param_2)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  uint uVar6;
  undefined4 unaff_l3;
  uint *puVar7;
  undefined4 unaff_l4;
  uint *puVar8;
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
  uVar5 = param_1[10];
  if (uVar5 != 0) {
    param_1[10] = 0;
    param_1[4] = 0;
    param_1[3] = 0;
    *param_1 = 0;
    if ((uVar5 & 1) == 0) {
      piVar2 = param_1;
      _ipc_port_check_circularity(param_1,uVar5);
      if (piVar2 == (int *)0x0) {
        _ipc_notify_port_destroyed(uVar5,param_1);
        goto locret_F005ADBC;
      }
      _ipc_port_release_sonce(uVar5);
    }
    else {
      uVar5 = uVar5 & 0xfffffffe;
      piVar2 = param_1;
      _ipc_port_check_circularity(param_1,uVar5);
      if (piVar2 == (int *)0x0) {
        _ipc_notify_port_destroyed_compat(uVar5,param_1);
        goto locret_F005ADBC;
      }
      _ipc_port_release_send(uVar5);
    }
    do {
      do {
      } while (*param_1 != 0);
      piVar2 = param_1;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
  }
  while( true ) {
    piVar2 = param_1 + 0x13;
    _ipc_thread_dequeue();
    if (piVar2 == (int *)0x0) break;
    piVar2[0x26] = 0;
    _thread_go();
  }
  uVar5 = param_1[2] & 0x7fffffff;
  param_1[2] = uVar5;
  _ipc_port_timestamp();
  param_1[3] = uVar5;
  *param_1 = 0;
  piVar2 = param_1 + 0x10;
  if (param_1[9] != 0) {
    _ipc_notify_send_once();
  }
  do {
    do {
    } while (*piVar2 != 0);
    piVar3 = piVar2;
    _simple_lock_try();
  } while (piVar3 == (int *)0x0);
  while (piVar3 = param_1 + 0x11, _ipc_kmsg_dequeue(), piVar3 != (int *)0x0) {
    *piVar2 = 0;
    _ipc_object_release(param_1);
    piVar3[7] = 0;
    _ipc_kmsg_destroy(piVar3);
    do {
      do {
      } while (*piVar2 != 0);
      piVar3 = piVar2;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
  }
  *piVar2 = 0;
  puVar7 = (uint *)param_1[0xb];
  if (puVar7 == (uint *)0x0) {
    uVar5 = param_1[2];
  }
  else {
    puVar8 = (uint *)puVar7[1];
    uVar6 = *puVar8;
    uVar5 = 1;
    puVar1 = puVar7;
    if (uVar6 < 2) {
      uVar5 = *puVar8;
    }
    else {
      do {
        if (puVar1[3] != 0) {
          uVar4 = puVar1[2];
          if ((uVar4 & 1) == 0) {
            _ipc_notify_dead_name(uVar4,puVar1[3]);
          }
          else {
            _ipc_port_delete_compat(param_1,uVar4 & 0xfffffffe);
          }
        }
        uVar5 = uVar5 + 1;
        puVar1 = puVar1 + 2;
      } while (uVar5 < uVar6);
      uVar5 = *puVar8;
    }
    _ipc_table_free(uVar5 << 3,puVar7);
    uVar5 = param_1[2];
  }
  if ((uVar5 & 0xffff) != 0) {
    _ipc_kobject_destroy(param_1);
  }
  _ipc_object_release(param_1);
locret_F005ADBC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1163 start=0xf005adc4 */

/* WARNING: Removing unreachable block (ram,0xf005ae80) */
/* WARNING: Removing unreachable block (ram,0xf005adf8) */
/* WARNING: Removing unreachable block (ram,0xf005ae5c) */
/* WARNING: Removing unreachable block (ram,0xf005af10) */
/* WARNING: Removing unreachable block (ram,0xf005ade4) */

undefined8 _ipc_port_check_circularity(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  if (param_1 == param_2) {
loc_F005AEF8:
    uVar6 = 1;
  }
  else {
    do {
      do {
      } while (*param_1 != 0);
      piVar1 = param_1;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    piVar1 = param_2;
    _simple_lock_try();
    if (piVar1 == (int *)0x0) {
loc_F005AE40:
      *param_1 = 0;
      do {
        do {
        } while (_ipc_port_multiple_lock_data != 0);
        puVar3 = &_ipc_port_multiple_lock_data;
        _simple_lock_try();
        piVar5 = param_2;
      } while (puVar3 == (undefined4 *)0x0);
      do {
        do {
          piVar1 = piVar5;
          piVar5 = piVar1;
        } while (*piVar1 != 0);
        piVar4 = piVar1;
        _simple_lock_try();
      } while ((piVar4 == (int *)0x0) ||
              (((piVar1[2] < 0 && (piVar1[4] == 0)) &&
               (piVar5 = (int *)piVar1[3], (int *)piVar1[3] != (int *)0x0))));
      if (param_1 == piVar1) {
        _ipc_port_multiple_lock_data = 0;
        if (param_2 == (int *)0x0) {
          uVar6 = 1;
          goto locret_F005AF60;
        }
        piVar1 = (int *)param_2[3];
        while( true ) {
          piVar5 = piVar1;
          *param_2 = 0;
          param_2 = (int *)0x0;
          if (piVar5 == (int *)0x0) break;
          piVar1 = (int *)piVar5[3];
          param_2 = piVar5;
        }
        goto loc_F005AEF8;
      }
      do {
        do {
        } while (*param_1 != 0);
        piVar5 = param_1;
        _simple_lock_try();
      } while (piVar5 == (int *)0x0);
      _ipc_port_multiple_lock_data = 0;
      iVar2 = param_2[1];
    }
    else {
      piVar1 = param_2;
      if (param_2[2] < 0) {
        if (param_2[4] == 0) {
          if (param_2[3] != 0) {
            *param_2 = 0;
            goto loc_F005AE40;
          }
          iVar2 = param_2[1];
        }
        else {
          iVar2 = param_2[1];
        }
      }
      else {
        iVar2 = param_2[1];
      }
    }
    param_2[1] = iVar2 + 1;
    param_1[3] = (int)param_2;
    if (param_1 != piVar1) {
      piVar5 = (int *)param_1[3];
      while (piVar4 = piVar5, *param_1 = 0, piVar4 != piVar1) {
        param_1 = piVar4;
        piVar5 = (int *)piVar4[3];
      }
    }
    *piVar1 = 0;
    uVar6 = 0;
  }
locret_F005AF60:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=1164 start=0xf005af68 */

/* WARNING: Removing unreachable block (ram,0xf005afac) */
/* WARNING: Removing unreachable block (ram,0xf005af70) */

undefined8 _ipc_port_lookup_notify(uint *param_1,undefined4 param_2)

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
  int *piVar2;
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
  _ipc_entry_lookup(param_1,param_2);
  if ((param_1 == (uint *)0x0) || ((*param_1 & 0x20000) == 0)) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)param_1[1];
    do {
      do {
      } while (*piVar2 != 0);
      piVar1 = piVar2;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    piVar2[1] = piVar2[1] + 1;
    piVar2[8] = piVar2[8] + 1;
    *piVar2 = 0;
  }
  return CONCAT44(param_2,piVar2);
}
/* GHIDRADEC_FUNCTION index=1165 start=0xf005afe4 */

/* WARNING: Removing unreachable block (ram,0xf005aff8) */

undefined8 _ipc_port_make_send(int *param_1,undefined4 param_2)

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
  param_1[6] = param_1[6] + 1;
  param_1[7] = param_1[7] + 1;
  param_1[1] = param_1[1] + 1;
  *param_1 = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1166 start=0xf005b03c */

/* WARNING: Removing unreachable block (ram,0xf005b064) */

undefined8 _ipc_port_copy_send(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
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
  piVar2 = param_1;
  if ((param_1 != (int *)0x0) && (param_1 != (int *)0xffffffff)) {
    do {
      do {
      } while (*param_1 != 0);
      piVar1 = param_1;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if (param_1[2] < 0) {
      param_1[1] = param_1[1] + 1;
      param_1[7] = param_1[7] + 1;
    }
    else {
      piVar2 = (int *)0xffffffff;
    }
    *param_1 = 0;
  }
  return CONCAT44(param_2,piVar2);
}
/* GHIDRADEC_FUNCTION index=1167 start=0xf005b0b4 */

/* WARNING: Removing unreachable block (ram,0xf005b0ec) */
/* WARNING: Removing unreachable block (ram,0xf005b0d8) */

undefined8 _ipc_port_copyout_send(int param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if ((param_1 == 0) || (param_1 == -1)) {
    *(int *)((int)register0x00000038 + -0xc) = param_1;
  }
  else {
    _ipc_object_copyout(param_2,param_1,0x11,1,(undefined *)((int)register0x00000038 + -0xc));
    if (param_2 == 0) {
      uVar1 = *(undefined4 *)((int)register0x00000038 + -0xc);
      goto locret_F005B114;
    }
    _ipc_port_release_send(param_1);
    if (param_2 == 0x14) {
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0xffffffff;
    }
    else {
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    }
  }
  uVar1 = *(undefined4 *)((int)register0x00000038 + -0xc);
locret_F005B114:
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1168 start=0xf005b11c */

/* WARNING: Removing unreachable block (ram,0xf005b190) */
/* WARNING: Removing unreachable block (ram,0xf005b1d4) */
/* WARNING: Removing unreachable block (ram,0xf005b138) */

undefined8 _ipc_port_release_send(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
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
  iVar3 = 0;
  iVar4 = 0;
  do {
    do {
    } while (*param_1 != 0);
    piVar1 = param_1;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  iVar2 = param_1[1];
  param_1[1] = iVar2 + -1;
  if (param_1[2] < 0) {
    iVar2 = param_1[7];
    param_1[7] = iVar2 + -1;
    if ((iVar2 + -1 == 0) && (iVar3 = param_1[9], iVar3 != 0)) {
      param_1[9] = 0;
      iVar4 = param_1[6];
    }
    *param_1 = 0;
    if (iVar3 != 0) {
      _ipc_notify_no_senders(iVar3,iVar4);
    }
  }
  else {
    *param_1 = 0;
    if (iVar2 + -1 == 0) {
      _zfree((&_ipc_object_zones)[(param_1[2] & 0x7fffffffU) >> 0x10],param_1);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1169 start=0xf005b1e4 */

/* WARNING: Removing unreachable block (ram,0xf005b1f8) */

undefined8 _ipc_port_make_sonce(int *param_1,undefined4 param_2)

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
  param_1[8] = param_1[8] + 1;
  param_1[1] = param_1[1] + 1;
  *param_1 = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1170 start=0xf005b230 */

/* WARNING: Removing unreachable block (ram,0xf005b29c) */
/* WARNING: Removing unreachable block (ram,0xf005b244) */

undefined8 _ipc_port_release_sonce(int *param_1,undefined4 param_2)

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
  param_1[1] = iVar2 + -1;
  if (param_1[2] < 0) {
    *param_1 = 0;
    param_1[8] = param_1[8] + -1;
  }
  else {
    *param_1 = 0;
    if (iVar2 + -1 == 0) {
      _zfree((&_ipc_object_zones)[(param_1[2] & 0x7fffffffU) >> 0x10],param_1);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1171 start=0xf005b2bc */

/* WARNING: Removing unreachable block (ram,0xf005b2e8) */
/* WARNING: Removing unreachable block (ram,0xf005b2fc) */
/* WARNING: Removing unreachable block (ram,0xf005b2d0) */

undefined8 _ipc_port_release_receive(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = param_1[3];
  _ipc_port_destroy(param_1);
  if (iVar2 != 0) {
    _ipc_object_release(iVar2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1172 start=0xf005b30c */

/* WARNING: Removing unreachable block (ram,0xf005b344) */
/* WARNING: Removing unreachable block (ram,0xf005b318) */

undefined8 _ipc_port_alloc_special(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar1;
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
  puVar1 = _ipc_object_zones;
  _zalloc();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 1;
    puVar1[2] = 0x80000000;
    _ipc_port_init(puVar1,param_1,1);
  }
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=1173 start=0xf005b35c */

/* WARNING: Removing unreachable block (ram,0xf005b38c) */
/* WARNING: Removing unreachable block (ram,0xf005b394) */
/* WARNING: Removing unreachable block (ram,0xf005b370) */

undefined8 _ipc_port_dealloc_special(int *param_1,undefined4 param_2)

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
  param_1[4] = 0;
  param_1[3] = 0;
  _ipc_port_clear_receiver(param_1);
  _ipc_port_destroy(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1174 start=0xf005b3a4 */

/* WARNING: Removing unreachable block (ram,0xf005b424) */
/* WARNING: Removing unreachable block (ram,0xf005b4f0) */
/* WARNING: Removing unreachable block (ram,0xf005b464) */
/* WARNING: Removing unreachable block (ram,0xf005b3d4) */
/* WARNING: Removing unreachable block (ram,0xf005b400) */
/* WARNING: Removing unreachable block (ram,0xf005b494) */
/* WARNING: Removing unreachable block (ram,0xf005b414) */
/* WARNING: Removing unreachable block (ram,0xf005b3ec) */
/* WARNING: Removing unreachable block (ram,0xf005b3b0) */

undefined8 _ipc_port_alloc_compat(uint param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint *puVar1;
  int *piVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar10;
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
  piVar2 = _ipc_object_zones;
  _zalloc();
  puVar1 = _ipc_table_dnrequests;
  if (piVar2 == (int *)0x0) {
    uVar10 = 6;
  }
  else {
    puVar3 = (uint *)(*_ipc_table_dnrequests << 3);
    _ipc_table_alloc();
    if (puVar3 == (uint *)0x0) {
      _zfree(_ipc_object_zones,piVar2);
      uVar10 = 6;
    }
    else {
      uVar10 = param_1;
      _ipc_entry_alloc(param_1,(undefined *)((int)register0x00000038 + -0xc),
                       (undefined *)((int)register0x00000038 + -0x10));
      if (uVar10 == 0) {
        puVar6 = *(uint **)((int)register0x00000038 + -0x10);
        puVar6[2] = 1;
        puVar6[1] = (uint)piVar2;
        *puVar6 = *puVar6 | 0x420000;
        *piVar2 = 0;
        do {
          do {
          } while (*piVar2 != 0);
          piVar4 = piVar2;
          _simple_lock_try();
        } while (piVar4 == (int *)0x0);
        *(undefined4 *)(param_1 + 8) = 0;
        piVar2[1] = 1;
        piVar2[2] = -0x80000000;
        _ipc_port_init(piVar2,param_1,*(undefined4 *)((int)register0x00000038 + -0xc));
        uVar9 = *puVar1;
        uVar10 = 0;
        if (2 < uVar9) {
          iVar5 = 0x10;
          uVar7 = 2;
          uVar8 = uVar10;
          do {
            uVar10 = uVar7;
            *(undefined4 *)((int)puVar3 + iVar5 + 4) = 0;
            *(uint *)((int)puVar3 + iVar5) = uVar8;
            uVar7 = uVar10 + 1;
            iVar5 = uVar7 * 8;
            uVar8 = uVar10;
          } while (uVar7 < uVar9);
        }
        *puVar3 = uVar10;
        puVar3[1] = (uint)puVar1;
        piVar2[0xb] = (int)puVar3;
        puVar3[2] = param_1 | 1;
        puVar3[3] = *(uint *)((int)register0x00000038 + -0xc);
        _ipc_space_reference(param_1);
        uVar10 = 0;
        *param_2 = *(undefined4 *)((int)register0x00000038 + -0xc);
        *param_3 = piVar2;
      }
      else {
        _zfree(_ipc_object_zones,piVar2);
        _ipc_table_free(*puVar1 << 3,puVar3);
      }
    }
  }
  return CONCAT44(param_2,uVar10);
}
/* GHIDRADEC_FUNCTION index=1175 start=0xf005b510 */

/* WARNING: Removing unreachable block (ram,0xf005b544) */
/* WARNING: Removing unreachable block (ram,0xf005b530) */

undefined8 _ipc_port_copyout_send_compat(int param_1,int param_2)

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
  if ((param_1 == 0) || (param_1 == -1)) {
    *(int *)((int)register0x00000038 + -0xc) = param_1;
  }
  else {
    iVar1 = param_2;
    _ipc_object_copyout_compat(param_2,param_1,0x11,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 == 0) {
      uVar2 = *(undefined4 *)((int)register0x00000038 + -0xc);
      goto locret_F005B55C;
    }
    _ipc_port_release_send(param_1);
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  }
  uVar2 = *(undefined4 *)((int)register0x00000038 + -0xc);
locret_F005B55C:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1176 start=0xf005b564 */

/* WARNING: Removing unreachable block (ram,0xf005b5f4) */
/* WARNING: Removing unreachable block (ram,0xf005b594) */

undefined8 _ipc_port_copyout_receiver(int *param_1,int param_2)

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
  if ((param_1 == (int *)0x0) || (param_1 == (int *)0xffffffff)) {
    iVar3 = 0;
  }
  else {
    do {
      do {
      } while (*param_1 != 0);
      piVar1 = param_1;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    iVar3 = 0;
    if (param_1[3] == param_2) {
      iVar3 = param_1[4];
    }
    iVar2 = param_1[1];
    param_1[1] = iVar2 + -1;
    *param_1 = 0;
    if (iVar2 + -1 == 0) {
      _zfree((&_ipc_object_zones)[(param_1[2] & 0x7fffffffU) >> 0x10],param_1);
    }
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=1177 start=0xf005b608 */

/* WARNING: Removing unreachable block (ram,0xf005b63c) */
/* WARNING: Removing unreachable block (ram,0xf005b620) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf005b620 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int _ipc_pset_alloc(undefined4 *param_1)

{
  undefined8 in_o0_1;
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
  iVar1 = (int)((qword)in_o0_1 >> 0x20);
  _ipc_object_alloc(iVar1,(undefined4 *)in_o0_1,0x80000,0,
                    (undefined *)((int)register0x00000038 + -0xc),
                    (undefined *)((int)register0x00000038 + -0x10));
  if (iVar1 == 0) {
    iVar1 = (int)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20);
    *(int *)(iVar1 + 0xc) = (int)*(undefined8 *)((int)register0x00000038 + -0x10);
    _ipc_mqueue_init(iVar1 + 0x10);
    *(undefined4 *)in_o0_1 = *(undefined4 *)((int)register0x00000038 + -0xc);
    iVar1 = 0;
    *param_1 = *(undefined4 *)((int)register0x00000038 + -0x10);
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1178 start=0xf005b660 */

/* WARNING: Removing unreachable block (ram,0xf005b694) */
/* WARNING: Removing unreachable block (ram,0xf005b678) */

undefined8 _ipc_pset_alloc_name(int param_1,undefined4 param_2,undefined4 *param_3)

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
  _ipc_object_alloc_name(param_1,1,0x80000,0,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (param_1 == 0) {
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    *(undefined4 *)(iVar1 + 0xc) = param_2;
    _ipc_mqueue_init(iVar1 + 0x10);
    param_1 = 0;
    *param_3 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1179 start=0xf005b6b0 */

/* WARNING: Removing unreachable block (ram,0xf005b71c) */
/* WARNING: Removing unreachable block (ram,0xf005b700) */
/* WARNING: Removing unreachable block (ram,0xf005b730) */
/* WARNING: Removing unreachable block (ram,0xf005b6d8) */

undefined8 _ipc_pset_add(int param_1,int param_2)

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
  *(int *)(param_2 + 0x30) = param_1;
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  do {
    do {
    } while (*(int *)(param_2 + 0x40) != 0);
    piVar1 = (int *)(param_2 + 0x40);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  do {
    do {
    } while (*(int *)(param_1 + 0x10) != 0);
    piVar1 = (int *)(param_1 + 0x10);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  _ipc_mqueue_move(param_1 + 0x10,param_2 + 0x40,param_2);
  *(undefined4 *)(param_1 + 0x10) = 0;
  _ipc_mqueue_changed(param_2 + 0x40,0x10004006);
  *(undefined4 *)(param_2 + 0x40) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1180 start=0xf005b744 */

/* WARNING: Removing unreachable block (ram,0xf005b794) */
/* WARNING: Removing unreachable block (ram,0xf005b7ac) */
/* WARNING: Removing unreachable block (ram,0xf005b76c) */

undefined8 _ipc_pset_remove(int param_1,int param_2)

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
  *(undefined4 *)(param_2 + 0x30) = 0;
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
  do {
    do {
    } while (*(int *)(param_2 + 0x40) != 0);
    piVar1 = (int *)(param_2 + 0x40);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  do {
    do {
    } while (*(int *)(param_1 + 0x10) != 0);
    piVar1 = (int *)(param_1 + 0x10);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  _ipc_mqueue_move(param_2 + 0x40,param_1 + 0x10,param_2);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_2 + 0x40) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1181 start=0xf005b7c4 */

/* WARNING: Removing unreachable block (ram,0xf005b81c) */
/* WARNING: Removing unreachable block (ram,0xf005b878) */
/* WARNING: Removing unreachable block (ram,0xf005b9c0) */
/* WARNING: Removing unreachable block (ram,0xf005b978) */
/* WARNING: Removing unreachable block (ram,0xf005b8ec) */
/* WARNING: Removing unreachable block (ram,0xf005b938) */
/* WARNING: Removing unreachable block (ram,0xf005b95c) */
/* WARNING: Removing unreachable block (ram,0xf005b910) */
/* WARNING: Removing unreachable block (ram,0xf005b984) */
/* WARNING: Removing unreachable block (ram,0xf005b864) */
/* WARNING: Removing unreachable block (ram,0xf005b8c4) */
/* WARNING: Removing unreachable block (ram,0xf005b838) */
/* WARNING: Removing unreachable block (ram,0xf005b7d8) */

undefined8 _ipc_pset_move(int param_1,int *param_2,int *param_3)

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
  uint uVar3;
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
    } while (*param_2 != 0);
    piVar2 = param_2;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  piVar2 = (int *)param_2[0xc];
  if (piVar2 == param_3) {
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else if (piVar2 == (int *)0x0) {
    do {
      do {
      } while (*param_3 != 0);
      piVar1 = param_3;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    *(undefined4 *)(param_1 + 8) = 0;
    _ipc_pset_add(param_3,param_2);
    *param_3 = 0;
  }
  else if (param_3 == (int *)0x0) {
    *(undefined4 *)(param_1 + 8) = 0;
    do {
      do {
      } while (*piVar2 != 0);
      piVar1 = piVar2;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    _ipc_pset_remove(piVar2,param_2);
    if (piVar2[2] < 0) {
      *piVar2 = 0;
    }
    else {
      *piVar2 = 0;
      if (piVar2[1] == 0) {
        _zfree((&_ipc_object_zones)[(piVar2[2] & 0x7fffffffU) >> 0x10],piVar2);
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = (int *)0x0;
      }
    }
  }
  else {
    if (piVar2 < param_3) {
      do {
        do {
        } while (*piVar2 != 0);
        piVar1 = piVar2;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      do {
        do {
        } while (*param_3 != 0);
        piVar1 = param_3;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
    }
    else {
      do {
        do {
        } while (*param_3 != 0);
        piVar1 = param_3;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      do {
        do {
        } while (*piVar2 != 0);
        piVar1 = piVar2;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
    }
    *(undefined4 *)(param_1 + 8) = 0;
    _ipc_pset_remove(piVar2,param_2);
    _ipc_pset_add(param_3,param_2);
    *param_3 = 0;
    *piVar2 = 0;
    if (piVar2[1] == 0) {
      _zfree((&_ipc_object_zones)[(piVar2[2] & 0x7fffffffU) >> 0x10],piVar2);
    }
  }
  *param_2 = 0;
  uVar3 = 0;
  if (param_3 == (int *)0x0) {
    uVar3 = (piVar2 != (int *)0x0) - 1 & 0xc;
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1182 start=0xf005b9ec */

/* WARNING: Removing unreachable block (ram,0xf005ba2c) */
/* WARNING: Removing unreachable block (ram,0xf005ba6c) */
/* WARNING: Removing unreachable block (ram,0xf005ba14) */

undefined8 _ipc_pset_destroy(undefined4 *param_1,undefined4 param_2)

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
  param_1[2] = param_1[2] & 0x7fffffff;
  do {
    do {
    } while (param_1[4] != 0);
    piVar1 = param_1 + 4;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  _ipc_mqueue_changed(param_1 + 4,0x10004009);
  param_1[4] = 0;
  iVar2 = param_1[1];
  param_1[1] = iVar2 + -1;
  *param_1 = 0;
  if (iVar2 + -1 == 0) {
    _zfree((&_ipc_object_zones)[(param_1[2] & 0x7fffffff) >> 0x10],param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1183 start=0xf005ba7c */

/* WARNING: Removing unreachable block (ram,0xf005bac4) */
/* WARNING: Removing unreachable block (ram,0xf005ba94) */

undefined8 _ipc_right_lookup_write(int param_1,undefined4 param_2,int *param_3)

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
  undefined4 uVar3;
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
  if (*(int *)(param_1 + 0xc) == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    uVar3 = 0x10;
  }
  else {
    iVar2 = param_1;
    _ipc_entry_lookup(param_1,param_2);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 8) = 0;
      uVar3 = 0xf;
    }
    else {
      *param_3 = iVar2;
      uVar3 = 0;
    }
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1184 start=0xf005baf4 */

/* WARNING: Removing unreachable block (ram,0xf005bb40) */
/* WARNING: Removing unreachable block (ram,0xf005bb5c) */
/* WARNING: Removing unreachable block (ram,0xf005bb08) */

undefined8 _ipc_right_reverse(int param_1,int *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
    } while (*param_2 != 0);
    piVar1 = param_2;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (param_2[2] < 0) {
    if (param_2[3] == param_1) {
      iVar2 = param_2[4];
      _ipc_entry_lookup(param_1,iVar2);
      *param_3 = iVar2;
      *param_4 = param_1;
      uVar3 = 1;
      goto locret_F005BB80;
    }
    _ipc_hash_lookup(param_1,param_2,param_3,param_4);
    uVar3 = 1;
    if (param_1 != 0) goto locret_F005BB80;
  }
  *param_2 = 0;
  uVar3 = 0;
locret_F005BB80:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1185 start=0xf005bb88 */

/* WARNING: Removing unreachable block (ram,0xf005bc70) */
/* WARNING: Removing unreachable block (ram,0xf005bc20) */
/* WARNING: Removing unreachable block (ram,0xf005bbdc) */
/* WARNING: Removing unreachable block (ram,0xf005bd34) */
/* WARNING: Removing unreachable block (ram,0xf005bc50) */
/* WARNING: Removing unreachable block (ram,0xf005bc88) */
/* WARNING: Removing unreachable block (ram,0xf005bba8) */

undefined8
_ipc_right_dnrequest
          (undefined4 *param_1,undefined4 param_2,int param_3,int param_4,undefined4 *param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 unaff_l0;
  undefined4 *puVar4;
  undefined4 unaff_l1;
  uint uVar5;
  undefined4 *puVar6;
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
  while (puVar4 = param_1,
        _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc)),
        puVar4 == (undefined4 *)0x0) {
    uVar5 = **(uint **)((int)register0x00000038 + -0xc);
    if ((uVar5 & 0x70000) == 0) {
loc_F005BCDC:
      if ((((uVar5 & 0x100000) == 0) || (param_3 == 0)) || (param_4 == 0)) {
        param_1[2] = 0;
        puVar4 = (undefined4 *)0x11;
        if ((uVar5 & 0x170000) != 0) {
          puVar4 = (undefined4 *)0x4;
        }
      }
      else {
        uVar2 = (uVar5 & 0xffff) + 1;
        if (((uVar5 & 0xffff) < uVar2) && (uVar2 < 0x10000)) {
          **(int **)((int)register0x00000038 + -0xc) = uVar5 + 1;
          param_1[2] = 0;
          _ipc_notify_dead_name(param_4,param_2);
          *param_5 = 0;
loc_F005BD60:
          puVar4 = (undefined4 *)0x0;
        }
        else {
          param_1[2] = 0;
          puVar4 = (undefined4 *)0x13;
        }
      }
      break;
    }
    puVar4 = (undefined4 *)(*(uint **)((int)register0x00000038 + -0xc))[1];
    puVar6 = param_1;
    _ipc_right_check(param_1,puVar4,param_2);
    if (puVar6 != (undefined4 *)0x0) {
      if ((uVar5 & 0x400000) == 0) {
        uVar5 = **(uint **)((int)register0x00000038 + -0xc);
        goto loc_F005BCDC;
      }
      param_1[2] = 0;
      puVar4 = (undefined4 *)0xf;
      break;
    }
    if (param_4 == 0) {
      puVar6 = (undefined4 *)0x0;
      if (((uVar5 & 0x400000) == 0) && (*(int *)(*(int *)((int)register0x00000038 + -0xc) + 8) != 0)
         ) {
        puVar6 = param_1;
        _ipc_right_dncancel(param_1,puVar4,param_2);
      }
      *puVar4 = 0;
      param_1[2] = 0;
      *param_5 = puVar6;
      goto loc_F005BD60;
    }
    if (*(int *)(*(int *)((int)register0x00000038 + -0xc) + 8) == 0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      puVar6 = param_1;
      _ipc_right_dncancel(param_1,puVar4,param_2);
    }
    puVar1 = puVar4;
    _ipc_port_dnrequest(puVar4,param_2,param_4,(undefined *)((int)register0x00000038 + -0x10));
    puVar3 = *(uint **)((int)register0x00000038 + -0xc);
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = *(uint *)((int)register0x00000038 + -0x10);
      *puVar4 = 0;
      puVar3[2] = uVar2;
      *puVar3 = uVar5 & 0xffbfffff;
      param_1[2] = 0;
      *param_5 = puVar6;
      goto loc_F005BD60;
    }
    param_1[2] = 0;
    _ipc_port_dngrow();
    if (puVar4 != (undefined4 *)0x0) break;
  }
  return CONCAT44(param_2,puVar4);
}
/* GHIDRADEC_FUNCTION index=1186 start=0xf005bd6c */

/* WARNING: Removing unreachable block (ram,0xf005bda0) */
/* WARNING: Removing unreachable block (ram,0xf005bd7c) */

undefined8
_ipc_right_dncancel(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  uVar1 = param_2;
  _ipc_port_dncancel(param_2,param_3,param_4[2]);
  param_4[2] = 0;
  if ((*param_4 & 0x400000) != 0) {
    _ipc_space_release(param_1);
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1187 start=0xf005bdb4 */

/* WARNING: Removing unreachable block (ram,0xf005be5c) */
/* WARNING: Removing unreachable block (ram,0xf005be48) */
/* WARNING: Removing unreachable block (ram,0xf005be64) */
/* WARNING: Removing unreachable block (ram,0xf005be08) */

undefined8 _ipc_right_inuse(int param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  uVar4 = *param_3;
  uVar1 = uVar4 & 0x1f0000;
  if (uVar1 == 0) {
    uVar5 = 0;
  }
  else {
    if (((uVar4 & 0x400000) != 0) && ((uVar1 == 0x10000 || (uVar1 == 0x40000)))) {
      piVar3 = (int *)param_3[1];
      do {
        do {
        } while (*piVar3 != 0);
        piVar2 = piVar3;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      *piVar3 = 0;
      if (-1 < piVar3[2]) {
        if (uVar1 == 0x10000) {
          if ((uVar4 & 0x200000) != 0) {
            _ipc_marequest_cancel(param_1,param_2);
          }
          _ipc_hash_delete(param_1,piVar3,param_2,param_3);
        }
        _ipc_object_release(piVar3);
        param_3[2] = 0;
        param_3[1] = 0;
        uVar5 = 0;
        *param_3 = *param_3 & 0xff800000;
        goto locret_F005BE9C;
      }
    }
    *(undefined4 *)(param_1 + 8) = 0;
    uVar5 = 1;
  }
locret_F005BE9C:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=1188 start=0xf005bea4 */

/* WARNING: Removing unreachable block (ram,0xf005bf2c) */
/* WARNING: Removing unreachable block (ram,0xf005bf10) */
/* WARNING: Removing unreachable block (ram,0xf005bf24) */
/* WARNING: Removing unreachable block (ram,0xf005bf50) */
/* WARNING: Removing unreachable block (ram,0xf005beb8) */

undefined8 _ipc_right_check(undefined4 param_1,int *param_2,undefined4 param_3,uint *param_4)

{
  int *piVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
    } while (*param_2 != 0);
    piVar1 = param_2;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (param_2[2] < 0) {
    uVar3 = 0;
  }
  else {
    *param_2 = 0;
    uVar2 = *param_4;
    if ((uVar2 & 0x10000) != 0) {
      if ((uVar2 & 0x200000) != 0) {
        uVar2 = uVar2 & 0xffdfffff;
        _ipc_marequest_cancel(param_1,param_3);
      }
      _ipc_hash_delete(param_1,param_2,param_3,param_4);
    }
    _ipc_object_release(param_2);
    if ((uVar2 & 0x400000) == 0) {
      uVar2 = uVar2 & 0xffe0ffff | 0x100000;
      if (param_4[2] != 0) {
        param_4[2] = 0;
        uVar2 = uVar2 + 1;
      }
      *param_4 = uVar2;
      param_4[1] = 0;
      uVar3 = 1;
    }
    else {
      param_4[2] = 0;
      param_4[1] = 0;
      _ipc_entry_dealloc(param_1,param_3,param_4);
      uVar3 = 1;
    }
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1189 start=0xf005bf98 */

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
/* GHIDRADEC_FUNCTION index=1190 start=0xf005c1b8 */

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
/* GHIDRADEC_FUNCTION index=1191 start=0xf005c490 */

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
/* GHIDRADEC_FUNCTION index=1192 start=0xf005c7a0 */

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
/* GHIDRADEC_FUNCTION index=1193 start=0xf005ccc0 */

/* WARNING: Removing unreachable block (ram,0xf005cce4) */

undefined8 _ipc_right_info(int param_1,undefined4 param_2,uint *param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 *puVar5;
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
  uVar4 = *param_3;
  if ((uVar4 & 0x50000) != 0) {
    puVar5 = (undefined4 *)param_3[1];
    iVar1 = param_1;
    _ipc_right_check(param_1,puVar5,param_2,param_3);
    if (iVar1 == 0) {
      *puVar5 = 0;
    }
    else {
      if ((uVar4 & 0x400000) != 0) {
        *(undefined4 *)(param_1 + 8) = 0;
        uVar6 = 0xf;
        goto locret_F005CD70;
      }
      uVar4 = *param_3;
    }
  }
  uVar3 = uVar4 & 0x1f0000;
  if ((uVar4 & 0x400000) == 0) {
    uVar2 = 0x80000000;
    if (param_3[2] != 0) goto loc_F005CD40;
  }
  else {
    uVar2 = 0x20000000;
loc_F005CD40:
    uVar3 = uVar3 | uVar2;
  }
  if ((uVar4 & 0x200000) != 0) {
    uVar3 = uVar3 | 0x40000000;
  }
  *param_4 = uVar3;
  *param_5 = uVar4 & 0xffff;
  uVar6 = 0;
locret_F005CD70:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=1194 start=0xf005cd78 */

/* WARNING: Removing unreachable block (ram,0xf005cdf8) */
/* WARNING: Removing unreachable block (ram,0xf005ce5c) */

undefined8 _ipc_right_copyin_check(undefined4 param_1,undefined4 param_2,uint *param_3,int param_4)

{
  uint uVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int *piVar5;
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
  switch(param_4) {
  case :
  case :
  case :
    uVar1 = 0x20000;
    break;
  case :
  case :
  case :
    if ((uVar3 & 0x100000) != 0) {
      uVar4 = 1;
      goto locret_F005CE68;
    }
    if ((uVar3 & 0x50000) == 0) {
      uVar4 = 0;
      goto locret_F005CE68;
    }
    piVar5 = (int *)param_3[1];
    do {
      do {
      } while (*piVar5 != 0);
      piVar2 = piVar5;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    *piVar5 = 0;
    if (-1 < piVar5[2]) {
      uVar4 = 1;
      if ((uVar3 & 0x400000) != 0) {
        uVar4 = 0;
      }
      goto locret_F005CE68;
    }
    uVar1 = 0x10000;
    if (param_4 == 0x12) {
      uVar1 = 0x40000;
    }
    break;
  :
    _panic(aIpcRightCopyin);
    uVar4 = 1;
    goto locret_F005CE68;
  }
  uVar4 = 1;
  if ((uVar3 & uVar1) == 0) {
    uVar4 = 0;
  }
locret_F005CE68:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=1195 start=0xf005ce70 */

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
/* GHIDRADEC_FUNCTION index=1196 start=0xf005d308 */

/* WARNING: Removing unreachable block (ram,0xf005d3a0) */
/* WARNING: Removing unreachable block (ram,0xf005d38c) */

undefined8
_ipc_right_copyin_undo
          (undefined4 param_1,undefined4 param_2,uint *param_3,int param_4,int param_5,int param_6)

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
  uVar2 = *param_3;
  if (param_6 == 0) {
    if ((uVar2 & 0x1f0000) != 0) {
      if ((uVar2 & 0x1f0000) == 0x100000) {
        if (param_4 != 0x13) {
          *param_3 = uVar2 + 1;
        }
      }
      else {
        if (param_4 != 0x13) {
          *param_3 = uVar2 + 1;
        }
        _ipc_right_check(param_1,param_5,param_2);
      }
      goto loc_F005D394;
    }
    uVar1 = 0x100001;
  }
  else {
    uVar1 = 0x100002;
  }
  *param_3 = uVar2 & 0xff800000 | uVar1;
loc_F005D394:
  if (param_5 != -1) {
    _ipc_object_release(param_5);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1197 start=0xf005d3b0 */

/* WARNING: Removing unreachable block (ram,0xf005d478) */
/* WARNING: Removing unreachable block (ram,0xf005d460) */
/* WARNING: Removing unreachable block (ram,0xf005d494) */
/* WARNING: Removing unreachable block (ram,0xf005d3ec) */

undefined8
_ipc_right_copyin_two(int param_1,undefined4 param_2,uint *param_3,undefined4 *param_4,int *param_5)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
  undefined4 unaff_l1;
  uint uVar3;
  undefined4 unaff_l3;
  int iVar4;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  iVar4 = 0;
  if (((uVar3 & 0x10000) == 0) || ((uVar3 & 0xffff) < 2)) {
    uVar5 = 0x11;
  }
  else {
    puVar2 = (undefined4 *)param_3[1];
    iVar1 = param_1;
    _ipc_right_check(param_1,puVar2,param_2,param_3);
    if (iVar1 == 0) {
      if ((uVar3 & 0xffff) == 2) {
        if ((uVar3 & 0x20000) == 0) {
          if (param_3[2] != 0) {
            iVar4 = param_1;
            _ipc_right_dncancel(param_1,puVar2,param_2,param_3);
          }
          _ipc_hash_delete(param_1,puVar2,param_2,param_3);
          if ((uVar3 & 0x200000) == 0) {
            iVar1 = puVar2[7];
          }
          else {
            _ipc_marequest_cancel(param_1,param_2);
            iVar1 = puVar2[7];
          }
          puVar2[7] = iVar1 + 1;
          puVar2[1] = puVar2[1] + 1;
          param_3[1] = 0;
        }
        else {
          puVar2[7] = puVar2[7] + 1;
          puVar2[1] = puVar2[1] + 2;
        }
        uVar3 = uVar3 & 0xfffe0000;
      }
      else {
        puVar2[7] = puVar2[7] + 2;
        puVar2[1] = puVar2[1] + 2;
        uVar3 = uVar3 - 2;
      }
      *param_3 = uVar3;
      *puVar2 = 0;
      *param_4 = puVar2;
      *param_5 = iVar4;
      uVar5 = 0;
    }
    else {
      uVar5 = 0xf;
      if ((uVar3 & 0x400000) == 0) {
        uVar5 = 0x11;
      }
    }
  }
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=1198 start=0xf005d500 */

/* WARNING: Removing unreachable block (ram,0xf005d640) */
/* WARNING: Removing unreachable block (ram,0xf005d678) */
/* WARNING: Removing unreachable block (ram,0xf005d668) */
/* WARNING: Removing unreachable block (ram,0xf005d5f8) */

undefined8
_ipc_right_copyout(undefined4 param_1,int param_2,uint *param_3,uint param_4,int param_5,
                  undefined4 *param_6)

{
  undefined4 unaff_l0;
  uint uVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  int iVar3;
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
  uVar1 = *param_3;
  if (param_4 == 0x11) {
    if ((uVar1 & 0x10000) == 0) {
      if ((uVar1 & 0x20000) != 0) goto loc_F005D5D4;
      *param_6 = 0;
      _ipc_hash_insert(param_1,param_6,param_2,param_3);
    }
    else {
      if ((uVar1 & 0xffff) == 0xfffe) {
        if (param_5 == 0) {
          *param_6 = 0;
          uVar2 = 0x13;
        }
        else {
          param_6[7] = param_6[7] + -1;
          param_6[1] = param_6[1] + -1;
          *param_6 = 0;
          uVar2 = 0;
        }
        goto locret_F005D684;
      }
      param_6[7] = param_6[7] + -1;
loc_F005D5D4:
      param_6[1] = param_6[1] + -1;
      *param_6 = 0;
    }
    *param_3 = (uVar1 | 0x10000) + 1;
  }
  else if (param_4 < 0x12) {
    if (param_4 == 0x10) {
      param_6[4] = param_2;
      iVar3 = param_6[3];
      param_6[3] = param_1;
      if ((uVar1 & 0x10000) == 0) {
        *param_6 = 0;
      }
      else {
        param_6[1] = param_6[1] + -1;
        *param_6 = 0;
        _ipc_hash_delete(param_1,param_6,param_2,param_3);
      }
      *param_3 = uVar1 | 0x20000;
      param_2 = iVar3;
      if (iVar3 != 0) {
        _ipc_object_release(iVar3);
        uVar2 = 0;
        goto locret_F005D684;
      }
    }
    else {
loc_F005D678:
      _panic(aIpcRightCopyou);
    }
  }
  else {
    if (param_4 != 0x12) goto loc_F005D678;
    *param_6 = 0;
    *param_3 = uVar1 | 0x40001;
  }
  uVar2 = 0;
locret_F005D684:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1199 start=0xf005d68c */

/* WARNING: Removing unreachable block (ram,0xf005d854) */
/* WARNING: Removing unreachable block (ram,0xf005d7d8) */
/* WARNING: Removing unreachable block (ram,0xf005d830) */
/* WARNING: Removing unreachable block (ram,0xf005d6d4) */
/* WARNING: Removing unreachable block (ram,0xf005d724) */
/* WARNING: Removing unreachable block (ram,0xf005d7c4) */
/* WARNING: Removing unreachable block (ram,0xf005d7fc) */
/* WARNING: Removing unreachable block (ram,0xf005d868) */
/* WARNING: Removing unreachable block (ram,0xf005d6b0) */

undefined8 _ipc_right_rename(int param_1,undefined4 param_2,uint *param_3,int param_4,uint *param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  uint uVar4;
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
  uVar5 = *param_3;
  uVar4 = param_3[2];
  piVar3 = (int *)param_3[1];
  if (uVar4 != 0) {
    iVar1 = param_1;
    _ipc_right_check(param_1,piVar3,param_2,param_3);
    if (iVar1 == 0) {
      *(int *)(piVar3[0xb] + uVar4 * 8 + 4) = param_4;
      *piVar3 = 0;
      param_3[2] = 0;
    }
    else {
      if ((uVar5 & 0x400000) != 0) {
        _ipc_entry_dealloc(param_1,param_4,param_5);
        *(undefined4 *)(param_1 + 8) = 0;
        uVar6 = 0xf;
        goto locret_F005D878;
      }
      uVar5 = *param_3;
      uVar4 = 0;
      piVar3 = (int *)0x0;
    }
  }
  if ((uVar5 & 0x200000) != 0) {
    _ipc_marequest_rename(param_1,param_2,param_4);
  }
  param_5[2] = uVar4;
  param_5[1] = (uint)piVar3;
  uVar4 = uVar5 & 0x1f0000;
  *param_5 = *param_5 | uVar5 & 0x7fffff;
  if (uVar4 == 0x30000) {
loc_F005D7EC:
    do {
      do {
      } while (*piVar3 != 0);
      piVar2 = piVar3;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    piVar3[4] = param_4;
    *piVar3 = 0;
    param_3[1] = 0;
  }
  else if (uVar4 < 0x30001) {
    if (uVar4 == 0x10000) {
      _ipc_hash_delete(param_1,piVar3,param_2,param_3);
      _ipc_hash_insert(param_1,piVar3,param_4,param_5);
      param_3[1] = 0;
    }
    else {
      if (uVar4 == 0x20000) goto loc_F005D7EC;
loc_F005D854:
      _panic(aIpcRightRename);
      param_3[1] = 0;
    }
  }
  else if (uVar4 == 0x80000) {
    do {
      do {
      } while (*piVar3 != 0);
      piVar2 = piVar3;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    piVar3[3] = param_4;
    *piVar3 = 0;
    param_3[1] = 0;
  }
  else {
    uVar5 = 0x100000;
    if (uVar4 < 0x80001) {
      uVar5 = 0x40000;
    }
    if (uVar4 != uVar5) goto loc_F005D854;
    param_3[1] = 0;
  }
  _ipc_entry_dealloc(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 8) = 0;
  uVar6 = 0;
locret_F005D878:
  return CONCAT44(param_2,uVar6);
}

