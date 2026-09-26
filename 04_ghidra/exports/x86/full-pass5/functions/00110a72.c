/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00110a72 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00110a72(void)

{
  char *pcVar1;
  byte bVar2;
  short sVar3;
  int *piVar4;
  uint uVar5;
  code *pcVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int unaff_EBP;
  int iVar12;
  byte *pbVar13;
  
LAB_00110d0d:
  iVar12 = *(int *)(*(int *)(unaff_EBP + 0xc) + 0x14);
joined_r0x00110d14:
  if (iVar12 < 1) {
LAB_00110d1a:
    _spltty();
    if (((*(uint *)(*(int *)(unaff_EBP + 8) + 0x40) & 0x4000121) == 0) &&
       (pcVar6 = *(code **)(*(int *)(unaff_EBP + 8) + 0x24), pcVar6 != (code *)0x0)) {
      (*pcVar6)();
    }
    _splx();
    return *(undefined4 *)(unaff_EBP + -0x74);
  }
  piVar4 = *(int **)(unaff_EBP + 0xc);
  iVar12 = *(int *)(*piVar4 + 4);
  if (iVar12 != 0) {
    if (100 < iVar12) {
      iVar12 = 100;
    }
    pbVar13 = (byte *)(unaff_EBP + -100);
    iVar9 = _uiomove(pbVar13,iVar12,1);
    *(int *)(unaff_EBP + -0x74) = iVar9;
    if (iVar9 != 0) goto LAB_00110d1a;
    if (*(int *)(*(int *)(unaff_EBP + 8) + 0x18) <= *(int *)(unaff_EBP + -0x6c)) {
      uVar5 = *(uint *)(*(int *)(unaff_EBP + 8) + 0x3c);
      if ((uVar5 & 0x800000) != 0) goto LAB_00110d0d;
      if (((uVar5 & 0x200024) == 4) && ((*(byte *)(*(int *)(unaff_EBP + -0x68) + 0x13) & 0x10) != 0)
         ) {
        if (0 < iVar12) {
          while( true ) {
            bVar2 = *pbVar13;
            pbVar13 = pbVar13 + 1;
            *(undefined1 *)(*(int *)(unaff_EBP + 8) + 0x4b) = 0;
            iVar9 = _ttyoutput((int)(char)bVar2);
            if (-1 < iVar9) break;
            iVar12 = iVar12 + -1;
            if (*(int *)(unaff_EBP + -0x6c) < *(int *)(*(int *)(unaff_EBP + 8) + 0x18))
            goto LAB_00110d48;
            if (iVar12 < 1) goto LAB_00110d0d;
          }
          _spltty();
          if (((*(uint *)(*(int *)(unaff_EBP + 8) + 0x40) & 0x4000121) == 0) &&
             (pcVar6 = *(code **)(*(int *)(unaff_EBP + 8) + 0x24), pcVar6 != (code *)0x0)) {
            (*pcVar6)();
          }
          _splx();
          _sleep(0x1e8df0);
          *(undefined1 *)(*(int *)(unaff_EBP + 8) + 0x4b) = 0;
          if (iVar12 != 0) {
            piVar4 = *(int **)(unaff_EBP + 0xc);
            *(int *)*piVar4 = *(int *)*piVar4 - iVar12;
            *(int *)(*piVar4 + 4) = *(int *)(*piVar4 + 4) + iVar12;
            piVar4[5] = piVar4[5] + iVar12;
            piVar4[2] = piVar4[2] - iVar12;
          }
          goto LAB_00110924;
        }
        goto LAB_00110d0d;
      }
      if ((((*(uint *)(*(int *)(unaff_EBP + 8) + 0x3c) & 0x2200020) == 0) &&
          (uVar5 = *(uint *)(*(int *)(unaff_EBP + -0x68) + 0x10), (uVar5 & 0x10000000) != 0)) &&
         (pbVar7 = pbVar13, iVar9 = iVar12, (uVar5 & 0x300) != 0x300)) {
        while (-1 < iVar9 + -1) {
          *pbVar7 = *pbVar7 & 0x7f;
          pbVar7 = pbVar7 + 1;
          iVar9 = iVar9 + -1;
        }
      }
      do {
        if (iVar12 < 1) goto LAB_00110d0d;
        iVar9 = iVar12;
        if (((*(uint *)(*(int *)(unaff_EBP + 8) + 0x3c) & 0x200020) == 0) &&
           ((*(byte *)(*(int *)(unaff_EBP + -0x68) + 0x13) & 0x10) != 0)) {
          iVar10 = _scanc(iVar12,pbVar13,&_partab);
          iVar9 = iVar12 - iVar10;
          if (iVar12 - iVar10 != 0) goto LAB_00110c74;
          *(undefined1 *)(*(int *)(unaff_EBP + 8) + 0x4b) = 0;
          iVar9 = _ttyoutput((int)(char)*pbVar13);
          if (-1 < iVar9) {
            _spltty();
            if (((*(uint *)(*(int *)(unaff_EBP + 8) + 0x40) & 0x4000121) == 0) &&
               (pcVar6 = *(code **)(*(int *)(unaff_EBP + 8) + 0x24), pcVar6 != (code *)0x0)) {
              (*pcVar6)();
            }
            _splx();
            _sleep(0x1e8df0);
            if (iVar12 != 0) {
              piVar4 = *(int **)(unaff_EBP + 0xc);
              *(int *)*piVar4 = *(int *)*piVar4 - iVar12;
              *(int *)(*piVar4 + 4) = *(int *)(*piVar4 + 4) + iVar12;
              piVar4[5] = piVar4[5] + iVar12;
              piVar4[2] = piVar4[2] - iVar12;
            }
            goto LAB_00110924;
          }
          pbVar13 = pbVar13 + 1;
          iVar12 = iVar12 + -1;
        }
        else {
LAB_00110c74:
          *(undefined1 *)(*(int *)(unaff_EBP + 8) + 0x4b) = 0;
          iVar10 = _b_to_q(pbVar13,iVar9);
          iVar9 = iVar9 - iVar10;
          pcVar1 = (char *)(*(int *)(unaff_EBP + 8) + 0x48);
          *pcVar1 = *pcVar1 + (char)iVar9;
          pbVar13 = pbVar13 + iVar9;
          iVar12 = iVar12 - iVar9;
          _tk_nout = _tk_nout + iVar9;
          if (0 < iVar10) {
            _spltty();
            if (((*(uint *)(*(int *)(unaff_EBP + 8) + 0x40) & 0x4000121) == 0) &&
               (pcVar6 = *(code **)(*(int *)(unaff_EBP + 8) + 0x24), pcVar6 != (code *)0x0)) {
              (*pcVar6)();
            }
            _splx();
            _sleep(0x1e8df0);
            piVar4 = *(int **)(unaff_EBP + 0xc);
            *(int *)*piVar4 = *(int *)*piVar4 - iVar12;
            *(int *)(*piVar4 + 4) = *(int *)(*piVar4 + 4) + iVar12;
            piVar4[5] = piVar4[5] + iVar12;
            piVar4[2] = piVar4[2] - iVar12;
            goto LAB_00110924;
          }
        }
      } while (((*(byte *)(*(int *)(unaff_EBP + 8) + 0x3e) & 0x80) == 0) &&
              (*(int *)(*(int *)(unaff_EBP + 8) + 0x18) <= *(int *)(unaff_EBP + -0x6c)));
    }
LAB_00110d48:
    uVar11 = _spltty();
    if (iVar12 != 0) {
      piVar4 = *(int **)(unaff_EBP + 0xc);
      *(int *)*piVar4 = *(int *)*piVar4 - iVar12;
      *(int *)(*piVar4 + 4) = *(int *)(*piVar4 + 4) + iVar12;
      piVar4[5] = piVar4[5] + iVar12;
      piVar4[2] = piVar4[2] - iVar12;
    }
    _spltty();
    if (((*(uint *)(*(int *)(unaff_EBP + 8) + 0x40) & 0x4000121) == 0) &&
       (pcVar6 = *(code **)(*(int *)(unaff_EBP + 8) + 0x24), pcVar6 != (code *)0x0)) {
      (*pcVar6)();
    }
    _splx();
    if (*(int *)(unaff_EBP + -0x6c) < *(int *)(*(int *)(unaff_EBP + 8) + 0x18)) {
      uVar5 = *(uint *)(*(int *)(unaff_EBP + 8) + 0x40);
      if ((uVar5 & 0x2000) != 0) {
        _splx();
        if (*(int *)(*(int *)(unaff_EBP + 0xc) + 0x14) != *(int *)(unaff_EBP + -0x70)) {
          return 0;
        }
LAB_00110946:
        if ((*(byte *)(*_active_u + 0x16) & 2) != 0) {
          return 0xb;
        }
        return 0x23;
      }
      *(uint *)(*(int *)(unaff_EBP + 8) + 0x40) = uVar5 | 0x40;
      _sleep(*(int *)(unaff_EBP + 8) + 0x18);
      _splx(uVar11);
    }
    else {
      _splx();
    }
LAB_00110924:
    do {
      uVar5 = *(uint *)(*(int *)(unaff_EBP + 8) + 0x40);
      if ((uVar5 & 0x10) == 0) {
        sVar3 = *(short *)(*(int *)(unaff_EBP + -0x68) + 0x10);
        while (-1 < sVar3) {
          if (-1 < (short)uVar5) {
            return 5;
          }
          if ((uVar5 & 0x2000) != 0) goto LAB_00110946;
          _sleep(*(uint *)(unaff_EBP + 8));
          uVar5 = *(uint *)(*(int *)(unaff_EBP + 8) + 0x40);
          if ((uVar5 & 0x10) != 0) break;
          sVar3 = *(short *)(*(int *)(unaff_EBP + -0x68) + 0x10);
        }
      }
      iVar12 = *_active_u;
      if ((*(byte *)(iVar12 + 0x16) & 2) == 0) {
        iVar9 = *(int *)(unaff_EBP + 8);
        if (((((*(short *)(iVar9 + 0x44) == *(short *)(iVar12 + 0x2e)) || (_active_u[0x5a] != iVar9)
              ) || ((*(byte *)(iVar9 + 0x3e) & 0x40) == 0)) ||
            (((*(byte *)(iVar12 + 0x29) & 0x10) != 0 || ((*(byte *)(iVar12 + 0x22) & 0x20) != 0))))
           || ((*(byte *)(iVar12 + 0x1e) & 0x20) != 0)) goto LAB_00110a3c;
        iVar9 = (int)*(short *)(iVar12 + 0x2e);
      }
      else {
        iVar8 = _get_posix_proc();
        iVar10 = *(int *)(unaff_EBP + 8);
        iVar9 = *(int *)(*(int *)(iVar8 + 0x10) + 0xc);
        if (((iVar9 == *(short *)(iVar10 + 0x44)) || (_active_u[0x5a] != iVar10)) ||
           (((*(byte *)(iVar10 + 0x3e) & 0x40) == 0 ||
            (((*(byte *)(iVar12 + 0x22) & 0x20) != 0 || ((*(byte *)(iVar12 + 0x1e) & 0x20) != 0)))))
           ) goto LAB_00110a3c;
        if (*(int *)(*(int *)(iVar8 + 0x10) + 0x10) == 0) {
          return 5;
        }
      }
      _gsignal(iVar9);
      _sleep(0x1e8df0);
    } while( true );
  }
  piVar4[1] = piVar4[1] + -1;
  *piVar4 = *piVar4 + 8;
  if (piVar4[1] < 1) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ttwrite_001dafc6);
  }
  goto LAB_00110d0d;
LAB_00110a3c:
  iVar12 = *(int *)(*(int *)(unaff_EBP + 0xc) + 0x14);
  goto joined_r0x00110d14;
}

