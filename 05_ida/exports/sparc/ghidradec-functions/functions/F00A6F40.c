
/* WARNING: Removing unreachable block (ram,0xf00a7174) */
/* WARNING: Removing unreachable block (ram,0xf00a7010) */
/* WARNING: Removing unreachable block (ram,0xf00a6f94) */
/* WARNING: Removing unreachable block (ram,0xf00a6fe0) */
/* WARNING: Removing unreachable block (ram,0xf00a722c) */
/* WARNING: Removing unreachable block (ram,0xf00a6fcc) */
/* WARNING: Removing unreachable block (ram,0xf00a7248) */
/* WARNING: Removing unreachable block (ram,0xf00a6fa4) */
/* WARNING: Removing unreachable block (ram,0xf00a7104) */
/* WARNING: Removing unreachable block (ram,0xf00a719c) */
/* WARNING: Removing unreachable block (ram,0xf00a7218) */

undefined8 _setconf(int param_1,undefined4 param_2)

{
  char cVar1;
  sword sVar2;
  char *pcVar3;
  int iVar4;
  undefined *puVar5;
  undefined8 *puVar6;
  undefined5 *puVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  sword sVar8;
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
  sVar8 = 0;
  _rootfs = dword_F011B160;
  if (((_boothowto & 1) == 0) && (pcVar3 = (char *)(int)_rootdevice._0_1_, pcVar3 == (char *)0x0)) {
    _getDefaultRoot();
    iVar4 = -0xfee5000;
    if (pcVar3 != (char *)0x0) goto loc_F00A700C;
    sub_F00A7380();
    if (iVar4 == 0) {
      puVar5 = aNoScsiControll_0;
      goto loc_F00A7104;
    }
    puVar5 = aNoScsiDriveAtD_0;
    goto loc_F00A7248;
  }
  do {
    if ((_boothowto & 1) == 0) {
      pcVar3 = (char *)&_rootdevice;
      if (_rootdevice._0_1_ != '\0') goto loc_F00A700C;
      _getDefaultRoot();
      iVar4 = -0xfee5000;
      if (pcVar3 != (char *)0x0) goto loc_F00A700C;
      sub_F00A7380();
      if (iVar4 == 0) {
        puVar5 = aNoScsiControll;
loc_F00A7104:
        _printf(puVar5);
      }
      else {
        puVar5 = aNoScsiDriveAtD;
loc_F00A7248:
        _printf(puVar5,0);
      }
    }
    else {
      _printf(aRootDevice);
      pcVar3 = (char *)((int)register0x00000038 + -0x88);
      _gets(pcVar3,pcVar3);
loc_F00A700C:
      _printf(aRootOnS,pcVar3);
      dword_F0131560 = &off_F011B108;
      puVar6 = off_F011B108;
      while (puVar6 != (undefined8 *)0x0) {
        if ((*(char *)*dword_F0131560 == *pcVar3) &&
           (*(char *)((int)*dword_F0131560 + 1) == pcVar3[1])) {
          if (*(sword *)(dword_F0131560 + 1) != -1) {
            if (pcVar3[3] == '*') {
              pcVar3[3] = pcVar3[4];
              cVar1 = pcVar3[2];
            }
            else {
              cVar1 = pcVar3[2];
            }
            if (7 < (byte)(cVar1 - 0x30U)) {
              puVar5 = aBadMissingUnit;
              goto loc_F00A7104;
            }
            cVar1 = pcVar3[3];
            if ((byte)(cVar1 + 0x9fU) < 8) {
              sVar2 = cVar1 + -0x61;
            }
            else {
              sVar2 = 0;
              if (cVar1 != '\0') {
                puVar5 = aBadPartitionNu;
                goto loc_F00A7104;
              }
            }
            sVar8 = sVar2;
            param_1 = pcVar3[2] + -0x30;
          }
          if (*(sword *)(dword_F0131560 + 1) == -1) {
            _rootfs = dword_F011B238;
          }
          else {
            _rootfs = DAT_f011b240._0_4_;
            _rootdev = *(word *)(dword_F0131560 + 1) & 0xff00 | (sword)param_1 * 8 + sVar8;
            *(word *)(dword_F0131560 + 1) = _rootdev;
          }
          return CONCAT44(param_2,param_1);
        }
        puVar6 = dword_F0131560[2];
        dword_F0131560 = dword_F0131560 + 2;
      }
    }
    dword_F0131560 = &off_F011B108;
    puVar6 = off_F011B108;
    while (puVar6 != (undefined8 *)0x0) {
      puVar7 = &aUse;
      if ((dword_F0131560 != &off_F011B108) &&
         (puVar7 = (undefined5 *)&DAT_f011b218, dword_F0131560[2] == (undefined8 *)0x0)) {
        puVar7 = &aOr;
      }
      _printf(&aSSD,puVar7,*dword_F0131560);
      puVar6 = dword_F0131560[2];
      dword_F0131560 = dword_F0131560 + 2;
    }
    _printf(&asc_F011B230);
    _boothowto = _boothowto | 1;
  } while( true );
}
