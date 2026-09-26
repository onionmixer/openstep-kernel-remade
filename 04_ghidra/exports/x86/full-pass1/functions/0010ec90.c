/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010ec90 */

int _ttnread(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if ((*(byte *)((int)piVar1 + 0x3f) & 0x20) != 0) {
    _ttypend(piVar1);
  }
  iVar2 = piVar1[3];
  if (((*(byte *)(piVar1 + 0xf) & 0x22) != 0) &&
     (iVar2 = iVar2 + *piVar1, iVar2 < (int)(uint)*(byte *)((int)param_1 + 0x15))) {
    iVar2 = 0;
  }
  return iVar2;
}

