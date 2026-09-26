/* GHIDRADEC_FUNCTION index=950 start=0xf0045b00 */

/* WARNING: Removing unreachable block (ram,0xf0045bb8) */
/* WARNING: Removing unreachable block (ram,0xf0045b60) */
/* WARNING: Removing unreachable block (ram,0xf0045b50) */
/* WARNING: Removing unreachable block (ram,0xf0045ba8) */
/* WARNING: Removing unreachable block (ram,0xf0045c10) */
/* WARNING: Removing unreachable block (ram,0xf0045b10) */

undefined8
_xdr_array(int *param_1,uint *param_2,uint *param_3,uint param_4,int param_5,code *param_6)

{
  int *piVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  int *piVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar7;
  undefined4 unaff_i3;
  uint uVar8;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  uVar5 = *param_2;
  piVar6 = (int *)0x1;
  piVar1 = param_1;
  _xdr_u_int(param_1,param_3);
  if (piVar1 == (int *)0x0) {
    puVar2 = aXdrArraySizeFa;
  }
  else {
    uVar7 = *param_3;
    if ((uVar7 <= param_4) || (*param_1 == 2)) {
      uVar3 = uVar7;
      .umul(uVar7,param_5);
      if (uVar5 == 0) {
        if (*param_1 == 1) {
          if (uVar7 == 0) {
            piVar6 = (int *)0x1;
            goto locret_F0045C20;
          }
          uVar5 = uVar3;
          _kalloc();
          *param_2 = uVar5;
          _bzero();
        }
        else if (*param_1 == 2) {
          piVar6 = (int *)0x1;
          goto locret_F0045C20;
        }
      }
      uVar8 = 0;
      if (uVar7 == 0) {
        iVar4 = *param_1;
      }
      else {
        do {
          bVar9 = piVar6 == (int *)0x0;
          piVar6 = (int *)0x0;
          if (bVar9) break;
          piVar6 = param_1;
          (*param_6)(param_1,uVar5,0xffffffff);
          uVar8 = uVar8 + 1;
          uVar5 = uVar5 + param_5;
        } while (uVar8 < uVar7);
        iVar4 = *param_1;
      }
      if (iVar4 == 2) {
        _kfree(*param_2,uVar3);
        *param_2 = 0;
      }
      goto locret_F0045C20;
    }
    puVar2 = aXdrArrayBadSiz;
  }
  piVar6 = (int *)0x0;
  _printf(puVar2);
locret_F0045C20:
  return CONCAT44(param_2,piVar6);
}
/* GHIDRADEC_FUNCTION index=951 start=0xf0045c28 */

undefined8 _xdrmbuf_init(undefined4 *param_1,int param_2,undefined4 param_3)

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
  *param_1 = param_3;
  param_1[1] = _xdrmbuf_ops;
  param_1[4] = param_2;
  param_1[3] = param_2 + *(int *)(param_2 + 4);
  param_1[2] = 0;
  param_1[5] = (int)*(sword *)(param_2 + 8);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=952 start=0xf0045c60 */

undefined8 _xdrmbuf_destroy(undefined4 param_1,undefined4 param_2)

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
/* GHIDRADEC_FUNCTION index=953 start=0xf0045c6c */

/* WARNING: Removing unreachable block (ram,0xf0045cf0) */
/* WARNING: Removing unreachable block (ram,0xf0045c94) */

