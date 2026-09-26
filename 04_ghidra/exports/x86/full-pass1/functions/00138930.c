/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00138930 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

boolean_t _xdr_bp_whoami_res(void)

{
  boolean_t bVar1;
  XDR *in_stack_00000004;
  char **in_stack_00000008;
  
  bVar1 = _xdr_string(in_stack_00000004,in_stack_00000008,0xff);
  if (((bVar1 == 0) ||
      (bVar1 = _xdr_string(in_stack_00000004,in_stack_00000008 + 1,0xff), bVar1 == 0)) ||
     (bVar1 = _xdr_union(in_stack_00000004,(int *)(in_stack_00000008 + 2),
                         (char *)(in_stack_00000008 + 3),(xdr_discrim *)&DAT_001dd4a4,(xdrproc_t)0x0
                        ), bVar1 == 0)) {
    bVar1 = 0;
  }
  else {
    bVar1 = 1;
  }
  return bVar1;
}

