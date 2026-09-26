/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011ee90 */

ushort * _ifa_ifwithnet(ushort *param_1)

{
  code *pcVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  
  if (*param_1 < 0x11) {
    pcVar1 = (code *)(&PTR__null_netmatch_001db794)[(uint)*param_1 * 2];
    for (iVar3 = _ifnet; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x5c)) {
      for (puVar2 = *(ushort **)(iVar3 + 0x18); puVar2 != (ushort *)0x0;
          puVar2 = *(ushort **)(puVar2 + 0x12)) {
        if ((*puVar2 == *param_1) && (iVar4 = (*pcVar1)(puVar2,param_1), iVar4 != 0)) {
          return puVar2;
        }
      }
    }
  }
  return (ushort *)0x0;
}

