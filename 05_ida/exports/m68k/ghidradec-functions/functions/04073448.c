
uint _np_printing_timeout(int param_1)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  cVar5 = 4 < *(uint *)(param_1 + 0x126);
  if (*(uint *)(param_1 + 0x126) == 4) {
    _np_printing_shutdown(param_1);
    cVar2 = param_1 < 0;
    cVar3 = param_1 == 0;
    cVar4 = '\0';
    bVar6 = 0;
    _np_setstate(param_1,9);
    uVar1 = (uint)(byte)(cVar5 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar6);
  }
  else {
    uVar1 = _printf(aNpDSpuriousPri,(param_1 + -0x40c3a24) * 0x2b2e43db >> 2);
  }
  return uVar1;
}
