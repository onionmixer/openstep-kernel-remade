/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00136a6c */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

boolean_t _xdr_callhdr(void)

{
  boolean_t bVar1;
  XDR *in_stack_00000004;
  uint *in_stack_00000008;
  
  in_stack_00000008[1] = 0;
  in_stack_00000008[2] = 2;
  if ((((in_stack_00000004->x_op == XDR_ENCODE) &&
       (bVar1 = _xdr_u_long(in_stack_00000004,in_stack_00000008), bVar1 != 0)) &&
      (bVar1 = _xdr_enum(in_stack_00000004,(int *)(in_stack_00000008 + 1)), bVar1 != 0)) &&
     ((bVar1 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 2), bVar1 != 0 &&
      (bVar1 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 3), bVar1 != 0)))) {
    bVar1 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 4);
    return bVar1;
  }
  return 0;
}

