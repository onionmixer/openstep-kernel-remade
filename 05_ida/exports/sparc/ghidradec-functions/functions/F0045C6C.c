
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
