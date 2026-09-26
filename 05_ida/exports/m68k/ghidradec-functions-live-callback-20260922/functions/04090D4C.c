
void __bdiv(word *param_1,word *param_2,sword *param_3,word *param_4,uint param_5,uint param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  word wVar4;
  int iVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  word *pwVar10;
  word *pwVar11;
  word *pwVar12;
  word *pwVar13;
  uint auStack_7c [3];
  undefined auStack_70 [4];
  uint auStack_6c [4];
  int aiStack_5c [2];
  word wStack_52;
  sword *psStack_28;
  int iStack_24;
  undefined2 *puStack_20;
  word *pwStack_1c;
  uint uStack_18;
  sword sVar6;
  
  iVar2 = -(param_5 + 3 & 0xfffffffc);
  pwVar10 = (word *)(&stack0xffffffb0 + iVar2);
  iVar3 = -(param_6 + 3 & 0xfffffffc);
  param_5 = param_5 >> 1;
  param_6 = param_6 >> 1;
  iVar1 = param_5 - param_6;
  while (*param_2 == 0) {
    pwVar13 = param_4 + 1;
    *param_4 = 0;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    param_5 = param_5 - 1;
    param_6 = param_6 - 1;
    param_4 = pwVar13;
    if (param_6 == 0) {
      param_6 = 10 / 0;
    }
  }
  if (param_6 == 1) {
    wVar4 = *param_1;
    uVar7 = (uint)wVar4;
    iStack_24 = 0;
    if (0 < iVar1) {
      do {
        param_1 = param_1 + 1;
        uVar7 = (uint)*param_1 | uVar7 << 0x10;
        *param_3 = (sword)(uVar7 / *param_2);
        uVar7 = uVar7 % (uint)*param_2;
        wVar4 = (word)uVar7;
        iStack_24 = iStack_24 + 1;
        param_3 = param_3 + 1;
      } while (iStack_24 < iVar1);
    }
    *param_4 = wVar4;
  }
  else {
    uVar7 = 0;
    do {
      if ((int)((uint)*param_2 << uVar7 + 0x10) < 0) break;
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 < 0x10);
    *(uint *)(&stack0xffffffac + iVar3 + iVar2) = param_5;
    *(undefined4 *)((int)aiStack_5c + iVar3 + iVar2 + 4) = 0;
    *(undefined **)((int)aiStack_5c + iVar3 + iVar2) = &stack0xffffffb0 + iVar2;
    *(uint *)((int)auStack_6c + iVar3 + iVar2 + 0xc) = uVar7;
    *(word **)((int)auStack_6c + iVar3 + iVar2 + 8) = param_1;
    *(undefined4 *)((int)auStack_6c + iVar3 + iVar2 + 4) = 0x4090e40;
    sub_409100E();
    *(uint *)((int)auStack_6c + iVar3 + iVar2 + 4) = param_6;
    *(undefined4 *)((int)auStack_6c + iVar3 + iVar2) = 0;
    *(undefined **)(auStack_70 + iVar3 + iVar2) = &stack0xffffffb0 + iVar3 + iVar2;
    *(uint *)((int)auStack_7c + iVar3 + iVar2 + 8) = uVar7;
    *(word **)((int)auStack_7c + iVar3 + iVar2 + 4) = param_2;
    *(undefined4 *)((int)auStack_7c + iVar3 + iVar2) = 0x4090e4e;
    sub_409100E();
    pwVar13 = (word *)(&stack0xffffffb2 + iVar2);
    puStack_20 = (undefined2 *)(&stack0xffffffb4 + iVar2);
    iStack_24 = 0;
    if (0 < iVar1) {
      psStack_28 = param_3;
      pwStack_1c = pwVar13;
      do {
        wVar4 = *(word *)(&stack0xffffffb0 + iVar3 + iVar2);
        if (wVar4 == *pwVar10) {
          uVar9 = 0xffff;
          uStack_18 = (uint)wVar4;
          uStack_18 = *pwVar13 + uStack_18;
        }
        else {
          uVar9 = CONCAT22(*pwVar10,*pwVar13);
          uStack_18 = uVar9 % (uint)wVar4;
          uVar9 = uVar9 / wVar4;
        }
        if (uStack_18 < 0x10000) {
          do {
            if (*(word *)(&stack0xffffffb2 + iVar3 + iVar2) * uVar9 <=
                CONCAT22((sword)uStack_18,*puStack_20)) break;
            uVar9 = uVar9 - 1;
            uStack_18 = *(word *)(&stack0xffffffb0 + iVar3 + iVar2) + uStack_18;
          } while (uStack_18 < 0x10000);
        }
        uVar8 = 0;
        iVar5 = param_6 - 1;
        if (-1 < iVar5) {
          pwVar11 = pwStack_1c + iVar5;
          pwVar12 = (word *)(&stack0xffffffb0 + iVar5 * 2 + iVar3 + iVar2);
          do {
            uVar8 = ((uint)*pwVar11 - uVar9 * *pwVar12) + uVar8;
            *pwVar11 = (word)uVar8;
            if (uVar8 < 0x10000) {
              uVar8 = 0;
            }
            else {
              uVar8 = uVar8 >> 0x10 | 0xffff0000;
            }
            pwVar11 = pwVar11 + -1;
            pwVar12 = pwVar12 + -1;
            wVar4 = (word)((uint)iVar5 >> 0x10);
            sVar6 = (sword)iVar5 + -1;
            iVar5 = CONCAT22(wVar4,sVar6);
          } while ((sVar6 != -1) || (iVar5 = (uint)wVar4 * 0x10000 + -1, wVar4 != 0));
        }
        *psStack_28 = (sword)uVar9;
        if ((int)(uVar8 + *pwVar10) < 0) {
          *psStack_28 = (sword)uVar9 + -1;
          uVar9 = 0;
          iVar5 = param_6 - 1;
          if (-1 < iVar5) {
            pwVar11 = pwStack_1c + iVar5;
            pwVar12 = (word *)(&stack0xffffffb0 + iVar5 * 2 + iVar3 + iVar2);
            do {
              do {
                uVar9 = (uint)*pwVar12 + (uint)*pwVar11 + uVar9;
                *pwVar11 = (word)uVar9;
                uVar9 = uVar9 >> 0x10;
                pwVar11 = pwVar11 + -1;
                pwVar12 = pwVar12 + -1;
                wVar4 = (word)((uint)iVar5 >> 0x10);
                sVar6 = (sword)iVar5 + -1;
                iVar5 = CONCAT22(wVar4,sVar6);
              } while (sVar6 != -1);
              iVar5 = (uint)wVar4 * 0x10000 + -1;
            } while (wVar4 != 0);
          }
        }
        pwStack_1c = pwStack_1c + 1;
        psStack_28 = psStack_28 + 1;
        pwVar10 = pwVar10 + 1;
        puStack_20 = puStack_20 + 1;
        pwVar13 = pwVar13 + 1;
        iStack_24 = iStack_24 + 1;
      } while (iStack_24 < iVar1);
    }
    *(uint *)(&stack0xffffffac + iVar3 + iVar2) = param_6 - 1;
    *(int *)((int)aiStack_5c + iVar3 + iVar2 + 4) =
         (int)(uint)*(word *)((int)&wStack_52 + param_5 * 2 + iVar2) >> (uVar7 & 0x3f);
    *(word **)((int)aiStack_5c + iVar3 + iVar2) = param_4 + 1;
    *(uint *)((int)auStack_6c + iVar3 + iVar2 + 0xc) = 0x10 - uVar7;
    *(undefined **)((int)auStack_6c + iVar3 + iVar2 + 8) = &stack0xffffffb0 + iStack_24 * 2 + iVar2;
    *(undefined4 *)((int)auStack_6c + iVar3 + iVar2 + 4) = 0x4090ffe;
    wVar4 = sub_409100E();
    *param_4 = wVar4;
  }
  return;
}

