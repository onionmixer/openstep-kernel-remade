
/* WARNING: Removing unreachable block (ram,0xf003bf8c) */
/* WARNING: Removing unreachable block (ram,0xf003bf4c) */
/* WARNING: Removing unreachable block (ram,0xf003bf0c) */
/* WARNING: Removing unreachable block (ram,0xf003beec) */
/* WARNING: Removing unreachable block (ram,0xf003be44) */
/* WARNING: Removing unreachable block (ram,0xf003bd44) */
/* WARNING: Removing unreachable block (ram,0xf003be74) */
/* WARNING: Removing unreachable block (ram,0xf003be2c) */
/* WARNING: Removing unreachable block (ram,0xf003be04) */
/* WARNING: Removing unreachable block (ram,0xf003bd98) */
/* WARNING: Removing unreachable block (ram,0xf003bde8) */
/* WARNING: Removing unreachable block (ram,0xf003be18) */
/* WARNING: Removing unreachable block (ram,0xf003be60) */
/* WARNING: Removing unreachable block (ram,0xf003bdc4) */
/* WARNING: Removing unreachable block (ram,0xf003bd14) */
/* WARNING: Removing unreachable block (ram,0xf003be50) */
/* WARNING: Removing unreachable block (ram,0xf003bef8) */
/* WARNING: Removing unreachable block (ram,0xf003bf28) */
/* WARNING: Removing unreachable block (ram,0xf003bf58) */
/* WARNING: Removing unreachable block (ram,0xf003bfa8) */
/* WARNING: Removing unreachable block (ram,0xf003bd84) */

undefined8 sub_F003BCD8(int param_1,undefined *param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined *puVar5;
  int iVar6;
  undefined4 unaff_l3;
  undefined *puVar7;
  undefined4 unaff_l4;
  undefined4 *puVar8;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined *puVar9;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 uVar10;
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
  puVar5 = (undefined *)0x0;
  puVar8 = (undefined4 *)0x0;
  uVar10 = 0;
  puVar9 = (undefined *)0x0;
  puVar7 = (undefined *)0x0;
  _svstat = _svstat + 1;
  uVar4 = *(uint *)(param_1 + 8);
  iVar6 = 0;
  puVar2 = puVar9;
  if (uVar4 < 0x12) {
    if (*(int *)(param_1 + 4) == 2) {
      puVar5 = _rfsdisptab;
      puVar8 = (undefined4 *)(_rfsdisptab + uVar4 * 0x18);
      *(undefined *)(dword_F0133DDC + 0x38) = 0;
      sub_F003BBE8();
      _bzero(puVar5,_rfssize);
      puVar2 = param_2;
      (**(code **)(*(int *)(param_2 + 8) + 8))
                (param_2,*(undefined4 *)(_rfsdisptab + uVar4 * 0x18 + 4),puVar5);
      if (puVar2 != (undefined *)0x0) {
        puVar3 = puVar2;
        if (uVar4 != 0) {
          _crget();
          uVar10 = *(undefined4 *)(_active_u + 0x1c);
          *(undefined **)(_active_u + 0x1c) = puVar2;
          puVar7 = puVar5;
          _findexport(puVar5,puVar5 + 0x14);
          puVar3 = puVar7;
          puVar9 = puVar2;
          if ((puVar7 != (undefined *)0x0) && (sub_F003C118(), puVar3 == (undefined *)0x0)) {
            _svcerr_weakauth(param_2);
            iVar1 = *(int *)(param_1 + 0x1c);
            puVar7 = aNfsServerWeakA;
            goto loc_F003BE44;
          }
        }
        sub_F003BBE8();
        _bzero(puVar3,_rfssize);
        *(int *)(unk_F013A8D8 + uVar4 * 4) = *(int *)(unk_F013A8D8 + uVar4 * 4) + 1;
        (*(code *)*puVar8)(puVar5,puVar3,puVar7,param_1);
        goto loc_F003BEB0;
      }
      _svcerr_decode(param_2);
      iVar1 = *(int *)(param_1 + 0x1c);
      puVar7 = aNfsServerBadGe;
      puVar2 = puVar9;
    }
    else {
      _svcerr_progvers(*(undefined4 *)(param_1 + 0x1c),2,2);
      iVar1 = *(int *)(param_1 + 0x1c);
      puVar7 = aNfsServerBadVe;
    }
  }
  else {
    _svcerr_noproc(*(undefined4 *)(param_1 + 0x1c));
    iVar1 = *(int *)(param_1 + 0x1c);
    puVar7 = aNfsServerBadPr;
  }
loc_F003BE44:
  iVar6 = 1;
  iVar1 = iVar1 + 0x14;
  _inet_ntoa(iVar1);
  _printf(puVar7,iVar1);
  puVar3 = (undefined *)0x0;
  puVar9 = puVar2;
loc_F003BEB0:
  if ((puVar8 != (undefined4 *)0x0) &&
     (puVar2 = param_2, (**(code **)(*(int *)(param_2 + 8) + 0x10))(param_2,puVar8[1],puVar5),
     puVar2 == (undefined *)0x0)) {
    iVar6 = iVar6 + 1;
    iVar1 = *(int *)(param_1 + 0x1c) + 0x14;
    _inet_ntoa(iVar1);
    _printf(aNfsServerBadFr,iVar1);
  }
  if (puVar5 != (undefined *)0x0) {
    sub_F003BCBC(puVar5);
  }
  if ((iVar6 == 0) &&
     (puVar2 = param_2, _svc_sendreply(param_2,puVar8[3],puVar3), puVar2 == (undefined *)0x0)) {
    iVar6 = 1;
    iVar1 = *(int *)(param_1 + 0x1c) + 0x14;
    _inet_ntoa(iVar1);
    _printf(aNfsServerBadSe,iVar1);
  }
  if (puVar3 != (undefined *)0x0) {
    if ((code *)puVar8[5] != sub_F003BBDC) {
      (*(code *)puVar8[5])(puVar3);
    }
    sub_F003BCBC(puVar3);
  }
  if (puVar9 != (undefined *)0x0) {
    *(undefined4 *)(_active_u + 0x1c) = uVar10;
    _crfree(puVar9);
  }
  DAT_f013a8d4 = DAT_f013a8d4 + iVar6;
  return CONCAT44(param_2,param_1);
}
