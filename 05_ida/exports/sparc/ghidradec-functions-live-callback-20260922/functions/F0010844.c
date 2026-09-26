
/* WARNING: Removing unreachable block (ram,0xf0010b40) */
/* WARNING: Removing unreachable block (ram,0xf0010af4) */
/* WARNING: Removing unreachable block (ram,0xf0010aa0) */
/* WARNING: Removing unreachable block (ram,0xf0010a34) */
/* WARNING: Removing unreachable block (ram,0xf0010a18) */
/* WARNING: Removing unreachable block (ram,0xf0010990) */
/* WARNING: Removing unreachable block (ram,0xf0010920) */
/* WARNING: Removing unreachable block (ram,0xf00108f0) */
/* WARNING: Removing unreachable block (ram,0xf0010898) */
/* WARNING: Removing unreachable block (ram,0xf0010874) */
/* WARNING: Removing unreachable block (ram,0xf001087c) */
/* WARNING: Removing unreachable block (ram,0xf00108a4) */
/* WARNING: Removing unreachable block (ram,0xf0010910) */
/* WARNING: Removing unreachable block (ram,0xf001096c) */
/* WARNING: Removing unreachable block (ram,0xf0010a0c) */
/* WARNING: Removing unreachable block (ram,0xf00109f8) */
/* WARNING: Removing unreachable block (ram,0xf0010a90) */
/* WARNING: Removing unreachable block (ram,0xf0010ad8) */
/* WARNING: Removing unreachable block (ram,0xf0010b30) */
/* WARNING: Removing unreachable block (ram,0xf0010b4c) */
/* WARNING: Removing unreachable block (ram,0xf0010858) */

undefined8 _proc_shutdown(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar6;
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
  iVar5 = *(int *)(*(int *)(_active_threads + 0xc) + 0x3c);
  iVar3 = 1;
  _pfind();
  if ((iVar3 != 0) && (iVar3 != iVar5)) {
    _task_suspend(*(undefined4 *)(iVar3 + 0x68));
  }
  iVar3 = 2;
  _pfind();
  if ((iVar3 != 0) && (iVar3 != iVar5)) {
    _task_suspend(*(undefined4 *)(iVar3 + 0x68));
  }
  _printf(aKillingAllProc);
  if (_allproc != 0) {
    sVar1 = *(sword *)(_allproc + 0x32);
    iVar3 = _allproc;
    while( true ) {
      if (sVar1 == 0) {
        iVar3 = *(int *)(iVar3 + 8);
      }
      else if ((*(uint *)(iVar3 + 0x28) & 2) == 0) {
        if (iVar3 == iVar5) {
          iVar3 = *(int *)(iVar3 + 8);
        }
        else {
          _psignal(iVar3,0xf);
          iVar3 = *(int *)(iVar3 + 8);
        }
      }
      else {
        iVar3 = *(int *)(iVar3 + 8);
      }
      if (iVar3 == 0) break;
      sVar1 = *(sword *)(iVar3 + 0x32);
    }
  }
  _ns_sleep(0,2000000000);
  _ns_sleep(0,2000000000);
  if (_allproc != 0) {
    sVar1 = *(sword *)(_allproc + 0x32);
    iVar3 = _allproc;
    while( true ) {
      if (sVar1 == 0) {
        iVar3 = *(int *)(iVar3 + 8);
      }
      else if ((*(uint *)(iVar3 + 0x28) & 2) == 0) {
        if (iVar3 == iVar5) {
          iVar3 = *(int *)(iVar3 + 8);
        }
        else {
          _psignal(iVar3,9);
          iVar3 = *(int *)(iVar3 + 8);
        }
      }
      else {
        iVar3 = *(int *)(iVar3 + 8);
      }
      if (iVar3 == 0) break;
      sVar1 = *(sword *)(iVar3 + 0x32);
    }
  }
  _ns_sleep(0,1000000000);
  if (_allproc != 0) {
    sVar1 = *(sword *)(_allproc + 0x32);
    iVar3 = _allproc;
    while( true ) {
      if (sVar1 == 0) {
        iVar3 = *(int *)(iVar3 + 8);
      }
      else if ((*(uint *)(iVar3 + 0x28) & 2) == 0) {
        if (iVar3 == iVar5) {
          iVar3 = *(int *)(iVar3 + 8);
        }
        else if (*(int *)(iVar3 + 0x78) == 0) {
          *(int *)(iVar3 + 0x78) = _active_threads;
          _printf(&DAT_f010b238);
          _do_exit(iVar3,1);
          iVar3 = _allproc;
        }
        else {
          _thread_block();
          iVar3 = _allproc;
        }
      }
      else {
        iVar3 = *(int *)(iVar3 + 8);
      }
      if (iVar3 == 0) break;
      sVar1 = *(sword *)(iVar3 + 0x32);
    }
  }
  _printf(&DAT_f010b240);
  if (_allproc != 0) {
    iVar5 = *(int *)(_allproc + 0x68);
    iVar3 = _allproc;
    do {
      iVar6 = *(int *)(iVar5 + 0x38);
      bVar2 = false;
      iVar5 = 0;
      if (*(uint *)(iVar6 + 0x154) < 0x80000000) {
        iVar4 = *(int *)(iVar6 + 0x14c);
        do {
          iVar4 = *(int *)(iVar4 + iVar5 * 4);
          if (iVar4 == 0) {
loc_F0010AAC:
            iVar4 = *(int *)(iVar6 + 0x150);
          }
          else {
            if (iVar4 != -0x10000) {
              _vno_lockrelease(iVar4);
              *(undefined4 *)(*(int *)(iVar6 + 0x14c) + iVar5 * 4) = 0;
              _closef(iVar4);
              bVar2 = true;
              goto loc_F0010AAC;
            }
            iVar4 = *(int *)(iVar6 + 0x150);
          }
          *(undefined *)(iVar4 + iVar5) = 0;
          iVar5 = iVar5 + 1;
          if (*(int *)(iVar6 + 0x154) < iVar5) break;
          iVar4 = *(int *)(iVar6 + 0x14c);
        } while( true );
      }
      if (*(int *)(iVar6 + 0x15c) == 0) {
        iVar5 = *(int *)(iVar6 + 0x160);
      }
      else {
        *(undefined4 *)(iVar6 + 0x15c) = 0;
        _vn_rele();
        bVar2 = true;
        iVar5 = *(int *)(iVar6 + 0x160);
      }
      if (iVar5 != 0) {
        *(undefined4 *)(iVar6 + 0x160) = 0;
        _vn_rele();
        bVar2 = true;
      }
      iVar6 = _allproc;
      if (!bVar2) {
        iVar6 = *(int *)(iVar3 + 8);
      }
      if (iVar6 == 0) break;
      iVar5 = *(int *)(iVar6 + 0x68);
      iVar3 = iVar6;
    } while( true );
  }
  _thread_wakeup_prim(&_reaper_queue,0,0);
  _ns_sleep(0,2000000000);
  _printf(aContinuing);
  return CONCAT44(param_2,param_1);
}

