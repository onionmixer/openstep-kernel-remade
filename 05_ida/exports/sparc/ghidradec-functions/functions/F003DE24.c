
/* WARNING: Removing unreachable block (ram,0xf003e11c) */
/* WARNING: Removing unreachable block (ram,0xf003e0d8) */
/* WARNING: Removing unreachable block (ram,0xf003e0fc) */
/* WARNING: Removing unreachable block (ram,0xf003e0ac) */
/* WARNING: Removing unreachable block (ram,0xf003e04c) */
/* WARNING: Removing unreachable block (ram,0xf003dff8) */
/* WARNING: Removing unreachable block (ram,0xf003dfc0) */
/* WARNING: Removing unreachable block (ram,0xf003df64) */
/* WARNING: Removing unreachable block (ram,0xf003df2c) */
/* WARNING: Removing unreachable block (ram,0xf003def8) */
/* WARNING: Removing unreachable block (ram,0xf003ded0) */
/* WARNING: Removing unreachable block (ram,0xf003dea8) */
/* WARNING: Removing unreachable block (ram,0xf003de78) */
/* WARNING: Removing unreachable block (ram,0xf003de54) */
/* WARNING: Removing unreachable block (ram,0xf003de68) */
/* WARNING: Removing unreachable block (ram,0xf003de8c) */
/* WARNING: Removing unreachable block (ram,0xf003dec4) */
/* WARNING: Removing unreachable block (ram,0xf003dee4) */
/* WARNING: Removing unreachable block (ram,0xf003df14) */
/* WARNING: Removing unreachable block (ram,0xf003df50) */
/* WARNING: Removing unreachable block (ram,0xf003df70) */
/* WARNING: Removing unreachable block (ram,0xf003dfe8) */
/* WARNING: Removing unreachable block (ram,0xf003e028) */
/* WARNING: Removing unreachable block (ram,0xf003e09c) */
/* WARNING: Removing unreachable block (ram,0xf003e0b4) */
/* WARNING: Removing unreachable block (ram,0xf003e084) */
/* WARNING: Removing unreachable block (ram,0xf003e110) */
/* WARNING: Removing unreachable block (ram,0xf003e128) */
/* WARNING: Removing unreachable block (ram,0xf003de4c) */

undefined8 sub_F003DE24(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined *puVar6;
  uint uVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar8;
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
  puVar8 = (undefined *)0x0;
  if (dword_F010D2C8 != 0) goto locret_F003E130;
  dword_F010D2C8 = 1;
  _bzero((undefined *)((int)register0x00000038 + -0x18),0x10);
  iVar2 = 2;
  _ifb_ifwithaf();
  puVar8 = aNfsServerSOk_0;
  if (iVar2 == 0) {
    _printf(aWhoamiZeroIfp);
    puVar8 = (undefined *)0x41;
    goto locret_F003E130;
  }
  _initrootnet();
  if (puVar8 != (undefined *)0x0) {
    _panic(aWhoamiInitroot);
  }
  puVar8 = (undefined *)0x0;
  _in_control(0,0xc0206912,(undefined *)((int)register0x00000038 + -0x58),iVar2);
  if (puVar8 != (undefined *)0x0) {
    _printf(aWhoamiInContro,puVar8,(int)*(sword *)(iVar2 + 0xc));
    _panic(aBadSiocgifbrda);
  }
  _bcopy((undefined *)((int)register0x00000038 + -0x48),
         (undefined *)((int)register0x00000038 + -0x18),0x10);
  _bcopy((undefined *)((int)register0x00000038 + -0x48),unk_F012F514,0x10);
  *(undefined4 *)((int)register0x00000038 + -0x20) = 1;
  iVar3 = 0;
  _in_control(0,0xc020690d,(undefined *)((int)register0x00000038 + -0x58),iVar2);
  if (iVar3 != 0) {
    _panic(aBadSiocgifaddr);
  }
  bVar1 = false;
  *(undefined4 *)((int)register0x00000038 + -0x5c) =
       *(undefined4 *)((int)register0x00000038 + -0x44);
  _bcopy((undefined *)((int)register0x00000038 + -0x5c),
         (undefined *)((int)register0x00000038 + -0x1c),4);
  *(undefined4 *)((int)register0x00000038 + -0x38) = 3;
  *(undefined4 *)((int)register0x00000038 + -0x34) = 0;
  uVar4 = 0x100;
  _kalloc();
  *(undefined4 *)((int)register0x00000038 + -0x30) = uVar4;
  uVar4 = 0x100;
  _kalloc();
  *(undefined4 *)((int)register0x00000038 + -0x2c) = uVar4;
  do {
    puVar5 = (undefined *)((int)register0x00000038 + -0x18);
    *(undefined4 *)((int)register0x00000038 + -0x68) =
         *(undefined4 *)((int)register0x00000038 + -0x38);
    *(undefined4 *)((int)register0x00000038 + -100) =
         *(undefined4 *)((int)register0x00000038 + -0x34);
    sub_F003DD3C(puVar5,0x186ba,1,1,_xdr_bp_whoami_arg,
                 (undefined *)((int)register0x00000038 + -0x20),_xdr_bp_whoami_res,
                 (undefined *)((int)register0x00000038 + -0x30),
                 (undefined *)((int)register0x00000038 + -0x68),0);
    if ((puVar5 == (undefined *)0x5) && (!bVar1)) {
      _printf(aNoBootparamSer);
      _printf(aWhoamiPmapRmtc,5);
      bVar1 = true;
    }
    *(undefined4 *)((int)register0x00000038 + -0x38) = 0x14;
    *(undefined4 *)((int)register0x00000038 + -0x34) = 0;
  } while (puVar5 == (undefined *)0x5);
  if (bVar1) {
    _printf(aBootparamRespo_1);
  }
  if (puVar5 == (undefined *)0x0) {
    uVar7 = *(uint *)((int)register0x00000038 + -0x30);
    _strlen();
    _hostnamelen = uVar7;
    if (uVar7 < 0x101) {
      if ((int)uVar7 < 1) {
        _printf(aWhoamiNoHostNa);
        puVar8 = (undefined *)0x6;
      }
      else {
        _bcopy(*(undefined4 *)((int)register0x00000038 + -0x30),_hostname);
        _printf(aHostnameS,_hostname);
        uVar7 = *(uint *)((int)register0x00000038 + -0x2c);
        _strlen();
        _domainnamelen = uVar7;
        if (0x100 < uVar7) {
          puVar5 = aWhoamiDomainna;
          goto loc_F003E0D8;
        }
        if (0 < (int)uVar7) {
          _bcopy(*(undefined4 *)((int)register0x00000038 + -0x2c),_domainname);
          puVar6 = aDomainnameS;
          puVar5 = _domainname;
          goto loc_F003E110;
        }
      }
      goto loc_F003E118;
    }
    puVar5 = aWhoamiHostname;
loc_F003E0D8:
    puVar8 = (undefined *)0x3f;
    _printf(puVar5);
    uVar4 = *(undefined4 *)((int)register0x00000038 + -0x30);
  }
  else {
    puVar6 = aWhoamiRpcCallF;
    puVar8 = puVar5;
loc_F003E110:
    _printf(puVar6,puVar5);
loc_F003E118:
    uVar4 = *(undefined4 *)((int)register0x00000038 + -0x30);
  }
  _kfree(uVar4,0x100);
  _kfree(*(undefined4 *)((int)register0x00000038 + -0x2c),0x100);
locret_F003E130:
  return CONCAT44(param_2,puVar8);
}
