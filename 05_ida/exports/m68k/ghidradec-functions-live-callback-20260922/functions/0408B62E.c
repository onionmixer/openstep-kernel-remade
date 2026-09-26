
void _zsclose(word param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int *piVar19;
  char cStack_49;
  
  uVar16 = param_1 & 0x1f;
  iVar17 = uVar16 * 0x164;
  piVar19 = (int *)(DAT_40b52d0 + iVar17);
  puVar2 = *(undefined **)(DAT_40b52d0 + iVar17 + 0xc);
  iVar1 = uVar16 * 0x86;
  uVar3 = *(undefined4 *)(dword_40B57D4 + 0x28);
  uVar4 = *(undefined4 *)(dword_40B57D4 + 0x2c);
  uVar5 = *(undefined4 *)(dword_40B57D4 + 0x30);
  uVar6 = *(undefined4 *)(dword_40B57D4 + 0x34);
  uVar7 = *(undefined4 *)(dword_40B57D4 + 0x38);
  uVar8 = *(undefined4 *)(dword_40B57D4 + 0x3c);
  uVar9 = *(undefined4 *)(dword_40B57D4 + 0x40);
  uVar10 = *(undefined4 *)(dword_40B57D4 + 0x44);
  uVar11 = *(undefined4 *)(dword_40B57D4 + 0x48);
  uVar12 = *(undefined4 *)(dword_40B57D4 + 0x4c);
  uVar13 = *(undefined4 *)(dword_40B57D4 + 0x50);
  uVar14 = *(undefined4 *)(dword_40B57D4 + 0x54);
  uVar15 = *(undefined4 *)(dword_40B57D4 + 0x58);
  iVar18 = _setjmp(dword_40B57D4 + 0x28);
  if (iVar18 == 0) {
    (**(code **)(unk_40AE4B0 + (char)unk_40B51BC[iVar1 + 0x45] * 0x30))(unk_40B51BC + iVar1);
  }
  iVar18 = dword_40B57D4;
  *(undefined4 *)(dword_40B57D4 + 0x28) = uVar3;
  *(undefined4 *)(iVar18 + 0x2c) = uVar4;
  *(undefined4 *)(iVar18 + 0x30) = uVar5;
  *(undefined4 *)(iVar18 + 0x34) = uVar6;
  *(undefined4 *)(iVar18 + 0x38) = uVar7;
  *(undefined4 *)(iVar18 + 0x3c) = uVar8;
  *(undefined4 *)(iVar18 + 0x40) = uVar9;
  *(undefined4 *)(iVar18 + 0x44) = uVar10;
  *(undefined4 *)(iVar18 + 0x48) = uVar11;
  *(undefined4 *)(iVar18 + 0x4c) = uVar12;
  *(undefined4 *)(iVar18 + 0x50) = uVar13;
  *(undefined4 *)(iVar18 + 0x54) = uVar14;
  *(undefined4 *)(iVar18 + 0x58) = uVar15;
  sub_408CF32(uVar16,2,2);
  cStack_49 = (char)param_1;
  if ((cStack_49 < '\0') ||
     ((((*(uint *)(unk_40B51BC + iVar1 + 0x3e) & 0x202) != 0 ||
       ((*(uint *)(unk_40B51BC + iVar1 + 0x3e) & 4) == 0)) &&
      (*(int *)(unk_40B5418 + iVar17 + 0x10) == 0)))) {
    sub_408CF32(uVar16,0,0);
  }
  iVar18 = _setjmp(dword_40B57D4 + 0x28);
  if (iVar18 == 0) {
    _ttyclose(unk_40B51BC + iVar1);
  }
  iVar1 = dword_40B57D4;
  *(undefined4 *)(dword_40B57D4 + 0x28) = uVar3;
  *(undefined4 *)(iVar1 + 0x2c) = uVar4;
  *(undefined4 *)(iVar1 + 0x30) = uVar5;
  *(undefined4 *)(iVar1 + 0x34) = uVar6;
  *(undefined4 *)(iVar1 + 0x38) = uVar7;
  *(undefined4 *)(iVar1 + 0x3c) = uVar8;
  *(undefined4 *)(iVar1 + 0x40) = uVar9;
  *(undefined4 *)(iVar1 + 0x44) = uVar10;
  *(undefined4 *)(iVar1 + 0x48) = uVar11;
  *(undefined4 *)(iVar1 + 0x4c) = uVar12;
  *(undefined4 *)(iVar1 + 0x50) = uVar13;
  *(undefined4 *)(iVar1 + 0x54) = uVar14;
  *(undefined4 *)(iVar1 + 0x58) = uVar15;
  (&DAT_40b5400)[uVar16 * 0x59] = (&DAT_40b5400)[uVar16 * 0x59] & 0x146;
  if (*(int *)(unk_40B5418 + iVar17 + 0x10) == 0) {
    _delay(1);
    *puVar2 = 1;
    _delay(1);
    *puVar2 = 0;
    *(undefined4 *)(unk_40B5404 + iVar17 + 4) = 0;
    *(undefined4 *)(unk_40B5404 + iVar17 + 8) = 0;
    *(undefined4 *)(unk_40B5404 + iVar17 + 0xc) = 0;
    *(undefined4 *)(unk_40B5404 + iVar17 + 0x10) = 0;
    *(undefined4 *)(unk_40B5418 + iVar17) = 0;
    *(undefined4 *)(unk_40B5404 + iVar17) = 0;
    (&DAT_40b5400)[uVar16 * 0x59] = 0;
    _zsrelease(uVar16);
    if (*piVar19 != 0) {
      _kfree(*piVar19,dword_40B51A8 * 2);
      *piVar19 = 0;
    }
  }
  _wakeup(piVar19);
  return;
}

