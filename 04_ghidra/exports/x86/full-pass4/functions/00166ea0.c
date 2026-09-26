/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00166ea0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __regparm1 _thread_deallocate(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (param_2 != 0) {
    uVar5 = _splsched();
    piVar6 = (int *)(param_2 + 0x20);
    do {
      do {
      } while (*piVar6 != 0);
      LOCK();
      iVar2 = *piVar6;
      *piVar6 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    iVar2 = *(int *)(param_2 + 0x24);
    *(int *)(param_2 + 0x24) = iVar2 + -1;
    if (iVar2 == 1 || iVar2 + -1 < 0) {
      *(undefined4 *)(param_2 + 0x24) = 1;
      LOCK();
      *(undefined4 *)(param_2 + 0x20) = 0;
      UNLOCK();
      _splx(uVar5);
      iVar2 = *(int *)(param_2 + 0x180);
      piVar6 = (int *)(iVar2 + 0x158);
      do {
        do {
        } while (*piVar6 != 0);
        LOCK();
        iVar3 = *piVar6;
        *piVar6 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      piVar6 = *(int **)(param_2 + 0xc);
      do {
        do {
        } while (*piVar6 != 0);
        LOCK();
        iVar3 = *piVar6;
        *piVar6 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      uVar5 = _splsched();
      piVar1 = piVar6 + 10;
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      piVar1 = (int *)(param_2 + 0x20);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      iVar3 = *(int *)(param_2 + 0x24);
      *(int *)(param_2 + 0x24) = iVar3 + -1;
      if (iVar3 == 1 || iVar3 + -1 < 0) {
        if (*(int *)(param_2 + 0x144) != 0) {
          _reset_timeout(param_2 + 0x118);
        }
        if (*(int *)(param_2 + 0x174) != 0) {
          _reset_timeout(param_2 + 0x148);
        }
        *(undefined4 *)(param_2 + 100) = 0xffffffff;
        _thread_read_times(param_2,&local_c,&local_14);
        piVar6[0x16] = piVar6[0x16] + local_8;
        piVar6[0x15] = piVar6[0x15] + local_c;
        if (999999 < piVar6[0x16]) {
          piVar6[0x16] = piVar6[0x16] + -1000000;
          piVar6[0x15] = piVar6[0x15] + 1;
        }
        piVar6[0x18] = piVar6[0x18] + local_10;
        piVar6[0x17] = piVar6[0x17] + local_14;
        if (999999 < piVar6[0x18]) {
          piVar6[0x18] = piVar6[0x18] + -1000000;
          piVar6[0x17] = piVar6[0x17] + 1;
        }
        piVar6[9] = piVar6[9] + -1;
        piVar1 = *(int **)(param_2 + 0x10);
        piVar4 = *(int **)(param_2 + 0x14);
        if (piVar6 + 7 == piVar1) {
          piVar6[8] = (int)piVar4;
        }
        else {
          piVar1[5] = (int)piVar4;
        }
        if (piVar6 + 7 == piVar4) {
          piVar6[7] = (int)piVar1;
        }
        else {
          piVar4[4] = (int)piVar1;
        }
        _pset_remove_thread(iVar2,param_2);
        LOCK();
        *(undefined4 *)(param_2 + 0x20) = 0;
        UNLOCK();
        LOCK();
        piVar6[10] = 0;
        UNLOCK();
        _splx(uVar5);
        LOCK();
        *piVar6 = 0;
        UNLOCK();
        LOCK();
        *(undefined4 *)(iVar2 + 0x158) = 0;
        UNLOCK();
        _pset_deallocate(iVar2);
        if (*(int *)(param_2 + 0x7c) != 0) {
          _kmem_free(_kernel_map,*(int *)(param_2 + 0x7c),_page_size);
        }
        if (*(int *)(param_2 + 0x80) != 0) {
          _vm_object_deallocate(*(int *)(param_2 + 0x80));
        }
        if (_active_threads == param_2) {
                    /* WARNING: Subroutine does not return */
          _panic(s_thread_deallocating_itself_001dfbe8);
        }
        if ((*(uint *)(param_2 + 0x4c) & 0xfffffeeb) != 2) {
                    /* WARNING: Subroutine does not return */
          _panic(s_unstopped_thread_destroyed__001dfc03);
        }
        _task_deallocate(*(undefined4 *)(param_2 + 0xc));
        if ((*(byte *)(param_2 + 0x4d) & 1) == 0) {
          _splsched();
          _stack_free(param_2);
          _splx(uVar5);
          __thread_deallocate_stack = __thread_deallocate_stack + 1;
        }
        if (*(int *)(param_2 + 0x30) != 0) {
          _freeStack(*(int *)(param_2 + 0x30));
        }
        _pcb_terminate(param_2);
        __nthreads = __nthreads + -1;
        _uthread_free(*(undefined4 *)(param_2 + 0x84));
        param_1 = _zfree(_thread_zone,param_2);
      }
      else {
        LOCK();
        *(undefined4 *)(param_2 + 0x20) = 0;
        UNLOCK();
        LOCK();
        piVar6[10] = 0;
        UNLOCK();
        _splx(uVar5);
        LOCK();
        *piVar6 = 0;
        UNLOCK();
        LOCK();
        param_1 = *(undefined4 *)(iVar2 + 0x158);
        *(undefined4 *)(iVar2 + 0x158) = 0;
        UNLOCK();
      }
    }
    else {
      LOCK();
      *(undefined4 *)(param_2 + 0x20) = 0;
      UNLOCK();
      param_1 = _splx(uVar5);
    }
  }
  return param_1;
}

