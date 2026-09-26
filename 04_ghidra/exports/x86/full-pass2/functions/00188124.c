/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00188124 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00188124(int param_1)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 uVar6;
  uint uVar7;
  
  iVar2 = param_1 * 2;
  (&DAT_001f74f1)[iVar2] = (&DAT_001f74f1)[iVar2] & 0xf;
  iVar4 = _eisa_present();
  if (iVar4 == 0) {
    if (param_1 < 4) {
      (&DAT_001f74f1)[iVar2] = (&DAT_001f74f1)[iVar2] & 0xf3;
      uVar7 = 0;
    }
    else {
      uVar7 = (byte)(&DAT_001f74f1)[iVar2] & 0xfffffff3 | 4;
      (&DAT_001f74f1)[iVar2] = (char)uVar7;
    }
  }
  else {
    bVar1 = (&DAT_001f74f1)[iVar2];
    (&DAT_001f74f1)[iVar2] = bVar1 & 0xf3;
    uVar7 = (uint)(3 < param_1);
    bVar3 = (&_dma_cmd_regs)[uVar7];
    (&_dma_cmd_regs)[uVar7] = bVar3 | 4;
    _us_spin(1);
    uVar6 = __dma_chip_port;
    if (uVar7 != 0) {
      uVar6 = DAT_001e18a0;
    }
    out(uVar6,bVar3 | 4);
    LOCK();
    _DAT_001e75ec = _DAT_001e75ec + 1;
    UNLOCK();
    _us_spin(1);
    uVar6 = DAT_001e18ac;
    if (param_1 < 4) {
      uVar6 = DAT_001e189e;
    }
    out(uVar6,bVar1 & 0xf3);
    LOCK();
    _DAT_001e75ec = _DAT_001e75ec + 1;
    UNLOCK();
    uVar7 = (uint)(3 < param_1);
    bVar1 = (&_dma_cmd_regs)[uVar7];
    bVar3 = bVar1 & 0xfb;
    (&_dma_cmd_regs)[uVar7] = bVar3;
    uVar5 = _us_spin(1);
    uVar6 = __dma_chip_port;
    if (uVar7 != 0) {
      uVar6 = DAT_001e18a0;
    }
    uVar7 = CONCAT31((int3)((uint)uVar5 >> 8),bVar1) & 0xfffffffb;
    out(uVar6,bVar3);
    LOCK();
    _DAT_001e75ec = _DAT_001e75ec + 1;
    UNLOCK();
  }
  return uVar7;
}

