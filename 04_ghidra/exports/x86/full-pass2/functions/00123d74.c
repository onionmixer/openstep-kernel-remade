/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00123d74 */

undefined4 _in_broadcast(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = _in_ifaddr;
  do {
    if (iVar1 == 0) {
      if ((param_1 != 0xffffffff) && (param_1 != 0)) {
        return 0;
      }
      return 1;
    }
    if ((*(byte *)(*(int *)(iVar1 + 0x20) + 0xc) & 2) != 0) {
      if (*(uint *)(iVar1 + 0x14) == param_1) {
        return 1;
      }
      uVar2 = param_1 >> 0x18 | (param_1 & 0xff0000) >> 8 | (param_1 & 0xff00) << 8 |
              param_1 << 0x18;
      if (*(uint *)(iVar1 + 0x30) == uVar2) {
        return 1;
      }
      if (*(uint *)(iVar1 + 0x28) == uVar2) {
        return 1;
      }
    }
    iVar1 = *(int *)(iVar1 + 0x40);
  } while( true );
}

