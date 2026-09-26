
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
  undefined (*pauVar1) [12];
  undefined (*pauVar2) [14];
  undefined (*pauVar3) [14];
  undefined (*pauVar4) [14];
  int iVar5;
  undefined (*pauVar6) [15];
  undefined (*pauVar7) [12];
  uint uVar8;
  undefined (*pauVar9) [14];
  undefined (*pauVar10) [14];
  undefined *puVar11;
  undefined (*pauVar12) [14];
  undefined (*pauVar13) [11];
  char cVar14;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined (*pauVar15) [12];
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined (*pauVar16) [12];
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar17;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar18;
  undefined4 unaff_i1;
  undefined (*pauVar19) [11];
  undefined4 unaff_i2;
  int iVar20;
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
  pauVar15 = (undefined (*) [12])0x0;
  pauVar19 = (undefined (*) [11])0x0;
  pauVar16 = (undefined (*) [12])0x0;
  *(undefined *)((int)register0x00000038 + -0x19) = 0;
  *(undefined *)((int)register0x00000038 + -0x39) = 0;
  iVar20 = 0;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  pauVar1 = (undefined (*) [12])0x80;
  _IOMalloc();
  pauVar2 = paIoconfigtable;
  _objc_msgSend(paIoconfigtable,paNewforconfigda,param_1);
  uVar18 = paValueforstring;
  pauVar3 = pauVar2;
  _objc_msgSend();
  pauVar4 = pauVar2;
  _objc_msgSend(pauVar2,uVar18,&aDynamic);
  if (pauVar4 != (undefined (*) [14])0x0) {
    if (((*pauVar4)[0] == 'Y') || ((*pauVar4)[0] == 'y')) {
      _objc_msgSend(_autoConfigTables,paAddobject,pauVar2);
      _objc_msgSend(pauVar2,paFreestring,pauVar4);
      uVar18 = 1;
      goto locret_F00C3A70;
    }
    _objc_msgSend(pauVar2,paFreestring,pauVar4);
  }
  pauVar4 = pauVar2;
  _objc_msgSend(pauVar2,paValueforstring,aPromName);
  *(undefined (**) [14])((int)register0x00000038 + -0x34) = pauVar4;
  if (pauVar4 == (undefined (*) [14])0x0) {
loc_F00C3454:
    *(undefined *)((int)register0x00000038 + -0x39) = 1;
  }
  else {
    iVar5 = *(int *)((int)register0x00000038 + -0x34);
    _strcmp(iVar5,&aPseudo);
    if (iVar5 == 0) goto loc_F00C3454;
  }
  uVar18 = paValueforstring;
  pauVar4 = pauVar2;
  _objc_msgSend(pauVar2,paValueforstring,aClassNames);
  if (pauVar4 == (undefined (*) [14])0x0) {
    pauVar4 = pauVar2;
    _objc_msgSend(pauVar2,uVar18,aDriverName_0);
  }
  pauVar6 = paKernstringlist;
  _objc_msgSend(paKernstringlist,paAlloc);
  _objc_msgSend();
  *(undefined (**) [15])((int)register0x00000038 + -0x14) = pauVar6;
  pauVar9 = pauVar4;
  _strlen(pauVar4);
  _IOFree(pauVar4,*pauVar9 + 1);
  pauVar4 = pauVar2;
  _objc_msgSend(pauVar2,uVar18,aBusType_1);
  if ((pauVar4 == (undefined (*) [14])0x0) || ((*pauVar4)[0] == '\0')) {
    *(undefined6 **)((int)register0x00000038 + -0x24) = &aSparc_4;
  }
  else {
    *(undefined (**) [14])((int)register0x00000038 + -0x24) = pauVar4;
  }
  _sprintf(pauVar1,aSkernbus_0,*(undefined4 *)((int)register0x00000038 + -0x24));
  pauVar7 = pauVar1;
  _objc_getClass();
  *(undefined (**) [12])((int)register0x00000038 + -0x2c) = pauVar7;
  if (pauVar7 == (undefined (*) [12])0x0) {
    *(undefined4 *)((int)register0x00000038 + -0x2c) = _defaultBusClass;
  }
  pauVar9 = pauVar2;
  _objc_msgSend(pauVar2,paValueforstring,aInstance);
  *(undefined (**) [14])((int)register0x00000038 + -0xc) = pauVar9;
  if (pauVar9 == (undefined (*) [14])0x0) {
    *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  }
  else {
    sub_F00C2F04();
    if (pauVar9 == (undefined (*) [14])0x0) {
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
    }
    else if (1 < *(int *)((int)register0x00000038 + -0x10)) {
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
    }
  }
  uVar18 = paAlloc;
  iVar5 = 0;
  uVar17 = 0;
  while( true ) {
    uVar8 = *(uint *)((int)register0x00000038 + -0x14);
    _objc_msgSend(uVar8,paCount_0);
    pauVar9 = *(undefined (**) [14])((int)register0x00000038 + -0x14);
    if (uVar8 <= uVar17) break;
    _objc_msgSend(pauVar9,paStringat,uVar17);
    pauVar10 = pauVar9;
    _objc_getClass();
    if (pauVar10 == (undefined (*) [14])0x0) {
      _IOLog(aConfiguredrive,pauVar9);
      if (pauVar3 == (undefined (*) [14])0x0) goto loc_F00C39C8;
      puVar11 = aDriverSCouldNo;
      pauVar9 = pauVar3;
      goto loc_F00C39BC;
    }
    uVar8 = *(uint *)((int)register0x00000038 + -0x2c);
    if (*(char *)((int)register0x00000038 + -0x19) == '\0') {
      if ((pauVar3 != (undefined (*) [14])0x0) &&
         (pauVar12 = pauVar3, sub_F00C310C(), ((uint)pauVar12 & 0xff) == 0)) goto loc_F00C39C8;
      *(undefined *)((int)register0x00000038 + -0x19) = 1;
      uVar8 = *(uint *)((int)register0x00000038 + -0x2c);
    }
    _objc_msgSend(uVar8,paConfiguredrive,pauVar2);
    if ((uVar8 & 0xff) != 0) {
      iVar5 = 1;
      break;
    }
    pauVar12 = pauVar10;
    _objc_msgSend(pauVar10,paDevicestyle);
    if (pauVar12 == (undefined (*) [14])0x0) {
      pauVar15 = *(undefined (**) [12])((int)register0x00000038 + -0x2c);
      _objc_msgSend(pauVar15,paDevicedescript,pauVar2);
      if (pauVar15 == (undefined (*) [12])0x0) {
        puVar11 = aConfiguredrive_3;
      }
      else {
        pauVar7 = pauVar15;
        _objc_msgSend();
        cVar14 = *(char *)((int)register0x00000038 + -0x39);
        if (pauVar7 == (undefined (*) [12])0x0) {
          _objc_msgSend(pauVar15,paSetbus,_defaultBus);
          cVar14 = *(char *)((int)register0x00000038 + -0x39);
        }
        if (cVar14 == '\0') {
          iVar20 = *(int *)((int)register0x00000038 + -0x34);
          _findDeviceinfoForDevice(iVar20,*(undefined4 *)((int)register0x00000038 + -0x10));
          if (iVar20 == 0) {
            _IOLog(aConfiguredrive_1,*(undefined4 *)((int)register0x00000038 + -0x34),pauVar9);
            goto loc_F00C39C8;
          }
          _objc_msgSend(pauVar15,paAdddeviceinfo,iVar20);
        }
        pauVar7 = pauVar15;
        _objc_msgSend(pauVar15,paBus_0);
        _objc_msgSend();
        if (pauVar7 == (undefined (*) [12])0x0) {
          puVar11 = aConfiguredrive_4;
        }
        else {
          pauVar19 = paKerndevice;
          _objc_msgSend(paKerndevice,uVar18);
          _objc_msgSend();
          if (pauVar19 != (undefined (*) [11])0x0) {
            _objc_msgSend(pauVar15,paSetdevice,pauVar19);
            _sprintf(pauVar1,aIoSdevicedescr,*(undefined4 *)((int)register0x00000038 + -0x24));
            pauVar16 = pauVar1;
            _objc_getClass();
            _objc_msgSend();
            _objc_msgSend();
            if (pauVar16 != (undefined (*) [12])0x0) {
              pauVar13 = pauVar19;
              _create_dev_port(pauVar19);
              _objc_msgSend(pauVar16,paSetdeviceport,pauVar13);
              _objc_msgSend(pauVar16,paSetdeviceinfo,iVar20);
              goto loc_F00C3860;
            }
            goto loc_F00C39C8;
          }
          puVar11 = aConfiguredrive_2;
        }
      }
loc_F00C39BC:
      _IOLog(puVar11,pauVar9);
loc_F00C39C8:
      if (pauVar3 != (undefined (*) [14])0x0) {
        _objc_msgSend(pauVar2,paFreestring,pauVar3);
      }
      if (pauVar4 != (undefined (*) [14])0x0) {
        _objc_msgSend(pauVar2,paFreestring,pauVar4);
      }
      if (pauVar2 != (undefined (*) [14])0x0) {
        _objc_msgSend(pauVar2,paFree);
      }
      if (pauVar16 != (undefined (*) [12])0x0) {
        _objc_msgSend(pauVar16,paFree);
      }
      if (pauVar15 != (undefined (*) [12])0x0) {
        _objc_msgSend(pauVar15,paFree);
      }
      uVar18 = paFree;
      if (pauVar19 == (undefined (*) [11])0x0) goto loc_F00C3A6C;
      goto loc_F00C3A64;
    }
    if ((undefined (*) [14])0x2 < pauVar12) {
      puVar11 = aInvalidStyleFo;
      goto loc_F00C39BC;
    }
    pauVar15 = paKerndevicedesc;
    _objc_msgSend(paKerndevicedesc,uVar18);
    _objc_msgSend();
    if (pauVar15 == (undefined (*) [12])0x0) goto loc_F00C39C8;
    pauVar16 = paIodevicedescri;
    _objc_msgSend(paIodevicedescri,uVar18);
    _objc_msgSend();
    if (pauVar16 == (undefined (*) [12])0x0) goto loc_F00C39C8;
loc_F00C3860:
    pauVar12 = pauVar10;
    _objc_msgSend(pauVar10,paRespondsto,paProbe);
    if (((uint)pauVar12 & 0xff) == 0) {
      _IOLog(aConfiguredrive_0,pauVar9);
      uVar17 = uVar17 + 1;
    }
    else {
      pauVar7 = paIodevice_0;
      _objc_msgSend(paIodevice_0,paAddloadedclass_0,pauVar10,pauVar16);
      if (pauVar7 == (undefined (*) [12])0x0) {
        iVar5 = iVar5 + 1;
      }
      uVar17 = uVar17 + 1;
    }
  }
  _IOFree(pauVar1,0x80);
  uVar18 = paFree;
  _objc_msgSend(*(undefined4 *)((int)register0x00000038 + -0x14),paFree);
  if (pauVar3 != (undefined (*) [14])0x0) {
    _objc_msgSend(pauVar2,paFreestring,pauVar3);
  }
  if (pauVar4 != (undefined (*) [14])0x0) {
    _objc_msgSend(pauVar2,paFreestring,pauVar4);
  }
  if (iVar5 == 0) {
    if (pauVar2 != (undefined (*) [14])0x0) {
      _objc_msgSend(pauVar2,uVar18);
    }
    if (pauVar16 != (undefined (*) [12])0x0) {
      _objc_msgSend(pauVar16,uVar18);
    }
    if (pauVar15 != (undefined (*) [12])0x0) {
      _objc_msgSend(pauVar15,uVar18);
    }
    if (pauVar19 != (undefined (*) [11])0x0) {
loc_F00C3A64:
      _objc_msgSend(pauVar19,uVar18);
    }
loc_F00C3A6C:
    uVar18 = 0;
  }
  else {
    uVar18 = 1;
  }
locret_F00C3A70:
  return CONCAT44(pauVar19,uVar18);
}
