
/* WARNING: Removing unreachable block (ram,0xf007307c) */
/* WARNING: Removing unreachable block (ram,0xf007301c) */
/* WARNING: Removing unreachable block (ram,0xf0073044) */
/* WARNING: Removing unreachable block (ram,0xf0072f78) */
/* WARNING: Removing unreachable block (ram,0xf0072f48) */
/* WARNING: Removing unreachable block (ram,0xf0072f04) */
/* WARNING: Removing unreachable block (ram,0xf0072ef8) */
/* WARNING: Removing unreachable block (ram,0xf0072f10) */
/* WARNING: Removing unreachable block (ram,0xf0072f58) */
/* WARNING: Removing unreachable block (ram,0xf0072fb8) */
/* WARNING: Removing unreachable block (ram,0xf0072ff0) */
/* WARNING: Removing unreachable block (ram,0xf0073068) */
/* WARNING: Removing unreachable block (ram,0xf0073094) */
/* WARNING: Removing unreachable block (ram,0xf0072ee0) */

sqword _task_create(int *param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar5;
  undefined4 unaff_i1;
  undefined *puVar6;
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
  puVar1 = _task_zone;
  _zalloc();
  if (puVar1 == (undefined4 *)0x0) {
    _panic(aTaskCreateNoMe);
  }
  uVar3 = _u_task_zone;
  _zalloc();
  puVar1[0xe] = uVar3;
  _utask_zero(puVar1);
  puVar1[1] = 2;
  uVar3 = _kernel_map;
  if (param_3 != &_kernel_task) {
    if (param_2 != 0) {
      iVar2 = param_1[3];
      _vm_map_fork();
      puVar1[3] = iVar2;
      goto loc_F0072F84;
    }
    uVar3 = 0;
    _pmap_create();
    _vm_map_create();
  }
  puVar1[3] = uVar3;
loc_F0072F84:
  *puVar1 = 0;
  puVar1[8] = puVar1 + 7;
  puVar1[7] = puVar1 + 7;
  puVar1[10] = 0;
  puVar1[6] = 0;
  puVar1[2] = 1;
  puVar1[0x11] = 0;
  puVar1[9] = 0;
  puVar1[0x10] = 0;
  puVar1[0x14] = 0;
  _ipc_task_init(puVar1,param_1);
  puVar1[0x15] = 0;
  puVar1[0x16] = 0;
  puVar1[0x17] = 0;
  puVar1[0x18] = 0;
  if (param_1 == (int *)0x0) {
    puVar1[0x13] = 0;
    puVar6 = _default_pset;
    _pset_reference(_default_pset);
    puVar1[0x12] = 10;
    puVar5 = unk_F0135118;
  }
  else {
    puVar1[0x13] = param_1[0x13];
    do {
      do {
      } while (*param_1 != 0);
      piVar4 = param_1;
      _simple_lock_try();
    } while (piVar4 == (int *)0x0);
    puVar6 = (undefined *)param_1[0xb];
    if (*(int *)(puVar6 + 0x154) == 0) {
      puVar6 = _default_pset;
    }
    _pset_reference(puVar6);
    puVar1[0x12] = param_1[0x12];
    *param_1 = 0;
    puVar5 = puVar6 + 0x158;
  }
  do {
    do {
    } while (*(int *)puVar5 != 0);
    piVar4 = (int *)puVar5;
    _simple_lock_try();
  } while (piVar4 == (int *)0x0);
  _pset_add_task(puVar6,puVar1);
  *(undefined4 *)(puVar6 + 0x158) = 0;
  puVar1[0xc] = 1;
  puVar1[0xd] = 0;
  _ipc_task_enable(puVar1);
  *param_3 = puVar1;
  return ZEXT48(puVar6) << 0x20;
}
