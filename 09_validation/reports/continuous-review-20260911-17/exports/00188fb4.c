
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __regparm2
_dma_xfer_width(undefined4 param_1,undefined4 param_2,uint param_3,byte param_4)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  byte bVar5;
  undefined2 uVar6;
  undefined2 extraout_var;
  
  uVar3 = (uint)_dma_assigned_bits;
  if ((_dma_assigned_bits >> (param_3 & 0x1f) & 1) != 0) {
    bVar5 = (param_4 & 3) << 2;
    bVar1 = (&DAT_001f74f1)[param_3 * 2];
    (&DAT_001f74f1)[param_3 * 2] = bVar1 & 0xf3 | bVar5;
    uVar3 = (uint)(3 < (int)param_3);
    bVar2 = (&_dma_cmd_regs)[uVar3];
    (&_dma_cmd_regs)[uVar3] = bVar2 | 4;
    _us_spin(1);
    uVar6 = __dma_chip_port;
    if (uVar3 != 0) {
      uVar6 = DAT_001e18a0;
    }
    out(uVar6,bVar2 | 4);
    LOCK();
    _DAT_001e75ec = _DAT_001e75ec + 1;
    UNLOCK();
    _us_spin(1);
    uVar6 = DAT_001e18ac;
    if ((int)param_3 < 4) {
      uVar6 = DAT_001e189e;
    }
    out(uVar6,(byte)param_3 & 3 | bVar1 & 0xf0 | bVar5);
    LOCK();
    _DAT_001e75ec = _DAT_001e75ec + 1;
    UNLOCK();
    uVar3 = (uint)(3 < (int)param_3);
    bVar1 = (&_dma_cmd_regs)[uVar3];
    bVar2 = bVar1 & 0xfb;
    (&_dma_cmd_regs)[uVar3] = bVar2;
    uVar4 = _us_spin(1);
    uVar6 = __dma_chip_port;
    if (uVar3 != 0) {
      uVar6 = DAT_001e18a0;
    }
    param_2 = CONCAT22(extraout_var,uVar6);
    uVar3 = CONCAT31((int3)((uint)uVar4 >> 8),bVar1) & 0xfffffffb;
    out(uVar6,bVar2);
    LOCK();
    _DAT_001e75ec = _DAT_001e75ec + 1;
    UNLOCK();
  }
  return CONCAT44(param_2,uVar3);
}

