
/* WARNING: Removing unreachable block (ram,0xf001a158) */
/* WARNING: Removing unreachable block (ram,0xf001a248) */
/* WARNING: Removing unreachable block (ram,0xf001a1d0) */
/* WARNING: Removing unreachable block (ram,0xf001a17c) */
/* WARNING: Removing unreachable block (ram,0xf001a2bc) */
/* WARNING: Removing unreachable block (ram,0xf001a268) */
/* WARNING: Removing unreachable block (ram,0xf001a188) */
/* WARNING: Removing unreachable block (ram,0xf001a214) */
/* WARNING: Removing unreachable block (ram,0xf001a1e4) */
/* WARNING: Removing unreachable block (ram,0xf001a130) */
/* WARNING: Removing unreachable block (ram,0xf001a29c) */

undefined8 _ttyrub(uint param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar6;
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
  piVar5 = (int *)*param_2;
  uVar4 = piVar5[0xf];
  if (((uVar4 & 8) == 0) || ((piVar5[0x10] & 0x400000U) != 0)) goto locret_F001A2D0;
  piVar5[0xf] = uVar4 & 0xff7fffff;
  if ((uVar4 & 0x10000) == 0) {
    if ((uVar4 & 0x20000) == 0) {
      uVar4 = (uint)*(byte *)((int)piVar5 + 0x4d);
    }
    else {
      uVar4 = param_1;
      if ((piVar5[0x10] & 0x40000U) == 0) {
        _ttyoutput(0x5c,piVar5);
        piVar5[0x10] = piVar5[0x10] | 0x40000;
      }
    }
    _ttyecho(uVar4,param_2);
    cVar3 = *(char *)((int)piVar5 + 0x4b);
    goto loc_F001A2C8;
  }
  uVar4 = param_1 - 0x109;
  if (*(char *)((int)piVar5 + 0x4b) == '\0') {
loc_F001A17C:
    _ttyretype(param_2);
    goto locret_F001A2D0;
  }
  param_1 = param_1 & 0xff;
  if (uVar4 < 2) {
loc_F001A154:
    _ttyrubo(piVar5,2);
    cVar3 = *(char *)((int)piVar5 + 0x4b);
  }
  else {
    switch(_partab[param_1] & 0x3f) {
    case :
      _ttyrubo(piVar5,1);
      cVar3 = *(char *)((int)piVar5 + 0x4b);
      break;
    case :
    case :
    case :
    case :
    case :
      if ((piVar5[0xf] & 0x10000000U) != 0) goto loc_F001A154;
      cVar3 = *(char *)((int)piVar5 + 0x4b);
      break;
    case :
      iVar1 = *piVar5;
      if (*(char *)((int)piVar5 + 0x4b) < iVar1) goto loc_F001A17C;
      _spltty();
      cVar3 = *(char *)(piVar5 + 0x12);
      piVar5[0x10] = piVar5[0x10] | 0x200000;
      piVar5[0xf] = piVar5[0xf] | 0x800000;
      *(undefined *)(piVar5 + 0x12) = *(undefined *)(piVar5 + 0x13);
      piVar6 = (int *)(piVar5[1] + -1);
      while( true ) {
        piVar2 = piVar5;
        _nextc3(piVar5,piVar6,(undefined *)((int)register0x00000038 + -0xc));
        if (piVar2 == (int *)0x0) break;
        _ttyecho(*(undefined4 *)((int)register0x00000038 + -0xc),param_2);
        piVar6 = piVar2;
      }
      piVar5[0xf] = piVar5[0xf] & 0xff7fffff;
      piVar5[0x10] = piVar5[0x10] & 0xffdfffff;
      _splx(iVar1);
      iVar1 = (int)cVar3 - (int)*(char *)(piVar5 + 0x12);
      *(char *)(piVar5 + 0x12) = *(char *)(piVar5 + 0x12) + (char)iVar1;
      if (8 < iVar1) {
        iVar1 = 8;
      }
      iVar1 = iVar1 + -1;
      param_1 = 0;
      if (iVar1 < 0) {
        cVar3 = *(char *)((int)piVar5 + 0x4b);
      }
      else {
        do {
          _ttyoutput(8,piVar5);
          iVar1 = iVar1 + -1;
        } while (-1 < iVar1);
        cVar3 = *(char *)((int)piVar5 + 0x4b);
      }
      break;
    :
      _panic(&aTtyrub);
      cVar3 = *(char *)((int)piVar5 + 0x4b);
    }
  }
loc_F001A2C8:
  *(char *)((int)piVar5 + 0x4b) = cVar3 + -1;
locret_F001A2D0:
  return CONCAT44(param_2,param_1);
}
