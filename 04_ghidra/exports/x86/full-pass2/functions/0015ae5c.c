/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015ae5c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * _allocStack(void)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int local_8;
  
  bVar1 = false;
  iVar5 = 0;
  do {
    _lock_write(&_stack_queue_lock);
    if (DAT_001ded68 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      if ((int **)DAT_001e5b98 == &DAT_001e5b98) {
        piVar3 = (int *)0x0;
      }
      else {
        *(int ***)(*DAT_001e5b98 + 4) = &DAT_001e5b98;
        piVar3 = DAT_001e5b98;
        DAT_001e5b98 = (int *)*DAT_001e5b98;
      }
      piVar3[2] = 2;
      piVar3 = piVar3 + 3;
      DAT_001ded68 = DAT_001ded68 + -1;
      _DAT_001f63b8 = _DAT_001f63b8 + -1;
      _DAT_001f63b4 = _DAT_001f63b4 + 1;
    }
    _lock_done(&_stack_queue_lock);
    if (piVar3 == (int *)0x0) {
      iVar2 = _kmem_alloc_wired(_kernel_map,&local_8,DAT_001e5ba0);
      if (iVar2 == 0) {
        __stackStats = __stackStats + 1;
        *(undefined4 *)(local_8 + 8) = 2;
        _DAT_001f63b4 = _DAT_001f63b4 + 1;
        _stack_init(local_8 + 0xc);
        if (1 < DAT_001e5ba4) {
          _lock_write(&_stack_queue_lock);
          iVar2 = 1;
          piVar3 = (int *)(local_8 + DAT_001e5ba0);
          if (1 < DAT_001e5ba4) {
            do {
              piVar4 = piVar3;
              _stack_init(piVar4 + 3);
              piVar4[2] = 0;
              piVar3 = piVar4;
              if ((int **)DAT_001e5b9c != &DAT_001e5b98) {
                *DAT_001e5b9c = (int)piVar4;
                piVar3 = DAT_001e5b98;
              }
              DAT_001e5b98 = piVar3;
              piVar4[1] = (int)DAT_001e5b9c;
              *piVar4 = (int)&DAT_001e5b98;
              DAT_001ded68 = DAT_001ded68 + 1;
              _DAT_001f63b8 = _DAT_001f63b8 + 1;
              iVar2 = iVar2 + 1;
              piVar3 = (int *)((int)piVar4 + DAT_001e5ba0);
              DAT_001e5b9c = piVar4;
            } while (iVar2 < DAT_001e5ba4);
          }
          _lock_done(&_stack_queue_lock);
        }
        piVar3 = (int *)(local_8 + 0xc);
        if (piVar3 != (int *)0x0) goto LAB_0015b06c;
      }
      if (bVar1) {
        if (iVar5 != 0) {
          return (int *)0x0;
        }
      }
      else {
        bVar1 = true;
        _uprintf(s_MACH__Out_of_kernel_stacks__paus_001ded74);
        if (DAT_001ded70 == 0) {
          _printf(s_stack_alloc__Kernel_stacks_exhau_001ded9b);
        }
      }
      _lock_write(&_stack_queue_lock);
      if (DAT_001ded68 == 0) {
        _assert_wait(&DAT_001e5b98,0);
        DAT_001ded70 = 1;
        _lock_done(&_stack_queue_lock);
        _thread_block();
        iVar5 = *(int *)(_active_threads + 0x44);
      }
      else {
        _lock_done(&_stack_queue_lock);
        iVar5 = 0;
      }
    }
    else {
LAB_0015b06c:
      if (bVar1) {
        _uprintf(s_continuing_001dedc1);
      }
    }
    if (piVar3 != (int *)0x0) {
      return piVar3;
    }
  } while( true );
}

