/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00164d80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _do_thread_scan(void)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  bool bVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  undefined1 *puVar12;
  uint local_1c;
  int local_18;
  int local_14;
  undefined1 *puVar13;
  
  puVar12 = &stack0xffffffd8;
  do {
    *(undefined4 *)(puVar12 + -4) = 0x164d91;
    uVar9 = _splsched();
    do {
    } while (DAT_001e9710 != 0);
    LOCK();
    DAT_001e9710 = 1;
    UNLOCK();
    local_18 = DAT_001e9718;
    if (0 < DAT_001e9718) {
      puVar10 = (undefined4 *)(&_default_pset + DAT_001e9714 * 8);
      do {
        puVar6 = (undefined4 *)*puVar10;
        iVar3 = _stuck_count;
        while (_stuck_count = iVar3, puVar10 != puVar6) {
          puVar4 = (undefined4 *)*puVar6;
          if (((puVar6[0x13] & 0xf) == 4) && (1 < (uint)(_sched_tick - puVar6[0x1c]))) {
            if (iVar3 == 0x80) {
              LOCK();
              DAT_001e9710 = 0;
              UNLOCK();
              *(undefined4 *)(puVar12 + -4) = uVar9;
              *(undefined4 *)(puVar12 + -8) = 0x164e1c;
              _splx();
              bVar7 = true;
              goto LAB_00164e9b;
            }
            puVar4[1] = puVar6[1];
            *(undefined4 *)puVar6[1] = *puVar6;
            DAT_001e9718 = DAT_001e9718 + -1;
            puVar6[2] = 0;
            *(undefined4 **)(&_stuck_threads + iVar3 * 4) = puVar6;
            _stuck_count = _stuck_count + 1;
            if (_do_thread_scan_debug != 0) {
              *(undefined4 **)(puVar12 + -4) = puVar6;
              *(char **)(puVar12 + -8) = s_do_runq_scan__adding_thread___x_001df708;
              *(undefined4 *)(puVar12 + -0xc) = 0x164e66;
              _printf(*(char **)(puVar12 + -8));
            }
          }
          local_18 = local_18 + -1;
          puVar6 = puVar4;
          iVar3 = _stuck_count;
        }
        puVar10 = puVar10 + -2;
      } while (0 < local_18);
    }
    LOCK();
    DAT_001e9710 = 0;
    UNLOCK();
    *(undefined4 *)(puVar12 + -4) = uVar9;
    *(undefined4 *)(puVar12 + -8) = 0x164e94;
    _splx();
    bVar7 = false;
LAB_00164e9b:
    puVar11 = _master_processor;
    puVar13 = puVar12 + -4;
    if (bVar7) goto LAB_0016517c;
    *(undefined4 *)(puVar12 + -4) = 0x164eb3;
    uVar9 = _splsched();
    piVar1 = (int *)(puVar11 + 0x100);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar3 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    local_14 = *(int *)(puVar11 + 0x108);
    if (0 < local_14) {
      puVar10 = (undefined4 *)(puVar11 + *(int *)(puVar11 + 0x104) * 8);
      do {
        puVar6 = (undefined4 *)*puVar10;
        iVar3 = _stuck_count;
        while (_stuck_count = iVar3, puVar10 != puVar6) {
          puVar4 = (undefined4 *)*puVar6;
          if (((puVar6[0x13] & 0xf) == 4) && (1 < (uint)(_sched_tick - puVar6[0x1c]))) {
            if (iVar3 == 0x80) {
              LOCK();
              *(undefined4 *)(puVar11 + 0x100) = 0;
              UNLOCK();
              *(undefined4 *)(puVar12 + -4) = uVar9;
              *(undefined4 *)(puVar12 + -8) = 0x164f43;
              _splx();
              bVar7 = true;
              puVar13 = puVar12 + -4;
              goto LAB_00165179;
            }
            puVar4[1] = puVar6[1];
            *(undefined4 *)puVar6[1] = *puVar6;
            *(int *)(puVar11 + 0x108) = *(int *)(puVar11 + 0x108) + -1;
            puVar6[2] = 0;
            *(undefined4 **)(&_stuck_threads + iVar3 * 4) = puVar6;
            _stuck_count = _stuck_count + 1;
            if (_do_thread_scan_debug != 0) {
              *(undefined4 **)(puVar12 + -4) = puVar6;
              *(char **)(puVar12 + -8) = s_do_runq_scan__adding_thread___x_001df708;
              *(undefined4 *)(puVar12 + -0xc) = 0x164f91;
              _printf(*(char **)(puVar12 + -8));
            }
          }
          local_14 = local_14 + -1;
          puVar6 = puVar4;
          iVar3 = _stuck_count;
        }
        puVar10 = puVar10 + -2;
      } while (0 < local_14);
    }
    LOCK();
    *(undefined4 *)(puVar11 + 0x100) = 0;
    UNLOCK();
    *(undefined4 *)(puVar12 + -4) = uVar9;
    *(undefined4 *)(puVar12 + -8) = 0x164fc0;
    _splx();
    bVar7 = false;
LAB_00165179:
    while( true ) {
      puVar12 = puVar13 + 4;
LAB_0016517c:
      if (_stuck_count < 1) break;
      _stuck_count = _stuck_count + -1;
      puVar10 = *(undefined4 **)(&_stuck_threads + _stuck_count * 4);
      *(undefined4 *)(&_stuck_threads + _stuck_count * 4) = 0;
      *(undefined4 *)(puVar12 + -4) = 0x164fee;
      uVar9 = _splsched();
      piVar1 = puVar10 + 8;
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      if ((puVar10[0x13] & 0xf) == 4) {
        *(undefined4 **)(puVar12 + -4) = puVar10;
        *(undefined4 *)(puVar12 + -8) = 0x16501d;
        _update_priority();
        if (puVar10[0x1c] != _sched_tick) {
          *(undefined4 **)(puVar12 + -4) = puVar10;
          *(undefined4 *)(puVar12 + -8) = 0x165030;
          _update_priority();
        }
        puVar6 = DAT_001e971c;
        if (DAT_001e9724 < 1) {
          if (puVar10[0x61] == 0) {
            puVar11 = &_default_pset;
          }
          else {
            _need_ast = _need_ast | 4;
            puVar11 = _master_processor;
          }
          local_1c = puVar10[0x16];
          if (0x1f < local_1c) {
            *(uint *)(puVar12 + -4) = local_1c;
            *(char **)(puVar12 + -8) = s_run_queue_enqueue__pri_too_high___001df684;
            *(undefined4 *)(puVar12 + -0xc) = 0x1650d5;
            _printf(*(char **)(puVar12 + -8));
            local_1c = 0x1f;
          }
          piVar1 = (int *)(puVar11 + 0x100);
          do {
            do {
            } while (*piVar1 != 0);
            LOCK();
            iVar3 = *piVar1;
            *piVar1 = 1;
            UNLOCK();
          } while (iVar3 == 1);
          puVar2 = puVar11 + local_1c * 8;
          *puVar10 = puVar2;
          puVar10[1] = *(undefined4 *)(puVar2 + 4);
          *(undefined4 **)puVar10[1] = puVar10;
          *(undefined4 **)(puVar2 + 4) = puVar10;
          if ((*(uint *)(puVar11 + 0x104) < local_1c) || (*(int *)(puVar11 + 0x108) == 0)) {
            *(uint *)(puVar11 + 0x104) = local_1c;
          }
          *(int *)(puVar11 + 0x108) = *(int *)(puVar11 + 0x108) + 1;
          puVar10[2] = puVar11;
          LOCK();
          *(undefined4 *)(puVar11 + 0x100) = 0;
          UNLOCK();
          if (*(int *)(_active_threads + 0x58) < (int)puVar10[0x16]) {
            *(undefined4 *)(_processor_ptr + 0x124) = 0;
            _need_ast = _need_ast | 4;
          }
        }
        else {
          puVar4 = (undefined4 *)DAT_001e971c[0x43];
          puVar5 = (undefined4 *)DAT_001e971c[0x44];
          puVar8 = puVar5;
          if ((undefined4 **)puVar4 != &DAT_001e971c) {
            puVar4[0x44] = puVar5;
            puVar8 = _DAT_001e9720;
          }
          _DAT_001e9720 = puVar8;
          if ((undefined4 **)puVar5 != &DAT_001e971c) {
            puVar5[0x43] = puVar4;
            puVar4 = DAT_001e971c;
          }
          DAT_001e971c = puVar4;
          DAT_001e9724 = DAT_001e9724 + -1;
          puVar6[0x46] = puVar10;
          puVar6[0x45] = 3;
        }
      }
      LOCK();
      puVar10[8] = 0;
      UNLOCK();
      puVar13 = puVar12 + -4;
      *(undefined4 *)(puVar12 + -4) = uVar9;
      *(undefined4 *)(puVar12 + -8) = 0x165179;
      _splx();
    }
    if (!bVar7) {
      return;
    }
  } while( true );
}

