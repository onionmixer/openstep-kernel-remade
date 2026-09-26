/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001361f4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

boolean_t _xdr_rmtcallres(void)

{
  boolean_t bVar1;
  XDR *in_stack_00000004;
  undefined4 *in_stack_00000008;
  char *local_8;
  
  local_8 = (char *)*in_stack_00000008;
  bVar1 = _xdr_reference(in_stack_00000004,&local_8,4,_xdr_u_long);
  if ((bVar1 != 0) && (bVar1 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 1), bVar1 != 0)) {
    *in_stack_00000008 = local_8;
    bVar1 = (*(code *)in_stack_00000008[3])();
    return bVar1;
  }
  return 0;
}

