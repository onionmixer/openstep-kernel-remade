
void _save_rte(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 1);
  if (uVar1 < 0xa4) {
    _bcopy(param_1,&unk_40B3485,uVar1);
    _ip_nhops = uVar1 - 3 >> 2;
    *(undefined4 *)(unk_40B3488 + _ip_nhops * 4) = param_2;
    _ip_nhops = _ip_nhops + 1;
  }
  else if (_ipprintfs != 0) {
    _printf(aSaveRteOlenD,uVar1);
  }
  return;
}

