
void _proc_shutdown(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *(int *)(*(int *)(_active_threads + 0xc) + 0x34);
  iVar4 = _pfind(1);
  if ((iVar4 != 0) && (iVar1 != iVar4)) {
    _task_suspend(*(undefined4 *)(iVar4 + 0x66));
  }
  iVar4 = _pfind(2);
  if ((iVar4 != 0) && (iVar1 != iVar4)) {
    _task_suspend(*(undefined4 *)(iVar4 + 0x66));
  }
  _printf(aKillingAllProc);
  for (iVar4 = _allproc; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    if (((*(sword *)(iVar4 + 0x32) != 0) && ((*(byte *)(iVar4 + 0x2b) & 2) == 0)) &&
       (iVar1 != iVar4)) {
      _psignal(iVar4,0xf);
    }
  }
  _ns_sleep(0,2000000000);
  _ns_sleep(0,2000000000);
  for (iVar4 = _allproc; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    if (((*(sword *)(iVar4 + 0x32) != 0) && ((*(byte *)(iVar4 + 0x2b) & 2) == 0)) &&
       (iVar1 != iVar4)) {
      _psignal(iVar4,9);
    }
  }
  _ns_sleep(0,1000000000);
  iVar4 = _allproc;
  while (iVar4 != 0) {
    if (((*(sword *)(iVar4 + 0x32) == 0) || ((*(byte *)(iVar4 + 0x2b) & 2) != 0)) ||
       (iVar1 == iVar4)) {
      iVar4 = *(int *)(iVar4 + 8);
    }
    else if (*(int *)(iVar4 + 0x76) == 0) {
      *(int *)(iVar4 + 0x76) = _active_threads;
      _printf(&asc_40A6047);
      _do_exit(iVar4,1);
      iVar4 = _allproc;
    }
    else {
      _thread_block();
      iVar4 = _allproc;
    }
  }
  _printf(&asc_40A6049);
  iVar1 = _allproc;
  while (iVar4 = iVar1, iVar4 != 0) {
    iVar1 = *(int *)(*(int *)(iVar4 + 0x66) + 0x30);
    bVar3 = false;
    iVar5 = 0;
    if (*(uint *)(iVar1 + 0x14e) < 0x80000000) {
      do {
        iVar2 = *(int *)(*(int *)(iVar1 + 0x146) + iVar5 * 4);
        if ((iVar2 != 0) && (iVar2 != -0x10000)) {
          _vno_lockrelease(iVar2);
          *(undefined4 *)(*(int *)(iVar1 + 0x146) + iVar5 * 4) = 0;
          _closef(iVar2);
          bVar3 = true;
        }
        *(undefined *)(iVar5 + *(int *)(iVar1 + 0x14a)) = 0;
        iVar5 = iVar5 + 1;
      } while (iVar5 <= *(int *)(iVar1 + 0x14e));
    }
    iVar5 = *(int *)(iVar1 + 0x156);
    if (iVar5 != 0) {
      *(int *)(iVar1 + 0x156) = 0;
      _vn_rele(iVar5);
      bVar3 = true;
    }
    iVar5 = *(int *)(iVar1 + 0x15a);
    if (iVar5 != 0) {
      *(int *)(iVar1 + 0x15a) = 0;
      _vn_rele(iVar5);
      bVar3 = true;
    }
    iVar1 = _allproc;
    if (!bVar3) {
      iVar1 = *(int *)(iVar4 + 8);
    }
  }
  _thread_wakeup_prim(&_reaper_queue,0,0);
  _ns_sleep(0,2000000000);
  _printf(aContinuing);
  return;
}

