
undefined4 _SetKeyMapping(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  word wVar8;
  int iVar9;
  sword sVar10;
  int iVar11;
  undefined *puVar12;
  int iVar13;
  undefined2 uStack_2ec;
  byte abStack_2ea [128];
  uint uStack_26a;
  int aiStack_266 [144];
  int iStack_26;
  int iStack_22;
  byte abStack_1e [10];
  int iStack_14;
  int iStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  puVar12 = &stack0xfffffffc;
  iVar13 = -1;
  iStack_c = param_1 + param_2;
  iStack_10 = param_1;
  uStack_8 = 1;
  _bzero(&uStack_2ec,0x2dc);
  uStack_26a = 0xffffffff;
  iStack_14 = param_1;
  uStack_8 = sub_40694AE(&iStack_10);
  uStack_2ec = (undefined2)uStack_8;
  iVar2 = sub_40694AE(&iStack_10);
  iVar9 = 0;
  if (0 < iVar2) {
    do {
      uVar3 = sub_40694AE(&iStack_10);
      if (0xf < (int)uVar3) {
        return 0;
      }
      if ((int)uStack_26a < (int)uVar3) {
        uStack_26a = uVar3;
      }
      aiStack_266[uVar3] = iStack_10;
      iVar11 = 0;
      iVar4 = sub_40694AE(&iStack_10);
      if (0 < iVar4) {
        do {
          iVar5 = sub_40694AE(&iStack_10);
          if (0x7f < iVar5) {
            return 0;
          }
          if ((abStack_2ea[iVar5] & 0x10) != 0) {
            return 0;
          }
          abStack_2ea[iVar5] = (byte)uVar3 & 0xf | 0x10 | abStack_2ea[iVar5];
          iVar11 = iVar11 + 1;
        } while (iVar11 < iVar4);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < iVar2);
  }
  iVar9 = 0;
  iVar2 = sub_40694AE(&iStack_10);
  do {
    if (iVar9 < iVar2) {
      *(int *)(puVar12 + -0x222) = iStack_10;
      uVar3 = sub_40694AE(&iStack_10);
      if (uVar3 == 0xff) goto loc_406963E;
      abStack_2ea[iVar9] = abStack_2ea[iVar9] | 0x20;
      iVar11 = 0;
      iVar4 = 1;
      if (-1 < (int)uStack_26a) {
        do {
          if ((uVar3 & 1) != 0) {
            iVar4 = iVar4 * 2;
          }
          iVar11 = iVar11 + 1;
          uVar3 = (int)uVar3 >> 1;
        } while (iVar11 <= (int)uStack_26a);
      }
      iVar11 = 0;
      if (0 < iVar4) {
        do {
          iVar5 = sub_40694AE(&iStack_10);
          iVar6 = sub_40694AE(&iStack_10);
          if ((iVar5 == -1) && (iVar13 < iVar6)) {
            iVar13 = iVar6;
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < iVar4);
      }
    }
    else {
loc_406963E:
      *(undefined4 *)(puVar12 + -0x222) = 0;
    }
    puVar12 = puVar12 + 4;
    iVar9 = iVar9 + 1;
    if (0x7f < iVar9) {
      iStack_26 = sub_40694AE(&iStack_10);
      iStack_22 = iStack_10;
      if (iVar13 < iStack_26) {
        iVar9 = 0;
        if (0 < iStack_26) {
          do {
            iVar13 = 0;
            iVar2 = sub_40694AE(&iStack_10);
            if (0 < iVar2) {
              do {
                sub_40694AE(&iStack_10);
                sub_40694AE(&iStack_10);
                iVar13 = iVar13 + 1;
              } while (iVar13 < iVar2);
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < iStack_26);
        }
        iVar9 = sub_40694AE(&iStack_10);
        if (iVar9 < 10) {
          if (iVar9 == 0) {
            if (word_40B1256 != 0) {
              return 0;
            }
            iVar9 = 0;
            do {
              abStack_1e[iVar9] = *(byte *)(iVar9 + _curMapping + 0x2ce);
              iVar9 = iVar9 + 1;
            } while (iVar9 < 9);
          }
          else {
            iVar13 = 8;
            do {
              do {
                abStack_1e[iVar13] = 0xff;
                wVar8 = (word)((uint)iVar13 >> 0x10);
                sVar10 = (sword)iVar13 + -1;
                iVar13 = CONCAT22(wVar8,sVar10);
              } while (sVar10 != -1);
              iVar13 = (uint)wVar8 * 0x10000 + -1;
            } while (wVar8 != 0);
            iVar13 = 0;
            if (0 < iVar9) {
              do {
                iVar2 = sub_40694AE(&iStack_10);
                bVar7 = sub_40694AE(&iStack_10);
                if (8 < iVar2) {
                  return 0;
                }
                abStack_1e[iVar2] = bVar7;
                iVar13 = iVar13 + 1;
              } while (iVar13 < iVar9);
            }
          }
          iVar9 = 0;
          do {
            if (abStack_1e[iVar9] != 0xff) {
              abStack_2ea[abStack_1e[iVar9]] = abStack_2ea[abStack_1e[iVar9]] | 0x60;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < 4);
          uVar1 = *(undefined4 *)(_curMapping + 0x2d8);
          _keySema = _keySema + 1;
          iVar9 = 0;
          do {
            abStack_2ea[iVar9] = unk_40C3336[iVar9] & 0x80 | abStack_2ea[iVar9];
            iVar9 = iVar9 + 1;
          } while (iVar9 < 0x80);
          *(uint *)(_evg + 0xc) = *(uint *)(_evg + 0xc) & 0xffff;
          iVar9 = 0;
          if (uStack_26a < 0x80000000) {
            do {
              _CalcModBit(&uStack_2ec,iVar9);
              iVar9 = iVar9 + 1;
            } while (iVar9 <= (int)uStack_26a);
          }
          _bcopy(&uStack_2ec,&_curMappingStorage,0x2dc);
          _curMapLen = param_2;
          _keySema = _keySema + -1;
          return uVar1;
        }
      }
      return 0;
    }
  } while( true );
}
