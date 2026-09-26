/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017b134 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _vm_page_init(undefined4 *param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar4 = &_vm_page_template;
  puVar5 = param_1;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  param_1[9] = param_4;
  if ((*(byte *)(param_1 + 8) & 4) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_vm_page_insert_001e0d84);
  }
  param_1[5] = param_2;
  param_1[6] = param_3;
  piVar1 = (int *)(_vm_page_buckets +
                  ((param_3 >> ((byte)_page_shift & 0x1f)) + (int)param_2 & __vm_page_hash_mask) * 8
                  );
  uVar2 = _splimp();
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar3 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  param_1[4] = piVar1[1];
  piVar1[1] = (int)param_1;
  LOCK();
  *piVar1 = 0;
  UNLOCK();
  _splx(uVar2);
  puVar4 = (undefined4 *)param_2[1];
  if (param_2 == puVar4) {
    *param_2 = param_1;
  }
  else {
    puVar4[2] = param_1;
  }
  param_1[3] = puVar4;
  param_1[2] = param_2;
  param_2[1] = param_1;
  *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) | 4;
  *(short *)((int)param_2 + 0x1a) = *(short *)((int)param_2 + 0x1a) + 1;
  return;
}

