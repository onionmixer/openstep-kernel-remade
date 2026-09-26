
int sub_4084026(int param_1)

{
  int *piVar1;
  int *piVar2;
  byte bVar3;
  byte bVar4;
  int *piVar5;
  int iVar6;
  undefined2 uVar7;
  undefined2 extraout_D0u;
  undefined2 extraout_D0u_00;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  word wVar12;
  int iVar13;
  sword sVar14;
  byte *pbVar15;
  byte *pbVar16;
  word *pwVar17;
  word *pwVar18;
  bool bVar19;
  
  piVar5 = (int *)(param_1 + 0x3e);
  iVar8 = _curipl();
  iVar6 = dword_40B21CC;
  if (iVar8 != dword_40B21CC) {
    dword_40B21CC = _curipl();
    uVar7 = (undefined2)((uint)dword_40B21CC >> 0x10);
    if (*(char *)(param_1 + 0x53) == '\x01') {
      piVar1 = (int *)*piVar5;
      while (bVar19 = piVar5 < piVar1, piVar5 != piVar1) {
        iVar8 = *piVar5;
        pbVar9 = *(byte **)(iVar8 + 0x10);
        if (*(byte **)(iVar8 + 0x14) == pbVar9) {
          piVar1 = *(int **)(iVar8 + 0x2c);
          piVar2 = *(int **)(iVar8 + 0x30);
          if (piVar1 == piVar5) {
            *(int **)(param_1 + 0x42) = piVar2;
          }
          else {
            piVar1[0xc] = (int)piVar2;
          }
          if (piVar2 == piVar5) {
            *piVar5 = (int)piVar1;
          }
          else {
            piVar2[0xb] = (int)piVar1;
          }
          *(int *)(param_1 + 0x26) = *(int *)(iVar8 + 4) + *(int *)(param_1 + 0x26);
          if (piVar5 == (int *)*piVar5) {
            *(uint *)(iVar8 + 0x34) = *(uint *)(iVar8 + 0x34) | 1;
          }
          (**(code **)(iVar8 + 0x28))(iVar8);
          uVar7 = extraout_D0u;
        }
        else {
          iVar13 = (int)*(byte **)(iVar8 + 0x14) - (int)pbVar9;
          if (0x100 < iVar13) {
            iVar13 = 0x100;
          }
          iVar13 = iVar13 + -1;
          pbVar16 = pbVar9;
          if (iVar13 != -1) {
            do {
              pbVar15 = pbVar16 + 1;
              bVar3 = *pbVar16;
              iVar10 = 0x32;
              bVar4 = *(byte *)(_slot_id_bmap + 0x2008002);
              pbVar9 = (byte *)CONCAT31((int3)((uint)pbVar9 >> 8),bVar4);
              while ((bVar4 & 2) == 0) {
                pbVar9 = (byte *)_delay(2);
                iVar10 = iVar10 + -1;
                if (iVar10 == 0) goto loc_4084176;
                bVar4 = *(byte *)(_slot_id_bmap + 0x2008002);
                pbVar9 = (byte *)CONCAT31((int3)((uint)pbVar9 >> 8),bVar4);
              }
              if (iVar10 != 0) {
                if (_cpu_type == '\0') {
                  *(uint *)(_slot_id_bmap + 0x2008004) = (uint)bVar3;
                }
                else {
                  *(undefined *)(_slot_id_bmap + 0x2008005) = 0;
                  pbVar9 = (byte *)0x0;
                  *(undefined *)(_slot_id_bmap + 0x2008006) = 0;
                  *(byte *)(_slot_id_bmap + 0x2008007) = bVar3;
                }
              }
loc_4084176:
              if (iVar10 == 0) break;
              wVar12 = (word)((uint)iVar13 >> 0x10);
              sVar14 = (sword)iVar13 + -1;
              iVar13 = CONCAT22(wVar12,sVar14);
              pbVar16 = pbVar15;
            } while ((sVar14 != -1) || (iVar13 = (uint)wVar12 * 0x10000 + -1, wVar12 != 0));
          }
          uVar7 = (undefined2)((uint)pbVar9 >> 0x10);
          bVar19 = pbVar16 < *(byte **)(iVar8 + 0x10);
          if (pbVar16 == *(byte **)(iVar8 + 0x10)) break;
          *(byte **)(iVar8 + 0x10) = pbVar16;
        }
        piVar1 = (int *)*piVar5;
      }
    }
    else {
      piVar1 = (int *)*piVar5;
      while (bVar19 = piVar5 < piVar1, piVar5 != piVar1) {
        iVar8 = *piVar5;
        pwVar18 = *(word **)(iVar8 + 0x10);
        if (*(word **)(iVar8 + 0x14) == pwVar18) {
          piVar1 = *(int **)(iVar8 + 0x2c);
          piVar2 = *(int **)(iVar8 + 0x30);
          if (piVar1 == piVar5) {
            *(int **)(param_1 + 0x42) = piVar2;
          }
          else {
            piVar1[0xc] = (int)piVar2;
          }
          if (piVar2 == piVar5) {
            *piVar5 = (int)piVar1;
          }
          else {
            piVar2[0xb] = (int)piVar1;
          }
          *(int *)(param_1 + 0x26) = *(int *)(iVar8 + 4) + *(int *)(param_1 + 0x26);
          if (piVar5 == (int *)*piVar5) {
            *(uint *)(iVar8 + 0x34) = *(uint *)(iVar8 + 0x34) | 1;
          }
          (**(code **)(iVar8 + 0x28))(iVar8);
          uVar7 = extraout_D0u_00;
        }
        else {
          iVar13 = (int)*(word **)(iVar8 + 0x14) - (int)pwVar18;
          iVar10 = iVar13 >> 1;
          if (0x40 < iVar10) {
            iVar10 = 0x40;
          }
          iVar10 = iVar10 + -1;
          if (iVar10 != -1) {
            do {
              pwVar17 = pwVar18 + 1;
              wVar12 = *pwVar18;
              iVar11 = 0x32;
              bVar3 = *(byte *)(_slot_id_bmap + 0x2008002);
              iVar13 = CONCAT31((int3)((uint)iVar13 >> 8),bVar3);
              while ((bVar3 & 2) == 0) {
                iVar13 = _delay(2);
                iVar11 = iVar11 + -1;
                if (iVar11 == 0) goto loc_40842B2;
                bVar3 = *(byte *)(_slot_id_bmap + 0x2008002);
                iVar13 = CONCAT31((int3)((uint)iVar13 >> 8),bVar3);
              }
              if (iVar11 != 0) {
                if (_cpu_type == '\0') {
                  *(uint *)(_slot_id_bmap + 0x2008004) = (uint)wVar12;
                }
                else {
                  *(undefined *)(_slot_id_bmap + 0x2008005) = 0;
                  iVar13 = 0;
                  *(char *)(_slot_id_bmap + 0x2008006) = (char)(wVar12 >> 8);
                  *(char *)(_slot_id_bmap + 0x2008007) = (char)wVar12;
                }
              }
loc_40842B2:
              if (iVar11 == 0) break;
              wVar12 = (word)((uint)iVar10 >> 0x10);
              sVar14 = (sword)iVar10 + -1;
              iVar10 = CONCAT22(wVar12,sVar14);
              pwVar18 = pwVar17;
            } while ((sVar14 != -1) || (iVar10 = (uint)wVar12 * 0x10000 + -1, wVar12 != 0));
          }
          uVar7 = (undefined2)((uint)iVar13 >> 0x10);
          bVar19 = pwVar18 < *(word **)(iVar8 + 0x10);
          if (pwVar18 == *(word **)(iVar8 + 0x10)) break;
          *(word **)(iVar8 + 0x10) = pwVar18;
        }
        piVar1 = (int *)*piVar5;
      }
    }
    iVar8 = CONCAT22(uVar7,(word)(byte)(bVar19 << 4 | (iVar6 < 0) << 3 | (iVar6 == 0) << 2));
  }
  dword_40B21CC = iVar6;
  return iVar8;
}
