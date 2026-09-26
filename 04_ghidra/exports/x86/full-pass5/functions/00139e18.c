/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00139e18 */

int FUN_00139e18(int param_1,int param_2,code *param_3,byte param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  code **ppcVar9;
  code *pcStack_34;
  int iStack_30;
  code *pcStack_2c;
  code *pcVar4;
  
  pcVar4 = *(code **)(param_1 + 0x30);
  uVar1 = *(ushort *)(pcVar4 + 0x42);
  if ((code *)0x1 < param_3) {
                    /* WARNING: Subroutine does not return */
    pcStack_2c = __analysis_fragment_00139e3e;
    _panic(s_spec_rdwr_001dd793);
  }
  if (param_3 == (code *)0x0) {
    if (*(int *)(param_2 + 0x14) == 0) {
      return 0;
    }
    iStack_30 = 0x139e5f;
    pcStack_2c = pcVar4;
    _smark();
  }
  if (*(int *)(param_1 + 0x28) == 4) {
    if (param_3 == (code *)0x0) {
      pcStack_2c = (code *)(int)(short)uVar1;
      ppcVar9 = &pcStack_2c;
      pcVar4 = (code *)(&PTR__cnread_001e2f40)[(short)(uVar1 >> 8) * 0xb];
    }
    else {
      iStack_30 = 0x139e9f;
      pcStack_2c = pcVar4;
      _smark();
      iStack_30 = param_2;
      pcStack_34 = (code *)(int)(short)uVar1;
      ppcVar9 = &pcStack_34;
      pcVar4 = (code *)(&PTR__cnwrite_001e2f44)[(short)(uVar1 >> 8) * 0xb];
    }
    *(undefined4 *)((int)ppcVar9 + -4) = 0x139ec3;
    iVar3 = (*pcVar4)();
    return iVar3;
  }
  if (*(int *)(param_1 + 0x28) != 3) {
    return 0x2d;
  }
  if (*(int *)(param_2 + 0x14) == 0) {
    return 0;
  }
  uVar2 = *(undefined4 *)(pcVar4 + 0x3c);
  do {
    uVar5 = *(uint *)(param_2 + 8) / 0x2000;
    uVar8 = *(uint *)(param_2 + 8) % 0x2000;
    iVar3 = 0x2000 - uVar8;
    if (*(int *)(param_2 + 0x14) < (int)(0x2000 - uVar8)) {
      iVar3 = *(int *)(param_2 + 0x14);
    }
    iVar6 = (int)(0x2000 / (ulonglong)*(uint *)(pcVar4 + 0x48));
    pcStack_2c = (code *)(uVar5 * iVar6);
    _rablock = pcStack_2c + iVar6;
    _rasize = 0x2000;
    if (param_3 == (code *)0x0) {
      if ((int)pcStack_2c < 0) {
        pcStack_2c = (code *)0x139f69;
        pbVar7 = (byte *)_geteblk();
        pcStack_2c = *(code **)(pbVar7 + 0x14);
        iStack_30 = *(int *)(pbVar7 + 0x20);
        pcStack_34 = (code *)0x139f78;
        _blkclr();
        pbVar7[0x28] = 0;
        pbVar7[0x29] = 0;
        pbVar7[0x2a] = 0;
        pbVar7[0x2b] = 0;
      }
      else if (*(int *)(pcVar4 + 0x44) + 1U == uVar5) {
        iStack_30 = 0x2000;
        pcStack_34 = pcStack_2c;
        pcStack_2c = _rablock;
        pbVar7 = (byte *)_breada(uVar2);
      }
      else {
        pcStack_34 = (code *)0x139fbf;
        iStack_30 = uVar2;
        pbVar7 = (byte *)_bread();
      }
      *(uint *)(pcVar4 + 0x44) = uVar5;
    }
    else if (iVar3 == 0x2000) {
      pcStack_34 = (code *)0x139fdf;
      iStack_30 = uVar2;
      pbVar7 = (byte *)_getblk();
    }
    else {
      pcStack_34 = (code *)0x139ff3;
      iStack_30 = uVar2;
      pbVar7 = (byte *)_bread();
    }
    if (*(int *)(pbVar7 + 0x14) - *(int *)(pbVar7 + 0x28) < iVar3) {
      iVar3 = *(int *)(pbVar7 + 0x14) - *(int *)(pbVar7 + 0x28);
    }
    if ((*pbVar7 & 4) != 0) {
      pcStack_2c = (code *)0x139ef7;
      _brelse();
      return 5;
    }
    pcStack_2c = param_3;
    pcStack_34 = (code *)(uVar8 + *(int *)(pbVar7 + 0x20));
    iStack_30 = iVar3;
    iVar6 = _uiomove();
    if (param_3 == (code *)0x0) {
      if (uVar8 + iVar3 == 0x2000) {
        *pbVar7 = *pbVar7 | 0x80;
      }
      pcStack_2c = (code *)0x13a042;
      _brelse();
    }
    else {
      if ((param_4 & 4) == 0) {
        if (uVar8 + iVar3 == 0x2000) {
          *pbVar7 = *pbVar7 | 0x80;
          pcStack_2c = (code *)0x13a06d;
          _bawrite();
        }
        else {
          pcStack_2c = (code *)0x13a076;
          _bdwrite();
        }
      }
      else {
        pcStack_2c = (code *)0x13a054;
        _bwrite();
      }
      iStack_30 = 0x13a084;
      pcStack_2c = pcVar4;
      _smark();
    }
    if (iVar6 != 0) {
      return iVar6;
    }
    if (*(int *)(param_2 + 0x14) < 1) {
      return 0;
    }
  } while (iVar3 != 0);
  return 0;
}

