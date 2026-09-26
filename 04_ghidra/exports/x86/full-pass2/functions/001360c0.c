/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001360c0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

boolean_t _xdr_pmap(void)

{
  boolean_t bVar1;
  XDR *in_stack_00000004;
  uint *in_stack_00000008;
  
  bVar1 = _xdr_u_long(in_stack_00000004,in_stack_00000008);
  if (((bVar1 != 0) && (bVar1 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 1), bVar1 != 0))
     && (bVar1 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 2), bVar1 != 0)) {
    bVar1 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 3);
    return bVar1;
  }
  return 0;
}

