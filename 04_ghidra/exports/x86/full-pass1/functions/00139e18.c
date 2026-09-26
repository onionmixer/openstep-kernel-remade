/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00139e18 */

int FUN_00139e18(int param_1,int param_2,undefined *param_3,byte param_4)

{
  ushort uVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  undefined **ppuVar10;
  undefined *puStack_34;
  int iStack_30;
  undefined *puStack_2c;
  code *pcVar5;
  
  puVar2 = *(undefined **)(param_1 + 0x30);
  uVar1 = *(ushort *)(puVar2 + 0x42);
  if ((undefined *)0x1 < param_3) {
                    /* WARNING: Subroutine does not return */
    puStack_2c = &UNK_00139e3e;
    _panic(s_spec_rdwr_001dd793);
  }
  if (param_3 == (undefined *)0x0) {
    if (*(int *)(param_2 + 0x14) == 0) {
      return 0;
    }
    iStack_30 = 0x139e5f;
    puStack_2c = puVar2;
    _smark();
  }
  if (*(int *)(param_1 + 0x28) == 4) {
    if (param_3 == (undefined *)0x0) {
      puStack_2c = (undefined *)(int)(short)uVar1;
      ppuVar10 = &puStack_2c;
      pcVar5 = (code *)(&PTR__cnread_001e2f40)[(short)(uVar1 >> 8) * 0xb];
    }
    else {
      iStack_30 = 0x139e9f;
      puStack_2c = puVar2;
      _smark();
      iStack_30 = param_2;
      puStack_34 = (undefined *)(int)(short)uVar1;
      ppuVar10 = &puStack_34;
      pcVar5 = (code *)(&PTR__cnwrite_001e2f44)[(short)(uVar1 >> 8) * 0xb];
    }
    *(undefined4 *)((int)ppuVar10 + -4) = 0x139ec3;
    iVar4 = (*pcVar5)();
    return iVar4;
  }
  if (*(int *)(param_1 + 0x28) != 3) {
    return 0x2d;
  }
  if (*(int *)(param_2 + 0x14) == 0) {
    return 0;
  }
  uVar3 = *(undefined4 *)(puVar2 + 0x3c);
  do {
    uVar6 = *(uint *)(param_2 + 8) / 0x2000;
    uVar9 = *(uint *)(param_2 + 8) % 0x2000;
    iVar4 = 0x2000 - uVar9;
    if (*(int *)(param_2 + 0x14) < (int)(0x2000 - uVar9)) {
      iVar4 = *(int *)(param_2 + 0x14);
    }
    iVar7 = (int)(0x2000 / (ulonglong)*(uint *)(puVar2 + 0x48));
    puStack_2c = (undefined *)(uVar6 * iVar7);
    _rablock = puStack_2c + iVar7;
    _rasize = 0x2000;
    if (param_3 == (undefined *)0x0) {
      if ((int)puStack_2c < 0) {
        puStack_2c = (undefined *)0x139f69;
        pbVar8 = (byte *)_geteblk();
        puStack_2c = *(undefined **)(pbVar8 + 0x14);
        iStack_30 = *(int *)(pbVar8 + 0x20);
        puStack_34 = (undefined *)0x139f78;
        _blkclr();
        pbVar8[0x28] = 0;
        pbVar8[0x29] = 0;
        pbVar8[0x2a] = 0;
        pbVar8[0x2b] = 0;
      }
      else if (*(int *)(puVar2 + 0x44) + 1U == uVar6) {
        iStack_30 = 0x2000;
        puStack_34 = puStack_2c;
        puStack_2c = _rablock;
        pbVar8 = (byte *)_breada(uVar3);
      }
      else {
        puStack_34 = (undefined *)0x139fbf;
        iStack_30 = uVar3;
        pbVar8 = (byte *)_bread();
      }
      *(uint *)(puVar2 + 0x44) = uVar6;
    }
    else if (iVar4 == 0x2000) {
      puStack_34 = (undefined *)0x139fdf;
      iStack_30 = uVar3;
      pbVar8 = (byte *)_getblk();
    }
    else {
      puStack_34 = (undefined *)0x139ff3;
      iStack_30 = uVar3;
      pbVar8 = (byte *)_bread();
    }
    if (*(int *)(pbVar8 + 0x14) - *(int *)(pbVar8 + 0x28) < iVar4) {
      iVar4 = *(int *)(pbVar8 + 0x14) - *(int *)(pbVar8 + 0x28);
    }
    if ((*pbVar8 & 4) != 0) {
      puStack_2c = (undefined *)0x139ef7;
      _brelse();
      return 5;
    }
    puStack_2c = param_3;
    puStack_34 = (undefined *)(uVar9 + *(int *)(pbVar8 + 0x20));
    iStack_30 = iVar4;
    iVar7 = _uiomove();
    if (param_3 == (undefined *)0x0) {
      if (uVar9 + iVar4 == 0x2000) {
        *pbVar8 = *pbVar8 | 0x80;
      }
      puStack_2c = (undefined *)0x13a042;
      _brelse();
    }
    else {
      if ((param_4 & 4) == 0) {
        if (uVar9 + iVar4 == 0x2000) {
          *pbVar8 = *pbVar8 | 0x80;
          puStack_2c = (undefined *)0x13a06d;
          _bawrite();
        }
        else {
          puStack_2c = (undefined *)0x13a076;
          _bdwrite();
        }
      }
      else {
        puStack_2c = (undefined *)0x13a054;
        _bwrite();
      }
      iStack_30 = 0x13a084;
      puStack_2c = puVar2;
      _smark();
    }
    if (iVar7 != 0) {
      return iVar7;
    }
    if (*(int *)(param_2 + 0x14) < 1) {
      return 0;
    }
  } while (iVar4 != 0);
  return 0;
}

