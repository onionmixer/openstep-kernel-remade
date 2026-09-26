/* GHIDRADEC_FUNCTION index=1100 start=0xf0057da4 */

/* WARNING: Removing unreachable block (ram,0xf0057e84) */
/* WARNING: Removing unreachable block (ram,0xf0057e5c) */
/* WARNING: Removing unreachable block (ram,0xf0057f48) */
/* WARNING: Removing unreachable block (ram,0xf0057e08) */
/* WARNING: Removing unreachable block (ram,0xf0057ddc) */
/* WARNING: Removing unreachable block (ram,0xf0057f10) */
/* WARNING: Removing unreachable block (ram,0xf0057e40) */
/* WARNING: Removing unreachable block (ram,0xf0057f30) */
/* WARNING: Removing unreachable block (ram,0xf0057edc) */
/* WARNING: Removing unreachable block (ram,0xf0057dac) */

undefined8 _ipc_marequest_create(uint param_1,int *param_2,int param_3,undefined4 *param_4)

{
  uint *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  puVar1 = _ipc_marequest_zone;
  _zalloc();
  if (puVar1 == (uint *)0x0) {
    uVar5 = 0x1000000e;
    goto locret_F0057F68;
  }
  do {
    do {
    } while (*(int *)(param_1 + 8) != 0);
    piVar2 = (int *)(param_1 + 8);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if (*(int *)(param_1 + 0xc) == 0) {
loc_F0057F24:
    *(undefined4 *)(param_1 + 8) = 0;
    _zfree(_ipc_marequest_zone,puVar1);
    uVar5 = 0x1000000b;
  }
  else {
    uVar4 = param_1;
    _ipc_right_reverse(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc),
                       (undefined *)((int)register0x00000038 + -0x10));
    puVar3 = *(undefined4 **)((int)register0x00000038 + -0x10);
    if (uVar4 == 0) {
      if (param_3 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = param_1;
        _ipc_port_lookup_notify(param_1,param_3);
        if (uVar4 == 0) goto loc_F0057F24;
      }
      _ipc_space_reference(param_1);
      *puVar1 = param_1;
      puVar1[1] = 0;
      puVar1[2] = uVar4;
    }
    else {
      *param_2 = 0;
      param_2 = (int *)*puVar3;
      if (((uint)param_2 & 0x200000) != 0) {
        *(undefined4 *)(param_1 + 8) = 0;
        _zfree(_ipc_marequest_zone,puVar1);
        uVar5 = 0x10000006;
        goto locret_F0057F68;
      }
      if (param_3 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = param_1;
        _ipc_port_lookup_notify(param_1,param_3);
        if (uVar4 == 0) goto loc_F0057F24;
      }
      **(uint **)((int)register0x00000038 + -0x10) = (uint)param_2 | 0x200000;
      _ipc_space_reference(param_1);
      *puVar1 = param_1;
      puVar1[2] = uVar4;
      uVar4 = *(uint *)((int)register0x00000038 + -0xc);
      puVar1[1] = uVar4;
      param_2 = (int *)(_ipc_marequest_table +
                       ((param_1 >> 4) + (uVar4 >> 8) + (uVar4 & 0xff) & _ipc_marequest_mask) * 8);
      do {
        do {
        } while (*param_2 != 0);
        piVar2 = param_2;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      puVar1[3] = param_2[1];
      param_2[1] = (int)puVar1;
      *param_2 = 0;
    }
    *(undefined4 *)(param_1 + 8) = 0;
    *param_4 = puVar1;
    uVar5 = 0;
  }
locret_F0057F68:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=1101 start=0xf0057f70 */

/* WARNING: Removing unreachable block (ram,0xf0057fb4) */

undefined8 _ipc_marequest_cancel(uint param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  undefined4 unaff_l0;
  int *piVar5;
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
  piVar5 = (int *)(_ipc_marequest_table +
                  ((param_1 >> 4) + (param_2 >> 8) + (param_2 & 0xff) & _ipc_marequest_mask) * 8);
  do {
    do {
    } while (*piVar5 != 0);
    piVar1 = piVar5;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  puVar3 = (uint *)piVar5[1];
  puVar4 = (uint *)(piVar5 + 1);
  if (puVar3 != (uint *)0x0) {
    uVar2 = *puVar3;
    while( true ) {
      if ((uVar2 == param_1) && (puVar3[1] == param_2)) {
        uVar2 = puVar3[3];
        goto loc_F0058010;
      }
      puVar4 = puVar3 + 3;
      puVar3 = (uint *)puVar3[3];
      if (puVar3 == (uint *)0x0) break;
      uVar2 = *puVar3;
    }
  }
  uVar2 = puVar3[3];
loc_F0058010:
  *puVar4 = uVar2;
  *piVar5 = 0;
  puVar3[1] = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1102 start=0xf0058024 */

/* WARNING: Removing unreachable block (ram,0xf0058110) */
/* WARNING: Removing unreachable block (ram,0xf0058068) */

undefined8 _ipc_marequest_rename(uint param_1,uint param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  uint *puVar5;
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
  piVar4 = (int *)(_ipc_marequest_table +
                  ((param_1 >> 4) + (param_2 >> 8) + (param_2 & 0xff) & _ipc_marequest_mask) * 8);
  do {
    do {
    } while (*piVar4 != 0);
    piVar1 = piVar4;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  puVar5 = (uint *)piVar4[1];
  puVar3 = (uint *)(piVar4 + 1);
  if (puVar5 != (uint *)0x0) {
    uVar2 = *puVar5;
    while ((uVar2 != param_1 || (puVar5[1] != param_2))) {
      puVar3 = puVar5 + 3;
      puVar5 = (uint *)puVar5[3];
      if (puVar5 == (uint *)0x0) break;
      uVar2 = *puVar5;
    }
  }
  *puVar3 = puVar5[3];
  *piVar4 = 0;
  puVar5[1] = param_3;
  piVar4 = (int *)(_ipc_marequest_table +
                  ((param_1 >> 4) + (param_3 >> 8) + (param_3 & 0xff) & _ipc_marequest_mask) * 8);
  do {
    do {
    } while (*piVar4 != 0);
    piVar1 = piVar4;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  puVar5[3] = piVar4[1];
  piVar4[1] = (int)puVar5;
  *piVar4 = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1103 start=0xf005813c */

/* WARNING: Removing unreachable block (ram,0xf00582b0) */
/* WARNING: Removing unreachable block (ram,0xf005826c) */
/* WARNING: Removing unreachable block (ram,0xf0058234) */
/* WARNING: Removing unreachable block (ram,0xf00581c0) */
/* WARNING: Removing unreachable block (ram,0xf0058254) */
/* WARNING: Removing unreachable block (ram,0xf005827c) */
/* WARNING: Removing unreachable block (ram,0xf00582a4) */
/* WARNING: Removing unreachable block (ram,0xf005815c) */

undefined8 _ipc_marequest_destroy(undefined4 *param_1,undefined4 param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  uint *puVar6;
  uint uVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  int iVar9;
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
  puVar6 = (uint *)*param_1;
  uVar8 = 0;
  do {
    do {
    } while (puVar6[2] != 0);
    puVar1 = puVar6 + 2;
    _simple_lock_try();
  } while (puVar1 == (uint *)0x0);
  uVar7 = param_1[1];
  iVar9 = param_1[2];
  if (uVar7 != 0) {
    piVar5 = (int *)(_ipc_marequest_table +
                    (((uint)puVar6 >> 4) + (uVar7 >> 8) + (uVar7 & 0xff) & _ipc_marequest_mask) * 8)
    ;
    do {
      do {
      } while (*piVar5 != 0);
      piVar3 = piVar5;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    piVar3 = (int *)piVar5[1];
    piVar4 = piVar5 + 1;
    iVar2 = iRam0000000c;
    if (piVar3 != (int *)0x0) {
      puVar1 = (uint *)*piVar3;
      while ((puVar1 != puVar6 || (piVar3[1] != uVar7))) {
        piVar4 = piVar3 + 3;
        piVar3 = (int *)piVar3[3];
        if (piVar3 == (int *)0x0) goto loc_F005821C;
        puVar1 = (uint *)*piVar3;
      }
      iVar2 = piVar3[3];
    }
loc_F005821C:
    *piVar4 = iVar2;
    *piVar5 = 0;
    if (puVar6[3] == 0) {
      uVar7 = 0;
    }
    else {
      puVar1 = puVar6;
      _ipc_entry_lookup(puVar6,uVar7);
      *puVar1 = *puVar1 & 0xffdfffff;
      if (iVar9 == 0) {
        uVar8 = puVar6[0x11];
        _ipc_port_copy_send();
      }
    }
  }
  puVar6[2] = 0;
  _ipc_space_release(puVar6);
  _zfree(_ipc_marequest_zone,param_1);
  if (iVar9 == 0) {
    if ((uVar8 != 0) && (uVar8 != 0xffffffff)) {
      _ipc_notify_msg_accepted_compat(uVar8,uVar7);
    }
  }
  else {
    _ipc_notify_msg_accepted(iVar9,uVar7);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1104 start=0xf00582c0 */

/* WARNING: Removing unreachable block (ram,0xf0058310) */

undefined8 _ipc_marequest_info(undefined4 *param_1,int param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l3;
  int iVar6;
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
  if (_ipc_marequest_size < param_3) {
    param_3 = _ipc_marequest_size;
  }
  uVar5 = 0;
  if (param_3 != 0) {
    iVar6 = 0;
    do {
      iVar4 = 0;
      piVar3 = (int *)(_ipc_marequest_table + uVar5 * 8);
      do {
        do {
        } while (*piVar3 != 0);
        piVar1 = piVar3;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      for (iVar2 = piVar3[1]; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
        iVar4 = iVar4 + 1;
      }
      *piVar3 = 0;
      *(int *)(iVar6 + param_2) = iVar4;
      uVar5 = uVar5 + 1;
      iVar6 = iVar6 + 4;
    } while (uVar5 < param_3);
  }
  *param_1 = _ipc_marequest_max;
  return CONCAT44(param_2,_ipc_marequest_size);
}
/* GHIDRADEC_FUNCTION index=1105 start=0xf0058378 */

undefined8 _ipc_mqueue_init(undefined4 *param_1,undefined4 param_2)

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
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1106 start=0xf0058390 */

/* WARNING: Removing unreachable block (ram,0xf0058434) */
/* WARNING: Removing unreachable block (ram,0xf00583d4) */
/* WARNING: Removing unreachable block (ram,0xf00583dc) */
/* WARNING: Removing unreachable block (ram,0xf00583f0) */
/* WARNING: Removing unreachable block (ram,0xf00583b8) */

undefined8 _ipc_mqueue_move(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar4;
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
  iVar4 = param_2 + 4;
  iVar1 = *(int *)(param_2 + 4);
joined_r0xf00583a4:
  do {
    do {
      iVar3 = iVar1;
      if (iVar3 == 0) {
        return CONCAT44(iVar4,param_1 + 8);
      }
      iVar1 = iVar4;
      _ipc_kmsg_queue_next(iVar4,iVar3);
    } while (*(int *)(iVar3 + 0x1c) != param_3);
    _ipc_kmsg_rmqueue(iVar4,iVar3);
    while (iVar2 = param_1 + 8, _ipc_thread_dequeue(), iVar2 != 0) {
      _thread_go();
      if (*(uint *)(iVar3 + 0x18) <= *(uint *)(iVar2 + 0x9c)) {
        *(undefined4 *)(iVar2 + 0x98) = 0;
        *(int *)(iVar2 + 0x9c) = iVar3;
        iVar3 = *(int *)(param_3 + 0x34);
        *(int *)(param_3 + 0x34) = iVar3 + 1;
        *(int *)(iVar2 + 0xa0) = iVar3;
        goto joined_r0xf00583a4;
      }
      *(undefined4 *)(iVar2 + 0x98) = 0x10004004;
      *(undefined4 *)(iVar2 + 0x9c) = *(undefined4 *)(iVar3 + 0x18);
    }
    _ipc_kmsg_enqueue(param_1 + 4,iVar3);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1107 start=0xf0058450 */

/* WARNING: Removing unreachable block (ram,0xf0058468) */
/* WARNING: Removing unreachable block (ram,0xf0058454) */

undefined8 _ipc_mqueue_changed(int param_1,undefined4 param_2)

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
  while( true ) {
    iVar1 = param_1 + 8;
    _ipc_thread_dequeue();
    if (iVar1 == 0) break;
    *(undefined4 *)(iVar1 + 0x98) = param_2;
    _thread_go();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1108 start=0xf005847c */

/* WARNING: Removing unreachable block (ram,0xf00584c0) */
/* WARNING: Removing unreachable block (ram,0xf0058774) */
/* WARNING: Removing unreachable block (ram,0xf00586a8) */
/* WARNING: Removing unreachable block (ram,0xf0058600) */
/* WARNING: Removing unreachable block (ram,0xf00585c0) */
/* WARNING: Removing unreachable block (ram,0xf0058594) */
/* WARNING: Removing unreachable block (ram,0xf0058534) */
/* WARNING: Removing unreachable block (ram,0xf00585a4) */
/* WARNING: Removing unreachable block (ram,0xf00585b0) */
/* WARNING: Removing unreachable block (ram,0xf00585d8) */
/* WARNING: Removing unreachable block (ram,0xf0058540) */
/* WARNING: Removing unreachable block (ram,0xf0058684) */
/* WARNING: Removing unreachable block (ram,0xf0058790) */
/* WARNING: Removing unreachable block (ram,0xf00584d8) */
/* WARNING: Removing unreachable block (ram,0xf0058494) */

undefined8 _ipc_mqueue_send(int *param_1,uint param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  int *piVar6;
  undefined4 unaff_l1;
  int *piVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int *piVar9;
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
  piVar6 = (int *)param_1[7];
  do {
    do {
    } while (*piVar6 != 0);
    piVar7 = piVar6;
    _simple_lock_try();
  } while (piVar7 == (int *)0x0);
  if (piVar6[3] == _ipc_space_kernel) {
    *piVar6 = 0;
    _ipc_kobject_server();
    if (param_1 == (int *)0x0) {
      uVar8 = 0;
    }
    else {
      _ipc_mqueue_send();
      uVar8 = 0;
    }
locret_F00587A4:
    return CONCAT44(param_2,uVar8);
  }
  do {
    iVar1 = piVar6[2];
loc_F00584F8:
    iVar5 = _active_threads;
    if (-1 < iVar1) {
      iVar1 = piVar6[1];
      piVar6[1] = iVar1 + -1;
      *piVar6 = 0;
      if (iVar1 + -1 == 0) {
        _zfree((&_ipc_object_zones)[(piVar6[2] & 0x7fffffffU) >> 0x10],piVar6);
        param_1[7] = 0;
      }
      else {
        param_1[7] = 0;
      }
loc_F0058540:
      _ipc_kmsg_destroy(param_1);
      uVar8 = 0;
      goto locret_F00587A4;
    }
    if ((uint)piVar6[0xe] < (uint)piVar6[0xf]) {
loc_F005863C:
      uVar4 = param_1[5];
loc_F0058640:
      if ((uVar4 & 0x40000000) != 0) {
        *piVar6 = 0;
        goto loc_F0058540;
      }
      piVar6[0xe] = piVar6[0xe] + 1;
      if (piVar6[0xc] == 0) {
        piVar7 = piVar6 + 0x10;
      }
      else {
        piVar7 = (int *)(piVar6[0xc] + 0x10);
      }
      do {
        do {
        } while (*piVar7 != 0);
        piVar2 = piVar7;
        _simple_lock_try();
        piVar9 = piVar7 + 2;
      } while (piVar2 == (int *)0x0);
      *piVar6 = 0;
      iVar1 = *piVar9;
      while( true ) {
        if (iVar1 == 0) {
          iVar1 = piVar7[1];
          if (iVar1 == 0) {
            piVar7[1] = (int)param_1;
            *param_1 = (int)param_1;
            param_1[1] = (int)param_1;
          }
          else {
            piVar6 = *(int **)(iVar1 + 4);
            *param_1 = iVar1;
            param_1[1] = (int)piVar6;
            *(int **)(iVar1 + 4) = param_1;
            *piVar6 = (int)param_1;
          }
          *piVar7 = 0;
          uVar8 = 0;
          goto locret_F00587A4;
        }
        iVar5 = *(int *)(iVar1 + 0x90);
        if (iVar5 == iVar1) {
          *piVar9 = 0;
        }
        else {
          iVar3 = *(int *)(iVar1 + 0x94);
          *piVar9 = iVar5;
          *(int *)(iVar5 + 0x94) = iVar3;
          *(int *)(iVar3 + 0x90) = iVar5;
          *(int *)(iVar1 + 0x90) = iVar1;
          *(int *)(iVar1 + 0x94) = iVar1;
        }
        if ((uint)param_1[6] <= *(uint *)(iVar1 + 0x9c)) break;
        *(undefined4 *)(iVar1 + 0x98) = 0x10004004;
        *(int *)(iVar1 + 0x9c) = param_1[6];
        _thread_go();
        iVar1 = *piVar9;
      }
      *(undefined4 *)(iVar1 + 0x98) = 0;
      *(int **)(iVar1 + 0x9c) = param_1;
      iVar5 = piVar6[0xd];
      piVar6[0xd] = iVar5 + 1;
      *(int *)(iVar1 + 0xa0) = iVar5;
      *piVar7 = 0;
      if ((param_2 & 0x20000) == 0) {
        _thread_go(iVar1);
        uVar8 = 0;
      }
      else {
        _thread_go_and_switch(param_4,iVar1);
        uVar8 = 0;
      }
      goto locret_F00587A4;
    }
    if ((param_2 & 0x10000) != 0) {
      uVar4 = param_1[5];
      goto loc_F0058640;
    }
    if (*(char *)((int)param_1 + 0x17) == '\x12') goto loc_F005863C;
    if ((param_2 & 0x10) == 0) {
      _thread_will_wait(_active_threads);
    }
    else {
      if (param_3 == 0) {
        *piVar6 = 0;
        uVar8 = 0x10000004;
        goto locret_F00587A4;
      }
      _thread_will_wait_with_timeout(_active_threads,param_3);
    }
    _ipc_thread_enqueue(piVar6 + 0x13,iVar5);
    *(undefined4 *)(iVar5 + 0x98) = 0x10000001;
    *piVar6 = 0;
    _thread_block_with_continuation(0);
    do {
      do {
      } while (*piVar6 != 0);
      piVar7 = piVar6;
      _simple_lock_try();
    } while (piVar7 == (int *)0x0);
    if (*(int *)(iVar5 + 0x98) == 0) {
      iVar1 = piVar6[2];
      goto loc_F00584F8;
    }
    _ipc_thread_rmqueue(piVar6 + 0x13,iVar5);
    iVar1 = *(int *)(iVar5 + 0x44);
    if (iVar1 != 1) {
      if (iVar1 < 1) {
        iVar1 = piVar6[2];
      }
      else {
        if (iVar1 < 4) {
          *piVar6 = 0;
          uVar8 = 0x10000007;
          goto locret_F00587A4;
        }
        iVar1 = piVar6[2];
      }
      goto loc_F00584F8;
    }
    param_3 = 0;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1109 start=0xf00587ac */

/* WARNING: Removing unreachable block (ram,0xf00588ec) */
/* WARNING: Removing unreachable block (ram,0xf00587fc) */
/* WARNING: Removing unreachable block (ram,0xf00588c0) */
/* WARNING: Removing unreachable block (ram,0xf00587b4) */

undefined8 _ipc_mqueue_send_interrupt(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 unaff_l3;
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
  puVar6 = (undefined4 *)param_1[7];
  puVar7 = puVar6;
  _simple_lock_try();
  if (puVar7 == (undefined4 *)0x0) {
    uVar8 = 0x800;
  }
  else if ((int)puVar6[2] < 0) {
    puVar7 = (undefined4 *)(puVar6[0xc] + 0x10);
    if (puVar6[0xc] == 0) {
      puVar7 = puVar6 + 0x10;
    }
    puVar1 = puVar7;
    _simple_lock_try();
    piVar2 = puVar7 + 2;
    if (puVar1 == (undefined4 *)0x0) {
      *puVar6 = 0;
      uVar8 = 0x800;
    }
    else {
      *puVar6 = 0;
      puVar6[0xe] = puVar6[0xe] + 1;
      iVar5 = *piVar2;
      while (iVar5 != 0) {
        iVar4 = *(int *)(iVar5 + 0x90);
        if (iVar4 == iVar5) {
          *piVar2 = 0;
        }
        else {
          iVar3 = *(int *)(iVar5 + 0x94);
          *piVar2 = iVar4;
          *(int *)(iVar4 + 0x94) = iVar3;
          *(int *)(iVar3 + 0x90) = iVar4;
          *(int *)(iVar5 + 0x90) = iVar5;
          *(int *)(iVar5 + 0x94) = iVar5;
        }
        if ((uint)param_1[6] <= *(uint *)(iVar5 + 0x9c)) {
          *(undefined4 *)(iVar5 + 0x98) = 0;
          *(int **)(iVar5 + 0x9c) = param_1;
          iVar4 = puVar6[0xd];
          puVar6[0xd] = iVar4 + 1;
          *(int *)(iVar5 + 0xa0) = iVar4;
          *puVar7 = 0;
          uVar8 = 0;
          _thread_go();
          goto locret_F00588F4;
        }
        *(undefined4 *)(iVar5 + 0x98) = 0x10004004;
        *(int *)(iVar5 + 0x9c) = param_1[6];
        _thread_go();
        iVar5 = *piVar2;
      }
      iVar5 = puVar7[1];
      if (iVar5 == 0) {
        puVar7[1] = param_1;
        *param_1 = (int)param_1;
        param_1[1] = (int)param_1;
      }
      else {
        piVar2 = *(int **)(iVar5 + 4);
        *param_1 = iVar5;
        param_1[1] = (int)piVar2;
        *(int **)(iVar5 + 4) = param_1;
        *piVar2 = (int)param_1;
      }
      *puVar7 = 0;
      uVar8 = 0;
    }
  }
  else {
    *puVar6 = 0;
    uVar8 = 0x10000003;
  }
locret_F00588F4:
  return CONCAT44(param_2,uVar8);
}
/* GHIDRADEC_FUNCTION index=1110 start=0xf00588fc */

/* WARNING: Removing unreachable block (ram,0xf0058a14) */
/* WARNING: Removing unreachable block (ram,0xf00589a8) */
/* WARNING: Removing unreachable block (ram,0xf0058a44) */
/* WARNING: Removing unreachable block (ram,0xf0058938) */
/* WARNING: Removing unreachable block (ram,0xf0058970) */
/* WARNING: Removing unreachable block (ram,0xf00589e0) */
/* WARNING: Removing unreachable block (ram,0xf0058a90) */
/* WARNING: Removing unreachable block (ram,0xf0058914) */

undefined8 _ipc_mqueue_copyin(uint *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  uint *puVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar3;
  undefined4 uVar4;
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
    } while (param_1[2] != 0);
    puVar1 = param_1 + 2;
    _simple_lock_try();
  } while (puVar1 == (uint *)0x0);
  if ((param_1[3] == 0) ||
     (puVar1 = param_1, _ipc_entry_lookup(param_1,param_2), puVar1 == (uint *)0x0)) {
loc_F0058A64:
    param_1[2] = 0;
    uVar4 = 0x10004002;
  }
  else {
    param_2 = (int *)puVar1[1];
    if ((*puVar1 & 0x20000) == 0) {
      if ((*puVar1 & 0x80000) == 0) goto loc_F0058A64;
      do {
        do {
        } while (*param_2 != 0);
        piVar3 = param_2;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      param_1[2] = 0;
      piVar3 = param_2 + 4;
    }
    else {
      do {
        do {
        } while (*param_2 != 0);
        piVar3 = param_2;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      param_1[2] = 0;
      piVar3 = (int *)param_2[0xc];
      if (piVar3 == (int *)0x0) {
        piVar3 = param_2 + 0x10;
      }
      else {
        do {
          do {
          } while (*piVar3 != 0);
          piVar2 = piVar3;
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
        if (piVar3[2] < 0) {
          *piVar3 = 0;
          *param_2 = 0;
          uVar4 = 0x1000400a;
          goto locret_F0058AB0;
        }
        _ipc_pset_remove(piVar3,param_2);
        *piVar3 = 0;
        if (piVar3[1] == 0) {
          _zfree((&_ipc_object_zones)[(piVar3[2] & 0x7fffffffU) >> 0x10],piVar3);
        }
        piVar3 = param_2 + 0x10;
      }
    }
    param_2[1] = param_2[1] + 1;
    do {
      do {
      } while (*piVar3 != 0);
      piVar2 = piVar3;
      _simple_lock_try();
      uVar4 = 0;
    } while (piVar2 == (int *)0x0);
    *param_2 = 0;
    *param_4 = param_2;
    *param_3 = piVar3;
  }
locret_F0058AB0:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=1111 start=0xf0058ab8 */

/* WARNING: Removing unreachable block (ram,0xf0058cb0) */
/* WARNING: Removing unreachable block (ram,0xf0058d40) */
/* WARNING: Removing unreachable block (ram,0xf0058cd4) */
/* WARNING: Removing unreachable block (ram,0xf0058bc0) */
/* WARNING: Removing unreachable block (ram,0xf0058b60) */
/* WARNING: Removing unreachable block (ram,0xf0058bd8) */
/* WARNING: Removing unreachable block (ram,0xf0058cf0) */
/* WARNING: Removing unreachable block (ram,0xf0058d4c) */
/* WARNING: Removing unreachable block (ram,0xf0058c74) */
/* WARNING: Removing unreachable block (ram,0xf0058b70) */

undefined8
_ipc_mqueue_receive(int *param_1,int *param_2,uint param_3,int param_4,int param_5,int param_6)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  uint *puVar6;
  undefined4 unaff_l1;
  uint *puVar7;
  uint *puVar8;
  undefined4 unaff_l3;
  int *piVar9;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
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
  undefined auStackX_0 [92];
  
  iVar5 = _active_threads;
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
  puVar8 = *(uint **)((int)register0x00000038 + 0x5c);
  piVar9 = *(int **)((int)register0x00000038 + 0x60);
  puVar7 = (uint *)(param_1 + 1);
  if (param_5 != 0) goto loc_F0058BC8;
  do {
    puVar6 = (uint *)*puVar7;
loc_F0058ADC:
    if (puVar6 != (uint *)0x0) {
      if (param_3 < puVar6[6]) {
        *puVar8 = puVar6[6];
        *param_1 = 0;
        uVar11 = 0x10004004;
      }
      else {
        puVar4 = (uint *)*puVar6;
        if (puVar4 == puVar6) {
          *puVar7 = 0;
        }
        else {
          puVar1 = (uint *)puVar6[1];
          *puVar7 = (uint)puVar4;
          puVar4[1] = (uint)puVar1;
          *puVar1 = (uint)puVar4;
        }
        param_2 = (int *)puVar6[7];
        iVar5 = param_2[0xd];
        param_2[0xd] = iVar5 + 1;
loc_F0058CC0:
        *param_1 = 0;
        if (puVar6[3] != 0) {
          _ipc_marequest_destroy();
          puVar6[3] = 0;
        }
        do {
          do {
          } while (*param_2 != 0);
          piVar2 = param_2;
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
        if (param_2[2] < 0) {
          iVar3 = param_2[0xe];
          iVar10 = param_2[0x13];
          param_2[0xe] = iVar3 - 1U;
          if ((iVar10 != 0) && (iVar3 - 1U < (uint)param_2[0xf])) {
            _ipc_thread_rmqueue(param_2 + 0x13,iVar10);
            *(undefined4 *)(iVar10 + 0x98) = 0;
            _thread_go(iVar10);
          }
        }
        *param_2 = 0;
        *puVar8 = (uint)puVar6;
        *piVar9 = iVar5;
        uVar11 = 0;
      }
      goto locret_F0058D64;
    }
    if (((uint)param_2 & 0x100) == 0) {
      _thread_will_wait(iVar5);
      iVar3 = param_1[2];
    }
    else {
      if (param_4 == 0) {
        *param_1 = 0;
        uVar11 = 0x10004003;
        goto locret_F0058D64;
      }
      _thread_will_wait_with_timeout(iVar5,param_4);
      iVar3 = param_1[2];
    }
    if (iVar3 == 0) {
      param_1[2] = iVar5;
    }
    else {
      iVar10 = *(int *)(iVar3 + 0x94);
      *(int *)(iVar5 + 0x90) = iVar3;
      *(int *)(iVar5 + 0x94) = iVar10;
      *(int *)(iVar3 + 0x94) = iVar5;
      *(int *)(iVar10 + 0x90) = iVar5;
    }
    *(undefined4 *)(iVar5 + 0x98) = 0x10004001;
    *(uint *)(iVar5 + 0x9c) = param_3;
    *param_1 = 0;
    iVar3 = 0;
    if (param_6 != 0) {
      iVar3 = param_6;
    }
    _thread_block_with_continuation(iVar3);
loc_F0058BC8:
    do {
      do {
      } while (*param_1 != 0);
      piVar2 = param_1;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    iVar3 = *(int *)(iVar5 + 0x98);
    if (iVar3 == 0) {
      puVar6 = *(uint **)(iVar5 + 0x9c);
      iVar5 = *(int *)(iVar5 + 0xa0);
      param_2 = (int *)puVar6[7];
      goto loc_F0058CC0;
    }
    if (iVar3 == 0x10004004) {
      *puVar8 = *(uint *)(iVar5 + 0x9c);
loc_F0058C68:
      *param_1 = 0;
      uVar11 = *(undefined4 *)(iVar5 + 0x98);
locret_F0058D64:
      return CONCAT44(param_2,uVar11);
    }
    if (0x10004004 < iVar3) {
      if ((iVar3 == 0x10004006) || (iVar3 == 0x10004009)) goto loc_F0058C68;
loc_F0058CB0:
      _panic(aIpcMqueueRecei);
      puVar6 = (uint *)*puVar7;
      goto loc_F0058ADC;
    }
    if (iVar3 != 0x10004001) goto loc_F0058CB0;
    _ipc_thread_rmqueue(param_1 + 2,iVar5);
    iVar3 = *(int *)(iVar5 + 0x44);
    if (iVar3 != 1) {
      if (iVar3 < 1) {
        puVar6 = (uint *)*puVar7;
      }
      else {
        if (iVar3 < 4) {
          *param_1 = 0;
          uVar11 = 0x10004005;
          goto locret_F0058D64;
        }
        puVar6 = (uint *)*puVar7;
      }
      goto loc_F0058ADC;
    }
    param_4 = 0;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1112 start=0xf0058d6c */

undefined8 _ipc_notify_init_port_deleted(undefined4 *param_1,undefined4 param_2)

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
  *param_1 = 0x12;
  param_1[1] = 0x20;
  param_1[4] = 1;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0x41;
  *(undefined *)(param_1 + 6) = 0xf;
  *(undefined *)((int)param_1 + 0x19) = 0x20;
  param_1[7] = 0;
  param_1[6] = param_1[6] & 0xffff0008 | 0x18;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1113 start=0xf0058dd0 */

undefined8 _ipc_notify_init_msg_accepted(undefined4 *param_1,undefined4 param_2)

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
  *param_1 = 0x12;
  param_1[1] = 0x20;
  param_1[4] = 1;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0x42;
  *(undefined *)(param_1 + 6) = 0xf;
  *(undefined *)((int)param_1 + 0x19) = 0x20;
  param_1[7] = 0;
  param_1[6] = param_1[6] & 0xffff0008 | 0x18;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1114 start=0xf0058e34 */

undefined8 _ipc_notify_init_port_destroyed(undefined4 *param_1,undefined4 param_2)

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
  *param_1 = 0x80000012;
  param_1[1] = 0x20;
  param_1[4] = 1;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0x45;
  *(undefined *)(param_1 + 6) = 0x10;
  *(undefined *)((int)param_1 + 0x19) = 0x20;
  param_1[7] = 0;
  param_1[6] = param_1[6] & 0xffff0008 | 0x18;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1115 start=0xf0058e9c */

undefined8 _ipc_notify_init_no_senders(undefined4 *param_1,undefined4 param_2)

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
  *param_1 = 0x12;
  param_1[1] = 0x20;
  param_1[4] = 1;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0x46;
  *(undefined *)(param_1 + 6) = 2;
  *(undefined *)((int)param_1 + 0x19) = 0x20;
  param_1[7] = 0;
  param_1[6] = param_1[6] & 0xffff0008 | 0x18;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1116 start=0xf0058f00 */

undefined8 _ipc_notify_init_send_once(undefined4 *param_1,undefined4 param_2)

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
  *param_1 = 0x12;
  param_1[1] = 0x18;
  param_1[4] = 1;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0x47;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1117 start=0xf0058f34 */

undefined8 _ipc_notify_init_dead_name(undefined4 *param_1,undefined4 param_2)

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
  *param_1 = 0x12;
  param_1[1] = 0x20;
  param_1[4] = 1;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[5] = 0x48;
  *(undefined *)(param_1 + 6) = 0xf;
  *(undefined *)((int)param_1 + 0x19) = 0x20;
  param_1[7] = 0;
  param_1[6] = param_1[6] & 0xffff0008 | 0x18;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1118 start=0xf0058f98 */

/* WARNING: Removing unreachable block (ram,0xf0058fd0) */
/* WARNING: Removing unreachable block (ram,0xf0058fb8) */
/* WARNING: Removing unreachable block (ram,0xf0058fac) */
/* WARNING: Removing unreachable block (ram,0xf0058fc4) */
/* WARNING: Removing unreachable block (ram,0xf0058fdc) */
/* WARNING: Removing unreachable block (ram,0xf0058fa0) */

undefined8 _ipc_notify_init(undefined4 param_1,undefined4 param_2)

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
  _ipc_notify_init_port_deleted(&_ipc_notify_port_deleted_template);
  _ipc_notify_init_msg_accepted(&_ipc_notify_msg_accepted_template);
  _ipc_notify_init_port_destroyed(&_ipc_notify_port_destroyed_template);
  _ipc_notify_init_no_senders(&_ipc_notify_no_senders_template);
  _ipc_notify_init_send_once(&_ipc_notify_send_once_template);
  _ipc_notify_init_dead_name(&_ipc_notify_dead_name_template);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1119 start=0xf0058fec */

/* WARNING: Removing unreachable block (ram,0xf0059010) */
/* WARNING: Removing unreachable block (ram,0xf005908c) */
/* WARNING: Removing unreachable block (ram,0xf0059018) */
/* WARNING: Removing unreachable block (ram,0xf0058ff0) */

undefined8 _ipc_notify_port_deleted(undefined4 param_1,undefined4 param_2)

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
  iVar1 = 0x34;
  _kalloc();
  if (iVar1 == 0) {
    _printf(aDroppedPortDel,param_1,param_2);
    _ipc_port_release_sonce(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x34;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_port_deleted_template;
    *(undefined4 *)(iVar1 + 0x18) = DAT_f013bfd4._0_4_;
    *(undefined4 *)(iVar1 + 0x1c) = DAT_f013bfd4._4_4_;
    *(undefined4 *)(iVar1 + 0x20) = DAT_f013bfd4._8_4_;
    *(undefined4 *)(iVar1 + 0x24) = DAT_f013bfd4._12_4_;
    *(undefined4 *)(iVar1 + 0x28) = DAT_f013bfd4._16_4_;
    *(undefined4 *)(iVar1 + 0x2c) = DAT_f013bfd4._20_4_;
    *(undefined4 *)(iVar1 + 0x30) = DAT_f013bfd4._24_4_;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1120 start=0xf005909c */

/* WARNING: Removing unreachable block (ram,0xf00590c0) */
/* WARNING: Removing unreachable block (ram,0xf005913c) */
/* WARNING: Removing unreachable block (ram,0xf00590c8) */
/* WARNING: Removing unreachable block (ram,0xf00590a0) */

undefined8 _ipc_notify_msg_accepted(undefined4 param_1,undefined4 param_2)

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
  iVar1 = 0x34;
  _kalloc();
  if (iVar1 == 0) {
    _printf(aDroppedMsgAcce,param_1,param_2);
    _ipc_port_release_sonce(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x34;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_msg_accepted_template;
    *(undefined4 *)(iVar1 + 0x18) = DAT_f013bf94._0_4_;
    *(undefined4 *)(iVar1 + 0x1c) = DAT_f013bf94._4_4_;
    *(undefined4 *)(iVar1 + 0x20) = DAT_f013bf94._8_4_;
    *(undefined4 *)(iVar1 + 0x24) = DAT_f013bf94._12_4_;
    *(undefined4 *)(iVar1 + 0x28) = DAT_f013bf94._16_4_;
    *(undefined4 *)(iVar1 + 0x2c) = DAT_f013bf94._20_4_;
    *(undefined4 *)(iVar1 + 0x30) = DAT_f013bf94._24_4_;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1121 start=0xf005914c */

/* WARNING: Removing unreachable block (ram,0xf0059178) */
/* WARNING: Removing unreachable block (ram,0xf00591f4) */
/* WARNING: Removing unreachable block (ram,0xf0059170) */
/* WARNING: Removing unreachable block (ram,0xf0059180) */
/* WARNING: Removing unreachable block (ram,0xf0059150) */

undefined8 _ipc_notify_port_destroyed(undefined4 param_1,undefined4 param_2)

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
  iVar1 = 0x34;
  _kalloc();
  if (iVar1 == 0) {
    _printf(aDroppedPortDes,param_1,param_2);
    _ipc_port_release_sonce(param_1);
    _ipc_port_release_receive(param_2);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x34;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_port_destroyed_template;
    *(undefined4 *)(iVar1 + 0x18) = DAT_f013bff4._0_4_;
    *(undefined4 *)(iVar1 + 0x1c) = DAT_f013bff4._4_4_;
    *(undefined4 *)(iVar1 + 0x20) = DAT_f013bff4._8_4_;
    *(undefined4 *)(iVar1 + 0x24) = DAT_f013bff4._12_4_;
    *(undefined4 *)(iVar1 + 0x28) = DAT_f013bff4._16_4_;
    *(undefined4 *)(iVar1 + 0x2c) = DAT_f013bff4._20_4_;
    *(undefined4 *)(iVar1 + 0x30) = DAT_f013bff4._24_4_;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1122 start=0xf0059204 */

/* WARNING: Removing unreachable block (ram,0xf0059228) */
/* WARNING: Removing unreachable block (ram,0xf00592a4) */
/* WARNING: Removing unreachable block (ram,0xf0059230) */
/* WARNING: Removing unreachable block (ram,0xf0059208) */

undefined8 _ipc_notify_no_senders(undefined4 param_1,undefined4 param_2)

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
  iVar1 = 0x34;
  _kalloc();
  if (iVar1 == 0) {
    _printf(aDroppedNoSende,param_1,param_2);
    _ipc_port_release_sonce(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x34;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_no_senders_template;
    *(undefined4 *)(iVar1 + 0x18) = DAT_f013bfb4._0_4_;
    *(undefined4 *)(iVar1 + 0x1c) = DAT_f013bfb4._4_4_;
    *(undefined4 *)(iVar1 + 0x20) = DAT_f013bfb4._8_4_;
    *(undefined4 *)(iVar1 + 0x24) = DAT_f013bfb4._12_4_;
    *(undefined4 *)(iVar1 + 0x28) = DAT_f013bfb4._16_4_;
    *(undefined4 *)(iVar1 + 0x2c) = DAT_f013bfb4._20_4_;
    *(undefined4 *)(iVar1 + 0x30) = DAT_f013bfb4._24_4_;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1123 start=0xf00592b4 */

/* WARNING: Removing unreachable block (ram,0xf00592d4) */
/* WARNING: Removing unreachable block (ram,0xf005933c) */
/* WARNING: Removing unreachable block (ram,0xf00592dc) */
/* WARNING: Removing unreachable block (ram,0xf00592b8) */

undefined8 _ipc_notify_send_once(undefined4 param_1,undefined4 param_2)

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
  iVar1 = 0x2c;
  _kalloc();
  if (iVar1 == 0) {
    _printf(aDroppedSendOnc,param_1);
    _ipc_port_release_sonce(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x2c;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_send_once_template;
    *(undefined4 *)(iVar1 + 0x18) = DAT_f013c014._0_4_;
    *(undefined4 *)(iVar1 + 0x1c) = DAT_f013c014._4_4_;
    *(undefined4 *)(iVar1 + 0x20) = DAT_f013c014._8_4_;
    *(undefined4 *)(iVar1 + 0x24) = DAT_f013c014._12_4_;
    *(undefined4 *)(iVar1 + 0x28) = DAT_f013c014._16_4_;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1124 start=0xf005934c */

/* WARNING: Removing unreachable block (ram,0xf0059370) */
/* WARNING: Removing unreachable block (ram,0xf00593ec) */
/* WARNING: Removing unreachable block (ram,0xf0059378) */
/* WARNING: Removing unreachable block (ram,0xf0059350) */

undefined8 _ipc_notify_dead_name(undefined4 param_1,undefined4 param_2)

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
  iVar1 = 0x34;
  _kalloc();
  if (iVar1 == 0) {
    _printf(aDroppedDeadNam,param_1,param_2);
    _ipc_port_release_sonce(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x34;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_dead_name_template;
    *(undefined4 *)(iVar1 + 0x18) = DAT_f013bf74._0_4_;
    *(undefined4 *)(iVar1 + 0x1c) = DAT_f013bf74._4_4_;
    *(undefined4 *)(iVar1 + 0x20) = DAT_f013bf74._8_4_;
    *(undefined4 *)(iVar1 + 0x24) = DAT_f013bf74._12_4_;
    *(undefined4 *)(iVar1 + 0x28) = DAT_f013bf74._16_4_;
    *(undefined4 *)(iVar1 + 0x2c) = DAT_f013bf74._20_4_;
    *(undefined4 *)(iVar1 + 0x30) = DAT_f013bf74._24_4_;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1125 start=0xf00593fc */

/* WARNING: Removing unreachable block (ram,0xf0059420) */
/* WARNING: Removing unreachable block (ram,0xf00594a4) */
/* WARNING: Removing unreachable block (ram,0xf0059428) */
/* WARNING: Removing unreachable block (ram,0xf0059400) */

undefined8 _ipc_notify_port_deleted_compat(undefined4 param_1,undefined4 param_2)

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
  iVar1 = 0x34;
  _kalloc();
  if (iVar1 == 0) {
    _printf(aDroppedPortDel_0,param_1,param_2);
    _ipc_port_release_send(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x34;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_port_deleted_template;
    *(undefined4 *)(iVar1 + 0x18) = DAT_f013bfd4._0_4_;
    *(undefined4 *)(iVar1 + 0x1c) = DAT_f013bfd4._4_4_;
    *(undefined4 *)(iVar1 + 0x20) = DAT_f013bfd4._8_4_;
    *(undefined4 *)(iVar1 + 0x24) = DAT_f013bfd4._12_4_;
    *(undefined4 *)(iVar1 + 0x28) = DAT_f013bfd4._16_4_;
    *(undefined4 *)(iVar1 + 0x2c) = DAT_f013bfd4._20_4_;
    *(undefined4 *)(iVar1 + 0x30) = DAT_f013bfd4._24_4_;
    *(undefined4 *)(iVar1 + 0x14) = 0x11;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1126 start=0xf00594b4 */

/* WARNING: Removing unreachable block (ram,0xf00594d8) */
/* WARNING: Removing unreachable block (ram,0xf005955c) */
/* WARNING: Removing unreachable block (ram,0xf00594e0) */
/* WARNING: Removing unreachable block (ram,0xf00594b8) */

undefined8 _ipc_notify_msg_accepted_compat(undefined4 param_1,undefined4 param_2)

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
  iVar1 = 0x34;
  _kalloc();
  if (iVar1 == 0) {
    _printf(aDroppedMsgAcce_0,param_1,param_2);
    _ipc_port_release_send(param_1);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x34;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_msg_accepted_template;
    *(undefined4 *)(iVar1 + 0x18) = DAT_f013bf94._0_4_;
    *(undefined4 *)(iVar1 + 0x1c) = DAT_f013bf94._4_4_;
    *(undefined4 *)(iVar1 + 0x20) = DAT_f013bf94._8_4_;
    *(undefined4 *)(iVar1 + 0x24) = DAT_f013bf94._12_4_;
    *(undefined4 *)(iVar1 + 0x28) = DAT_f013bf94._16_4_;
    *(undefined4 *)(iVar1 + 0x2c) = DAT_f013bf94._20_4_;
    *(undefined4 *)(iVar1 + 0x30) = DAT_f013bf94._24_4_;
    *(undefined4 *)(iVar1 + 0x14) = 0x11;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1127 start=0xf005956c */

/* WARNING: Removing unreachable block (ram,0xf0059598) */
/* WARNING: Removing unreachable block (ram,0xf0059620) */
/* WARNING: Removing unreachable block (ram,0xf0059590) */
/* WARNING: Removing unreachable block (ram,0xf00595a0) */
/* WARNING: Removing unreachable block (ram,0xf0059570) */

undefined8 _ipc_notify_port_destroyed_compat(undefined4 param_1,undefined4 param_2)

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
  iVar1 = 0x34;
  _kalloc();
  if (iVar1 == 0) {
    _printf(aDroppedPortDes_0,param_1,param_2);
    _ipc_port_release_send(param_1);
    _ipc_port_release_receive(param_2);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x34;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(undefined4 *)(iVar1 + 0x14) = _ipc_notify_port_destroyed_template;
    *(undefined4 *)(iVar1 + 0x18) = DAT_f013bff4._0_4_;
    *(undefined4 *)(iVar1 + 0x1c) = DAT_f013bff4._4_4_;
    *(undefined4 *)(iVar1 + 0x20) = DAT_f013bff4._8_4_;
    *(undefined4 *)(iVar1 + 0x24) = DAT_f013bff4._12_4_;
    *(undefined4 *)(iVar1 + 0x28) = DAT_f013bff4._16_4_;
    *(undefined4 *)(iVar1 + 0x2c) = DAT_f013bff4._20_4_;
    *(undefined4 *)(iVar1 + 0x30) = DAT_f013bff4._24_4_;
    *(undefined4 *)(iVar1 + 0x14) = 0x80000011;
    *(undefined4 *)(iVar1 + 0x1c) = param_1;
    *(undefined4 *)(iVar1 + 0x30) = param_2;
    _ipc_mqueue_send(iVar1,0x10000,0,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1128 start=0xf0059630 */

/* WARNING: Removing unreachable block (ram,0xf0059644) */

undefined8 _ipc_object_reference(int *param_1,undefined4 param_2)

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
  param_1[1] = param_1[1] + 1;
  *param_1 = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1129 start=0xf0059670 */

/* WARNING: Removing unreachable block (ram,0xf00596cc) */
/* WARNING: Removing unreachable block (ram,0xf0059684) */

undefined8 _ipc_object_release(int *param_1,undefined4 param_2)

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
  *param_1 = 0;
  if (iVar2 + -1 == 0) {
    _zfree((&_ipc_object_zones)[(param_1[2] & 0x7fffffffU) >> 0x10],param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1130 start=0xf00596dc */

/* WARNING: Removing unreachable block (ram,0xf005973c) */
/* WARNING: Removing unreachable block (ram,0xf00596e8) */

undefined8 _ipc_object_translate(int param_1,int *param_2,char param_3,undefined4 *param_4)

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
    if ((**(uint **)((int)register0x00000038 + -0xc) & 1 << (param_3 + 0x10U & 0x1f)) == 0) {
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
      *param_4 = param_2;
      iVar2 = 0;
    }
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1131 start=0xf0059764 */

/* WARNING: Removing unreachable block (ram,0xf0059774) */

undefined8 _ipc_object_alloc_dead(int param_1,undefined4 param_2)

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
  _ipc_entry_alloc(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 == 0) {
    **(uint **)((int)register0x00000038 + -0xc) =
         **(uint **)((int)register0x00000038 + -0xc) | 0x100001;
    *(undefined4 *)(param_1 + 8) = 0;
    iVar1 = 0;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1132 start=0xf00597b0 */

/* WARNING: Removing unreachable block (ram,0xf00597dc) */
/* WARNING: Removing unreachable block (ram,0xf00597c0) */

undefined8 _ipc_object_alloc_dead_name(int param_1,undefined4 param_2)

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
  _ipc_entry_alloc_name(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar2 == 0) {
    iVar1 = param_1;
    _ipc_right_inuse(param_1,param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
    iVar2 = 0xd;
    if (iVar1 == 0) {
      **(uint **)((int)register0x00000038 + -0xc) =
           **(uint **)((int)register0x00000038 + -0xc) | 0x100001;
      *(undefined4 *)(param_1 + 8) = 0;
      iVar2 = 0;
    }
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1133 start=0xf0059818 */

/* WARNING: Removing unreachable block (ram,0xf0059898) */
/* WARNING: Removing unreachable block (ram,0xf005984c) */
/* WARNING: Removing unreachable block (ram,0xf0059864) */
/* WARNING: Removing unreachable block (ram,0xf005982c) */

undefined8
_ipc_object_alloc(int param_1,int param_2,uint param_3,uint param_4,undefined4 param_5,
                 undefined4 *param_6)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
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
  piVar1 = (int *)(&_ipc_object_zones)[param_2];
  _zalloc();
  if (piVar1 == (int *)0x0) {
    iVar4 = 6;
  }
  else {
    iVar4 = param_1;
    _ipc_entry_alloc(param_1,param_5,(undefined *)((int)register0x00000038 + -0xc));
    puVar2 = *(uint **)((int)register0x00000038 + -0xc);
    if (iVar4 == 0) {
      puVar2[1] = (uint)piVar1;
      *puVar2 = *puVar2 | param_3 | param_4;
      *piVar1 = 0;
      do {
        do {
        } while (*piVar1 != 0);
        piVar3 = piVar1;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      *(undefined4 *)(param_1 + 8) = 0;
      piVar1[1] = 1;
      piVar1[2] = param_2 << 0x10 | 0x80000000;
      *param_6 = piVar1;
      iVar4 = 0;
    }
    else {
      _zfree((&_ipc_object_zones)[param_2],piVar1);
    }
  }
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=1134 start=0xf00598d4 */

/* WARNING: Removing unreachable block (ram,0xf0059948) */
/* WARNING: Removing unreachable block (ram,0xf0059930) */
/* WARNING: Removing unreachable block (ram,0xf0059908) */
/* WARNING: Removing unreachable block (ram,0xf0059980) */
/* WARNING: Removing unreachable block (ram,0xf0059920) */
/* WARNING: Removing unreachable block (ram,0xf00598e8) */

undefined8
_ipc_object_alloc_name
          (int param_1,int param_2,uint param_3,uint param_4,undefined4 param_5,undefined4 *param_6)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
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
  piVar1 = (int *)(&_ipc_object_zones)[param_2];
  _zalloc();
  if (piVar1 == (int *)0x0) {
    iVar4 = 6;
  }
  else {
    iVar4 = param_1;
    _ipc_entry_alloc_name(param_1,param_5,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar4 == 0) {
      iVar4 = param_1;
      _ipc_right_inuse(param_1,param_5,*(undefined4 *)((int)register0x00000038 + -0xc));
      puVar2 = *(uint **)((int)register0x00000038 + -0xc);
      if (iVar4 == 0) {
        puVar2[1] = (uint)piVar1;
        *puVar2 = *puVar2 | param_3 | param_4;
        *piVar1 = 0;
        do {
          do {
          } while (*piVar1 != 0);
          piVar3 = piVar1;
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        *(undefined4 *)(param_1 + 8) = 0;
        piVar1[1] = 1;
        piVar1[2] = param_2 << 0x10 | 0x80000000;
        *param_6 = piVar1;
        iVar4 = 0;
      }
      else {
        _zfree((&_ipc_object_zones)[param_2],piVar1);
        iVar4 = 0xd;
      }
    }
    else {
      _zfree((&_ipc_object_zones)[param_2],piVar1);
    }
  }
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=1135 start=0xf00599bc */

/* WARNING: Removing unreachable block (ram,0xf0059a54) */

undefined8 _ipc_object_copyin_type(undefined4 param_1,undefined4 param_2)

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
  switch(param_1) {
  :
    _panic(aIpcObjectCopyi);
  case :
    uVar1 = 0;
    break;
  case :
  case :
    uVar1 = 0x10;
    break;
  case :
  case :
  case :
  case :
    uVar1 = 0x11;
    break;
  case :
  case :
    uVar1 = 0x12;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1136 start=0xf0059a68 */

/* WARNING: Removing unreachable block (ram,0xf0059ac8) */
/* WARNING: Removing unreachable block (ram,0xf0059aa4) */
/* WARNING: Removing unreachable block (ram,0xf0059aec) */
/* WARNING: Removing unreachable block (ram,0xf0059a78) */

undefined8 _ipc_object_copyin(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  iVar1 = param_1;
  _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 == 0) {
    iVar1 = param_1;
    _ipc_right_copyin(param_1,param_2,*(undefined4 *)((int)register0x00000038 + -0xc),param_3,1,
                      param_4,(undefined *)((int)register0x00000038 + -0x10));
    if ((**(uint **)((int)register0x00000038 + -0xc) & 0x1f0000) == 0) {
      _ipc_entry_dealloc(param_1,param_2);
    }
    *(undefined4 *)(param_1 + 8) = 0;
    if ((iVar1 == 0) && (*(int *)((int)register0x00000038 + -0x10) != 0)) {
      _ipc_notify_port_deleted(*(int *)((int)register0x00000038 + -0x10),param_2);
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1137 start=0xf0059afc */

/* WARNING: Removing unreachable block (ram,0xf0059bb0) */
/* WARNING: Removing unreachable block (ram,0xf0059c04) */
/* WARNING: Removing unreachable block (ram,0xf0059c8c) */
/* WARNING: Removing unreachable block (ram,0xf0059b78) */
/* WARNING: Removing unreachable block (ram,0xf0059c54) */

undefined8 _ipc_object_copyin_from_kernel(int *param_1,undefined4 param_2)

{
  int iVar1;
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
  switch(param_2) {
  case :
  case :
    do {
      do {
      } while (*param_1 != 0);
      piVar2 = param_1;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    param_1[6] = 0;
    param_1[4] = 0;
    param_1[3] = 0;
    *param_1 = 0;
    break;
  case :
  case :
    do {
      do {
      } while (*param_1 != 0);
      piVar2 = param_1;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    if (param_1[2] < 0) {
      param_1[7] = param_1[7] + 1;
      iVar1 = param_1[1];
    }
    else {
      iVar1 = param_1[1];
    }
    param_1[1] = iVar1 + 1;
    *param_1 = 0;
    break;
  :
    _panic(aIpcObjectCopyi_0);
    break;
  case :
  case :
    break;
  case :
    do {
      do {
      } while (*param_1 != 0);
      piVar2 = param_1;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    param_1[1] = param_1[1] + 1;
    param_1[6] = param_1[6] + 1;
    *param_1 = 0;
    param_1[7] = param_1[7] + 1;
    break;
  case :
    do {
      do {
      } while (*param_1 != 0);
      piVar2 = param_1;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    param_1[1] = param_1[1] + 1;
    param_1[8] = param_1[8] + 1;
    *param_1 = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1138 start=0xf0059c9c */

/* WARNING: Removing unreachable block (ram,0xf0059ce4) */

undefined8 _ipc_object_destroy(undefined4 param_1,uint param_2)

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
  if (param_2 != 0x11) {
    if (param_2 < 0x12) {
      if (param_2 == 0x10) {
        _ipc_port_release_receive();
      }
    }
    else if (param_2 == 0x12) {
      _ipc_notify_send_once();
      return CONCAT44(param_2,param_1);
    }
    return CONCAT44(param_2,param_1);
  }
  _ipc_port_release_send(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1139 start=0xf0059cf4 */

/* WARNING: Removing unreachable block (ram,0xf0059dd4) */
/* WARNING: Removing unreachable block (ram,0xf0059da8) */
/* WARNING: Removing unreachable block (ram,0xf0059d50) */
/* WARNING: Removing unreachable block (ram,0xf0059d6c) */
/* WARNING: Removing unreachable block (ram,0xf0059e04) */
/* WARNING: Removing unreachable block (ram,0xf0059d80) */
/* WARNING: Removing unreachable block (ram,0xf0059d10) */

undefined8
_ipc_object_copyout(int param_1,int *param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
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
  do {
    do {
    } while (*(int *)(param_1 + 8) != 0);
    piVar1 = (int *)(param_1 + 8);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  iVar2 = *(int *)(param_1 + 0xc);
  while (iVar2 != 0) {
    iVar2 = param_1;
    if ((param_3 != 0x12) &&
       (iVar3 = param_1,
       _ipc_right_reverse(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc),
                          (undefined *)((int)register0x00000038 + -0x10)), iVar3 != 0))
    goto loc_F0059DF4;
    iVar3 = param_1;
    _ipc_entry_get(param_1,(undefined *)((int)register0x00000038 + -0xc),
                   (undefined *)((int)register0x00000038 + -0x10));
    if (iVar3 == 0) goto loc_F0059D98;
    _ipc_entry_grow_table();
    if (iVar2 != 0) goto locret_F0059E24;
    iVar2 = *(int *)(param_1 + 0xc);
  }
  *(undefined4 *)(param_1 + 8) = 0;
  iVar2 = 0x10;
locret_F0059E24:
  return CONCAT44(param_2,iVar2);
loc_F0059D98:
  do {
    do {
    } while (*param_2 != 0);
    piVar1 = param_2;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
  if (param_2[2] < 0) {
    *(int **)(*(int *)((int)register0x00000038 + -0x10) + 4) = param_2;
loc_F0059DF4:
    _ipc_right_copyout(param_1,*(undefined4 *)((int)register0x00000038 + -0xc),
                       *(undefined4 *)((int)register0x00000038 + -0x10),param_3,param_4,param_2);
    *(undefined4 *)(param_1 + 8) = 0;
    if (iVar2 == 0) {
      *param_5 = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
  }
  else {
    *param_2 = 0;
    _ipc_entry_dealloc(param_1,uVar4,*(undefined4 *)((int)register0x00000038 + -0x10));
    *(undefined4 *)(param_1 + 8) = 0;
    iVar2 = 0x14;
  }
  goto locret_F0059E24;
}
/* GHIDRADEC_FUNCTION index=1140 start=0xf0059e2c */

/* WARNING: Removing unreachable block (ram,0xf0059e98) */
/* WARNING: Removing unreachable block (ram,0xf0059ee0) */
/* WARNING: Removing unreachable block (ram,0xf0059e60) */
/* WARNING: Removing unreachable block (ram,0xf0059eb4) */
/* WARNING: Removing unreachable block (ram,0xf0059f10) */
/* WARNING: Removing unreachable block (ram,0xf0059f3c) */
/* WARNING: Removing unreachable block (ram,0xf0059e38) */

undefined8
_ipc_object_copyout_name(int param_1,int *param_2,int param_3,undefined4 param_4,int param_5)

{
  int *piVar1;
  uint *puVar2;
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
  iVar3 = param_1;
  _ipc_entry_alloc_name(param_1,param_5,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar3 != 0) goto locret_F0059F4C;
  if (param_3 == 0x12) {
loc_F0059EAC:
    iVar3 = param_1;
    _ipc_right_inuse(param_1,param_5,*(undefined4 *)((int)register0x00000038 + -0xc));
    if (iVar3 != 0) {
      iVar3 = 0xd;
      goto locret_F0059F4C;
    }
    do {
      do {
      } while (*param_2 != 0);
      piVar1 = param_2;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if (-1 < param_2[2]) {
      *param_2 = 0;
      _ipc_entry_dealloc(param_1,param_5,*(undefined4 *)((int)register0x00000038 + -0xc));
      *(undefined4 *)(param_1 + 8) = 0;
      iVar3 = 0x14;
      goto locret_F0059F4C;
    }
    *(int **)(*(int *)((int)register0x00000038 + -0xc) + 4) = param_2;
  }
  else {
    iVar3 = param_1;
    _ipc_right_reverse(param_1,param_2,(undefined *)((int)register0x00000038 + -0x10),
                       (undefined *)((int)register0x00000038 + -0x14));
    if (iVar3 == 0) goto loc_F0059EAC;
    puVar2 = *(uint **)((int)register0x00000038 + -0xc);
    if (param_5 != *(int *)((int)register0x00000038 + -0x10)) {
      *param_2 = 0;
      if ((*puVar2 & 0x1f0000) == 0) {
        _ipc_entry_dealloc(param_1,param_5);
      }
      *(undefined4 *)(param_1 + 8) = 0;
      iVar3 = 0x15;
      goto locret_F0059F4C;
    }
  }
  iVar3 = param_1;
  _ipc_right_copyout(param_1,param_5,*(undefined4 *)((int)register0x00000038 + -0xc),param_3,param_4
                     ,param_2);
  *(undefined4 *)(param_1 + 8) = 0;
locret_F0059F4C:
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=1141 start=0xf0059f54 */

/* WARNING: Removing unreachable block (ram,0xf0059fe0) */
/* WARNING: Removing unreachable block (ram,0xf005a02c) */
/* WARNING: Removing unreachable block (ram,0xf005a01c) */

undefined8 _ipc_object_copyout_dest(int param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 uVar3;
  undefined4 uVar4;
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
  uVar3 = 0;
  iVar1 = param_2[1];
  param_2[1] = iVar1 + -1;
  if (param_3 != 0x11) {
    if (param_3 == 0x12) {
      if (param_2[3] != param_1) {
        param_2[1] = iVar1;
        *param_2 = 0;
        _ipc_notify_send_once(param_2);
        *param_4 = 0;
        goto locret_F005A038;
      }
      *param_2 = 0;
      uVar3 = param_2[4];
      param_2[8] = param_2[8] + -1;
    }
    else {
      _panic(aIpcObjectCopyo_0);
    }
    *param_4 = uVar3;
    goto locret_F005A038;
  }
  iVar2 = 0;
  iVar1 = param_2[7];
  uVar3 = 0;
  param_2[7] = iVar1 + -1;
  if (iVar1 + -1 == 0) {
    iVar2 = param_2[9];
    if (iVar2 != 0) {
      param_2[9] = 0;
      uVar3 = param_2[6];
      goto loc_F0059FBC;
    }
    iVar1 = param_2[3];
  }
  else {
loc_F0059FBC:
    iVar1 = param_2[3];
  }
  uVar4 = 0;
  if (iVar1 == param_1) {
    uVar4 = param_2[4];
  }
  *param_2 = 0;
  if (iVar2 == 0) {
    *param_4 = uVar4;
  }
  else {
    _ipc_notify_no_senders(iVar2,uVar3);
    *param_4 = uVar4;
  }
locret_F005A038:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1142 start=0xf005a040 */

/* WARNING: Removing unreachable block (ram,0xf005a0c4) */
/* WARNING: Removing unreachable block (ram,0xf005a068) */
/* WARNING: Removing unreachable block (ram,0xf005a08c) */
/* WARNING: Removing unreachable block (ram,0xf005a0a8) */
/* WARNING: Removing unreachable block (ram,0xf005a04c) */

undefined8 _ipc_object_rename(int param_1,int param_2,int param_3)

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
  iVar1 = param_1;
  _ipc_entry_alloc_name(param_1,param_3,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 == 0) {
    iVar1 = param_1;
    _ipc_right_inuse(param_1,param_3,*(undefined4 *)((int)register0x00000038 + -0xc));
    if (iVar1 == 0) {
      if ((param_2 == param_3) || (iVar1 = param_1, _ipc_entry_lookup(param_1,param_2), iVar1 == 0))
      {
        _ipc_entry_dealloc(param_1,param_3,*(undefined4 *)((int)register0x00000038 + -0xc));
        *(undefined4 *)(param_1 + 8) = 0;
        iVar1 = 0xf;
      }
      else {
        _ipc_right_rename(param_1,param_2,iVar1,param_3,
                          *(undefined4 *)((int)register0x00000038 + -0xc));
        iVar1 = param_1;
      }
    }
    else {
      iVar1 = 0xd;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1143 start=0xf005a0d8 */

/* WARNING: Removing unreachable block (ram,0xf005a0fc) */

undefined8 _ipc_object_copyout_type_compat(uint param_1,undefined4 param_2)

{
  bool bVar1;
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
  if (param_1 == 0x10) {
    param_1 = 5;
  }
  else if ((param_1 < 0x12) || (bVar1 = 0x12 < param_1, param_1 = 6, bVar1)) {
    _panic(aIpcObjectCopyo);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1144 start=0xf005a10c */

/* WARNING: Removing unreachable block (ram,0xf005a13c) */
/* WARNING: Removing unreachable block (ram,0xf005a118) */

undefined8
_ipc_object_copyin_compat
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

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
  iVar1 = param_1;
  _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 == 0) {
    _ipc_right_copyin_compat
              (param_1,param_2,*(undefined4 *)((int)register0x00000038 + -0xc),param_3,param_4,
               param_5);
    iVar1 = param_1;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1145 start=0xf005a14c */

/* WARNING: Removing unreachable block (ram,0xf005a178) */
/* WARNING: Removing unreachable block (ram,0xf005a158) */

undefined8
_ipc_object_copyin_header(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  iVar1 = param_1;
  _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 == 0) {
    _ipc_right_copyin_header
              (param_1,param_2,*(undefined4 *)((int)register0x00000038 + -0xc),param_3,param_4);
    iVar1 = param_1;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1146 start=0xf005a188 */

/* WARNING: Removing unreachable block (ram,0xf005a2cc) */
/* WARNING: Removing unreachable block (ram,0xf005a29c) */
/* WARNING: Removing unreachable block (ram,0xf005a2e8) */
/* WARNING: Removing unreachable block (ram,0xf005a268) */
/* WARNING: Removing unreachable block (ram,0xf005a200) */
/* WARNING: Removing unreachable block (ram,0xf005a1e4) */
/* WARNING: Removing unreachable block (ram,0xf005a23c) */
/* WARNING: Removing unreachable block (ram,0xf005a284) */
/* WARNING: Removing unreachable block (ram,0xf005a324) */
/* WARNING: Removing unreachable block (ram,0xf005a2a8) */
/* WARNING: Removing unreachable block (ram,0xf005a214) */
/* WARNING: Removing unreachable block (ram,0xf005a1a4) */

undefined8 _ipc_object_copyout_compat(int *param_1,int *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint *puVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar5;
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
  do {
    do {
    } while (param_1[2] != 0);
    piVar5 = param_1 + 2;
    _simple_lock_try();
  } while (piVar5 == (int *)0x0);
  iVar1 = param_1[3];
  do {
    if (iVar1 == 0) {
      param_1[2] = 0;
      piVar5 = (int *)0x10;
locret_F005A344:
      return CONCAT44(param_2,piVar5);
    }
    piVar5 = param_1;
    if ((param_3 != 0x12) &&
       (piVar2 = param_1,
       _ipc_right_reverse(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc),
                          (undefined *)((int)register0x00000038 + -0x10)), piVar2 != (int *)0x0)) {
loc_F005A314:
      _ipc_right_copyout(param_1,*(undefined4 *)((int)register0x00000038 + -0xc),
                         *(undefined4 *)((int)register0x00000038 + -0x10),param_3,1,param_2);
      param_1[2] = 0;
      if (piVar5 == (int *)0x0) {
        *param_4 = *(undefined4 *)((int)register0x00000038 + -0xc);
      }
      goto locret_F005A344;
    }
    piVar2 = param_1;
    _ipc_entry_get(param_1,(undefined *)((int)register0x00000038 + -0xc),
                   (undefined *)((int)register0x00000038 + -0x10));
    if (piVar2 == (int *)0x0) {
      do {
        do {
        } while (*param_2 != 0);
        piVar2 = param_2;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      uVar3 = *(undefined4 *)((int)register0x00000038 + -0xc);
      if (-1 < param_2[2]) {
        *param_2 = 0;
        _ipc_entry_dealloc(param_1,uVar3,*(undefined4 *)((int)register0x00000038 + -0x10));
        param_1[2] = 0;
        piVar5 = (int *)0x14;
        goto locret_F005A344;
      }
      piVar2 = param_2;
      _ipc_port_dnrequest(param_2,uVar3,(uint)param_1 | 1,
                          (undefined *)((int)register0x00000038 + -0x14));
      if (piVar2 == (int *)0x0) {
        _ipc_space_reference(param_1,*(undefined4 *)((int)register0x00000038 + -0xc));
        puVar4 = *(uint **)((int)register0x00000038 + -0x10);
        puVar4[2] = *(uint *)((int)register0x00000038 + -0x14);
        puVar4[1] = (uint)param_2;
        *puVar4 = *puVar4 | 0x400000;
        goto loc_F005A314;
      }
      _ipc_entry_dealloc(param_1,*(undefined4 *)((int)register0x00000038 + -0xc),
                         *(undefined4 *)((int)register0x00000038 + -0x10));
      param_1[2] = 0;
      piVar5 = param_2;
      _ipc_port_dngrow();
      if (piVar5 != (int *)0x0) goto locret_F005A344;
      do {
        do {
        } while (param_1[2] != 0);
        piVar5 = param_1 + 2;
        _simple_lock_try();
      } while (piVar5 == (int *)0x0);
      iVar1 = param_1[3];
    }
    else {
      _ipc_entry_grow_table();
      if (piVar5 != (int *)0x0) goto locret_F005A344;
      iVar1 = param_1[3];
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1147 start=0xf005a34c */

/* WARNING: Removing unreachable block (ram,0xf005a494) */
/* WARNING: Removing unreachable block (ram,0xf005a444) */
/* WARNING: Removing unreachable block (ram,0xf005a414) */
/* WARNING: Removing unreachable block (ram,0xf005a3c0) */
/* WARNING: Removing unreachable block (ram,0xf005a374) */
/* WARNING: Removing unreachable block (ram,0xf005a3a0) */
/* WARNING: Removing unreachable block (ram,0xf005a3e4) */
/* WARNING: Removing unreachable block (ram,0xf005a430) */
/* WARNING: Removing unreachable block (ram,0xf005a47c) */
/* WARNING: Removing unreachable block (ram,0xf005a4a0) */
/* WARNING: Removing unreachable block (ram,0xf005a358) */

undefined8 _ipc_object_copyout_name_compat(int *param_1,int *param_2,int param_3,undefined4 param_4)

{
  uint *puVar1;
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
  do {
    piVar2 = param_1;
    _ipc_entry_alloc_name(param_1,param_4,(undefined *)((int)register0x00000038 + -0xc));
    if (piVar2 != (int *)0x0) break;
    piVar2 = param_1;
    _ipc_right_inuse(param_1,param_4,*(undefined4 *)((int)register0x00000038 + -0xc));
    if (piVar2 != (int *)0x0) {
      piVar2 = (int *)0xd;
      break;
    }
    if ((param_3 != 0x12) &&
       (piVar2 = param_1,
       _ipc_right_reverse(param_1,param_2,(undefined *)((int)register0x00000038 + -0x10),
                          (undefined *)((int)register0x00000038 + -0x14)), piVar2 != (int *)0x0)) {
      *param_2 = 0;
      _ipc_entry_dealloc(param_1,param_4,*(undefined4 *)((int)register0x00000038 + -0xc));
      param_1[2] = 0;
      piVar2 = (int *)0x15;
      break;
    }
    do {
      do {
      } while (*param_2 != 0);
      piVar2 = param_2;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    if (-1 < param_2[2]) {
      *param_2 = 0;
      _ipc_entry_dealloc(param_1,param_4,*(undefined4 *)((int)register0x00000038 + -0xc));
      param_1[2] = 0;
      piVar2 = (int *)0x14;
      break;
    }
    piVar2 = param_2;
    _ipc_port_dnrequest(param_2,param_4,(uint)param_1 | 1,
                        (undefined *)((int)register0x00000038 + -0x18));
    if (piVar2 == (int *)0x0) {
      _ipc_space_reference(param_1);
      puVar1 = *(uint **)((int)register0x00000038 + -0xc);
      puVar1[2] = *(uint *)((int)register0x00000038 + -0x18);
      puVar1[1] = (uint)param_2;
      *puVar1 = *puVar1 | 0x400000;
      piVar2 = param_1;
      _ipc_right_copyout(param_1,param_4,puVar1,param_3,1,param_2);
      param_1[2] = 0;
      break;
    }
    _ipc_entry_dealloc(param_1,param_4,*(undefined4 *)((int)register0x00000038 + -0xc));
    param_1[2] = 0;
    piVar2 = param_2;
    _ipc_port_dngrow();
  } while (piVar2 == (int *)0x0);
  return CONCAT44(param_2,piVar2);
}
/* GHIDRADEC_FUNCTION index=1148 start=0xf005a4c0 */

/* WARNING: Removing unreachable block (ram,0xf005a4dc) */

undefined8 _ipc_port_timestamp(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
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
    } while (_ipc_port_timestamp_lock_data != 0);
    puVar2 = &_ipc_port_timestamp_lock_data;
    _simple_lock_try();
    iVar1 = _ipc_port_timestamp_data;
  } while (puVar2 == (undefined4 *)0x0);
  _ipc_port_timestamp_lock_data = 0;
  _ipc_port_timestamp_data = _ipc_port_timestamp_data + 1;
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1149 start=0xf005a50c */

undefined8 _ipc_port_dnrequest(int param_1,int param_2,int param_3,int *param_4)

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
  int *piVar2;
  undefined4 unaff_i5;
  int iVar3;
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
  piVar2 = *(int **)(param_1 + 0x2c);
  if (piVar2 == (int *)0x0) {
    uVar1 = 3;
  }
  else {
    iVar3 = *piVar2;
    if (iVar3 == 0) {
      uVar1 = 3;
    }
    else {
      uVar1 = 0;
      *piVar2 = piVar2[iVar3 * 2];
      piVar2[iVar3 * 2 + 1] = param_2;
      piVar2[iVar3 * 2] = param_3;
      *param_4 = iVar3;
    }
  }
  return CONCAT44(param_2,uVar1);
}

