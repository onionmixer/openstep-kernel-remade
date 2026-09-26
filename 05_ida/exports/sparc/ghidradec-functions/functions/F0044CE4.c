
/* WARNING: Removing unreachable block (ram,0xf0044d5c) */
/* WARNING: Removing unreachable block (ram,0xf0044e10) */
/* WARNING: Removing unreachable block (ram,0xf0044e30) */
/* WARNING: Removing unreachable block (ram,0xf0044dfc) */
/* WARNING: Removing unreachable block (ram,0xf0044d10) */

undefined8 __svcauth_unix(int param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
  int iVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar9;
  undefined4 unaff_i1;
  undefined4 *puVar10;
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
  puVar6 = (undefined4 *)((int)register0x00000038 + -0x20);
  puVar5 = *(undefined4 **)(param_1 + 0x18);
  puVar5[1] = puVar5 + 6;
  puVar5[5] = puVar5 + 0x46;
  uVar8 = *(uint *)(param_2 + 0x20);
  _xdrmem_create(puVar6,*(undefined4 *)(param_2 + 0x1c),uVar8,1);
  puVar10 = puVar6;
  (**(code **)(*(int *)((int)register0x00000038 + -0x1c) + 0x18))(puVar6,uVar8);
  if (puVar10 == (undefined4 *)0x0) {
    puVar1 = puVar6;
    _xdr_authunix_parms(puVar6,puVar5);
    puVar10 = (undefined4 *)0x0;
    if (puVar1 == (undefined4 *)0x0) {
      *(undefined4 *)((int)register0x00000038 + -0x20) = 2;
      _xdr_authunix_parms(puVar6,puVar5);
      uVar9 = 1;
      goto loc_F0044E54;
    }
    iVar7 = *(int *)(param_1 + 0x1c);
loc_F0044E44:
    *(undefined4 *)(iVar7 + 0x20) = 0;
    uVar9 = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x28) = 0;
  }
  else {
    *puVar5 = *puVar10;
    iVar7 = puVar10[1];
    puVar10 = puVar10 + 2;
    if (iVar7 < 0x100) {
      _bcopy(puVar10,puVar5[1],iVar7);
      uVar2 = iVar7 + 3;
      *(undefined *)(puVar5[1] + iVar7) = 0;
      if ((int)uVar2 < 0) {
        uVar2 = iVar7 + 6;
      }
      puVar10 = (undefined4 *)((int)puVar10 + (uVar2 & 0xfffffffc));
      puVar5[2] = *puVar10;
      puVar5[3] = puVar10[1];
      iVar7 = puVar10[2];
      puVar10 = puVar10 + 3;
      if (iVar7 < 0x11) {
        iVar4 = 0;
        puVar5[4] = iVar7;
        if (0 < iVar7) {
          do {
            iVar3 = iVar4 * 4;
            iVar4 = iVar4 + 1;
            *(undefined4 *)(puVar5[5] + iVar3) = *puVar10;
            puVar10 = puVar10 + 1;
          } while (iVar4 < iVar7);
        }
        if ((iVar7 + 5) * 4 + (uVar2 & 0xfffffffc) <= uVar8) {
          iVar7 = *(int *)(param_1 + 0x1c);
          goto loc_F0044E44;
        }
        _printf(aBadAuthLenGidD,iVar7,uVar8,uVar8);
      }
    }
    uVar9 = 1;
  }
loc_F0044E54:
  (**(code **)(*(int *)((int)register0x00000038 + -0x1c) + 0x1c))
            ((undefined *)((int)register0x00000038 + -0x20));
  return CONCAT44(puVar10,uVar9);
}
