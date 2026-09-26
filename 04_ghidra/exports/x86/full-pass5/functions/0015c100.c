/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c100 */

undefined4 _compute_mach_factor(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *local_18;
  int local_10;
  int local_8;
  
  do {
  } while (_all_psets_lock != 0);
  LOCK();
  _all_psets_lock = 1;
  UNLOCK();
  uVar3 = _all_psets_lock;
  for (puVar2 = _all_psets; (undefined4 **)puVar2 != &_all_psets;
      puVar2 = (undefined4 *)puVar2[0x53]) {
    piVar5 = puVar2 + 0x56;
    _all_psets_lock = uVar3;
    do {
      do {
      } while (*piVar5 != 0);
      LOCK();
      iVar4 = *piVar5;
      *piVar5 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    local_10 = puVar2[0x49];
    if (0 < local_10) {
      iVar4 = puVar2[0x42];
      for (puVar1 = (undefined4 *)puVar2[0x47]; puVar2 + 0x47 != puVar1;
          puVar1 = (undefined4 *)puVar1[0x4d]) {
        iVar4 = iVar4 + puVar1[0x42];
      }
      iVar4 = iVar4 + (local_10 - puVar2[0x45]);
      if (puVar2 == (undefined4 *)&_default_pset) {
        iVar4 = iVar4 + -1;
      }
      if (local_10 < iVar4) {
        local_8 = (local_10 * 1000) / (iVar4 + 1);
        local_10 = (iVar4 << 7) / local_10;
      }
      else {
        local_8 = (local_10 - iVar4) * 1000;
        local_10 = 0x80;
      }
      puVar2[0x5c] = (puVar2[0x5c] * 4 + local_8) / 5;
      puVar2[0x5d] = (puVar2[0x5d] * 4 + iVar4 * 1000) / 5;
      if (puVar2 == (undefined4 *)&_default_pset) {
        piVar5 = &_avenrun;
        local_18 = &DAT_001dee80;
        piVar6 = &_mach_factor;
        do {
          *piVar6 = (*local_18 * *piVar6 + (1000 - *local_18) * local_8) / 1000;
          *piVar5 = (*local_18 * *piVar5 + (1000 - *local_18) * iVar4 * 1000) / 1000;
          piVar5 = piVar5 + 1;
          local_18 = local_18 + 1;
          piVar6 = piVar6 + 1;
        } while ((int)piVar5 < 0x1dee71);
      }
      puVar2[0x5e] = local_10 + puVar2[0x5e] >> 1;
    }
    LOCK();
    puVar2[0x56] = 0;
    UNLOCK();
    uVar3 = _all_psets_lock;
  }
  LOCK();
  _all_psets_lock = 0;
  UNLOCK();
  return uVar3;
}

