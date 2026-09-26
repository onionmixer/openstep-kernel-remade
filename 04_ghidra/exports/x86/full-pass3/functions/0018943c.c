/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018943c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _get_dma_addr(int param_1)

{
  byte bVar1;
  int iVar2;
  uint3 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  int iVar7;
  undefined2 uVar8;
  undefined2 extraout_var;
  uint uVar9;
  uint uVar10;
  
  uVar9 = (uint)(3 < param_1);
  bVar1 = (&_dma_cmd_regs)[uVar9];
  (&_dma_cmd_regs)[uVar9] = bVar1 | 4;
  _us_spin(1);
  uVar8 = __dma_chip_port;
  if (uVar9 != 0) {
    uVar8 = DAT_001e18a0;
  }
  out(uVar8,bVar1 | 4);
  LOCK();
  _DAT_001e75ec = _DAT_001e75ec + 1;
  UNLOCK();
  _us_spin(1);
  uVar8 = DAT_001e18a8;
  if (param_1 < 4) {
    uVar8 = DAT_001e189a;
  }
  out(uVar8,0xff);
  LOCK();
  _DAT_001e75ec = _DAT_001e75ec + 1;
  UNLOCK();
  _us_spin(1);
  iVar2 = param_1 * 10;
  uVar4 = in(*(undefined2 *)(&__dma_chan_port + iVar2));
  _us_spin(1);
  uVar5 = in(*(undefined2 *)(&__dma_chan_port + iVar2));
  _us_spin(1);
  uVar6 = in(*(undefined2 *)(&DAT_001e1844 + iVar2));
  uVar3 = CONCAT12(uVar6,CONCAT11(uVar5,uVar4));
  uVar9 = (uint)uVar3;
  iVar7 = _eisa_present();
  if (iVar7 != 0) {
    _us_spin(1);
    uVar4 = in(*(undefined2 *)(&DAT_001e1846 + iVar2));
    uVar9 = CONCAT13(uVar4,uVar3);
  }
  uVar10 = (uint)(3 < param_1);
  bVar1 = (&_dma_cmd_regs)[uVar10];
  (&_dma_cmd_regs)[uVar10] = bVar1 & 0xfb;
  _us_spin(1);
  uVar8 = __dma_chip_port;
  if (uVar10 != 0) {
    uVar8 = DAT_001e18a0;
  }
  out(uVar8,bVar1 & 0xfb);
  LOCK();
  _DAT_001e75ec = _DAT_001e75ec + 1;
  UNLOCK();
  if (((byte)(&DAT_001f74f1)[param_1 * 2] >> 2 & 3) == 1) {
    uVar9 = CONCAT22((short)(uVar9 >> 0x10),(short)uVar9 * 2);
  }
  return CONCAT44(CONCAT22(extraout_var,uVar8),uVar9);
}

