/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00134c88 */

undefined4 FUN_00134c88(XDR *param_1,char *param_2)

{
  boolean_t bVar1;
  int iVar2;
  undefined4 uVar3;
  
  bVar1 = _xdr_opaque(param_1,param_2,0x20);
  if ((bVar1 == 0) || (iVar2 = FUN_001341f8(param_1,param_2 + 0x20), iVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

