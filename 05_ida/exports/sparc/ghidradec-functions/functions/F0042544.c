
/* WARNING: Removing unreachable block (ram,0xf00426d8) */
/* WARNING: Removing unreachable block (ram,0xf0042700) */
/* WARNING: Removing unreachable block (ram,0xf00426b8) */
/* WARNING: Removing unreachable block (ram,0xf00425d8) */
/* WARNING: Removing unreachable block (ram,0xf0042618) */
/* WARNING: Removing unreachable block (ram,0xf00426c0) */
/* WARNING: Removing unreachable block (ram,0xf0042714) */
/* WARNING: Removing unreachable block (ram,0xf0042730) */
/* WARNING: Removing unreachable block (ram,0xf004269c) */

undefined8 _authkern_marshal(int param_1,undefined4 *param_2)

{
  sword sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined *puVar5;
  uint uVar6;
  undefined4 unaff_l0;
  int *piVar7;
  undefined *puVar8;
  undefined4 unaff_l1;
  sword *psVar9;
  sword *psVar10;
  sword *psVar11;
  undefined4 unaff_l3;
  int iVar12;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar13;
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
  iVar2 = *(int *)(_active_u + 0x1c);
  psVar11 = (sword *)(iVar2 + 10);
  psVar9 = (sword *)(iVar2 + 0x2a);
  if (psVar11 < psVar9) {
    sVar1 = *(sword *)(iVar2 + 0x28);
    psVar10 = psVar9;
    while ((psVar9 = psVar10, sVar1 == -1 && (psVar9 = psVar10 + -1, psVar11 < psVar9))) {
      sVar1 = psVar10[-2];
      psVar10 = psVar9;
    }
  }
  iVar2 = (int)psVar9 - (int)psVar11 >> 1;
  uVar6 = _hostnamelen + 3;
  if ((int)uVar6 < 0) {
    uVar6 = _hostnamelen + 6;
  }
  iVar12 = (uVar6 & 0xfffffffc) + iVar2 * 4 + 0x14;
  puVar3 = param_2;
  (**(code **)(param_2[1] + 0x18))(param_2,iVar12 + 0x10);
  if (puVar3 != (undefined4 *)0x0) {
    _getthetime((undefined *)((int)register0x00000038 + -0x28));
    *puVar3 = 1;
    puVar3[1] = iVar12;
    puVar3[2] = *(undefined4 *)((int)register0x00000038 + -0x28);
    puVar3[3] = _hostnamelen;
    _bcopy(_hostname,puVar3 + 4,_hostnamelen);
    uVar6 = _hostnamelen + 3;
    if ((int)uVar6 < 0) {
      uVar6 = _hostnamelen + 6;
    }
    piVar7 = (int *)((int)(puVar3 + 4) + (uVar6 & 0xfffffffc));
    *piVar7 = (int)*(sword *)(*(int *)(_active_u + 0x1c) + 2);
    piVar7[1] = (int)*(sword *)(*(int *)(_active_u + 0x1c) + 4);
    piVar7[2] = iVar2;
    piVar7 = piVar7 + 3;
    for (; psVar11 < psVar9; psVar11 = psVar11 + 1) {
      *piVar7 = (int)*psVar11;
      piVar7 = piVar7 + 1;
    }
    *piVar7 = 0;
    piVar7[1] = 0;
    uVar13 = 1;
    goto locret_F0042738;
  }
  uVar4 = 400;
  _kalloc();
  puVar8 = (undefined *)((int)register0x00000038 + -0x20);
  _xdrmem_create(puVar8,uVar4,400,0);
  puVar5 = puVar8;
  _xdr_authkern();
  if (puVar5 == (undefined *)0x0) {
    _printf(aAuthkernMarsha);
    uVar13 = 0;
  }
  else {
    (**(code **)(*(int *)((int)register0x00000038 + -0x1c) + 0x10))();
    *(undefined **)(param_1 + 8) = puVar8;
    *(undefined4 *)(param_1 + 4) = uVar4;
    puVar3 = param_2;
    _xdr_opaque_auth(param_2,param_1);
    if (puVar3 != (undefined4 *)0x0) {
      puVar3 = param_2;
      _xdr_opaque_auth(param_2,param_1 + 0xc);
      uVar13 = 1;
      if (puVar3 != (undefined4 *)0x0) goto loc_F004272C;
    }
    uVar13 = 0;
  }
loc_F004272C:
  _kfree(uVar4,400);
locret_F0042738:
  return CONCAT44(param_2,uVar13);
}
