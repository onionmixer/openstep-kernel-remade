/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001365cc */

boolean_t _xdr_opaque_auth(XDR *param_1,int *param_2)

{
  boolean_t bVar1;
  
  bVar1 = _xdr_enum(param_1,param_2);
  if (bVar1 == 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = _xdr_bytes(param_1,(char **)(param_2 + 1),(uint *)(param_2 + 2),400);
  }
  return bVar1;
}

