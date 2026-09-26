/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012359c */

uint _in_lnaof(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = (param_1 & 0xff0000) >> 8;
  uVar1 = param_1 >> 0x18 | uVar2;
  uVar3 = (param_1 & 0xff00) << 8;
  uVar6 = uVar1 | uVar3;
  uVar5 = param_1 << 0x18;
  iVar4 = _in_ifaddr;
  if ((int)(uVar6 | uVar5) < 0) {
    if ((uVar5 & 0xc0000000) == 0x80000000) {
      uVar6 = uVar1;
      uVar5 = uVar3 | uVar5;
    }
    else if ((uVar5 & 0xe0000000) == 0xc0000000) {
      uVar6 = param_1 >> 0x18;
      uVar5 = uVar2 | uVar3 | uVar5;
    }
    else {
      if ((uVar5 & 0xf0000000) != 0xe0000000) {
        return uVar6 | uVar5;
      }
      uVar6 = uVar6 | uVar5 & 0xfffffff;
      uVar5 = 0xe0000000;
    }
  }
  while( true ) {
    if (iVar4 == 0) {
      return uVar6;
    }
    if (*(uint *)(iVar4 + 0x28) == uVar5) break;
    iVar4 = *(int *)(iVar4 + 0x40);
  }
  return ~*(uint *)(iVar4 + 0x34) & uVar6;
}

