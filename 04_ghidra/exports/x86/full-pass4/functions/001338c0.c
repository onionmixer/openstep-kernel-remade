/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001338c0 */

undefined8 FUN_001338c0(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  short *psVar9;
  uint uVar10;
  uint uVar11;
  uint local_2c;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  local_20 = 0;
  piVar8 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
  do {
    do {
    } while (*piVar8 != 0);
    LOCK();
    iVar7 = *piVar8;
    *piVar8 = 1;
    UNLOCK();
  } while (iVar7 == 1);
  *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) | 8;
  LOCK();
  *(undefined4 *)(*(int *)(param_2 + 0x14) + 0x10) = 0;
  UNLOCK();
  iVar7 = param_1[0xc];
  _rlock(iVar7);
  uVar10 = _page_size;
  uVar11 = *(uint *)(*(int *)(param_1[9] + 0x128) + 0x24) & 0xfffffc00;
  local_2c = _page_size;
  psVar9 = *(short **)(*param_1 + 0x30);
  if (psVar9 == (short *)0x0) {
    if (*(int *)(*(int *)(_active_threads + 0xc) + 0x3c) == 0) {
      psVar9 = *(short **)(iVar7 + 0x70);
      if (psVar9 == (short *)0x0) {
        _printf(s_NFS_failure_on_pagein__no_creden_001dcb70);
        _runlock(iVar7);
        piVar8 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
        do {
          do {
          } while (*piVar8 != 0);
          LOCK();
          iVar7 = *piVar8;
          *piVar8 = 1;
          UNLOCK();
        } while (iVar7 == 1);
        *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) & 0xf7;
        iVar7 = *(int *)(param_2 + 0x14);
        LOCK();
        *(undefined4 *)(iVar7 + 0x10) = 0;
        UNLOCK();
        uVar3 = 2;
        goto LAB_00133dd9;
      }
    }
    else {
      psVar9 = (short *)_active_u[7];
    }
  }
  *psVar9 = *psVar9 + 1;
  if (*(int *)(iVar7 + 0x70) != 0) {
    _crfree(*(int *)(iVar7 + 0x70));
  }
  *(short **)(iVar7 + 0x70) = psVar9;
  if (*(uint *)(iVar7 + 0x98) < param_3 + uVar10) {
    _vm_page_zero_fill(param_2);
  }
  while( true ) {
    uVar2 = param_3 / uVar11;
    uVar6 = param_3 % uVar11;
    uVar10 = local_2c;
    if (uVar11 - uVar6 < local_2c) {
      uVar10 = uVar11 - uVar6;
    }
    uVar5 = *(uint *)(iVar7 + 0x98) - param_3;
    if (*(uint *)(iVar7 + 0x98) <= param_3) break;
    if (uVar5 < uVar10) {
      uVar10 = uVar5;
    }
    (**(code **)(param_1[7] + 0x50))(param_1,uVar2,&local_8,&local_c);
    if (local_c < 0) {
      _runlock(iVar7);
      piVar8 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
      do {
        do {
        } while (*piVar8 != 0);
        LOCK();
        iVar7 = *piVar8;
        *piVar8 = 1;
        UNLOCK();
      } while (iVar7 == 1);
      *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) & 0xf7;
      LOCK();
      piVar8 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
      iVar7 = *piVar8;
      *piVar8 = 0;
      UNLOCK();
      uVar3 = 1;
      goto LAB_00133dd9;
    }
    _nfs_validate_caches(local_8,*(undefined4 *)(iVar7 + 0x70),0);
    local_1c = 0;
    if (((_page_size == uVar11) && (local_20 == 0)) && (uVar6 == 0)) {
      iVar1 = *(int *)(iVar7 + 100);
      if (iVar1 + 1U == uVar2) {
        (**(code **)(param_1[7] + 0x50))(param_1,iVar1 + 2,0,&local_10);
        if (_nfsslowlink == 0) goto LAB_00133b9f;
        (**(code **)(param_1[7] + 0x50))(param_1,iVar1 + 3,0,&local_14);
        (**(code **)(param_1[7] + 0x50))(param_1,iVar1 + 4,0,&local_18);
      }
      else {
        local_10 = 0;
LAB_00133b9f:
        local_14 = 0;
        local_18 = 0;
      }
      uVar6 = _breadDirect(local_8,param_2,local_c,uVar11,uVar10,local_10,uVar11,&local_1c);
      if (local_14 != 0) {
        _vnReadAhead(local_8,local_14,uVar11);
      }
      if (local_18 != 0) {
        _vnReadAhead(local_8,local_18,uVar11);
      }
      if (local_1c == 0) {
        *(uint *)(iVar7 + 100) = uVar2;
        if ((int)uVar6 < (int)uVar10) {
          uVar10 = uVar6;
        }
        goto LAB_00133cd9;
      }
LAB_00133ce3:
      *(int *)(*param_1 + 0x34) = local_1c;
      if (*(short *)(*param_1 + 4) == 0) {
        if (*(int *)(*(int *)(_active_threads + 0xc) + 0x3c) != 0) {
          _printf(s__s__d___001dcb97,_active_u + 2,(int)*(short *)(*_active_u + 0x30));
        }
        if (local_1c == 0x46) {
          _printf(s_NFS_read_error_on_pagein__stale_f_001dcba0);
        }
        else {
          _printf(s_NFS_read_error__d_on_pagein_001dcbcd,local_1c);
        }
      }
      _runlock(iVar7);
      piVar8 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
      do {
        do {
        } while (*piVar8 != 0);
        LOCK();
        iVar7 = *piVar8;
        *piVar8 = 1;
        UNLOCK();
      } while (iVar7 == 1);
      *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) & 0xf7;
      LOCK();
      piVar8 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
      iVar7 = *piVar8;
      *piVar8 = 0;
      UNLOCK();
      uVar3 = 2;
      goto LAB_00133dd9;
    }
    _incore(local_8,local_c);
    if (*(int *)(iVar7 + 100) + 1U == uVar2) {
      (**(code **)(param_1[7] + 0x50))(param_1,*(int *)(iVar7 + 100) + 2,0,&local_10);
      puVar4 = (uint *)_breada(local_8,local_c,uVar11,local_10,uVar11);
    }
    else {
      puVar4 = (uint *)_bread(local_8,local_c,uVar11);
    }
    *(uint *)(iVar7 + 100) = uVar2;
    if ((*puVar4 & 4) == 0) {
      _copy_to_phys(uVar6 + puVar4[8],local_20 + *(int *)(param_2 + 0x24),uVar10);
      if ((*puVar4 & 0xfffffffc) == 0) {
        *puVar4 = *puVar4 | 0x400000;
      }
    }
    else {
      local_1c = (int)(short)puVar4[7];
    }
    _brelse(puVar4);
