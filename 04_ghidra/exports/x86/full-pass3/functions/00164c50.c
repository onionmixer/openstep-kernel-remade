/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00164c50 */

undefined4 _do_runq_scan(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  
  uVar4 = _splsched();
  piVar5 = (int *)(param_1 + 0x100);
  do {
    do {
    } while (*piVar5 != 0);
    LOCK();
    iVar7 = *piVar5;
    *piVar5 = 1;
    UNLOCK();
  } while (iVar7 == 1);
  iVar7 = *(int *)(param_1 + 0x108);
  if (0 < iVar7) {
    puVar6 = (undefined4 *)(param_1 + *(int *)(param_1 + 0x104) * 8);
    do {
      puVar2 = (undefined4 *)*puVar6;
      iVar3 = _stuck_count;
      while (_stuck_count = iVar3, puVar6 != puVar2) {
        puVar1 = (undefined4 *)*puVar2;
        if (((puVar2[0x13] & 0xf) == 4) && (1 < (uint)(_sched_tick - puVar2[0x1c]))) {
          if (iVar3 == 0x80) {
            LOCK();
            *(undefined4 *)(param_1 + 0x100) = 0;
            UNLOCK();
            _splx(uVar4);
            return 1;
          }
          puVar1[1] = puVar2[1];
          *(undefined4 *)puVar2[1] = *puVar2;
          *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + -1;
          puVar2[2] = 0;
          *(undefined4 **)(&_stuck_threads + iVar3 * 4) = puVar2;
          _stuck_count = _stuck_count + 1;
          if (_do_thread_scan_debug != 0) {
            _printf(s_do_runq_scan__adding_thread___x_001df708,puVar2);
          }
        }
        iVar7 = iVar7 + -1;
        puVar2 = puVar1;
        iVar3 = _stuck_count;
      }
      puVar6 = puVar6 + -2;
    } while (0 < iVar7);
  }
  LOCK();
  *(undefined4 *)(param_1 + 0x100) = 0;
  UNLOCK();
  _splx(uVar4);
  return 0;
}

