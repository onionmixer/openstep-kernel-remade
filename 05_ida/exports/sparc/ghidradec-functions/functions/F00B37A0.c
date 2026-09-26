
/* WARNING: Removing unreachable block (ram,0xf00b38ec) */
/* WARNING: Removing unreachable block (ram,0xf00b38d0) */
/* WARNING: Removing unreachable block (ram,0xf00b3da0) */
/* WARNING: Removing unreachable block (ram,0xf00b3d70) */
/* WARNING: Removing unreachable block (ram,0xf00b3cb8) */
/* WARNING: Removing unreachable block (ram,0xf00b3c20) */
/* WARNING: Removing unreachable block (ram,0xf00b3b64) */
/* WARNING: Removing unreachable block (ram,0xf00b3a68) */
/* WARNING: Removing unreachable block (ram,0xf00b3a44) */
/* WARNING: Removing unreachable block (ram,0xf00b3a14) */
/* WARNING: Removing unreachable block (ram,0xf00b39e0) */
/* WARNING: Removing unreachable block (ram,0xf00b3968) */
/* WARNING: Removing unreachable block (ram,0xf00b3880) */
/* WARNING: Removing unreachable block (ram,0xf00b385c) */
/* WARNING: Removing unreachable block (ram,0xf00b380c) */
/* WARNING: Removing unreachable block (ram,0xf00b3870) */
/* WARNING: Removing unreachable block (ram,0xf00b3924) */
/* WARNING: Removing unreachable block (ram,0xf00b39b0) */
/* WARNING: Removing unreachable block (ram,0xf00b3a04) */
/* WARNING: Removing unreachable block (ram,0xf00b3a3c) */
/* WARNING: Removing unreachable block (ram,0xf00b3a58) */
/* WARNING: Removing unreachable block (ram,0xf00b3b44) */
/* WARNING: Removing unreachable block (ram,0xf00b3b8c) */
/* WARNING: Removing unreachable block (ram,0xf00b3cac) */
/* WARNING: Removing unreachable block (ram,0xf00b3cc0) */
/* WARNING: Removing unreachable block (ram,0xf00b3d94) */
/* WARNING: Removing unreachable block (ram,0xf00b3da8) */
/* WARNING: Removing unreachable block (ram,0xf00b38e4) */
/* WARNING: Removing unreachable block (ram,0xf00b3828) */
/* WARNING: Removing unreachable block (ram,0xf00b37e8) */