LAB_00133cd9:
    if (local_1c != 0) goto LAB_00133ce3;
    local_2c = local_2c - uVar10;
    local_20 = local_20 + uVar10;
    param_3 = param_3 + uVar10;
    if (((int)local_2c < 1) || (uVar10 == 0)) goto LAB_00133d9f;
  }
  if (local_20 == 0) {
    _runlock(iVar7);
    piVar8 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
    do {
      do {
      } while (*piVar8 != 0);
      LOCK();
      iVar7 = *piVar8;
      *piVar8 = 1;
      UNLOCK();
    } while (iVar7 == 1);
    *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) & 0xf7;
    iVar7 = *(int *)(param_2 + 0x14);
    LOCK();
    *(undefined4 *)(iVar7 + 0x10) = 0;
    UNLOCK();
    uVar3 = 1;
    goto LAB_00133dd9;
  }
LAB_00133d9f:
  _runlock(iVar7);
  piVar8 = (int *)(*(int *)(param_2 + 0x14) + 0x10);
  do {
    do {
    } while (*piVar8 != 0);
    LOCK();
    iVar7 = *piVar8;
    *piVar8 = 1;
    UNLOCK();
  } while (iVar7 == 1);
  *(byte *)(param_2 + 0x21) = *(byte *)(param_2 + 0x21) & 0xf7;
  iVar7 = *(int *)(param_2 + 0x14);
  LOCK();
  *(undefined4 *)(iVar7 + 0x10) = 0;
  UNLOCK();
  uVar3 = 0;
LAB_00133dd9:
  return CONCAT44(iVar7,uVar3);
}

