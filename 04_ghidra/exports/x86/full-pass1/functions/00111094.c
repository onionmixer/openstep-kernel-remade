/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00111094 */

void _ttyecho(uint param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if ((*(byte *)(iVar1 + 0x42) & 0x20) == 0) {
    *(uint *)(iVar1 + 0x3c) = *(uint *)(iVar1 + 0x3c) & 0xff7fffff;
  }
  if ((((*(uint *)(iVar1 + 0x3c) & 8) != 0) ||
      (((*(byte *)(param_2 + 4) & 2) != 0 && (param_1 == 10)))) &&
     ((*(byte *)(iVar1 + 0x42) & 0x40) == 0)) {
    if (((*(uint *)(iVar1 + 0x3c) & 0x10000000) != 0) &&
       ((((param_1 & 0xff) < 0x20 && (1 < param_1 - 9)) || ((param_1 & 0xff) == 0x7f)))) {
      _ttyoutput(0x5e,iVar1);
      param_1 = param_1 & 0xff;
      if (param_1 == 0x7f) {
        param_1 = 0x3f;
      }
      else if ((*(byte *)(iVar1 + 0x3c) & 4) == 0) {
        param_1 = param_1 + 0x40;
      }
      else {
        param_1 = param_1 + 0x60;
      }
    }
    param_1 = param_1 & 0xff;
    if (((0x1f < param_1) &&
        ((((*(byte *)(iVar1 + 0x3f) & 8) != 0 || ((*(byte *)((int)param_2 + 0x12) & 0x40) != 0)) ||
         (param_1 < 0x7f)))) || ((param_1 - 7 < 4 || (param_1 == 0xd)))) {
      _ttyoutput(param_1,iVar1);
    }
  }
  return;
}

