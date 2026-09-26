/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010de30 */

void _ttyflush(FILE *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = _spltty();
  if ((param_2 & 1) != 0) {
    do {
      iVar4 = _getc((FILE *)&param_1->_flags);
    } while (-1 < iVar4);
    _wakeup(param_1);
  }
  if ((param_2 & 2) != 0) {
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
              (param_1,param_2);
    do {
      iVar4 = _getc((FILE *)&param_1->_lbfsize);
    } while (-1 < iVar4);
  }
  if ((param_2 & 1) != 0) {
    do {
      iVar4 = _getc(param_1);
    } while (-1 < iVar4);
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
  }
  _splx(uVar3);
  return;
}

