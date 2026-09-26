/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00191874 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00191874(void)

{
  undefined1 *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined1 *puVar9;
  int unaff_EBP;
  char *pcVar10;
  bool bVar11;
  
  puVar7 = (undefined4 *)&stack0x00000004;
  puVar9 = &stack0x00000004;
  __rootfs = DAT_001e268b;
  puVar1 = &stack0x00000004;
  if ((_boothowto & 1) != 0) goto LAB_001918a2;
  if (_rootdevice == '\0') {
    __boottype = _DAT_000110ac;
    _rootdev = (short)_DAT_000110ac << 8 |
               (ushort)DAT_000110ad | (ushort)(_DAT_000110ac >> 0xd) & 0x7f8;
LAB_00191ad0:
    *(uint *)(puVar9 + -4) = _boothowto;
    *(int *)(puVar9 + -8) = (int)(short)_rootdev;
    *(char **)(puVar9 + -0xc) = s_rootdev__x__howto__x_001e273f;
    *(undefined4 *)(puVar9 + -0x10) = 0x191ae9;
    _printf(*(char **)(puVar9 + -0xc));
    return;
  }
  do {
    puVar1 = (undefined1 *)puVar7;
    if ((_boothowto & 1) == 0) {
      iVar4 = 6;
      bVar11 = true;
      pcVar6 = &DAT_001e269d;
      pcVar10 = &_rootdevice;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar11 = *pcVar6 == *pcVar10;
        pcVar6 = pcVar6 + 1;
        pcVar10 = pcVar10 + 1;
      } while (bVar11);
      if (!bVar11) {
        pcVar6 = &_rootdevice;
LAB_00191951:
        *(char **)((int)puVar7 + -4) = pcVar6;
        *(char **)((int)puVar7 + -8) = s_root_on__s_001e26e9;
        *(undefined4 *)((int)puVar7 + -0xc) = 0x19195c;
        _printf(*(char **)((int)puVar7 + -8));
        goto LAB_0019195f;
      }
      *(undefined4 *)(unaff_EBP + -0x90) = 0;
      iVar4 = 0;
      pcVar6 = (char *)(unaff_EBP + -0x8c);
      do {
        *(int *)((int)puVar7 + -4) = iVar4;
        *(undefined **)((int)puVar7 + -8) = &DAT_001e26a3;
        *(char **)((int)puVar7 + -0xc) = pcVar6;
        *(undefined4 *)((int)puVar7 + -0x10) = 0x1918f4;
        _sprintf(*(char **)((int)puVar7 + -0xc),*(char **)((int)puVar7 + -8));
        *(int *)((int)puVar7 + -0x10) = unaff_EBP + -0x90;
        *(char **)((int)puVar7 + -0x14) = pcVar6;
        *(undefined4 *)((int)puVar7 + -0x18) = 0x191901;
        iVar3 = _IOGetObjectForDeviceName();
        if (iVar3 != 0) break;
        *(undefined **)((int)puVar7 + -4) = PTR_s_inquiryDeviceType_001f9420;
        *(undefined4 *)((int)puVar7 + -8) = *(undefined4 *)(unaff_EBP + -0x90);
        *(undefined4 *)((int)puVar7 + -0xc) = 0x19191b;
        cVar2 = _objc_msgSend();
        if (cVar2 == '\x05') goto LAB_00191951;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 0x10);
      *(undefined4 *)((int)puVar7 + -4) = 0x19192d;
      iVar4 = FUN_00191c68();
      if (iVar4 == 0) {
        puVar8 = (undefined4 *)((int)puVar7 + -4);
        *(char **)((int)puVar7 + -4) = s_No_SCSI_controller_or_CD_ROM_dri_001e26bf;
      }
      else {
        puVar8 = (undefined4 *)((int)puVar7 + -4);
        *(char **)((int)puVar7 + -4) = s_No_CD_ROM_drive_found_001e26a8;
      }
LAB_001919e5:
      puVar8[-1] = 0x1919ea;
      _printf((char *)*puVar8);
      puVar7 = puVar8 + 1;
    }
    else {
LAB_001918a2:
      puVar7 = (undefined4 *)puVar1;
      *(char **)((int)puVar7 + -4) = s_root_device__001e268f;
      *(undefined4 *)((int)puVar7 + -8) = 0x1918ac;
      _printf(*(char **)((int)puVar7 + -4));
      pcVar6 = (char *)(unaff_EBP + -0x80);
      *(char **)((int)puVar7 + -8) = pcVar6;
      *(char **)((int)puVar7 + -0xc) = pcVar6;
      *(undefined4 *)((int)puVar7 + -0x10) = 0x1918b6;
      _gets(*(char **)((int)puVar7 + -0xc));
LAB_0019195f:
      DAT_001e7740 = &_genericconf;
      puVar5 = _genericconf;
      while (puVar5 != (undefined *)0x0) {
        if ((**DAT_001e7740 == *pcVar6) && ((*DAT_001e7740)[1] == pcVar6[1])) {
          puVar9 = (undefined1 *)puVar7;
          if (*(short *)(DAT_001e7740 + 1) != -1) {
            if (7 < (byte)(pcVar6[2] - 0x30U)) {
              puVar8 = (undefined4 *)((int)puVar7 + -4);
              *(char **)((int)puVar7 + -4) = s_bad_missing_unit_number_001e270b;
              goto LAB_001919e5;
            }
            cVar2 = pcVar6[3];
            if ((byte)(cVar2 + 0x9fU) < 8) {
              *(int *)(unaff_EBP + -0x94) = cVar2 + -0x61;
            }
            else if (cVar2 != '\0') {
              puVar8 = (undefined4 *)((int)puVar7 + -4);
              *(char **)((int)puVar7 + -4) = s_bad_partition_number_001e26f5;
              goto LAB_001919e5;
            }
            if (*(ushort *)(DAT_001e7740 + 1) != 0xffff) {
              _rootdev = *(ushort *)(DAT_001e7740 + 1) & 0xff00 |
                         (pcVar6[2] + -0x30) * 8 + *(short *)(unaff_EBP + -0x94);
              *(ushort *)(DAT_001e7740 + 1) = _rootdev;
              goto LAB_00191ad0;
            }
          }
          __rootfs = DAT_001e273b;
          goto LAB_00191ad0;
        }
        puVar5 = DAT_001e7740[2];
        DAT_001e7740 = DAT_001e7740 + 2;
      }
    }
    DAT_001e7740 = &_genericconf;
    puVar5 = _genericconf;
    while (puVar5 != (undefined *)0x0) {
      *(undefined **)((int)puVar7 + -4) = *DAT_001e7740;
      if (DAT_001e7740 == &_genericconf) {
        puVar5 = &DAT_001e272c;
      }
      else {
        puVar5 = &DAT_001e2727;
        if (DAT_001e7740[2] != (undefined *)0x0) {
          puVar5 = &DAT_001e2724;
        }
      }
      *(undefined **)((int)puVar7 + -8) = puVar5;
      *(char **)((int)puVar7 + -0xc) = s__s_s__d_001e2731;
      *(undefined4 *)((int)puVar7 + -0x10) = 0x191a34;
      _printf(*(char **)((int)puVar7 + -0xc));
      puVar5 = DAT_001e7740[2];
      DAT_001e7740 = DAT_001e7740 + 2;
    }
    *(undefined **)((int)puVar7 + -4) = &DAT_001e2739;
    *(undefined4 *)((int)puVar7 + -8) = 0x191a55;
    _printf(*(char **)((int)puVar7 + -4));
    _boothowto = _boothowto | 1;
  } while( true );
}

