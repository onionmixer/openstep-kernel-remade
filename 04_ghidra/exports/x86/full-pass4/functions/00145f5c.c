/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00145f5c */

int _ipc_entry_alloc(int param_1,uint *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  
  piVar1 = (int *)(param_1 + 8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar5 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar5 == 1);
  while( true ) {
    if (*(int *)(param_1 + 0xc) == 0) {
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      return 0x10;
    }
    iVar5 = *(int *)(param_1 + 0x14);
    iVar2 = *(int *)(iVar5 + 8);
    if (iVar2 != 0) break;
    iVar5 = _ipc_entry_grow_table(param_1);
    if (iVar5 != 0) {
      return iVar5;
    }
  }
  puVar4 = (uint *)(iVar2 * 0x10 + iVar5);
  *(uint *)(iVar5 + 8) = puVar4[2];
  uVar3 = *puVar4;
  *puVar4 = uVar3 + 0x1000000;
  puVar4[2] = 0;
  *param_2 = iVar2 << 8 | uVar3 + 0x1000000 >> 0x18;
  *param_3 = puVar4;
  return 0;
}

