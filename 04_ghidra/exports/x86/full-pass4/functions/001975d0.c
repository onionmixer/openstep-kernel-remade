/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001975d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_001975d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  short *psVar1;
  int iVar2;
  byte bVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  byte *pbVar8;
  int iVar9;
  byte local_2c;
  byte local_24;
  int local_1c;
  byte *local_18;
  short local_10;
  short local_e;
  undefined2 local_c;
  undefined2 local_a;
  undefined *local_8;
  
  if (*(int *)(param_1 + 0x114) == 2) {
    local_18 = (byte *)_kmLocalizeString(param_3);
    DAT_001e8640 = (byte *)0x0;
    _DAT_001e8628 = 0x120;
    _DAT_001e862c = 0x34;
    uVar5 = 0;
    do {
      (&DAT_001e7780)[uVar5] = 0x55;
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0xea0);
    iVar6 = 0;
    local_24 = 0;
    bVar3 = *local_18;
    pbVar8 = local_18;
    while (bVar3 != 0) {
      local_24 = *pbVar8;
      if (local_24 == 10) {
        iVar6 = iVar6 + 1;
      }
      pbVar8 = pbVar8 + 1;
      bVar3 = *pbVar8;
    }
    if (local_24 != 10) {
      iVar6 = iVar6 + 1;
    }
    DAT_001e8630 = DAT_001e8630 + 3 & 0xfffffffc;
    _DAT_001e8628 = _DAT_001e8628 & 0xfffffffc;
    iVar9 = (*(short *)(PTR__Times_Italic_14_001e3e90 + 8) + 9) / 10 +
            (int)*(short *)(PTR__Times_Italic_14_001e3e90 + 8);
    DAT_001e863c = (_DAT_001e862c - (iVar6 + -1) * iVar9) / 2 + 2;
    bVar3 = *local_18;
    while (bVar3 != 0) {
      iVar6 = 0;
      bVar3 = *local_18;
      pbVar8 = local_18;
      while ((bVar3 != 0 && (*pbVar8 != 10))) {
        iVar6 = iVar6 + *(short *)(PTR__Times_Italic_14_001e3e90 + (uint)*pbVar8 * 0x10 + -0x1e8);
        pbVar8 = pbVar8 + 1;
        bVar3 = *pbVar8;
      }
      _DAT_001e8638 = (int)(_DAT_001e8628 - iVar6) / 2;
      bVar3 = *local_18;
      while (bVar3 != 0) {
        if (*local_18 == 10) {
          local_18 = local_18 + 1;
          break;
        }
        psVar1 = (short *)(PTR__Times_Italic_14_001e3e90 + (uint)*local_18 * 0x10 + -0x1f0);
        local_1c = 0;
        if (0 < psVar1[1]) {
          do {
            sVar4 = *psVar1;
            iVar6 = 0;
            if (0 < sVar4) {
              do {
                uVar5 = ((psVar1[1] - local_1c) + -1) * (int)sVar4 + *(int *)(psVar1 + 6) + iVar6;
                if ((*(byte *)(((int)uVar5 >> 3) + *(int *)(PTR__Times_Italic_14_001e3e90 + 0x610))
                     >> (7 - (uVar5 & 7) & 0x1f) & 1) != 0) {
                  iVar2 = (((DAT_001e863c - psVar1[3]) - local_1c) * _DAT_001e8628 +
                          psVar1[2] + _DAT_001e8638 + iVar6) * 2;
                  pbVar8 = PTR_DAT_001e3e8c + (iVar2 >> 3);
                  if (pbVar8 != DAT_001e8640) {
                    if (DAT_001e8640 != (byte *)0x0) {
                      *DAT_001e8640 = DAT_001e8644;
                    }
                    DAT_001e8644 = *pbVar8;
                    DAT_001e8640 = pbVar8;
                  }
                  bVar3 = 6 - ((byte)iVar2 & 7);
                  bVar7 = (byte)(3 << (bVar3 & 0x1f));
                  local_2c = (byte)(3 << (bVar3 & 0x1f));
                  DAT_001e8644 = DAT_001e8644 & ~bVar7 | local_2c & bVar7;
                }
                iVar6 = iVar6 + 1;
                sVar4 = *psVar1;
              } while (iVar6 < sVar4);
            }
            local_1c = local_1c + 1;
          } while (local_1c < psVar1[1]);
        }
        if (DAT_001e8640 != (byte *)0x0) {
          *DAT_001e8640 = DAT_001e8644;
        }
        DAT_001e8640 = (byte *)0x0;
        _DAT_001e8638 = _DAT_001e8638 + psVar1[4];
        local_18 = local_18 + 1;
        bVar3 = *local_18;
      }
      DAT_001e863c = DAT_001e863c + iVar9;
      bVar3 = *local_18;
    }
    local_c = DAT_001e8628;
    local_a = DAT_001e862c;
    local_10 = (short)DAT_001e8630 + 0xc;
    local_e = DAT_001e8634 + 0x3e;
    local_8 = PTR_DAT_001e3e8c;
    (**(code **)(*(int *)(param_1 + 0x10c) + 0xc))(*(int *)(param_1 + 0x10c),&local_10);
  }
  return;
}

