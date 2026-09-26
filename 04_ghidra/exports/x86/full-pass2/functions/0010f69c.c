/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010f69c */

void _ttcooked(uint param_1,undefined4 *param_2)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  FILE *pFVar9;
  uint uVar10;
  uint uVar11;
  uchar *puVar12;
  uint uVar13;
  char cVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  undefined1 *puVar22;
  uint uVar23;
  
  pFVar9 = (FILE *)*param_2;
  uVar10 = pFVar9->_ur;
  uVar11 = param_2[4];
  uVar23 = param_1;
  if ((param_1 & 0xff000000) == 0) {
LAB_0010f7e9:
    if ((((pFVar9->_ubuf[2] & 0x10) == 0) && ((uVar10 & 0x8000020) == 0)) &&
       ((uVar11 & 0x400000) != 0)) {
      uVar23 = uVar23 & 0xffffff7f;
    }
    uVar16._0_1_ = pFVar9->_ubuf[0];
    uVar16._1_1_ = pFVar9->_ubuf[1];
    uVar16._2_1_ = pFVar9->_ubuf[2];
    uVar16._3_1_ = pFVar9->_nbuf[0];
    if ((uVar16 & 0x80000) != 0) {
      uVar23 = uVar23 | 0x100;
      uVar16 = uVar16 & 0xfff7ffff;
      pFVar9->_ubuf[0] = (char)uVar16;
      pFVar9->_ubuf[1] = (char)(uVar16 >> 8);
      pFVar9->_ubuf[2] = (char)(uVar16 >> 0x10);
      pFVar9->_nbuf[0] = (char)(uVar16 >> 0x18);
    }
    if ((((uVar23 & 0x100) != 0) || ((pFVar9->_ubuf[2] & 0x40) != 0)) ||
       ((*(int *)(pFVar9[1]._ubuf + ((int)uVar23 >> 5) * 4 + -0x34) >> ((byte)uVar23 & 0x1f) & 1U)
        == 0)) {
LAB_0010fbb1:
      if ((uVar10 & 0x22) == 0) goto LAB_0010fe90;
LAB_0010fbe0:
      if ((int)pFVar9->_p < 0x401) {
        iVar15 = _putc(uVar23,pFVar9);
        if (-1 < iVar15) {
          iVar15 = _ttcheckwakeup();
          if (iVar15 != 0) {
            _ttwakeup();
          }
          _ttyecho();
        }
      }
      else {
        if ((pFVar9->_lbfsize <
             (int)*(short *)(&_tthiwat + (*(byte *)((int)&(pFVar9->_lb)._size + 2) & 0x1f) * 2)) &&
           ((uVar11 & 0x8000000) != 0)) {
          _ttyoutput();
        }
LAB_0010fecf:
        _log();
      }
      goto LAB_0010ffd4;
    }
    if (((undefined *)(uVar11 & 0x181000) == &DAT_00101000) && (uVar23 == 0xff)) {
      _putc(0x1ff,pFVar9);
      uVar23 = 0x1ff;
    }
    cVar14 = (char)uVar23;
    if (((uVar11 & 0x10) != 0) && (cVar14 != -1)) {
      if (*(char *)((int)&pFVar9[1]._p + 2) == cVar14) {
        if ((uVar10 & 8) != 0) {
          if ((uVar10 & 0x40000) == 0) {
            _ttyecho();
          }
          else {
            _ttyoutstr();
          }
        }
        uVar2._0_1_ = pFVar9->_ubuf[0];
        uVar2._1_1_ = pFVar9->_ubuf[1];
        uVar2._2_1_ = pFVar9->_ubuf[2];
        uVar2._3_1_ = pFVar9->_nbuf[0];
        uVar2 = uVar2 | 0x80000;
        pFVar9->_ubuf[0] = (char)uVar2;
        pFVar9->_ubuf[1] = (char)(uVar2 >> 8);
        pFVar9->_ubuf[2] = (char)(uVar2 >> 0x10);
        pFVar9->_nbuf[0] = (char)(uVar2 >> 0x18);
        goto LAB_0010ffd4;
      }
      if ((cVar14 != -1) && (*(char *)&pFVar9[1]._p == cVar14)) {
        if ((uVar10 & 0x800000) == 0) {
          _spltty();
          _wakeup();
          uVar11._0_1_ = pFVar9->_ubuf[0];
          uVar11._1_1_ = pFVar9->_ubuf[1];
          uVar11._2_1_ = pFVar9->_ubuf[2];
          uVar11._3_1_ = pFVar9->_nbuf[0];
          uVar11 = uVar11 & 0xfffffeff;
          pFVar9->_ubuf[0] = (char)uVar11;
          pFVar9->_ubuf[1] = (char)(uVar11 >> 8);
          pFVar9->_ubuf[2] = (char)(uVar11 >> 0x10);
          pFVar9->_nbuf[0] = (char)(uVar11 >> 0x18);
          (*(code *)(&PTR__nulldev_001e2f4c)[(uint)*(byte *)((int)&pFVar9->_extra + 1) * 0xb])();
          do {
            iVar15 = _getc((FILE *)&pFVar9->_lbfsize);
          } while (-1 < iVar15);
          _splx();
          _ttyecho();
          if (pFVar9->_p + *(int *)&pFVar9->_flags != (uchar *)0x0) {
            _ttyretype();
          }
          pFVar9->_ur = pFVar9->_ur | 0x800000;
          return;
        }
        goto LAB_00110000;
      }
    }
    if (((uVar11 & 8) != 0) && (cVar14 != -1)) {
      if ((*(char *)((int)&pFVar9->_blksize + 3) == cVar14) || ((char)pFVar9->_offset == cVar14)) {
        if (-1 < (int)uVar10) {
          _spltty();
          do {
            iVar15 = _getc((FILE *)&pFVar9->_flags);
          } while (-1 < iVar15);
          _wakeup();
          _wakeup();
          uVar3._0_1_ = pFVar9->_ubuf[0];
          uVar3._1_1_ = pFVar9->_ubuf[1];
          uVar3._2_1_ = pFVar9->_ubuf[2];
          uVar3._3_1_ = pFVar9->_nbuf[0];
          uVar3 = uVar3 & 0xfffffeff;
          pFVar9->_ubuf[0] = (char)uVar3;
          pFVar9->_ubuf[1] = (char)(uVar3 >> 8);
          pFVar9->_ubuf[2] = (char)(uVar3 >> 0x10);
          pFVar9->_nbuf[0] = (char)(uVar3 >> 0x18);
          (*(code *)(&PTR__nulldev_001e2f4c)[(uint)*(byte *)((int)&pFVar9->_extra + 1) * 0xb])();
          do {
            iVar15 = _getc((FILE *)&pFVar9->_lbfsize);
          } while (-1 < iVar15);
          do {
            iVar15 = _getc(pFVar9);
          } while (-1 < iVar15);
          *(undefined1 *)((int)&(pFVar9->_lb)._size + 3) = 0;
          *(undefined1 *)&pFVar9->_blksize = 0;
          uVar4._0_1_ = pFVar9->_ubuf[0];
          uVar4._1_1_ = pFVar9->_ubuf[1];
          uVar4._2_1_ = pFVar9->_ubuf[2];
          uVar4._3_1_ = pFVar9->_nbuf[0];
          uVar4 = uVar4 & 0xff40ffff;
          pFVar9->_ubuf[0] = (char)uVar4;
          pFVar9->_ubuf[1] = (char)(uVar4 >> 8);
          pFVar9->_ubuf[2] = (char)(uVar4 >> 0x10);
          pFVar9->_nbuf[0] = (char)(uVar4 >> 0x18);
          _splx();
        }
        _ttyecho();
        puVar22 = &stack0xffffffd4;
      }
      else {
        if ((cVar14 == -1) || (*(char *)((int)&pFVar9->_offset + 5) != cVar14)) goto LAB_0010fabc;
        if (-1 < (int)uVar10) {
          _spltty();
          do {
            iVar15 = _getc((FILE *)&pFVar9->_flags);
          } while (-1 < iVar15);
          _wakeup();
          do {
            iVar15 = _getc(pFVar9);
          } while (-1 < iVar15);
          *(undefined1 *)((int)&(pFVar9->_lb)._size + 3) = 0;
          *(undefined1 *)&pFVar9->_blksize = 0;
          uVar5._0_1_ = pFVar9->_ubuf[0];
          uVar5._1_1_ = pFVar9->_ubuf[1];
          uVar5._2_1_ = pFVar9->_ubuf[2];
          uVar5._3_1_ = pFVar9->_nbuf[0];
          uVar5 = uVar5 & 0xff40ffff;
          pFVar9->_ubuf[0] = (char)uVar5;
          pFVar9->_ubuf[1] = (char)(uVar5 >> 8);
          pFVar9->_ubuf[2] = (char)(uVar5 >> 0x10);
          pFVar9->_nbuf[0] = (char)(uVar5 >> 0x18);
          _splx();
        }
        _ttyecho();
        puVar22 = &stack0xffffffcc;
      }
LAB_0010faac:
      *(int *)(puVar22 + -4) = (int)*(short *)&(pFVar9->_lb)._base;
      *(undefined4 *)(puVar22 + -8) = 0x10fab6;
      _gsignal();
      goto LAB_0010ffd4;
    }
LAB_0010fabc:
    if (((uVar11 & 0x4000000) == 0) || (cVar14 == -1)) {
LAB_0010fb28:
      if (uVar23 == 0xd) {
        if ((uVar11 & 0x1000000) != 0) goto LAB_0010ffd4;
        if (((uVar10 & 0x10) != 0) || ((uVar11 & 0x2000000) != 0)) {
          uVar23 = 10;
        }
      }
      else if ((uVar23 == 10) && ((uVar11 & 0x800000) != 0)) {
        uVar23 = 0xd;
      }
      if (((uVar10 & 4) != 0) && ((int)uVar23 < 0x80)) {
        uVar20._0_1_ = pFVar9->_ubuf[0];
        uVar20._1_1_ = pFVar9->_ubuf[1];
        uVar20._2_1_ = pFVar9->_ubuf[2];
        uVar20._3_1_ = pFVar9->_nbuf[0];
        if ((uVar20 & 0x10000) != 0) {
          _unputc();
          _ttyrub();
          if ((&_maptab)[uVar23] != '\0') {
            uVar23 = (uint)(char)(&_maptab)[uVar23];
          }
          uVar23 = uVar23 | 0x100;
          uVar6._0_1_ = pFVar9->_ubuf[0];
          uVar6._1_1_ = pFVar9->_ubuf[1];
          uVar6._2_1_ = pFVar9->_ubuf[2];
          uVar6._3_1_ = pFVar9->_nbuf[0];
          uVar6 = uVar6 & 0xfffcffff;
          pFVar9->_ubuf[0] = (char)uVar6;
          pFVar9->_ubuf[1] = (char)(uVar6 >> 8);
          pFVar9->_ubuf[2] = (char)(uVar6 >> 0x10);
          pFVar9->_nbuf[0] = (char)(uVar6 >> 0x18);
          goto LAB_0010fbb1;
        }
        if (uVar23 - 0x41 < 0x1a) {
          uVar23 = uVar23 + 0x20;
        }
        else if (uVar23 == 0x5c) {
          uVar20 = uVar20 | 0x10000;
          pFVar9->_ubuf[0] = (char)uVar20;
          pFVar9->_ubuf[1] = (char)(uVar20 >> 8);
          pFVar9->_ubuf[2] = (char)(uVar20 >> 0x10);
          pFVar9->_nbuf[0] = (char)(uVar20 >> 0x18);
        }
      }
      if ((uVar10 & 0x22) != 0) goto LAB_0010fbe0;
      cVar14 = (char)uVar23;
      if ((pFVar9->_ubuf[2] & 2) == 0) {
LAB_0010fc98:
        if (cVar14 != -1) {
          if (*(char *)((int)&pFVar9->_blksize + 1) == cVar14) {
            if (pFVar9->_p != (uchar *)0x0) {
              cVar14 = _unputc();
              _ttyrub();
              if ((((uVar10 & 0x80000) != 0) && (cVar14 < '\0')) &&
                 ((pFVar9->_p != (uchar *)0x0 && (cVar14 = _unputc(), cVar14 != -0x72)))) {
                _ttyrub();
              }
            }
          }
          else {
            if (cVar14 == -1) goto LAB_0010fe90;
            if (*(char *)((int)&pFVar9->_blksize + 2) == cVar14) {
              if ((((uVar11 & 4) == 0) || ((uVar10 & 0x4000000) == 0)) ||
                 (puVar12 = pFVar9->_p,
                 puVar12 != (uchar *)(int)*(char *)((int)&(pFVar9->_lb)._size + 3))) {
                _ttyecho();
                if ((uVar11 & 4) != 0) {
                  _ttyecho();
                }
                do {
                  iVar15 = _getc(pFVar9);
                } while (0 < iVar15);
                *(undefined1 *)((int)&(pFVar9->_lb)._size + 3) = 0;
              }
              else {
                while (puVar12 != (uchar *)0x0) {
                  _unputc();
                  _ttyrub();
                  puVar12 = pFVar9->_p;
                }
              }
              uVar7._0_1_ = pFVar9->_ubuf[0];
              uVar7._1_1_ = pFVar9->_ubuf[1];
              uVar7._2_1_ = pFVar9->_ubuf[2];
              uVar7._3_1_ = pFVar9->_nbuf[0];
              uVar7 = uVar7 & 0xffc0ffff;
              pFVar9->_ubuf[0] = (char)uVar7;
              pFVar9->_ubuf[1] = (char)(uVar7 >> 8);
              pFVar9->_ubuf[2] = (char)(uVar7 >> 0x10);
              pFVar9->_nbuf[0] = (char)(uVar7 >> 0x18);
            }
            else {
              if (cVar14 == -1) goto LAB_0010fe90;
              if (*(char *)((int)&pFVar9[1]._p + 1) == cVar14) {
                while ((iVar15 = _unputc(), iVar15 == 0x20 || (iVar15 == 9))) {
                  _ttyrub();
                }
                if (iVar15 != -1) {
                  _ttyrub();
                  uVar23 = _unputc();
                  if (uVar23 != 0xffffffff) {
                    bVar8 = (&_partab)[uVar23 & 0xff];
                    do {
                      if (((uVar23 == 0x20) || (uVar23 == 9)) ||
                         (((uVar11 & 0x20) != 0 &&
                          (((&_partab)[uVar23 & 0xff] & 0x40) != (bVar8 & 0x40))))) {
                        _putc(uVar23,pFVar9);
                        break;
                      }
                      _ttyrub();
                      uVar23 = _unputc();
                    } while (uVar23 != 0xffffffff);
                  }
                }
              }
              else {
                if ((cVar14 == -1) || (*(char *)((int)&pFVar9->_offset + 7) != cVar14))
                goto LAB_0010fe90;
                _ttyretype();
              }
            }
          }
          goto LAB_0010ffd4;
        }
      }
      else if (cVar14 != -1) {
        if ((*(char *)((int)&pFVar9->_blksize + 1) != cVar14) &&
           (*(char *)((int)&pFVar9->_blksize + 2) != cVar14)) goto LAB_0010fc98;
        _unputc();
        _ttyrub();
        uVar23 = uVar23 | 0x100;
      }
LAB_0010fe90:
      if (0x3ff < (int)(pFVar9->_p + *(int *)&pFVar9->_flags)) {
        if (((uVar11 & 0x8000000) != 0) &&
           (pFVar9->_lbfsize <
            (int)*(short *)(&_tthiwat + (*(byte *)((int)&(pFVar9->_lb)._size + 2) & 0x1f) * 2))) {
          _ttyoutput();
        }
        goto LAB_0010fecf;
      }
      iVar15 = _putc(uVar23,pFVar9);
      if (-1 < iVar15) {
        if ((uVar23 == 10) ||
           (((uVar23 == *(byte *)((int)&pFVar9->_offset + 3) ||
             (uVar23 == *(byte *)((int)&pFVar9->_offset + 4))) && (uVar23 != 0xff)))) {
          *(undefined1 *)((int)&(pFVar9->_lb)._size + 3) = 0;
          _catq();
          _ttwakeup();
        }
        else {
          cVar14 = *(char *)((int)&(pFVar9->_lb)._size + 3);
          pcVar1 = (char *)((int)&(pFVar9->_lb)._size + 3);
          *pcVar1 = *pcVar1 + '\x01';
          if (cVar14 == '\0') {
            *(char *)&pFVar9->_blksize = (char)(pFVar9->_lb)._size;
          }
        }
        uVar13._0_1_ = pFVar9->_ubuf[0];
        uVar13._1_1_ = pFVar9->_ubuf[1];
        uVar13._2_1_ = pFVar9->_ubuf[2];
        uVar13._3_1_ = pFVar9->_nbuf[0];
        uVar21 = uVar13 & 0xfffdffff;
        pFVar9->_ubuf[0] = (char)uVar21;
        pFVar9->_ubuf[1] = (char)(uVar21 >> 8);
        pFVar9->_ubuf[2] = (char)(uVar21 >> 0x10);
        pFVar9->_nbuf[0] = (char)(uVar21 >> 0x18);
        if ((uVar13 & 0x400000) == 0) {
          cVar14 = (char)uVar23;
          if ((cVar14 != -1) && (*(char *)(param_2 + 5) == cVar14)) {
            uVar21 = uVar21 | 0x20000;
            pFVar9->_ubuf[0] = (char)uVar21;
            pFVar9->_ubuf[1] = (char)(uVar21 >> 8);
            pFVar9->_ubuf[2] = (char)(uVar21 >> 0x10);
            pFVar9->_nbuf[0] = (char)(uVar21 >> 0x18);
          }
          uVar18._0_1_ = pFVar9->_ubuf[0];
          uVar18._1_1_ = pFVar9->_ubuf[1];
          uVar18._2_1_ = pFVar9->_ubuf[2];
          uVar18._3_1_ = pFVar9->_nbuf[0];
          if ((uVar18 & 0x40000) != 0) {
            uVar18 = uVar18 & 0xfffbffff;
            pFVar9->_ubuf[0] = (char)uVar18;
            pFVar9->_ubuf[1] = (char)(uVar18 >> 8);
            pFVar9->_ubuf[2] = (char)(uVar18 >> 0x10);
            pFVar9->_nbuf[0] = (char)(uVar18 >> 0x18);
            _ttyoutput();
          }
          iVar15 = (pFVar9->_lb)._size;
          _ttyecho();
          if (((cVar14 != -1) && (*(char *)((int)&pFVar9->_offset + 3) == cVar14)) &&
             ((uVar10 & 8) != 0)) {
            iVar19 = (int)(char)(pFVar9->_lb)._size - (int)(char)iVar15;
            iVar15 = 2;
            if (iVar19 < 3) {
              iVar15 = iVar19;
            }
            for (; 0 < iVar15; iVar15 = iVar15 + -1) {
              _ttyoutput();
            }
          }
        }
      }
      goto LAB_0010ffd4;
    }
    if (*(char *)((int)&pFVar9->_offset + 2) == cVar14) {
      uVar17._0_1_ = pFVar9->_ubuf[0];
      uVar17._1_1_ = pFVar9->_ubuf[1];
      uVar17._2_1_ = pFVar9->_ubuf[2];
      uVar17._3_1_ = pFVar9->_nbuf[0];
      if ((uVar17 & 0x100) == 0) {
        uVar17 = uVar17 | 0x100;
        pFVar9->_ubuf[0] = (char)uVar17;
        pFVar9->_ubuf[1] = (char)(uVar17 >> 8);
        pFVar9->_ubuf[2] = (char)(uVar17 >> 0x10);
        pFVar9->_nbuf[0] = (char)(uVar17 >> 0x18);
        (*(code *)(&PTR__nulldev_001e2f4c)[(uint)*(byte *)((int)&pFVar9->_extra + 1) * 0xb])();
        return;
      }
      if (cVar14 == -1) {
        return;
      }
      if (*(char *)((int)&pFVar9->_offset + 1) != cVar14) {
        return;
      }
      goto LAB_0010ffd4;
    }
    if ((cVar14 == -1) || (*(char *)((int)&pFVar9->_offset + 1) != cVar14)) goto LAB_0010fb28;
  }
  else {
    uVar23 = param_1 & 0xffffff;
    if (((param_1 & 0x1000000) == 0) || (uVar23 != 0)) {
      if ((((param_1 & 0x2000000) != 0) && ((uVar11 & 0x200000) != 0)) ||
         ((param_1 & 0x1000000) != 0)) {
        if ((uVar11 & 0x80000) != 0) goto LAB_0010ffd4;
        if ((uVar11 & 0x100000) != 0) goto LAB_0010f7c0;
        uVar23 = 0x100;
      }
      goto LAB_0010f7e9;
    }
    if ((uVar11 & 0x20000) == 0) {
      if ((uVar11 & 0x40000) == 0) {
        if ((uVar11 & 0x100000) != 0) {
LAB_0010f7c0:
          _putc(0x1ff,pFVar9);
          _putc(0x100,pFVar9);
          uVar23 = uVar23 | 0x100;
        }
        goto LAB_0010f7e9;
      }
      _spltty();
      do {
        iVar15 = _getc((FILE *)&pFVar9->_flags);
      } while (-1 < iVar15);
      _wakeup();
      _wakeup();
      uVar23._0_1_ = pFVar9->_ubuf[0];
      uVar23._1_1_ = pFVar9->_ubuf[1];
      uVar23._2_1_ = pFVar9->_ubuf[2];
      uVar23._3_1_ = pFVar9->_nbuf[0];
      uVar23 = uVar23 & 0xfffffeff;
      pFVar9->_ubuf[0] = (char)uVar23;
      pFVar9->_ubuf[1] = (char)(uVar23 >> 8);
      pFVar9->_ubuf[2] = (char)(uVar23 >> 0x10);
      pFVar9->_nbuf[0] = (char)(uVar23 >> 0x18);
      (*(code *)(&PTR__nulldev_001e2f4c)[(uint)*(byte *)((int)&pFVar9->_extra + 1) * 0xb])();
      do {
        iVar15 = _getc((FILE *)&pFVar9->_lbfsize);
      } while (-1 < iVar15);
      do {
        iVar15 = _getc(pFVar9);
      } while (-1 < iVar15);
      *(undefined1 *)((int)&(pFVar9->_lb)._size + 3) = 0;
      *(undefined1 *)&pFVar9->_blksize = 0;
      uVar21._0_1_ = pFVar9->_ubuf[0];
      uVar21._1_1_ = pFVar9->_ubuf[1];
      uVar21._2_1_ = pFVar9->_ubuf[2];
      uVar21._3_1_ = pFVar9->_nbuf[0];
      uVar21 = uVar21 & 0xff40ffff;
      pFVar9->_ubuf[0] = (char)uVar21;
      pFVar9->_ubuf[1] = (char)(uVar21 >> 8);
      pFVar9->_ubuf[2] = (char)(uVar21 >> 0x10);
      pFVar9->_nbuf[0] = (char)(uVar21 >> 0x18);
      _splx();
      puVar22 = &stack0xffffffd4;
      goto LAB_0010faac;
    }
LAB_0010ffd4:
    if ((uVar11 & 0x10) == 0) {
      return;
    }
    if (((uVar10 & 0x40000000) != 0) && ((pFVar9->_ubuf[1] & 1) != 0)) {
      cVar14 = *(char *)((int)&pFVar9->_offset + 2);
      if (cVar14 == -1) {
        return;
      }
      if (*(char *)((int)&pFVar9->_offset + 1) != cVar14) {
        return;
      }
    }
  }
  uVar10._0_1_ = pFVar9->_ubuf[0];
  uVar10._1_1_ = pFVar9->_ubuf[1];
  uVar10._2_1_ = pFVar9->_ubuf[2];
  uVar10._3_1_ = pFVar9->_nbuf[0];
  uVar10 = uVar10 & 0xfffffeff;
  pFVar9->_ubuf[0] = (char)uVar10;
  pFVar9->_ubuf[1] = (char)(uVar10 >> 8);
  pFVar9->_ubuf[2] = (char)(uVar10 >> 0x10);
  pFVar9->_nbuf[0] = (char)(uVar10 >> 0x18);
LAB_00110000:
  pFVar9->_ur = pFVar9->_ur & 0xff7fffff;
  return;
}

