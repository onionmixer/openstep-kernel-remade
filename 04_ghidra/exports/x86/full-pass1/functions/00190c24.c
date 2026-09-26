/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00190c24 */

int _pmap_extract(int *param_1,uint param_2)

{
  int *piVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  
  uVar2 = _splvm();
  piVar1 = param_1 + 3;
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar4 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar4 == 1);
  puVar3 = (uint *)((param_2 >> 0x16) * 4 + *param_1);
  if ((((*puVar3 & 1) == 0) ||
      (puVar3 = (uint *)((param_2 >> 10 & 0xffc) + (*puVar3 & 0xfffff000)), puVar3 == (uint *)0x0))
     || ((*puVar3 & 1) == 0)) {
    iVar4 = 0;
  }
  else {
    iVar4 = (param_2 & 0xfff) + (*puVar3 & 0xfffff000);
  }
  LOCK();
  param_1[3] = 0;
  UNLOCK();
  _splx(uVar2);
  return iVar4;
}

