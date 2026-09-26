
/* WARNING: Removing unreachable block (ram,0xf00c86f8) */
/* WARNING: Removing unreachable block (ram,0xf00c86b4) */
/* WARNING: Removing unreachable block (ram,0xf00c8688) */
/* WARNING: Removing unreachable block (ram,0xf00c8664) */
/* WARNING: Removing unreachable block (ram,0xf00c863c) */
/* WARNING: Removing unreachable block (ram,0xf00c8600) */
/* WARNING: Removing unreachable block (ram,0xf00c85b4) */
/* WARNING: Removing unreachable block (ram,0xf00c8524) */
/* WARNING: Removing unreachable block (ram,0xf00c84f8) */
/* WARNING: Removing unreachable block (ram,0xf00c84d8) */
/* WARNING: Removing unreachable block (ram,0xf00c850c) */
/* WARNING: Removing unreachable block (ram,0xf00c8558) */
/* WARNING: Removing unreachable block (ram,0xf00c85e8) */
/* WARNING: Removing unreachable block (ram,0xf00c861c) */
/* WARNING: Removing unreachable block (ram,0xf00c8654) */
/* WARNING: Removing unreachable block (ram,0xf00c8674) */
/* WARNING: Removing unreachable block (ram,0xf00c869c) */
/* WARNING: Removing unreachable block (ram,0xf00c86d4) */
/* WARNING: Removing unreachable block (ram,0xf00c8710) */
/* WARNING: Removing unreachable block (ram,0xf00c84d0) */

void sub_F00C84B4(void)

{
  char cVar1;
  undefined *puVar2;
  uint uVar3;
  undefined (*pauVar4) [12];
  undefined (*pauVar5) [16];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar6;
  uint uVar7;
  undefined4 unaff_l3;
  uint uVar8;
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
  uVar8 = 1;
  puVar2 = DAT_f00fa400;
  while( true ) {
    sub_F00C8724();
    puVar6 = dword_F01330A0;
    _vol_check_manual_poll();
    if ((uint **)puVar6 != &dword_F01330A0) break;
loc_F00C8710:
    puVar2 = (undefined *)0x3e8;
    _IOSleep();
  }
  uVar3 = *puVar6;
  do {
    _objc_msgSend(uVar3,paName);
    uVar7 = *puVar6;
    uVar3 = uVar7;
    _objc_msgSend(uVar7,paLastreadystate_0);
    if (uVar3 != 0) {
      uVar8 = *puVar6;
      _objc_msgSend(uVar8,paNeedsmanualpol);
      if ((((uVar8 & 0xff) == 0) || (puVar2 != (undefined *)0x0)) || (uVar8 = uVar3, uVar3 == 3)) {
        uVar8 = uVar7;
        _objc_msgSend(uVar7,paUpdatereadysta);
      }
    }
    if (uVar3 < 3) {
      if (uVar3 == 0) {
        puVar6 = (uint *)puVar6[6];
      }
      else if (uVar8 == 0) {
        _objc_msgSend(uVar7,paSetlastreadyst,0);
        if (*(char *)((int)puVar6 + 0xd) != '\0') {
          _vol_panel_remove(puVar6[4]);
        }
        _objc_msgSend(uVar7,paUpdatephysical);
        _objc_msgSend(uVar7,paDiskbecameread);
        pauVar4 = paIodevicedescri;
        _objc_msgSend(paIodevicedescri,paNew);
        _objc_msgSend();
        pauVar5 = paIodiskpartitio_1;
        _objc_msgSend(paIodiskpartitio_1,paProbe,pauVar4);
        if (((uint)pauVar5 & 0xff) == 0) {
          _objc_msgSend(pauVar4,paFree);
          cVar1 = *(char *)((int)puVar6 + 0xd);
        }
        else {
          cVar1 = *(char *)((int)puVar6 + 0xd);
        }
        if (cVar1 == '\0') {
          sub_F00C8AA4(uVar7,(int)*(sword *)(puVar6 + 1),(int)*(sword *)((int)puVar6 + 6));
        }
        else {
          *(undefined *)((int)puVar6 + 0xd) = 0;
        }
loc_F00C8700:
        puVar6 = (uint *)puVar6[6];
      }
      else {
        puVar6 = (uint *)puVar6[6];
      }
    }
    else if (uVar3 == 3) {
      if (uVar8 == 0) {
        uVar3 = puVar6[2];
        puVar6[2] = uVar3 - 1;
        if (uVar3 - 1 == 0) {
          _objc_msgSend(uVar7,paUnit_0);
          _vol_panel_request(0,6,1,0,puVar6[5],uVar7,0,&asc_F00FA528,&asc_F00FA528,0,puVar6 + 4);
          *(undefined *)(puVar6 + 3) = 1;
        }
        goto loc_F00C8700;
      }
      _objc_msgSend(uVar7,paSetlastreadyst,2);
      if (*(char *)(puVar6 + 3) == '\0') {
        puVar6 = (uint *)puVar6[6];
      }
      else {
        *(undefined *)(puVar6 + 3) = 0;
        _vol_panel_remove(puVar6[4]);
        puVar6 = (uint *)puVar6[6];
      }
    }
    else {
      puVar6 = (uint *)puVar6[6];
    }
    if ((uint **)puVar6 == &dword_F01330A0) goto loc_F00C8710;
    uVar3 = *puVar6;
  } while( true );
}

