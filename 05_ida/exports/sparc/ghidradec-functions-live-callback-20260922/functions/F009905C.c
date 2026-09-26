
/* WARNING: Removing unreachable block (ram,0xf0099104) */
/* WARNING: Removing unreachable block (ram,0xf00990b8) */
/* WARNING: Removing unreachable block (ram,0xf009909c) */
/* WARNING: Removing unreachable block (ram,0xf00990dc) */
/* WARNING: Removing unreachable block (ram,0xf0099124) */
/* WARNING: Removing unreachable block (ram,0xf0099074) */

undefined8
_addintr(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6)

{
  int iVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
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
  if (param_2 != 0) {
    if ((int *)0x4f < param_1) {
      _panic(aAddintrVectorN);
    }
    param_1 = *(int **)(_vectorlist + (int)param_1 * 4);
    if (param_1 == (int *)0x0) {
      _panic(aAddintrSpecifi);
      iVar1 = iRam0000000c;
    }
    else {
      iVar1 = param_1[3];
    }
    if (iVar1 == -1) {
      _panic(aAddintrInterru);
    }
    iVar1 = 0;
    piVar2 = param_1 + 5;
    do {
      if (*param_1 == 0) {
        _bzero(param_1,0x18);
        *param_1 = param_2;
        piVar2[-1] = param_5;
        *piVar2 = param_6;
loc_F00990FC:
        sub_F009921C(param_1,param_3,param_4);
        goto locret_F009912C;
      }
      piVar2 = piVar2 + 6;
      if (*param_1 == param_2) goto loc_F00990FC;
      iVar1 = iVar1 + 1;
      param_1 = param_1 + 6;
    } while (iVar1 < 10);
    _panic(aAddintrTooMany);
  }
locret_F009912C:
  return CONCAT44(param_2,param_1);
}

