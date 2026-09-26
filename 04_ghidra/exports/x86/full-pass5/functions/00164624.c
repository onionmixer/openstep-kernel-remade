/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00164624 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _idle_thread_continue(void)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int *piVar15;
  undefined *puVar16;
  int *piVar17;
  undefined4 uVar18;
  uint local_20;
  
  iVar7 = _processor_ptr;
  piVar15 = (int *)(_processor_ptr + 0x118);
  piVar17 = (int *)(_processor_ptr + 0x108);
  do {
    _PMSetCpuState(0);
    while (((*piVar15 == 0 && (DAT_001e9718 == 0)) && (*piVar17 == 0))) {
      if ((_need_ast & 0xfffffff8) != 0) {
        _splsched();
        _need_ast = _need_ast & 0xfffffff8;
        _spl0();
      }
    }
    _PMSetCpuState(1);
    uVar10 = _splsched();
    while (iVar12 = *(int *)(iVar7 + 0x114), iVar12 != 3) {
      if (iVar12 != 2) {
        if (1 < iVar12 - 4U) {
          _printf(s_Bad_processor_state__d__Cpu__d__001df6d0,*(undefined4 *)(_processor_ptr + 0x114)
                  ,0);
                    /* WARNING: Subroutine does not return */
          _panic(s_idle_thread_001df6f2);
        }
        puVar4 = (undefined4 *)*piVar15;
        if (puVar4 != (undefined4 *)0x0) {
          *piVar15 = 0;
          if (puVar4[0x1c] != _sched_tick) {
            _update_priority(puVar4);
          }
          puVar8 = DAT_001e971c;
          if (DAT_001e9724 < 1) {
            if (puVar4[0x61] == 0) {
              puVar16 = &_default_pset;
            }
            else {
              _need_ast = _need_ast | 4;
              puVar16 = _master_processor;
            }
            local_20 = puVar4[0x16];
            if (0x1f < local_20) {
              _printf(s_run_queue_enqueue__pri_too_high___001df684,local_20);
              local_20 = 0x1f;
            }
            piVar1 = (int *)(puVar16 + 0x100);
            do {
              do {
              } while (*piVar1 != 0);
              LOCK();
              iVar12 = *piVar1;
              *piVar1 = 1;
              UNLOCK();
            } while (iVar12 == 1);
            puVar2 = puVar16 + local_20 * 8;
            *puVar4 = puVar2;
            puVar4[1] = *(undefined4 *)(puVar2 + 4);
            *(undefined4 **)puVar4[1] = puVar4;
            *(undefined4 **)(puVar2 + 4) = puVar4;
            if ((*(uint *)(puVar16 + 0x104) < local_20) || (*(int *)(puVar16 + 0x108) == 0)) {
              *(uint *)(puVar16 + 0x104) = local_20;
            }
            *(int *)(puVar16 + 0x108) = *(int *)(puVar16 + 0x108) + 1;
            puVar4[2] = puVar16;
            LOCK();
            *(undefined4 *)(puVar16 + 0x100) = 0;
            UNLOCK();
          }
          else {
            puVar5 = (undefined4 *)DAT_001e971c[0x43];
            puVar6 = (undefined4 *)DAT_001e971c[0x44];
            puVar9 = puVar6;
            if ((undefined4 **)puVar5 != &DAT_001e971c) {
              puVar5[0x44] = puVar6;
              puVar9 = _DAT_001e9720;
            }
            _DAT_001e9720 = puVar9;
            if ((undefined4 **)puVar6 != &DAT_001e971c) {
              puVar6[0x43] = puVar5;
              puVar5 = DAT_001e971c;
            }
            DAT_001e971c = puVar5;
            DAT_001e9724 = DAT_001e9724 + -1;
            puVar8[0x46] = puVar4;
            puVar8[0x45] = 3;
          }
        }
        iVar12 = _processor_ptr;
        uVar18 = _active_threads;
        uVar11 = _splsched();
        _need_ast = _need_ast & 0xfffffffb;
        do {
          uVar13 = _thread_select(iVar12);
          iVar14 = _thread_invoke(uVar18,_idle_thread_continue,uVar13);
        } while (iVar14 == 0);
        goto LAB_001649c4;
      }
      iVar12 = *(int *)(iVar7 + 300);
      piVar1 = (int *)(iVar12 + 0x118);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar14 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar14 == 1);
      if (*(int *)(iVar7 + 0x114) == 2) {
        __no_dispatch_count = __no_dispatch_count + 1;
        *(int *)(iVar12 + 0x114) = *(int *)(iVar12 + 0x114) + -1;
        iVar14 = *(int *)(iVar7 + 0x10c);
        iVar3 = *(int *)(iVar7 + 0x110);
        if (iVar12 + 0x10c == iVar14) {
          *(int *)(iVar12 + 0x110) = iVar3;
        }
        else {
          *(int *)(iVar14 + 0x110) = iVar3;
        }
        if (iVar12 + 0x10c == iVar3) {
          *(int *)(iVar12 + 0x10c) = iVar14;
        }
        else {
          *(int *)(iVar3 + 0x10c) = iVar14;
        }
        *(undefined4 *)(iVar7 + 0x114) = 1;
        LOCK();
        *(undefined4 *)(iVar12 + 0x118) = 0;
        iVar12 = _processor_ptr;
        uVar18 = _active_threads;
        UNLOCK();
        uVar11 = _splsched();
        _need_ast = _need_ast & 0xfffffffb;
        do {
          uVar13 = _thread_select(iVar12);
          iVar14 = _thread_invoke(uVar18,_idle_thread_continue,uVar13);
        } while (iVar14 == 0);
        goto LAB_001649c4;
      }
      LOCK();
      *(undefined4 *)(iVar12 + 0x118) = 0;
      UNLOCK();
    }
    iVar12 = *piVar15;
    *piVar15 = 0;
    *(undefined4 *)(iVar7 + 0x114) = 1;
    uVar18 = DAT_001e977c;
    if (*(int *)(iVar12 + 0x60) == 2) {
      uVar18 = *(undefined4 *)(iVar12 + 0x5c);
    }
    *(undefined4 *)(iVar7 + 0x120) = uVar18;
    *(undefined4 *)(iVar7 + 0x124) = 1;
    iVar14 = _processor_ptr;
    uVar18 = _active_threads;
    uVar11 = _splsched();
    while (iVar12 = _thread_invoke(uVar18,_idle_thread_continue,iVar12), iVar12 == 0) {
      iVar12 = _thread_select(iVar14);
    }
LAB_001649c4:
    _splx(uVar11);
    _splx(uVar10);
  } while( true );
}

