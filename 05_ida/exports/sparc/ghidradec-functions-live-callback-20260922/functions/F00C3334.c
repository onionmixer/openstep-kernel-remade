
/* WARNING: Removing unreachable block (ram,0xf00c38ac) */
/* WARNING: Removing unreachable block (ram,0xf00c3a64) */
/* WARNING: Removing unreachable block (ram,0xf00c3a2c) */
/* WARNING: Removing unreachable block (ram,0xf00c39f4) */
/* WARNING: Removing unreachable block (ram,0xf00c383c) */
/* WARNING: Removing unreachable block (ram,0xf00c3814) */
/* WARNING: Removing unreachable block (ram,0xf00c39bc) */
/* WARNING: Removing unreachable block (ram,0xf00c37dc) */
/* WARNING: Removing unreachable block (ram,0xf00c37b4) */
/* WARNING: Removing unreachable block (ram,0xf00c379c) */
/* WARNING: Removing unreachable block (ram,0xf00c3780) */
/* WARNING: Removing unreachable block (ram,0xf00c3754) */
/* WARNING: Removing unreachable block (ram,0xf00c3728) */
/* WARNING: Removing unreachable block (ram,0xf00c398c) */
/* WARNING: Removing unreachable block (ram,0xf00c36e4) */
/* WARNING: Removing unreachable block (ram,0xf00c36ac) */
/* WARNING: Removing unreachable block (ram,0xf00c3964) */
/* WARNING: Removing unreachable block (ram,0xf00c393c) */
/* WARNING: Removing unreachable block (ram,0xf00c38fc) */
/* WARNING: Removing unreachable block (ram,0xf00c38cc) */
/* WARNING: Removing unreachable block (ram,0xf00c3638) */
/* WARNING: Removing unreachable block (ram,0xf00c35e4) */
/* WARNING: Removing unreachable block (ram,0xf00c35c0) */
/* WARNING: Removing unreachable block (ram,0xf00c3558) */
/* WARNING: Removing unreachable block (ram,0xf00c3520) */
/* WARNING: Removing unreachable block (ram,0xf00c34d0) */
/* WARNING: Removing unreachable block (ram,0xf00c34b8) */
/* WARNING: Removing unreachable block (ram,0xf00c3490) */
/* WARNING: Removing unreachable block (ram,0xf00c3440) */
/* WARNING: Removing unreachable block (ram,0xf00c340c) */
/* WARNING: Removing unreachable block (ram,0xf00c33e0) */
/* WARNING: Removing unreachable block (ram,0xf00c338c) */
/* WARNING: Removing unreachable block (ram,0xf00c3370) */
/* WARNING: Removing unreachable block (ram,0xf00c33a4) */
/* WARNING: Removing unreachable block (ram,0xf00c33f4) */
/* WARNING: Removing unreachable block (ram,0xf00c3424) */
/* WARNING: Removing unreachable block (ram,0xf00c3470) */
/* WARNING: Removing unreachable block (ram,0xf00c34a8) */
/* WARNING: Removing unreachable block (ram,0xf00c34c4) */
/* WARNING: Removing unreachable block (ram,0xf00c34e4) */
/* WARNING: Removing unreachable block (ram,0xf00c3528) */
/* WARNING: Removing unreachable block (ram,0xf00c3570) */
/* WARNING: Removing unreachable block (ram,0xf00c35dc) */
/* WARNING: Removing unreachable block (ram,0xf00c3600) */
/* WARNING: Removing unreachable block (ram,0xf00c3660) */
/* WARNING: Removing unreachable block (ram,0xf00c38e0) */
/* WARNING: Removing unreachable block (ram,0xf00c3918) */
/* WARNING: Removing unreachable block (ram,0xf00c3950) */
/* WARNING: Removing unreachable block (ram,0xf00c367c) */
/* WARNING: Removing unreachable block (ram,0xf00c36c0) */
/* WARNING: Removing unreachable block (ram,0xf00c3700) */
/* WARNING: Removing unreachable block (ram,0xf00c371c) */
/* WARNING: Removing unreachable block (ram,0xf00c3738) */
/* WARNING: Removing unreachable block (ram,0xf00c3764) */
/* WARNING: Removing unreachable block (ram,0xf00c3794) */
/* WARNING: Removing unreachable block (ram,0xf00c37a4) */
/* WARNING: Removing unreachable block (ram,0xf00c37c8) */
/* WARNING: Removing unreachable block (ram,0xf00c37f0) */
/* WARNING: Removing unreachable block (ram,0xf00c3804) */
/* WARNING: Removing unreachable block (ram,0xf00c382c) */
/* WARNING: Removing unreachable block (ram,0xf00c39d8) */
/* WARNING: Removing unreachable block (ram,0xf00c3a10) */
/* WARNING: Removing unreachable block (ram,0xf00c3a48) */
/* WARNING: Removing unreachable block (ram,0xf00c386c) */
/* WARNING: Removing unreachable block (ram,0xf00c388c) */
/* WARNING: Removing unreachable block (ram,0xf00c3354) */

