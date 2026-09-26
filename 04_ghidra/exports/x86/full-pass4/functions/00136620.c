/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00136620 */

boolean_t _xdr_accepted_reply(XDR *param_1,int *param_2)

{
  boolean_t bVar1;
  
  bVar1 = _xdr_enum(param_1,param_2);
  if (bVar1 == 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = _xdr_bytes(param_1,(char **)(param_2 + 1),(uint *)(param_2 + 2),400);
  }
  if ((bVar1 != 0) && (bVar1 = _xdr_enum(param_1,param_2 + 3), bVar1 != 0)) {
    if (param_2[3] == 0) {
      bVar1 = (*(code *)param_2[5])(param_1,param_2[4]);
      return bVar1;
    }
    if (param_2[3] != 2) {
      return 1;
    }
    bVar1 = _xdr_u_long(param_1,(uint *)(param_2 + 4));
    if (bVar1 != 0) {
      bVar1 = _xdr_u_long(param_1,(uint *)(param_2 + 5));
      return bVar1;
    }
  }
  return 0;
}

