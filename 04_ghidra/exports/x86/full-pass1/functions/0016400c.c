/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016400c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _thread_setrun(undefined4 *param_1,int param_2)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined *puVar9;
  
  if (param_1[0x1c] != _sched_tick) {
    _update_priority(param_1);
  }
  puVar5 = DAT_001e971c;
  if (DAT_001e9724 < 1) {
    if (param_1[0x61] == 0) {
      puVar9 = &_default_pset;
    }
    else {
      _need_ast = (undefined4 *)((uint)_need_ast | 4);
      puVar9 = _master_processor;
    }
    uVar8 = param_1[0x16];
    if (0x1f < uVar8) {
      _printf(s_run_queue_enqueue__pri_too_high___001df684,uVar8);
      uVar8 = 0x1f;
    }
    piVar1 = (int *)(puVar9 + 0x100);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    puVar2 = puVar9 + uVar8 * 8;
    *param_1 = puVar2;
    param_1[1] = *(undefined4 *)(puVar2 + 4);
    *(undefined4 **)param_1[1] = param_1;
    *(undefined4 **)(puVar2 + 4) = param_1;
    if ((*(uint *)(puVar9 + 0x104) < uVar8) || (*(int *)(puVar9 + 0x108) == 0)) {
      *(uint *)(puVar9 + 0x104) = uVar8;
    }
    *(int *)(puVar9 + 0x108) = *(int *)(puVar9 + 0x108) + 1;
    param_1[2] = puVar9;
    LOCK();
    puVar7 = *(undefined4 **)(puVar9 + 0x100);
    *(undefined4 *)(puVar9 + 0x100) = 0;
    UNLOCK();
    if ((param_2 != 0) &&
       (puVar7 = (undefined4 *)param_1[0x16], *(int *)(_active_threads + 0x58) < (int)puVar7)) {
      *(undefined4 *)(_processor_ptr + 0x124) = 0;
      puVar7 = (undefined4 *)((uint)_need_ast | 4);
      _need_ast = puVar7;
    }
  }
  else {
    puVar4 = (undefined4 *)DAT_001e971c[0x43];
    puVar7 = (undefined4 *)DAT_001e971c[0x44];
    puVar6 = puVar7;
    if ((undefined4 **)puVar4 != &DAT_001e971c) {
      puVar4[0x44] = puVar7;
      puVar6 = _DAT_001e9720;
    }
    _DAT_001e9720 = puVar6;
    if ((undefined4 **)puVar7 != &DAT_001e971c) {
      puVar7[0x43] = puVar4;
      puVar4 = DAT_001e971c;
    }
    DAT_001e971c = puVar4;
    DAT_001e9724 = DAT_001e9724 + -1;
    puVar5[0x46] = param_1;
    puVar5[0x45] = 3;
  }
  return puVar7;
}

