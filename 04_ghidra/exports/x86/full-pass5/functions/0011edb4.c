/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011edb4 */

short * _ifa_ifwithaddr(short *param_1)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  
  if (_ifnet != 0) {
    iVar3 = _ifnet;
    do {
      for (psVar1 = *(short **)(iVar3 + 0x18); psVar1 != (short *)0x0;
          psVar1 = *(short **)(psVar1 + 0x12)) {
        if (*psVar1 == *param_1) {
          iVar2 = _bcmp(psVar1 + 1,param_1 + 1,0xe);
          if (iVar2 == 0) {
            return psVar1;
          }
          if (((*(byte *)(iVar3 + 0xc) & 2) != 0) &&
             (iVar2 = _bcmp(psVar1 + 9,param_1 + 1,0xe), iVar2 == 0)) {
            return psVar1;
          }
        }
      }
      iVar3 = *(int *)(iVar3 + 0x5c);
    } while (iVar3 != 0);
  }
  return (short *)0x0;
}

