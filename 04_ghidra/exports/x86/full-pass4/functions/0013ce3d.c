/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013ce3d */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0013ce3d(void)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 uStack00000004;
  
  iVar3 = unaff_ESI;
  if (unaff_ESI < 0) {
    iVar3 = unaff_ESI + 7;
  }
  pbVar2 = (byte *)(unaff_EDI + 0x2d4 + (iVar3 >> 3));
  *pbVar2 = *pbVar2 | (byte)(1 << ((char)unaff_ESI + (char)(iVar3 >> 3) * -8 & 0x1fU));
  *(int *)(unaff_EDI + 0x20) = *(int *)(unaff_EDI + 0x20) + -1;
  *(int *)(unaff_EBX + 200) = *(int *)(unaff_EBX + 200) + -1;
  piVar1 = (int *)(*(int *)(unaff_EBX + 0x2d8 +
                           (*(int *)(unaff_EBP + 0xc) >>
                           ((byte)*(undefined4 *)(unaff_EBX + 0x70) & 0x1f)) * 4) + 8 +
                  (~*(uint *)(unaff_EBX + 0x6c) & *(uint *)(unaff_EBP + 0xc)) * 0x10);
  *piVar1 = *piVar1 + -1;
  *(char *)(unaff_EBX + 0xd0) = *(char *)(unaff_EBX + 0xd0) + '\x01';
  if ((*(uint *)(unaff_EBP + 0x14) & 0xf000) == 0x4000) {
    *(int *)(unaff_EDI + 0x18) = *(int *)(unaff_EDI + 0x18) + 1;
    *(int *)(unaff_EBX + 0xc0) = *(int *)(unaff_EBX + 0xc0) + 1;
    piVar1 = (int *)(*(int *)(unaff_EBX + 0x2d8 +
                             (*(int *)(unaff_EBP + 0xc) >>
                             ((byte)*(undefined4 *)(unaff_EBX + 0x70) & 0x1f)) * 4) +
                    (~*(uint *)(unaff_EBX + 0x6c) & *(uint *)(unaff_EBP + 0xc)) * 0x10);
    *piVar1 = *piVar1 + 1;
  }
  uStack00000004 = 0x13cecd;
  _byte_swap_cylgroup();
  uStack00000004 = *(undefined4 *)(unaff_EBP + -0xc);
  _bdwrite();
  return *(int *)(unaff_EBP + 0xc) * *(int *)(unaff_EBX + 0xb8) + unaff_ESI;
}

