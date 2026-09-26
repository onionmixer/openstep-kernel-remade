/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010f2d0 */

void _ttyinput(int param_1,FILE *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  char *unaff_EBX;
  int unaff_ESI;
  uchar *local_10;
  int local_c;
  int local_8;
  
  iVar9 = _ttynty(param_2);
  if ((*(byte *)(iVar9 + 0x11) & 8) != 0) {
    if ((param_2->_ur & 0x20000000U) != 0) {
      param_2->_ur = param_2->_ur & 0xdfffffff;
      uVar1._0_1_ = param_2->_ubuf[0];
      uVar1._1_1_ = param_2->_ubuf[1];
      uVar1._2_1_ = param_2->_ubuf[2];
      uVar1._3_1_ = param_2->_nbuf[0];
      uVar1 = uVar1 | 0x100000;
      param_2->_ubuf[0] = (char)uVar1;
      param_2->_ubuf[1] = (char)(uVar1 >> 8);
      param_2->_ubuf[2] = (char)(uVar1 >> 0x10);
      param_2->_nbuf[0] = (char)(uVar1 >> 0x18);
      local_10 = param_2->_p;
      local_c = param_2->_r;
      local_8 = param_2->_w;
      param_2->_p = (uchar *)0x0;
      param_2->_w = 0;
      param_2->_r = 0;
      while( true ) {
        iVar10 = _getc((FILE *)&local_10);
        if (iVar10 < 0) break;
        _ttyinput(iVar10,param_2);
      }
      uVar2._0_1_ = param_2->_ubuf[0];
      uVar2._1_1_ = param_2->_ubuf[1];
      uVar2._2_1_ = param_2->_ubuf[2];
      uVar2._3_1_ = param_2->_nbuf[0];
      uVar2 = uVar2 & 0xffefffff;
      param_2->_ubuf[0] = (char)uVar2;
      param_2->_ubuf[1] = (char)(uVar2 >> 8);
      param_2->_ubuf[2] = (char)(uVar2 >> 0x10);
      param_2->_nbuf[0] = (char)(uVar2 >> 0x18);
    }
    _tk_nin = _tk_nin + 1;
    if ((param_1._3_1_ == '\0') && ((param_2->_ur & 0x20) != 0)) {
      if ((int)param_2->_p < 0x401) {
        iVar10 = _putc(param_1,param_2);
        if (-1 < iVar10) {
          iVar10 = _ttcheckwakeup(iVar9);
          if (iVar10 != 0) {
            _ttwakeup(param_2);
          }
          _ttyecho(param_1,iVar9);
        }
      }
      else {
        _log(4,s_tty_d__raw_input_overrun_001daf42,(int)*(short *)&param_2->_extra);
        _ttwakeup(param_2);
      }
      uVar1 = param_2->_ur;
      param_2->_ur = uVar1 & 0xff7fffff;
      if (((*(byte *)(iVar9 + 0x10) & 0x10) != 0) &&
         (((uVar1 & 0x40000000) == 0 ||
          ((cVar6 = *(char *)((int)&param_2->_offset + 2), cVar6 != -1 &&
           (*(char *)((int)&param_2->_offset + 1) == cVar6)))))) {
        uVar3._0_1_ = param_2->_ubuf[0];
        uVar3._1_1_ = param_2->_ubuf[1];
        uVar3._2_1_ = param_2->_ubuf[2];
        uVar3._3_1_ = param_2->_nbuf[0];
        uVar3 = uVar3 & 0xfffffeff;
        param_2->_ubuf[0] = (char)uVar3;
        param_2->_ubuf[1] = (char)(uVar3 >> 8);
        param_2->_ubuf[2] = (char)(uVar3 >> 0x10);
        param_2->_nbuf[0] = (char)(uVar3 >> 0x18);
      }
    }
    else {
      _ttcooked(param_1,iVar9);
    }
    if ((0x1ff < (int)(param_2->_p + *(int *)&param_2->_flags)) &&
       (((param_2->_ur & 0x22U) != 0 || (0 < *(int *)&param_2->_flags)))) {
      if (((param_2->_ur & 1U) != 0) && (cVar6 = *(char *)((int)&param_2->_offset + 2), cVar6 != -1)
         ) {
        iVar9 = _putc((int)cVar6,(FILE *)&param_2->_lbfsize);
        if (iVar9 == 0) {
          uVar4._0_1_ = param_2->_ubuf[0];
          uVar4._1_1_ = param_2->_ubuf[1];
          uVar4._2_1_ = param_2->_ubuf[2];
          uVar4._3_1_ = param_2->_nbuf[0];
          uVar4 = uVar4 | 0x400;
          param_2->_ubuf[0] = (char)uVar4;
          param_2->_ubuf[1] = (char)(uVar4 >> 8);
          param_2->_ubuf[2] = (char)(uVar4 >> 0x10);
          param_2->_nbuf[0] = (char)(uVar4 >> 0x18);
          uVar11 = _spltty();
          uVar7._0_1_ = param_2->_ubuf[0];
          uVar7._1_1_ = param_2->_ubuf[1];
          uVar7._2_1_ = param_2->_ubuf[2];
          uVar7._3_1_ = param_2->_nbuf[0];
          if (((uVar7 & 0x4000121) == 0) && (param_2->_read != (_func_3 *)0x0)) {
            (*param_2->_read)(param_2,unaff_EBX,unaff_ESI);
          }
          _splx(uVar11);
        }
      }
      uVar5._0_1_ = param_2->_ubuf[0];
      uVar5._1_1_ = param_2->_ubuf[1];
      uVar5._2_1_ = param_2->_ubuf[2];
      uVar5._3_1_ = param_2->_nbuf[0];
      uVar5 = uVar5 | 0x800000;
      param_2->_ubuf[0] = (char)uVar5;
      param_2->_ubuf[1] = (char)(uVar5 >> 8);
      param_2->_ubuf[2] = (char)(uVar5 >> 0x10);
      param_2->_nbuf[0] = (char)(uVar5 >> 0x18);
    }
    uVar11 = _spltty();
    uVar8._0_1_ = param_2->_ubuf[0];
    uVar8._1_1_ = param_2->_ubuf[1];
    uVar8._2_1_ = param_2->_ubuf[2];
    uVar8._3_1_ = param_2->_nbuf[0];
    if (((uVar8 & 0x4000121) == 0) && (param_2->_read != (_func_3 *)0x0)) {
      (*param_2->_read)(param_2,unaff_EBX,unaff_ESI);
    }
    _splx(uVar11);
  }
  return;
}

