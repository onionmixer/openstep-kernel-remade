
int sub_4065C02(int *param_1,int *param_2)

{
  int iVar1;
  sword sVar2;
  undefined2 uVar3;
  undefined4 in_D0;
  int iVar4;
  int iVar5;
  int *piVar6;
  sword *psVar7;
  sword *psVar8;
  word *pwVar9;
  void **ppvVar10;
  int *piVar11;
  int *piVar12;
  undefined4 *puVar13;
  int *piVar14;
  int *piVar15;
  char in_XF;
  bool bVar16;
  bool bVar17;
  
  puVar13 = &_pseudo_inits;
  if (off_40B30C8 != (void *)0x0) {
    ppvVar10 = &off_40B30C8;
    do {
      in_D0 = (**ppvVar10)(*puVar13);
      ppvVar10 = ppvVar10 + 2;
      puVar13 = puVar13 + 2;
    } while (*ppvVar10 != (void *)0x0);
  }
  uVar3 = (undefined2)((uint)in_D0 >> 0x10);
  bVar16 = (int)param_1 < 0;
  bVar17 = param_1 == (int *)0x0;
  if (!bVar17) {
    piVar11 = param_1 + 6;
    piVar14 = param_1;
    do {
      uVar3 = (undefined2)((uint)in_D0 >> 0x10);
      iVar5 = *piVar14;
      bVar16 = iVar5 < 0;
      bVar17 = true;
      if (iVar5 == 0) break;
      piVar14[7] = (int)piVar11;
      *piVar11 = (int)piVar11;
      if (*(code **)(iVar5 + 0x18) != (code *)0x0) {
        in_D0 = (**(code **)(iVar5 + 0x18))(piVar14[2]);
      }
      uVar3 = (undefined2)((uint)in_D0 >> 0x10);
      piVar11 = (int *)((int)piVar11 + 0x26);
      piVar14 = (int *)((int)piVar14 + 0x26);
      bVar16 = (int)piVar14 < 0;
      bVar17 = piVar14 == (int *)0x0;
    } while (!bVar17);
  }
  iVar5 = CONCAT22(uVar3,(word)(byte)(in_XF << 4 | bVar16 << 3 | bVar17 << 2));
  if (param_1 != (int *)0x0) {
    piVar11 = param_1 + 1;
    piVar14 = param_1 + 2;
    do {
      iVar1 = *param_1;
      if (iVar1 == 0) break;
      iVar4 = _map_addr(*piVar14,*(undefined4 *)(iVar1 + 0x1c));
      if (iVar4 != 0) {
        *piVar14 = iVar4;
      }
      *(int **)(*(int *)(iVar1 + 0x2c) + *(sword *)piVar11 * 4) = param_1;
      param_1[3] = (int)_bus_hd;
      iVar5 = _dev_find(*piVar14,(int)*(sword *)piVar11,(int)*(sword *)((int)param_1 + 6),iVar1,
                        *(undefined4 *)(iVar1 + 0x28));
      *piVar14 = iVar5;
      if (iVar5 == 0) {
        if (iVar4 != 0) {
          iVar5 = _kmem_free(_kernel_map,iVar4,*(undefined4 *)(iVar1 + 0x1c));
        }
      }
      else {
        *(undefined2 *)(param_1 + 9) = 1;
        if (param_2 != (int *)0x0) {
          piVar6 = param_2 + 1;
          pwVar9 = (word *)(param_2 + 2);
          piVar15 = param_2 + 3;
          psVar7 = (sword *)((int)param_2 + 0x1a);
          psVar8 = (sword *)((int)param_2 + 6);
          piVar12 = param_2;
          do {
            iVar5 = *piVar12;
            if (iVar5 == 0) break;
            if ((iVar1 == iVar5) && (*psVar7 == 0)) {
              sVar2 = *psVar8;
              iVar5 = CONCAT22((sword)((uint)iVar5 >> 0x10),sVar2);
              if ((sVar2 == *(sword *)piVar11) || (sVar2 == 0x3f)) {
                *psVar8 = *(sword *)piVar11;
                *(undefined **)((int)piVar12 + 0x26) = _bus_hd;
                *(int *)((int)piVar12 + 0x12) = *piVar14;
                *(int **)((int)piVar12 + 0x22) = param_1;
                if (*(int *)(iVar1 + 0x24) != 0) {
                  *(int **)(*(int *)(iVar1 + 0x24) + *(sword *)piVar6 * 4) = piVar12;
                }
                iVar4 = (**(code **)(iVar1 + 4))(piVar12,*piVar14);
                iVar5 = 0;
                if (iVar4 != 0) {
                  *psVar7 = 1;
                  if ((*(sword *)piVar15 == 0) || (3 < _dkn)) {
                    *(undefined2 *)piVar15 = 0xffff;
                  }
                  else {
                    *(undefined2 *)piVar15 = _dkn._2_2_;
                    _dkn = _dkn + 1;
                  }
                  if ((*(byte *)(iVar1 + 0x31) & 2) == 0) {
                    iVar5 = _printf(aSDAtSDSlaveD,*(undefined4 *)(iVar1 + 0x20),
                                    (int)*(sword *)piVar6,*(undefined4 *)(iVar1 + 0x28),
                                    (int)*(sword *)piVar11,(int)(sword)*pwVar9);
                  }
                  else {
                    iVar5 = _printf(aSDAtSDTargetDL,*(undefined4 *)((int)piVar12 + 0x16),
                                    (int)*(sword *)piVar6,*(undefined4 *)(iVar1 + 0x28),
                                    (int)*(sword *)piVar11,(*pwVar9 & 0x7f) >> 4,*pwVar9 & 7);
                  }
                  if (*(code **)(iVar1 + 8) != (code *)0x0) {
                    iVar5 = (**(code **)(iVar1 + 8))(piVar12);
                  }
                }
              }
            }
            piVar6 = (int *)((int)piVar6 + 0x2a);
            pwVar9 = pwVar9 + 0x15;
            piVar15 = (int *)((int)piVar15 + 0x2a);
            psVar7 = psVar7 + 0x15;
            psVar8 = psVar8 + 0x15;
            piVar12 = (int *)((int)piVar12 + 0x2a);
          } while (piVar12 != (int *)0x0);
        }
      }
      piVar11 = (int *)((int)piVar11 + 0x26);
      piVar14 = (int *)((int)piVar14 + 0x26);
      param_1 = (int *)((int)param_1 + 0x26);
    } while (param_1 != (int *)0x0);
  }
  if (param_2 != (int *)0x0) {
    psVar7 = (sword *)((int)param_2 + 0x1a);
    piVar11 = (int *)((int)param_2 + 0x12);
    piVar14 = param_2 + 1;
    do {
      iVar1 = *param_2;
      if (iVar1 == 0) {
        return iVar5;
      }
      if ((*psVar7 == 0) && (*(sword *)(param_2 + 2) == -1)) {
        iVar4 = _map_addr(*piVar11,*(undefined4 *)(iVar1 + 0x1c));
        if (iVar4 != 0) {
          *piVar11 = iVar4;
        }
        *(undefined2 *)(param_2 + 3) = 0xffff;
        if (*(int *)(iVar1 + 0x24) != 0) {
          *(int **)(*(int *)(iVar1 + 0x24) + *(sword *)piVar14 * 4) = param_2;
        }
        iVar5 = _dev_find(*piVar11,(int)*(sword *)piVar14,(int)*(char *)((int)param_2 + 10),iVar1,
                          *(undefined4 *)(iVar1 + 0x20));
        *piVar11 = iVar5;
        if (iVar5 == 0) {
          if (iVar4 != 0) {
            iVar5 = _kmem_free(_kernel_map,iVar4,*(undefined4 *)(iVar1 + 0x1c));
          }
        }
        else {
          *psVar7 = 1;
          if (*(code **)(iVar1 + 8) != (code *)0x0) {
            iVar5 = (**(code **)(iVar1 + 8))(param_2);
          }
        }
      }
      psVar7 = psVar7 + 0x15;
      piVar11 = (int *)((int)piVar11 + 0x2a);
      piVar14 = (int *)((int)piVar14 + 0x2a);
      param_2 = (int *)((int)param_2 + 0x2a);
    } while (param_2 != (int *)0x0);
  }
  return iVar5;
}

