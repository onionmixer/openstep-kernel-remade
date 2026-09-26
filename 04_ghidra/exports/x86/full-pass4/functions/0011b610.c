/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b610 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _dnlc_lookup(int param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  char *pcVar7;
  
  if (_doingcache == 0) {
    iVar4 = 0;
  }
  else {
    uVar6 = 0xffffffff;
    pcVar7 = param_2;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    iVar4 = ~uVar6 - 1;
    if (iVar4 < 0x21) {
      uVar6 = (int)*param_2 + (int)param_2[~uVar6 - 2] + iVar4 + param_1 & 0x3f;
      piVar5 = (int *)FUN_0011b8dc(param_1,param_2,iVar4,uVar6,param_3);
      if (piVar5 == (int *)0x0) {
        _DAT_001e9c04 = _DAT_001e9c04 + 1;
        iVar4 = 0;
      }
      else {
        __ncstats = __ncstats + 1;
        *(int *)(piVar5[3] + 8) = piVar5[2];
        *(int *)(piVar5[2] + 0xc) = piVar5[3];
        iVar3 = DAT_001e9bec;
        iVar4 = *(int *)(DAT_001e9bec + 8);
        *(int **)(DAT_001e9bec + 8) = piVar5;
        piVar5[2] = iVar4;
        *(int **)(iVar4 + 0xc) = piVar5;
        piVar5[3] = iVar3;
        if ((undefined4 *)piVar5[1] != &_nc_hash + uVar6 * 2) {
          *(undefined4 **)(*piVar5 + 4) = (undefined4 *)piVar5[1];
          *(int *)piVar5[1] = *piVar5;
          piVar2 = *(int **)(piVar5[1] + 4);
          *piVar5 = *piVar2;
          piVar5[1] = (int)piVar2;
          *(int **)(*piVar2 + 4) = piVar5;
          *piVar2 = (int)piVar5;
        }
        iVar4 = piVar5[4];
      }
    }
    else {
      _DAT_001e9c14 = _DAT_001e9c14 + 1;
      iVar4 = 0;
    }
  }
  return iVar4;
}

