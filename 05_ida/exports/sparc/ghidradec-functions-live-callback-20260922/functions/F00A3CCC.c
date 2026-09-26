
/* WARNING: Removing unreachable block (ram,0xf00a3dc8) */
/* WARNING: Removing unreachable block (ram,0xf00a3d84) */
/* WARNING: Removing unreachable block (ram,0xf00a3d54) */
/* WARNING: Removing unreachable block (ram,0xf00a3d20) */
/* WARNING: Removing unreachable block (ram,0xf00a3cfc) */
/* WARNING: Removing unreachable block (ram,0xf00a3d10) */
/* WARNING: Removing unreachable block (ram,0xf00a3d48) */
/* WARNING: Removing unreachable block (ram,0xf00a3d70) */
/* WARNING: Removing unreachable block (ram,0xf00a3d94) */
/* WARNING: Removing unreachable block (ram,0xf00a3e08) */
/* WARNING: Removing unreachable block (ram,0xf00a3ce0) */

undefined8 _setcpudelay(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
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
  _Cpudelay = 1;
  _us_spin();
  do {
    iVar2 = _Cpudelay << 1;
    _Cpudelay = iVar2;
    do {
      _spl8();
      uVar5 = *(uint *)(_utimersp + 4);
      _us_spin(0x32);
      uVar4 = *(uint *)(_utimersp + 4);
      _splx(iVar2);
      uVar6 = uVar4 - uVar5;
    } while (uVar4 < uVar5);
  } while (uVar6 < 0xc800);
  iVar2 = _Cpudelay;
  umul(_Cpudelay,0xc800);
  iVar2 = iVar2 + uVar6;
  udiv(iVar2,uVar6);
  _Cpudelay = iVar2;
  if (iVar2 < 0) {
    _Cpudelay = 0;
  }
  do {
    _spl8();
    uVar5 = *(uint *)(_utimersp + 4);
    _us_spin(0x32);
    uVar4 = *(uint *)(_utimersp + 4);
    _splx(iVar2);
  } while (uVar4 < uVar5);
  _cpudelay = 0xb;
  do {
    iVar2 = _cpudelay + -1;
    _cpudelay = iVar2;
    do {
      _spl8();
      uVar4 = 800 >> ((byte)_cpudelay & 0x1f);
      uVar5 = *(uint *)(_utimersp + 4);
      if (0 < (int)(uVar4 - 1)) {
        iVar3 = uVar4 - 2;
        do {
          bVar1 = 0 < iVar3;
          iVar3 = iVar3 + -1;
        } while (bVar1);
      }
      uVar4 = *(uint *)(_utimersp + 4);
      _splx(iVar2);
    } while (uVar4 < uVar5);
  } while ((uVar4 - uVar5 < 0xc800) && (0 < _cpudelay));
  return CONCAT44(param_2,param_1);
}

