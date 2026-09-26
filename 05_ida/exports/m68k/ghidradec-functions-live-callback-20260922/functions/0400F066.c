
int _ttwrite(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  word wVar7;
  sword sVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  int iVar14;
  byte abStack_68 [100];
  
  iVar4 = _ttynty(param_1);
  iVar14 = (int)*(sword *)(_tthiwat + (*(byte *)(param_1 + 0x48) & 0x1f) * 2);
  iVar1 = *(int *)((int)param_2 + 0x12);
  iVar10 = 0;
loc_400F0B8:
  do {
    uVar2 = *(uint *)(param_1 + 0x3e);
    if (((uVar2 & 0x10) != 0) || (*(sword *)(iVar4 + 0x12) < 0)) {
      iVar9 = *_active_u;
      if ((*(byte *)(iVar9 + 0x16) & 0x40) == 0) {
        if ((((*(sword *)(iVar9 + 0x2e) == *(sword *)(param_1 + 0x42)) ||
             (param_1 != *(int *)((int)_active_u + 0x15e))) ||
            ((*(byte *)(param_1 + 0x3b) & 0x40) == 0)) ||
           ((((*(byte *)(iVar9 + 0x2a) & 0x10) != 0 || ((*(byte *)(iVar9 + 0x21) & 0x20) != 0)) ||
            ((*(byte *)(iVar9 + 0x1d) & 0x20) != 0)))) goto loc_400F1C8;
        iVar6 = (int)*(sword *)(iVar9 + 0x2e);
      }
      else {
        iVar5 = _get_posix_proc((int)*(sword *)(iVar9 + 0x30));
        iVar6 = *(int *)(*(int *)(iVar5 + 0xe) + 0xc);
        if (((*(sword *)(param_1 + 0x42) == iVar6) || (param_1 != *(int *)((int)_active_u + 0x15e)))
           || (((*(byte *)(param_1 + 0x3b) & 0x40) == 0 ||
               (((*(byte *)(iVar9 + 0x21) & 0x20) != 0 || ((*(byte *)(iVar9 + 0x1d) & 0x20) != 0))))
              )) {
loc_400F1C8:
          if (*(int *)((int)param_2 + 0x12) < 1) {
loc_400F3C6:
            _ttstart(param_1);
            return iVar10;
          }
          do {
            iVar9 = *(int *)(*param_2 + 4);
            if (iVar9 == 0) {
              param_2[1] = param_2[1] + -1;
              *param_2 = *param_2 + 8;
              if (param_2[1] < 1) {
                    /* WARNING: Subroutine does not return */
                _panic(&aTtwrite);
              }
            }
            else {
              if (100 < iVar9) {
                iVar9 = 100;
              }
              pbVar13 = abStack_68;
              iVar10 = _uiomove(pbVar13,iVar9,1,param_2);
              if (iVar10 != 0) goto loc_400F3C6;
              if (iVar14 < *(int *)(param_1 + 0x18)) goto loc_400F3D4;
              if ((*(uint *)(param_1 + 0x3a) & 0x800000) == 0) {
                if (((*(uint *)(param_1 + 0x3a) & 0x200024) == 4) &&
                   ((*(byte *)(iVar4 + 0x10) & 0x10) != 0)) {
                  if (0 < iVar9) {
                    while( true ) {
                      bVar3 = *pbVar13;
                      *(undefined *)(param_1 + 0x49) = 0;
                      iVar6 = _ttyoutput((int)(char)bVar3,param_1);
                      if (-1 < iVar6) break;
                      iVar9 = iVar9 + -1;
                      if (iVar14 < *(int *)(param_1 + 0x18)) goto loc_400F3D4;
                      pbVar13 = pbVar13 + 1;
                      if (iVar9 < 1) goto loc_400F3BE;
                    }
                    _ttstart(param_1);
                    _sleep(&_lbolt,0x1d);
                    *(undefined *)(param_1 + 0x49) = 0;
loc_400F286:
                    if (iVar9 != 0) {
                      *(int *)*param_2 = *(int *)*param_2 - iVar9;
                      *(int *)(*param_2 + 4) = iVar9 + *(int *)(*param_2 + 4);
                      *(int *)((int)param_2 + 0x12) = iVar9 + *(int *)((int)param_2 + 0x12);
                      param_2[2] = param_2[2] - iVar9;
                    }
                    goto loc_400F0B8;
                  }
                }
                else {
                  if (((*(uint *)(param_1 + 0x3a) & 0x2200020) == 0) &&
                     ((((*(uint *)(iVar4 + 0x10) & 0x10000000) != 0 &&
                       ((*(uint *)(iVar4 + 0x10) & 0x300) != 0x300)) &&
                      (iVar6 = iVar9 + -1, pbVar11 = pbVar13, -1 < iVar6)))) {
                    do {
                      do {
                        pbVar12 = pbVar11 + 1;
                        *pbVar11 = *pbVar11 & 0x7f;
                        wVar7 = (word)((uint)iVar6 >> 0x10);
                        sVar8 = (sword)iVar6 + -1;
                        iVar6 = CONCAT22(wVar7,sVar8);
                        pbVar11 = pbVar12;
                      } while (sVar8 != -1);
                      iVar6 = (uint)wVar7 * 0x10000 + -1;
                    } while (wVar7 != 0);
                  }
                  while (0 < iVar9) {
                    iVar6 = iVar9;
                    if (((*(uint *)(param_1 + 0x3a) & 0x200020) == 0) &&
                       ((*(byte *)(iVar4 + 0x10) & 0x10) != 0)) {
                      iVar5 = _scanc(iVar9,pbVar13,_partab,0x3f);
                      iVar6 = iVar9 - iVar5;
                      if (iVar9 - iVar5 != 0) goto loc_400F382;
                      *(undefined *)(param_1 + 0x49) = 0;
                      iVar6 = _ttyoutput((int)(char)*pbVar13,param_1);
                      if (-1 < iVar6) {
                        _ttstart(param_1);
                        _sleep(&_lbolt,0x1d);
                        goto loc_400F286;
                      }
                      pbVar13 = pbVar13 + 1;
                      iVar9 = iVar9 + -1;
                      if (*(char *)(param_1 + 0x3b) < '\0') goto loc_400F3D4;
                      iVar6 = *(int *)(param_1 + 0x18);
                    }
                    else {
loc_400F382:
                      *(undefined *)(param_1 + 0x49) = 0;
                      iVar5 = _b_to_q(pbVar13,iVar6,(int *)(param_1 + 0x18));
                      iVar6 = iVar6 - iVar5;
                      *(char *)(param_1 + 0x46) = (char)iVar6 + *(char *)(param_1 + 0x46);
                      pbVar13 = pbVar13 + iVar6;
                      iVar9 = iVar9 - iVar6;
                      _tk_nout = iVar6 + _tk_nout;
                      if (0 < iVar5) {
                        _ttstart(param_1);
                        _sleep(&_lbolt,0x1d);
                        *(int *)*param_2 = *(int *)*param_2 - iVar9;
                        *(int *)(*param_2 + 4) = iVar9 + *(int *)(*param_2 + 4);
                        *(int *)((int)param_2 + 0x12) = iVar9 + *(int *)((int)param_2 + 0x12);
                        param_2[2] = param_2[2] - iVar9;
                        goto loc_400F0B8;
                      }
                      if (*(char *)(param_1 + 0x3b) < '\0') goto loc_400F3D4;
                      iVar6 = *(int *)(param_1 + 0x18);
                    }
                    if (iVar14 < iVar6) goto loc_400F3D4;
                  }
                }
              }
            }
loc_400F3BE:
            if (*(int *)((int)param_2 + 0x12) < 1) goto loc_400F3C6;
          } while( true );
        }
        if (*(int *)(*(int *)(iVar5 + 0xe) + 0x10) == 0) {
          return 5;
        }
      }
      _gsignal(iVar6,0x16);
      _sleep(&_lbolt,0x1c);
      goto loc_400F0B8;
    }
    if (-1 < (sword)uVar2) {
      return 5;
    }
    if ((uVar2 & 0x2000) != 0) goto loc_400F420;
    _sleep(param_1,0x1c);
  } while( true );
loc_400F3D4:
  if (iVar9 != 0) {
    *(int *)*param_2 = *(int *)*param_2 - iVar9;
    *(int *)(*param_2 + 4) = iVar9 + *(int *)(*param_2 + 4);
    *(int *)((int)param_2 + 0x12) = iVar9 + *(int *)((int)param_2 + 0x12);
    param_2[2] = param_2[2] - iVar9;
  }
  _ttstart(param_1);
  if (iVar14 < *(int *)(param_1 + 0x18)) {
    if ((*(uint *)(param_1 + 0x3e) & 0x2000) != 0) {
      if (iVar1 != *(int *)((int)param_2 + 0x12)) {
        return 0;
      }
loc_400F420:
      if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
        return 0xb;
      }
      return 0x23;
    }
    *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) | 0x40;
    _sleep(param_1 + 0x18,0x1d);
  }
  goto loc_400F0B8;
}

