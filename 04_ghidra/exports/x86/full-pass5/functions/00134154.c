/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00134154 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

boolean_t _xdr_writeargs(void)

{
  boolean_t bVar1;
  XDR *in_stack_00000004;
  char *in_stack_00000008;
  
  bVar1 = _xdr_opaque(in_stack_00000004,in_stack_00000008,0x20);
  if ((((bVar1 != 0) &&
       (bVar1 = _xdr_long(in_stack_00000004,(int *)(in_stack_00000008 + 0x20)), bVar1 != 0)) &&
      (bVar1 = _xdr_long(in_stack_00000004,(int *)(in_stack_00000008 + 0x24)), bVar1 != 0)) &&
     (bVar1 = _xdr_long(in_stack_00000004,(int *)(in_stack_00000008 + 0x28)), bVar1 != 0)) {
    if ((in_stack_00000004->x_ops == (xdr_ops *)&_xdrmbuf_ops) &&
       (in_stack_00000004->x_op == XDR_DECODE)) {
      bVar1 = _xdrmbuf_getmbuf();
    }
    else {
      bVar1 = _xdr_bytes(in_stack_00000004,(char **)(in_stack_00000008 + 0x30),
                         (uint *)(in_stack_00000008 + 0x2c),0x2000);
    }
    if (bVar1 != 0) {
      return 1;
    }
  }
  return 0;
}

