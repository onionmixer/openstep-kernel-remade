
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
