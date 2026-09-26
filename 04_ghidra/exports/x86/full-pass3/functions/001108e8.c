/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001108e8 */

/* WARNING: Type propagation algorithm not settling */

int _ttwrite(uint param_1,int *param_2)

{
  byte bVar1;
  short sVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  byte *pbVar13;
  int local_78;
  byte local_68 [100];
  
  iVar4 = _ttynty(param_1);
  iVar5 = (int)*(short *)(&_tthiwat + (*(byte *)(param_1 + 0x4a) & 0x1f) * 2);
  iVar6 = param_2[5];
  local_78 = 0;
LAB_00110924:
  do {
    uVar11 = *(uint *)(param_1 + 0x40);
    if ((uVar11 & 0x10) == 0) {
      sVar2 = *(short *)(iVar4 + 0x10);
      while (-1 < sVar2) {
        if (-1 < (short)uVar11) {
          return 5;
        }
        if ((uVar11 & 0x2000) != 0) goto LAB_00110946;
        _sleep(param_1);
        uVar11 = *(uint *)(param_1 + 0x40);
        if ((uVar11 & 0x10) != 0) break;
        sVar2 = *(short *)(iVar4 + 0x10);
      }
    }
    iVar12 = *_active_u;
    if ((*(byte *)(iVar12 + 0x16) & 2) == 0) {
      if (((*(short *)(param_1 + 0x44) == *(short *)(iVar12 + 0x2e)) || (_active_u[0x5a] != param_1)
          ) || (((*(byte *)(param_1 + 0x3e) & 0x40) == 0 ||
                ((((*(byte *)(iVar12 + 0x29) & 0x10) != 0 ||
                  ((*(byte *)(iVar12 + 0x22) & 0x20) != 0)) ||
                 ((*(byte *)(iVar12 + 0x1e) & 0x20) != 0)))))) {
LAB_00110a3c:
        iVar12 = param_2[5];
        do {
          if (iVar12 < 1) {
LAB_00110d1a:
            uVar9 = _spltty();
            if (((*(uint *)(param_1 + 0x40) & 0x4000121) == 0) &&
               (*(code **)(param_1 + 0x24) != (code *)0x0)) {
              (**(code **)(param_1 + 0x24))(param_1);
            }
            _splx(uVar9);
            return local_78;
          }
          iVar12 = *(int *)(*param_2 + 4);
          if (iVar12 == 0) {
            param_2[1] = param_2[1] + -1;
            *param_2 = *param_2 + 8;
            if (param_2[1] < 1) {
                    /* WARNING: Subroutine does not return */
              _panic(s_ttwrite_001dafc6);
            }
          }
          else {
            if (100 < iVar12) {
              iVar12 = 100;
            }
            pbVar13 = local_68;
            local_78 = _uiomove(pbVar13,iVar12,1,param_2);
            if (local_78 != 0) goto LAB_00110d1a;
            if (iVar5 < *(int *)(param_1 + 0x18)) goto LAB_00110d48;
            if ((*(uint *)(param_1 + 0x3c) & 0x800000) == 0) {
              if (((*(uint *)(param_1 + 0x3c) & 0x200024) == 4) &&
                 ((*(byte *)(iVar4 + 0x13) & 0x10) != 0)) {
                while (0 < iVar12) {
                  bVar1 = *pbVar13;
                  pbVar13 = pbVar13 + 1;
                  *(undefined1 *)(param_1 + 0x4b) = 0;
                  iVar8 = _ttyoutput((int)(char)bVar1,param_1);
                  if (-1 < iVar8) {
                    uVar9 = _spltty();
                    if (((*(uint *)(param_1 + 0x40) & 0x4000121) == 0) &&
                       (*(code **)(param_1 + 0x24) != (code *)0x0)) {
                      (**(code **)(param_1 + 0x24))(param_1);
                    }
                    _splx(uVar9);
                    _sleep(0x1e8df0);
                    *(undefined1 *)(param_1 + 0x4b) = 0;
                    if (iVar12 != 0) {
                      *(int *)*param_2 = *(int *)*param_2 - iVar12;
                      *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + iVar12;
                      param_2[5] = param_2[5] + iVar12;
                      param_2[2] = param_2[2] - iVar12;
                    }
                    goto LAB_00110924;
                  }
                  iVar12 = iVar12 + -1;
                  if (iVar5 < *(int *)(param_1 + 0x18)) goto LAB_00110d48;
                }
              }
              else {
                if (((*(uint *)(param_1 + 0x3c) & 0x2200020) == 0) &&
                   (((*(uint *)(iVar4 + 0x10) & 0x10000000) != 0 &&
                    (pbVar3 = pbVar13, iVar8 = iVar12, (*(uint *)(iVar4 + 0x10) & 0x300) != 0x300)))
                   ) {
                  while (-1 < iVar8 + -1) {
                    *pbVar3 = *pbVar3 & 0x7f;
                    pbVar3 = pbVar3 + 1;
                    iVar8 = iVar8 + -1;
                  }
                }
                while (0 < iVar12) {
                  iVar8 = iVar12;
                  if (((*(uint *)(param_1 + 0x3c) & 0x200020) == 0) &&
                     ((*(byte *)(iVar4 + 0x13) & 0x10) != 0)) {
                    iVar7 = _scanc(iVar12,pbVar13,&_partab,0x3f);
                    iVar8 = iVar12 - iVar7;
                    if (iVar12 - iVar7 != 0) goto LAB_00110c74;
                    *(undefined1 *)(param_1 + 0x4b) = 0;
                    iVar8 = _ttyoutput((int)(char)*pbVar13,param_1);
                    if (-1 < iVar8) {
                      uVar9 = _spltty();
                      if (((*(uint *)(param_1 + 0x40) & 0x4000121) == 0) &&
                         (*(code **)(param_1 + 0x24) != (code *)0x0)) {
                        (**(code **)(param_1 + 0x24))(param_1);
                      }
                      _splx(uVar9);
                      _sleep(0x1e8df0);
                      if (iVar12 != 0) {
                        *(int *)*param_2 = *(int *)*param_2 - iVar12;
                        *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + iVar12;
                        param_2[5] = param_2[5] + iVar12;
                        param_2[2] = param_2[2] - iVar12;
                      }
                      goto LAB_00110924;
                    }
                    pbVar13 = pbVar13 + 1;
                    iVar12 = iVar12 + -1;
                  }
                  else {
LAB_00110c74:
                    *(undefined1 *)(param_1 + 0x4b) = 0;
                    iVar7 = _b_to_q(pbVar13,iVar8,param_1 + 0x18);
                    iVar8 = iVar8 - iVar7;
                    *(char *)(param_1 + 0x48) = *(char *)(param_1 + 0x48) + (char)iVar8;
                    pbVar13 = pbVar13 + iVar8;
                    iVar12 = iVar12 - iVar8;
                    _tk_nout = _tk_nout + iVar8;
                    if (0 < iVar7) {
                      uVar9 = _spltty();
                      if (((*(uint *)(param_1 + 0x40) & 0x4000121) == 0) &&
                         (*(code **)(param_1 + 0x24) != (code *)0x0)) {
                        (**(code **)(param_1 + 0x24))(param_1);
                      }
                      _splx(uVar9);
                      _sleep(0x1e8df0);
                      *(int *)*param_2 = *(int *)*param_2 - iVar12;
                      *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + iVar12;
                      param_2[5] = param_2[5] + iVar12;
                      param_2[2] = param_2[2] - iVar12;
                      goto LAB_00110924;
                    }
                  }
                  if (((*(byte *)(param_1 + 0x3e) & 0x80) != 0) ||
                     (iVar5 < *(int *)(param_1 + 0x18))) goto LAB_00110d48;
                }
              }
            }
          }
          iVar12 = param_2[5];
        } while( true );
      }
      iVar8 = (int)*(short *)(iVar12 + 0x2e);
    }
    else {
      iVar7 = _get_posix_proc((int)*(short *)(iVar12 + 0x30));
      iVar8 = *(int *)(*(int *)(iVar7 + 0x10) + 0xc);
      if ((((iVar8 == *(short *)(param_1 + 0x44)) || (_active_u[0x5a] != param_1)) ||
          ((*(byte *)(param_1 + 0x3e) & 0x40) == 0)) ||
         (((*(byte *)(iVar12 + 0x22) & 0x20) != 0 || ((*(byte *)(iVar12 + 0x1e) & 0x20) != 0))))
      goto LAB_00110a3c;
      if (*(int *)(*(int *)(iVar7 + 0x10) + 0x10) == 0) {
        return 5;
      }
    }
    _gsignal(iVar8,0x16);
    _sleep(0x1e8df0);
  } while( true );
LAB_00110d48:
  uVar9 = _spltty();
  if (iVar12 != 0) {
    *(int *)*param_2 = *(int *)*param_2 - iVar12;
    *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + iVar12;
    param_2[5] = param_2[5] + iVar12;
    param_2[2] = param_2[2] - iVar12;
  }
  uVar10 = _spltty();
  if (((*(uint *)(param_1 + 0x40) & 0x4000121) == 0) && (*(code **)(param_1 + 0x24) != (code *)0x0))
  {
    (**(code **)(param_1 + 0x24))(param_1);
  }
  _splx(uVar10);
  if (iVar5 < *(int *)(param_1 + 0x18)) {
    if ((*(uint *)(param_1 + 0x40) & 0x2000) != 0) {
      _splx(uVar9);
      if (param_2[5] == iVar6) {
LAB_00110946:
        if ((*(byte *)(*_active_u + 0x16) & 2) == 0) {
          iVar6 = 0x23;
        }
        else {
          iVar6 = 0xb;
        }
      }
      else {
        iVar6 = 0;
      }
      return iVar6;
    }
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x40;
    uVar10 = 0x1d;
    uVar11 = param_1 + 0x18;
    _sleep(uVar11);
    _splx(uVar9,uVar11,uVar10);
  }
  else {
    _splx(uVar9);
  }
  goto LAB_00110924;
}

