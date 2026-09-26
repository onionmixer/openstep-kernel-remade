
void _ttyecho(uint param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if ((*(byte *)(iVar1 + 0x3f) & 0x20) == 0) {
    *(byte *)(iVar1 + 0x3b) = *(byte *)(iVar1 + 0x3b) & 0x7f;
  }
  if ((((*(uint *)(iVar1 + 0x3a) & 8) != 0) ||
      (((*(byte *)((int)param_2 + 0x13) & 2) != 0 && (param_1 == 10)))) &&
     ((*(byte *)(iVar1 + 0x3f) & 0x40) == 0)) {
    if (((*(uint *)(iVar1 + 0x3a) & 0x10000000) != 0) &&
       ((((param_1 & 0xff) < 0x20 && (1 < param_1 - 9)) || ((param_1 & 0xff) == 0x7f)))) {
      _ttyoutput(0x5e,iVar1);
      param_1 = param_1 & 0xff;
      if (param_1 == 0x7f) {
        param_1 = 0x3f;
      }
      else if ((*(byte *)(iVar1 + 0x3d) & 4) == 0) {
        param_1 = param_1 + 0x40;
      }
      else {
        param_1 = param_1 + 0x60;
      }
    }
    param_1 = param_1 & 0xff;
    if (((0x1f < param_1) &&
        ((((*(byte *)(iVar1 + 0x3a) & 8) != 0 || ((*(byte *)((int)param_2 + 0x11) & 0x40) != 0)) ||
         (param_1 < 0x7f)))) || ((param_1 - 7 < 4 || (param_1 == 0xd)))) {
      _ttyoutput(param_1,iVar1);
    }
  }
  return;
}
