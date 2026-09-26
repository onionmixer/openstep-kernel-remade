
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool _is_dma_done(uint param_1)

{
  byte bVar1;
  uint uVar2;
  undefined2 uVar3;
  
  _us_spin(1);
  uVar3 = DAT_001e18a0;
  if ((int)param_1 < 4) {
    uVar3 = __dma_chip_port;
  }
  bVar1 = in(uVar3);
  if ((int)param_1 < 4) {
    uVar2 = bVar1 & 0xf | __prev_tcstatus0;
    __prev_tcstatus0 = uVar2;
  }
  else {
    param_1 = param_1 - 4;
    uVar2 = bVar1 & 0xf | __prev_tcstatus1;
    __prev_tcstatus1 = uVar2;
  }
  return (uVar2 >> (param_1 & 0x1f) & 1) != 0;
}

