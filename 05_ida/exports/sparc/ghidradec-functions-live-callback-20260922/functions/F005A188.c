
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

