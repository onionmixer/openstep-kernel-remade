/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001388f4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

boolean_t _xdr_bp_whoami_arg(void)

{
  boolean_t bVar1;
  XDR *in_stack_00000004;
  int *in_stack_00000008;
  
  bVar1 = _xdr_union(in_stack_00000004,in_stack_00000008,(char *)(in_stack_00000008 + 1),
                     (xdr_discrim *)&DAT_001dd4a4,(xdrproc_t)0x0);
  if (bVar1 != 0) {
    return 1;
  }
  return 0;
}

