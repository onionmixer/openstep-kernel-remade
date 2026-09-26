/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00105d58 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00105d58(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int unaff_EBP;
  int *piVar9;
  undefined4 *puVar10;
  
  if (*(short *)(*(int *)(unaff_EBP + 8) + 0x30) != 1) {
    *(undefined2 *)(*(int *)(unaff_EBP + 8) + 0x34) = *(undefined2 *)(unaff_EBP + 0xc);
    iVar7 = *(int *)(unaff_EBP + -0x14);
    piVar9 = (int *)(iVar7 + 0x170);
    iVar6 = *(int *)(unaff_EBP + -0x14);
    *(undefined4 *)(iVar6 + 0x170) = 0;
    *(undefined4 *)(iVar6 + 0x174) = 0;
    iVar1 = *(int *)(unaff_EBP + -0x14);
    *(undefined4 *)(iVar6 + 0x178) = 0;
    *(undefined4 *)(iVar6 + 0x17c) = 0;
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x18) + 0x1c;
    do {
      do {
      } while (**(int **)(unaff_EBP + -0x18) != 0);
      LOCK();
      iVar6 = **(int **)(unaff_EBP + -0x18);
      **(int **)(unaff_EBP + -0x18) = 1;
      UNLOCK();
    } while (iVar6 == 1);
    iVar6 = **(int **)(unaff_EBP + -0x1c);
    *(int *)(unaff_EBP + -0x28) = iVar1 + 0x178;
    uVar4 = _splsched();
    *(undefined4 *)(unaff_EBP + -0x20) = uVar4;
    piVar8 = *(int **)(unaff_EBP + -0x28);
    if (*(int *)(unaff_EBP + -0x1c) != iVar6) {
      do {
        *(int **)(unaff_EBP + -0x28) = piVar8;
        _thread_read_times(iVar6,unaff_EBP + -8);
        *piVar9 = *piVar9 + *(int *)(unaff_EBP + -8);
        *(int *)(iVar7 + 0x174) = *(int *)(iVar7 + 0x174) + *(int *)(unaff_EBP + -4);
        piVar8 = *(int **)(unaff_EBP + -0x28);
        *piVar8 = *piVar8 + *(int *)(unaff_EBP + -0x10);
        piVar8[1] = piVar8[1] + *(int *)(unaff_EBP + -0xc);
        iVar6 = *(int *)(iVar6 + 0x10);
      } while (*(int *)(unaff_EBP + -0x1c) != iVar6);
    }
    *(int **)(unaff_EBP + -0x28) = piVar8;
    _splx();
    *piVar9 = *piVar9 + *(int *)(*(int *)(unaff_EBP + -0x18) + 0x54);
    *(int *)(iVar7 + 0x174) = *(int *)(iVar7 + 0x174) + *(int *)(*(int *)(unaff_EBP + -0x18) + 0x58)
    ;
    piVar9 = *(int **)(unaff_EBP + -0x28);
    *piVar9 = *piVar9 + *(int *)(*(int *)(unaff_EBP + -0x18) + 0x5c);
    piVar9[1] = piVar9[1] + *(int *)(*(int *)(unaff_EBP + -0x18) + 0x60);
    LOCK();
    **(undefined4 **)(unaff_EBP + -0x18) = 0;
    UNLOCK();
    puVar5 = (undefined4 *)_kalloc();
    *(undefined4 **)(*(int *)(unaff_EBP + 8) + 0x38) = puVar5;
    puVar10 = (undefined4 *)(_active_u + 0x170);
    for (iVar7 = 0x12; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar5 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar5 = puVar5 + 1;
    }
    _ruadd(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x38),*(int *)(unaff_EBP + -0x14) + 0x1b8);
    if (*(int *)(*(int *)(unaff_EBP + 8) + 0x48) != 0) {
      _wakeup();
    }
    iVar7 = *(int *)(unaff_EBP + 8);
    uVar2 = *(uint *)(iVar7 + 0x80);
    if (uVar2 != 0) {
      *(undefined4 *)(uVar2 + 0x7c) = 0;
      *(uint *)(uVar2 + 0x28) = *(uint *)(uVar2 + 0x28) & 0xffffffef;
      _psignal(uVar2,(char *)0x9);
      *(undefined4 *)(iVar7 + 0x80) = 0;
    }
    if ((*(byte *)(*(int *)(unaff_EBP + 8) + 0x16) & 2) != 0) {
      iVar7 = *(int *)(*(int *)(*(int *)(unaff_EBP + -0x24) + 0x10) + 8);
      if (*(int *)(iVar7 + 4) == *(int *)(unaff_EBP + 8)) {
        if ((*(int *)(iVar7 + 8) != 0) && (iVar6 = _ttynty(), *(int *)(iVar6 + 8) == iVar7)) {
          if (*(int *)(iVar6 + 0xc) != 0) {
            _pgsignal(*(int *)(iVar6 + 0xc),1);
          }
          _ttywait();
        }
        *(undefined4 *)(iVar7 + 4) = 0;
      }
      iVar7 = *(int *)(unaff_EBP + 8);
      if ((*(byte *)(iVar7 + 0x16) & 2) != 0) {
        iVar6 = _get_posix_proc((int)*(short *)(iVar7 + 0x30));
        _fixjobc(iVar7,*(undefined4 *)(iVar6 + 0x10));
      }
    }
    uVar2 = *(uint *)(*(int *)(unaff_EBP + 8) + 0x48);
    while (uVar2 != 0) {
      uVar3 = *(uint *)(uVar2 + 0x4c);
      if (uVar3 != 0) {
        *(undefined4 *)(uVar3 + 0x50) = 0;
      }
      if (*(int *)(_init_proc + 0x48) != 0) {
        *(uint *)(*(int *)(_init_proc + 0x48) + 0x50) = uVar2;
      }
      iVar7 = _init_proc;
      *(undefined4 *)(uVar2 + 0x4c) = *(undefined4 *)(_init_proc + 0x48);
      *(undefined4 *)(uVar2 + 0x50) = 0;
      *(uint *)(iVar7 + 0x48) = uVar2;
      *(int *)(uVar2 + 0x44) = iVar7;
      *(undefined2 *)(uVar2 + 0x32) = 1;
      if ((*(uint *)(uVar2 + 0x28) & 0x10) == 0) {
        if ((*(int *)(uVar2 + 0x68) != 0) && (0 < *(int *)(*(int *)(uVar2 + 0x68) + 0x44))) {
          _psignal(uVar2,(char *)0x1);
          _psignal(uVar2,(char *)0x13);
        }
      }
      else {
        *(uint *)(uVar2 + 0x28) = *(uint *)(uVar2 + 0x28) & 0xffffffef;
        *(undefined4 *)(uVar2 + 0x7c) = 0;
        _psignal(uVar2,(char *)0x9);
      }
      _spgrp();
      uVar2 = uVar3;
    }
    iVar7 = *(int *)(unaff_EBP + 8);
    *(undefined4 *)(iVar7 + 0x48) = 0;
    uVar2 = *(uint *)(iVar7 + 0x7c);
    if (uVar2 != 0) {
      _psignal(uVar2,(char *)0x14);
      _wakeup(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x7c));
      *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + 8) + 0x7c) + 0x80) = 0;
    }
    if (*(int *)(_active_u + 0x248) != 0) {
      *(undefined4 *)(_active_u + 0x25c) = 0;
      _simple_lock_free();
    }
    iVar7 = *(int *)(_active_u + 0x24c);
    while (iVar7 != 0) {
      iVar6 = *(int *)(iVar7 + 4);
      _kfree(iVar7);
      iVar7 = iVar6;
    }
    _psignal(*(uint *)(*(int *)(unaff_EBP + 8) + 0x44),(char *)0x14);
    _wakeup(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x44));
    iVar7 = *(int *)(unaff_EBP + 8);
    *(undefined4 *)(iVar7 + 0x68) = 0;
    *(undefined4 *)(iVar7 + 0x6c) = 0;
    _task_terminate(*(task_t *)(unaff_EBP + -0x18));
    if (*(int *)(_active_threads + 0xc) == *(int *)(unaff_EBP + -0x18)) {
      _thread_halt_self();
    }
    return;
  }
  _printf(s_init_exited_with__d_001da84c);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}

