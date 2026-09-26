/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019335c */

undefined4 _allocbuf(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  
  puVar4 = DAT_001e8838;
  iVar6 = _page_size * (((_page_size - 1) + param_2) / _page_size);
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar6 - iVar1 != 0) {
    if (iVar6 < iVar1) {
      if (DAT_001e8838 != (uint *)&DAT_001e882c) {
        uVar3 = _splbio();
        *(uint *)(puVar4[4] + 0xc) = puVar4[3];
        *(uint *)(puVar4[3] + 0x10) = puVar4[4];
        *(byte *)puVar4 = (byte)*puVar4 | 8;
        _splx(uVar3);
        _pagemove(*(int *)(param_1 + 0x20) + iVar6,puVar4[8],*(int *)(param_1 + 0x18) - iVar6);
        puVar4[6] = *(int *)(param_1 + 0x18) - iVar6;
        *(int *)(param_1 + 0x18) = iVar6;
        *puVar4 = *puVar4 | 0x10000;
        puVar4[5] = 0;
        _brelse(puVar4);
      }
    }
    else {
      while (iVar1 < iVar6) {
        uVar5 = iVar6 - *(int *)(param_1 + 0x18);
        puVar4 = (uint *)_getnewbuf();
        uVar2 = puVar4[6];
        if ((int)uVar2 <= (int)uVar5) {
          uVar5 = uVar2;
        }
        _pagemove((uVar2 - uVar5) + puVar4[8],*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x18),
                  uVar5);
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + uVar5;
        uVar5 = puVar4[6] - uVar5;
        puVar4[6] = uVar5;
        if ((int)uVar5 < (int)puVar4[5]) {
          puVar4[5] = uVar5;
        }
        if ((int)puVar4[6] < 1) {
          *(uint *)(puVar4[2] + 4) = puVar4[1];
          *(uint *)(puVar4[1] + 8) = puVar4[2];
          puVar4[1] = (uint)DAT_001e8830;
          puVar4[2] = (uint)&DAT_001e882c;
          DAT_001e8830[2] = (uint)puVar4;
          DAT_001e8830 = puVar4;
          *(undefined2 *)((int)puVar4 + 0x1e) = 0xffff;
          *(undefined2 *)(puVar4 + 7) = 0;
          *puVar4 = *puVar4 | 0x10000;
        }
        _brelse(puVar4);
        iVar1 = *(int *)(param_1 + 0x18);
      }
    }
  }
  *(int *)(param_1 + 0x14) = param_2;
  return 1;
}

