
undefined4 _thread_create(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  
  if (param_1 == (int *)0x0) {
    uVar2 = 4;
  }
  else {
    iVar3 = _zalloc(_thread_zone);
    if (iVar3 == 0) {
      uVar2 = 6;
    }
    else {
      _bcopy(&_thread_template,iVar3,0x184);
      *(int **)(iVar3 + 0xc) = param_1;
      *(undefined4 *)(iVar3 + 0x6c) = _sched_tick;
      _thread_timeout_setup(iVar3);
      _pcb_init(iVar3);
      _ipc_thread_init(iVar3);
      uVar2 = _zalloc(_u_thread_zone);
      *(undefined4 *)(iVar3 + 0x80) = uVar2;
      _uarea_zero(iVar3);
      _uarea_init(iVar3);
      puVar5 = (undefined *)param_1[9];
      _pset_reference(puVar5);
      while( true ) {
        puVar4 = (undefined *)param_1[9];
        if (*(int *)(puVar4 + 0x148) == 0) {
          puVar4 = _default_pset;
        }
        if (puVar5 == puVar4) break;
        _pset_reference(puVar4);
        _pset_deallocate(puVar5);
        puVar5 = puVar4;
      }
      *(int *)(iVar3 + 0x4c) = param_1[0x10];
      if (*(int *)(puVar5 + 0x154) < *(int *)(iVar3 + 0x50)) {
        *(int *)(iVar3 + 0x50) = *(int *)(puVar5 + 0x154);
      }
      if (*(int *)(iVar3 + 0x50) < *(int *)(iVar3 + 0x4c)) {
        *(int *)(iVar3 + 0x4c) = *(int *)(iVar3 + 0x50);
      }
      _compute_priority(iVar3,1);
      *(int *)(iVar3 + 0x3c) = param_1[5] + 1;
      _pset_add_thread(puVar5,iVar3);
      if (*(int *)(puVar5 + 0x120) != 0) {
        *(int *)(iVar3 + 0x3c) = *(int *)(iVar3 + 0x3c) + 1;
      }
      *param_1 = *param_1 + 1;
      param_1[8] = param_1[8] + 1;
      piVar1 = (int *)param_1[7];
      if (piVar1 == param_1 + 6) {
        *piVar1 = iVar3;
      }
      else {
        piVar1[4] = iVar3;
      }
      *(int **)(iVar3 + 0x14) = piVar1;
      *(int **)(iVar3 + 0x10) = param_1 + 6;
      param_1[7] = iVar3;
      *(undefined4 *)(iVar3 + 0x170) = 1;
      if (param_1[1] == 0) {
        _thread_terminate(iVar3);
        _thread_deallocate(iVar3);
        uVar2 = 5;
      }
      else {
        _ipc_thread_enable(iVar3);
        _nthreads = _nthreads + 1;
        *param_2 = iVar3;
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}
