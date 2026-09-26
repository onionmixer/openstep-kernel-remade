/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00138868 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

boolean_t _xdr_ip_addr_t(void)

{
  boolean_t bVar1;
  XDR *in_stack_00000004;
  char *in_stack_00000008;
  
  bVar1 = _xdr_char(in_stack_00000004,in_stack_00000008);
  if ((((bVar1 != 0) && (bVar1 = _xdr_char(in_stack_00000004,in_stack_00000008 + 1), bVar1 != 0)) &&
      (bVar1 = _xdr_char(in_stack_00000004,in_stack_00000008 + 2), bVar1 != 0)) &&
     (bVar1 = _xdr_char(in_stack_00000004,in_stack_00000008 + 3), bVar1 != 0)) {
    return 1;
  }
  return 0;
}

