/* GHIDRADEC_FUNCTION index=650 start=0xf002bc18 */

undefined8 _if_control(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
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
  if (*(code **)(param_1 + 0x38) == (code *)0x0) {
    param_1 = 6;
  }
  else {
    (**(code **)(param_1 + 0x38))(param_1,param_2,param_3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=651 start=0xf002bc50 */

/* WARNING: Removing unreachable block (ram,0xf002bd44) */

undefined8 _if_ioctl(int param_1,uint param_2,undefined *param_3)

{
  undefined *puVar1;
  code *pcVar2;
  undefined4 unaff_l0;
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
  pcVar2 = *(code **)(param_1 + 0x38);
  if (pcVar2 == (code *)0x0) {
    param_1 = 6;
    goto locret_F002BD84;
  }
  if (param_2 == 0x80206931) {
    _if_control(param_1,_IFCONTROL_ADDMULTICAST);
    goto locret_F002BD84;
  }
  if (param_2 < 0x80206932) {
    if (param_2 == 0x8020690c) {
      puVar1 = (undefined *)&_IFCONTROL_SETADDR;
    }
    else {
      if (param_2 != 0x80206910) {
        *(uint *)((int)register0x00000038 + -0x10) = param_2;
        goto loc_F002BD60;
      }
      puVar1 = _IFCONTROL_SETFLAGS;
      param_3 = param_3 + 0x10;
    }
  }
  else if (param_2 == 0xc020690d) {
    puVar1 = (undefined *)&_IFCONTROL_GETADDR;
    param_3 = param_3 + 0x10;
  }
  else if (param_2 < 0xc020690e) {
    if (param_2 == 0x80206932) {
      puVar1 = _IFCONTROL_RMVMULTICAST;
    }
    else {
      *(uint *)((int)register0x00000038 + -0x10) = param_2;
loc_F002BD60:
      *(undefined **)((int)register0x00000038 + -0xc) = param_3;
      puVar1 = _IFCONTROL_UNIXIOCTL;
      pcVar2 = *(code **)(param_1 + 0x38);
      param_3 = (undefined *)((int)register0x00000038 + -0x10);
    }
  }
  else {
    if (param_2 != 0xc0206921) {
      *(uint *)((int)register0x00000038 + -0x10) = param_2;
      goto loc_F002BD60;
    }
    puVar1 = _IFCONTROL_AUTOADDR;
    param_3 = param_3 + 0x10;
  }
  (*pcVar2)(param_1,puVar1,param_3);
locret_F002BD84:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=652 start=0xf002bd8c */

undefined8 _if_init(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  iVar1 = 6;
  if (*(code **)(param_1 + 0x30) != (code *)0x0) {
    (**(code **)(param_1 + 0x30))();
    iVar1 = param_1;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=653 start=0xf002bdb8 */

undefined8 _if_getbuf(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  iVar1 = 0;
  if (*(code **)(param_1 + 0x40) != (code *)0x0) {
    (**(code **)(param_1 + 0x40))();
    iVar1 = param_1;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=654 start=0xf002bde4 */

undefined8 _if_private(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x58));
}
/* GHIDRADEC_FUNCTION index=655 start=0xf002bdf4 */

undefined8 _if_unit(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,(int)*(sword *)(param_1 + 8));
}
/* GHIDRADEC_FUNCTION index=656 start=0xf002be04 */

undefined8 _if_name(undefined4 *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*param_1);
}
/* GHIDRADEC_FUNCTION index=657 start=0xf002be14 */

undefined8 _if_type(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 4));
}
/* GHIDRADEC_FUNCTION index=658 start=0xf002be24 */

undefined8 _if_mtu(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,(int)*(sword *)(param_1 + 10));
}
/* GHIDRADEC_FUNCTION index=659 start=0xf002be34 */

undefined8 _if_class(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x14));
}
/* GHIDRADEC_FUNCTION index=660 start=0xf002be44 */

undefined8 _if_flags(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,(int)*(sword *)(param_1 + 0xc));
}
/* GHIDRADEC_FUNCTION index=661 start=0xf002be54 */

undefined8 _if_opackets(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x4c));
}
/* GHIDRADEC_FUNCTION index=662 start=0xf002be64 */

undefined8 _if_ipackets(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x44));
}
/* GHIDRADEC_FUNCTION index=663 start=0xf002be74 */

undefined8 _if_oerrors(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x50));
}
/* GHIDRADEC_FUNCTION index=664 start=0xf002be84 */

undefined8 _if_ierrors(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x48));
}
/* GHIDRADEC_FUNCTION index=665 start=0xf002be94 */

undefined8 _if_collisions(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x54));
}
/* GHIDRADEC_FUNCTION index=666 start=0xf002bea4 */

