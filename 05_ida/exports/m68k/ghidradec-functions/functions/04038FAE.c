
void _syncip(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  
  iVar2 = *(int *)(param_1 + 0x4e);
  uVar5 = (*(uint *)(iVar2 + 0x30) + *(int *)(param_1 + 0x6e) + -1) / *(uint *)(iVar2 + 0x30);
  iVar6 = _nbuf;
  if (_nbuf < 0) {
    iVar6 = _nbuf + 1;
  }
  if ((int)uVar5 < iVar6 >> 1) {
    iVar6 = 0;
    if (0 < (int)uVar5) {
      do {
        iVar3 = _bmap(param_1,iVar6,1);
        if ((iVar6 < 0xc) &&
           (*(uint *)(param_1 + 0x6e) < (uint)(iVar6 + 1 << (*(uint *)(iVar2 + 0x50) & 0x3f)))) {
          uVar4 = *(uint *)(iVar2 + 0x4c) &
                  (*(int *)(iVar2 + 0x34) + (*(uint *)(param_1 + 0x6e) & ~*(uint *)(iVar2 + 0x48)))
                  - 1;
        }
        else {
          uVar4 = *(uint *)(iVar2 + 0x30);
        }
        _blkflush(*(undefined4 *)(param_1 + 0x3e),iVar3 << (*(uint *)(iVar2 + 100) & 0x3f),uVar4);
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)uVar5);
    }
  }
  else {
    puVar1 = _buf + _nbuf * 0x11;
    for (puVar7 = _buf; puVar7 < puVar1; puVar7 = puVar7 + 0x11) {
      if ((puVar7[0x10] == *(uint *)(param_1 + 0x3e)) && ((*puVar7 & 0x200) != 0)) {
        if ((*puVar7 & 8) == 0) {
          *(uint *)(puVar7[4] + 0xc) = puVar7[3];
          *(uint *)(puVar7[3] + 0x10) = puVar7[4];
          *puVar7 = *puVar7 | 8;
          _bwrite(puVar7);
        }
        else {
          *puVar7 = *puVar7 | 0x40;
          _sleep(puVar7,0x15);
          puVar7 = puVar7 + -0x11;
        }
      }
    }
  }
  *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x40;
  _iupdat(param_1,1);
  return;
}
