
void _pcb_init(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = _zalloc(_pcb_zone);
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  _bzero(uVar1,0x1a0);
  return;
}

