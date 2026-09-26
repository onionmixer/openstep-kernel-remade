/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018836c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined6 __regparm2 _dma_unmask_chan(undefined4 param_1,undefined2 param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  
  uVar3 = (uint)_dma_assigned_bits;
  if ((_dma_assigned_bits >> (param_3 & 0x1f) & 1) != 0) {
    uVar3 = (uint)(3 < (int)param_3);
    bVar1 = (&_dma_cmd_regs)[uVar3];
    (&_dma_cmd_regs)[uVar3] = bVar1 | 4;
    _us_spin(1);
    uVar5 = __dma_chip_port;
    if (uVar3 != 0) {
      uVar5 = DAT_001e18a0;
    }
    out(uVar5,bVar1 | 4);
    LOCK();
    _DAT_001e75ec = _DAT_001e75ec + 1;
    UNLOCK();
    _us_spin(1);
    uVar5 = DAT_001e18a4;
    if ((int)param_3 < 4) {
      uVar5 = DAT_001e1896;
    }
    out(uVar5,(byte)param_3 & 3);
    LOCK();
    _DAT_001e75ec = _DAT_001e75ec + 1;
    UNLOCK();
    uVar3 = (uint)(3 < (int)param_3);
    bVar1 = (&_dma_cmd_regs)[uVar3];
    bVar2 = bVar1 & 0xfb;
    (&_dma_cmd_regs)[uVar3] = bVar2;
    uVar4 = _us_spin(1);
    param_2 = __dma_chip_port;
    if (uVar3 != 0) {
      param_2 = DAT_001e18a0;
    }
    uVar3 = CONCAT31((int3)((uint)uVar4 >> 8),bVar1) & 0xfffffffb;
    out(param_2,bVar2);
    LOCK();
    _DAT_001e75ec = _DAT_001e75ec + 1;
    UNLOCK();
  }
  return CONCAT24(param_2,uVar3);
}

