
/* WARNING: Removing unreachable block (ram,0xf001985c) */
/* WARNING: Removing unreachable block (ram,0xf001980c) */
/* WARNING: Removing unreachable block (ram,0xf00199f4) */
/* WARNING: Removing unreachable block (ram,0xf00199d0) */
/* WARNING: Removing unreachable block (ram,0xf0019984) */
/* WARNING: Removing unreachable block (ram,0xf00198e0) */
/* WARNING: Removing unreachable block (ram,0xf001987c) */
/* WARNING: Removing unreachable block (ram,0xf00197a8) */
/* WARNING: Removing unreachable block (ram,0xf0019780) */
/* WARNING: Removing unreachable block (ram,0xf001968c) */
/* WARNING: Removing unreachable block (ram,0xf0019704) */
/* WARNING: Removing unreachable block (ram,0xf00195f4) */
/* WARNING: Removing unreachable block (ram,0xf00195d8) */
/* WARNING: Removing unreachable block (ram,0xf00194b8) */
/* WARNING: Removing unreachable block (ram,0xf001944c) */
/* WARNING: Removing unreachable block (ram,0xf0019430) */
/* WARNING: Removing unreachable block (ram,0xf0019454) */
/* WARNING: Removing unreachable block (ram,0xf0019500) */
/* WARNING: Removing unreachable block (ram,0xf00195e8) */
/* WARNING: Removing unreachable block (ram,0xf0019714) */
/* WARNING: Removing unreachable block (ram,0xf001969c) */
/* WARNING: Removing unreachable block (ram,0xf0019768) */
/* WARNING: Removing unreachable block (ram,0xf0019798) */
/* WARNING: Removing unreachable block (ram,0xf0019870) */
/* WARNING: Removing unreachable block (ram,0xf00198cc) */
/* WARNING: Removing unreachable block (ram,0xf0019914) */
/* WARNING: Removing unreachable block (ram,0xf0019998) */
/* WARNING: Removing unreachable block (ram,0xf00199e4) */
/* WARNING: Removing unreachable block (ram,0xf00199fc) */
/* WARNING: Removing unreachable block (ram,0xf001982c) */
/* WARNING: Removing unreachable block (ram,0xf0019864) */
/* WARNING: Removing unreachable block (ram,0xf001941c) */

