/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00108434 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short * _crdup(short *param_1)

{
  short *psVar1;
  int iVar2;
  short *psVar3;
  
  psVar1 = (short *)_kalloc(0x2a);
  _bzero(psVar1,0x2a);
  *psVar1 = *psVar1 + 1;
  __cractive = __cractive + 1;
  psVar3 = psVar1;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)psVar3 = *(undefined4 *)param_1;
    param_1 = param_1 + 2;
    psVar3 = psVar3 + 2;
  }
  *psVar3 = *param_1;
  *psVar1 = 1;
  return psVar1;
}

