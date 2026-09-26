/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017afd8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _vm_page_rename(int param_1,int *param_2,uint param_3)

{
  undefined4 *puVar1;
  short *psVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  
  do {
  } while (_vm_page_queue_lock != 0);
  LOCK();
  _vm_page_queue_lock = 1;
  UNLOCK();
  if ((*(byte *)(param_1 + 0x20) & 4) != 0) {
    piVar3 = (int *)(_vm_page_buckets +
                    ((*(uint *)(param_1 + 0x18) >> ((byte)_page_shift & 0x1f)) +
                     *(int *)(param_1 + 0x14) & __vm_page_hash_mask) * 8);
    uVar4 = _splimp();
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar5 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar5 == 1);
    iVar5 = piVar3[1];
    if (iVar5 == param_1) {
      piVar3[1] = *(int *)(param_1 + 0x10);
    }
    else {
      do {
        puVar1 = (undefined4 *)(iVar5 + 0x10);
        iVar5 = *(int *)(iVar5 + 0x10);
      } while (iVar5 != param_1);
      *puVar1 = *(undefined4 *)(iVar5 + 0x10);
    }
    LOCK();
    *piVar3 = 0;
    UNLOCK();
    _splx(uVar4);
    iVar5 = *(int *)(param_1 + 8);
    piVar3 = *(int **)(param_1 + 0xc);
    if (*(int *)(param_1 + 0x14) == iVar5) {
      *(int **)(iVar5 + 4) = piVar3;
    }
    else {
      *(int **)(iVar5 + 0xc) = piVar3;
    }
    if (*(int **)(param_1 + 0x14) == piVar3) {
      *piVar3 = iVar5;
    }
    else {
      piVar3[2] = iVar5;
    }
    psVar2 = (short *)(*(int *)(param_1 + 0x14) + 0x1a);
    *psVar2 = *psVar2 + -1;
    *(byte *)(param_1 + 0x20) = *(byte *)(param_1 + 0x20) & 0xfb;
  }
  *(int **)(param_1 + 0x14) = param_2;
  *(uint *)(param_1 + 0x18) = param_3;
  piVar3 = (int *)(_vm_page_buckets +
                  ((param_3 >> ((byte)_page_shift & 0x1f)) + (int)param_2 & __vm_page_hash_mask) * 8
                  );
  uVar4 = _splimp();
  do {
    do {
    } while (*piVar3 != 0);
    LOCK();
    iVar5 = *piVar3;
    *piVar3 = 1;
    UNLOCK();
  } while (iVar5 == 1);
  *(int *)(param_1 + 0x10) = piVar3[1];
  piVar3[1] = param_1;
  LOCK();
  *piVar3 = 0;
  UNLOCK();
  _splx(uVar4);
  piVar3 = (int *)param_2[1];
  if (param_2 == piVar3) {
    *param_2 = param_1;
  }
  else {
    piVar3[2] = param_1;
  }
  *(int **)(param_1 + 0xc) = piVar3;
  *(int **)(param_1 + 8) = param_2;
  param_2[1] = param_1;
  *(byte *)(param_1 + 0x20) = *(byte *)(param_1 + 0x20) | 4;
  *(short *)((int)param_2 + 0x1a) = *(short *)((int)param_2 + 0x1a) + 1;
  uVar4 = _vm_page_queue_lock;
  LOCK();
  _vm_page_queue_lock = 0;
  UNLOCK();
  return uVar4;
}

