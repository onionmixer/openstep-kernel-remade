/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00101ff0 */

/* WARNING: Removing unreachable block (ram,0x00102064) */

int _ffs(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = 1;
  iVar2 = iVar1;
  uVar3 = param_1;
  if ((char)param_1 == '\0') {
    while( true ) {
      iVar1 = iVar2 + 8;
      param_1 = uVar3 >> 8;
      if ((char)(uVar3 >> 8) != '\0') break;
      iVar1 = iVar2 + 0x10;
      param_1 = uVar3 >> 0x10;
      if ((char)(uVar3 >> 0x10) != '\0') break;
      iVar1 = iVar2 + 0x18;
      param_1 = uVar3 >> 0x18;
      if ((char)(uVar3 >> 0x18) != '\0') break;
      iVar2 = iVar2 + 0x40;
      uVar3 = 0;
    }
  }
  for (; ((((iVar2 = iVar1, (param_1 & 1U) == 0 &&
            (iVar2 = iVar1 + 1, ((uint)param_1 >> 1 & 1) == 0)) &&
           (iVar2 = iVar1 + 2, ((uint)param_1 >> 2 & 1) == 0)) &&
          ((iVar2 = iVar1 + 3, ((uint)param_1 >> 3 & 1) == 0 &&
           (iVar2 = iVar1 + 4, ((uint)param_1 >> 4 & 1) == 0)))) &&
         ((iVar2 = iVar1 + 5, ((uint)param_1 >> 5 & 1) == 0 &&
          ((iVar2 = iVar1 + 6, ((uint)param_1 >> 6 & 1) == 0 &&
           (iVar2 = iVar1 + 7, ((uint)param_1 >> 7 & 1) == 0)))))); param_1 = (uint)param_1 >> 8) {
    iVar1 = iVar1 + 8;
  }
  return iVar2;
}

