/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001649f6 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_001649f6(void)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined *puVar14;
  int unaff_EBP;
  undefined4 *puStack0000000c;
  
  do {
    puStack0000000c = *(undefined4 **)(unaff_EBP + -0x10);
    _splx();
    puStack0000000c = (undefined4 *)0x0;
    _PMSetCpuState();
    while (((**(int **)(unaff_EBP + -8) == 0 && (DAT_001e9718 == 0)) &&
           (**(int **)(unaff_EBP + -0xc) == 0))) {
      if ((_need_ast & 0xfffffff8) != 0) {
        puStack0000000c = (undefined4 *)0x16466d;
        _splsched();
        _need_ast = _need_ast & 0xfffffff8;
        puStack0000000c = (undefined4 *)0x164684;
        _spl0();
      }
    }
    puStack0000000c = (undefined4 *)0x1;
    _PMSetCpuState();
    uVar10 = _splsched();
    *(undefined4 *)(unaff_EBP + -0x10) = uVar10;
    while( true ) {
      iVar13 = *(int *)(unaff_EBP + -4);
      iVar12 = *(int *)(iVar13 + 0x114);
      if (iVar12 == 3) break;
      if (iVar12 != 2) {
        if (1 < iVar12 - 4U) {
          puStack0000000c = (undefined4 *)0x0;
          _printf(s_Bad_processor_state__d__Cpu__d__001df6d0);
                    /* WARNING: Subroutine does not return */
          _panic(s_idle_thread_001df6f2);
        }
        puVar4 = (undefined4 *)**(undefined4 **)(unaff_EBP + -8);
        if (puVar4 != (undefined4 *)0x0) {
          **(undefined4 **)(unaff_EBP + -8) = 0;
          if (puVar4[0x1c] != _sched_tick) {
            puStack0000000c = puVar4;
            _update_priority();
          }
          puVar8 = DAT_001e971c;
          if (DAT_001e9724 < 1) {
            if (puVar4[0x61] == 0) {
              puVar14 = &_default_pset;
            }
            else {
              _need_ast = _need_ast | 4;
              puVar14 = _master_processor;
            }
            puStack0000000c = (undefined4 *)puVar4[0x16];
            *(undefined4 **)(unaff_EBP + -0x1c) = puStack0000000c;
            if (0x1f < puStack0000000c) {
              _printf(s_run_queue_enqueue__pri_too_high___001df684);
              *(undefined4 *)(unaff_EBP + -0x1c) = 0x1f;
            }
            piVar1 = (int *)(puVar14 + 0x100);
            do {
              do {
              } while (*piVar1 != 0);
              LOCK();
              iVar12 = *piVar1;
              *piVar1 = 1;
              UNLOCK();
            } while (iVar12 == 1);
            uVar7 = *(uint *)(unaff_EBP + -0x1c);
            puVar2 = puVar14 + uVar7 * 8;
            *puVar4 = puVar2;
            puVar4[1] = *(undefined4 *)(puVar2 + 4);
            *(undefined4 **)puVar4[1] = puVar4;
            *(undefined4 **)(puVar2 + 4) = puVar4;
            if ((*(uint *)(puVar14 + 0x104) < uVar7) || (*(int *)(puVar14 + 0x108) == 0)) {
              *(undefined4 *)(puVar14 + 0x104) = *(undefined4 *)(unaff_EBP + -0x1c);
            }
            *(int *)(puVar14 + 0x108) = *(int *)(puVar14 + 0x108) + 1;
            puVar4[2] = puVar14;
            LOCK();
            *(undefined4 *)(puVar14 + 0x100) = 0;
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
        uVar10 = _processor_ptr;
        puStack0000000c = (undefined4 *)0x16498d;
        uVar11 = _splsched();
        *(undefined4 *)(unaff_EBP + -0x18) = uVar11;
        _need_ast = _need_ast & 0xfffffffb;
        do {
          puStack0000000c = (undefined4 *)uVar10;
          puStack0000000c = (undefined4 *)_thread_select();
          iVar12 = _thread_invoke();
        } while (iVar12 == 0);
LAB_001649c0:
        puStack0000000c = *(undefined4 **)(unaff_EBP + -0x18);
        goto LAB_001649c4;
      }
      iVar12 = *(int *)(*(int *)(unaff_EBP + -4) + 300);
      piVar1 = (int *)(iVar12 + 0x118);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar13 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar13 == 1);
      if (*(int *)(*(int *)(unaff_EBP + -4) + 0x114) == 2) {
        __no_dispatch_count = __no_dispatch_count + 1;
        *(int *)(iVar12 + 0x114) = *(int *)(iVar12 + 0x114) + -1;
        iVar13 = *(int *)(*(int *)(unaff_EBP + -4) + 0x10c);
        iVar3 = *(int *)(*(int *)(unaff_EBP + -4) + 0x110);
        if (iVar12 + 0x10c == iVar13) {
          *(int *)(iVar12 + 0x110) = iVar3;
        }
        else {
          *(int *)(iVar13 + 0x110) = iVar3;
        }
        if (iVar12 + 0x10c == iVar3) {
          *(int *)(iVar12 + 0x10c) = iVar13;
        }
        else {
          *(int *)(iVar3 + 0x10c) = iVar13;
        }
        *(undefined4 *)(*(int *)(unaff_EBP + -4) + 0x114) = 1;
        LOCK();
        *(undefined4 *)(iVar12 + 0x118) = 0;
        uVar10 = _processor_ptr;
        UNLOCK();
        puStack0000000c = (undefined4 *)0x164808;
        uVar11 = _splsched();
        *(undefined4 *)(unaff_EBP + -0x18) = uVar11;
        _need_ast = _need_ast & 0xfffffffb;
        do {
          puStack0000000c = (undefined4 *)uVar10;
          puStack0000000c = (undefined4 *)_thread_select();
          iVar12 = _thread_invoke();
        } while (iVar12 == 0);
        goto LAB_001649c0;
      }
      LOCK();
      *(undefined4 *)(iVar12 + 0x118) = 0;
      UNLOCK();
    }
    iVar12 = **(int **)(unaff_EBP + -8);
    **(int **)(unaff_EBP + -8) = 0;
    *(undefined4 *)(iVar13 + 0x114) = 1;
    uVar10 = DAT_001e977c;
    if (*(int *)(iVar12 + 0x60) == 2) {
      iVar13 = *(int *)(unaff_EBP + -4);
      uVar10 = *(undefined4 *)(iVar12 + 0x5c);
    }
    *(undefined4 *)(iVar13 + 0x120) = uVar10;
    *(undefined4 *)(*(int *)(unaff_EBP + -4) + 0x124) = 1;
    *(undefined4 *)(unaff_EBP + -0x18) = _active_threads;
    uVar10 = _processor_ptr;
    puStack0000000c = (undefined4 *)0x164717;
    uVar11 = _splsched();
    *(undefined4 *)(unaff_EBP + -0x14) = uVar11;
    while (puStack0000000c = (undefined4 *)iVar12, iVar12 = _thread_invoke(), iVar12 == 0) {
      puStack0000000c = (undefined4 *)uVar10;
      iVar12 = _thread_select();
    }
    puStack0000000c = *(undefined4 **)(unaff_EBP + -0x14);
LAB_001649c4:
    _splx();
  } while( true );
}

