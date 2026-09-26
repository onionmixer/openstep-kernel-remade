/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011039c */

int _ttread(FILE *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uchar *puVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  char cVar16;
  char *unaff_EBX;
  int unaff_ESI;
  FILE *pFVar17;
  undefined4 uVar18;
  uchar *local_40;
  int iVar19;
  FILE *local_30;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uchar *local_10;
  int local_c;
  int local_8;
  
  iVar10 = _ttynty(param_1);
  iVar19 = 0;
LAB_001103bb:
  bVar8 = false;
LAB_001103c2:
  while( true ) {
    uVar3 = param_1->_ur;
    uVar11 = _spltty();
    if ((uVar3 & 0x20000000) != 0) {
      param_1->_ur = param_1->_ur & 0xdfffffff;
      uVar15._0_1_ = param_1->_ubuf[0];
      uVar15._1_1_ = param_1->_ubuf[1];
      uVar15._2_1_ = param_1->_ubuf[2];
      uVar15._3_1_ = param_1->_nbuf[0];
      uVar15 = uVar15 | 0x100000;
      param_1->_ubuf[0] = (char)uVar15;
      param_1->_ubuf[1] = (char)(uVar15 >> 8);
      param_1->_ubuf[2] = (char)(uVar15 >> 0x10);
      param_1->_nbuf[0] = (char)(uVar15 >> 0x18);
      local_10 = param_1->_p;
      local_c = param_1->_r;
      local_8 = param_1->_w;
      param_1->_p = (uchar *)0x0;
      param_1->_w = 0;
      param_1->_r = 0;
      while (iVar12 = _getc((FILE *)&local_10), -1 < iVar12) {
        _ttyinput(iVar12,param_1);
      }
      uVar1._0_1_ = param_1->_ubuf[0];
      uVar1._1_1_ = param_1->_ubuf[1];
      uVar1._2_1_ = param_1->_ubuf[2];
      uVar1._3_1_ = param_1->_nbuf[0];
      uVar1 = uVar1 & 0xffefffff;
      param_1->_ubuf[0] = (char)uVar1;
      param_1->_ubuf[1] = (char)(uVar1 >> 8);
      param_1->_ubuf[2] = (char)(uVar1 >> 0x10);
      param_1->_nbuf[0] = (char)(uVar1 >> 0x18);
    }
    _splx(uVar11);
    while ((uVar4._0_1_ = param_1->_ubuf[0], uVar4._1_1_ = param_1->_ubuf[1],
           uVar4._2_1_ = param_1->_ubuf[2], uVar4._3_1_ = param_1->_nbuf[0], (uVar4 & 0x10) == 0 &&
           (-1 < *(short *)(iVar10 + 0x10)))) {
      if (-1 < (short)uVar4) {
        return 5;
      }
      if ((uVar4 & 0x2000) != 0) goto LAB_0011044e;
      _sleep((uint)param_1);
    }
    iVar12 = *_active_u;
    if ((*(byte *)(iVar12 + 0x16) & 2) != 0) break;
    if (((FILE *)_active_u[0x5a] != param_1) ||
       (*(short *)&(param_1->_lb)._base == *(short *)(iVar12 + 0x2e))) goto LAB_0011052c;
    if (((*(byte *)(iVar12 + 0x22) & 0x10) != 0) ||
       (((*(byte *)(iVar12 + 0x1e) & 0x10) != 0 || ((*(byte *)(iVar12 + 0x29) & 0x10) != 0)))) {
      return 5;
    }
    iVar14 = (int)*(short *)(iVar12 + 0x2e);
LAB_00110510:
    _gsignal(iVar14,0x15);
    _sleep(0x1e8df0);
  }
  iVar13 = _get_posix_proc((int)*(short *)(iVar12 + 0x30));
  if ((FILE *)_active_u[0x5a] == param_1) {
    iVar14 = *(int *)(*(int *)(iVar13 + 0x10) + 0xc);
    if (iVar14 != *(short *)&(param_1->_lb)._base) {
      if ((*(byte *)(iVar12 + 0x22) & 0x10) != 0) {
        return 5;
      }
      if ((*(byte *)(iVar12 + 0x1e) & 0x10) != 0) {
        return 5;
      }
      if (*(int *)(*(int *)(iVar13 + 0x10) + 0x10) == 0) {
        return 5;
      }
      if ((*(byte *)(iVar12 + 0x29) & 0x10) != 0) {
        return 5;
      }
      goto LAB_00110510;
    }
  }
LAB_0011052c:
  uVar11 = _spltty();
  if ((uVar3 & 0x22) == 0) {
    local_30 = (FILE *)&param_1->_flags;
    iVar12._0_2_ = param_1->_flags;
    iVar12._2_2_ = param_1->_file;
    if (0 < iVar12) goto LAB_001106f8;
  }
  else {
    uVar15 = (uint)*(byte *)(iVar10 + 0x15);
    local_30 = param_1;
    if (*(byte *)(iVar10 + 0x16) == 0) {
      if ((int)uVar15 <= (int)param_1->_p) goto LAB_001106f8;
    }
    else {
      iVar12 = (uint)*(byte *)(iVar10 + 0x16) * 100000;
      if (uVar15 == 0) {
        if (0 < (int)param_1->_p) goto LAB_001106f8;
        if (bVar8) {
          _getthetime(&local_28);
          iVar12 = iVar12 + ((local_28 - local_18) * -1000000 - (local_24 - local_14));
        }
        else {
          bVar8 = true;
          _getthetime(&local_18);
        }
      }
      else {
        puVar5 = param_1->_p;
        if ((int)puVar5 < 1) goto LAB_00110690;
        if ((int)uVar15 <= (int)puVar5) goto LAB_001106f8;
        if (bVar8) {
          if ((int)local_40 < (int)puVar5) {
            _getthetime(&local_18);
          }
          else {
            _getthetime(&local_20);
            iVar12 = iVar12 + ((local_20 - local_18) * -1000000 - (local_1c - local_14));
          }
        }
        else {
          bVar8 = true;
          _getthetime(&local_18);
        }
        local_40 = param_1->_p;
      }
      if (iVar12 < 1) goto LAB_001106f8;
      _untimeout(_wakeup,param_1);
      _timeout(0x10ab38);
    }
  }
LAB_00110690:
  bVar9 = false;
  if (((param_1->_ubuf[0] & 0x10) != 0) || (*(short *)(iVar10 + 0x10) < 0)) {
    bVar9 = true;
  }
  if ((!bVar9) && ((param_1->_ubuf[0] & 4) != 0)) {
    _splx(uVar11);
    return 0;
  }
  if ((param_1->_ubuf[1] & 0x20) != 0) {
    _splx(uVar11);
LAB_0011044e:
    if ((*(byte *)(*_active_u + 0x16) & 2) != 0) {
      return 0xb;
    }
    return 0x23;
  }
  uVar18 = 0x1c;
  pFVar17 = param_1;
  _sleep((uint)param_1);
  _splx(uVar11,pFVar17,uVar18);
  goto LAB_001103c2;
LAB_001106f8:
  _splx(uVar11);
  bVar8 = true;
  do {
    uVar15 = _getc(local_30);
    if ((int)uVar15 < 0) goto LAB_001107b4;
    cVar16 = (char)uVar15;
    if (cVar16 != -1) {
      if (((*(char *)((int)&param_1->_offset + 6) == cVar16) && ((uVar3 & 0x20) == 0)) &&
         ((*(byte *)(iVar10 + 0x10) & 8) != 0)) break;
      if (((cVar16 != -1) && (*(char *)((int)&param_1->_offset + 3) == cVar16)) &&
         ((uVar3 & 0x22) == 0)) goto LAB_001107b4;
    }
    iVar19 = _ureadc(uVar15,param_2);
    if (((iVar19 != 0) || (*(int *)(param_2 + 0x14) == 0)) ||
       (((uVar3 & 0x22) == 0 &&
        ((uVar15 == 10 ||
         (((uVar15 == *(byte *)((int)&param_1->_offset + 3) ||
           (uVar15 == *(byte *)((int)&param_1->_offset + 4))) && (uVar15 != 0xff))))))))
    goto LAB_001107b4;
    bVar8 = false;
  } while( true );
  _gsignal((int)*(short *)&(param_1->_lb)._base,0x12);
  if (!bVar8) {
LAB_001107b4:
    if ((int)param_1->_p < 0xcc) {
      uVar11 = _spltty();
      uVar3._0_1_ = param_1->_ubuf[0];
      uVar3._1_1_ = param_1->_ubuf[1];
      uVar3._2_1_ = param_1->_ubuf[2];
      uVar3._3_1_ = param_1->_nbuf[0];
      uVar3 = uVar3 & 0xff7fffff;
      param_1->_ubuf[0] = (char)uVar3;
      param_1->_ubuf[1] = (char)(uVar3 >> 8);
      param_1->_ubuf[2] = (char)(uVar3 >> 0x10);
      param_1->_nbuf[0] = (char)(uVar3 >> 0x18);
      _splx(uVar11);
      uVar6._0_1_ = param_1->_ubuf[0];
      uVar6._1_1_ = param_1->_ubuf[1];
      uVar6._2_1_ = param_1->_ubuf[2];
      uVar6._3_1_ = param_1->_nbuf[0];
      if ((((uVar6 & 0x1000400) == 0x400) &&
          (cVar16 = *(char *)((int)&param_1->_offset + 1), cVar16 != -1)) &&
         (iVar10 = _putc((int)cVar16,(FILE *)&param_1->_lbfsize), iVar10 == 0)) {
        uVar11 = _spltty();
        uVar2._0_1_ = param_1->_ubuf[0];
        uVar2._1_1_ = param_1->_ubuf[1];
        uVar2._2_1_ = param_1->_ubuf[2];
        uVar2._3_1_ = param_1->_nbuf[0];
        uVar2 = uVar2 & 0xfffffbff;
        param_1->_ubuf[0] = (char)uVar2;
        param_1->_ubuf[1] = (char)(uVar2 >> 8);
        param_1->_ubuf[2] = (char)(uVar2 >> 0x10);
        param_1->_nbuf[0] = (char)(uVar2 >> 0x18);
        _splx(uVar11);
        uVar11 = _spltty();
        uVar7._0_1_ = param_1->_ubuf[0];
        uVar7._1_1_ = param_1->_ubuf[1];
        uVar7._2_1_ = param_1->_ubuf[2];
        uVar7._3_1_ = param_1->_nbuf[0];
        if (((uVar7 & 0x4000121) == 0) && (param_1->_read != (_func_3 *)0x0)) {
          (*param_1->_read)(param_1,unaff_EBX,unaff_ESI);
        }
        _splx(uVar11);
      }
    }
    return iVar19;
  }
  _sleep((uint)param_1);
  goto LAB_001103bb;
}

