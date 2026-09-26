/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013c0ac */

int _blkpref(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint local_20;
  
  iVar1 = *(int *)(param_1 + 0x50);
  if ((param_4 != 0) && (0 < param_3)) {
    if (param_4 == param_1 + 0x8c) {
      local_20 = *(uint *)(param_4 + -4 + param_3 * 4);
    }
    else {
      uVar4 = *(uint *)(param_4 + -4 + param_3 * 4);
      local_20 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    }
  }
  if ((param_3 % *(int *)(iVar1 + 0x5c) == 0) || (local_20 == 0)) {
    if (param_2 < 0xc) {
      local_20 = *(uint *)(param_1 + 0x48) / *(uint *)(iVar1 + 0xb8);
LAB_0013c289:
      iVar3 = local_20 * *(int *)(iVar1 + 0xbc) + *(int *)(iVar1 + 0x38);
    }
    else {
      if ((param_3 == 0) || (local_20 == 0)) {
        iVar3 = param_2 / *(int *)(iVar1 + 0x5c) +
                *(uint *)(param_1 + 0x48) / *(uint *)(iVar1 + 0xb8);
      }
      else {
        iVar3 = (int)local_20 / *(int *)(iVar1 + 0xbc) + 1;
      }
      iVar2 = *(int *)(iVar1 + 0x2c);
      uVar4 = iVar3 % iVar2;
      iVar3 = *(int *)(iVar1 + 0xc4) / iVar2;
      if ((int)uVar4 < iVar2) {
        local_20 = uVar4;
        do {
          if (iVar3 <= *(int *)(*(int *)(iVar1 + 0x2d8 +
                                        ((int)local_20 >>
                                        ((byte)*(undefined4 *)(iVar1 + 0x70) & 0x1f)) * 4) + 4 +
                               (~*(uint *)(iVar1 + 0x6c) & local_20) * 0x10)) {
            *(uint *)(iVar1 + 0x2d4) = local_20;
            return local_20 * *(int *)(iVar1 + 0xbc) + *(int *)(iVar1 + 0x38);
          }
          local_20 = local_20 + 1;
        } while ((int)local_20 < iVar2);
      }
      local_20 = 0;
      if (-1 < (int)uVar4) {
        do {
          if (iVar3 <= *(int *)(*(int *)(iVar1 + 0x2d8 +
                                        ((int)local_20 >>
                                        ((byte)*(undefined4 *)(iVar1 + 0x70) & 0x1f)) * 4) + 4 +
                               (~*(uint *)(iVar1 + 0x6c) & local_20) * 0x10)) {
            *(uint *)(iVar1 + 0x2d4) = local_20;
            goto LAB_0013c289;
          }
          local_20 = local_20 + 1;
        } while ((int)local_20 <= (int)uVar4);
      }
      iVar3 = 0;
    }
  }
  else {
    iVar3 = local_20 + *(int *)(iVar1 + 0x38);
    iVar2 = *(int *)(iVar1 + 0x58);
    if (iVar2 < param_3) {
      if (param_4 == param_1 + 0x8c) {
        local_20 = *(uint *)(param_4 + (param_3 - iVar2) * 4);
      }
      else {
        uVar4 = *(uint *)(param_4 + (param_3 - iVar2) * 4);
        local_20 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
      }
      if (local_20 + (*(int *)(iVar1 + 0x58) << ((byte)*(undefined4 *)(iVar1 + 0x60) & 0x1f)) !=
          iVar3) {
        return iVar3;
      }
    }
    if (*(int *)(iVar1 + 0x40) != 0) {
      iVar2 = *(int *)(iVar1 + 0x38);
      iVar3 = iVar3 + ((iVar2 + -1 +
                       (*(int *)(iVar1 + 0x40) * *(int *)(iVar1 + 0x44) * *(int *)(iVar1 + 0xa8)) /
                       (*(int *)(iVar1 + 0x7c) * 1000)) / iVar2) * iVar2;
    }
  }
  return iVar3;
}

