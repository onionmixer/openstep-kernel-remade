/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001214c8 */

undefined4 _raw_bind(int param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  ushort *puVar3;
  
  puVar3 = (ushort *)(param_2 + *(int *)(param_2 + 4));
  if (_ifnet != 0) {
    if ((3 < *puVar3) || (*puVar3 < 2)) {
      return 0x2f;
    }
    if ((*(int *)(puVar3 + 2) == 0) || (iVar2 = _ifa_ifwithaddr(puVar3), iVar2 != 0)) {
      iVar2 = *(int *)(param_1 + 8);
      _bcopy(puVar3,(void *)(iVar2 + 0x1c),0x10);
      pbVar1 = (byte *)(iVar2 + 0x4c);
      *pbVar1 = *pbVar1 | 1;
      return 0;
    }
  }
  return 0x31;
}

