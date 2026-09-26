
uint _odclose(word param_1)

{
  word wVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 extraout_D0u;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  char cVar10;
  bool bVar11;
  
  uVar2 = (param_1 & 0xff) >> 3;
  uVar5 = param_1 & 7;
  uVar4 = uVar2 * 0xda;
  uVar6 = uVar4;
  if (uVar2 != 0x1f) {
    if (*(code **)(_cdevsw + (uint)(param_1 >> 8) * 0x2c) == _odopen) {
      uVar5 = -2 << uVar5 | 0xfffffffeU >> 0x20 - uVar5;
    }
    else {
      uVar5 = ~(0x100 << uVar5);
    }
    wVar1 = *(word *)(DAT_40c3f76 + uVar4 + 0x22) & (word)uVar5;
    uVar6 = CONCAT22((sword)(uVar5 >> 0x10),wVar1);
    *(word *)(DAT_40c3f76 + uVar4 + 0x22) = wVar1;
    if (wVar1 == 0) {
      if (((_rootdev & 0xff) >> 3 != uVar2) ||
         (uVar6 = (uint)(_rootdev >> 8), uVar6 != _od_blk_major)) {
        wVar1 = *(word *)(unk_40C3FA0 + uVar4) & 0x2800;
        uVar3 = 0;
        cVar10 = wVar1 < 0x2000;
        bVar9 = SBORROW2(wVar1,0x2000);
        bVar7 = (sword)(wVar1 + 0xe000) < 0;
        bVar8 = wVar1 == 0x2000;
        bVar11 = (bool)cVar10;
        if (!bVar8) {
          if ((*(word *)(unk_40C3FA0 + uVar4) & 0x800) != 0) {
            do {
              _sleep(unk_40C3FA0 + uVar4,0x14);
            } while ((unk_40C3FA0[uVar4] & 8) != 0);
          }
          if (*(int *)(DAT_40c3f76 + uVar4) != 0) {
            _kmem_free(_kernel_map,*(int *)(DAT_40c3f76 + uVar4),0x1c48);
            *(undefined4 *)(DAT_40c3f76 + uVar4) = 0;
          }
          if (*(int *)(DAT_40c3f76 + uVar4 + 4) != 0) {
            _kmem_free(_kernel_map,*(int *)(DAT_40c3f76 + uVar4 + 4),0x3000);
            *(undefined4 *)(DAT_40c3f76 + uVar4 + 4) = 0;
          }
          uVar3 = 0;
          if (*(int *)(DAT_40c3f76 + uVar4 + 0x18) != 0) {
            _kmem_free(_kernel_map,*(int *)(DAT_40c3f76 + uVar4 + 0x18),0x10000);
            *(undefined4 *)(DAT_40c3f76 + uVar4 + 0x18) = 0;
            uVar3 = extraout_D0u;
          }
          *(undefined2 *)(unk_40C3FA0 + uVar4) = 0;
          bVar7 = false;
          bVar8 = true;
          bVar9 = false;
          bVar11 = false;
        }
        uVar6 = CONCAT22(uVar3,(word)(byte)(cVar10 << 4 | bVar7 << 3 | bVar8 << 2 | bVar9 << 1 |
                                           bVar11));
      }
    }
  }
  return uVar6;
}
