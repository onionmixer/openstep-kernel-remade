/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010df60 */

int _ttioctl(FILE *param_1,int param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  uchar *puVar14;
  uchar *puVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  uint uVar25;
  void *pvVar26;
  char *unaff_EBX;
  undefined1 *puVar27;
  undefined1 *puVar28;
  int unaff_ESI;
  uint uVar29;
  uint uVar30;
  uint local_38;
  undefined4 local_1c;
  
  iVar20 = _ttynty();
  puVar27 = &stack0xffffffbc;
  if (param_2 == -0x7ff98bef) {
LAB_0010e07e:
    while ((((iVar21 = *_active_u, *(short *)&(param_1->_lb)._base != *(short *)(iVar21 + 0x2e) &&
             ((FILE *)_active_u[0x5a] == param_1)) && ((*(byte *)(iVar21 + 0x29) & 0x10) == 0)) &&
           (((*(byte *)(iVar21 + 0x22) & 0x20) == 0 && ((*(byte *)(iVar21 + 0x1e) & 0x20) == 0)))))
    {
      _gsignal();
      _sleep(0x1e8df0);
    }
  }
  else {
    if (-0x7ff98bef < param_2) {
      if (param_2 != 0x2000745e) {
        if (param_2 < 0x2000745f) {
          if (param_2 != -0x7ff78b99) {
            if (param_2 < -0x7ff78b98) {
              if (param_2 == -0x7ff98b8b) goto LAB_0010e07e;
            }
            else if ((param_2 < -0x7fdb8be9) && (-0x7fdb8bed < param_2)) goto LAB_0010e07e;
            goto LAB_0010e0ac;
          }
        }
        else if ((param_2 < 0x2000746e) ||
                ((0x2000746f < param_2 && ((0x2000747b < param_2 || (param_2 < 0x2000747a))))))
        goto LAB_0010e0ac;
      }
      goto LAB_0010e07e;
    }
    if (param_2 == -0x7ffb8b8a) goto LAB_0010e07e;
    if (-0x7ffb8b8a < param_2) {
      if ((param_2 < -0x7ffb8b83) ||
         ((-0x7ffb8b81 < param_2 && ((-0x7ff98bf6 < param_2 || (param_2 < -0x7ff98bf7))))))
      goto LAB_0010e0ac;
      goto LAB_0010e07e;
    }
    if (param_2 == -0x7ffb8bff) goto LAB_0010e07e;
    if (param_2 < -0x7ffb8bfe) {
      if (param_2 == -0x7ffe8b8e) goto LAB_0010e07e;
    }
    else if (param_2 == -0x7ffb8bf0) goto LAB_0010e07e;
  }
LAB_0010e0ac:
  if (param_2 == 0x20007402) {
    _spltty();
    uVar30._0_1_ = param_1->_ubuf[0];
    uVar30._1_1_ = param_1->_ubuf[1];
    uVar30._2_1_ = param_1->_ubuf[2];
    uVar30._3_1_ = param_1->_nbuf[0];
    uVar30 = uVar30 | 0x200;
    param_1->_ubuf[0] = (char)uVar30;
    param_1->_ubuf[1] = (char)(uVar30 >> 8);
    param_1->_ubuf[2] = (char)(uVar30 >> 0x10);
    param_1->_nbuf[0] = (char)(uVar30 >> 0x18);
    goto LAB_0010e53c;
  }
  if (0x20007402 < param_2) {
    if (param_2 == 0x40047460) {
      uVar29._0_1_ = param_1->_ubuf[0];
      uVar29._1_1_ = param_1->_ubuf[1];
      uVar29._2_1_ = param_1->_ubuf[2];
      uVar29._3_1_ = param_1->_nbuf[0];
LAB_0010e8b0:
      *param_3 = uVar29;
      return 0;
    }
    if (param_2 < 0x40047461) {
      if (param_2 == 0x20007468) {
        if (param_1 != (FILE *)&_cons) {
          (*(code *)(&PTR__cnioctl_001e2f48)[(uint)*(byte *)((int)&_cons_tp->_extra + 1) * 0xb])
                    ((int)*(short *)&_cons_tp->_extra);
        }
        _cons_tp = param_1;
        return 0;
      }
      if (param_2 < 0x20007469) {
        if (param_2 != 0x2000740e) {
          if (0x2000740e < param_2) {
            if (param_2 != 0x2000745e) {
              return -1;
            }
            _spltty();
            while (((param_1->_lbfsize != 0 ||
                    (uVar19._0_1_ = param_1->_ubuf[0], uVar19._1_1_ = param_1->_ubuf[1],
                    uVar19._2_1_ = param_1->_ubuf[2], uVar19._3_1_ = param_1->_nbuf[0],
                    (uVar19 & 0x2000020) != 0)) &&
                   (((param_1->_ubuf[0] & 0x10) != 0 ||
                    (iVar20 = _ttynty(), *(short *)(iVar20 + 0x10) < 0))))) {
              (*param_1->_read)(param_1,unaff_EBX,unaff_ESI);
              param_1->_ubuf[0] = param_1->_ubuf[0] | 0x40;
              _sleep((uint)&param_1->_lbfsize);
            }
            _splx();
            return 0;
          }
          if (param_2 != 0x2000740d) {
            return -1;
          }
          _spltty();
          param_1->_ubuf[0] = param_1->_ubuf[0] | 0x80;
LAB_0010e53c:
          _splx();
          return 0;
        }
        local_1c = _spltty();
        uVar1._0_1_ = param_1->_ubuf[0];
        uVar1._1_1_ = param_1->_ubuf[1];
        uVar1._2_1_ = param_1->_ubuf[2];
        uVar1._3_1_ = param_1->_nbuf[0];
        uVar1 = uVar1 & 0xffffff7f;
        param_1->_ubuf[0] = (char)uVar1;
        param_1->_ubuf[1] = (char)(uVar1 >> 8);
        param_1->_ubuf[2] = (char)(uVar1 >> 0x10);
        param_1->_nbuf[0] = (char)(uVar1 >> 0x18);
        puVar28 = &stack0xffffffbc;
      }
      else if (param_2 == 0x2000746f) {
        local_1c = _spltty();
        uVar24._0_1_ = param_1->_ubuf[0];
        uVar24._1_1_ = param_1->_ubuf[1];
        uVar24._2_1_ = param_1->_ubuf[2];
        uVar24._3_1_ = param_1->_nbuf[0];
        puVar28 = &stack0xffffffbc;
        if ((uVar24 & 0x100) == 0) {
          uVar24 = uVar24 | 0x100;
          param_1->_ubuf[0] = (char)uVar24;
          param_1->_ubuf[1] = (char)(uVar24 >> 8);
          param_1->_ubuf[2] = (char)(uVar24 >> 0x10);
          param_1->_nbuf[0] = (char)(uVar24 >> 0x18);
          (*(code *)(&PTR__nulldev_001e2f4c)[(uint)*(byte *)((int)&param_1->_extra + 1) * 0xb])();
          puVar28 = &stack0xffffffbc;
        }
      }
      else {
        if (param_2 < 0x20007470) {
          if (param_2 != 0x2000746e) {
            return -1;
          }
          _spltty();
          uVar25._0_1_ = param_1->_ubuf[0];
          uVar25._1_1_ = param_1->_ubuf[1];
          uVar25._2_1_ = param_1->_ubuf[2];
          uVar25._3_1_ = param_1->_nbuf[0];
          if (((uVar25 & 0x100) != 0) || ((param_1->_ur & 0x800000) != 0)) {
            uVar25 = uVar25 & 0xfffffeff;
            param_1->_ubuf[0] = (char)uVar25;
            param_1->_ubuf[1] = (char)(uVar25 >> 8);
            param_1->_ubuf[2] = (char)(uVar25 >> 0x10);
            param_1->_nbuf[0] = (char)(uVar25 >> 0x18);
            param_1->_ur = param_1->_ur & 0xff7fffff;
            _spltty();
            uVar12._0_1_ = param_1->_ubuf[0];
            uVar12._1_1_ = param_1->_ubuf[1];
            uVar12._2_1_ = param_1->_ubuf[2];
            uVar12._3_1_ = param_1->_nbuf[0];
            if (((uVar12 & 0x4000121) == 0) && (param_1->_read != (_func_3 *)0x0)) {
              (*param_1->_read)(param_1,unaff_EBX,unaff_ESI);
            }
            _splx();
          }
          goto LAB_0010e53c;
        }
        if (param_2 != 0x4004667f) {
          if (param_2 != 0x40047400) {
            return -1;
          }
          uVar30 = (uint)*(char *)((int)&(param_1->_lb)._base + 3);
          goto LAB_0010e99c;
        }
        local_1c = _spltty();
        uVar30 = _ttnread();
        *param_3 = uVar30;
        puVar28 = &stack0xffffffb8;
      }
      goto LAB_0010ec1a;
    }
    if (param_2 == 0x40067408) {
      *(undefined1 *)param_3 = *(undefined1 *)((int)&(param_1->_lb)._size + 1);
      *(undefined1 *)((int)param_3 + 1) = *(undefined1 *)((int)&(param_1->_lb)._size + 2);
      *(undefined1 *)((int)param_3 + 2) = *(undefined1 *)((int)&param_1->_blksize + 1);
      *(undefined1 *)((int)param_3 + 3) = *(undefined1 *)((int)&param_1->_blksize + 2);
      *(short *)(param_3 + 1) = (short)param_1->_ur;
      return 0;
    }
    if (0x40067408 < param_2) {
      if (param_2 == 0x40067474) {
        pvVar26 = (void *)((int)&param_1->_offset + 5);
      }
      else {
        if (0x40067474 < param_2) {
          if (param_2 == 0x40087468) {
            *param_3 = param_1[1]._r;
            param_3[1] = param_1[1]._w;
            return 0;
          }
          if (param_2 == 0x40247413) {
            _ttgettermios();
            return 0;
          }
          return -1;
        }
        if (param_2 != 0x40067412) {
          return -1;
        }
        pvVar26 = (void *)((int)&param_1->_blksize + 3);
      }
      _bcopy(pvVar26,param_3,6);
      return 0;
    }
    if (param_2 == 0x40047477) {
      iVar21 = *_active_u;
      if ((*(byte *)(iVar21 + 0x16) & 2) != 0) {
        iVar22 = _get_posix_proc();
        iVar22 = *(int *)(*(int *)(iVar22 + 0x10) + 8);
        if (*(int *)(iVar20 + 8) != iVar22) {
          return 0x19;
        }
        if ((*(byte *)(iVar21 + 0x2b) & 0x40) == 0) {
          return 0x19;
        }
        if (*(int *)(iVar22 + 8) == 0) {
          return 0x19;
        }
      }
      uVar30 = (uint)*(short *)&(param_1->_lb)._base;
    }
    else {
      if (0x40047477 < param_2) {
        if (param_2 != 0x4004747c) {
          return -1;
        }
        uVar29 = (uint)*(ushort *)((int)&param_1->_ur + 2);
        goto LAB_0010e8b0;
      }
      if (param_2 != 0x40047473) {
        return -1;
      }
      uVar30 = param_1->_lbfsize;
    }
LAB_0010e99c:
    *param_3 = uVar30;
    return 0;
  }
  if (param_2 == -0x7ffb8b82) {
    param_1->_ur = param_1->_ur & ~(*param_3 << 0x10);
LAB_0010e851:
    *(undefined4 *)(iVar20 + 0x10) = 0x1c251a1c;
    *(undefined1 *)(iVar20 + 0x14) = 0x5c;
    *(undefined1 *)(iVar20 + 0x15) = 1;
    *(undefined1 *)(iVar20 + 0x16) = 0;
    _ttysetspec();
    return 0;
  }
  if (param_2 < -0x7ffb8b81) {
    if (param_2 == -0x7ffb8bff) {
      uVar30 = *param_3;
      if ((_nldisp <= uVar30) || ((code *)(&_linesw)[uVar30 * 0xc] == _nodev)) {
        return 6;
      }
      if (uVar30 == (int)*(char *)((int)&(param_1->_lb)._base + 3)) {
        return 0;
      }
      local_1c = _spltty();
      (*(code *)(&PTR__ttylclose_001dafec)[*(char *)((int)&(param_1->_lb)._base + 3) * 0xc])();
      param_1[1]._write = (_func_5 *)0x0;
      iVar20 = (*(code *)(&_linesw)[uVar30 * 0xc])();
      if (iVar20 != 0) {
        param_1[1]._write = (_func_5 *)0x0;
        (*(code *)(&_linesw)[*(char *)((int)&(param_1->_lb)._base + 3) * 0xc])();
        _splx();
        return iVar20;
      }
      *(char *)((int)&(param_1->_lb)._base + 3) = (char)uVar30;
      puVar28 = &stack0xffffffbc;
    }
    else {
      if (-0x7ffb8bff < param_2) {
        if (param_2 == -0x7ffb8b8a) {
          iVar21 = *_active_u;
          uVar30 = *param_3;
          if ((*(byte *)(iVar21 + 0x16) & 2) == 0) {
            if ((*(short *)(_active_u[7] + 2) != 0) && ((param_4 & 1) == 0)) {
              return 1;
            }
            local_38._0_2_ = (undefined2)uVar30;
            *(undefined2 *)&(param_1->_lb)._base = (undefined2)local_38;
            return 0;
          }
          iVar22 = _pgfind();
          iVar23 = _get_posix_proc();
          if ((0 < (int)uVar30) && (iVar22 != 0)) {
            iVar23 = *(int *)(*(int *)(iVar23 + 0x10) + 8);
            if ((*(int *)(iVar20 + 8) == iVar23) && ((*(byte *)(iVar21 + 0x2b) & 0x40) != 0)) {
              if (*(int *)(iVar22 + 8) == iVar23) {
                *(int *)(iVar20 + 0xc) = iVar22;
                *(undefined2 *)&(param_1->_lb)._base = *(undefined2 *)(iVar22 + 0xc);
                return 0;
              }
              return 1;
            }
            return 0x19;
          }
          return 0x16;
        }
        if (param_2 < -0x7ffb8b89) {
          if (param_2 != -0x7ffb8bf0) {
            return -1;
          }
          if (*param_3 == 0) {
            local_38 = 3;
          }
          else {
            local_38 = *param_3 & 3;
          }
          _spltty();
          if ((local_38 & 1) != 0) {
            do {
              iVar20 = _getc((FILE *)&param_1->_flags);
            } while (-1 < iVar20);
            _wakeup();
          }
          if ((local_38 & 2) != 0) {
            _wakeup();
            uVar2._0_1_ = param_1->_ubuf[0];
            uVar2._1_1_ = param_1->_ubuf[1];
            uVar2._2_1_ = param_1->_ubuf[2];
            uVar2._3_1_ = param_1->_nbuf[0];
            uVar2 = uVar2 & 0xfffffeff;
            param_1->_ubuf[0] = (char)uVar2;
            param_1->_ubuf[1] = (char)(uVar2 >> 8);
            param_1->_ubuf[2] = (char)(uVar2 >> 0x10);
            param_1->_nbuf[0] = (char)(uVar2 >> 0x18);
            (*(code *)(&PTR__nulldev_001e2f4c)[(uint)*(byte *)((int)&param_1->_extra + 1) * 0xb])();
            do {
              iVar20 = _getc((FILE *)&param_1->_lbfsize);
            } while (-1 < iVar20);
          }
          if ((local_38 & 1) != 0) {
            do {
              iVar20 = _getc(param_1);
            } while (-1 < iVar20);
            *(undefined1 *)((int)&(param_1->_lb)._size + 3) = 0;
            *(undefined1 *)&param_1->_blksize = 0;
            uVar3._0_1_ = param_1->_ubuf[0];
            uVar3._1_1_ = param_1->_ubuf[1];
            uVar3._2_1_ = param_1->_ubuf[2];
            uVar3._3_1_ = param_1->_nbuf[0];
            uVar3 = uVar3 & 0xff40ffff;
            param_1->_ubuf[0] = (char)uVar3;
            param_1->_ubuf[1] = (char)(uVar3 >> 8);
            param_1->_ubuf[2] = (char)(uVar3 >> 0x10);
            param_1->_nbuf[0] = (char)(uVar3 >> 0x18);
          }
          goto LAB_0010e53c;
        }
        if (param_2 != -0x7ffb8b83) {
          return -1;
        }
        uVar30 = (uint)(ushort)param_1->_ur;
        param_1->_ur = uVar30;
        param_1->_ur = *param_3 << 0x10 | uVar30;
        *(undefined4 *)(iVar20 + 0x10) = 0x1c251a1c;
        *(undefined1 *)(iVar20 + 0x14) = 0x5c;
        *(undefined1 *)(iVar20 + 0x15) = 1;
        *(undefined1 *)(iVar20 + 0x16) = 0;
        goto LAB_0010e89e;
      }
      if (param_2 == -0x7ffb9983) {
        local_1c = _spltty();
        if (*param_3 == 0) {
          uVar9._0_1_ = param_1->_ubuf[0];
          uVar9._1_1_ = param_1->_ubuf[1];
          uVar9._2_1_ = param_1->_ubuf[2];
          uVar9._3_1_ = param_1->_nbuf[0];
          uVar9 = uVar9 & 0xffffbfff;
          param_1->_ubuf[0] = (char)uVar9;
          param_1->_ubuf[1] = (char)(uVar9 >> 8);
          param_1->_ubuf[2] = (char)(uVar9 >> 0x10);
          param_1->_nbuf[0] = (char)(uVar9 >> 0x18);
          puVar28 = &stack0xffffffbc;
        }
        else {
          uVar8._0_1_ = param_1->_ubuf[0];
          uVar8._1_1_ = param_1->_ubuf[1];
          uVar8._2_1_ = param_1->_ubuf[2];
          uVar8._3_1_ = param_1->_nbuf[0];
          uVar8 = uVar8 | 0x4000;
          param_1->_ubuf[0] = (char)uVar8;
          param_1->_ubuf[1] = (char)(uVar8 >> 8);
          param_1->_ubuf[2] = (char)(uVar8 >> 0x10);
          param_1->_nbuf[0] = (char)(uVar8 >> 0x18);
          puVar28 = &stack0xffffffbc;
        }
      }
      else if (param_2 < -0x7ffb9982) {
        if (param_2 != -0x7ffe8b8e) {
          return -1;
        }
        if (*(short *)(_active_u[7] + 2) != 0) {
          if ((param_4 & 1) == 0) {
            return 1;
          }
          if ((FILE *)_active_u[0x5a] != param_1) {
            return 0xd;
          }
        }
        local_1c = _spltty();
        (*(code *)(&PTR__ttyinput_001daffc)[*(char *)((int)&(param_1->_lb)._base + 3) * 0xc])();
        puVar28 = &stack0xffffffb4;
      }
      else {
        if (param_2 != -0x7ffb9982) {
          return -1;
        }
        local_1c = _spltty();
        if (*param_3 == 0) {
          uVar7._0_1_ = param_1->_ubuf[0];
          uVar7._1_1_ = param_1->_ubuf[1];
          uVar7._2_1_ = param_1->_ubuf[2];
          uVar7._3_1_ = param_1->_nbuf[0];
          uVar7 = uVar7 & 0xffffdfff;
          param_1->_ubuf[0] = (char)uVar7;
          param_1->_ubuf[1] = (char)(uVar7 >> 8);
          param_1->_ubuf[2] = (char)(uVar7 >> 0x10);
          param_1->_nbuf[0] = (char)(uVar7 >> 0x18);
          puVar28 = &stack0xffffffbc;
        }
        else {
          uVar6._0_1_ = param_1->_ubuf[0];
          uVar6._1_1_ = param_1->_ubuf[1];
          uVar6._2_1_ = param_1->_ubuf[2];
          uVar6._3_1_ = param_1->_nbuf[0];
          uVar6 = uVar6 | 0x2000;
          param_1->_ubuf[0] = (char)uVar6;
          param_1->_ubuf[1] = (char)(uVar6 >> 8);
          param_1->_ubuf[2] = (char)(uVar6 >> 0x10);
          param_1->_nbuf[0] = (char)(uVar6 >> 0x18);
          puVar28 = &stack0xffffffbc;
        }
      }
    }
  }
  else {
    if (param_2 == -0x7ff98bef) {
      puVar27 = &stack0xffffffb0;
      _bcopy(param_3,(void *)((int)&param_1->_blksize + 3),6);
LAB_0010e89e:
      *(int *)(puVar27 + -4) = iVar20;
      *(undefined4 *)(puVar27 + -8) = 0x10e8a4;
      _ttysetspec();
      return 0;
    }
    if (param_2 < -0x7ff98bee) {
      if (param_2 == -0x7ffb8b81) {
        param_1->_ur = param_1->_ur | *param_3 << 0x10;
        goto LAB_0010e851;
      }
      if (-0x7ff98bf6 < param_2) {
        return -1;
      }
      if (param_2 < -0x7ff98bf7) {
        return -1;
      }
      *(undefined1 *)((int)&param_1->_blksize + 1) = *(undefined1 *)((int)param_3 + 2);
      *(undefined1 *)((int)&param_1->_blksize + 2) = *(undefined1 *)((int)param_3 + 3);
      *(char *)((int)&(param_1->_lb)._size + 1) = (char)*param_3;
      *(undefined1 *)((int)&(param_1->_lb)._size + 2) = *(undefined1 *)((int)param_3 + 1);
      uVar11 = (ushort)param_3[1];
      local_38 = (uint)uVar11 | param_1->_ur & 0xffff0000U;
      local_1c = _spltty();
      uVar30 = param_1->_ur;
      if ((((uVar30 & 0x20) == 0) && ((uVar11 & 0x20) == 0)) && (param_2 != -0x7ff98bf7)) {
        if ((uVar30 & 2) != (uVar11 & 2)) {
          if ((uVar11 & 2) == 0) {
            param_1->_ur = uVar30 | 0x20000000;
            local_38 = local_38 | 0x20000000;
            _ttwakeup();
          }
          else {
            _catq();
            puVar14 = param_1->_p;
            puVar15 = (uchar *)param_1->_r;
            iVar21 = param_1->_w;
            param_1->_p = *(uchar **)&param_1->_flags;
            param_1->_r = (int)(param_1->_bf)._base;
            param_1->_w = (param_1->_bf)._size;
            *(uchar **)&param_1->_flags = puVar14;
            (param_1->_bf)._base = puVar15;
            (param_1->_bf)._size = iVar21;
          }
        }
      }
      else {
        _spltty();
        while (((param_1->_lbfsize != 0 ||
                (uVar13._0_1_ = param_1->_ubuf[0], uVar13._1_1_ = param_1->_ubuf[1],
                uVar13._2_1_ = param_1->_ubuf[2], uVar13._3_1_ = param_1->_nbuf[0],
                (uVar13 & 0x2000020) != 0)) &&
               (((param_1->_ubuf[0] & 0x10) != 0 ||
                (iVar21 = _ttynty(), *(short *)(iVar21 + 0x10) < 0))))) {
          (*param_1->_read)(param_1,unaff_EBX,unaff_ESI);
          param_1->_ubuf[0] = param_1->_ubuf[0] | 0x40;
          _sleep((uint)&param_1->_lbfsize);
        }
        _splx();
        _spltty();
        do {
          iVar21 = _getc((FILE *)&param_1->_flags);
        } while (-1 < iVar21);
        _wakeup();
        do {
          iVar21 = _getc(param_1);
        } while (-1 < iVar21);
        *(undefined1 *)((int)&(param_1->_lb)._size + 3) = 0;
        *(undefined1 *)&param_1->_blksize = 0;
        uVar4._0_1_ = param_1->_ubuf[0];
        uVar4._1_1_ = param_1->_ubuf[1];
        uVar4._2_1_ = param_1->_ubuf[2];
        uVar4._3_1_ = param_1->_nbuf[0];
        uVar4 = uVar4 & 0xff40ffff;
        param_1->_ubuf[0] = (char)uVar4;
        param_1->_ubuf[1] = (char)(uVar4 >> 8);
        param_1->_ubuf[2] = (char)(uVar4 >> 0x10);
        param_1->_nbuf[0] = (char)(uVar4 >> 0x18);
        _splx();
      }
      param_1->_ur = local_38;
      *(undefined4 *)(iVar20 + 0x10) = 0x1c251a1c;
      *(undefined1 *)(iVar20 + 0x14) = 0x5c;
      *(undefined1 *)(iVar20 + 0x15) = 1;
      *(undefined1 *)(iVar20 + 0x16) = 0;
      _ttysetspec();
      puVar28 = &stack0xffffffbc;
      if ((param_1->_ur & 0x20) != 0) {
        uVar5._0_1_ = param_1->_ubuf[0];
        uVar5._1_1_ = param_1->_ubuf[1];
        uVar5._2_1_ = param_1->_ubuf[2];
        uVar5._3_1_ = param_1->_nbuf[0];
        uVar5 = uVar5 & 0xfffffeff;
        param_1->_ubuf[0] = (char)uVar5;
        param_1->_ubuf[1] = (char)(uVar5 >> 8);
        param_1->_ubuf[2] = (char)(uVar5 >> 0x10);
        param_1->_nbuf[0] = (char)(uVar5 >> 0x18);
        _spltty();
        uVar16._0_1_ = param_1->_ubuf[0];
        uVar16._1_1_ = param_1->_ubuf[1];
        uVar16._2_1_ = param_1->_ubuf[2];
        uVar16._3_1_ = param_1->_nbuf[0];
        if (((uVar16 & 0x4000121) == 0) && (param_1->_read != (_func_3 *)0x0)) {
          (*param_1->_read)(param_1,unaff_EBX,unaff_ESI);
        }
        _splx();
        puVar28 = &stack0xffffffbc;
      }
    }
    else {
      if (param_2 == -0x7ff78b99) {
        iVar20 = _bcmp(&param_1[1]._r,param_3,8);
        if (iVar20 == 0) {
          return 0;
        }
        param_1[1]._r = *param_3;
        param_1[1]._w = param_3[1];
        _gsignal();
        return 0;
      }
      if (param_2 < -0x7ff78b98) {
        if (param_2 != -0x7ff98b8b) {
          return -1;
        }
        puVar27 = &stack0xffffffb0;
        _bcopy(param_3,(void *)((int)&param_1->_offset + 5),6);
        goto LAB_0010e89e;
      }
      if (-0x7fdb8bea < param_2) {
        return -1;
      }
      if (param_2 < -0x7fdb8bec) {
        return -1;
      }
      local_1c = _spltty();
      if (*(char *)((int)param_3 + 0x21) == '\0') {
        *(undefined1 *)((int)param_3 + 0x21) = *(undefined1 *)((int)param_3 + 0x22);
      }
      if (param_2 + 0x7fdb8bebU < 2) {
        _spltty();
        while (((param_1->_lbfsize != 0 ||
                (uVar17._0_1_ = param_1->_ubuf[0], uVar17._1_1_ = param_1->_ubuf[1],
                uVar17._2_1_ = param_1->_ubuf[2], uVar17._3_1_ = param_1->_nbuf[0],
                (uVar17 & 0x2000020) != 0)) &&
               (((param_1->_ubuf[0] & 0x10) != 0 ||
                (iVar21 = _ttynty(), *(short *)(iVar21 + 0x10) < 0))))) {
          (*param_1->_read)(param_1,unaff_EBX,unaff_ESI);
          param_1->_ubuf[0] = param_1->_ubuf[0] | 0x40;
          _sleep((uint)&param_1->_lbfsize);
        }
        _splx();
        if (param_2 == -0x7fdb8bea) {
          _spltty();
          do {
            iVar21 = _getc((FILE *)&param_1->_flags);
          } while (-1 < iVar21);
          _wakeup();
          do {
            iVar21 = _getc(param_1);
          } while (-1 < iVar21);
          *(undefined1 *)((int)&(param_1->_lb)._size + 3) = 0;
          *(undefined1 *)&param_1->_blksize = 0;
          uVar10._0_1_ = param_1->_ubuf[0];
          uVar10._1_1_ = param_1->_ubuf[1];
          uVar10._2_1_ = param_1->_ubuf[2];
          uVar10._3_1_ = param_1->_nbuf[0];
          uVar10 = uVar10 & 0xff40ffff;
          param_1->_ubuf[0] = (char)uVar10;
          param_1->_ubuf[1] = (char)(uVar10 >> 8);
          param_1->_ubuf[2] = (char)(uVar10 >> 0x10);
          param_1->_nbuf[0] = (char)(uVar10 >> 0x18);
          _splx();
        }
      }
      if (((((param_3[2] & 1) == 0) &&
           (uVar18._0_1_ = param_1->_ubuf[0], uVar18._1_1_ = param_1->_ubuf[1],
           uVar18._2_1_ = param_1->_ubuf[2], uVar18._3_1_ = param_1->_nbuf[0], (uVar18 & 0x10) == 0)
           ) && (*(short *)(iVar20 + 0x10) < 0)) && (-1 < (short)param_3[2])) {
        uVar30 = uVar18 & 0xfffffffb | 2;
        param_1->_ubuf[0] = (char)uVar30;
        param_1->_ubuf[1] = (char)(uVar30 >> 8);
        param_1->_ubuf[2] = (char)(uVar30 >> 0x10);
        param_1->_nbuf[0] = (char)(uVar30 >> 0x18);
        _ttwakeup();
      }
      uVar30 = param_3[3] >> 5 & 1;
      if ((param_2 != -0x7fdb8bea) && (uVar30 != ((param_1->_ur & 0x22U) == 0))) {
        if (uVar30 == 0) {
          _catq();
          puVar14 = param_1->_p;
          puVar15 = (uchar *)param_1->_r;
          iVar21 = param_1->_w;
          param_1->_p = *(uchar **)&param_1->_flags;
          param_1->_r = (int)(param_1->_bf)._base;
          param_1->_w = (param_1->_bf)._size;
          *(uchar **)&param_1->_flags = puVar14;
          (param_1->_bf)._base = puVar15;
          (param_1->_bf)._size = iVar21;
        }
        else {
          param_1->_ur = param_1->_ur | 0x20000000;
          _ttwakeup();
        }
      }
      if ((uVar30 == 0) && ((*(uint *)(iVar20 + 0x14) & 0xffff00) != (param_3[6] & 0xffff00))) {
        _ttwakeup();
      }
      _ttsettermios();
      _ttysetspec();
      puVar28 = &stack0xffffffb0;
    }
  }
LAB_0010ec1a:
  *(undefined4 *)(puVar28 + -4) = local_1c;
  *(undefined4 *)(puVar28 + -8) = 0x10ec23;
  _splx();
  return 0;
}

