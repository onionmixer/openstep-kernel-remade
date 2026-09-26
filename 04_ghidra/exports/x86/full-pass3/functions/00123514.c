/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00123514 */

uint _in_netof(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = (param_1 & 0xff0000) >> 8;
  uVar2 = (param_1 & 0xff00) << 8;
  uVar4 = param_1 << 0x18;
  uVar5 = param_1 >> 0x18 | uVar1 | uVar2 | uVar4;
  iVar3 = _in_ifaddr;
  if ((int)uVar5 < 0) {
    if ((uVar4 & 0xc0000000) == 0x80000000) {
      uVar4 = uVar2 | uVar4;
    }
    else if ((uVar4 & 0xe0000000) == 0xc0000000) {
      uVar4 = uVar1 | uVar2 | uVar4;
    }
    else {
      if ((uVar4 & 0xf0000000) != 0xe0000000) {
        return 0;
      }
      uVar4 = 0xe0000000;
    }
  }
  while( true ) {
    if (iVar3 == 0) {
      return uVar4;
    }
    if (*(uint *)(iVar3 + 0x28) == uVar4) break;
    iVar3 = *(int *)(iVar3 + 0x40);
  }
  return uVar5 & *(uint *)(iVar3 + 0x34);
}

