
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong _get_dma_count(int param_1)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined2 extraout_var;
  undefined4 uVar5;
  undefined2 extraout_var_00;
  uint uVar6;
  
  uVar6 = (uint)(3 < param_1);
  bVar3 = (&_dma_cmd_regs)[uVar6];
  (&_dma_cmd_regs)[uVar6] = bVar3 | 4;
  _us_spin(1);
  uVar4 = __dma_chip_port;
  if (uVar6 != 0) {
    uVar4 = DAT_001e18a0;
  }
  out(uVar4,bVar3 | 4);
  LOCK();
  _DAT_001e75ec = _DAT_001e75ec + 1;
  UNLOCK();
  _us_spin(1);
  uVar4 = DAT_001e18a8;
  if (param_1 < 4) {
    uVar4 = DAT_001e189a;
  }
  out(uVar4,0xff);
  LOCK();
  _DAT_001e75ec = _DAT_001e75ec + 1;
  UNLOCK();
  _us_spin(1);
  iVar1 = param_1 * 10;
  in(*(undefined2 *)(&DAT_001e1848 + iVar1));
  _us_spin(1);
  in(*(undefined2 *)(&DAT_001e1848 + iVar1));
  iVar2 = _eisa_present();
  if (iVar2 == 0) {
    uVar6 = (uint)(3 < param_1);
    bVar3 = (&_dma_cmd_regs)[uVar6] & 0xfb;
    (&_dma_cmd_regs)[uVar6] = bVar3;
    _us_spin(1);
    uVar4 = __dma_chip_port;
    if (uVar6 != 0) {
      uVar4 = DAT_001e18a0;
    }
    uVar5 = CONCAT22(extraout_var_00,uVar4);
  }
  else {
    in(*(undefined2 *)(&DAT_001e184a + iVar1));
    uVar6 = (uint)(3 < param_1);
    bVar3 = (&_dma_cmd_regs)[uVar6] & 0xfb;
    (&_dma_cmd_regs)[uVar6] = bVar3;
    _us_spin(1);
    uVar4 = __dma_chip_port;
    if (uVar6 != 0) {
      uVar4 = DAT_001e18a0;
    }
    uVar5 = CONCAT22(extraout_var,uVar4);
  }
  out((short)uVar5,bVar3);
  LOCK();
  _DAT_001e75ec = _DAT_001e75ec + 1;
  UNLOCK();
  return CONCAT44(uVar5,(uint)((byte)(&DAT_001f74f1)[param_1 * 2] >> 2)) & 0xffffffff00000003;
}

