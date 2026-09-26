/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00137b88 */

boolean_t _xdr_char(XDR *param_1,char *param_2)

{
  boolean_t bVar1;
  int local_8;
  
  local_8 = (int)*param_2;
  bVar1 = _xdr_long(param_1,&local_8);
  if (bVar1 != 0) {
    *param_2 = (char)local_8;
  }
  return (uint)(bVar1 != 0);
}

