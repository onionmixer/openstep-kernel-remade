/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013a61c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0013a61c(uint *param_1,uint param_2,uint param_3,int *param_4,int *param_5)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  uint local_20;
  byte local_1c;
  byte local_18;
  uint local_8;
  
  param_2 = param_2 / _page_size;
  param_3 = param_3 / *param_1;
  bVar2 = *(byte *)(param_1[3] + 3 + param_2 * 4);
  if ((bVar2 & 0xf) == 0) {
    *(undefined1 *)(param_2 + param_1[5]) = 0xff;
    if (param_1[7] <= param_2) {
      _DAT_001e5a70 = param_2 + 1;
      param_1[7] = _DAT_001e5a70;
    }
  }
  else {
    local_18 = (byte)((1 << (bVar2 & 0xf)) + -1 << (bVar2 >> 4));
    pbVar4 = (byte *)((*(uint *)(param_1[3] + param_2 * 4) & 0xffffff) + param_1[5]);
    *pbVar4 = *pbVar4 | local_18;
  }
  uVar3 = param_1[8];
  bVar2 = (byte)param_3;
  if ((uVar3 == param_1[0xb] / _page_size) || (uVar3 == param_1[0x10] / _page_size)) {
    pbVar4 = (byte *)(uVar3 + param_1[5]);
    local_1c = *pbVar4;
    if (local_1c != 0) {
      uVar3 = (1 << (bVar2 & 0x1f)) - 1;
      local_20 = 0;
      if (-param_3 != -9) {
        do {
          if ((local_1c & uVar3) == uVar3) {
            *pbVar4 = *pbVar4 & ~(byte)(uVar3 << ((byte)local_20 & 0x1f));
            goto LAB_0013a73d;
          }
          local_1c = local_1c >> 1;
          local_20 = local_20 + 1;
        } while (local_20 < -param_3 + 9);
      }
    }
  }
  else {
    local_20 = 0xffffffff;
LAB_0013a73d:
    if (-1 < (int)local_20) {
      local_8 = param_1[8];
      _DAT_001e5a64 = _DAT_001e5a64 + 1;
      goto LAB_0013a7f8;
    }
  }
  uVar3 = 0;
  if (param_1[7] != 0) {
    do {
      if (*(char *)(uVar3 + param_1[5]) == -1) {
        pbVar4 = (byte *)(param_1[5] + uVar3);
        local_1c = *pbVar4;
        local_8 = uVar3;
        if (local_1c != 0) {
          uVar3 = (1 << (bVar2 & 0x1f)) - 1;
          local_20 = 0;
          if (-param_3 != -9) goto LAB_0013a7c0;
        }
        break;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_1[7]);
  }
  goto LAB_0013a7e5;
  while( true ) {
    local_1c = local_1c >> 1;
    local_20 = local_20 + 1;
    if (-param_3 + 9 <= local_20) break;
LAB_0013a7c0:
    uVar1 = local_1c & uVar3;
    if (uVar1 == uVar3) {
      *pbVar4 = *pbVar4 & ~(byte)(uVar1 << ((byte)local_20 & 0x1f));
      goto LAB_0013a7ea;
    }
  }
LAB_0013a7e5:
  local_20 = 0xffffffff;
LAB_0013a7ea:
  if ((int)local_20 < 0) {
    return 0;
  }
  _DAT_001e5a68 = _DAT_001e5a68 + 1;
LAB_0013a7f8:
  if ((int)local_20 < 0) {
    return 0;
  }
  *(uint *)(param_1[3] + param_2 * 4) =
       *(uint *)(param_1[3] + param_2 * 4) & 0xff000000 | local_8 & 0xffffff;
  *(byte *)(param_1[3] + 3 + param_2 * 4) =
       *(byte *)(param_1[3] + 3 + param_2 * 4) & 0xf | (char)local_20 << 4;
  *(byte *)(param_1[3] + 3 + param_2 * 4) =
       *(byte *)(param_1[3] + 3 + param_2 * 4) & 0xf0 | bVar2 & 0xf;
  *param_4 = local_8 * _page_size;
  *param_5 = local_20 * *param_1;
  if (param_3 != _page_size / *param_1) {
    param_1[8] = local_8;
  }
  if (DAT_001e5a6c < local_8) {
    DAT_001e5a6c = local_8;
  }
  return 1;
}

