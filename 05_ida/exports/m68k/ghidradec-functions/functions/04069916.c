
void _DoCharGen(sword *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  sword sVar2;
  int iVar3;
  word wVar4;
  word wVar5;
  int iVar6;
  uint uVar7;
  sword sVar8;
  uint uVar9;
  word *pwVar10;
  byte *pbVar11;
  byte *pbVar12;
  word *pwVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  word wStack_10;
  sword sStack_e;
  word wStack_c;
  word wStack_a;
  sword sStack_8;
  word wStack_6;
  
  _keyPressed = 1;
  sVar2 = *param_1;
  sStack_e = -(sword)-(param_3 == 2);
  sVar8 = (sword)param_2;
  uVar14 = 0xb;
  if (param_3 != 0) {
    uVar14 = 10;
  }
  wVar5 = (word)((uint)*(undefined4 *)(_evg + 0xc) >> 0x10);
  pwVar13 = *(word **)(_curMapping + param_2 * 4 + 0xc6);
  sStack_8 = sVar8;
  if (pwVar13 != (word *)0x0) {
    if (sVar2 == 0) {
      pwVar10 = (word *)((int)pwVar13 + 1);
      wVar4 = (word)*(byte *)pwVar13;
    }
    else {
      pwVar10 = pwVar13 + 1;
      wVar4 = *pwVar13;
    }
    if (wVar4 != 0) {
      iVar3 = 2;
      if (sVar2 != 0) {
        iVar3 = 4;
      }
      iVar6 = 0;
      if (-1 < *(int *)(_curMapping + 0x82)) {
        do {
          if ((wVar4 & 1) != 0) {
            if ((wVar5 & 1) != 0) {
              pwVar10 = (word *)(iVar3 + (int)pwVar10);
            }
            iVar3 = iVar3 * 2;
          }
          wVar4 = (sword)wVar4 >> 1;
          wVar5 = (sword)wVar5 >> 1;
          iVar6 = iVar6 + 1;
        } while (iVar6 <= *(int *)(_curMapping + 0x82));
      }
    }
    if (sVar2 == 0) {
      wStack_c = (word)(char)*(byte *)pwVar10;
      wStack_a = (word)(byte)*pwVar10;
    }
    else {
      wStack_c = *pwVar10;
      wStack_a = pwVar10[1];
    }
    pwVar13 = *(word **)(_curMapping + param_2 * 4 + 0xc6);
    uVar7 = (*(uint *)(_evg + 0xc) & 0x3ffff) >> 0x10;
    if (sVar2 == 0) {
      pwVar10 = (word *)((int)pwVar13 + 1);
      wVar5 = (word)*(byte *)pwVar13;
    }
    else {
      pwVar10 = pwVar13 + 1;
      wVar5 = *pwVar13;
    }
    if ((wVar5 != 0) && (uVar7 != 0)) {
      iVar3 = 2;
      if (sVar2 != 0) {
        iVar3 = 4;
      }
      iVar6 = 0;
      if (-1 < *(int *)(_curMapping + 0x82)) {
        do {
          if ((wVar5 & 1) != 0) {
            if ((uVar7 & 1) != 0) {
              pwVar10 = (word *)(iVar3 + (int)pwVar10);
            }
            iVar3 = iVar3 * 2;
          }
          wVar5 = (sword)wVar5 >> 1;
          uVar7 = (int)uVar7 >> 1;
          iVar6 = iVar6 + 1;
        } while (iVar6 <= *(int *)(_curMapping + 0x82));
      }
    }
    if (sVar2 == 0) {
      wStack_10 = (word)(char)*(byte *)pwVar10;
      wStack_6 = (word)(byte)*pwVar10;
    }
    else {
      wStack_10 = *pwVar10;
      wStack_6 = pwVar10[1];
    }
    if (wStack_c == 0xffff) {
      pbVar12 = *(byte **)(_curMapping + 0x2ca);
      iVar3 = 0;
      if (wStack_a != 0) {
        do {
          if (sVar2 == 0) {
            pbVar11 = pbVar12 + 1;
            iVar6 = (uint)*pbVar12 * 2;
          }
          else {
            pbVar11 = pbVar12 + 2;
            iVar6 = *(sword *)pbVar12 * 4;
          }
          pbVar12 = pbVar11 + iVar6;
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)(uint)wStack_a);
      }
      uVar1 = *(undefined4 *)(_evg + 0xc);
      iVar3 = 0;
      if (sVar2 == 0) {
        pwVar13 = (word *)(pbVar12 + 1);
        uVar7 = (uint)*pbVar12;
      }
      else {
        pwVar13 = (word *)(pbVar12 + 2);
        uVar7 = (uint)*(sword *)pbVar12;
      }
      if (0 < (int)uVar7) {
        do {
          if (sVar2 == 0) {
            pwVar10 = (word *)((int)pwVar13 + 1);
            wStack_c = (word)*(byte *)pwVar13;
          }
          else {
            pwVar10 = pwVar13 + 1;
            wStack_c = *pwVar13;
          }
          if (wStack_c == 0xff) {
            wStack_6 = 0;
            sStack_e = 0;
            wStack_a = 0;
            wStack_c = 0;
            wStack_10 = 0;
            if (param_3 != 0) {
              if (sVar2 == 0) {
                pwVar13 = (word *)((int)pwVar10 + 1);
                uVar9 = (uint)*(byte *)pwVar10;
              }
              else {
                pwVar13 = pwVar10 + 1;
                uVar9 = (uint)(sword)*pwVar10;
              }
              *(uint *)(_evg + 0xc) = *(uint *)(_evg + 0xc) | 1 << (uVar9 + 0x10 & 0x3f);
              uVar16 = *(undefined4 *)(_evg + 0x18);
              uVar15 = 0xc;
              sStack_8 = sVar8;
              goto loc_4069B8A;
            }
            if (sVar2 == 0) {
              pwVar13 = (word *)((int)pwVar10 + 1);
              sStack_8 = sVar8;
            }
            else {
              pwVar13 = pwVar10 + 1;
              sStack_8 = sVar8;
            }
          }
          else {
            if (sVar2 == 0) {
              pwVar13 = (word *)((int)pwVar10 + 1);
              wStack_6 = (word)*(byte *)pwVar10;
            }
            else {
              pwVar13 = pwVar10 + 1;
              wStack_6 = *pwVar10;
            }
            uVar16 = *(undefined4 *)(_evg + 0x18);
            uVar15 = uVar14;
loc_4069B8A:
            wStack_10 = wStack_c;
            wStack_a = wStack_6;
            _LLEventPost(uVar15,uVar16,&wStack_10);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)uVar7);
      }
      *(undefined4 *)(_evg + 0xc) = uVar1;
    }
    else {
      _LLEventPost(uVar14,*(undefined4 *)(_evg + 0x18),&wStack_10);
    }
  }
  if ((*(byte *)(_curMapping + 2 + param_2) & 0x40) != 0) {
    _DoSpecialKey(param_2,param_3,*(undefined4 *)(_evg + 0xc));
  }
  if (param_3 == 1) {
    word_40B1252 = uRam040c364a;
    word_40B1254 = sVar8;
  }
  else if ((param_3 == 0) && (param_2 == word_40B1254)) {
    word_40B1252 = 0xffff;
    word_40B1254 = -1;
  }
  return;
}
