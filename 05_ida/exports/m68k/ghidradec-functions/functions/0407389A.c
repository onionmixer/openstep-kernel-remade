
undefined4 _np_dma_intr(int param_1)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  
  if (*(int *)(param_1 + 0x126) == 4) {
    _np_printing_shutdown(param_1);
  }
  cVar2 = '\0';
  uVar1 = *(uint *)(param_1 + 0x30);
  bVar3 = (uVar1 & 0x4000) == 0;
  if (!bVar3) {
    uVar1 = (param_1 + -0x40c3a24) * 0x2b2e43db;
    cVar2 = (uVar1 >> 1 & 1) != 0;
    _printf(aNpDDmaErrorFlu,(int)uVar1 >> 2);
    uVar1 = *(uint *)(param_1 + 0x30) & 0xffffbfff;
    *(uint *)(param_1 + 0x30) = uVar1;
    bVar3 = uVar1 == 0;
  }
  return CONCAT22((sword)(uVar1 >> 0x10),
                  (word)(byte)(cVar2 << 4 | ((int)uVar1 < 0) << 3 | bVar3 << 2));
}
