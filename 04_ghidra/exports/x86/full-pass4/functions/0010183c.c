/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010183c */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=orphan_instruction_fragment.
   Context recorded in gap-actions.json. */

undefined4 __regparm3
__analysis_fragment_0010183c(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int unaff_EBX;
  uint uVar2;
  int unaff_EBP;
  int unaff_ESI;
  
  uVar1 = (undefined1)param_3;
  *(undefined1 *)((int)param_2 + 0x1e) = uVar1;
  *(short *)(param_2 + 7) = (short)param_3;
  param_2[6] = param_3;
  param_2[5] = param_3;
  param_2[4] = param_3;
  param_2[3] = param_3;
  param_2[2] = param_3;
  param_2[1] = param_3;
  *param_2 = param_3;
  uVar2 = unaff_EBX - unaff_ESI;
  param_2 = (undefined4 *)((int)param_2 + ((uVar2 & 0x1c) - 0x20) + unaff_ESI);
  switch(uVar2 & 0x1c) {
  case 0:
    while( true ) {
      param_2 = param_2 + 8;
      uVar2 = uVar2 - 0x20;
      if ((int)uVar2 < 0) break;
      *param_2 = param_3;
switchD_001018f8_caseD_1c:
      param_2[1] = param_3;
switchD_001018f8_caseD_18:
      param_2[2] = param_3;
switchD_001018f8_caseD_14:
      param_2[3] = param_3;
switchD_001018f8_caseD_10:
      param_2[4] = param_3;
switchD_001018f8_caseD_c:
      param_2[5] = param_3;
switchD_001018f8_caseD_8:
      param_2[6] = param_3;
switchD_001018f8_caseD_4:
      param_2[7] = param_3;
    }
    uVar2 = uVar2 & 3;
    break;
  case 4:
    goto switchD_001018f8_caseD_4;
  case 8:
    goto switchD_001018f8_caseD_8;
  case 0xc:
    goto switchD_001018f8_caseD_c;
  case 0x10:
    goto switchD_001018f8_caseD_10;
  case 0x14:
    goto switchD_001018f8_caseD_14;
  case 0x18:
    goto switchD_001018f8_caseD_18;
  case 0x1c:
    goto switchD_001018f8_caseD_1c;
  }
  if (uVar2 == 2) {
LAB_001019ac:
    *(undefined1 *)((int)param_2 + 1) = uVar1;
  }
  else {
    if (2 < (int)uVar2) {
      if (uVar2 != 3) goto switchD_00101669_default;
      *(undefined1 *)((int)param_2 + 2) = uVar1;
      goto LAB_001019ac;
    }
    if (uVar2 != 1) goto switchD_00101669_default;
  }
  *(undefined1 *)param_2 = uVar1;
switchD_00101669_default:
  return *(undefined4 *)(unaff_EBP + -4);
}

