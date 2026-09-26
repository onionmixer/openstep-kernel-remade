
/* WARNING: Removing unreachable block (ram,0xf008c500) */
/* WARNING: Removing unreachable block (ram,0xf008c4c4) */
/* WARNING: Removing unreachable block (ram,0xf008c484) */
/* WARNING: Removing unreachable block (ram,0xf008c490) */
/* WARNING: Removing unreachable block (ram,0xf008c4f4) */
/* WARNING: Removing unreachable block (ram,0xf008c478) */
/* WARNING: Removing unreachable block (ram,0xf008c460) */

undefined8 sub_F008C44C(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
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
  iVar1 = _kernel_task;
  _task_create(_kernel_task,0,&_IOTask_kern);
  if (iVar1 == 0) {
    _task_deallocate(_IOTask_kern,0);
    _vm_map_deallocate(*(undefined4 *)(_IOTask_kern + 0xc));
    iVar1 = _IOTask_kern;
    *(undefined4 *)(_IOTask_kern + 0xc) = _kernel_map;
    *(undefined4 *)(iVar1 + 0x3c) = _kernel_proc;
    *(undefined4 *)(iVar1 + 0x50) = 1;
    _lock_init(*(int *)(iVar1 + 0x38) + 0x20,1);
    iVar1 = _IOTask_kern;
    *(undefined4 *)(*(int *)(_IOTask_kern + 0x38) + 0x1c) = _rootcred;
    **(undefined4 **)(iVar1 + 0x38) = _kernel_proc;
    _processor_set_policy_enable(_default_pset,2);
    uVar2 = *(undefined4 *)(_IOTask_kern + 0x6c);
    _IOTaskGetPort();
    _IOTask = uVar2;
  }
  else {
    _IOLog(aIolibioinitTas);
  }
  return CONCAT44(param_2,param_1);
}

