
/* WARNING: Removing unreachable block (ram,0xf004432c) */
/* WARNING: Removing unreachable block (ram,0xf0044304) */
/* WARNING: Removing unreachable block (ram,0xf0044318) */
/* WARNING: Removing unreachable block (ram,0xf0044340) */
/* WARNING: Removing unreachable block (ram,0xf00442f0) */

undefined8 _xdr_callhdr(int *param_1,int param_2)

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
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)(param_2 + 8) = 2;
  if (*param_1 == 0) {
    piVar1 = param_1;
    _xdr_u_long(param_1,param_2);
    if ((((piVar1 == (int *)0x0) ||
         (piVar1 = param_1, _xdr_enum(param_1,param_2 + 4), piVar1 == (int *)0x0)) ||
        (piVar1 = param_1, _xdr_u_long(param_1,param_2 + 8), piVar1 == (int *)0x0)) ||
       (piVar1 = param_1, _xdr_u_long(param_1,param_2 + 0xc), piVar1 == (int *)0x0)) {
      param_1 = (int *)0x0;
    }
    else {
      _xdr_u_long(param_1,param_2 + 0x10);
    }
  }
  else {
    param_1 = (int *)0x0;
  }
  return CONCAT44(param_2,param_1);
}
