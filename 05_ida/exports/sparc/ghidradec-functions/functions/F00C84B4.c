
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
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar5;
  uint uVar6;
  undefined4 unaff_l3;
  uint uVar7;
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
  uVar7 = 1;
  puVar2 = DAT_f00fa400;
  while( true ) {
    sub_F00C8724();
    puVar5 = dword_F01330A0;
    _vol_check_manual_poll();
    if ((uint **)puVar5 != &dword_F01330A0) break;
loc_F00C8710:
    puVar2 = (undefined *)0x3e8;
    _IOSleep();
  }
  uVar3 = *puVar5;
  do {
    _objc_msgSend(uVar3,paName);
    uVar6 = *puVar5;
    uVar3 = uVar6;
    _objc_msgSend(uVar6,paLastreadystate_0);
    if (uVar3 != 0) {
      uVar7 = *puVar5;
      _objc_msgSend(uVar7,paNeedsmanualpol);
      if ((((uVar7 & 0xff) == 0) || (puVar2 != (undefined *)0x0)) || (uVar7 = uVar3, uVar3 == 3)) {
        uVar7 = uVar6;
        _objc_msgSend(uVar6,paUpdatereadysta);
      }
    }
    if (uVar3 < 3) {
      if (uVar3 == 0) {
        puVar5 = (uint *)puVar5[6];
      }
      else if (uVar7 == 0) {
        _objc_msgSend(uVar6,paSetlastreadyst,0);
        if (*(char *)((int)puVar5 + 0xd) != '\0') {
          _vol_panel_remove(puVar5[4]);
        }
        _objc_msgSend(uVar6,paUpdatephysical);
        _objc_msgSend(uVar6,paDiskbecameread);
        pauVar4 = paIodevicedescri;
        _objc_msgSend(paIodevicedescri,paNew);
        _objc_msgSend();
        uVar3 = paIodiskpartitio_1;
        _objc_msgSend(paIodiskpartitio_1,paProbe,pauVar4);
        if ((uVar3 & 0xff) == 0) {
          _objc_msgSend(pauVar4,paFree);
          cVar1 = *(char *)((int)puVar5 + 0xd);
        }
        else {
          cVar1 = *(char *)((int)puVar5 + 0xd);
        }
        if (cVar1 == '\0') {
          sub_F00C8AA4(uVar6,(int)*(sword *)(puVar5 + 1),(int)*(sword *)((int)puVar5 + 6));
        }
        else {
          *(undefined *)((int)puVar5 + 0xd) = 0;
        }
loc_F00C8700:
        puVar5 = (uint *)puVar5[6];
      }
      else {
        puVar5 = (uint *)puVar5[6];
      }
    }
    else if (uVar3 == 3) {
      if (uVar7 == 0) {
        uVar3 = puVar5[2];
        puVar5[2] = uVar3 - 1;
        if (uVar3 - 1 == 0) {
          _objc_msgSend(uVar6,paUnit_0);
          _vol_panel_request(0,6,1,0,puVar5[5],uVar6,0,&asc_F00FA528,&asc_F00FA528,0,puVar5 + 4);
          *(undefined *)(puVar5 + 3) = 1;
        }
        goto loc_F00C8700;
      }
      _objc_msgSend(uVar6,paSetlastreadyst,2);
      if (*(char *)(puVar5 + 3) == '\0') {
        puVar5 = (uint *)puVar5[6];
      }
      else {
        *(undefined *)(puVar5 + 3) = 0;
        _vol_panel_remove(puVar5[4]);
        puVar5 = (uint *)puVar5[6];
      }
    }
    else {
      puVar5 = (uint *)puVar5[6];
    }
    if ((uint **)puVar5 == &dword_F01330A0) goto loc_F00C8710;
    uVar3 = *puVar5;
  } while( true );
}