undefined8 _ttread(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  undefined4 unaff_l0;
  int iVar9;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar10;
  undefined4 unaff_l4;
  int *piVar11;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  int *piVar12;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  piVar3 = param_1;
  _ttynty();
  piVar12 = (int *)0x0;
  bVar1 = false;
  puVar5 = (undefined *)piVar3;
loc_F0019430:
  do {
    uVar10 = param_1[0xf];
    _spltty();
    if ((uVar10 & 0x20000000) != 0) {
      _ttypend(param_1);
    }
    _splx(puVar5);
    uVar7 = param_1[0x10];
    if ((uVar7 & 0x10) == 0) {
      uVar4 = piVar3[4];
      while ((uVar4 & 0x8000) == 0) {
        if ((uVar7 & 0x8000) == 0) goto loc_F00195D0;
        if ((uVar7 & 0x2000) != 0) {
          uVar10 = *(uint *)(*_active_u + 0x14);
          goto loc_F0019850;
        }
        _sleep(param_1,0x1c);
        uVar7 = param_1[0x10];
        if ((uVar7 & 0x10) != 0) break;
        uVar4 = piVar3[4];
      }
    }
    iVar9 = *_active_u;
    if ((*(uint *)(iVar9 + 0x14) & 0x4000) != 0) {
      puVar5 = (undefined *)(int)*(sword *)(iVar9 + 0x30);
      _get_posix_proc();
      if (param_1 == (int *)_active_u[0x59]) {
        piVar11 = (int *)((int)puVar5 + 0x10);
        puVar5 = (undefined *)(int)*(sword *)(param_1 + 0x11);
        piVar8 = *(int **)(*piVar11 + 0xc);
        if (piVar8 != (int *)puVar5) {
          if ((*(uint *)(iVar9 + 0x20) & 0x100000) != 0) {
            piVar12 = (int *)0x5;
            goto locret_F0019A08;
          }
          if ((*(uint *)(iVar9 + 0x1c) & 0x100000) != 0) {
            piVar12 = (int *)0x5;
            goto locret_F0019A08;
          }
          if (*(int *)(*piVar11 + 0x10) != 0) {
            if ((*(uint *)(iVar9 + 0x28) & 0x1000) == 0) goto loc_F00195D8;
            piVar12 = (int *)0x5;
            goto locret_F0019A08;
          }
loc_F00195D0:
          piVar12 = (int *)0x5;
locret_F0019A08:
          return CONCAT44(param_2,piVar12);
        }
      }
loc_F00195F4:
      _spltty();
      if ((uVar10 & 0x22) == 0) {
        piVar11 = param_1 + 3;
        if (0 < param_1[3]) goto loc_F0019870;
loc_F00197C8:
        uVar10 = param_1[0x10];
      }
      else {
        uVar7 = (uint)*(byte *)((int)piVar3 + 0x15);
        piVar11 = param_1;
        if (*(byte *)((int)piVar3 + 0x16) == 0) {
          if ((int)uVar7 <= *param_1) goto loc_F0019870;
          uVar10 = param_1[0x10];
        }
        else {
          iVar9 = (uint)*(byte *)((int)piVar3 + 0x16) * 100000;
          if (uVar7 == 0) {
            if (0 < *param_1) goto loc_F0019870;
            if (bVar1) {
              _getthetime((undefined *)((int)register0x00000038 + -0x18));
              iVar9 = iVar9 - ((*(int *)((int)register0x00000038 + -0x18) -
                               *(int *)((int)register0x00000038 + -0x10)) * 1000000 +
                              (*(int *)((int)register0x00000038 + -0x14) -
                              *(int *)((int)register0x00000038 + -0xc)));
            }
            else {
              bVar1 = true;
              _getthetime((undefined *)((int)register0x00000038 + -0x10));
            }
          }
          else {
            iVar6 = *param_1;
            if (iVar6 < 1) goto loc_F00197C8;
            if ((int)uVar7 <= iVar6) goto loc_F0019870;
            if (bVar1) {
              if (param_3 < iVar6) goto loc_F001968C;
              _getthetime((undefined *)((int)register0x00000038 + -0x18));
              iVar9 = iVar9 - ((*(int *)((int)register0x00000038 + -0x18) -
                               *(int *)((int)register0x00000038 + -0x10)) * 1000000 +
                              (*(int *)((int)register0x00000038 + -0x14) -
                              *(int *)((int)register0x00000038 + -0xc)));
            }
            else {
              bVar1 = true;
loc_F001968C:
              _getthetime((undefined *)((int)register0x00000038 + -0x10));
            }
            param_3 = *param_1;
          }
          if (iVar9 < 1) {
loc_F0019870:
            _splx(puVar5);
            bVar1 = true;
loc_F001987C:
            piVar8 = piVar11;
            _getc();
            uVar7 = (uint)piVar8 & 0xff;
            if ((int)piVar8 < 0) goto loc_F0019974;
            if (uVar7 != 0xff) {
              if (((uVar7 == *(byte *)((int)param_1 + 0x56)) && ((uVar10 & 0x20) == 0)) &&
                 ((piVar3[4] & 8U) != 0)) break;
              if (((uVar7 != 0xff) && (uVar7 == *(byte *)((int)param_1 + 0x53))) &&
                 ((uVar10 & 0x22) == 0)) {
                iVar9 = *param_1;
                goto loc_F0019978;
              }
            }
            piVar12 = piVar8;
            _ureadc(piVar8,param_2);
            if (piVar12 != (int *)0x0) {
              iVar9 = *param_1;
              goto loc_F0019978;
            }
            if (*(int *)(param_2 + 0x14) == 0) goto loc_F0019974;
            bVar1 = false;
            if ((uVar10 & 0x22) == 0) {
              if (piVar8 == (int *)0xa) {
                iVar9 = *param_1;
                goto loc_F0019978;
              }
              if (((piVar8 == (int *)(uint)*(byte *)((int)param_1 + 0x53)) ||
                  (piVar8 == (int *)(uint)*(byte *)(param_1 + 0x15))) &&
                 (bVar1 = false, piVar8 != (int *)0xff)) goto loc_F0019974;
            }
            goto loc_F001987C;
          }
          .umul(iVar9,_hz);
          iVar9 = iVar9 + 999999;
          .div(iVar9,1000000);
          _untimeout(_wakeup,param_1);
          _timeout(_wakeup,param_1,iVar9);
          uVar10 = param_1[0x10];
        }
      }
      if (((uVar10 & 0x10) != 0) || (bVar2 = false, (piVar3[4] & 0x8000U) != 0)) {
        bVar2 = true;
      }
      if (bVar2) {
        uVar10 = param_1[0x10];
      }
      else {
        if ((param_1[0x10] & 4U) != 0) {
          _splx(puVar5);
          piVar12 = (int *)0x0;
          goto locret_F0019A08;
        }
        uVar10 = param_1[0x10];
      }
      if ((uVar10 & 0x2000) != 0) {
        _splx(puVar5);
        uVar10 = *(uint *)(*_active_u + 0x14);
loc_F0019850:
        piVar12 = (int *)0x23;
        if ((uVar10 & 0x4000) != 0) {
          piVar12 = (int *)0xb;
        }
        goto locret_F0019A08;
      }
      _sleep(param_1,0x1c);
      _splx(puVar5);
      goto loc_F0019430;
    }
    puVar5 = (undefined *)_active_u[0x59];
    if (param_1 != (int *)puVar5) goto loc_F00195F4;
    piVar8 = (int *)(int)*(sword *)(iVar9 + 0x2e);
    puVar5 = (undefined *)(int)*(sword *)(param_1 + 0x11);
    if (piVar8 == (int *)puVar5) goto loc_F00195F4;
    if ((*(uint *)(iVar9 + 0x20) & 0x100000) != 0) {
      piVar12 = (int *)0x5;
      goto locret_F0019A08;
    }
    if ((*(uint *)(iVar9 + 0x1c) & 0x100000) != 0) {
      piVar12 = (int *)0x5;
      goto locret_F0019A08;
    }
    if ((*(uint *)(iVar9 + 0x28) & 0x1000) != 0) goto loc_F00195D0;
loc_F00195D8:
    _gsignal(piVar8,0x15);
    puVar5 = _lbolt;
    _sleep(_lbolt,0x1c);
  } while( true );
  _gsignal((int)*(sword *)(param_1 + 0x11),0x12);
  if (!bVar1) {
loc_F0019974:
    iVar9 = *param_1;
loc_F0019978:
    if (iVar9 < 0xcc) {
      _spltty();
      param_1[0x10] = param_1[0x10] & 0xff7fffff;
      _splx();
      if (((param_1[0x10] & 0x1000400U) == 0x400) && (*(char *)((int)param_1 + 0x51) != -1)) {
        iVar9 = (int)*(char *)((int)param_1 + 0x51);
        _putc(iVar9,param_1 + 6);
        if (iVar9 == 0) {
          _spltty();
          param_1[0x10] = param_1[0x10] & 0xfffffbff;
          _splx();
          _ttstart(param_1);
        }
      }
    }
    goto locret_F0019A08;
  }
  puVar5 = (undefined *)param_1;
  _sleep(param_1,0x1c);
  bVar1 = false;
  goto loc_F0019430;
}