undefined8 sub_F00C3334(undefined4 param_1)

{
  undefined6 *puVar1;
  undefined (*pauVar2) [19];
  undefined (*pauVar3) [12];
  undefined (*pauVar4) [14];
  undefined (*pauVar5) [14];
  undefined (*pauVar6) [14];
  int iVar7;
  undefined (*pauVar8) [15];
  undefined (*pauVar9) [12];
  uint uVar10;
  undefined (*pauVar11) [14];
  undefined (*pauVar12) [14];
  undefined *puVar13;
  undefined (*pauVar14) [14];
  undefined (*pauVar15) [11];
  undefined5 *puVar16;
  char cVar17;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined (*pauVar18) [12];
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined (*pauVar19) [12];
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar20;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar21;
  undefined4 unaff_i1;
  undefined (*pauVar22) [11];
  undefined4 unaff_i2;
  int iVar23;
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
  pauVar18 = (undefined (*) [12])0x0;
  pauVar22 = (undefined (*) [11])0x0;
  pauVar19 = (undefined (*) [12])0x0;
  *(undefined *)((int)register0x00000038 + -0x19) = 0;
  *(undefined *)((int)register0x00000038 + -0x39) = 0;
  iVar23 = 0;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  pauVar3 = (undefined (*) [12])0x80;
  _IOMalloc();
  pauVar4 = paIoconfigtable;
  _objc_msgSend(paIoconfigtable,paNewforconfigda,param_1);
  pauVar2 = paValueforstring;
  pauVar5 = pauVar4;
  _objc_msgSend();
  pauVar6 = pauVar4;
  _objc_msgSend(pauVar4,pauVar2,&aDynamic);
  if (pauVar6 != (undefined (*) [14])0x0) {
    if (((*pauVar6)[0] == 'Y') || ((*pauVar6)[0] == 'y')) {
      _objc_msgSend(_autoConfigTables,paAddobject,pauVar4);
      _objc_msgSend(pauVar4,paFreestring,pauVar6);
      uVar21 = 1;
      goto locret_F00C3A70;
    }
    _objc_msgSend(pauVar4,paFreestring,pauVar6);
  }
  pauVar6 = pauVar4;
  _objc_msgSend(pauVar4,paValueforstring,aPromName);
  *(undefined (**) [14])((int)register0x00000038 + -0x34) = pauVar6;
  if (pauVar6 == (undefined (*) [14])0x0) {
loc_F00C3454:
    *(undefined *)((int)register0x00000038 + -0x39) = 1;
  }
  else {
    iVar7 = *(int *)((int)register0x00000038 + -0x34);
    _strcmp(iVar7,&aPseudo);
    if (iVar7 == 0) goto loc_F00C3454;
  }
  pauVar2 = paValueforstring;
  pauVar6 = pauVar4;
  _objc_msgSend(pauVar4,paValueforstring,aClassNames);
  if (pauVar6 == (undefined (*) [14])0x0) {
    pauVar6 = pauVar4;
    _objc_msgSend(pauVar4,pauVar2,aDriverName_0);
  }
  pauVar8 = paKernstringlist;
  _objc_msgSend(paKernstringlist,paAlloc);
  _objc_msgSend();
  *(undefined (**) [15])((int)register0x00000038 + -0x14) = pauVar8;
  pauVar11 = pauVar6;
  _strlen(pauVar6);
  _IOFree(pauVar6,*pauVar11 + 1);
  pauVar6 = pauVar4;
  _objc_msgSend(pauVar4,pauVar2,aBusType_1);
  if ((pauVar6 == (undefined (*) [14])0x0) || ((*pauVar6)[0] == '\0')) {
    *(undefined6 **)((int)register0x00000038 + -0x24) = &aSparc_4;
  }
  else {
    *(undefined (**) [14])((int)register0x00000038 + -0x24) = pauVar6;
  }
  _sprintf(pauVar3,aSkernbus_0,*(undefined4 *)((int)register0x00000038 + -0x24));
  pauVar9 = pauVar3;
  _objc_getClass();
  *(undefined (**) [12])((int)register0x00000038 + -0x2c) = pauVar9;
  if (pauVar9 == (undefined (*) [12])0x0) {
    *(undefined4 *)((int)register0x00000038 + -0x2c) = _defaultBusClass;
  }
  pauVar11 = pauVar4;
  _objc_msgSend(pauVar4,paValueforstring,aInstance);
  *(undefined (**) [14])((int)register0x00000038 + -0xc) = pauVar11;
  if (pauVar11 == (undefined (*) [14])0x0) {
    *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  }
  else {
    sub_F00C2F04();
    if (pauVar11 == (undefined (*) [14])0x0) {
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
    }
    else if (1 < *(int *)((int)register0x00000038 + -0x10)) {
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
    }
  }
  puVar1 = paAlloc;
  iVar7 = 0;
  uVar20 = 0;
  while( true ) {
    uVar10 = *(uint *)((int)register0x00000038 + -0x14);
    _objc_msgSend(uVar10,paCount_0);
    pauVar11 = *(undefined (**) [14])((int)register0x00000038 + -0x14);
    if (uVar10 <= uVar20) break;
    _objc_msgSend(pauVar11,paStringat,uVar20);
    pauVar12 = pauVar11;
    _objc_getClass();
    if (pauVar12 == (undefined (*) [14])0x0) {
      _IOLog(aConfiguredrive,pauVar11);
      if (pauVar5 == (undefined (*) [14])0x0) goto loc_F00C39C8;
      puVar13 = aDriverSCouldNo;
      pauVar11 = pauVar5;
      goto loc_F00C39BC;
    }
    uVar10 = *(uint *)((int)register0x00000038 + -0x2c);
    if (*(char *)((int)register0x00000038 + -0x19) == '\0') {
      if ((pauVar5 != (undefined (*) [14])0x0) &&
         (pauVar14 = pauVar5, sub_F00C310C(), ((uint)pauVar14 & 0xff) == 0)) goto loc_F00C39C8;
      *(undefined *)((int)register0x00000038 + -0x19) = 1;
      uVar10 = *(uint *)((int)register0x00000038 + -0x2c);
    }
    _objc_msgSend(uVar10,paConfiguredrive,pauVar4);
    if ((uVar10 & 0xff) != 0) {
      iVar7 = 1;
      break;
    }
    pauVar14 = pauVar12;
    _objc_msgSend(pauVar12,paDevicestyle);
    if (pauVar14 == (undefined (*) [14])0x0) {
      pauVar18 = *(undefined (**) [12])((int)register0x00000038 + -0x2c);
      _objc_msgSend(pauVar18,paDevicedescript,pauVar4);
      if (pauVar18 == (undefined (*) [12])0x0) {
        puVar13 = aConfiguredrive_3;
      }
      else {
        pauVar9 = pauVar18;
        _objc_msgSend();
        cVar17 = *(char *)((int)register0x00000038 + -0x39);
        if (pauVar9 == (undefined (*) [12])0x0) {
          _objc_msgSend(pauVar18,paSetbus,_defaultBus);
          cVar17 = *(char *)((int)register0x00000038 + -0x39);
        }
        if (cVar17 == '\0') {
          iVar23 = *(int *)((int)register0x00000038 + -0x34);
          _findDeviceinfoForDevice(iVar23,*(undefined4 *)((int)register0x00000038 + -0x10));
          if (iVar23 == 0) {
            _IOLog(aConfiguredrive_1,*(undefined4 *)((int)register0x00000038 + -0x34),pauVar11);
            goto loc_F00C39C8;
          }
          _objc_msgSend(pauVar18,paAdddeviceinfo,iVar23);
        }
        pauVar9 = pauVar18;
        _objc_msgSend(pauVar18,paBus_0);
        _objc_msgSend();
        if (pauVar9 == (undefined (*) [12])0x0) {
          puVar13 = aConfiguredrive_4;
        }
        else {
          pauVar22 = paKerndevice;
          _objc_msgSend(paKerndevice,puVar1);
          _objc_msgSend();
          if (pauVar22 != (undefined (*) [11])0x0) {
            _objc_msgSend(pauVar18,paSetdevice,pauVar22);
            _sprintf(pauVar3,aIoSdevicedescr,*(undefined4 *)((int)register0x00000038 + -0x24));
            pauVar19 = pauVar3;
            _objc_getClass();
            _objc_msgSend();
            _objc_msgSend();
            if (pauVar19 != (undefined (*) [12])0x0) {
              pauVar15 = pauVar22;
              _create_dev_port(pauVar22);
              _objc_msgSend(pauVar19,paSetdeviceport,pauVar15);
              _objc_msgSend(pauVar19,paSetdeviceinfo,iVar23);
              goto loc_F00C3860;
            }
            goto loc_F00C39C8;
          }
          puVar13 = aConfiguredrive_2;
        }
      }
loc_F00C39BC:
      _IOLog(puVar13,pauVar11);
loc_F00C39C8:
      if (pauVar5 != (undefined (*) [14])0x0) {
        _objc_msgSend(pauVar4,paFreestring,pauVar5);
      }
      if (pauVar6 != (undefined (*) [14])0x0) {
        _objc_msgSend(pauVar4,paFreestring,pauVar6);
      }
      if (pauVar4 != (undefined (*) [14])0x0) {
        _objc_msgSend(pauVar4,paFree);
      }
      if (pauVar19 != (undefined (*) [12])0x0) {
        _objc_msgSend(pauVar19,paFree);
      }
      if (pauVar18 != (undefined (*) [12])0x0) {
        _objc_msgSend(pauVar18,paFree);
      }
      puVar16 = paFree;
      if (pauVar22 == (undefined (*) [11])0x0) goto loc_F00C3A6C;
      goto loc_F00C3A64;
    }
    if ((undefined (*) [14])0x2 < pauVar14) {
      puVar13 = aInvalidStyleFo;
      goto loc_F00C39BC;
    }
    pauVar18 = paKerndevicedesc;
    _objc_msgSend(paKerndevicedesc,puVar1);
    _objc_msgSend();
    if (pauVar18 == (undefined (*) [12])0x0) goto loc_F00C39C8;
    pauVar19 = paIodevicedescri;
    _objc_msgSend(paIodevicedescri,puVar1);
    _objc_msgSend();
    if (pauVar19 == (undefined (*) [12])0x0) goto loc_F00C39C8;
loc_F00C3860:
    pauVar14 = pauVar12;
    _objc_msgSend(pauVar12,paRespondsto,paProbe);
    if (((uint)pauVar14 & 0xff) == 0) {
      _IOLog(aConfiguredrive_0,pauVar11);
      uVar20 = uVar20 + 1;
    }
    else {
      pauVar9 = paIodevice_0;
      _objc_msgSend(paIodevice_0,paAddloadedclass_0,pauVar12,pauVar19);
      if (pauVar9 == (undefined (*) [12])0x0) {
        iVar7 = iVar7 + 1;
      }
      uVar20 = uVar20 + 1;
    }
  }
  _IOFree(pauVar3,0x80);
  puVar16 = paFree;
  _objc_msgSend(*(undefined4 *)((int)register0x00000038 + -0x14),paFree);
  if (pauVar5 != (undefined (*) [14])0x0) {
    _objc_msgSend(pauVar4,paFreestring,pauVar5);
  }
  if (pauVar6 != (undefined (*) [14])0x0) {
    _objc_msgSend(pauVar4,paFreestring,pauVar6);
  }
  if (iVar7 == 0) {
    if (pauVar4 != (undefined (*) [14])0x0) {
      _objc_msgSend(pauVar4,puVar16);
    }
    if (pauVar19 != (undefined (*) [12])0x0) {
      _objc_msgSend(pauVar19,puVar16);
    }
    if (pauVar18 != (undefined (*) [12])0x0) {
      _objc_msgSend(pauVar18,puVar16);
    }
    if (pauVar22 != (undefined (*) [11])0x0) {
loc_F00C3A64:
      _objc_msgSend(pauVar22,puVar16);
    }
loc_F00C3A6C:
    uVar21 = 0;
  }
  else {
    uVar21 = 1;
  }
locret_F00C3A70:
  return CONCAT44(pauVar22,uVar21);
}

