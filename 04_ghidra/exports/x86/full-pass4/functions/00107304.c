/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107304 */

int _spgrp(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar1 = param_1;
  do {
    do {
      iVar3 = iVar1;
      *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) & 0xffcdffff;
      iVar2 = iVar2 + 1;
      iVar1 = *(int *)(iVar3 + 0x48);
    } while (*(int *)(iVar3 + 0x48) != 0);
    while( true ) {
      if (iVar3 == param_1) {
        return iVar2;
      }
      iVar1 = *(int *)(iVar3 + 0x4c);
      if (*(int *)(iVar3 + 0x4c) != 0) break;
      iVar3 = *(int *)(iVar3 + 0x44);
    }
  } while( true );
}

