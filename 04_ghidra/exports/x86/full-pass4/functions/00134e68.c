/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00134e68 */

undefined4 FUN_00134e68(XDR *param_1,uint *param_2)

{
  boolean_t bVar1;
  
  bVar1 = _xdr_bytes(param_1,(char **)(param_2 + 1),param_2,0x400);
  if (bVar1 == 0) {
    return 0;
  }
  return 1;
}

