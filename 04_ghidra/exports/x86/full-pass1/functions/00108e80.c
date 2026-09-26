/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00108e80 */

void _proc_shutdown(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  
  uVar1 = *(uint *)(*(int *)(_active_threads + 0xc) + 0x3c);
  uVar5 = _pfind(1);
  if ((uVar5 != 0) && (uVar5 != uVar1)) {
    _task_suspend(*(task_t *)(uVar5 + 0x68));
  }
  uVar5 = _pfind(2);
  if ((uVar5 != 0) && (uVar5 != uVar1)) {
    _task_suspend(*(task_t *)(uVar5 + 0x68));
  }
  _printf(s_Killing_all_processes_001da9ce);
  for (uVar5 = _allproc; uVar5 != 0; uVar5 = *(uint *)(uVar5 + 8)) {
    if (((*(short *)(uVar5 + 0x32) != 0) && ((*(byte *)(uVar5 + 0x28) & 2) == 0)) &&
       (uVar5 != uVar1)) {
      _psignal(uVar5,(char *)0xf);
    }
  }
  _ns_sleep(2000000000,0);
  _ns_sleep(2000000000,0);
  for (uVar5 = _allproc; uVar5 != 0; uVar5 = *(uint *)(uVar5 + 8)) {
    if (((*(short *)(uVar5 + 0x32) != 0) && ((*(byte *)(uVar5 + 0x28) & 2) == 0)) &&
       (uVar5 != uVar1)) {
      _psignal(uVar5,(char *)0x9);
    }
  }
  _ns_sleep(1000000000,0);
  uVar5 = _allproc;
  while (uVar5 != 0) {
    if (((*(short *)(uVar5 + 0x32) == 0) || ((*(byte *)(uVar5 + 0x28) & 2) != 0)) ||
       (uVar5 == uVar1)) {
      uVar5 = *(uint *)(uVar5 + 8);
    }
    else if (*(int *)(uVar5 + 0x78) == 0) {
      *(int *)(uVar5 + 0x78) = _active_threads;
      _printf(&DAT_001da9e5);
      _do_exit(uVar5,1);
      uVar5 = _allproc;
    }
    else {
      _thread_block();
      uVar5 = _allproc;
    }
  }
  _printf(&DAT_001da9e7);
  uVar1 = _allproc;
  while (uVar5 = uVar1, uVar5 != 0) {
    iVar2 = *(int *)(*(int *)(uVar5 + 0x68) + 0x38);
    bVar4 = false;
    iVar6 = 0;
    if (-1 < *(int *)(iVar2 + 0x158)) {
      do {
        iVar3 = *(int *)(*(int *)(iVar2 + 0x150) + iVar6 * 4);
        if ((iVar3 != 0) && (iVar3 != -0x10000)) {
          _vno_lockrelease(iVar3);
          *(undefined4 *)(*(int *)(iVar2 + 0x150) + iVar6 * 4) = 0;
          _closef(iVar3);
          bVar4 = true;
        }
        *(undefined1 *)(iVar6 + *(int *)(iVar2 + 0x154)) = 0;
        iVar6 = iVar6 + 1;
      } while (iVar6 <= *(int *)(iVar2 + 0x158));
    }
    iVar6 = *(int *)(iVar2 + 0x160);
    if (iVar6 != 0) {
      *(undefined4 *)(iVar2 + 0x160) = 0;
      _vn_rele(iVar6);
      bVar4 = true;
    }
    iVar6 = *(int *)(iVar2 + 0x164);
    if (iVar6 != 0) {
      *(undefined4 *)(iVar2 + 0x164) = 0;
      _vn_rele(iVar6);
      bVar4 = true;
    }
    uVar1 = _allproc;
    if (!bVar4) {
      uVar1 = *(uint *)(uVar5 + 8);
    }
  }
  _thread_wakeup_prim(&_reaper_queue,0,0);
  _ns_sleep(2000000000,0);
  _printf(s_continuing_001da9e9);
  return;
}

