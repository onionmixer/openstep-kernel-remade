
undefined4 _task_create(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  puVar2 = (undefined4 *)_zalloc(_task_zone);
  if (puVar2 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aTaskCreateNoMe);
  }
  uVar3 = _zalloc(_u_task_zone);
  puVar2[0xc] = uVar3;
  _utask_zero(puVar2);
  *puVar2 = 2;
  if (param_3 == &_kernel_task) {
    puVar2[2] = _kernel_map;
  }
  else if (param_2 == 0) {
    uVar3 = _pmap_create(0,0,~_page_mask & 0xfffffffc,1);
    uVar3 = _vm_map_create(uVar3);
    puVar2[2] = uVar3;
  }
  else {
    uVar3 = _vm_map_fork(*(undefined4 *)(param_1 + 8));
    puVar2[2] = uVar3;
  }
  puVar1 = puVar2 + 6;
  puVar2[7] = puVar1;
  *puVar1 = puVar1;
  puVar2[5] = 0;
  puVar2[1] = 1;
  puVar2[0xf] = 0;
  puVar2[8] = 0;
  puVar2[0xe] = 0;
  puVar2[0x12] = 0;
  _ipc_task_init(puVar2,param_1);
  puVar2[0x13] = 0;
  puVar2[0x14] = 0;
  puVar2[0x15] = 0;
  puVar2[0x16] = 0;
  if (param_1 == 0) {
    puVar2[0x11] = 0;
    puVar4 = _default_pset;
    _pset_reference(_default_pset);
    puVar2[0x10] = 10;
  }
  else {
    puVar2[0x11] = *(undefined4 *)(param_1 + 0x44);
    puVar4 = *(undefined **)(param_1 + 0x24);
    if (*(int *)(puVar4 + 0x148) == 0) {
      puVar4 = _default_pset;
    }
    _pset_reference(puVar4);
    puVar2[0x10] = *(undefined4 *)(param_1 + 0x40);
  }
  _pset_add_task(puVar4,puVar2);
  puVar2[10] = 1;
  puVar2[0xb] = 0;
  _ipc_task_enable(puVar2);
  *param_3 = puVar2;
  return 0;
}

