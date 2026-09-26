
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

