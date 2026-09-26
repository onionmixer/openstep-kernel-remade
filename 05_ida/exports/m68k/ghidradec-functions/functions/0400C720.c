
int _selscan(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iStack_14;
  int iStack_10;
  
  iVar7 = 0;
  iVar8 = 0;
  iStack_10 = param_2;
  iStack_14 = param_1;
  do {
    uVar2 = *(undefined4 *)(unk_40AE242 + iVar8 * 4);
    uVar9 = 0;
    if (0 < param_3) {
      do {
        uVar5 = *(uint *)(iStack_14 + (uVar9 >> 5) * 4);
        if (uVar5 != 0) {
          uVar6 = 0;
          do {
            uVar3 = uVar5 & 1;
            uVar5 = (int)uVar5 >> 1;
            if (uVar3 != 0) {
              uVar3 = uVar6 + uVar9;
              if ((param_3 <= (int)uVar3) || (*(int *)(_active_u + 0x152) <= (int)uVar3)) break;
              iVar4 = *(int *)(*(int *)(_active_u + 0x146) + uVar3 * 4);
              if (iVar4 == 0) {
                *(undefined *)(dword_40B57D4 + 100) = 9;
                break;
              }
              iVar4 = (**(code **)(*(int *)(iVar4 + 0x12) + 8))(iVar4,uVar2);
              if (iVar4 != 0) {
                puVar1 = (uint *)(iStack_10 + (uVar3 >> 5) * 4);
                *puVar1 = 1 << (uVar3 & 0x1f) | *puVar1;
                iVar7 = iVar7 + 1;
              }
              if (uVar5 == 0) break;
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < 0x20);
        }
        uVar9 = uVar9 + 0x20;
      } while ((int)uVar9 < param_3);
    }
    iStack_10 = iStack_10 + 0x20;
    iStack_14 = iStack_14 + 0x20;
    iVar8 = iVar8 + 1;
    if (2 < iVar8) {
      return iVar7;
    }
  } while( true );
}
