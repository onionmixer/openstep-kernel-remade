
undefined4 _tcp_fasttimo(void)

{
  undefined4 *puVar1;
  int iVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined2 uVar5;
  uint in_D0;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  
  uVar6 = in_D0 & 0xffff0000;
  uVar5 = (undefined2)(uVar6 >> 0x10);
  bVar8 = false;
  bVar9 = false;
  bVar7 = _tcb == (undefined4 *)0x0;
  puVar4 = (undefined4 *)0x0;
  if (!bVar7) {
    bVar9 = &_tcb < _tcb;
    bVar8 = SBORROW4(0x40b7da0,(int)_tcb);
    puVar4 = (undefined4 *)((int)&_tcb - (int)_tcb);
    bVar7 = (undefined4 **)_tcb == &_tcb;
    puVar1 = _tcb;
    while (!bVar7) {
      iVar2 = puVar1[7];
      if (iVar2 != 0) {
        bVar3 = *(byte *)(iVar2 + 0x1b);
        uVar6 = CONCAT31((int3)(uVar6 >> 8),bVar3);
        if ((bVar3 & 2) != 0) {
          *(byte *)(iVar2 + 0x1b) = bVar3 & 0xfd | 1;
          unk_40BBD4C = unk_40BBD4C + 1;
          uVar6 = _tcp_output(iVar2);
        }
      }
      uVar5 = (undefined2)(uVar6 >> 0x10);
      puVar1 = (undefined4 *)*puVar1;
      bVar9 = puVar1 < &_tcb;
      bVar8 = SBORROW4((int)puVar1,0x40b7da0);
      puVar4 = puVar1 + -0x102df68;
      bVar7 = (undefined4 **)puVar1 == &_tcb;
    }
  }
  return CONCAT22(uVar5,(word)(byte)(bVar9 << 4 | ((int)puVar4 < 0) << 3 | bVar7 << 2 | bVar8 << 1 |
                                    bVar9));
}
