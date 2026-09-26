
void _thread_setrun(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  
  if (*(int *)(param_1 + 0x6c) != _sched_tick) {
    _update_priority(param_1);
  }
  puVar6 = _master_processor;
  puVar4 = unk_40B6750;
  if (dword_40B6758 < 1) {
    if (*(int *)(param_1 + 0x17c) == 0) {
      puVar6 = _default_pset;
    }
    else {
      _need_ast = _need_ast | 4;
      if (_need_ast != 0) {
        pbVar3 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
        *pbVar3 = *pbVar3 | 0x10;
      }
    }
    _run_queue_enqueue(puVar6,param_1);
    if ((param_2 != 0) && (*(int *)(_active_threads + 0x54) < *(int *)(param_1 + 0x54))) {
      *(undefined4 *)(_processor_ptr + 0x120) = 0;
      _need_ast = _need_ast | 4;
      if (_need_ast != 0) {
        pbVar3 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
        *pbVar3 = *pbVar3 | 0x10;
      }
    }
  }
  else {
    puVar1 = (undefined4 *)unk_40B6750[0x42];
    puVar2 = (undefined4 *)unk_40B6750[0x43];
    puVar5 = puVar2;
    if ((undefined4 **)puVar1 != &unk_40B6750) {
      puVar1[0x43] = puVar2;
      puVar5 = dword_40B6754;
    }
    dword_40B6754 = puVar5;
    if ((undefined4 **)puVar2 != &unk_40B6750) {
      puVar2[0x42] = puVar1;
      puVar1 = unk_40B6750;
    }
    unk_40B6750 = puVar1;
    dword_40B6758 = dword_40B6758 + -1;
    puVar4[0x45] = param_1;
    puVar4[0x44] = 3;
  }
  return;
}
