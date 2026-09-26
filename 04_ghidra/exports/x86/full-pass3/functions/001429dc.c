/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001429dc */

void _syncip(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  undefined4 uVar11;
  
  iVar2 = *(int *)(param_1 + 0x50);
  uVar3 = (*(int *)(param_1 + 0x6c) + -1 + *(uint *)(iVar2 + 0x30)) / *(uint *)(iVar2 + 0x30);
  if ((int)uVar3 < _nbuf / 2) {
    iVar7 = 0;
    if (0 < (int)uVar3) {
      do {
        iVar4 = _bmap(param_1,iVar7,1);
        if ((iVar7 < 0xc) &&
           (*(uint *)(param_1 + 0x6c) <
            (uint)(iVar7 + 1 << ((byte)*(undefined4 *)(iVar2 + 0x50) & 0x1f)))) {
          uVar5 = ((~*(uint *)(iVar2 + 0x48) & *(uint *)(param_1 + 0x6c)) + *(int *)(iVar2 + 0x34))
                  - 1 & *(uint *)(iVar2 + 0x4c);
        }
        else {
          uVar5 = *(uint *)(iVar2 + 0x30);
        }
        _blkflush(*(undefined4 *)(param_1 + 0x40),
                  iVar4 << ((byte)*(undefined4 *)(iVar2 + 100) & 0x1f),uVar5);
        iVar7 = iVar7 + 1;
      } while (iVar7 < (int)uVar3);
    }
  }
  else {
    puVar1 = _buf + _nbuf * 0x11;
    if (_buf < puVar1) {
      puVar9 = _buf + 4;
      puVar8 = _buf;
      do {
        if ((puVar9[0xc] == *(uint *)(param_1 + 0x40)) && ((*puVar8 & 0x200) != 0)) {
          uVar6 = _splbio();
          if ((*puVar8 & 8) == 0) {
            _splx(uVar6);
            uVar6 = _splbio();
            *(uint *)(*puVar9 + 0xc) = puVar9[-1];
            *(uint *)(puVar9[-1] + 0x10) = *puVar9;
            *(byte *)puVar8 = (byte)*puVar8 | 8;
            _splx(uVar6);
            _bwrite(puVar8);
          }
          else {
            *puVar8 = *puVar8 | 0x40;
            uVar11 = 0x15;
            puVar10 = puVar8;
            _sleep((uint)puVar8);
            _splx(uVar6,puVar10,uVar11);
            puVar9 = puVar9 + -0x11;
            puVar8 = puVar8 + -0x11;
          }
        }
        puVar9 = puVar9 + 0x11;
        puVar8 = puVar8 + 0x11;
      } while (puVar8 < puVar1);
    }
  }
  *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 0x40;
  _iupdat(param_1,1);
  return;
}

