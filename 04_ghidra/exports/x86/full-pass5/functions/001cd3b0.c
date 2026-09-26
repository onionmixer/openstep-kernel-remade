/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cd3b0 */

int FUN_001cd3b0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = __objc_create_zone();
  uVar2 = __objc_create_zone(param_1);
  iVar1 = (**(code **)(iVar1 + 4))(uVar2);
  if ((iVar1 == 0) && (param_1 != 0)) {
    __objc_fatal("unable to allocate space");
  }
  return iVar1;
}

