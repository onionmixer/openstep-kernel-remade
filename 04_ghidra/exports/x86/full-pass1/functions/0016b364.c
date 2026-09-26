/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016b364 */

int * FUN_0016b364(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  uint local_14;
  int *local_8;
  
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_zalloc__null_zone_001dfd2a);
  }
  if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
    iVar6 = _splhigh();
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar2 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    param_1[1] = iVar6;
  }
  else {
    _lock_write(param_1 + 0xc);
  }
  local_8 = (int *)param_1[4];
  if (local_8 != (int *)0x0) {
    param_1[2] = param_1[2] + 1;
    param_1[4] = *local_8;
    if ((int *)param_1[3] == local_8) {
      param_1[3] = 0;
    }
    if (local_8 != (int *)0x0) {
LAB_0016b762:
      if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
LAB_0016b774:
        LOCK();
        *param_1 = 0;
        UNLOCK();
        _splx(param_1[1]);
      }
      else {
        _lock_done(param_1 + 0xc);
      }
      return local_8;
    }
  }
  do {
    piVar1 = param_1 + 0xc;
    while (param_1[9] != 0) {
      if (param_2 == 0) {
        if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
          LOCK();
          *param_1 = 0;
          UNLOCK();
          _splx(param_1[1]);
        }
        else {
          _lock_done(piVar1);
        }
        return (int *)0x0;
      }
      _assert_wait(param_1 + 9,1);
      if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
        LOCK();
        *param_1 = 0;
        UNLOCK();
        _splx(param_1[1]);
      }
      else {
        _lock_done(piVar1);
      }
      _thread_block_with_continuation(0);
      if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
        iVar6 = _splhigh();
        do {
          do {
          } while (*param_1 != 0);
          LOCK();
          iVar2 = *param_1;
          *param_1 = 1;
          UNLOCK();
        } while (iVar2 == 1);
        param_1[1] = iVar6;
      }
      else {
        _lock_write(piVar1);
      }
LAB_0016b758:
      if (local_8 != (int *)0x0) goto LAB_0016b762;
    }
    if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
      iVar6 = param_1[7];
    }
    else {
      iVar6 = param_1[8];
    }
    if ((uint)param_1[6] < (uint)(param_1[5] + iVar6)) {
      bVar3 = *(byte *)(param_1 + 0xb);
      if ((bVar3 & 4) != 0) goto LAB_0016b762;
      if ((bVar3 & 8) == 0) {
        if (_zone_ignore_overflow == 0) {
          if ((bVar3 & 1) == 0) {
            LOCK();
            *param_1 = 0;
            UNLOCK();
            _splx(param_1[1]);
          }
          else {
            _lock_done(piVar1);
          }
          if (param_2 == 0) {
            return (int *)0x0;
          }
          _printf(s_zone___s__empty__001dfd3c,param_1[10]);
                    /* WARNING: Subroutine does not return */
          _panic(s_zalloc_001dfd4e);
        }
      }
      else {
        param_1[6] = param_1[6] + ((uint)param_1[6] >> 1);
      }
    }
    if (((*(byte *)(param_1 + 0xb) & 1) == 0) ||
       (param_1[9] = 1, (*(byte *)(param_1 + 0xb) & 1) == 0)) {
      LOCK();
      *param_1 = 0;
      UNLOCK();
      _splx(param_1[1]);
    }
    else {
      _lock_done(piVar1);
    }
    if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
      local_8 = (int *)_zget_space(param_1[0xf],param_1[7],param_2);
      if (local_8 == (int *)0x0) {
        if (param_2 == 0) {
          return (int *)0x0;
        }
                    /* WARNING: Subroutine does not return */
        _panic(s_zalloc_001dfd5c);
      }
      if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
        iVar6 = _splhigh();
        do {
          do {
          } while (*param_1 != 0);
          LOCK();
          iVar2 = *param_1;
          *param_1 = 1;
          UNLOCK();
        } while (iVar2 == 1);
        param_1[1] = iVar6;
      }
      else {
        _lock_write(piVar1);
      }
      param_1[2] = param_1[2] + 1;
      param_1[5] = param_1[5] + param_1[7];
      if ((*(byte *)(param_1 + 0xb) & 1) != 0) {
        _lock_done(piVar1);
        return local_8;
      }
      goto LAB_0016b774;
    }
    iVar6 = _kmem_alloc_pageable(_zone_map,&local_8,param_1[8]);
    piVar8 = local_8;
    if (iVar6 != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_zalloc_001dfd55);
    }
    local_14 = param_1[8];
    if (local_8 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_zcram___memory_at_zero_001dfcfe);
    }
    uVar4 = param_1[7];
    if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
      iVar6 = _splhigh();
      do {
        do {
        } while (*param_1 != 0);
        LOCK();
        iVar2 = *param_1;
        *param_1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      param_1[1] = iVar6;
    }
    else {
      _lock_write(piVar1);
    }
    while (uVar4 <= local_14) {
      piVar5 = (int *)param_1[3];
      if ((piVar5 == (int *)0x0) || (piVar8 <= piVar5)) {
        piVar5 = param_1 + 4;
      }
      do {
        piVar7 = piVar5;
        piVar5 = (int *)*piVar7;
        if (piVar5 == (int *)0x0) break;
      } while (piVar5 < piVar8);
      *piVar8 = (int)piVar5;
      *piVar7 = (int)piVar8;
      param_1[3] = (int)piVar8;
      param_1[2] = param_1[2];
      local_14 = local_14 - uVar4;
      piVar8 = (int *)((int)piVar8 + uVar4);
      param_1[5] = param_1[5] + uVar4;
    }
    if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
      LOCK();
      *param_1 = 0;
      UNLOCK();
      _splx(param_1[1]);
    }
    else {
      _lock_done(piVar1);
    }
    if ((*(byte *)(param_1 + 0xb) & 1) == 0) {
      iVar6 = _splhigh();
      do {
        do {
        } while (*param_1 != 0);
        LOCK();
        iVar2 = *param_1;
        *param_1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      param_1[1] = iVar6;
    }
    else {
      _lock_write(piVar1);
    }
    param_1[9] = 0;
    _thread_wakeup_prim(param_1 + 9,0,0);
    local_8 = (int *)param_1[4];
    if (local_8 != (int *)0x0) {
      param_1[2] = param_1[2] + 1;
      param_1[4] = *local_8;
      if ((int *)param_1[3] == local_8) {
        param_1[3] = 0;
      }
      goto LAB_0016b758;
    }
  } while( true );
}

