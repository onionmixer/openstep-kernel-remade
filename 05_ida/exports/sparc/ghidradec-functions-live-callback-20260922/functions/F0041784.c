
/* WARNING: Removing unreachable block (ram,0xf0041a58) */
/* WARNING: Removing unreachable block (ram,0xf0041a30) */
/* WARNING: Removing unreachable block (ram,0xf0041a08) */
/* WARNING: Removing unreachable block (ram,0xf00419e0) */
/* WARNING: Removing unreachable block (ram,0xf00419b8) */
/* WARNING: Removing unreachable block (ram,0xf0041990) */
/* WARNING: Removing unreachable block (ram,0xf004197c) */
/* WARNING: Removing unreachable block (ram,0xf00419a4) */
/* WARNING: Removing unreachable block (ram,0xf00419cc) */
/* WARNING: Removing unreachable block (ram,0xf00419f4) */
/* WARNING: Removing unreachable block (ram,0xf0041a1c) */
/* WARNING: Removing unreachable block (ram,0xf0041a44) */
/* WARNING: Removing unreachable block (ram,0xf0041a6c) */
/* WARNING: Removing unreachable block (ram,0xf0041968) */

undefined8 sub_F0041784(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  if (*param_1 == 0) {
    piVar1 = param_1;
    (**(code **)(param_1[1] + 0x18))(param_1,0x44);
    if (piVar1 != (int *)0x0) {
      *piVar1 = *param_2;
      piVar1[1] = param_2[1];
      piVar1[2] = param_2[2];
      piVar1[3] = param_2[3];
      piVar1[4] = param_2[4];
      piVar1[5] = param_2[5];
      piVar1[6] = param_2[6];
      piVar1[7] = param_2[7];
      piVar1[8] = param_2[8];
      piVar1[9] = param_2[9];
      piVar1[10] = param_2[10];
      piVar1[0xb] = param_2[0xb];
      piVar1[0xc] = param_2[0xc];
      piVar1[0xd] = param_2[0xd];
      piVar1[0xe] = param_2[0xe];
      piVar1[0xf] = param_2[0xf];
      uVar2 = 1;
      piVar1[0x10] = param_2[0x10];
      goto locret_F0041A84;
    }
  }
  else {
    piVar1 = param_1;
    (**(code **)(param_1[1] + 0x18))(param_1,0x44);
    if (piVar1 != (int *)0x0) {
      *param_2 = *piVar1;
      param_2[1] = piVar1[1];
      param_2[2] = piVar1[2];
      param_2[3] = piVar1[3];
      param_2[4] = piVar1[4];
      param_2[5] = piVar1[5];
      param_2[6] = piVar1[6];
      param_2[7] = piVar1[7];
      param_2[8] = piVar1[8];
      param_2[9] = piVar1[9];
      param_2[10] = piVar1[10];
      param_2[0xb] = piVar1[0xb];
      param_2[0xc] = piVar1[0xc];
      param_2[0xd] = piVar1[0xd];
      param_2[0xe] = piVar1[0xe];
      param_2[0xf] = piVar1[0xf];
      uVar2 = 1;
      param_2[0x10] = piVar1[0x10];
      goto locret_F0041A84;
    }
  }
  piVar1 = param_1;
  _xdr_enum(param_1,param_2);
  if (((((piVar1 != (int *)0x0) &&
        (piVar1 = param_1, _xdr_u_long(param_1,param_2 + 1), piVar1 != (int *)0x0)) &&
       (piVar1 = param_1, _xdr_u_long(param_1,param_2 + 2), piVar1 != (int *)0x0)) &&
      (((piVar1 = param_1, _xdr_u_long(param_1,param_2 + 3), piVar1 != (int *)0x0 &&
        (piVar1 = param_1, _xdr_u_long(param_1,param_2 + 4), piVar1 != (int *)0x0)) &&
       ((piVar1 = param_1, _xdr_u_long(param_1,param_2 + 5), piVar1 != (int *)0x0 &&
        ((piVar1 = param_1, _xdr_u_long(param_1,param_2 + 6), piVar1 != (int *)0x0 &&
         (piVar1 = param_1, _xdr_u_long(param_1,param_2 + 7), piVar1 != (int *)0x0)))))))) &&
     ((piVar1 = param_1, _xdr_u_long(param_1,param_2 + 8), piVar1 != (int *)0x0 &&
      ((((piVar1 = param_1, _xdr_u_long(param_1,param_2 + 9), piVar1 != (int *)0x0 &&
         (piVar1 = param_1, _xdr_u_long(param_1,param_2 + 10), piVar1 != (int *)0x0)) &&
        (piVar1 = param_1, sub_F00422B8(param_1,param_2 + 0xb), piVar1 != (int *)0x0)) &&
       (piVar1 = param_1, sub_F00422B8(param_1,param_2 + 0xd), piVar1 != (int *)0x0)))))) {
    sub_F00422B8(param_1,param_2 + 0xf);
    uVar2 = 1;
    if (param_1 != (int *)0x0) goto locret_F0041A84;
  }
  uVar2 = 0;
locret_F0041A84:
  return CONCAT44(param_2,uVar2);
}

