/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cd5b4 */

uint * FUN_001cd5b4(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  puVar1 = *(uint **)(param_1 + 0x20);
  if (puVar1 == (uint *)&_emptyCache) {
    puVar2 = (uint *)__cache_create(param_1);
  }
  else {
    if (DAT_001e55a8 != 0) {
      if ((*(byte *)(param_1 + 0x10) & 0x40) == 0) {
        puVar1[1] = 0;
        uVar5 = 0;
        if (*puVar1 != 0xffffffff) {
          do {
            if (puVar1[uVar5 + 2] != 0) {
              if (*(undefined **)(puVar1[uVar5 + 2] + 8) == &__objc_msgForward) {
                iVar3 = _NXDefaultMallocZone();
                uVar4 = _NXDefaultMallocZone(puVar1[uVar5 + 2]);
                (**(code **)(iVar3 + 8))(uVar4);
              }
              puVar1[uVar5 + 2] = 0;
            }
            uVar5 = uVar5 + 1;
          } while (uVar5 < *puVar1 + 1);
        }
        *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) | 0x40;
        return puVar1;
      }
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xffffffbf;
    }
    uVar5 = (*puVar1 + 1) * 2;
    iVar3 = _NXDefaultMallocZone();
    uVar4 = _NXDefaultMallocZone((uVar5 - 1) * 4 + 0xc);
    puVar2 = (uint *)(**(code **)(iVar3 + 4))(uVar4);
    *puVar2 = uVar5 - 1;
    puVar2[1] = 0;
    uVar6 = 0;
    if (uVar5 != 0) {
      do {
        puVar2[uVar6 + 2] = 0;
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar5);
    }
    if (DAT_001e55a4 == 0) {
      uVar5 = 0;
      if (*puVar1 != 0xffffffff) {
        do {
          if (puVar1[uVar5 + 2] != 0) {
            uVar6 = *puVar2 & *(uint *)puVar1[uVar5 + 2];
            if (puVar2[uVar6 + 2] == 0) {
              puVar2[uVar6 + 2] = puVar1[uVar5 + 2];
            }
            else {
              do {
                uVar6 = uVar6 + 1 & *puVar2;
              } while (puVar2[uVar6 + 2] != 0);
              puVar2[uVar6 + 2] = puVar1[uVar5 + 2];
            }
            puVar2[1] = puVar2[1] + 1;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < *puVar1 + 1);
      }
      *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) | 0x20;
    }
    else {
      uVar5 = 0;
      if (*puVar1 != 0xffffffff) {
        do {
          if ((puVar1[uVar5 + 2] != 0) &&
             (*(undefined **)(puVar1[uVar5 + 2] + 8) == &__objc_msgForward)) {
            iVar3 = _NXDefaultMallocZone();
            uVar4 = _NXDefaultMallocZone(puVar1[uVar5 + 2]);
            (**(code **)(iVar3 + 8))(uVar4);
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < *puVar1 + 1);
      }
    }
    *(uint **)(param_1 + 0x20) = puVar2;
    iVar3 = _NXDefaultMallocZone();
    uVar4 = _NXDefaultMallocZone(puVar1);
    (**(code **)(iVar3 + 8))(uVar4);
  }
  return puVar2;
}