undefined8 _xdrmbuf_getlong(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar1 = *(int *)(param_1 + 0x14) + -4;
  *(int *)(param_1 + 0x14) = iVar1;
  if (iVar1 < 0) {
    if (iVar1 != -4) {
      _printf(aXdrMbufLongCro);
    }
    uVar3 = 0;
    if (*(int **)(param_1 + 0x10) == (int *)0x0) goto locret_F0045D14;
    iVar1 = **(int **)(param_1 + 0x10);
    *(int *)(param_1 + 0x10) = iVar1;
    if (iVar1 == 0) goto locret_F0045D14;
    *(int *)(param_1 + 0xc) = iVar1 + *(int *)(iVar1 + 4);
    *(int *)(param_1 + 0x14) = *(sword *)(iVar1 + 8) + -4;
  }
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  if ((((uint)puVar2 & 3) == 0) && (((uint)param_2 & 3) == 0)) {
    *param_2 = *puVar2;
    iVar1 = *(int *)(param_1 + 0xc);
  }
  else {
    _bcopy(puVar2,param_2,4);
    iVar1 = *(int *)(param_1 + 0xc);
  }
  uVar3 = 1;
  *(int *)(param_1 + 0xc) = iVar1 + 4;
locret_F0045D14:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=954 start=0xf0045d1c */

/* WARNING: Removing unreachable block (ram,0xf0045da0) */
/* WARNING: Removing unreachable block (ram,0xf0045d44) */

undefined8 _xdrmbuf_putlong(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar1 = *(int *)(param_1 + 0x14) + -4;
  *(int *)(param_1 + 0x14) = iVar1;
  if (iVar1 < 0) {
    if (iVar1 != -4) {
      _printf(aXdrMbufPutlong);
    }
    uVar3 = 0;
    if (*(int **)(param_1 + 0x10) == (int *)0x0) goto locret_F0045DC4;
    iVar1 = **(int **)(param_1 + 0x10);
    *(int *)(param_1 + 0x10) = iVar1;
    if (iVar1 == 0) goto locret_F0045DC4;
    *(int *)(param_1 + 0xc) = iVar1 + *(int *)(iVar1 + 4);
    *(int *)(param_1 + 0x14) = *(sword *)(iVar1 + 8) + -4;
  }
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  if ((((uint)puVar2 & 3) == 0) && (((uint)param_2 & 3) == 0)) {
    *puVar2 = *param_2;
    iVar1 = *(int *)(param_1 + 0xc);
  }
  else {
    _bcopy(param_2,puVar2,4);
    iVar1 = *(int *)(param_1 + 0xc);
  }
  uVar3 = 1;
  *(int *)(param_1 + 0xc) = iVar1 + 4;
locret_F0045DC4:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=955 start=0xf0045dcc */

/* WARNING: Removing unreachable block (ram,0xf0045e54) */
/* WARNING: Removing unreachable block (ram,0xf0045df0) */

undefined8 _xdrmbuf_getbytes(int param_1,int param_2,int param_3)

{
  int iVar1;
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
  while (iVar1 = *(int *)(param_1 + 0x14) - param_3, *(int *)(param_1 + 0x14) = iVar1, iVar1 < 0) {
    iVar1 = *(int *)(param_1 + 0x14) + param_3;
    *(int *)(param_1 + 0x14) = iVar1;
    if (0 < iVar1) {
      _bcopy(*(undefined4 *)(param_1 + 0xc),param_2);
      param_2 = param_2 + *(int *)(param_1 + 0x14);
      param_3 = param_3 - *(int *)(param_1 + 0x14);
    }
    uVar2 = 0;
    if (*(int **)(param_1 + 0x10) == (int *)0x0) goto locret_F0045E6C;
    iVar1 = **(int **)(param_1 + 0x10);
    *(int *)(param_1 + 0x10) = iVar1;
    if (iVar1 == 0) goto locret_F0045E6C;
    *(int *)(param_1 + 0xc) = iVar1 + *(int *)(iVar1 + 4);
    *(int *)(param_1 + 0x14) = (int)*(sword *)(iVar1 + 8);
  }
  _bcopy(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
  uVar2 = 1;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
locret_F0045E6C:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=956 start=0xf0045e74 */

/* WARNING: Removing unreachable block (ram,0xf0045eec) */
/* WARNING: Removing unreachable block (ram,0xf0045e7c) */

undefined8 _xdrmbuf_getmbuf(int param_1,int *param_2,uint *param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 unaff_l0;
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
  iVar1 = param_1;
  _xdr_u_int(param_1,param_3);
  uVar3 = 0;
  if (iVar1 != 0) {
    piVar2 = *(int **)(param_1 + 0x10);
    iVar1 = (int)*(sword *)((int)piVar2 + 8) - *(int *)(param_1 + 0x14);
    *(int *)((int)piVar2 + 4) = *(int *)((int)piVar2 + 4) + iVar1;
    *(sword *)((int)piVar2 + 8) = *(sword *)((int)piVar2 + 8) - (sword)iVar1;
    *param_2 = (int)piVar2;
    for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      uVar3 = uVar3 + (int)*(sword *)(piVar2 + 2);
    }
    uVar4 = 1;
    if (*param_3 <= uVar3) goto locret_F0045EF8;
    _printf(aXdrmbufGetmbuf);
  }
  uVar4 = 0;
locret_F0045EF8:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=957 start=0xf0045f00 */

/* WARNING: Removing unreachable block (ram,0xf0045f88) */
/* WARNING: Removing unreachable block (ram,0xf0045f24) */

undefined8 _xdrmbuf_putbytes(int param_1,int param_2,int param_3)

{
  int iVar1;
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
  while (iVar1 = *(int *)(param_1 + 0x14) - param_3, *(int *)(param_1 + 0x14) = iVar1, iVar1 < 0) {
    iVar1 = *(int *)(param_1 + 0x14) + param_3;
    *(int *)(param_1 + 0x14) = iVar1;
    if (0 < iVar1) {
      _bcopy(param_2,*(undefined4 *)(param_1 + 0xc));
      param_2 = param_2 + *(int *)(param_1 + 0x14);
      param_3 = param_3 - *(int *)(param_1 + 0x14);
    }
    uVar2 = 0;
    if (*(int **)(param_1 + 0x10) == (int *)0x0) goto locret_F0045FA0;
    iVar1 = **(int **)(param_1 + 0x10);
    *(int *)(param_1 + 0x10) = iVar1;
    if (iVar1 == 0) goto locret_F0045FA0;
    *(int *)(param_1 + 0xc) = iVar1 + *(int *)(iVar1 + 4);
    *(int *)(param_1 + 0x14) = (int)*(sword *)(iVar1 + 8);
  }
  _bcopy(param_2,*(undefined4 *)(param_1 + 0xc),param_3);
  uVar2 = 1;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
locret_F0045FA0:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=958 start=0xf0045fa8 */

/* WARNING: Removing unreachable block (ram,0xf0045ff4) */
/* WARNING: Removing unreachable block (ram,0xf004601c) */
/* WARNING: Removing unreachable block (ram,0xf0045fc0) */

undefined8
_xdrmbuf_putbuf(int param_1,undefined4 param_2,uint param_3,int param_4,undefined4 param_5)

{
  int iVar1;
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
  *(uint *)((int)register0x00000038 + -0xc) = param_3;
  if (((param_3 & 3) == 0) &&
     (iVar1 = param_1, _xdrmbuf_putlong(param_1,(undefined *)((int)register0x00000038 + -0xc)),
     iVar1 != 0)) {
    *(sword *)(*(int *)(param_1 + 0x10) + 8) =
         *(sword *)(*(int *)(param_1 + 0x10) + 8) - (sword)*(undefined4 *)(param_1 + 0x14);
    _mclgetx(param_4,param_5,param_2,param_3,1);
    uVar2 = 1;
    if (param_4 != 0) {
      **(int **)(param_1 + 0x10) = param_4;
      *(undefined4 *)(param_1 + 0x14) = 0;
      goto locret_F0046028;
    }
    _printf(aXdrmbufPutbufM);
  }
  uVar2 = 0;
locret_F0046028:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=959 start=0xf0046030 */

undefined8 _xdrmbuf_getpos(int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(int *)(param_1 + 0xc) -
                          (*(int *)(param_1 + 0x10) + *(int *)(*(int *)(param_1 + 0x10) + 4)));
}
/* GHIDRADEC_FUNCTION index=960 start=0xf0046050 */

undefined8 _xdrmbuf_setpos(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
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
  iVar1 = *(int *)(param_1 + 0x10) + *(int *)(*(int *)(param_1 + 0x10) + 4) + param_2;
  iVar2 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x14);
  if (iVar1 <= iVar2) {
    *(int *)(param_1 + 0xc) = iVar1;
    *(int *)(param_1 + 0x14) = iVar2 - iVar1;
  }
  return CONCAT44(param_2,(uint)(iVar1 <= iVar2));
}
/* GHIDRADEC_FUNCTION index=961 start=0xf0046098 */

undefined8 _xdrmbuf_inline(int param_1,int param_2)

{
  int iVar1;
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
  iVar1 = 0;
  if (param_2 <= *(int *)(param_1 + 0x14)) {
    if ((*(uint *)(param_1 + 0xc) & 3) == 0) {
      iVar1 = *(int *)(param_1 + 0xc);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - param_2;
      *(int *)(param_1 + 0xc) = iVar1 + param_2;
    }
    else {
      iVar1 = 0;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=962 start=0xf00460e0 */

undefined8
_xdrmem_create(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  *param_1 = param_4;
  param_1[1] = unk_F010E150;
  param_1[4] = param_2;
  param_1[3] = param_2;
  param_1[5] = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=963 start=0xf0046324 */

/* WARNING: Removing unreachable block (ram,0xf0046368) */
/* WARNING: Removing unreachable block (ram,0xf0046394) */
/* WARNING: Removing unreachable block (ram,0xf0046358) */

undefined8 _xdr_reference(int *param_1,int *param_2,int param_3,code *param_4)

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
  int *piVar2;
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
  iVar1 = *param_2;
  if (iVar1 == 0) {
    if (*param_1 == 1) {
      iVar1 = param_3;
      _kalloc();
      *param_2 = iVar1;
      _bzero();
    }
    else if (*param_1 == 2) {
      piVar2 = (int *)0x1;
      goto locret_F00463A0;
    }
  }
  piVar2 = param_1;
  (*param_4)(param_1,iVar1,0xffffffff);
  if (*param_1 == 2) {
    _kfree(iVar1,param_3);
    *param_2 = 0;
  }
locret_F00463A0:
  return CONCAT44(param_2,piVar2);
}
/* GHIDRADEC_FUNCTION index=964 start=0xf00463a8 */

/* WARNING: Removing unreachable block (ram,0xf00463b4) */

undefined8 _xdr_bp_machine_name_t(int param_1,undefined4 param_2)

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
  _xdr_string(param_1,param_2,0xff);
  return CONCAT44(param_2,(uint)(param_1 != 0));
}
/* GHIDRADEC_FUNCTION index=965 start=0xf00463cc */

/* WARNING: Removing unreachable block (ram,0xf00463d8) */

undefined8 _xdr_bp_path_t(int param_1,undefined4 param_2)

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
  _xdr_string(param_1,param_2,0x400);
  return CONCAT44(param_2,(uint)(param_1 != 0));
}
/* GHIDRADEC_FUNCTION index=966 start=0xf00463f0 */

/* WARNING: Removing unreachable block (ram,0xf00463fc) */

undefined8 _xdr_bp_fileid_t(int param_1,undefined4 param_2)

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
  _xdr_string(param_1,param_2,0x20);
  return CONCAT44(param_2,(uint)(param_1 != 0));
}
/* GHIDRADEC_FUNCTION index=967 start=0xf0046414 */

/* WARNING: Removing unreachable block (ram,0xf0046444) */
/* WARNING: Removing unreachable block (ram,0xf0046430) */
/* WARNING: Removing unreachable block (ram,0xf0046460) */
/* WARNING: Removing unreachable block (ram,0xf004641c) */

undefined8 _xdr_ip_addr_t(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
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
  iVar1 = param_1;
  _xdr_char(param_1,param_2);
  if (((iVar1 == 0) || (iVar1 = param_1, _xdr_char(param_1,param_2 + 1), iVar1 == 0)) ||
     (iVar1 = param_1, _xdr_char(param_1,param_2 + 2), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    _xdr_char(param_1,param_2 + 3);
    uVar2 = (uint)(param_1 != 0);
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=968 start=0xf0046478 */

/* WARNING: Removing unreachable block (ram,0xf0046490) */

undefined8 _xdr_bp_address(int param_1,int param_2)

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
  _xdr_union(param_1,param_2,param_2 + 4,unk_F010E170,0);
  return CONCAT44(param_2,(uint)(param_1 != 0));
}
/* GHIDRADEC_FUNCTION index=969 start=0xf00464a8 */

/* WARNING: Removing unreachable block (ram,0xf00464b0) */

undefined8 _xdr_bp_whoami_arg(int param_1,undefined4 param_2)

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
  _xdr_bp_address(param_1,param_2);
  return CONCAT44(param_2,(uint)(param_1 != 0));
}
/* GHIDRADEC_FUNCTION index=970 start=0xf00464c8 */

/* WARNING: Removing unreachable block (ram,0xf00464e4) */
/* WARNING: Removing unreachable block (ram,0xf0046500) */
/* WARNING: Removing unreachable block (ram,0xf00464d0) */

undefined8 _xdr_bp_whoami_res(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
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
  iVar1 = param_1;
  _xdr_bp_machine_name_t(param_1,param_2);
  if ((iVar1 == 0) || (iVar1 = param_1, _xdr_bp_machine_name_t(param_1,param_2 + 4), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    _xdr_bp_address(param_1,param_2 + 8);
    uVar2 = (uint)(param_1 != 0);
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=971 start=0xf0046518 */

/* WARNING: Removing unreachable block (ram,0xf004653c) */
/* WARNING: Removing unreachable block (ram,0xf0046520) */

undefined8 _xdr_bp_getfile_arg(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
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
  iVar1 = param_1;
  _xdr_bp_machine_name_t(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    _xdr_bp_fileid_t(param_1,param_2 + 4);
    uVar2 = (uint)(param_1 != 0);
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=972 start=0xf0046554 */

/* WARNING: Removing unreachable block (ram,0xf0046570) */
/* WARNING: Removing unreachable block (ram,0xf004658c) */
/* WARNING: Removing unreachable block (ram,0xf004655c) */

undefined8 _xdr_bp_getfile_res(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
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
  iVar1 = param_1;
  _xdr_bp_machine_name_t(param_1,param_2);
  if ((iVar1 == 0) || (iVar1 = param_1, _xdr_bp_address(param_1,param_2 + 4), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    _xdr_bp_path_t(param_1,param_2 + 0xc);
    uVar2 = (uint)(param_1 != 0);
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=973 start=0xf00465a4 */

/* WARNING: Removing unreachable block (ram,0xf00465d4) */
/* WARNING: Removing unreachable block (ram,0xf00465ac) */

undefined8 _xdr_fhstatus(int param_1,int *param_2)

{
  int iVar1;
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
  iVar1 = param_1;
  _xdr_int(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if (*param_2 == 0) {
    _xdr_fhandle(param_1,param_2 + 1);
    uVar2 = 1;
    if (param_1 == 0) {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=974 start=0xf00471d8 */

/* WARNING: Removing unreachable block (ram,0xf00471ec) */
/* WARNING: Removing unreachable block (ram,0xf00471e0) */

undefined8 _fifosp(int param_1,undefined4 param_2)

{
  int iVar1;
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
  iVar1 = 0x8c;
  _kalloc();
  _bzero();
  *(undefined **)(iVar1 + 0x20) = _fifo_vnodeops;
  (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
            (param_1,(undefined *)((int)register0x00000038 + -0x48),
             *(undefined4 *)(_active_u + 0x1c));
  *(undefined4 *)(iVar1 + 0x4c) = *(undefined4 *)((int)register0x00000038 + -0x28);
  *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)((int)register0x00000038 + -0x24);
  *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)((int)register0x00000038 + -0x20);
  *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)((int)register0x00000038 + -0x1c);
  *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)((int)register0x00000038 + -0x18);
  *(undefined4 *)(iVar1 + 0x60) = *(undefined4 *)((int)register0x00000038 + -0x14);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=975 start=0xf00472e4 */

/* WARNING: Removing unreachable block (ram,0xf00472f4) */

undefined8 _bdevvp(sword param_1,undefined4 param_2)

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
  uVar1 = 0;
  _specvp(0,(int)param_1,3);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=976 start=0xf0047304 */

undefined8 _set_blocksize(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
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
  uVar2 = (param_2 & 0xffff) >> 8;
  if ((int)uVar2 < _nblkdev) {
    if (*(code **)(DAT_f011c7bc + uVar2 * 0x18) == (code *)0x0) {
      *(undefined4 *)(param_1 + 0x48) = 0;
    }
    else {
      iVar1 = (int)(sword)param_2;
      (**(code **)(DAT_f011c7bc + uVar2 * 0x18))();
      if (iVar1 == -1) {
        *(undefined4 *)(param_1 + 0x48) = 0;
      }
      else {
        *(int *)(param_1 + 0x48) = iVar1;
        if ((*(int *)(param_1 + 0x3c) != 0) &&
           (iVar3 = *(int *)(*(int *)(param_1 + 0x3c) + 0x30), *(int *)(iVar3 + 0x48) == 0)) {
          *(int *)(iVar3 + 0x48) = iVar1;
        }
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  return CONCAT44((int)(sword)param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=977 start=0xf0047398 */

/* WARNING: Removing unreachable block (ram,0xf00474ec) */
/* WARNING: Removing unreachable block (ram,0xf00473dc) */
/* WARNING: Removing unreachable block (ram,0xf00473ec) */
/* WARNING: Removing unreachable block (ram,0xf00473f8) */
/* WARNING: Removing unreachable block (ram,0xf00474bc) */
/* WARNING: Removing unreachable block (ram,0xf00474fc) */
/* WARNING: Removing unreachable block (ram,0xf00473ac) */

undefined8 _specvp(int param_1,undefined4 param_2,undefined4 param_3)

{
  sword sVar3;
  int iVar1;
  int iVar2;
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
  sVar3 = (sword)param_2;
  iVar1 = (int)sVar3;
  sub_F00478C4(iVar1,param_1,param_3);
  if (iVar1 != 0) goto loc_F00474F8;
  if ((param_1 == 0) || (*(int *)(param_1 + 0x28) != 8)) {
    iVar1 = 0x68;
    _kalloc();
    _bzero();
    *(undefined **)(iVar1 + 0x20) = _spec_vnodeops;
    if (param_1 == 0) goto loc_F0047470;
    iVar2 = param_1;
    (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
              (param_1,(undefined *)((int)register0x00000038 + -0x48),
               *(undefined4 *)(_active_u + 0x1c));
    if (iVar2 == 0) {
      *(undefined4 *)(iVar1 + 0x4c) = *(undefined4 *)((int)register0x00000038 + -0x28);
      *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)((int)register0x00000038 + -0x24);
      *(undefined4 *)(iVar1 + 0x54) = *(undefined4 *)((int)register0x00000038 + -0x20);
      *(undefined4 *)(iVar1 + 0x58) = *(undefined4 *)((int)register0x00000038 + -0x1c);
      *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)((int)register0x00000038 + -0x18);
      *(undefined4 *)(iVar1 + 0x60) = *(undefined4 *)((int)register0x00000038 + -0x14);
      goto loc_F0047470;
    }
    *(int *)(iVar1 + 0x38) = param_1;
  }
  else {
    iVar1 = param_1;
    _fifosp();
loc_F0047470:
    *(int *)(iVar1 + 0x38) = param_1;
  }
  *(sword *)(iVar1 + 0x42) = sVar3;
  *(sword *)(iVar1 + 0x30) = sVar3;
  *(undefined2 *)(iVar1 + 10) = 1;
  *(int *)(iVar1 + 0x34) = iVar1;
  if (param_1 == 0) {
    *(undefined4 *)(iVar1 + 0x2c) = 3;
    *(undefined4 *)(iVar1 + 0x28) = 0;
    *(int *)(iVar1 + 0x3c) = iVar1 + 4;
  }
  else {
    *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
    if (*(int *)(param_1 + 0x28) == 3) {
      iVar2 = (int)sVar3;
      _bdevvp();
      *(int *)(iVar1 + 0x3c) = iVar2;
      *(undefined4 *)(iVar1 + 0x48) = *(undefined4 *)(*(int *)(iVar2 + 0x30) + 0x48);
    }
  }
  sub_F00475C4(iVar1);
loc_F00474F8:
  _set_blocksize(iVar1,(int)sVar3);
  return CONCAT44(param_2,iVar1 + 4);
}
/* GHIDRADEC_FUNCTION index=978 start=0xf004750c */

/* WARNING: Removing unreachable block (ram,0xf004758c) */
/* WARNING: Removing unreachable block (ram,0xf0047544) */
/* WARNING: Removing unreachable block (ram,0xf0047538) */
/* WARNING: Removing unreachable block (ram,0xf0047564) */
/* WARNING: Removing unreachable block (ram,0xf00475ac) */
/* WARNING: Removing unreachable block (ram,0xf0047524) */

undefined8 _makespecvp(sword param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
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
  while( true ) {
    iVar2 = (int)param_1;
    iVar1 = iVar2;
    sub_F00478C4(iVar2,0,param_2);
    if (iVar1 == 0) break;
    if ((*(word *)(iVar1 + 0x40) & 1) == 0) goto locret_F00475BC;
    *(word *)(iVar1 + 0x40) = *(word *)(iVar1 + 0x40) | 0x10;
    _sleep(iVar1,10);
  }
  iVar1 = 0x68;
  _kalloc();
  _bzero();
  *(undefined **)(iVar1 + 0x20) = _spec_vnodeops;
  *(int *)(iVar1 + 0x2c) = param_2;
  if (param_2 == 3) {
    _bdevvp();
    *(int *)(iVar1 + 0x3c) = iVar2;
  }
  *(undefined4 *)(iVar1 + 0x38) = 0;
  *(sword *)(iVar1 + 0x42) = param_1;
  *(sword *)(iVar1 + 0x30) = param_1;
  *(undefined2 *)(iVar1 + 10) = 1;
  *(int *)(iVar1 + 0x34) = iVar1;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  sub_F00475C4(iVar1);
locret_F00475BC:
  return CONCAT44(param_2,iVar1 + 4);
}
/* GHIDRADEC_FUNCTION index=979 start=0xf0047614 */

undefined8 _sunsave(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 *puVar3;
  undefined4 *puVar4;
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
  puVar3 = *(undefined4 **)
            (_stable +
            ((uint)(*(word *)(param_1 + 0x42) >> 8) + (*(word *)(param_1 + 0x42) & 0xff) & 0xf) * 4)
  ;
  if (puVar3 != (undefined4 *)0x0) {
    iVar1 = (int)puVar3 - param_1;
    puVar2 = (undefined4 *)0x0;
    do {
      if (iVar1 == 0) {
        if (puVar2 == (undefined4 *)0x0) {
          *(undefined4 *)
           (_stable +
           ((uint)(*(word *)((int)puVar3 + 0x42) >> 8) + (*(word *)((int)puVar3 + 0x42) & 0xff) &
           0xf) * 4) = *puVar3;
        }
        else {
          *puVar2 = *puVar3;
        }
        break;
      }
      puVar4 = (undefined4 *)*puVar3;
      iVar1 = (int)puVar4 - param_1;
      puVar2 = puVar3;
      puVar3 = puVar4;
    } while (puVar4 != (undefined4 *)0x0);
  }
  return CONCAT44(puVar3,param_1);
}
/* GHIDRADEC_FUNCTION index=980 start=0xf00476a8 */

undefined8 _stillopen(uint param_1,int param_2)

{
  sword sVar1;
  undefined4 *puVar2;
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
  int iVar3;
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
  puVar2 = *(undefined4 **)(_stable + (((param_1 & 0xffff) >> 8) + (param_1 & 0xff) & 0xf) * 4);
  iVar3 = 0;
  if (puVar2 != (undefined4 *)0x0) {
    sVar1 = *(sword *)((int)puVar2 + 0x42);
    while( true ) {
      if (sVar1 == (sword)param_1) {
        if (puVar2[0xb] == param_2) {
          iVar3 = iVar3 + puVar2[0x19];
          puVar2 = (undefined4 *)*puVar2;
        }
        else {
          puVar2 = (undefined4 *)*puVar2;
        }
      }
      else {
        puVar2 = (undefined4 *)*puVar2;
      }
      if (puVar2 == (undefined4 *)0x0) break;
      sVar1 = *(sword *)((int)puVar2 + 0x42);
    }
  }
  return CONCAT44(param_2,(uint)(iVar3 != 0));
}
/* GHIDRADEC_FUNCTION index=981 start=0xf0047728 */

undefined8 _isclosing(uint param_1,int param_2)

{
  sword sVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  puVar2 = *(undefined4 **)(_stable + (((param_1 & 0xffff) >> 8) + (param_1 & 0xff) & 0xf) * 4);
  if (puVar2 != (undefined4 *)0x0) {
    sVar1 = *(sword *)((int)puVar2 + 0x42);
    while( true ) {
      if (sVar1 == (sword)param_1) {
        if (puVar2[0xb] == param_2) {
          if ((*(word *)(puVar2 + 0x10) & 8) != 0) {
            uVar3 = 1;
            goto locret_F00477A4;
          }
          puVar2 = (undefined4 *)*puVar2;
        }
        else {
          puVar2 = (undefined4 *)*puVar2;
        }
      }
      else {
        puVar2 = (undefined4 *)*puVar2;
      }
      if (puVar2 == (undefined4 *)0x0) break;
      sVar1 = *(sword *)((int)puVar2 + 0x42);
    }
  }
  uVar3 = 0;
locret_F00477A4:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=982 start=0xf00477ac */

undefined8 _other_specvp(undefined4 *param_1)

{
  word wVar1;
  word wVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar3;
  undefined4 unaff_i1;
  undefined4 *puVar4;
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
  wVar2 = *(word *)(param_1[0xc] + 0x42);
  puVar4 = *(undefined4 **)(_stable + ((uint)(wVar2 >> 8) + (wVar2 & 0xff) & 0xf) * 4);
  if (puVar4 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    wVar1 = *(word *)((int)puVar4 + 0x42);
    while( true ) {
      if (wVar1 == wVar2) {
        puVar3 = puVar4 + 1;
        if (puVar3 == param_1) {
          puVar4 = (undefined4 *)*puVar4;
        }
        else {
          if (puVar4[0xb] == param_1[10]) goto locret_F0047838;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        puVar4 = (undefined4 *)*puVar4;
      }
      if (puVar4 == (undefined4 *)0x0) break;
      wVar1 = *(word *)((int)puVar4 + 0x42);
    }
    puVar3 = (undefined4 *)0x0;
  }
locret_F0047838:
  return CONCAT44(puVar4,puVar3);
}
/* GHIDRADEC_FUNCTION index=983 start=0xf0047840 */

undefined8 _slookup(int param_1,uint param_2)

{
  sword sVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar3;
  undefined4 unaff_i1;
  uint uVar4;
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
  uVar4 = param_2 & 0xff;
  puVar2 = *(undefined4 **)(_stable + (((param_2 & 0xffff) >> 8) + uVar4 & 0xf) * 4);
  if (puVar2 != (undefined4 *)0x0) {
    uVar4 = (uint)(sword)param_2;
    sVar1 = *(sword *)((int)puVar2 + 0x42);
    while( true ) {
      if ((int)sVar1 == uVar4) {
        puVar3 = puVar2 + 1;
        if (puVar2[0xb] == param_1) {
          *(sword *)((int)puVar2 + 10) = *(sword *)((int)puVar2 + 10) + 1;
          goto locret_F00478BC;
        }
        puVar2 = (undefined4 *)*puVar2;
      }
      else {
        puVar2 = (undefined4 *)*puVar2;
      }
      if (puVar2 == (undefined4 *)0x0) break;
      sVar1 = *(sword *)((int)puVar2 + 0x42);
    }
  }
  puVar3 = (undefined4 *)0x0;
locret_F00478BC:
  return CONCAT44(uVar4,puVar3);
}
/* GHIDRADEC_FUNCTION index=984 start=0xf00479b8 */

/* WARNING: Removing unreachable block (ram,0xf00479bc) */

undefined8 _smark(int param_1,uint param_2)

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
  _microtime((undefined *)((int)register0x00000038 + -0x10));
  *(word *)(param_1 + 0x40) = *(word *)(param_1 + 0x40) | (word)param_2;
  if ((param_2 & 4) != 0) {
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)((int)register0x00000038 + -0x10);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  if ((param_2 & 2) != 0) {
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)((int)register0x00000038 + -0x10);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  if ((param_2 & 0x40) != 0) {
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)((int)register0x00000038 + -0x10);
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=985 start=0xf0047a20 */

/* WARNING: Removing unreachable block (ram,0xf0047a28) */

undefined8 _spec_badop(undefined4 param_1,undefined4 param_2)

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
  _panic(aSpecBadop);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=986 start=0xf00483b8 */

/* WARNING: Removing unreachable block (ram,0xf0048454) */

undefined8 _spec_setattr(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  char cVar4;
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
  iVar3 = *(int *)(param_1 + 0x30);
  iVar2 = *(int *)(iVar3 + 0x38);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    *(undefined4 *)(param_2 + 0x18) = 0xffffffff;
    (**(code **)(*(int *)(iVar2 + 0x1c) + 0x18))(iVar2,param_2,param_3);
  }
  if (iVar2 == 0) {
    cVar4 = *(int *)(param_2 + 0x28) != -1;
    if ((bool)cVar4) {
      *(int *)(iVar3 + 0x54) = *(int *)(param_2 + 0x28);
      *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(param_2 + 0x2c);
      iVar1 = *(int *)(param_2 + 0x20);
    }
    else {
      iVar1 = *(int *)(param_2 + 0x20);
    }
    if (iVar1 != -1) {
      *(int *)(iVar3 + 0x4c) = iVar1;
      cVar4 = cVar4 + '\x01';
      *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(param_2 + 0x24);
    }
    if (cVar4 != '\0') {
      _getthetime((undefined *)((int)register0x00000038 + -0x10));
      *(undefined4 *)(iVar3 + 0x5c) = *(undefined4 *)((int)register0x00000038 + -0x10);
      *(undefined4 *)(iVar3 + 0x60) = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=987 start=0xf0048474 */

undefined8 _spec_access(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
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
  iVar1 = *(int *)(*(int *)(param_1 + 0x30) + 0x38);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    (**(code **)(*(int *)(iVar1 + 0x1c) + 0x1c))(iVar1,param_2,param_3);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=988 start=0xf00484b0 */

undefined8 _spec_link(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
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
  iVar1 = *(int *)(*(int *)(param_1 + 0x30) + 0x38);
  if (iVar1 == 0) {
    iVar1 = 2;
  }
  else {
    (**(code **)(*(int *)(param_2 + 0x1c) + 0x2c))(iVar1,param_2,param_3,param_4);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=989 start=0xf0048504 */

/* WARNING: Removing unreachable block (ram,0xf0048630) */
/* WARNING: Removing unreachable block (ram,0xf004856c) */
/* WARNING: Removing unreachable block (ram,0xf0048574) */
/* WARNING: Removing unreachable block (ram,0xf004863c) */
/* WARNING: Removing unreachable block (ram,0xf004853c) */

sqword _spec_fsync(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
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
  iVar6 = *(int *)(param_1 + 0x30);
  if ((*(word *)(iVar6 + 0x40) & 0x46) == 0) {
    if (*(int *)(param_1 + 0x28) != 3) goto locret_F0048658;
    iVar7 = *(int *)(iVar6 + 0x38);
  }
  else {
    iVar7 = *(int *)(iVar6 + 0x38);
  }
  if (iVar7 == 0) goto locret_F0048658;
  iVar1 = 0x40;
  _kalloc();
  iVar2 = *(int *)(iVar6 + 0x38);
  (**(code **)(*(int *)(iVar2 + 0x1c) + 0x14))(iVar2,iVar1,param_2);
  if (iVar2 == 0) {
    iVar2 = 0x40;
    _kalloc();
    _vattr_null();
    iVar5 = *(int *)(iVar1 + 0x20);
    iVar3 = *(int *)(iVar6 + 0x4c);
    if (iVar3 < iVar5) {
      *(int *)(iVar2 + 0x20) = iVar5;
loc_F00485B4:
      uVar4 = *(undefined4 *)(iVar1 + 0x24);
    }
    else {
      if (iVar5 == iVar3) {
        if (*(int *)(iVar6 + 0x50) < *(int *)(iVar1 + 0x24)) {
          *(int *)(iVar2 + 0x20) = iVar5;
          goto loc_F00485B4;
        }
        *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar6 + 0x4c);
      }
      else {
        *(int *)(iVar2 + 0x20) = iVar3;
      }
      uVar4 = *(undefined4 *)(iVar6 + 0x50);
    }
    *(undefined4 *)(iVar2 + 0x24) = uVar4;
    iVar5 = *(int *)(iVar1 + 0x28);
    iVar3 = *(int *)(iVar6 + 0x54);
    if (iVar3 < iVar5) {
      *(int *)(iVar2 + 0x28) = iVar5;
loc_F0048600:
      uVar4 = *(undefined4 *)(iVar1 + 0x2c);
    }
    else {
      if (iVar5 == iVar3) {
        if (*(int *)(iVar6 + 0x58) < *(int *)(iVar1 + 0x2c)) {
          *(int *)(iVar2 + 0x28) = iVar5;
          goto loc_F0048600;
        }
        *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar6 + 0x54);
      }
      else {
        *(int *)(iVar2 + 0x28) = iVar3;
      }
      uVar4 = *(undefined4 *)(iVar6 + 0x58);
    }
    *(undefined4 *)(iVar2 + 0x2c) = uVar4;
    (**(code **)(*(int *)(iVar7 + 0x1c) + 0x18))(iVar7,iVar2,param_2);
    _kfree(iVar2,0x40);
  }
  _kfree(iVar1,0x40);
  (**(code **)(*(int *)(iVar7 + 0x1c) + 0x48))(iVar7,param_2);
locret_F0048658:
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=990 start=0xf00486b4 */

undefined8 _spec_lockctl(undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,0x16);
}
/* GHIDRADEC_FUNCTION index=991 start=0xf00486c0 */

undefined8 _spec_fid(int param_1,undefined4 param_2)

{
  int iVar1;
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
  iVar1 = *(int *)(*(int *)(param_1 + 0x30) + 0x38);
  if (iVar1 == 0) {
    iVar1 = 0x16;
  }
  else {
    (**(code **)(*(int *)(iVar1 + 0x1c) + 100))(iVar1,param_2);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=992 start=0xf0048710 */

sqword _spec_realvp(int param_1,int *param_2)

{
  int iVar1;
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
  bool bVar2;
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
  bVar2 = param_1 == 0;
  if ((!bVar2) &&
     ((*(undefined **)(param_1 + 0x1c) == _spec_vnodeops ||
      (bVar2 = param_1 == 0, *(undefined **)(param_1 + 0x1c) == _fifo_vnodeops)))) {
    param_1 = *(int *)(*(int *)(param_1 + 0x30) + 0x38);
    bVar2 = param_1 == 0;
  }
  if ((!bVar2) &&
     (iVar1 = param_1,
     (**(code **)(*(int *)(param_1 + 0x1c) + 0x70))
               (param_1,(undefined *)((int)register0x00000038 + -0xc)), iVar1 == 0)) {
    param_1 = *(int *)((int)register0x00000038 + -0xc);
  }
  *param_2 = param_1;
  return ZEXT48(param_2) << 0x20;
}
/* GHIDRADEC_FUNCTION index=993 start=0xf00487c0 */

/* WARNING: Removing unreachable block (ram,0xf0048928) */
/* WARNING: Removing unreachable block (ram,0xf00488ec) */
/* WARNING: Removing unreachable block (ram,0xf00488a8) */
/* WARNING: Removing unreachable block (ram,0xf0048860) */
/* WARNING: Removing unreachable block (ram,0xf0048800) */
/* WARNING: Removing unreachable block (ram,0xf0048858) */
/* WARNING: Removing unreachable block (ram,0xf0048898) */
/* WARNING: Removing unreachable block (ram,0xf00488c4) */
/* WARNING: Removing unreachable block (ram,0xf0048918) */
/* WARNING: Removing unreachable block (ram,0xf004893c) */
/* WARNING: Removing unreachable block (ram,0xf00487f4) */

undefined8 _alloc(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  int iVar6;
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
  iVar6 = *(int *)(param_1 + 0x50);
  if ((*(uint *)(iVar6 + 0x30) < param_3) || ((param_3 & ~*(uint *)(iVar6 + 0x4c)) != 0)) {
    _printf(aDev0xXBsizeDSi,(int)*(sword *)(param_1 + 0x46),*(uint *)(iVar6 + 0x30),param_3,
            iVar6 + 0xd4);
    _panic(aAllocBadSize);
  }
  if ((param_3 != *(uint *)(iVar6 + 0x30)) || (*(int *)(iVar6 + 0xc4) != 0)) {
    if (*(sword *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
      iVar1 = *(int *)(iVar6 + 0x24);
    }
    else {
      iVar5 = *(int *)(iVar6 + 0xc4);
      iVar1 = *(int *)(iVar6 + 0x28);
      uVar4 = *(undefined4 *)(iVar6 + 0x60);
      iVar3 = *(int *)(iVar6 + 0xcc);
      .umul(iVar1,*(undefined4 *)(iVar6 + 0x3c));
      .div();
      if (((iVar5 << ((byte)uVar4 & 0x1f)) + iVar3) - iVar1 < 1) goto loc_F004893C;
      iVar1 = *(int *)(iVar6 + 0x24);
    }
    if (iVar1 <= param_2) {
      param_2 = 0;
    }
    if (param_2 == 0) {
      iVar1 = *(int *)(param_1 + 0x48);
      .udiv(iVar1,*(undefined4 *)(iVar6 + 0xb8));
    }
    else {
      iVar1 = param_2;
      .div(param_2,*(undefined4 *)(iVar6 + 0xbc));
    }
    iVar3 = param_1;
    _hashalloc(param_1,iVar1,param_2,param_3,_alloccg);
    if (0 < iVar3) {
      iVar1 = param_1 + 0xc;
      (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(iVar1);
      uVar2 = param_3;
      .div(param_3,iVar1);
      *(uint *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + uVar2;
      *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
      iVar1 = *(int *)(param_1 + 0x40);
      _getblk(iVar1,iVar3 << ((byte)*(undefined4 *)(iVar6 + 100) & 0x1f),param_3);
      _bzero(*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(iVar1 + 0x14));
      *(undefined4 *)(iVar1 + 0x28) = 0;
      goto locret_F0048948;
    }
  }
loc_F004893C:
  _fsfull(iVar6,1);
  iVar1 = 0;
locret_F0048948:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=994 start=0xf0048950 */

/* WARNING: Removing unreachable block (ram,0xf00489b4) */
/* WARNING: Removing unreachable block (ram,0xf00489ec) */
/* WARNING: Removing unreachable block (ram,0xf0048998) */

undefined8 _fsfull(int param_1,uint param_2)

{
  byte bVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  undefined *puVar3;
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
  if ((param_2 & 1) == 0) {
    puVar3 = (undefined *)0x0;
    if ((param_2 & 2) == 0) {
      puVar2 = (undefined *)0x0;
      _panic(&aFsfull);
    }
    else {
      puVar2 = aOutOfInodes;
      puVar3 = aCreateSymlinkF;
    }
  }
  else {
    puVar2 = aFileSystemFull;
    puVar3 = aWriteFailedFil;
  }
  if (((int)*(char *)(param_1 + 0xd3) & param_2) == 0) {
    _fserr(param_1,puVar2);
    bVar1 = *(byte *)(param_1 + 0xd3);
  }
  else {
    bVar1 = *(byte *)(param_1 + 0xd3);
  }
  *(byte *)(param_1 + 0xd3) = bVar1 | (byte)param_2;
  if ((*(byte *)(_active_u + 0x25c) & 8) == 0) {
    _uprintf(aSS_1,param_1 + 0xd4,puVar3);
  }
  if (*(int *)(dword_F0133DDC + 0x3c) == 0) {
    *(int *)(dword_F0133DDC + 0x3c) = param_1;
    *(byte *)(dword_F0133DDC + 0x40) = (byte)param_2;
  }
  *(undefined *)(dword_F0133DDC + 0x38) = 0x1c;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=995 start=0xf0048a28 */

/* WARNING: Removing unreachable block (ram,0xf0048aa8) */
/* WARNING: Removing unreachable block (ram,0xf0048a5c) */
/* WARNING: Removing unreachable block (ram,0xf0048ac8) */

undefined8 _fssleep(int param_1,uint param_2)

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
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) == 0) {
      _panic(&aFssleep);
    }
    else if (*(int *)(param_1 + 200) <= *(int *)(param_1 + 0x90)) {
      do {
        _sleep(param_1 + 200,0x1a);
      } while (*(int *)(param_1 + 200) <= *(int *)(param_1 + 0x90));
    }
  }
  else if ((*(int *)(param_1 + 0xc4) << ((byte)*(undefined4 *)(param_1 + 0x60) & 0x1f)) +
           *(int *)(param_1 + 0xcc) <= *(int *)(param_1 + 0x88)) {
    do {
      _sleep(param_1 + 0xcc,0x1a);
    } while ((*(int *)(param_1 + 0xc4) << ((byte)*(undefined4 *)(param_1 + 0x60) & 0x1f)) +
             *(int *)(param_1 + 0xcc) <= *(int *)(param_1 + 0x88));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=996 start=0xf0048ad8 */

/* WARNING: Removing unreachable block (ram,0xf0048b6c) */

undefined8 _fspause(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  code *pcVar3;
  undefined4 unaff_l0;
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
  iVar2 = *(int *)(dword_F0133DDC + 0x3c);
  cVar1 = *(char *)(dword_F0133DDC + 0x40);
  *(undefined4 *)(dword_F0133DDC + 0x3c) = 0;
  *(undefined *)(dword_F0133DDC + 0x40) = 0;
  if ((iVar2 != 0) && (cVar1 != '\0')) {
    if (*(char *)(dword_F0133DDC + 0x38) != '\x1c') {
      uVar4 = 0;
      goto locret_F0048B94;
    }
    if (((*(byte *)(_active_u + 0x25c) & 8) != 0) && (param_1 == 0)) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0;
      pcVar3 = _fssleep;
      _rpsleep();
      uVar4 = 1;
      if (pcVar3 == (code *)0x0) {
        uVar4 = 0;
        *(undefined *)(dword_F0133DDC + 0x38) = 0x1c;
      }
      goto locret_F0048B94;
    }
  }
  uVar4 = 0;
locret_F0048B94:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=997 start=0xf0048b9c */

/* WARNING: Removing unreachable block (ram,0xf0048f0c) */
/* WARNING: Removing unreachable block (ram,0xf0048ec8) */
/* WARNING: Removing unreachable block (ram,0xf0048e88) */
/* WARNING: Removing unreachable block (ram,0xf0048e60) */
/* WARNING: Removing unreachable block (ram,0xf0048e2c) */
/* WARNING: Removing unreachable block (ram,0xf0048d9c) */
/* WARNING: Removing unreachable block (ram,0xf0048d70) */
/* WARNING: Removing unreachable block (ram,0xf0048dbc) */
/* WARNING: Removing unreachable block (ram,0xf0048d18) */
/* WARNING: Removing unreachable block (ram,0xf0048f30) */
/* WARNING: Removing unreachable block (ram,0xf0048cb0) */
/* WARNING: Removing unreachable block (ram,0xf0048c88) */
/* WARNING: Removing unreachable block (ram,0xf0048c48) */
/* WARNING: Removing unreachable block (ram,0xf0048c40) */
/* WARNING: Removing unreachable block (ram,0xf0048c7c) */
/* WARNING: Removing unreachable block (ram,0xf0048c94) */
/* WARNING: Removing unreachable block (ram,0xf0048cd0) */
/* WARNING: Removing unreachable block (ram,0xf0048cec) */
/* WARNING: Removing unreachable block (ram,0xf0048db4) */
/* WARNING: Removing unreachable block (ram,0xf0048de0) */
/* WARNING: Removing unreachable block (ram,0xf0048d78) */
/* WARNING: Removing unreachable block (ram,0xf0048e10) */
/* WARNING: Removing unreachable block (ram,0xf0048e48) */
/* WARNING: Removing unreachable block (ram,0xf0048e74) */
/* WARNING: Removing unreachable block (ram,0xf0048eb8) */
/* WARNING: Removing unreachable block (ram,0xf0048eec) */
/* WARNING: Removing unreachable block (ram,0xf0048f44) */
/* WARNING: Removing unreachable block (ram,0xf0048bf8) */
/* WARNING: Removing unreachable block (ram,0xf0048c04) */

undefined8 _realloccg(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar8;
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
  iVar7 = *(int *)(param_1 + 0x50);
  if ((((*(uint *)(iVar7 + 0x30) < param_4) || ((param_4 & ~*(uint *)(iVar7 + 0x4c)) != 0)) ||
      (*(uint *)(iVar7 + 0x30) < param_5)) || ((param_5 & ~*(uint *)(iVar7 + 0x4c)) != 0)) {
    _printf(aDev0xXBsizeDOs,(int)*(sword *)(param_1 + 0x46),*(undefined4 *)(iVar7 + 0x30),param_4,
            param_5,iVar7 + 0xd4);
    _panic(aRealloccgBadSi);
  }
  if (*(sword *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
loc_F0048C60:
    if (param_2 == 0) {
      _printf(aDev0xXBsizeDBp,(int)*(sword *)(param_1 + 0x46),*(undefined4 *)(iVar7 + 0x30),0,
              iVar7 + 0xd4);
      _panic(aRealloccgBadBp);
      uVar5 = *(undefined4 *)(iVar7 + 0xbc);
    }
    else {
      uVar5 = *(undefined4 *)(iVar7 + 0xbc);
    }
    iVar1 = param_2;
    .div(param_2,uVar5);
    iVar4 = param_1;
    _fragextend(param_1,iVar1,param_2,param_4,param_5);
    if (iVar4 != 0) {
      uVar5 = *(undefined4 *)(iVar7 + 100);
      while( true ) {
        puVar3 = *(uint **)(param_1 + 0x40);
        _bread(puVar3,iVar4 << ((byte)uVar5 & 0x1f),param_4);
        if ((*puVar3 & 4) != 0) break;
        puVar2 = puVar3;
        _brealloc(puVar3,param_5);
        if (puVar2 != (uint *)0x0) {
          iVar1 = param_5 - param_4;
          *puVar3 = *puVar3 | 2;
          _bzero(puVar3[8] + param_4,iVar1);
          iVar7 = param_1 + 0xc;
          (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(iVar7);
          goto loc_F0048F0C;
        }
        uVar5 = *(undefined4 *)(iVar7 + 100);
      }
      _brelse(puVar3);
      puVar3 = (uint *)0x0;
      goto locret_F0048F50;
    }
    if (*(int *)(iVar7 + 0x24) <= param_3) {
      param_3 = 0;
    }
    if (*(int *)(iVar7 + 0x80) == 0) {
      iVar4 = *(int *)(iVar7 + 0x28);
      .umul(iVar4,*(int *)(iVar7 + 0x3c) + -2);
      .div();
      uVar8 = *(uint *)(iVar7 + 0x30);
      if (iVar4 <= *(int *)(iVar7 + 0xcc)) {
        _log(5,aSOptimizationC_0,iVar7 + 0xd4);
        *(undefined4 *)(iVar7 + 0x80) = 1;
      }
    }
    else {
      uVar8 = param_5;
      if (*(int *)(iVar7 + 0x80) == 1) {
        if (4 < *(int *)(iVar7 + 0x3c)) {
          iVar4 = *(int *)(iVar7 + 0x28);
          .umul();
          .div();
          if (*(int *)(iVar7 + 0xcc) <= iVar4) {
            _log(5,aSOptimizationC,iVar7 + 0xd4);
            *(undefined4 *)(iVar7 + 0x80) = 0;
          }
        }
      }
      else {
        *(undefined4 *)(iVar7 + 0x80) = 1;
      }
    }
    iVar4 = param_1;
    _hashalloc(param_1,iVar1,param_3,uVar8,_alloccg);
    if (0 < iVar4) {
      puVar2 = *(uint **)(param_1 + 0x40);
      _bread(puVar2,param_2 << ((byte)*(undefined4 *)(iVar7 + 100) & 0x1f),param_4);
      if ((*puVar2 & 4) == 0) {
        puVar3 = *(uint **)(param_1 + 0x40);
        _getblk(puVar3,iVar4 << ((byte)*(undefined4 *)(iVar7 + 100) & 0x1f),param_5);
        _bcopy(puVar2[8],puVar3[8],param_4);
        iVar1 = param_5 - param_4;
        _bzero(puVar3[8] + param_4,iVar1);
        if ((*puVar2 & 0x200) != 0) {
          *puVar2 = *puVar2 & 0xfffffdff;
          *(int *)(_active_u + 0x19c) = *(int *)(_active_u + 0x19c) + -1;
        }
        _brelse(puVar2);
        _free_block(param_1,param_2,param_4);
        if ((int)param_5 < (int)uVar8) {
          _free_block(param_1,iVar4 + ((int)param_5 >> ((byte)*(undefined4 *)(iVar7 + 0x54) & 0x1f))
                      ,uVar8 - param_5);
          iVar4 = *(int *)(param_1 + 0x28);
        }
        else {
          iVar4 = *(int *)(param_1 + 0x28);
        }
        iVar7 = param_1 + 0xc;
        (**(code **)(iVar4 + 0x80))(iVar7);
loc_F0048F0C:
        .div(iVar1,iVar7);
        *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + iVar1;
        *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
      }
      else {
        _brelse(puVar2);
        puVar3 = (uint *)0x0;
      }
      goto locret_F0048F50;
    }
  }
  else {
    iVar6 = *(int *)(iVar7 + 0xc4);
    iVar1 = *(int *)(iVar7 + 0x28);
    uVar5 = *(undefined4 *)(iVar7 + 0x60);
    iVar4 = *(int *)(iVar7 + 0xcc);
    .umul(iVar1,*(undefined4 *)(iVar7 + 0x3c));
    .div();
    if (0 < ((iVar6 << ((byte)uVar5 & 0x1f)) + iVar4) - iVar1) goto loc_F0048C60;
  }
  _fsfull(iVar7,1);
  puVar3 = (uint *)0x0;
locret_F0048F50:
  return CONCAT44(param_2,puVar3);
}
/* GHIDRADEC_FUNCTION index=998 start=0xf0048f58 */

/* WARNING: Removing unreachable block (ram,0xf0049068) */
/* WARNING: Removing unreachable block (ram,0xf004903c) */
/* WARNING: Removing unreachable block (ram,0xf0048ff8) */
/* WARNING: Removing unreachable block (ram,0xf0048fc0) */
/* WARNING: Removing unreachable block (ram,0xf0048fdc) */
/* WARNING: Removing unreachable block (ram,0xf0049014) */
/* WARNING: Removing unreachable block (ram,0xf0049048) */
/* WARNING: Removing unreachable block (ram,0xf004907c) */
/* WARNING: Removing unreachable block (ram,0xf0048fa8) */

undefined8 _ialloc(uint param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar6;
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
  iVar4 = *(int *)(param_1 + 0x50);
  if (((*(sword *)(*(int *)(_active_u + 0x1c) + 2) == 0) ||
      (*(int *)(iVar4 + 0x94) < *(int *)(iVar4 + 200))) && (*(int *)(iVar4 + 200) != 0)) {
    uVar5 = *(undefined4 *)(iVar4 + 0xb8);
    uVar1 = *(uint *)(iVar4 + 0x2c);
    .umul(uVar1,uVar5);
    uVar6 = param_2;
    if (uVar1 <= param_2) {
      uVar6 = 0;
    }
    uVar1 = uVar6;
    .udiv(uVar6,uVar5);
    param_2 = param_1;
    _hashalloc(param_1,uVar1,uVar6,param_3,_ialloccg);
    if (param_2 != 0) {
      iVar2 = (int)*(sword *)(param_1 + 0x46);
      _iget(iVar2,*(undefined4 *)(param_1 + 0x50),param_2);
      if (iVar2 == 0) {
        _ifree(param_1,param_2,0);
        iVar2 = 0;
      }
      else {
        if (*(sword *)(iVar2 + 100) == 0) {
          iVar3 = *(int *)(iVar2 + 0xcc);
        }
        else {
          _printf(aMode0OInumDFsS,*(sword *)(iVar2 + 100),*(undefined4 *)(iVar2 + 0x48),iVar4 + 0xd4
                 );
          _panic(aIallocDupAlloc);
          iVar3 = *(int *)(iVar2 + 0xcc);
        }
        if (iVar3 != 0) {
          _printf(aFreeInodeSDHad,iVar4 + 0xd4,param_2);
          *(undefined4 *)(iVar2 + 0xcc) = 0;
        }
        *(undefined4 *)(iVar2 + 200) = 0;
      }
      goto locret_F0049088;
    }
  }
  _fsfull(iVar4,2);
  iVar2 = 0;
locret_F0049088:
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=999 start=0xf0049090 */

/* WARNING: Removing unreachable block (ram,0xf0049124) */
/* WARNING: Removing unreachable block (ram,0xf004909c) */

undefined8 _dirpref(int param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 unaff_l0;
  int iVar12;
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
  iVar12 = *(int *)(param_1 + 0x2c);
  iVar2 = *(int *)(param_1 + 200);
  .div(iVar2,iVar12);
  uVar10 = 0;
  uVar6 = 0;
  if (0 < iVar12) {
    bVar1 = (byte)*(undefined4 *)(param_1 + 0x70);
    iVar3 = 0 >> (bVar1 & 0x1f);
    iVar8 = *(int *)(param_1 + 0xb8);
    uVar11 = uVar10;
    do {
      iVar3 = *(int *)(iVar3 * 4 + param_1 + 0x2d8);
      iVar5 = (uVar6 & ~*(uint *)(param_1 + 0x6c)) * 0x10;
      iVar7 = *(int *)(iVar3 + iVar5);
      iVar9 = iVar8;
      uVar10 = uVar11;
      if ((iVar7 < iVar8) && (iVar9 = iVar7, uVar10 = uVar6, *(int *)(iVar3 + iVar5 + 8) < iVar2)) {
        iVar9 = iVar8;
        uVar10 = uVar11;
      }
      uVar6 = uVar6 + 1;
      iVar3 = (int)uVar6 >> (bVar1 & 0x1f);
      iVar8 = iVar9;
      uVar11 = uVar10;
    } while ((int)uVar6 < iVar12);
  }
  uVar4 = *(undefined4 *)(param_1 + 0xb8);
  .umul(uVar4,uVar10);
  return CONCAT44(param_2,uVar4);
}

