/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010835c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short * _crget(void)

{
  short *psVar1;
  
  psVar1 = (short *)_kalloc(0x2a);
  _bzero(psVar1,0x2a);
  *psVar1 = *psVar1 + 1;
  __cractive = __cractive + 1;
  return psVar1;
}

