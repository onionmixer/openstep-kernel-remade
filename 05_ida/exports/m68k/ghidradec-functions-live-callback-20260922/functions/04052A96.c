
void _thread_deallocate(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x20);
    *(int *)(param_1 + 0x20) = iVar1 + -1;
    if (iVar1 == 1 || iVar1 + -1 < 0) {
      *(undefined4 *)(param_1 + 0x20) = 1;
      uVar2 = *(undefined4 *)(param_1 + 0x178);
      iVar1 = *(int *)(param_1 + 0xc);
      iVar3 = *(int *)(param_1 + 0x20);
      *(int *)(param_1 + 0x20) = iVar3 + -1;
      if (iVar3 == 1 || iVar3 + -1 < 0) {
        if (*(int *)(param_1 + 0x13c) != 0) {
          _reset_timeout(param_1 + 0x110);
        }
        if (*(int *)(param_1 + 0x16c) != 0) {
          _reset_timeout(param_1 + 0x140);
        }
        *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
        _thread_read_times(param_1,&iStack_c,&iStack_14);
        *(int *)(iVar1 + 0x50) = iStack_8 + *(int *)(iVar1 + 0x50);
        *(int *)(iVar1 + 0x4c) = iStack_c + *(int *)(iVar1 + 0x4c);
        if (999999 < *(int *)(iVar1 + 0x50)) {
          *(int *)(iVar1 + 0x50) = *(int *)(iVar1 + 0x50) + -1000000;
          *(int *)(iVar1 + 0x4c) = *(int *)(iVar1 + 0x4c) + 1;
        }
        *(int *)(iVar1 + 0x58) = iStack_10 + *(int *)(iVar1 + 0x58);
        *(int *)(iVar1 + 0x54) = iStack_14 + *(int *)(iVar1 + 0x54);
        if (999999 < *(int *)(iVar1 + 0x58)) {
          *(int *)(iVar1 + 0x58) = *(int *)(iVar1 + 0x58) + -1000000;
          *(int *)(iVar1 + 0x54) = *(int *)(iVar1 + 0x54) + 1;
        }
        *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + -1;
        iVar3 = *(int *)(param_1 + 0x10);
        piVar4 = *(int **)(param_1 + 0x14);
        if (iVar3 == iVar1 + 0x18) {
          *(int **)(iVar1 + 0x1c) = piVar4;
        }
        else {
          *(int **)(iVar3 + 0x14) = piVar4;
        }
        if (piVar4 == (int *)(iVar1 + 0x18)) {
          *piVar4 = iVar3;
        }
        else {
          piVar4[4] = iVar3;
        }
        _pset_remove_thread(uVar2,param_1);
        _pset_deallocate(uVar2);
        if (*(int *)(param_1 + 0x78) != 0) {
          _kmem_free(_kernel_map,*(int *)(param_1 + 0x78),_page_size);
        }
        if (*(int *)(param_1 + 0x7c) != 0) {
          _vm_object_deallocate(*(int *)(param_1 + 0x7c));
        }
        if (param_1 == _active_threads) {
                    /* WARNING: Subroutine does not return */
          _panic(aThreadDealloca);
        }
        if ((*(uint *)(param_1 + 0x48) & 0xfffffeeb) != 2) {
                    /* WARNING: Subroutine does not return */
          _panic(aUnstoppedThrea);
        }
        _task_deallocate(*(undefined4 *)(param_1 + 0xc));
        if ((*(byte *)(param_1 + 0x4a) & 1) == 0) {
          _stack_free(param_1);
          _thread_deallocate_stack = _thread_deallocate_stack + 1;
        }
        if (*(int *)(param_1 + 0x2c) != 0) {
          _freeStack(*(int *)(param_1 + 0x2c));
        }
        _pcb_terminate(param_1);
        _nthreads = _nthreads + -1;
        _uthread_free(*(undefined4 *)(param_1 + 0x80));
        _zfree(_thread_zone,param_1);
      }
    }
  }
  return;
}

