/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cffec */

int FUN_001cffec(int param_1)

{
  int iVar1;
  
  iVar1 = __objc_create_zone();
  iVar1 = (**(code **)(iVar1 + 4))(iVar1,param_1);
  if ((iVar1 == 0) && (param_1 != 0)) {
    __objc_fatal("unable to allocate space");
  }
  return iVar1;
}

