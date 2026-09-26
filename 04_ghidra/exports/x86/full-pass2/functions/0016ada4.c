/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016ada4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * _zget_space(undefined *param_1,uint param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint local_c;
  int local_8;
  
  local_8 = 0;
  if (param_1 == (undefined *)0x0) {
    param_1 = &__zone_default_space;
  }
  if (param_2 < 0x11) {
    param_2 = 0x10;
  }
  else {
    param_2 = param_2 + 0xf & 0xfffffff0;
  }
  do {
  } while (_zget_space_lock != 0);
  LOCK();
  UNLOCK();
  do {
    _zget_space_lock = 1;
    piVar2 = (int *)FUN_0016a360(param_1,param_2);
    if (piVar2 != (int *)0x0) {
      piVar1 = (int *)piVar2[2];
      if (piVar2[1] - param_2 < 0x10) {
        iVar5 = *piVar2;
        *piVar1 = iVar5;
        if (iVar5 != 0) {
          *(int **)(*piVar2 + 8) = piVar1;
        }
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;
      }
      else {
        piVar3 = (int *)(param_2 + (int)piVar2);
        piVar3[1] = piVar2[1] - param_2;
        iVar5 = *piVar2;
        *piVar3 = iVar5;
        if (iVar5 != 0) {
          *(int **)(iVar5 + 8) = piVar3;
        }
        piVar3[2] = (int)piVar1;
        *piVar1 = (int)piVar3;
        uVar4 = (uint)piVar3[1] >> ((byte)*(undefined4 *)(param_1 + 0x10) & 0x1f);
        if ((int)*(uint *)(param_1 + 0x18) < (int)uVar4) {
          uVar4 = *(uint *)(param_1 + 0x18);
        }
        iVar5 = *(int *)(param_1 + 0x14) + uVar4 * 0x10;
        piVar1 = *(int **)(iVar5 + -0x10);
        if ((piVar1 == (int *)0x0) || (piVar3 < piVar1)) {
          *(int **)(iVar5 + -0x10) = piVar3;
        }
      }
LAB_0016af3f:
      LOCK();
      _zget_space_lock = 0;
      UNLOCK();
      if (local_8 != 0) {
        _kmem_free(_zone_map,local_8,local_c);
      }
      return piVar2;
    }
    if (local_8 != 0) {
      piVar2 = (int *)_zone_free_space_add(param_1,param_2,local_8,local_c);
      local_8 = 0;
      goto LAB_0016af3f;
    }
    local_c = param_2 + _page_mask & ~_page_mask;
    if (local_c <= _zdata_size) {
      _zdata_size = _zdata_size - local_c;
      piVar2 = (int *)_zone_free_space_add(param_1,param_2,_zdata_size + __zdata,local_c);
      goto LAB_0016af3f;
    }
    LOCK();
    _zget_space_lock = 0;
    UNLOCK();
    iVar5 = _kmem_alloc_zone(_zone_map,&local_8,local_c,param_3);
    if (iVar5 != 0) {
      return (int *)0x0;
    }
    do {
    } while (_zget_space_lock != 0);
    LOCK();
    UNLOCK();
  } while( true );
}

