/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011ee2c */

short * _ifa_ifwithdstaddr(short *param_1)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _ifnet;
  do {
    if (iVar2 == 0) {
      return (short *)0x0;
    }
    if ((*(byte *)(iVar2 + 0xc) & 0x10) != 0) {
      for (psVar1 = *(short **)(iVar2 + 0x18); psVar1 != (short *)0x0;
          psVar1 = *(short **)(psVar1 + 0x12)) {
        if ((*psVar1 == *param_1) && (iVar3 = _bcmp(psVar1 + 9,param_1 + 1,0xe), iVar3 == 0)) {
          return psVar1;
        }
      }
    }
    iVar2 = *(int *)(iVar2 + 0x5c);
  } while( true );
}

