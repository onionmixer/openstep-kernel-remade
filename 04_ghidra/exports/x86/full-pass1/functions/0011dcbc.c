/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011dcbc */

int _fdsetattr(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int local_8;
  
  iVar1 = _getvnodefp(param_1,&local_8);
  if (iVar1 == 0) {
    iVar1 = *(int *)(local_8 + 0x18);
    if ((*(byte *)(*(int *)(iVar1 + 0x24) + 0xc) & 1) == 0) {
      iVar1 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x18))
                        (iVar1,param_2,*(undefined4 *)(local_8 + 0x20));
    }
    else {
      iVar1 = 0x1e;
    }
  }
  return iVar1;
}

