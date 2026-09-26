/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001168aa */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001168aa(void)

{
  short sVar1;
  ushort uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int unaff_EBX;
  int unaff_EBP;
  ushort *unaff_ESI;
  
  for (puVar3 = *(undefined4 **)(unaff_EBP + 0xc); puVar3 != (undefined4 *)0x0;
      puVar3 = (undefined4 *)*puVar3) {
    unaff_EBX = unaff_EBX + *(short *)(puVar3 + 2);
  }
  sVar1 = *(short *)(*(int *)(unaff_EBP + 0x10) + 8);
  *(uint *)(unaff_EBP + -4) = (uint)unaff_ESI[3] - (uint)unaff_ESI[2];
  iVar7 = (uint)unaff_ESI[1] - (uint)*unaff_ESI;
  if (*(int *)(unaff_EBP + -4) < iVar7) {
    iVar7 = *(int *)(unaff_EBP + -4);
  }
  if ((iVar7 < unaff_EBX + sVar1) ||
     (iVar7 = _m_copy(*(undefined4 *)(unaff_EBP + 0x10),0), iVar7 == 0)) {
    uVar6 = 0;
  }
  else {
    *unaff_ESI = *unaff_ESI + *(short *)(iVar7 + 8);
    uVar2 = unaff_ESI[2];
    unaff_ESI[2] = uVar2 + 0x80;
    if (0x7c < *(uint *)(iVar7 + 4)) {
      unaff_ESI[2] = uVar2 + 0x480;
    }
    iVar4 = *(int *)(unaff_ESI + 6);
    if (iVar4 == 0) {
      *(int *)(unaff_ESI + 6) = iVar7;
    }
    else {
      iVar5 = *(int *)(iVar4 + 0x7c);
      while (iVar5 != 0) {
        iVar4 = *(int *)(iVar4 + 0x7c);
        iVar5 = *(int *)(iVar4 + 0x7c);
      }
      *(int *)(iVar4 + 0x7c) = iVar7;
    }
    if (*(int *)(unaff_EBP + 0xc) != 0) {
      _sbcompress();
    }
    uVar6 = 1;
  }
  return uVar6;
}

