/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00134b10 */

undefined4 _xdr_rnmargs(XDR *param_1,char *param_2)

{
  boolean_t bVar1;
  undefined4 uVar2;
  
  bVar1 = _xdr_opaque(param_1,param_2,0x20);
  if ((((bVar1 == 0) || (bVar1 = _xdr_string(param_1,(char **)(param_2 + 0x20),0xff), bVar1 == 0))
      || (bVar1 = _xdr_opaque(param_1,param_2 + 0x24,0x20), bVar1 == 0)) ||
     (bVar1 = _xdr_string(param_1,(char **)(param_2 + 0x44),0xff), bVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

