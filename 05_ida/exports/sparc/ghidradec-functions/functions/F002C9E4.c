
/* WARNING: Removing unreachable block (ram,0xf002cac8) */
/* WARNING: Removing unreachable block (ram,0xf002cb34) */
/* WARNING: Removing unreachable block (ram,0xf002cb08) */
/* WARNING: Removing unreachable block (ram,0xf002cb54) */
/* WARNING: Removing unreachable block (ram,0xf002cb8c) */
/* WARNING: Removing unreachable block (ram,0xf002cbe0) */
/* WARNING: Removing unreachable block (ram,0xf002cc34) */
/* WARNING: Removing unreachable block (ram,0xf002cbe8) */
/* WARNING: Removing unreachable block (ram,0xf002cb60) */
/* WARNING: Removing unreachable block (ram,0xf002cbf0) */
/* WARNING: Removing unreachable block (ram,0xf002cb10) */
/* WARNING: Removing unreachable block (ram,0xf002cae4) */
/* WARNING: Removing unreachable block (ram,0xf002cc48) */
/* WARNING: Removing unreachable block (ram,0xf002cc1c) */

undefined8 _raw_usrreq(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar3;
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
  iVar2 = 0;
  iVar1 = *(int *)(param_1 + 8);
  if (param_2 == 0xb) {
loc_F002C9FC:
    iVar2 = 0x2d;
    goto locret_F002CC50;
  }
  if ((param_5 != 0) && (*(sword *)(param_5 + 8) != 0)) {
loc_F002CA20:
    iVar2 = 0x2d;
    goto loc_F002CC3C;
  }
  if ((iVar1 == 0) && (param_2 != 0)) {
    iVar2 = 0x16;
    goto loc_F002CC3C;
  }
  switch(param_2) {
  case :
    if ((*(word *)(param_1 + 6) & 0x80) == 0) {
      iVar2 = 0xd;
    }
    else {
      iVar2 = 0x16;
      if (iVar1 == 0) {
        _raw_attach(param_1,param_4);
        iVar2 = param_1;
      }
    }
    break;
  case :
    if (iVar1 == 0) {
      iVar2 = 0x39;
      break;
    }
    _raw_detach(iVar1);
    bVar3 = param_3 == 0;
    goto loc_F002CC40;
  case :
    iVar2 = 0x16;
    if ((*(word *)(iVar1 + 0x4c) & 1) == 0) {
      _raw_bind(param_1,param_4);
      iVar2 = param_1;
    }
    break;
  case :
  case :
  case :
  case :
    goto loc_F002CA20;
  case :
    if ((*(word *)(iVar1 + 0x4c) & 2) != 0) {
      iVar2 = 0x38;
      break;
    }
    _raw_connaddr(iVar1,param_4);
    _soisconnected(param_1);
    bVar3 = param_3 == 0;
    goto loc_F002CC40;
  case :
    if ((*(word *)(iVar1 + 0x4c) & 2) != 0) {
      _raw_disconnect(iVar1);
      goto loc_F002CBF0;
    }
    iVar2 = 0x39;
    break;
  case :
    _socantsendmore(param_1);
    bVar3 = param_3 == 0;
    goto loc_F002CC40;
  case :
  case :
    goto loc_F002C9FC;
  case :
    if (param_4 == 0) {
      if ((*(word *)(iVar1 + 0x4c) & 2) != 0) goto loc_F002CBB0;
      iVar2 = 0x39;
    }
    else {
      iVar2 = 0x38;
      if ((*(word *)(iVar1 + 0x4c) & 2) == 0) {
        _raw_connaddr(iVar1,param_4);
loc_F002CBB0:
        (**(code **)(*(int *)(param_1 + 0xc) + 0x10))(param_3,param_1);
        iVar2 = param_3;
        param_3 = 0;
        if (param_4 != 0) {
          *(word *)(iVar1 + 0x4c) = *(word *)(iVar1 + 0x4c) & 0xfffd;
        }
      }
    }
    break;
  case :
    _raw_disconnect(iVar1);
    _sofree(param_1);
loc_F002CBF0:
    _soisdisconnected(param_1);
    bVar3 = param_3 == 0;
    goto loc_F002CC40;
  :
    _panic(aRawUsrreq);
    break;
  case :
    iVar2 = 0;
    goto locret_F002CC50;
  case :
    iVar1 = iVar1 + 0x1c;
    goto loc_F002CC14;
  case :
    iVar1 = iVar1 + 0xc;
loc_F002CC14:
    _bcopy(iVar1,param_4 + *(int *)(param_4 + 4),0x10);
    *(undefined2 *)(param_4 + 8) = 0x10;
  }
loc_F002CC3C:
  bVar3 = param_3 == 0;
loc_F002CC40:
  if (!bVar3) {
    _m_freem(param_3);
  }
locret_F002CC50:
  return CONCAT44(param_2,iVar2);
}
