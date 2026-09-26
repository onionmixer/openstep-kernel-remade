/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b31c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _dnlc_enter(int param_1,char *param_2,int param_3,short *param_4)

{
  size_t sVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  
  if (_doingcache != 0) {
    uVar6 = 0xffffffff;
    pcVar7 = param_2;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    sVar1 = ~uVar6 - 1;
    if ((int)sVar1 < 0x21) {
      uVar6 = (int)*param_2 + (int)param_2[~uVar6 - 2] + sVar1 + param_1 & 0x3f;
      iVar5 = FUN_0011b8dc(param_1,param_2,sVar1,uVar6,param_4);
      piVar3 = DAT_001e9be8;
      if (iVar5 == 0) {
        if (DAT_001e9be8 == (int *)&_nc_lru) {
          _DAT_001e9c18 = _DAT_001e9c18 + 1;
        }
        else {
          *(int *)(DAT_001e9be8[3] + 8) = DAT_001e9be8[2];
          *(int *)(piVar3[2] + 0xc) = piVar3[3];
          *(int *)(*piVar3 + 4) = piVar3[1];
          *(int *)piVar3[1] = *piVar3;
          if (piVar3[5] != 0) {
            if (piVar3[4] != 0) {
              _DAT_001e9c20 = _DAT_001e9c20 + -1;
            }
            if (piVar3[5] != 0) {
              _vn_rele(piVar3[5]);
            }
          }
          if (piVar3[4] != 0) {
            _vn_rele(piVar3[4]);
          }
          if (piVar3[0xf] != 0) {
            _crfree(piVar3[0xf]);
          }
          if ((char)piVar3[0x11] != '\0') {
            _kfree(piVar3[0x10],(int)*(short *)((int)piVar3 + 0x46));
          }
          piVar3[5] = param_1;
          *(short *)(param_1 + 6) = *(short *)(param_1 + 6) + 1;
          piVar3[4] = param_3;
          *(short *)(param_3 + 6) = *(short *)(param_3 + 6) + 1;
          *(char *)(piVar3 + 6) = (char)sVar1;
          _bcopy(param_2,(undefined *)((int)piVar3 + 0x19),sVar1);
          *(undefined1 *)(piVar3 + 0x11) = 0;
          *(undefined2 *)((int)piVar3 + 0x46) = 0;
          piVar3[0x10] = 0;
          piVar3[0xf] = (int)param_4;
          if (param_4 != (short *)0x0) {
            *param_4 = *param_4 + 1;
          }
          iVar4 = DAT_001e9bec;
          iVar5 = *(int *)(DAT_001e9bec + 8);
          *(int **)(DAT_001e9bec + 8) = piVar3;
          piVar3[2] = iVar5;
          *(int **)(iVar5 + 0xc) = piVar3;
          piVar3[3] = iVar4;
          *piVar3 = (&_nc_hash)[uVar6 * 2];
          piVar3[1] = (int)(&_nc_hash + uVar6 * 2);
          *(int **)((&_nc_hash)[uVar6 * 2] + 4) = piVar3;
          (&_nc_hash)[uVar6 * 2] = piVar3;
          _DAT_001e9c20 = _DAT_001e9c20 + 1;
          _DAT_001e9c08 = _DAT_001e9c08 + 1;
        }
      }
      else {
        _DAT_001e9c0c = _DAT_001e9c0c + 1;
      }
    }
    else {
      _DAT_001e9c10 = _DAT_001e9c10 + 1;
    }
  }
  return;
}

