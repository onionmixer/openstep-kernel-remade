/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010f0b4 */

undefined4 _ttymodem(FILE *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  char *unaff_EBX;
  int unaff_ESI;
  
  iVar5 = _ttynty(param_1);
  uVar6._0_1_ = param_1->_ubuf[0];
  uVar6._1_1_ = param_1->_ubuf[1];
  uVar6._2_1_ = param_1->_ubuf[2];
  uVar6._3_1_ = param_1->_nbuf[0];
  if (((uVar6 & 2) == 0) && ((param_1->_ur & 0x100000) != 0)) {
    if (param_2 == 0) {
      if ((uVar6 & 0x100) == 0) {
        uVar6 = uVar6 | 0x100;
        param_1->_ubuf[0] = (char)uVar6;
        param_1->_ubuf[1] = (char)(uVar6 >> 8);
        param_1->_ubuf[2] = (char)(uVar6 >> 0x10);
        param_1->_nbuf[0] = (char)(uVar6 >> 0x18);
        (*(code *)(&PTR__nulldev_001e2f4c)[(uint)*(byte *)((int)&param_1->_extra + 1) * 0xb])
                  (param_1,0);
      }
    }
    else {
      uVar6 = uVar6 & 0xfffffeff;
      param_1->_ubuf[0] = (char)uVar6;
      param_1->_ubuf[1] = (char)(uVar6 >> 8);
      param_1->_ubuf[2] = (char)(uVar6 >> 0x10);
      param_1->_nbuf[0] = (char)(uVar6 >> 0x18);
      uVar7 = _spltty();
      uVar3._0_1_ = param_1->_ubuf[0];
      uVar3._1_1_ = param_1->_ubuf[1];
      uVar3._2_1_ = param_1->_ubuf[2];
      uVar3._3_1_ = param_1->_nbuf[0];
      if (((uVar3 & 0x4000121) == 0) && (param_1->_read != (_func_3 *)0x0)) {
        (*param_1->_read)(param_1,unaff_EBX,unaff_ESI);
      }
      _splx(uVar7);
    }
  }
  else if (param_2 == 0) {
    uVar4._0_1_ = param_1->_ubuf[0];
    uVar4._1_1_ = param_1->_ubuf[1];
    uVar4._2_1_ = param_1->_ubuf[2];
    uVar4._3_1_ = param_1->_nbuf[0];
    uVar6 = uVar4 & 0xffffffef;
    param_1->_ubuf[0] = (char)uVar6;
    param_1->_ubuf[1] = (char)(uVar6 >> 8);
    param_1->_ubuf[2] = (char)(uVar6 >> 0x10);
    param_1->_nbuf[0] = (char)(uVar6 >> 0x18);
    if ((((uVar4 & 4) != 0) && (-1 < *(short *)(iVar5 + 0x10))) &&
       (_ttwakeup(param_1), (param_1->_ur & 0x1000000) == 0)) {
      _gsignal((int)*(short *)&(param_1->_lb)._base,1);
      _gsignal((int)*(short *)&(param_1->_lb)._base,0x13);
      uVar7 = _spltty();
      do {
        iVar5 = _getc((FILE *)&param_1->_flags);
      } while (-1 < iVar5);
      _wakeup(param_1);
      _wakeup(&param_1->_lbfsize);
      uVar1._0_1_ = param_1->_ubuf[0];
      uVar1._1_1_ = param_1->_ubuf[1];
      uVar1._2_1_ = param_1->_ubuf[2];
      uVar1._3_1_ = param_1->_nbuf[0];
      uVar1 = uVar1 & 0xfffffeff;
      param_1->_ubuf[0] = (char)uVar1;
      param_1->_ubuf[1] = (char)(uVar1 >> 8);
      param_1->_ubuf[2] = (char)(uVar1 >> 0x10);
      param_1->_nbuf[0] = (char)(uVar1 >> 0x18);
      (*(code *)(&PTR__nulldev_001e2f4c)[(uint)*(byte *)((int)&param_1->_extra + 1) * 0xb])
                (param_1,3);
      do {
        iVar5 = _getc((FILE *)&param_1->_lbfsize);
      } while (-1 < iVar5);
      do {
        iVar5 = _getc(param_1);
      } while (-1 < iVar5);
      *(undefined1 *)((int)&(param_1->_lb)._size + 3) = 0;
      *(undefined1 *)&param_1->_blksize = 0;
      uVar2._0_1_ = param_1->_ubuf[0];
      uVar2._1_1_ = param_1->_ubuf[1];
      uVar2._2_1_ = param_1->_ubuf[2];
      uVar2._3_1_ = param_1->_nbuf[0];
      uVar2 = uVar2 & 0xff40ffff;
      param_1->_ubuf[0] = (char)uVar2;
      param_1->_ubuf[1] = (char)(uVar2 >> 8);
      param_1->_ubuf[2] = (char)(uVar2 >> 0x10);
      param_1->_nbuf[0] = (char)(uVar2 >> 0x18);
      _splx(uVar7);
      return 0;
    }
  }
  else {
    param_1->_ubuf[0] = param_1->_ubuf[0] | 0x10;
    _wakeup(param_1);
  }
  return 1;
}

