/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00134aac */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

boolean_t _xdr_linkargs(void)

{
  boolean_t bVar1;
  XDR *in_stack_00000004;
  char *in_stack_00000008;
  
  bVar1 = _xdr_opaque(in_stack_00000004,in_stack_00000008,0x20);
  if (((bVar1 == 0) ||
      (bVar1 = _xdr_opaque(in_stack_00000004,in_stack_00000008 + 0x20,0x20), bVar1 == 0)) ||
     (bVar1 = _xdr_string(in_stack_00000004,(char **)(in_stack_00000008 + 0x40),0xff), bVar1 == 0))
  {
    bVar1 = 0;
  }
  else {
    bVar1 = 1;
  }
  return bVar1;
}

