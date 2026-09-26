/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00138a90 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

boolean_t _xdr_fhstatus(void)

{
  boolean_t bVar1;
  XDR *in_stack_00000004;
  int *in_stack_00000008;
  
  bVar1 = _xdr_int(in_stack_00000004,in_stack_00000008);
  if (bVar1 == 0) {
LAB_00138abc:
    bVar1 = 0;
  }
  else {
    if (*in_stack_00000008 == 0) {
      bVar1 = _xdr_fhandle();
      if (bVar1 == 0) goto LAB_00138abc;
    }
    bVar1 = 1;
  }
  return bVar1;
}

