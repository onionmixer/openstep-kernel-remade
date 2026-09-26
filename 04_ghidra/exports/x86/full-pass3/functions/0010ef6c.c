/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010ef6c */

void _ttyclose(FILE *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar3 = _ttynty(param_1);
  if (_cons_tp == param_1) {
    _cons_tp = (FILE *)&_cons;
    (*(code *)(&PTR__cnioctl_001e2f48)[(uint)*(byte *)((int)&param_1->_extra + 1) * 0xb])
              ((int)*(short *)&param_1->_extra,0x20006b08,0,0);
  }
  uVar4 = _spltty();
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
  (*(code *)(&PTR__nulldev_001e2f4c)[(uint)*(byte *)((int)&param_1->_extra + 1) * 0xb])(param_1,3);
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
  _splx(uVar4);
  if ((*(byte *)(*_active_u + 0x16) & 2) != 0) {
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0;
  }
  if ((FILE *)_active_u[0x5a] == param_1) {
    *(uint *)(*_active_u + 0x28) = *(uint *)(*_active_u + 0x28) & 0xbfffffff;
  }
  *(undefined2 *)&(param_1->_lb)._base = 0;
  param_1->_ubuf[0] = '\0';
  param_1->_ubuf[1] = '\0';
  param_1->_ubuf[2] = '\0';
  param_1->_nbuf[0] = '\0';
  *(undefined1 *)((int)&(param_1->_lb)._base + 3) = 0;
  param_1[1]._write = (_func_5 *)0x0;
  uVar4 = _spltty();
  _selthreadclear(&param_1->_write);
  _selthreadclear(&param_1->_seek);
  _splx(uVar4);
  return;
}

