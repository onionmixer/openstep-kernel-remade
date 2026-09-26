/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001916e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_001916e0(int param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  uint *puVar7;
  int iVar8;
  byte *pbVar9;
  
  piVar2 = (int *)(_pg_desc_tbl +
                  (((uint)(param_1 - __pg_first_phys) >> 0xc) >>
                  ((char)_ptes_per_vm_page - 1U & 0x1f)) * 0x14);
  if (param_2 == (*(byte *)(piVar2 + 4) & param_2)) {
    uVar6 = 1;
  }
  else {
    uVar6 = _splvm();
    piVar3 = (int *)piVar2[1];
    piVar5 = piVar2;
    while (piVar3 != (int *)0x0) {
      uVar4 = piVar5[2];
      piVar1 = piVar3 + 3;
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar8 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar8 == 1);
      puVar7 = (uint *)((uVar4 >> 0x16) * 4 + *piVar3);
      if (((*puVar7 & 1) != 0) &&
         (pbVar9 = (byte *)((*puVar7 & 0xfffff000) + (uVar4 >> 10 & 0xffc)),
         iVar8 = _ptes_per_vm_page, pbVar9 != (byte *)0x0)) {
        while (0 < iVar8) {
          if ((*pbVar9 & 0x40) != 0) {
            *(byte *)(piVar2 + 4) = *(byte *)(piVar2 + 4) | 1;
          }
          if ((*pbVar9 & 0x20) != 0) {
            *(byte *)(piVar2 + 4) = *(byte *)(piVar2 + 4) | 2;
          }
          pbVar9 = pbVar9 + 4;
          iVar8 = iVar8 + -1;
        }
        if (param_2 == (*(byte *)(piVar2 + 4) & param_2)) {
          LOCK();
          piVar3[3] = 0;
          UNLOCK();
          _splx(uVar6);
          return 1;
        }
      }
      LOCK();
      piVar3[3] = 0;
      UNLOCK();
      piVar5 = (int *)*piVar5;
      if (piVar5 == (int *)0x0) break;
      piVar3 = (int *)piVar5[1];
    }
    _splx(uVar6);
    uVar6 = 0;
  }
  return uVar6;
}

