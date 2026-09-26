
uint rem(uint param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  uVar4 = param_1;
  if (((int)(param_2 | param_1) < 0) &&
     ((-1 < (int)param_2 || (param_2 = -param_2, (int)param_1 < 0)))) {
    uVar4 = -param_1;
  }
  uVar6 = param_2;
  if (param_2 == 0) {
    pcVar1 = (code *)sw_trap(2);
    (*pcVar1)();
  }
  if (uVar6 <= uVar4) {
    iVar5 = 0;
    if (uVar4 < 0x8000000) {
      do {
        iVar3 = iVar5;
        uVar6 = uVar6 * 0x10;
        iVar5 = iVar3 + 1;
      } while (uVar6 < uVar4 || uVar6 - uVar4 == 0);
      if (iVar3 + 1 != 0) {
        bVar9 = (int)uVar4 < 0;
        goto loc_F00069A4;
      }
    }
    else {
      for (; iVar3 = 1, uVar7 = uVar6, uVar6 < 0x8000000; uVar6 = uVar6 << 4) {
        iVar5 = iVar5 + 1;
      }
      do {
        uVar6 = uVar7;
        iVar2 = iVar3;
        if (uVar4 <= uVar6) goto loc_F0006940;
        iVar3 = iVar2 + 1;
        uVar7 = uVar6 * 2;
      } while (!CARRY4(uVar6,uVar6));
      uVar6 = (uVar6 & 0x7fffffff) + 0x80000000;
loc_F0006940:
      if (0 < iVar2) {
        uVar4 = uVar4 - uVar6;
        iVar3 = iVar2 + -1;
        while( true ) {
          if (iVar3 < 1) break;
          uVar6 = uVar6 >> 1;
          if ((int)uVar4 < 0) {
            uVar4 = uVar4 + uVar6;
            iVar3 = iVar3 + -1;
          }
          else {
            uVar4 = uVar4 - uVar6;
            iVar3 = iVar3 + -1;
          }
        }
      }
      while( true ) {
        iVar3 = iVar5 + -1;
        bVar9 = (int)uVar4 < 0;
        if (iVar5 < 1) break;
loc_F00069A4:
        uVar7 = uVar6 >> 1;
        iVar5 = iVar3;
        if (bVar9) {
          iVar3 = uVar4 + uVar7;
          uVar8 = uVar6 >> 2;
          if (iVar3 < 0 == SCARRY4(uVar4,uVar7)) {
            iVar2 = iVar3 - uVar8;
            uVar4 = uVar6 >> 3;
            if (iVar3 < (int)uVar8) {
              iVar3 = iVar2 + uVar4;
              uVar6 = uVar6 >> 4;
              if (iVar3 < 0 == SCARRY4(iVar2,uVar4)) {
                uVar4 = iVar3 - uVar6;
              }
              else {
                uVar4 = iVar3 + uVar6;
              }
            }
            else {
              uVar6 = uVar6 >> 4;
              if (iVar2 < (int)uVar4) {
                uVar4 = (iVar2 - uVar4) + uVar6;
              }
              else {
                uVar4 = (iVar2 - uVar4) - uVar6;
              }
            }
          }
          else {
            iVar2 = iVar3 + uVar8;
            uVar4 = uVar6 >> 3;
            if (iVar2 < 0 == SCARRY4(iVar3,uVar8)) {
              uVar6 = uVar6 >> 4;
              if (iVar2 < (int)uVar4) {
                uVar4 = (iVar2 - uVar4) + uVar6;
              }
              else {
                uVar4 = (iVar2 - uVar4) - uVar6;
              }
            }
            else {
              iVar3 = iVar2 + uVar4;
              uVar6 = uVar6 >> 4;
              if (iVar3 < 0 == SCARRY4(iVar2,uVar4)) {
                uVar4 = iVar3 - uVar6;
              }
              else {
                uVar4 = iVar3 + uVar6;
              }
            }
          }
        }
        else {
          iVar3 = uVar4 - uVar7;
          uVar8 = uVar6 >> 2;
          if ((int)uVar4 < (int)uVar7) {
            iVar2 = iVar3 + uVar8;
            uVar4 = uVar6 >> 3;
            if (iVar2 < 0 == SCARRY4(iVar3,uVar8)) {
              uVar6 = uVar6 >> 4;
              if (iVar2 < (int)uVar4) {
                uVar4 = (iVar2 - uVar4) + uVar6;
              }
              else {
                uVar4 = (iVar2 - uVar4) - uVar6;
              }
            }
            else {
              iVar3 = iVar2 + uVar4;
              uVar6 = uVar6 >> 4;
              if (iVar3 < 0 == SCARRY4(iVar2,uVar4)) {
                uVar4 = iVar3 - uVar6;
              }
              else {
                uVar4 = iVar3 + uVar6;
              }
            }
          }
          else {
            iVar2 = iVar3 - uVar8;
            uVar4 = uVar6 >> 3;
            if (iVar3 < (int)uVar8) {
              iVar3 = iVar2 + uVar4;
              uVar6 = uVar6 >> 4;
              if (iVar3 < 0 == SCARRY4(iVar2,uVar4)) {
                uVar4 = iVar3 - uVar6;
              }
              else {
                uVar4 = iVar3 + uVar6;
              }
            }
            else {
              uVar6 = uVar6 >> 4;
              if (iVar2 < (int)uVar4) {
                uVar4 = (iVar2 - uVar4) + uVar6;
              }
              else {
                uVar4 = (iVar2 - uVar4) - uVar6;
              }
            }
          }
        }
      }
      if (bVar9) {
        uVar4 = uVar4 + param_2;
      }
    }
  }
  if ((int)param_1 < 0) {
    uVar4 = -uVar4;
  }
  return uVar4;
}

