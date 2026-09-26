
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
