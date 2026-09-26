/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00134b88 */

undefined4 _xdr_slargs(XDR *param_1,char *param_2)

{
  boolean_t bVar1;
  int iVar2;
  undefined4 uVar3;
  
  bVar1 = _xdr_opaque(param_1,param_2,0x20);
  if ((((((bVar1 == 0) || (bVar1 = _xdr_string(param_1,(char **)(param_2 + 0x20),0xff), bVar1 == 0))
        || (bVar1 = _xdr_string(param_1,(char **)(param_2 + 0x24),0x400), bVar1 == 0)) ||
       ((bVar1 = _xdr_u_long(param_1,(uint *)(param_2 + 0x28)), bVar1 == 0 ||
        (bVar1 = _xdr_u_long(param_1,(uint *)(param_2 + 0x2c)), bVar1 == 0)))) ||
      ((bVar1 = _xdr_u_long(param_1,(uint *)(param_2 + 0x30)), bVar1 == 0 ||
       ((bVar1 = _xdr_u_long(param_1,(uint *)(param_2 + 0x34)), bVar1 == 0 ||
        (iVar2 = FUN_00134924(param_1,param_2 + 0x38), iVar2 == 0)))))) ||
     (iVar2 = FUN_00134924(param_1,param_2 + 0x40), iVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

