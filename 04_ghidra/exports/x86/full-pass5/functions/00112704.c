/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00112704 */

int _ptcwrite(byte param_1,int *param_2)

{
  undefined1 uVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  int local_70;
  int *local_6c;
  undefined1 local_68 [100];
  
  piVar2 = *(int **)(&DAT_001e56d0 + (uint)param_1 * 0x10);
  local_6c = (int *)*param_2;
  puVar7 = (undefined1 *)0x0;
  iVar5 = 0;
  local_70 = 0;
  pbVar3 = *(byte **)(&DAT_001e56d4 + (uint)param_1 * 0x10);
  do {
    if ((*(byte *)(piVar2 + 0x10) & 4) != 0) {
      if ((*pbVar3 & 0x20) == 0) {
        while (0 < param_2[1]) {
          local_6c = (int *)*param_2;
          if (iVar5 == 0) {
            iVar6 = local_6c[1];
            if (iVar6 != 0) {
              iVar5 = iVar6;
              if (100 < iVar6) {
                iVar5 = 100;
              }
              puVar7 = local_68;
              iVar6 = _uiomove(puVar7,iVar5,1,param_2);
              if (iVar6 != 0) {
                return iVar6;
              }
              if ((*(byte *)(piVar2 + 0x10) & 4) == 0) {
                return 5;
              }
              goto LAB_001128ab;
            }
            param_2[1] = param_2[1] + -1;
            *param_2 = *param_2 + 8;
          }
          else {
LAB_001128ab:
            for (; 0 < iVar5; iVar5 = iVar5 + -1) {
              if ((0x3fd < *piVar2 + piVar2[3]) &&
                 ((0 < piVar2[3] || ((*(byte *)(piVar2 + 0xf) & 0x22) != 0)))) {
                _wakeup(piVar2);
                goto LAB_001128c4;
              }
              uVar1 = *puVar7;
              puVar7 = puVar7 + 1;
              (*(code *)(&PTR__ttyinput_001daffc)[*(char *)((int)piVar2 + 0x47) * 0xc])
                        (uVar1,piVar2);
              local_70 = local_70 + 1;
            }
            iVar5 = 0;
          }
        }
        goto LAB_001128bf;
      }
      if (piVar2[3] == 0) break;
    }
LAB_001128c4:
    if ((*(byte *)(piVar2 + 0x10) & 0x10) == 0) {
      return 5;
    }
    if ((*pbVar3 & 4) != 0) {
      *local_6c = *local_6c - iVar5;
      local_6c[1] = local_6c[1] + iVar5;
      param_2[5] = param_2[5] + iVar5;
      param_2[2] = param_2[2] - iVar5;
      if (local_70 == 0) {
        if ((*(byte *)(*_active_u + 0x16) & 2) == 0) {
          iVar5 = 0x23;
        }
        else {
          iVar5 = 0xb;
        }
      }
      else {
LAB_001128bf:
        iVar5 = 0;
      }
      return iVar5;
    }
    _sleep((uint)(piVar2 + 1));
  } while( true );
LAB_001127e3:
  while( true ) {
    if ((param_2[1] < 1) || (0x3fe < piVar2[3])) {
      _putc(0,(FILE *)(piVar2 + 3));
      _ttwakeup(piVar2);
      _wakeup((FILE *)(piVar2 + 3));
      return 0;
    }
    iVar6 = *(int *)(*param_2 + 4);
    if (iVar6 != 0) break;
    param_2[1] = param_2[1] + -1;
    *param_2 = *param_2 + 8;
  }
  if (iVar5 == 0) {
    if (100 < iVar6) {
      iVar6 = 100;
    }
    iVar4 = 0x3ff - piVar2[3];
    iVar5 = iVar6;
    if (iVar4 < iVar6) {
      iVar5 = iVar4;
    }
    puVar7 = local_68;
    iVar6 = _uiomove(puVar7,iVar5,1,param_2);
    if (iVar6 != 0) {
      return iVar6;
    }
    if ((*(byte *)(piVar2 + 0x10) & 4) == 0) {
      return 5;
    }
    if (iVar5 != 0) goto LAB_001127d3;
  }
  else {
LAB_001127d3:
    _b_to_q(puVar7,iVar5,piVar2 + 3);
  }
  iVar5 = 0;
  goto LAB_001127e3;
}

