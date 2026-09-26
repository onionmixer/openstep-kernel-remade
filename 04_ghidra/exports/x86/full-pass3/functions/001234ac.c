/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001234ac */

void _in_makeaddr(uint param_1)

{
  int iVar1;
  
  for (iVar1 = _in_ifaddr;
      (iVar1 != 0 && (*(uint *)(iVar1 + 0x28) != (*(uint *)(iVar1 + 0x2c) & param_1)));
      iVar1 = *(int *)(iVar1 + 0x40)) {
  }
  return;
}

