
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