undefined8
_esp_attach(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  char cVar5;
  int iVar4;
  byte bVar6;
  undefined uVar7;
  uint uVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar12;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar13;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar14;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar12 = 0;
  bVar14 = 0 < _nesp;
  param_1[0xb] = 0;
  if (bVar14) {
    if (2 < param_1[4]) {
      uVar13 = 0xffffffff;
      goto locret_F00B3DB4;
    }
    if (param_1[6] == 0) {
      uVar13 = 0xffffffff;
      goto locret_F00B3DB4;
    }
    puVar10 = (undefined4 *)param_1[5];
    iVar1 = puVar10[1];
    _map_regs(iVar1,puVar10[2],*puVar10);
    if (iVar1 == 0) {
      puVar11 = aEspDUnableToMa;
    }
    else {
      puVar2 = *(uint **)param_1[5];
      _dma_alloc(puVar2,((int *)param_1[5])[1]);
      if (puVar2 != (uint *)0x0) {
        if (*puVar2 >> 0x1c == 4) {
          *puVar2 = *puVar2 & 0xffffff7f;
          uVar8 = *puVar2;
        }
        else {
          uVar8 = *puVar2;
        }
        piVar3 = (int *)0x1b8;
        *puVar2 = uVar8 & 0xfffffeff;
        _kalloc();
        iVar4 = iRam00000048;
        if (piVar3 != (int *)0x0) {
          _bzero();
          iVar4 = _iopbmap;
          _rmalloc(_iopbmap,0x10);
          piVar3[0x12] = iVar4;
          iVar4 = piVar3[0x12];
          if (piVar3 != (int *)0x0) {
            if (piVar3[0x12] != 0) {
              *(undefined *)(piVar3 + 0xc) = 0;
              piVar9 = _esp_softc;
              bVar14 = _esp_softc == (int *)0x0;
              piVar3[10] = 0;
              if (bVar14) {
                _esp_softc = piVar3;
                _timeout(_esp_watch,0,_hz);
              }
              else {
                for (; piVar9[10] != 0; piVar9 = (int *)piVar9[10]) {
                }
                piVar9[10] = (int)piVar3;
              }
              if (param_1 != (int *)0x0) {
                iVar12 = param_1[10];
                piVar9 = param_1;
                while (((_getprop(iVar12,DAT_f011e308._0_4_,0xffffffff), iVar12 < 1 &&
                        (piVar9 != _top_devinfo)) && (piVar9 = (int *)*piVar9, piVar9 != (int *)0x0)
                       )) {
                  iVar12 = piVar9[10];
                }
              }
              if (iVar12 < 0x4c4b41) {
                param_2 = 0;
              }
              else {
                param_2 = iVar12 + 4999999;
                .div();
              }
              if (6 < (param_2 - 2 & 0xff)) {
                _esplog(piVar3,3,aBadClockFreque);
                *(undefined *)((int)piVar3 + 0x7a) = 0xff;
                param_2 = 4;
                iVar12 = 20000000;
              }
              *(char *)((int)piVar3 + 0x3d) = (char)param_2;
              .div(iVar12,1000);
              uVar8 = 1000000000;
              .div(1000000000,iVar12);
              *(sword *)((int)piVar3 + 0x3e) = (sword)uVar8;
              cVar5 = *(char *)((int)piVar3 + 0x3d);
              .umul(cVar5,(uVar8 & 0xffff) * 0x1e02);
              .div();
              cVar5 = cVar5 + '\x7f';
              .udiv();
              *(char *)(piVar3 + 0x10) = cVar5;
              iVar4 = *(int *)param_1[7];
              _ipltospl();
              piVar3[0x2d] = iVar4;
              piVar9 = _esp_softc;
              iVar12 = 0;
              if (0 < iVar4) {
                iVar12 = iVar4;
              }
              if (_esp_softc != (int *)0x0) {
                *_esp_softc = iVar12;
                while (piVar9 = (int *)piVar9[10], piVar9 != (int *)0x0) {
                  *piVar9 = iVar12;
                }
              }
              piVar3[1] = (int)_esp_start;
              piVar3[3] = (int)_esp_abort;
              piVar3[2] = (int)_esp_reset;
              piVar3[4] = (int)_esp_getcap;
              piVar3[5] = (int)_esp_setcap;
              piVar3[6] = (int)_scsi_std_pktalloc;
              piVar3[7] = (int)_scsi_std_dmaget;
              piVar3[8] = (int)_scsi_std_pktfree;
              piVar3[9] = (int)_scsi_std_dmafree;
              piVar3[0xb] = (int)param_1;
              *(undefined *)((int)piVar3 + 0x32) = 7;
              if (param_1 != (int *)0x0) {
                uVar8 = param_1[10];
                piVar9 = param_1;
                while( true ) {
                  _getprop(uVar8,DAT_f011e2d8._0_4_,0xffffffff);
                  if (uVar8 == 0xffffffff) {
                    uVar8 = piVar9[10];
                    _getprop(uVar8,DAT_f011e2d8._28_4_,0xffffffff);
                  }
                  if ((uVar8 != 7) && (uVar8 < 8)) {
                    _esplog(piVar3,6,aInitiatorScsiI,uVar8);
                    *(char *)((int)piVar3 + 0x32) = (char)uVar8;
                  }
                  if (((uVar8 < 0x80000000) || (piVar9 == _top_devinfo)) ||
                     (piVar9 = (int *)*piVar9, piVar9 == (int *)0x0)) break;
                  uVar8 = piVar9[10];
                }
              }
              if ((_scsi_options & 0x40) == 0) {
                piVar3[0x27] = iVar1;
              }
              else {
                *(byte *)((int)piVar3 + 0x32) = *(byte *)((int)piVar3 + 0x32) | 0x10;
                piVar3[0x27] = iVar1;
              }
              piVar3[0x28] = (int)puVar2;
              piVar9 = (int *)piVar3[0xb];
              *(byte *)((int)piVar3 + 0x32) =
                   *(byte *)((int)piVar3 + 0x32) | (byte)_espconf & 0xf8 | 0x40;
              *(undefined *)(piVar3 + 0x1f) = 0xff;
              iVar12 = piVar9[10];
              while( true ) {
                _getprop(iVar12,DAT_f011e308._20_4_,0xffffffff);
                if (iVar12 == -1) {
                  piVar9 = (int *)*piVar9;
                }
                else {
                  *(byte *)(piVar3 + 0x1f) = *(byte *)(piVar3 + 0x1f) & (byte)iVar12;
                  piVar9 = (int *)*piVar9;
                }
                if (piVar9 == _top_devinfo) break;
                iVar12 = piVar9[10];
              }
              if ((*(byte *)(piVar3 + 0x1f) == 0xff) || ((*(byte *)(piVar3 + 0x1f) & 0x30) == 0)) {
                *(undefined *)(piVar3 + 0x1f) = 0x1f;
              }
              piVar3[0x2b] = -0x100000;
              *(undefined2 *)((int)piVar3 + 0xb2) = 0xffff;
              *(undefined2 *)(piVar3 + 0x2c) = 0xffff;
              _addintr(*(undefined4 *)param_1[7],_esp_poll,param_1[3],param_1[0xb],param_4,param_5);
              _adddma(*(undefined4 *)param_1[7]);
              _report_dev(param_1);
              *(undefined *)(iVar1 + 0x2c) = 10;
              *(undefined *)((int)piVar3 + 0x76) = 0x2d;
              if ((*(byte *)(iVar1 + 0x2c) & 0xf) == 10) {
                *(char *)((int)piVar3 + 0x33) = (char)_espconf2;
                *(undefined *)(iVar1 + 0x30) = 5;
                iVar12 = 0;
                do {
                  iVar4 = iVar12 + 1;
                  *(char *)((int)piVar3 + iVar12 + 0x34) = (char)_espconf3;
                  iVar12 = iVar4;
                } while (iVar4 < 8);
                if ((param_2 & 0xff) < 6) {
                  *(byte *)(iVar1 + 0x2c) = *(byte *)((int)piVar3 + 0x33);
                  uVar7 = 2;
                }
                else {
                  bVar6 = *(byte *)((int)piVar3 + 0x33) | 0x40;
                  *(byte *)((int)piVar3 + 0x33) = bVar6;
                  *(byte *)(iVar1 + 0x2c) = bVar6;
                  *(undefined *)((int)piVar3 + 0x76) = 0x19;
                  uVar7 = 5;
                }
                *(undefined *)((int)piVar3 + 0x31) = uVar7;
                *(char *)(iVar1 + 0x30) = (char)_espconf3;
              }
              else {
                *(undefined *)((int)piVar3 + 0x31) = 0;
              }
              iVar12 = param_1[10];
              _getprop(iVar12,off_F011E330,0xffffffff);
              if (iVar12 != -1) {
                *(char *)(piVar3 + 0xf) = *(char *)(piVar3 + 0xf) + '\x01';
              }
              _esp_internal_reset(piVar3,0x1f);
              _scsi_config(piVar3,param_1);
              _scsa_config(piVar3);
              uVar13 = 0;
              goto locret_F00B3DB4;
            }
            iVar4 = piVar3[0x12];
          }
        }
        if (iVar4 == 0) {
          puVar11 = aDataStructures;
        }
        else {
          puVar11 = aCmdAreas;
        }
        _printf(aEspDNoSpaceFor,0,puVar11);
        if (piVar3 != (int *)0x0) {
          _kfree(piVar3,0x1b8);
        }
        _dma_free(puVar2);
        uVar13 = 0xffffffff;
        goto locret_F00B3DB4;
      }
      puVar11 = aEspDCannotFind;
    }
    _printf(puVar11,0);
  }
  uVar13 = 0xffffffff;
locret_F00B3DB4:
  return CONCAT44(param_2,uVar13);
}
