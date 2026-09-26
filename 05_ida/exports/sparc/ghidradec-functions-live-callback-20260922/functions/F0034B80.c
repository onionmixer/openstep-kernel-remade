
/* WARNING: Removing unreachable block (ram,0xf0034be8) */
/* WARNING: Removing unreachable block (ram,0xf0034bfc) */
/* WARNING: Removing unreachable block (ram,0xf0034c64) */
/* WARNING: Removing unreachable block (ram,0xf0034bc0) */

undefined8
_tcp_trace(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,undefined2 param_5)

{
  int iVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
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
  iVar1 = _tcp_debx + 1;
  iVar3 = _tcp_debx * 0xa4;
  puVar2 = DAT_f0136400;
  _tcp_debx = iVar1;
  if (iVar1 == 100) {
    _tcp_debx = 0;
  }
  _iptime();
  *(undefined **)(_tcp_debug + iVar3) = puVar2;
  *(sword *)(_tcp_debug + iVar3 + 4) = (sword)param_1;
  *(sword *)(_tcp_debug + iVar3 + 6) = (sword)param_2;
  *(int *)(_tcp_debug + iVar3 + 8) = param_3;
  if (param_3 == 0) {
    _bzero(iVar3 + -0xfec9848,0x6c);
  }
  else {
    _memcpy(iVar3 + -0xfec9848,param_3,0x6c);
  }
  if (param_4 == (undefined4 *)0x0) {
    _bzero(iVar3 + -0xfec9874,0x28);
  }
  else {
    *(undefined4 *)(_tcp_debug + iVar3 + 0xc) = *param_4;
    *(undefined4 *)(_tcp_debug + iVar3 + 0x10) = param_4[1];
    *(undefined4 *)(_tcp_debug + iVar3 + 0x14) = param_4[2];
    *(undefined4 *)(_tcp_debug + iVar3 + 0x18) = param_4[3];
    *(undefined4 *)(_tcp_debug + iVar3 + 0x1c) = param_4[4];
    *(undefined4 *)(_tcp_debug + iVar3 + 0x20) = param_4[5];
    *(undefined4 *)(_tcp_debug + iVar3 + 0x24) = param_4[6];
    *(undefined4 *)(_tcp_debug + iVar3 + 0x28) = param_4[7];
    *(undefined4 *)(_tcp_debug + iVar3 + 0x2c) = param_4[8];
    *(undefined4 *)(_tcp_debug + iVar3 + 0x30) = param_4[9];
  }
  *(undefined2 *)(_tcp_debug + iVar3 + 0x34) = param_5;
  return CONCAT44(param_2,param_1);
}

