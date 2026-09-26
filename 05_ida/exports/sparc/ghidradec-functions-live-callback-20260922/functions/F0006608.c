
int div(uint param_1,uint param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  uVar2 = param_2 ^ param_1;
  if (((int)(param_2 | param_1) < 0) &&
     ((-1 < (int)param_2 || (param_2 = -param_2, (int)param_1 < 0)))) {
    param_1 = -param_1;
  }
  if (param_2 == 0) {
    pcVar1 = (code *)sw_trap(2);
    (*pcVar1)();
  }
  iVar5 = 0;
  if (param_2 <= param_1) {
    iVar6 = 0;
    if (param_1 < 0x8000000) {
      do {
        iVar4 = iVar6;
        param_2 = param_2 * 0x10;
        iVar6 = iVar4 + 1;
      } while (param_2 < param_1 || param_2 - param_1 == 0);
      if (iVar4 + 1 != 0) {
        bVar9 = (int)param_1 < 0;
        goto loc_F0006704;
      }
    }
    else {
      for (; iVar4 = 1, uVar7 = param_2, param_2 < 0x8000000; param_2 = param_2 << 4) {
        iVar6 = iVar6 + 1;
      }
      do {
        param_2 = uVar7;
        iVar3 = iVar4;
        if (param_1 <= param_2) goto loc_F00066A0;
        iVar4 = iVar3 + 1;
        uVar7 = param_2 * 2;
      } while (!CARRY4(param_2,param_2));
      param_2 = (param_2 & 0x7fffffff) + 0x80000000;
loc_F00066A0:
      if (0 < iVar3) {
        param_1 = param_1 - param_2;
        iVar5 = 1;
        iVar4 = iVar3 + -1;
        while( true ) {
          if (iVar4 < 1) break;
          param_2 = param_2 >> 1;
          if ((int)param_1 < 0) {
            param_1 = param_1 + param_2;
            iVar5 = iVar5 * 2 + -1;
            iVar4 = iVar4 + -1;
          }
          else {
            param_1 = param_1 - param_2;
            iVar5 = iVar5 * 2 + 1;
            iVar4 = iVar4 + -1;
          }
        }
      }
      while( true ) {
        iVar4 = iVar6 + -1;
        bVar9 = (int)param_1 < 0;
        if (iVar6 < 1) break;
loc_F0006704:
        iVar5 = iVar5 * 0x10;
        uVar7 = param_2 >> 1;
        iVar6 = iVar4;
        if (bVar9) {
          iVar4 = param_1 + uVar7;
          uVar8 = param_2 >> 2;
          if (iVar4 < 0 == SCARRY4(param_1,uVar7)) {
            iVar3 = iVar4 - uVar8;
            uVar7 = param_2 >> 3;
            if (iVar4 < (int)uVar8) {
              iVar4 = iVar3 + uVar7;
              param_2 = param_2 >> 4;
              if (iVar4 < 0 == SCARRY4(iVar3,uVar7)) {
                param_1 = iVar4 - param_2;
                iVar5 = iVar5 + -5;
              }
              else {
                param_1 = iVar4 + param_2;
                iVar5 = iVar5 + -7;
              }
            }
            else {
              param_2 = param_2 >> 4;
              if (iVar3 < (int)uVar7) {
                param_1 = (iVar3 - uVar7) + param_2;
                iVar5 = iVar5 + -3;
              }
              else {
                param_1 = (iVar3 - uVar7) - param_2;
                iVar5 = iVar5 + -1;
              }
            }
          }
          else {
            iVar3 = iVar4 + uVar8;
            uVar7 = param_2 >> 3;
            if (iVar3 < 0 == SCARRY4(iVar4,uVar8)) {
              param_2 = param_2 >> 4;
              if (iVar3 < (int)uVar7) {
                param_1 = (iVar3 - uVar7) + param_2;
                iVar5 = iVar5 + -0xb;
              }
              else {
                param_1 = (iVar3 - uVar7) - param_2;
                iVar5 = iVar5 + -9;
              }
            }
            else {
              iVar4 = iVar3 + uVar7;
              param_2 = param_2 >> 4;
              if (iVar4 < 0 == SCARRY4(iVar3,uVar7)) {
                param_1 = iVar4 - param_2;
                iVar5 = iVar5 + -0xd;
              }
              else {
                param_1 = iVar4 + param_2;
                iVar5 = iVar5 + -0xf;
              }
            }
          }
        }
        else {
          iVar4 = param_1 - uVar7;
          uVar8 = param_2 >> 2;
          if ((int)param_1 < (int)uVar7) {
            iVar3 = iVar4 + uVar8;
            uVar7 = param_2 >> 3;
            if (iVar3 < 0 == SCARRY4(iVar4,uVar8)) {
              param_2 = param_2 >> 4;
              if (iVar3 < (int)uVar7) {
                param_1 = (iVar3 - uVar7) + param_2;
                iVar5 = iVar5 + 5;
              }
              else {
                param_1 = (iVar3 - uVar7) - param_2;
                iVar5 = iVar5 + 7;
              }
            }
            else {
              iVar4 = iVar3 + uVar7;
              param_2 = param_2 >> 4;
              if (iVar4 < 0 == SCARRY4(iVar3,uVar7)) {
                param_1 = iVar4 - param_2;
                iVar5 = iVar5 + 3;
              }
              else {
                param_1 = iVar4 + param_2;
                iVar5 = iVar5 + 1;
              }
            }
          }
          else {
            iVar3 = iVar4 - uVar8;
            uVar7 = param_2 >> 3;
            if (iVar4 < (int)uVar8) {
              iVar4 = iVar3 + uVar7;
              param_2 = param_2 >> 4;
              if (iVar4 < 0 == SCARRY4(iVar3,uVar7)) {
                param_1 = iVar4 - param_2;
                iVar5 = iVar5 + 0xb;
              }
              else {
                param_1 = iVar4 + param_2;
                iVar5 = iVar5 + 9;
              }
            }
            else {
              param_2 = param_2 >> 4;
              if (iVar3 < (int)uVar7) {
                param_1 = (iVar3 - uVar7) + param_2;
                iVar5 = iVar5 + 0xd;
              }
              else {
                param_1 = (iVar3 - uVar7) - param_2;
                iVar5 = iVar5 + 0xf;
              }
            }
          }
        }
      }
      if (bVar9) {
        iVar5 = iVar5 + -1;
      }
    }
  }
  if ((int)uVar2 < 0) {
    iVar5 = -iVar5;
  }
  return iVar5;
}

