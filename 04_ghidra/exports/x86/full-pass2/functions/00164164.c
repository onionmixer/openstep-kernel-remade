/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00164164 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _set_pri(int *param_1,uint param_2,int param_3)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined *puVar10;
  
  iVar7 = _rem_runq(param_1);
  param_1[0x16] = param_2;
  puVar8 = (undefined4 *)0x0;
  if (iVar7 != 0) {
    if (param_3 == 0) {
      if (0x1f < param_2) {
        _printf(s_run_queue_enqueue__pri_too_high___001df684,param_2);
        param_2 = 0x1f;
      }
      piVar1 = (int *)(iVar7 + 0x100);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      iVar3 = iVar7 + param_2 * 8;
      *param_1 = iVar3;
      param_1[1] = *(int *)(iVar3 + 4);
      *(int **)param_1[1] = param_1;
      *(int **)(iVar3 + 4) = param_1;
      if ((*(uint *)(iVar7 + 0x104) < param_2) || (*(int *)(iVar7 + 0x108) == 0)) {
        *(uint *)(iVar7 + 0x104) = param_2;
      }
      *(int *)(iVar7 + 0x108) = *(int *)(iVar7 + 0x108) + 1;
      param_1[2] = iVar7;
      LOCK();
      puVar8 = *(undefined4 **)(iVar7 + 0x100);
      *(undefined4 *)(iVar7 + 0x100) = 0;
      UNLOCK();
    }
    else {
      if (param_1[0x1c] != _sched_tick) {
        _update_priority(param_1);
      }
      puVar5 = DAT_001e971c;
      if (DAT_001e9724 < 1) {
        if (param_1[0x61] == 0) {
          puVar10 = &_default_pset;
        }
        else {
          _need_ast = (undefined4 *)((uint)_need_ast | 4);
          puVar10 = _master_processor;
        }
        uVar9 = param_1[0x16];
        if (0x1f < uVar9) {
          _printf(s_run_queue_enqueue__pri_too_high___001df684,uVar9);
          uVar9 = 0x1f;
        }
        piVar1 = (int *)(puVar10 + 0x100);
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar7 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar7 == 1);
        puVar2 = puVar10 + uVar9 * 8;
        *param_1 = (int)puVar2;
        param_1[1] = *(int *)(puVar2 + 4);
        *(int **)param_1[1] = param_1;
        *(int **)(puVar2 + 4) = param_1;
        if ((*(uint *)(puVar10 + 0x104) < uVar9) || (*(int *)(puVar10 + 0x108) == 0)) {
          *(uint *)(puVar10 + 0x104) = uVar9;
        }
        *(int *)(puVar10 + 0x108) = *(int *)(puVar10 + 0x108) + 1;
        param_1[2] = (int)puVar10;
        LOCK();
        *(undefined4 *)(puVar10 + 0x100) = 0;
        UNLOCK();
        puVar8 = (undefined4 *)param_1[0x16];
        if (*(int *)(_active_threads + 0x58) < (int)puVar8) {
          *(undefined4 *)(_processor_ptr + 0x124) = 0;
          puVar8 = (undefined4 *)((uint)_need_ast | 4);
          _need_ast = puVar8;
        }
      }
      else {
        puVar4 = (undefined4 *)DAT_001e971c[0x43];
        puVar8 = (undefined4 *)DAT_001e971c[0x44];
        puVar6 = puVar8;
        if ((undefined4 **)puVar4 != &DAT_001e971c) {
          puVar4[0x44] = puVar8;
          puVar6 = _DAT_001e9720;
        }
        _DAT_001e9720 = puVar6;
        if ((undefined4 **)puVar8 != &DAT_001e971c) {
          puVar8[0x43] = puVar4;
          puVar4 = DAT_001e971c;
        }
        DAT_001e971c = puVar4;
        DAT_001e9724 = DAT_001e9724 + -1;
        puVar5[0x46] = param_1;
        puVar5[0x45] = 3;
      }
    }
  }
  return puVar8;
}

