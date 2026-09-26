/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016b5b5 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0016b5b5(void)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *unaff_EBX;
  int unaff_EBP;
  int *piVar7;
  
  do {
    piVar7 = *(int **)(unaff_EBP + -4);
    *(int *)(unaff_EBP + -0x10) = unaff_EBX[8];
    if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_zcram___memory_at_zero_001dfcfe);
    }
    uVar3 = unaff_EBX[7];
    if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) {
      iVar5 = _splhigh();
      do {
        do {
        } while (*unaff_EBX != 0);
        LOCK();
        iVar1 = *unaff_EBX;
        *unaff_EBX = 1;
        UNLOCK();
      } while (iVar1 == 1);
      unaff_EBX[1] = iVar5;
    }
    else {
      _lock_write();
    }
    while (uVar3 <= *(uint *)(unaff_EBP + -0x10)) {
      piVar4 = (int *)unaff_EBX[3];
      if ((piVar4 == (int *)0x0) || (piVar7 <= piVar4)) {
        piVar4 = unaff_EBX + 4;
      }
      do {
        piVar6 = piVar4;
        piVar4 = (int *)*piVar6;
        if (piVar4 == (int *)0x0) break;
      } while (piVar4 < piVar7);
      *piVar7 = (int)piVar4;
      *piVar6 = (int)piVar7;
      unaff_EBX[3] = (int)piVar7;
      unaff_EBX[2] = unaff_EBX[2];
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) - uVar3;
      piVar7 = (int *)((int)piVar7 + uVar3);
      unaff_EBX[5] = unaff_EBX[5] + uVar3;
    }
    if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) {
      LOCK();
      *unaff_EBX = 0;
      UNLOCK();
      _splx();
    }
    else {
      _lock_done();
    }
    if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) {
      iVar5 = _splhigh();
      do {
        do {
        } while (*unaff_EBX != 0);
        LOCK();
        iVar1 = *unaff_EBX;
        *unaff_EBX = 1;
        UNLOCK();
      } while (iVar1 == 1);
      unaff_EBX[1] = iVar5;
    }
    else {
      _lock_write();
    }
    unaff_EBX[9] = 0;
    _thread_wakeup_prim(unaff_EBX + 9,0);
    *(int *)(unaff_EBP + -4) = unaff_EBX[4];
    piVar7 = *(int **)(unaff_EBP + -4);
    if (piVar7 == (int *)0x0) {
      *(int **)(unaff_EBP + -8) = unaff_EBX + 0xc;
      goto LAB_0016b3e8;
    }
    unaff_EBX[2] = unaff_EBX[2] + 1;
    unaff_EBX[4] = *piVar7;
    if ((int *)unaff_EBX[3] == piVar7) {
      unaff_EBX[3] = 0;
    }
    while( true ) {
      if (*(int *)(unaff_EBP + -4) != 0) goto LAB_0016b762;
LAB_0016b3e8:
      if (unaff_EBX[9] == 0) break;
      if (*(int *)(unaff_EBP + 0xc) == 0) {
        if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) {
          LOCK();
          *unaff_EBX = 0;
          UNLOCK();
          _splx();
          return 0;
        }
        _lock_done();
        return 0;
      }
      _assert_wait(unaff_EBX + 9);
      if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) {
        LOCK();
        *unaff_EBX = 0;
        UNLOCK();
        _splx();
      }
      else {
        _lock_done();
      }
      _thread_block_with_continuation();
      if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) {
        iVar5 = _splhigh();
        do {
          do {
          } while (*unaff_EBX != 0);
          LOCK();
          iVar1 = *unaff_EBX;
          *unaff_EBX = 1;
          UNLOCK();
        } while (iVar1 == 1);
        unaff_EBX[1] = iVar5;
      }
      else {
        _lock_write();
      }
    }
    if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) {
      iVar5 = unaff_EBX[7];
    }
    else {
      iVar5 = unaff_EBX[8];
    }
    if ((uint)unaff_EBX[6] < (uint)(unaff_EBX[5] + iVar5)) {
      bVar2 = *(byte *)(unaff_EBX + 0xb);
      if ((bVar2 & 4) != 0) {
LAB_0016b762:
        if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) goto LAB_0016b774;
        _lock_done();
        goto LAB_0016b781;
      }
      if ((bVar2 & 8) == 0) {
        if (_zone_ignore_overflow == 0) {
          if ((bVar2 & 1) == 0) {
            LOCK();
            *unaff_EBX = 0;
            UNLOCK();
            _splx();
          }
          else {
            _lock_done();
          }
          if (*(int *)(unaff_EBP + 0xc) == 0) {
            return 0;
          }
          _printf(s_zone___s__empty__001dfd3c);
                    /* WARNING: Subroutine does not return */
          _panic(s_zalloc_001dfd4e);
        }
      }
      else {
        unaff_EBX[6] = unaff_EBX[6] + ((uint)unaff_EBX[6] >> 1);
      }
    }
    if (((*(byte *)(unaff_EBX + 0xb) & 1) == 0) ||
       (unaff_EBX[9] = 1, (*(byte *)(unaff_EBX + 0xb) & 1) == 0)) {
      LOCK();
      *unaff_EBX = 0;
      UNLOCK();
      _splx();
    }
    else {
      _lock_done();
    }
    if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) {
      iVar5 = _zget_space(unaff_EBX[0xf],unaff_EBX[7]);
      *(int *)(unaff_EBP + -4) = iVar5;
      if (iVar5 == 0) {
        if (*(int *)(unaff_EBP + 0xc) == 0) {
          return 0;
        }
                    /* WARNING: Subroutine does not return */
        _panic(s_zalloc_001dfd5c);
      }
      if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) {
        iVar5 = _splhigh();
        do {
          do {
          } while (*unaff_EBX != 0);
          LOCK();
          iVar1 = *unaff_EBX;
          *unaff_EBX = 1;
          UNLOCK();
        } while (iVar1 == 1);
        unaff_EBX[1] = iVar5;
      }
      else {
        _lock_write();
      }
      unaff_EBX[2] = unaff_EBX[2] + 1;
      unaff_EBX[5] = unaff_EBX[5] + unaff_EBX[7];
      if ((*(byte *)(unaff_EBX + 0xb) & 1) == 0) {
LAB_0016b774:
        LOCK();
        *unaff_EBX = 0;
        UNLOCK();
        _splx();
      }
      else {
        _lock_done();
      }
LAB_0016b781:
      return *(undefined4 *)(unaff_EBP + -4);
    }
    iVar5 = _kmem_alloc_pageable(_zone_map,unaff_EBP + -4);
    if (iVar5 != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_zalloc_001dfd55);
    }
  } while( true );
}

