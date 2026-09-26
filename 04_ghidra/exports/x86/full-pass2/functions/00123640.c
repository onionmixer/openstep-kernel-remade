/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00123640 */

undefined4 _in_localaddr(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1 >> 0x18 | (param_1 & 0xff0000) >> 8 | (param_1 & 0xff00) << 8 | param_1 << 0x18;
  iVar1 = _in_ifaddr;
  if (_subnetsarelocal == 0) {
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x40)) {
      if (*(uint *)(iVar1 + 0x30) == (uVar2 & *(uint *)(iVar1 + 0x34))) {
        return 1;
      }
    }
  }
  else {
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x40)) {
      if (*(uint *)(iVar1 + 0x28) == (uVar2 & *(uint *)(iVar1 + 0x2c))) {
        return 1;
      }
    }
  }
  return 0;
}

