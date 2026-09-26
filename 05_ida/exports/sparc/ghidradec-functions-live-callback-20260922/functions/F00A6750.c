
/* WARNING: Removing unreachable block (ram,0xf00a6974) */
/* WARNING: Removing unreachable block (ram,0xf00a6940) */
/* WARNING: Removing unreachable block (ram,0xf00a68fc) */
/* WARNING: Removing unreachable block (ram,0xf00a68c0) */
/* WARNING: Removing unreachable block (ram,0xf00a68a4) */
/* WARNING: Removing unreachable block (ram,0xf00a67f8) */
/* WARNING: Removing unreachable block (ram,0xf00a67e0) */
/* WARNING: Removing unreachable block (ram,0xf00a687c) */
/* WARNING: Removing unreachable block (ram,0xf00a68b0) */
/* WARNING: Removing unreachable block (ram,0xf00a68cc) */
/* WARNING: Removing unreachable block (ram,0xf00a6930) */
/* WARNING: Removing unreachable block (ram,0xf00a69d8) */
/* WARNING: Removing unreachable block (ram,0xf00a6958) */
/* WARNING: Removing unreachable block (ram,0xf00a6834) */

undefined8 _log_ce_mem_err(uint param_1,uint param_2,uint param_3,code *param_4)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  uint uVar7;
  undefined4 unaff_l4;
  int iVar8;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar9;
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
  uVar4 = (param_2 & 0x700) >> 8;
  iVar8 = 0;
  uVar7 = (uint)(char)_ecc_syndrome_tab[(param_1 & 0xff00) >> 8];
  puVar9 = (undefined *)((param_1 & 0xf0) >> 4);
  if ((uVar4 < 6) && (3 < uVar4)) {
    iVar8 = (int)puVar9 << 3;
  }
  if (uVar7 < 0x48) {
    uVar4 = uVar7 >> 3;
    if (0x3f < uVar7) {
      uVar4 = uVar7 & 7;
    }
    iVar8 = (iVar8 + 7) - uVar4;
    iVar1 = (param_3 & 0xfffffff8) + iVar8;
    (*param_4)(iVar1,param_2 & 0xf);
    if (iVar1 == 0) {
      _printf(aSimmDecodeFunc);
    }
  }
  else {
    iVar6 = 0;
    iVar2 = (param_3 & 0xfffffff8) + iVar8;
    iVar5 = iVar2;
    do {
      iVar1 = iVar5;
      (*param_4)(iVar1,param_2 & 0xf);
      if (iVar1 == 0) {
        _printf(aSimmDecodeFunc_1);
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar2 + iVar6;
    } while (iVar6 < 8);
  }
  iVar6 = 0;
  iVar5 = 0;
  do {
    if (_mem_ce_simm[iVar5] == '\0') {
      _strcpy(_mem_ce_simm + iVar5,iVar1);
      *(int *)(_mem_ce_simm + iVar5 + 8) = *(int *)(_mem_ce_simm + iVar5 + 8) + 1;
      break;
    }
    puVar9 = _mem_ce_simm + iVar5;
    iVar2 = iVar1;
    _strcmp(iVar1,puVar9);
    if (iVar2 == 0) {
      iVar2 = *(int *)(_mem_ce_simm + iVar5 + 8);
      *(uint *)(_mem_ce_simm + iVar5 + 8) = iVar2 + 1U;
      if (0xff < iVar2 + 1U) {
        _printf(aMultipleSofter);
        _printf(aSeenXCorrected,*(undefined4 *)(_mem_ce_simm + iVar5 + 8));
        _printf(aFromSimmS,iVar1);
        _printf(aConsiderReplac);
        *(undefined4 *)(_mem_ce_simm + iVar5 + 8) = 0;
        _log_ce_error = 1;
      }
      break;
    }
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 0xc;
  } while (iVar6 < 0x100);
  if (0xff < iVar6) {
    _printf(aSofterrorMemCe);
  }
  if (_log_ce_error != 0) {
    if (uVar7 < 0x48) {
      puVar3 = aCorrectedSimmA;
    }
    else {
      puVar3 = aPossibleCorrec;
    }
    _printf(puVar3,iVar1);
    _printf(aOffsetIsD,iVar8);
    if (uVar7 < 0x40) {
      _printf(aBit2dWasCorrec,uVar7);
    }
    else if (uVar7 < 0x48) {
      _printf(aEccBit2dWasCor,uVar7 - 0x40);
    }
    else {
      if (uVar7 == 0x49) {
        puVar3 = aThreeBitsWereC;
      }
      else if (uVar7 < 0x4a) {
        if (uVar7 != 0x48) goto locret_F00A69E0;
        puVar3 = aTwoBitsWereCor;
      }
      else if (uVar7 == 0x4a) {
        puVar3 = aFourBitsWereCo;
      }
      else {
        if (uVar7 != 0x4b) goto locret_F00A69E0;
        puVar3 = aMoreThanFourBi;
      }
      _printf(puVar3);
    }
  }
locret_F00A69E0:
  return CONCAT44(_mem_ce_simm,puVar9);
}

