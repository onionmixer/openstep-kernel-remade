
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _dma_initialize(void)

{
  int iVar1;
  
  _us_spin(1);
  out(DAT_001e189c,0);
  LOCK();
  _DAT_001e75ec = _DAT_001e75ec + 1;
  UNLOCK();
  _us_spin(1);
  out(DAT_001e18aa,0);
  LOCK();
  _DAT_001e75ec = _DAT_001e75ec + 1;
  UNLOCK();
  __prev_tcstatus0 = 0;
  __prev_tcstatus1 = 0;
  _us_spin(1);
  out(__dma_chip_port,0x10);
  LOCK();
  _DAT_001e75ec = _DAT_001e75ec + 1;
  UNLOCK();
  _us_spin(1);
  out(DAT_001e18a0,0x10);
  LOCK();
  _DAT_001e75ec = _DAT_001e75ec + 1;
  UNLOCK();
  _dma_cmd_regs = 0x10;
  DAT_001f74e1 = 0x10;
  iVar1 = 0;
  do {
    _dma_assign_chan(iVar1);
    if (iVar1 == 4) {
      _dma_chan_xfer_mode(4,3);
      _dma_unmask_chan(4);
    }
    else {
      _dma_deassign_chan(iVar1);
      FUN_00188124(iVar1);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  _dma_buf_initialize();
  return;
}