undefined8 _if_flags_set(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  *(sword *)(param_1 + 0xc) = (sword)param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=667 start=0xf002beb4 */

undefined8 _if_opackets_set(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  *(undefined4 *)(param_1 + 0x4c) = param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=668 start=0xf002bec4 */

undefined8 _if_ipackets_set(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  *(undefined4 *)(param_1 + 0x44) = param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=669 start=0xf002bed4 */

undefined8 _if_oerrors_set(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  *(undefined4 *)(param_1 + 0x50) = param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=670 start=0xf002bee4 */

undefined8 _if_ierrors_set(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  *(undefined4 *)(param_1 + 0x48) = param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=671 start=0xf002bef4 */

undefined8 _if_collisions_set(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  *(undefined4 *)(param_1 + 0x54) = param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=672 start=0xf002bf44 */

undefined8 _iflist_first(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,_ifnet);
}
/* GHIDRADEC_FUNCTION index=673 start=0xf002bf58 */

undefined8 _iflist_next(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x5c));
}
/* GHIDRADEC_FUNCTION index=674 start=0xf002bf80 */

undefined8 _if_detach(undefined4 *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  *param_1 = &aNull;
  param_1[1] = &aNull;
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined2 *)((int)param_1 + 10) = 0;
  *(undefined2 *)(param_1 + 3) = 0;
  param_1[10] = 0;
  param_1[0xc] = sub_F002BF68;
  param_1[0xd] = sub_F002BF68;
  param_1[0xe] = sub_F002BF68;
  param_1[0xf] = sub_F002BF68;
  param_1[0x10] = sub_F002BF74;
  param_1[0x16] = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=675 start=0xf002bfd4 */

/* WARNING: Removing unreachable block (ram,0xf002c05c) */
/* WARNING: Removing unreachable block (ram,0xf002c118) */
/* WARNING: Removing unreachable block (ram,0xf002c050) */

undefined8
_if_attach(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  bool bVar1;
  undefined5 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar6;
  undefined4 unaff_l3;
  undefined4 uVar7;
  undefined4 unaff_l4;
  undefined4 uVar8;
  undefined4 unaff_l5;
  undefined4 uVar9;
  undefined4 unaff_l6;
  undefined4 uVar10;
  undefined4 unaff_l7;
  undefined4 uVar11;
  undefined4 unaff_i0;
  undefined4 *puVar12;
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
  uVar10 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar7 = *(undefined4 *)((int)register0x00000038 + 0x60);
  uVar8 = *(undefined4 *)((int)register0x00000038 + 100);
  uVar9 = *(undefined4 *)((int)register0x00000038 + 0x68);
  uVar6 = *(uint *)((int)register0x00000038 + 0x6c);
  bVar1 = false;
  uVar11 = *(undefined4 *)((int)register0x00000038 + 0x70);
  puVar12 = _ifnet;
  if (_ifnet != (undefined4 *)0x0) {
    puVar2 = (undefined5 *)*_ifnet;
    do {
      if (puVar2 == &aNull) {
        if (puVar12[5] == uVar6) {
          bVar1 = true;
          break;
        }
        puVar12 = (undefined4 *)puVar12[0x17];
      }
      else {
        puVar12 = (undefined4 *)puVar12[0x17];
      }
      if (puVar12 == (undefined4 *)0x0) break;
      puVar2 = (undefined5 *)*puVar12;
    } while( true );
  }
  if (bVar1) {
    *puVar12 = param_6;
  }
  else {
    puVar12 = (undefined4 *)0x60;
    _kalloc();
    _bzero();
    *puVar12 = param_6;
  }
  puVar12[1] = uVar7;
  *(sword *)(puVar12 + 2) = (sword)uVar10;
  *(sword *)((int)puVar12 + 10) = (sword)uVar8;
  *(sword *)(puVar12 + 3) = (sword)uVar9;
  puVar12[4] = 0;
  puVar12[6] = 0;
  puVar12[0xc] = param_1;
  puVar12[0xd] = param_3;
  puVar12[0xe] = param_5;
  puVar12[0xf] = param_2;
  puVar12[0x10] = param_4;
  puVar12[0x16] = uVar11;
  puVar12[5] = uVar6;
  puVar12[0x11] = 0;
  puVar12[0x12] = 0;
  puVar12[0x13] = 0;
  puVar12[0x14] = 0;
  puVar12[0x15] = 0;
  puVar12[10] = _ifqmaxlen;
  if (!bVar1) {
    piVar5 = (int *)&_ifnet;
    puVar3 = _ifnet;
    while (puVar3 != (undefined4 *)0x0) {
      iVar4 = *piVar5;
      if (*(uint *)(iVar4 + 0x14) < uVar6) {
        iVar4 = *piVar5;
        goto loc_F002C100;
      }
      piVar5 = (int *)(iVar4 + 0x5c);
      puVar3 = *(undefined4 **)(iVar4 + 0x5c);
    }
    iVar4 = *piVar5;
loc_F002C100:
    puVar12[0x17] = iVar4;
    *piVar5 = (int)puVar12;
  }
  if (puVar12[5] == 0) {
    sub_F002BF04(puVar12);
  }
  return CONCAT44(param_2,puVar12);
}
/* GHIDRADEC_FUNCTION index=676 start=0xf002c128 */

/* WARNING: Removing unreachable block (ram,0xf002c134) */

undefined8 _if_registervirtual(code *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar4;
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
  piVar4 = &dword_F012F414;
  puVar1 = (undefined4 *)0xc;
  _kalloc();
  *puVar1 = param_1;
  puVar1[1] = param_2;
  iVar2 = dword_F012F414;
  puVar1[2] = 0;
  for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    iVar2 = *piVar4;
    piVar4 = (int *)(iVar2 + 8);
  }
  *piVar4 = (int)puVar1;
  if (_ifnet != 0) {
    iVar3 = *(int *)(_ifnet + 0x14);
    iVar2 = _ifnet;
    while( true ) {
      if (iVar3 == 0) {
        (*param_1)(param_2,iVar2);
        iVar2 = *(int *)(iVar2 + 0x5c);
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x5c);
      }
      if (iVar2 == 0) break;
      iVar3 = *(int *)(iVar2 + 0x14);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=677 start=0xf002c1b8 */

/* WARNING: Removing unreachable block (ram,0xf002c224) */

undefined8 _if_handle_input(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  code *pcVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  if (_ifnet != 0) {
    pcVar2 = *(code **)(_ifnet + 0x3c);
    iVar3 = _ifnet;
    while( true ) {
      if (pcVar2 == (code *)0x0) {
        iVar3 = *(int *)(iVar3 + 0x5c);
      }
      else if (*(int *)(iVar3 + 0x14) == 0) {
        iVar3 = *(int *)(iVar3 + 0x5c);
      }
      else {
        iVar1 = iVar3;
        (*pcVar2)(iVar3,param_1,param_2,param_3);
        if (iVar1 == 0) {
          uVar4 = 0;
          goto locret_F002C230;
        }
        iVar3 = *(int *)(iVar3 + 0x5c);
      }
      if (iVar3 == 0) break;
      pcVar2 = *(code **)(iVar3 + 0x3c);
    }
  }
  _nb_free(param_2);
  uVar4 = 0x2f;
locret_F002C230:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=678 start=0xf002c238 */

/* WARNING: Removing unreachable block (ram,0xf002c288) */

undefined8 _mbuf_read(int *param_1,int param_2,uint param_3,uint param_4)

{
  sword sVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  uint uVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  uVar3 = 0;
  do {
    if (param_1 == (int *)0x0) {
      uVar4 = 0xffffffff;
locret_F002C2C0:
      return CONCAT44(param_2,uVar4);
    }
    if (param_3 < uVar3) {
      sVar1 = *(sword *)(param_1 + 2);
    }
    else {
      if (param_3 < uVar3 + (int)*(sword *)(param_1 + 2)) {
        uVar2 = (int)*(sword *)(param_1 + 2) - (param_3 - uVar3);
        if (param_4 < uVar2) {
          uVar2 = param_4;
        }
        _bcopy((int)param_1 + (param_3 - uVar3) + param_1[1],param_2,uVar2);
        param_2 = param_2 + uVar2;
        param_4 = param_4 - uVar2;
        param_3 = param_3 + uVar2;
        if (param_4 == 0) {
          uVar4 = 0;
          goto locret_F002C2C0;
        }
      }
      sVar1 = *(sword *)(param_1 + 2);
    }
    param_1 = (int *)*param_1;
    uVar3 = uVar3 + (int)sVar1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=679 start=0xf002c2c8 */

/* WARNING: Removing unreachable block (ram,0xf002c34c) */
/* WARNING: Removing unreachable block (ram,0xf002c338) */
/* WARNING: Removing unreachable block (ram,0xf002c378) */
/* WARNING: Removing unreachable block (ram,0xf002c324) */
/* WARNING: Removing unreachable block (ram,0xf002c340) */
/* WARNING: Removing unreachable block (ram,0xf002c354) */
/* WARNING: Removing unreachable block (ram,0xf002c300) */

undefined8 _if_output_mbuf(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  int iVar4;
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
  iVar4 = 0;
  for (piVar3 = (int *)param_2; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
    iVar4 = iVar4 + *(sword *)(piVar3 + 2);
  }
  if (*(sword *)(param_1 + 10) < iVar4) {
    _m_freem(param_2);
    param_1 = 0x28;
  }
  else {
    iVar1 = param_1;
    (**(code **)(param_1 + 0x40))();
    if (iVar1 == 0) {
      _m_freem(param_2);
      param_1 = 0x37;
    }
    else {
      iVar2 = iVar1;
      _nb_map();
      _mbuf_read(param_2,iVar2,0,iVar4);
      iVar2 = iVar1;
      _nb_size(iVar1);
      _nb_shrink_bot(iVar1,iVar2 - iVar4);
      _m_freem(param_2);
      (**(code **)(param_1 + 0x34))(param_1,iVar1,param_3);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=680 start=0xf002c38c */

/* WARNING: Removing unreachable block (ram,0xf002c3fc) */
/* WARNING: Removing unreachable block (ram,0xf002c3c0) */
/* WARNING: Removing unreachable block (ram,0xf002c3dc) */
/* WARNING: Removing unreachable block (ram,0xf002c408) */
/* WARNING: Removing unreachable block (ram,0xf002c390) */

undefined8 _netisr_thread_continue(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
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
  _splnet();
  uVar1 = _netisr;
  while (uVar1 != 0) {
    _netisr = uVar1 & 0xfffffffb;
    if ((uVar1 & 4) != 0) {
      _ipintr();
      uVar1 = _netisr;
    }
    _netisr = uVar1;
    uVar1 = _netisr;
    if ((_netisr & 1) != 0) {
      _netisr = _netisr & 0xfffffffe;
      _rawintr();
      uVar1 = _netisr;
    }
  }
  _netisr = uVar1;
  _assert_wait(_soft_net_wakeup,0);
  _thread_block_with_continuation(_netisr_thread_continue);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=681 start=0xf002c418 */

/* WARNING: Removing unreachable block (ram,0xf002c434) */
/* WARNING: Removing unreachable block (ram,0xf002c440) */
/* WARNING: Removing unreachable block (ram,0xf002c424) */

undefined8 _netisr_thread(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  
  uVar1 = _active_threads;
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
  _stack_privilege(_active_threads);
  _thread_bind(uVar1,_master_processor);
  _thread_block_with_continuation(_netisr_thread_continue);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=682 start=0xf002c450 */

/* WARNING: Removing unreachable block (ram,0xf002c4e8) */
/* WARNING: Removing unreachable block (ram,0xf002c474) */
/* WARNING: Removing unreachable block (ram,0xf002c488) */
/* WARNING: Removing unreachable block (ram,0xf002c4f0) */
/* WARNING: Removing unreachable block (ram,0xf002c458) */

undefined8 _raw_attach(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  iVar1 = 0;
  _m_getclr(0,4);
  if (iVar1 == 0) {
    uVar5 = 0x37;
  }
  else {
    iVar4 = param_1 + 0x3c;
    iVar3 = iVar4;
    _sbreserve(iVar4,0x800);
    iVar2 = param_1 + 0x24;
    if (iVar3 != 0) {
      _sbreserve(iVar2,0x824);
      if (iVar2 != 0) {
        iVar2 = *(int *)(iVar1 + 4);
        iVar3 = iVar1 + iVar2;
        *(int *)(iVar3 + 8) = param_1;
        *(int *)(param_1 + 8) = iVar3;
        *(undefined4 *)(iVar3 + 0x30) = 0;
        *(sword *)(iVar3 + 0x2c) = (sword)**(undefined4 **)(*(int *)(param_1 + 0xc) + 4);
        *(sword *)(iVar3 + 0x2e) = (sword)param_2;
        *(int *)(iVar1 + iVar2) = _rawcb;
        *(int **)(iVar3 + 4) = &_rawcb;
        uVar5 = 0;
        *(int *)(_rawcb + 4) = iVar3;
        _rawcb = iVar3;
        goto locret_F002C4FC;
      }
      _sbrelease(iVar4);
    }
    _m_free(iVar1);
    uVar5 = 0x37;
  }
locret_F002C4FC:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=683 start=0xf002c504 */

/* WARNING: Removing unreachable block (ram,0xf002c588) */
/* WARNING: Removing unreachable block (ram,0xf002c554) */
/* WARNING: Removing unreachable block (ram,0xf002c524) */
/* WARNING: Removing unreachable block (ram,0xf002c570) */
/* WARNING: Removing unreachable block (ram,0xf002c590) */
/* WARNING: Removing unreachable block (ram,0xf002c518) */

undefined8 _raw_detach(int *param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = param_1[2];
  if (param_1[0xe] != 0) {
    _rtfree();
  }
  *(undefined4 *)(iVar2 + 8) = 0;
  _sofree(iVar2);
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  if (param_1[0xd] != 0) {
    _m_freem(param_1[0xd] & 0xffffff80);
  }
  if (iVar2 == _ip_mrouter) {
    _ip_mrouter_done();
    sVar1 = *(sword *)(param_1 + 0xb);
  }
  else {
    sVar1 = *(sword *)(param_1 + 0xb);
  }
  if (sVar1 == 2) {
    _ip_freemoptions(param_1[0x14]);
  }
  _m_freem((uint)param_1 & 0xffffff80);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=684 start=0xf002c5a0 */

/* WARNING: Removing unreachable block (ram,0xf002c5c4) */

undefined8 _raw_disconnect(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  *(word *)(param_1 + 0x4c) = *(word *)(param_1 + 0x4c) & 0xfffd;
  if ((*(word *)(*(int *)(param_1 + 8) + 6) & 1) != 0) {
    _raw_detach(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=685 start=0xf002c5d4 */

/* WARNING: Removing unreachable block (ram,0xf002c640) */
/* WARNING: Removing unreachable block (ram,0xf002c61c) */

undefined8 _raw_bind(int param_1,uint param_2)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
  int iVar2;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  iVar2 = param_2 + *(int *)(param_2 + 4);
  if (_ifnet != 0) {
    param_2 = (uint)*(word *)(param_2 + *(int *)(param_2 + 4));
    if (3 < param_2) {
      uVar3 = 0x2f;
      goto locret_F002C658;
    }
    if (param_2 < 2) {
      uVar3 = 0x2f;
      goto locret_F002C658;
    }
    if ((*(int *)(iVar2 + 4) == 0) || (iVar1 = iVar2, _ifa_ifwithaddr(), iVar1 != 0)) {
      iVar1 = *(int *)(param_1 + 8);
      _bcopy(iVar2,iVar1 + 0x1c,0x10);
      uVar3 = 0;
      *(word *)(iVar1 + 0x4c) = *(word *)(iVar1 + 0x4c) | 1;
      goto locret_F002C658;
    }
  }
  uVar3 = 0x31;
locret_F002C658:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=686 start=0xf002c660 */

/* WARNING: Removing unreachable block (ram,0xf002c670) */

undefined8 _raw_connaddr(int param_1,int param_2)

{
  undefined4 unaff_l0;
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
  _bcopy(param_2 + *(int *)(param_2 + 4),param_1 + 0xc,0x10);
  *(word *)(param_1 + 0x4c) = *(word *)(param_1 + 0x4c) | 2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=687 start=0xf002c68c */

undefined8 _raw_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  DAT_f01363f4._0_4_ = &_rawcb;
  _rawcb = &_rawcb;
  dword_F013416C = 0x32;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=688 start=0xf002c6b4 */

/* WARNING: Removing unreachable block (ram,0xf002c7d8) */
/* WARNING: Removing unreachable block (ram,0xf002c778) */
/* WARNING: Removing unreachable block (ram,0xf002c6d0) */
/* WARNING: Removing unreachable block (ram,0xf002c79c) */
/* WARNING: Removing unreachable block (ram,0xf002c7f4) */
/* WARNING: Removing unreachable block (ram,0xf002c6bc) */

undefined8 _raw_input(int param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l0;
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
  piVar2 = (int *)0x0;
  _m_get(0,2);
  if (piVar2 == (int *)0x0) {
    _m_freem(param_1);
  }
  else {
    *piVar2 = param_1;
    iVar3 = piVar2[1];
    *(undefined2 *)(piVar2 + 2) = 0x24;
    param_1 = (int)piVar2 + iVar3;
    *(undefined2 *)(param_1 + 4) = *param_4;
    *(undefined2 *)(param_1 + 6) = param_4[1];
    *(undefined2 *)(param_1 + 8) = param_4[2];
    *(undefined2 *)(param_1 + 10) = param_4[3];
    *(undefined2 *)(param_1 + 0xc) = param_4[4];
    *(undefined2 *)(param_1 + 0xe) = param_4[5];
    *(undefined2 *)(param_1 + 0x10) = param_4[6];
    *(undefined2 *)(param_1 + 0x12) = param_4[7];
    *(undefined2 *)(param_1 + 0x14) = *param_3;
    *(undefined2 *)(param_1 + 0x16) = param_3[1];
    *(undefined2 *)(param_1 + 0x18) = param_3[2];
    *(undefined2 *)(param_1 + 0x1a) = param_3[3];
    *(undefined2 *)(param_1 + 0x1c) = param_3[4];
    *(undefined2 *)(param_1 + 0x1e) = param_3[5];
    *(undefined2 *)(param_1 + 0x20) = param_3[6];
    *(undefined2 *)(param_1 + 0x22) = param_3[7];
    *(undefined2 *)((int)piVar2 + iVar3) = *param_2;
    *(undefined2 *)(param_1 + 2) = param_2[1];
    _spltty();
    if (dword_F0134168 < dword_F013416C) {
      piVar2[0x1f] = 0;
      piVar1 = piVar2;
      if (DAT_f0134164 != (int *)0x0) {
        DAT_f0134164[0x1f] = (int)piVar2;
        piVar1 = _rawintrq;
      }
      _rawintrq = piVar1;
      dword_F0134168 = dword_F0134168 + 1;
      DAT_f0134164 = piVar2;
    }
    else {
      _m_freem(piVar2);
    }
    _splx(param_1);
    _netisr = _netisr | 1;
    _wakeup(_soft_net_wakeup);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=689 start=0xf002c804 */

/* WARNING: Removing unreachable block (ram,0xf002c9a4) */
/* WARNING: Removing unreachable block (ram,0xf002c990) */
/* WARNING: Removing unreachable block (ram,0xf002c94c) */
/* WARNING: Removing unreachable block (ram,0xf002c938) */
/* WARNING: Removing unreachable block (ram,0xf002c8f0) */
/* WARNING: Removing unreachable block (ram,0xf002c84c) */
/* WARNING: Removing unreachable block (ram,0xf002c8c8) */
/* WARNING: Removing unreachable block (ram,0xf002c918) */
/* WARNING: Removing unreachable block (ram,0xf002c95c) */
/* WARNING: Removing unreachable block (ram,0xf002c9c4) */
/* WARNING: Removing unreachable block (ram,0xf002c9b0) */
/* WARNING: Removing unreachable block (ram,0xf002c9b8) */
/* WARNING: Removing unreachable block (ram,0xf002c808) */

undefined8 _rawintr(int *param_1,undefined4 param_2)

{
  int *piVar1;
  sword sVar2;
  word wVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 unaff_l0;
  int iVar8;
  undefined4 unaff_l1;
  undefined4 *puVar9;
  int iVar10;
  undefined4 unaff_l3;
  sword *psVar11;
  undefined4 unaff_l4;
  int iVar12;
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
  
  piVar4 = param_1;
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
    piVar4 = param_1;
  }
  while( true ) {
    _spltty();
    piVar7 = _rawintrq;
    if (_rawintrq != (int *)0x0) {
      if ((int *)_rawintrq[0x1f] == (int *)0x0) {
        DAT_f0134164 = 0;
      }
      piVar1 = _rawintrq + 0x1f;
      _rawintrq = (int *)_rawintrq[0x1f];
      *piVar1 = 0;
      dword_F0134168 = dword_F0134168 + -1;
    }
    _splx(param_1);
    iVar12 = 0;
    if (piVar7 == (int *)0x0) {
      return CONCAT44(param_2,piVar4);
    }
    psVar11 = (sword *)((int)piVar7 + piVar7[1]);
    if ((undefined4 **)_rawcb != &_rawcb) break;
loc_F002C978:
    iVar8 = iVar12 + 0x24;
    if (iVar12 == 0) {
      _m_freem();
      param_1 = piVar7;
    }
    else {
      iVar6 = iVar8;
      _sbappendaddr(iVar8,psVar11 + 10,*piVar7,0);
      if (iVar6 == 0) {
        _m_freem(*piVar7);
      }
      else {
        _sowakeup(iVar12,iVar8);
      }
      _m_free();
      param_1 = piVar7;
    }
  }
  sVar2 = *(sword *)(_rawcb + 0xb);
  puVar9 = _rawcb;
  do {
    if (sVar2 == *psVar11) {
      if (*(sword *)((int)puVar9 + 0x2e) == 0) {
        wVar3 = *(word *)(puVar9 + 0x13);
      }
      else {
        if (*(sword *)((int)puVar9 + 0x2e) != psVar11[1]) {
          puVar9 = (undefined4 *)*puVar9;
          goto loc_F002C96C;
        }
        wVar3 = *(word *)(puVar9 + 0x13);
      }
      puVar5 = puVar9 + 7;
      if (((wVar3 & 1) == 0) || (_bcmp(puVar5,psVar11 + 2,0x10), puVar5 == (undefined4 *)0x0)) {
        puVar5 = puVar9 + 3;
        if (((*(word *)(puVar9 + 0x13) & 2) == 0) ||
           (_bcmp(puVar5,psVar11 + 10,0x10), puVar5 == (undefined4 *)0x0)) {
          if (iVar12 == 0) {
loc_F002C964:
            iVar12 = puVar9[2];
          }
          else {
            iVar8 = *piVar7;
            _m_copy(iVar8,0,1000000000);
            if (iVar8 == 0) goto loc_F002C964;
            iVar10 = iVar12 + 0x24;
            iVar6 = iVar10;
            _sbappendaddr(iVar10,psVar11 + 10,iVar8,0);
            if (iVar6 != 0) {
              _sowakeup(iVar12,iVar10);
              goto loc_F002C964;
            }
            _m_freem(iVar8);
            iVar12 = puVar9[2];
          }
          puVar9 = (undefined4 *)*puVar9;
        }
        else {
          puVar9 = (undefined4 *)*puVar9;
        }
      }
      else {
        puVar9 = (undefined4 *)*puVar9;
      }
    }
    else {
      puVar9 = (undefined4 *)*puVar9;
    }
loc_F002C96C:
    if ((undefined4 **)puVar9 == &_rawcb) goto loc_F002C978;
    sVar2 = *(sword *)(puVar9 + 0xb);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=690 start=0xf002c9d8 */

undefined8 _raw_ctlinput(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=691 start=0xf002c9e4 */

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
/* GHIDRADEC_FUNCTION index=692 start=0xf002cc58 */

/* WARNING: Removing unreachable block (ram,0xf002cd90) */
/* WARNING: Removing unreachable block (ram,0xf002cd70) */
/* WARNING: Removing unreachable block (ram,0xf002ce00) */
/* WARNING: Removing unreachable block (ram,0xf002ccc8) */

undefined8 _rtalloc(int *param_1,undefined *param_2)

{
  sword sVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar9;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  code *pcVar10;
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
  iVar4 = *param_1;
  uVar9 = (uint)*(word *)(param_1 + 1);
  if ((((iVar4 == 0) || (*(int *)(iVar4 + 0x2c) == 0)) || ((*(word *)(iVar4 + 0x24) & 1) == 0)) &&
     (uVar9 < 0x11)) {
    bVar2 = true;
    (**(code **)(_afswitch + uVar9 * 8))(param_1 + 1,(undefined *)((int)register0x00000038 + -0x10))
    ;
    uVar8 = *(uint *)((int)register0x00000038 + -0x10);
    puVar3 = DAT_f0135000;
    pcVar10 = *(code **)(_afswitch + uVar9 * 8 + 4);
    param_2 = _rthost;
    _splnet();
    piVar7 = param_1 + 1;
loc_F002CCD4:
    puVar6 = *(undefined4 **)(param_2 + (uVar8 & 7) * 4);
    if (puVar6 != (undefined4 *)0x0) {
      iVar4 = puVar6[1];
      do {
        iVar5 = (int)puVar6 + iVar4;
        if (*(uint *)((int)puVar6 + iVar4) == uVar8) {
          if ((*(word *)(iVar5 + 0x24) & 1) == 0) {
            puVar6 = (undefined4 *)*puVar6;
          }
          else if ((*(word *)(*(int *)(iVar5 + 0x2c) + 0xc) & 1) == 0) {
            puVar6 = (undefined4 *)*puVar6;
          }
          else {
            iVar4 = iVar5 + 4;
            if (bVar2) {
              _bcmp(iVar4,piVar7,0x10);
              if (iVar4 == 0) {
                sVar1 = *(sword *)(iVar5 + 0x26);
loc_F002CD88:
                *(sword *)(iVar5 + 0x26) = sVar1 + 1;
                _splx(puVar3);
                if (piVar7 == (int *)_wildcard) {
                  sRamf0135288 = sRamf0135288 + 1;
                  *param_1 = iVar5;
                }
                else {
                  *param_1 = iVar5;
                }
                goto locret_F002CE1C;
              }
              puVar6 = (undefined4 *)*puVar6;
            }
            else if (*(word *)(iVar5 + 4) == uVar9) {
              iVar4 = iVar5 + 4;
              (*pcVar10)(iVar4,piVar7);
              if (iVar4 != 0) {
                sVar1 = *(sword *)(iVar5 + 0x26);
                goto loc_F002CD88;
              }
              puVar6 = (undefined4 *)*puVar6;
            }
            else {
              puVar6 = (undefined4 *)*puVar6;
            }
          }
        }
        else {
          puVar6 = (undefined4 *)*puVar6;
        }
        if (puVar6 == (undefined4 *)0x0) break;
        iVar4 = puVar6[1];
      } while( true );
    }
    uVar8 = *(uint *)((int)register0x00000038 + -0xc);
    if (bVar2) {
      bVar2 = false;
      param_2 = _rtnet;
      goto loc_F002CCD4;
    }
    if (piVar7 != (int *)_wildcard) {
      uVar8 = 0;
      piVar7 = (int *)_wildcard;
      goto loc_F002CCD4;
    }
    _splx(puVar3);
    sRamf0135286 = sRamf0135286 + 1;
  }
locret_F002CE1C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=693 start=0xf002ce24 */

/* WARNING: Removing unreachable block (ram,0xf002ce6c) */
/* WARNING: Removing unreachable block (ram,0xf002ce38) */

undefined8 _rtfree(uint param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 unaff_l0;
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
  if (param_1 == 0) {
    _panic(&aRtfree);
    sVar1 = sRam00000026;
  }
  else {
    sVar1 = *(sword *)(param_1 + 0x26);
  }
  *(sword *)(param_1 + 0x26) = sVar1 + -1;
  if ((*(uint *)(param_1 + 0x24) & 0x1ffff) == 0) {
    _rttrash = _rttrash + -1;
    _m_free(param_1 & 0xffffff80);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=694 start=0xf002ce7c */

/* WARNING: Removing unreachable block (ram,0xf002cff8) */
/* WARNING: Removing unreachable block (ram,0xf002cf80) */
/* WARNING: Removing unreachable block (ram,0xf002cf04) */
/* WARNING: Removing unreachable block (ram,0xf002cee8) */
/* WARNING: Removing unreachable block (ram,0xf002cf18) */
/* WARNING: Removing unreachable block (ram,0xf002cfac) */
/* WARNING: Removing unreachable block (ram,0xf002d08c) */
/* WARNING: Removing unreachable block (ram,0xf002ce80) */

undefined8 _rtredirect(word *param_1,undefined2 *param_2,uint param_3,int param_4)

{
  undefined2 *puVar1;
  undefined *puVar2;
  undefined2 uVar3;
  undefined4 unaff_l0;
  int iVar4;
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
  bool bVar5;
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
  puVar1 = param_2;
  _ifa_ifwithnet();
  if (puVar1 == (undefined2 *)0x0) {
    _rtstat = _rtstat + 1;
    goto locret_F002D094;
  }
  *(word *)((int)register0x00000038 + -0x1c) = *param_1;
  *(word *)((int)register0x00000038 + -0x1a) = param_1[1];
  *(word *)((int)register0x00000038 + -0x18) = param_1[2];
  *(word *)((int)register0x00000038 + -0x16) = param_1[3];
  *(word *)((int)register0x00000038 + -0x14) = param_1[4];
  *(word *)((int)register0x00000038 + -0x12) = param_1[5];
  *(word *)((int)register0x00000038 + -0x10) = param_1[6];
  *(word *)((int)register0x00000038 + -0xe) = param_1[7];
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  _rtalloc((undefined *)((int)register0x00000038 + -0x20));
  iVar4 = *(int *)((int)register0x00000038 + -0x20);
  if (((iVar4 == 0) || (_bcmp(param_4,iVar4 + 0x14,0x10), param_4 == 0)) &&
     (puVar1 = param_2, _ifa_ifwithaddr(), puVar1 == (undefined2 *)0x0)) {
    bVar5 = iVar4 == 0;
    if (!bVar5) {
      puVar2 = _wildcard;
      (**(code **)(DAT_f010c154 + (uint)*param_1 * 8))(_wildcard,iVar4 + 4);
      bVar5 = iVar4 == 0;
      if (puVar2 != (undefined *)0x0) {
        _rtfree(iVar4);
        iVar4 = 0;
        bVar5 = true;
      }
    }
    if (bVar5) {
      _rtinit(param_1,param_2,0x8030720a,param_3 & 4 | 0x12);
      DAT_f0135282._0_2_ = DAT_f0135282._0_2_ + 1;
      goto locret_F002D094;
    }
    if ((*(word *)(iVar4 + 0x24) & 2) == 0) {
      _rtstat = _rtstat + 1;
    }
    else {
      if ((*(word *)(iVar4 + 0x24) & 4) == 0) {
        if ((param_3 & 4) != 0) {
          _rtinit(param_1,param_2,0x8030720a,param_3 | 0x10);
          DAT_f0135282._0_2_ = DAT_f0135282._0_2_ + 1;
          goto loc_F002D08C;
        }
        uVar3 = *param_2;
      }
      else {
        uVar3 = *param_2;
      }
      *(undefined2 *)(iVar4 + 0x14) = uVar3;
      *(undefined2 *)(iVar4 + 0x16) = param_2[1];
      *(undefined2 *)(iVar4 + 0x18) = param_2[2];
      *(undefined2 *)(iVar4 + 0x1a) = param_2[3];
      *(undefined2 *)(iVar4 + 0x1c) = param_2[4];
      *(undefined2 *)(iVar4 + 0x1e) = param_2[5];
      *(undefined2 *)(iVar4 + 0x20) = param_2[6];
      *(undefined2 *)(iVar4 + 0x22) = param_2[7];
      *(word *)(iVar4 + 0x24) = *(word *)(iVar4 + 0x24) | 0x20;
      DAT_f0135282._2_2_ = DAT_f0135282._2_2_ + 1;
    }
  }
  else {
    _rtstat = _rtstat + 1;
    if (iVar4 == 0) goto locret_F002D094;
  }
loc_F002D08C:
  _rtfree(iVar4);
locret_F002D094:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=695 start=0xf002d09c */

/* WARNING: Removing unreachable block (ram,0xf002d0d4) */
/* WARNING: Removing unreachable block (ram,0xf002d0c0) */

undefined8 _rtioctl(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
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
  uVar1 = param_1 + 0x7fcf8df6;
  if (uVar1 < 2) {
    _suser();
    if (uVar1 == 0) {
      param_1 = (int)*(char *)(dword_F0133DDC + 0x38);
    }
    else {
      _rtrequest(param_1,param_2);
    }
  }
  else {
    param_1 = 0x16;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=696 start=0xf002d0f8 */

/* WARNING: Removing unreachable block (ram,0xf002d2a0) */
/* WARNING: Removing unreachable block (ram,0xf002d314) */
/* WARNING: Removing unreachable block (ram,0xf002d2d4) */
/* WARNING: Removing unreachable block (ram,0xf002d210) */
/* WARNING: Removing unreachable block (ram,0xf002d1f4) */
/* WARNING: Removing unreachable block (ram,0xf002d2fc) */
/* WARNING: Removing unreachable block (ram,0xf002d2ec) */
/* WARNING: Removing unreachable block (ram,0xf002d330) */
/* WARNING: Removing unreachable block (ram,0xf002d410) */
/* WARNING: Removing unreachable block (ram,0xf002d17c) */

undefined8 _rtrequest(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 unaff_l1;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined4 unaff_l3;
  uint uVar9;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  code *pcVar10;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar11;
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
  iVar6 = 0;
  uVar3 = (uint)*(word *)(param_2 + 4);
  uVar11 = 0;
  if (0x10 < uVar3) {
    uVar11 = 0x2f;
    goto locret_F002D418;
  }
  (**(code **)(_afswitch + uVar3 * 8))(param_2 + 4,(undefined *)((int)register0x00000038 + -0x10));
  uVar9 = *(uint *)((int)register0x00000038 + -0x10);
  if ((*(word *)(param_2 + 0x24) & 4) == 0) {
    uVar9 = *(uint *)((int)register0x00000038 + -0xc);
    puVar1 = _rtnet;
  }
  else {
    puVar1 = _rthost;
  }
  piVar7 = (int *)(puVar1 + (uVar9 & 7) * 4);
  puVar1 = _afswitch;
  pcVar10 = *(code **)(_afswitch + uVar3 * 8 + 4);
  _spltty();
  piVar4 = (int *)*piVar7;
  piVar8 = piVar7;
  if (piVar4 != (int *)0x0) {
    iVar2 = piVar4[1];
    do {
      piVar5 = piVar4;
      iVar6 = (int)piVar5 + iVar2;
      if (*(uint *)((int)piVar5 + iVar2) == uVar9) {
        iVar2 = iVar6 + 4;
        if ((*(word *)(param_2 + 0x24) & 4) == 0) {
          if (*(sword *)(iVar6 + 4) == *(sword *)(param_2 + 4)) {
            iVar2 = iVar6 + 4;
            (*pcVar10)(iVar2,param_2 + 4);
            if (iVar2 != 0) goto loc_F002D20C;
          }
        }
        else {
          _bcmp(iVar2,param_2 + 4,0x10);
          if (iVar2 == 0) {
loc_F002D20C:
            iVar2 = iVar6 + 0x14;
            _bcmp(iVar2,param_2 + 0x14,0x10);
            piVar4 = piVar5;
            if (iVar2 == 0) break;
          }
        }
      }
      piVar4 = (int *)*piVar5;
      piVar8 = piVar5;
      if (piVar4 == (int *)0x0) break;
      iVar2 = piVar4[1];
    } while( true );
  }
  if (param_1 == -0x7fcf8df6) {
    if (piVar4 == (int *)0x0) {
      if ((*(word *)(param_2 + 0x24) & 2) == 0) {
        iVar6 = 0;
        if ((*(word *)(param_2 + 0x24) & 4) != 0) {
          iVar6 = param_2 + 4;
          _ifa_ifwithdstaddr();
        }
        if (iVar6 == 0) {
          iVar6 = param_2 + 0x14;
          _ifa_ifwithaddr();
          goto loc_F002D308;
        }
      }
      else {
        iVar6 = param_2 + 0x14;
        _ifa_ifwithdstaddr();
loc_F002D308:
        if (iVar6 == 0) {
          iVar6 = param_2 + 0x14;
          _ifa_ifwithnet();
          if (iVar6 == 0) {
            uVar11 = 0x33;
            goto loc_F002D410;
          }
        }
      }
      piVar4 = (int *)0x0;
      _m_get(0,5);
      if (piVar4 == (int *)0x0) {
        uVar11 = 0x37;
      }
      else {
        *piVar4 = *piVar7;
        *piVar7 = (int)piVar4;
        piVar4[1] = 0xc;
        iVar2 = piVar4[1];
        *(undefined2 *)(piVar4 + 2) = 0x30;
        *(uint *)((int)piVar4 + iVar2) = uVar9;
        *(undefined2 *)((int)piVar4 + iVar2 + 4) = *(undefined2 *)(param_2 + 4);
        *(undefined2 *)((int)piVar4 + iVar2 + 6) = *(undefined2 *)(param_2 + 6);
        *(undefined2 *)((int)piVar4 + iVar2 + 8) = *(undefined2 *)(param_2 + 8);
        *(undefined2 *)((int)piVar4 + iVar2 + 10) = *(undefined2 *)(param_2 + 10);
        *(undefined2 *)((int)piVar4 + iVar2 + 0xc) = *(undefined2 *)(param_2 + 0xc);
        *(undefined2 *)((int)piVar4 + iVar2 + 0xe) = *(undefined2 *)(param_2 + 0xe);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x10) = *(undefined2 *)(param_2 + 0x10);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x12) = *(undefined2 *)(param_2 + 0x12);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x14) = *(undefined2 *)(param_2 + 0x14);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x16) = *(undefined2 *)(param_2 + 0x16);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x18) = *(undefined2 *)(param_2 + 0x18);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x1a) = *(undefined2 *)(param_2 + 0x1a);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x1c) = *(undefined2 *)(param_2 + 0x1c);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x1e) = *(undefined2 *)(param_2 + 0x1e);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x20) = *(undefined2 *)(param_2 + 0x20);
        *(undefined2 *)((int)piVar4 + iVar2 + 0x22) = *(undefined2 *)(param_2 + 0x22);
        *(word *)((int)piVar4 + iVar2 + 0x24) = *(word *)(param_2 + 0x24) & 0x16 | 1;
        *(undefined2 *)((int)piVar4 + iVar2 + 0x26) = 0;
        *(undefined4 *)((int)piVar4 + iVar2 + 0x28) = 0;
        *(undefined4 *)((int)piVar4 + iVar2 + 0x2c) = *(undefined4 *)(iVar6 + 0x20);
      }
    }
    else {
      uVar11 = 0x11;
    }
  }
  else if (param_1 == -0x7fcf8df5) {
    if (piVar4 == (int *)0x0) {
      uVar11 = 3;
    }
    else {
      *piVar8 = *piVar4;
      if (*(sword *)(iVar6 + 0x26) < 1) {
        _m_free(piVar4);
      }
      else {
        *(word *)(iVar6 + 0x24) = *(word *)(iVar6 + 0x24) & 0xfffe;
        _rttrash = _rttrash + 1;
        *piVar4 = 0;
      }
    }
  }
loc_F002D410:
  _splx(puVar1);
locret_F002D418:
  return CONCAT44(param_2,uVar11);
}
/* GHIDRADEC_FUNCTION index=697 start=0xf002d420 */

/* WARNING: Removing unreachable block (ram,0xf002d4bc) */
/* WARNING: Removing unreachable block (ram,0xf002d42c) */

undefined8 _rtinit(undefined2 *param_1,undefined2 *param_2,undefined4 param_3,undefined2 param_4)

{
  undefined4 unaff_l0;
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
  _bzero((undefined *)((int)register0x00000038 + -0x38),0x30);
  *(undefined2 *)((int)register0x00000038 + -0x34) = *param_1;
  *(undefined2 *)((int)register0x00000038 + -0x32) = param_1[1];
  *(undefined2 *)((int)register0x00000038 + -0x30) = param_1[2];
  *(undefined2 *)((int)register0x00000038 + -0x2e) = param_1[3];
  *(undefined2 *)((int)register0x00000038 + -0x2c) = param_1[4];
  *(undefined2 *)((int)register0x00000038 + -0x2a) = param_1[5];
  *(undefined2 *)((int)register0x00000038 + -0x28) = param_1[6];
  *(undefined2 *)((int)register0x00000038 + -0x26) = param_1[7];
  *(undefined2 *)((int)register0x00000038 + -0x24) = *param_2;
  *(undefined2 *)((int)register0x00000038 + -0x22) = param_2[1];
  *(undefined2 *)((int)register0x00000038 + -0x20) = param_2[2];
  *(undefined2 *)((int)register0x00000038 + -0x1e) = param_2[3];
  *(undefined2 *)((int)register0x00000038 + -0x1c) = param_2[4];
  *(undefined2 *)((int)register0x00000038 + -0x1a) = param_2[5];
  *(undefined2 *)((int)register0x00000038 + -0x18) = param_2[6];
  *(undefined2 *)((int)register0x00000038 + -0x16) = param_2[7];
  *(undefined2 *)((int)register0x00000038 + -0x14) = param_4;
  _rtrequest(param_3,(undefined *)((int)register0x00000038 + -0x38));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=698 start=0xf002d4cc */

/* WARNING: Removing unreachable block (ram,0xf002d550) */
/* WARNING: Removing unreachable block (ram,0xf002d4f0) */

undefined8 _arptimer(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  byte *pbVar5;
  undefined4 unaff_l1;
  undefined *puVar6;
  int iVar7;
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
  iVar7 = 0;
  _timeout(_arptimer,0,_hz * 0x3c);
  puVar6 = _arptab;
  pbVar5 = _arptab + 0xb;
  do {
    if ((*pbVar5 != 0) && ((*pbVar5 & 4) == 0)) {
      bVar2 = pbVar5[-1];
      pbVar5[-1] = bVar2 + 1;
      uVar4 = (uint)(byte)(bVar2 + 1);
      if ((*pbVar5 & 2) == 0) {
        iVar1 = 2;
        iVar3 = uVar4 - 2;
      }
      else {
        iVar1 = 0x13;
        iVar3 = uVar4 - 0x13;
      }
      if (iVar3 != 0 && iVar3 < 0 == SBORROW4(uVar4,iVar1)) {
        _arptfree(puVar6);
      }
    }
    iVar7 = iVar7 + 1;
    pbVar5 = pbVar5 + 0x14;
    puVar6 = puVar6 + 0x14;
  } while (iVar7 < 0xab);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=699 start=0xf002d574 */

/* WARNING: Removing unreachable block (ram,0xf002d650) */
/* WARNING: Removing unreachable block (ram,0xf002d618) */
/* WARNING: Removing unreachable block (ram,0xf002d5e4) */
/* WARNING: Removing unreachable block (ram,0xf002d5c8) */
/* WARNING: Removing unreachable block (ram,0xf002d608) */
/* WARNING: Removing unreachable block (ram,0xf002d630) */
/* WARNING: Removing unreachable block (ram,0xf002d67c) */
/* WARNING: Removing unreachable block (ram,0xf002d584) */

undefined8 _arpwhohas(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l3;
  undefined *puVar4;
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
  iVar1 = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = *param_3;
  _m_get(0,1);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 8) = 0x1c;
    *(undefined2 *)((int)register0x00000038 + -0x18) = 0x806;
    *(undefined2 *)(iVar1 + 8) = 0x1c;
    puVar4 = (undefined *)((int)register0x00000038 + -0x18);
    _bcopy(puVar4,puVar4 + (uint)DAT_f010c358[0] * 2 + 2,2);
    _bcopy((uint)DAT_f010c358[0] + (uint)DAT_f010c358[1] + -0xfef3ca4,
           (undefined *)((int)register0x00000038 + -0x16));
    iVar3 = 0x7c - *(sword *)(iVar1 + 8);
    *(int *)(iVar1 + 4) = iVar3;
    iVar2 = iVar1 + iVar3;
    _bcopy(_arpethertempl,iVar2,(int)*(sword *)(iVar1 + 8));
    _bcopy(param_2,iVar2 + 8,DAT_f010c358[0]);
    _bcopy((undefined *)((int)register0x00000038 + -0x1c),iVar2 + DAT_f010c358[0] + 8,
           DAT_f010c358[1]);
    _bcopy(param_4,iVar2 + (uint)DAT_f010c358[0] * 2 + (uint)DAT_f010c358[1] + 8);
    *(undefined2 *)(iVar1 + iVar3) = *(undefined2 *)(iVar1 + iVar3);
    *(undefined2 *)(iVar2 + 2) = *(undefined2 *)(iVar2 + 2);
    *(undefined2 *)(iVar2 + 6) = *(undefined2 *)(iVar2 + 6);
    *(undefined2 *)((int)register0x00000038 + -0x18) = 0;
    _if_output_mbuf(param_1,iVar1,puVar4);
  }
  return CONCAT44(param_2,param_1);
}

