
undefined4 _do_runq_scan(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar4 = *(int *)(param_1 + 0x104);
  if (0 < iVar4) {
    puVar5 = (undefined4 *)(param_1 + *(int *)(param_1 + 0x100) * 8);
    do {
      puVar2 = (undefined4 *)*puVar5;
      iVar3 = _stuck_count;
      while (_stuck_count = iVar3, puVar2 != puVar5) {
        puVar1 = (undefined4 *)*puVar2;
        if (((puVar2[0x12] & 0xf) == 4) && (1 < (uint)(_sched_tick - puVar2[0x1b]))) {
          if (iVar3 == 0x80) {
            return 1;
          }
          puVar1[1] = puVar2[1];
          *(undefined4 *)puVar2[1] = *puVar2;
          *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + -1;
          puVar2[2] = 0;
          *(undefined4 **)(_stuck_threads + iVar3 * 4) = puVar2;
          _stuck_count = _stuck_count + 1;
          if (_do_thread_scan_debug != 0) {
            _printf(aDoRunqScanAddi,puVar2);
          }
        }
        iVar4 = iVar4 + -1;
        puVar2 = puVar1;
        iVar3 = _stuck_count;
      }
      puVar5 = puVar5 + -2;
    } while (0 < iVar4);
  }
  return 0;
}

