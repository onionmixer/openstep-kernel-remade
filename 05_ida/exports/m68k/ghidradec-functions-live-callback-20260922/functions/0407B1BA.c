
void sub_407B1BA(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined uVar4;
  byte bVar5;
  undefined uVar6;
  int iVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  undefined *puVar11;
  
  iVar2 = *param_1;
  puVar3 = *(undefined **)(*(int *)(iVar2 + 0x10) + 8);
  do {
    *(undefined *)(iVar2 + 0x5b) = 0;
    iVar7 = *(int *)((int)param_1 + 0x226);
    *(undefined *)(iVar2 + 0x5a) = 2;
    if (*(char *)((int)param_1 + 0x21e) == '\x06') {
      _delay(0x14);
      if ((*(byte *)(iVar7 + 0x24) & 8) != 0) {
        iVar9 = 0;
        if (_dma_chip == 0x139) goto loc_407B20E;
        while (iVar9 < 1) {
loc_407B20E:
          while( true ) {
            puVar3[0x20] = 0x3c;
            _delay(5);
            puVar3[0x20] = 0x38;
            _delay(5);
            iVar9 = iVar9 + 1;
            if (_dma_chip != 0x139) break;
            if (7 < iVar9) goto loc_407B240;
          }
        }
loc_407B240:
        _delay(0x14);
      }
      puVar3[0x20] = 0x20;
    }
    *(undefined *)((int)param_1 + 0x223) = puVar3[4];
    *(undefined *)(param_1 + 0x89) = puVar3[6];
    *(undefined *)((int)param_1 + 0x225) = puVar3[5];
    if ((((*(byte *)((int)param_1 + 0x223) & 0x40) == 0) &&
        ((*(byte *)((int)param_1 + 0x225) & 0x40) == 0)) ||
       ((dword_40B4FC2 == 6 && (*(char *)((int)param_1 + 0x21e) == '\t')))) {
      dword_40B4FC2 = (uint)*(byte *)((int)param_1 + 0x21e);
      switch(*(undefined *)((int)param_1 + 0x21e)) {
      case :
        sub_407ADBE(puVar3,*(undefined *)(iVar2 + 0x58));
        sub_407BCB6(iVar2,0,aStrayInterrupt);
        return;
      case :
      case :
loc_407b35e:
        if ((*(byte *)((int)param_1 + 0x225) & 3) == 0) {
          if ((*(byte *)((int)param_1 + 0x225) & 4) == 0) {
            if (*(char *)((int)param_1 + 0x21e) == '\x04') {
              *(undefined *)((int)param_1 + 0x21e) = 0;
            }
            else {
              puVar11 = aBadReselection;
loc_407B704:
              sub_407BCB6(iVar2,0,puVar11);
            }
          }
          else {
            uVar1 = *(byte *)(iVar2 + 0x58) & 0x3f;
            uVar1 = (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & (uint)(byte)puVar3[2];
            if (uVar1 != 0) {
              cVar8 = '\0';
              for (; (uVar1 & 1) == 0; uVar1 = (int)uVar1 >> 1) {
                cVar8 = cVar8 + '\x01';
              }
              goto loc_407B3AA;
            }
loc_407B44C:
            *(undefined *)((int)param_1 + 0x236) = 8;
            if ((*(byte *)((int)param_1 + 0x225) & 8) == 0) {
              puVar11 = aBadReselect;
              goto loc_407B704;
            }
            sub_407BC86(param_1,6,0);
            *(undefined *)((int)param_1 + 0x21e) = 7;
            puVar3[3] = 0x12;
          }
        }
        else {
          puVar3[3] = 0x27;
          *(undefined *)((int)param_1 + 0x21e) = 0;
        }
        break;
      case :
        if ((*(byte *)((int)param_1 + 0x225) & 0x20) == 0) {
          if (*(byte *)((int)param_1 + 0x225) != 0x18) {
            iVar7 = 0;
            goto loc_407b35e;
          }
          bVar5 = *(byte *)(param_1 + 0x89) & 7;
          if (((*(byte *)(param_1 + 0x89) & 7) != 0) && ((4 < bVar5 || (bVar5 < 2)))) {
            puVar11 = aSelectSeq;
            goto loc_407B704;
          }
          *(undefined *)((int)param_1 + 0x21e) = 3;
          *(undefined *)(iVar7 + 0x4f) = 1;
        }
        else {
          puVar3[3] = 1;
          *(undefined *)((int)param_1 + 0x21e) = 0;
          *(undefined *)(iVar7 + 0x4f) = 2;
        }
        break;
      case :
        puVar3[3] = 0;
        break;
      case :
        if ((*(byte *)((int)param_1 + 0x225) & 0x20) == 0) {
          if ((*(byte *)((int)param_1 + 0x225) & 8) == 0) {
            if ((puVar3[7] & 0x1f) == 1) {
              *(undefined *)(iVar7 + 0x4e) = puVar3[2];
              if ((*(byte *)((int)param_1 + 0x223) & 0x20) != 0) {
                iVar7 = *(int *)((int)param_1 + 0x216);
                *(int *)((int)param_1 + 0x216) = iVar7 + 1;
                if (5 < iVar7 + 1) {
                  puVar11 = aScsiBusParityO_1;
                  goto loc_407B704;
                }
                sub_407BC86(param_1,5,3);
              }
loc_407B688:
              *(undefined *)((int)param_1 + 0x21e) = 3;
              break;
            }
            puVar11 = aFifoLevel2;
          }
          else if ((puVar3[7] & 0x1f) == 2) {
            *(undefined *)(iVar7 + 0x4e) = puVar3[2];
            *(undefined *)((int)param_1 + 0x236) = puVar3[2];
            if ((*(byte *)((int)param_1 + 0x223) & 0x20) == 0) {
              *(undefined *)((int)param_1 + 0x21e) = 3;
              sub_407BB30(param_1);
              break;
            }
            iVar9 = *(int *)((int)param_1 + 0x216);
            *(int *)((int)param_1 + 0x216) = iVar9 + 1;
            if (iVar9 + 1 < 6) goto loc_407B716;
            puVar11 = aScsiBusParityO_0;
          }
          else {
            puVar11 = aFifoLevel;
          }
          goto loc_407B704;
        }
        break;
      case :
        iVar9 = *(int *)((int)param_1 + 0x22e);
        uVar6 = puVar3[1];
        uVar4 = *puVar3;
        *(uint *)((int)param_1 + 0x22e) = (uint)CONCAT11(uVar6,uVar4);
        if ((*(byte *)(iVar7 + 0x24) & 8) == 0) {
          *(uint *)((int)param_1 + 0x22e) = ((byte)puVar3[7] & 0x1f) + (uint)CONCAT11(uVar6,uVar4);
        }
        iVar9 = iVar9 - *(int *)((int)param_1 + 0x22e);
        *(int *)(iVar7 + 0x4a) = iVar9 + *(int *)(iVar7 + 0x4a);
        *(int *)((int)param_1 + 0x22a) = iVar9 + *(int *)((int)param_1 + 0x22a);
        *(undefined *)((int)param_1 + 0x21e) = 3;
        _dma_cleanup(param_1 + 1,*(undefined4 *)((int)param_1 + 0x22e));
        _busdone(*(undefined4 *)(iVar2 + 0x10));
        if (((param_1[0xc] & 0x4000U) != 0) || ((*(byte *)((int)param_1 + 0x223) & 0x20) != 0)) {
          if ((param_1[0xc] & 0x4000U) != 0) {
            *(undefined4 *)((int)param_1 + 0x216) = 6;
          }
          param_1[0xc] = param_1[0xc] & 0xffffbfff;
          iVar7 = *(int *)((int)param_1 + 0x216);
          *(int *)((int)param_1 + 0x216) = iVar7 + 1;
          if (5 < iVar7 + 1) {
            puVar11 = aScsiBusParityE;
            if ((param_1[0xc] & 0x4000U) != 0) {
              puVar11 = aDmaError_0;
            }
            goto loc_407B704;
          }
          sub_407BC86(param_1,5,3);
        }
        break;
      case :
        if (*(char *)((int)param_1 + 0x236) == '\0') {
          *(undefined *)((int)param_1 + 0x21e) = 0;
          *(undefined4 *)(iVar7 + 0x46) = *(undefined4 *)((int)param_1 + 0x22e);
          *(undefined *)(iVar7 + 0x4f) = 4;
        }
        else if (*(char *)((int)param_1 + 0x236) == '\x04') {
          *(undefined *)((int)param_1 + 0x21e) = 0;
          *(int *)(iVar7 + 0x20) = _hz * *(int *)(iVar7 + 0x42);
          *(byte *)(iVar7 + 0x24) = *(byte *)(iVar7 + 0x24) | 0x80;
          *(undefined *)(iVar7 + 0x4f) = 3;
        }
        else {
          *(undefined *)((int)param_1 + 0x21e) = 3;
          puVar3[3] = 0;
          puVar3[3] = 1;
        }
        break;
      case :
        puVar3[3] = 0;
        *(undefined *)((int)param_1 + 0x21e) = *(undefined *)(param_1 + 0x88);
        break;
      case :
        iVar9 = *(int *)((int)param_1 + 0x232);
        uVar6 = puVar3[1];
        uVar4 = *puVar3;
        *(uint *)((int)param_1 + 0x232) = (uint)CONCAT11(uVar6,uVar4);
        iVar9 = iVar9 - (uint)CONCAT11(uVar6,uVar4);
        iVar10 = iVar9 + *(int *)(iVar7 + 0x4a);
        *(int *)(iVar7 + 0x4a) = iVar10;
        if (((*(byte *)(iVar7 + 0x24) & 8) == 0) && (iVar9 != 0)) {
          *(int *)(iVar7 + 0x4a) = iVar10 + -0xf;
        }
        goto loc_407B688;
      case :
        if ((*(byte *)((int)param_1 + 0x225) & 0x20) == 0) {
          if ((puVar3[7] & 0x1f) != 1) {
            puVar11 = aMsginFifoError;
            goto loc_407B704;
          }
          *(undefined *)((int)param_1 + 0x236) = puVar3[2];
          if ((*(byte *)((int)param_1 + 0x223) & 0x20) == 0) {
            sub_407BB30(param_1);
            break;
          }
          iVar9 = *(int *)((int)param_1 + 0x216);
          *(int *)((int)param_1 + 0x216) = iVar9 + 1;
          if (5 < iVar9 + 1) {
            puVar11 = aScsiBusParityO_2;
            goto loc_407B704;
          }
loc_407B716:
          *(undefined *)((int)param_1 + 0x236) = 8;
          sub_407BC86(param_1,9,3);
          *(undefined *)((int)param_1 + 0x21e) = 7;
          puVar3[3] = 0x12;
          *(int *)(iVar2 + 0x5c) = _hz * *(int *)(iVar7 + 0x42);
          *(undefined *)(iVar2 + 0x5b) = 1;
        }
        break;
      case :
        if ((*(byte *)((int)param_1 + 0x225) & 0x20) == 0) {
          if ((puVar3[7] & 0x1f) != 1) {
            puVar11 = aMsginFifoError;
            goto loc_407B704;
          }
          cVar8 = *(char *)((int)param_1 + 0x222);
loc_407B3AA:
          bVar5 = puVar3[2];
          *(byte *)((int)param_1 + 0x236) = bVar5;
          if ((*(byte *)((int)param_1 + 0x223) & 0x20) != 0) {
            *(char *)((int)param_1 + 0x222) = cVar8;
            iVar9 = *(int *)((int)param_1 + 0x216);
            *(int *)((int)param_1 + 0x216) = iVar9 + 1;
            if (iVar9 + 1 < 6) goto loc_407B716;
            puVar11 = aScsiBusParityO;
            goto loc_407B704;
          }
          if ((-1 < (char)bVar5) || (iVar7 = _scsi_reselect(iVar2,cVar8,bVar5 & 7), iVar7 == 0))
          goto loc_407B44C;
          *(byte *)(iVar7 + 0x24) = *(byte *)(iVar7 + 0x24) & 0x7f;
          *(int *)((int)param_1 + 0x226) = iVar7;
          *(undefined4 *)((int)param_1 + 0x22a) = *(undefined4 *)(iVar7 + 0x32);
          *(undefined4 *)((int)param_1 + 0x22e) = *(undefined4 *)(iVar7 + 0x36);
          *(int *)((int)param_1 + 0x232) = *(int *)(iVar7 + 0x3a) + 1;
          *(undefined *)((int)param_1 + 0x21e) = 7;
          puVar3[3] = 0x12;
          *(int *)(iVar2 + 0x5c) = _hz * *(int *)(iVar7 + 0x42);
          *(undefined *)(iVar2 + 0x5b) = 1;
        }
        break;
      :
                    /* WARNING: Subroutine does not return */
        _panic(aScintrBadState);
      }
      if ((*(char *)((int)param_1 + 0x21e) != '\0') &&
         ((*(byte *)((int)param_1 + 0x225) & 0x20) != 0)) {
        *(undefined *)((int)param_1 + 0x21e) = 0;
        if (*(int *)((int)param_1 + 0x226) != 0) {
          *(undefined *)(*(int *)((int)param_1 + 0x226) + 0x4f) = 10;
        }
      }
      if (*(char *)((int)param_1 + 0x21e) == '\x03') {
        sub_407B89A(param_1);
      }
    }
    else {
      sub_407ADBE(puVar3,*(undefined *)(iVar2 + 0x58));
      sub_407BCB6(iVar2,0,aSoftwareError);
    }
    if ((*(char *)((int)param_1 + 0x21e) == '\0') &&
       (puVar3[3] = 0x44, *(char *)((int)param_1 + 0x21e) == '\0')) {
      if (*(int *)((int)param_1 + 0x226) != 0) {
        *(undefined4 *)((int)param_1 + 0x226) = 0;
        _scsi_cintr(iVar2);
      }
      if (*(char *)((int)param_1 + 0x21e) == '\0') {
        *(undefined *)((int)param_1 + 0x21e) = 1;
      }
    }
    if ((*_intrstat & 0x1000) == 0) {
      if ((*(char *)((int)param_1 + 0x21e) == '\x01') && (*(char *)(*param_1 + 0x60) == '\0')) {
        _sfa_relinquish(param_1[0x8e],param_1 + 0x8f,1);
      }
      return;
    }
  } while( true );
}

