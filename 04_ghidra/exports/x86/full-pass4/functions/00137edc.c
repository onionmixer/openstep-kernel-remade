/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00137edc */

boolean_t _xdr_netobj(XDR *param_1,netobj *param_2)

{
  boolean_t bVar1;
  
  bVar1 = _xdr_bytes(param_1,&param_2->n_bytes,&param_2->n_len,0x400);
  return bVar1;
}

