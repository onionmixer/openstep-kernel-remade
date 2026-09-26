/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013d53a */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0013d53a(void)

{
  int *piVar1;
  byte *pbVar2;
  byte bVar3;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  uint unaff_EDI;
  undefined4 uStack0000000c;
  
  bVar3 = (byte)*(undefined4 *)(unaff_EBP + -0x18) & 0x1f;
  pbVar2 = (byte *)(unaff_ESI + 0x2d4 + *(int *)(unaff_EBP + -0x14));
  *pbVar2 = *pbVar2 & ((byte)(-2 << bVar3) | (byte)(0xfffffffe >> 0x20 - bVar3));
  if (unaff_EDI < *(uint *)(unaff_ESI + 0x30)) {
    *(uint *)(unaff_ESI + 0x30) = unaff_EDI;
  }
  *(int *)(unaff_ESI + 0x20) = *(int *)(unaff_ESI + 0x20) + 1;
  *(int *)(unaff_EBX + 200) = *(int *)(unaff_EBX + 200) + 1;
  piVar1 = (int *)(*(int *)(unaff_EBX + 0x2d8 +
                           (*(int *)(unaff_EBP + -0x10) >>
                           ((byte)*(undefined4 *)(unaff_EBX + 0x70) & 0x1f)) * 4) + 8 +
                  (~*(uint *)(unaff_EBX + 0x6c) & *(uint *)(unaff_EBP + -0x10)) * 0x10);
  *piVar1 = *piVar1 + 1;
  if ((*(uint *)(unaff_EBP + 0x10) & 0xf000) == 0x4000) {
    *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + -1;
    *(int *)(unaff_EBX + 0xc0) = *(int *)(unaff_EBX + 0xc0) + -1;
    piVar1 = (int *)(*(int *)(unaff_EBX + 0x2d8 +
                             (*(int *)(unaff_EBP + -0x10) >>
                             ((byte)*(undefined4 *)(unaff_EBX + 0x70) & 0x1f)) * 4) +
                    (~*(uint *)(unaff_EBX + 0x6c) & *(uint *)(unaff_EBP + -0x10)) * 0x10);
    *piVar1 = *piVar1 + -1;
  }
  *(char *)(unaff_EBX + 0xd0) = *(char *)(unaff_EBX + 0xd0) + '\x01';
  uStack0000000c = 0x13d5c1;
  _byte_swap_cylgroup();
  uStack0000000c = *(undefined4 *)(unaff_EBP + -0xc);
  _bdwrite();
  if (((*(byte *)(unaff_EBX + 0xd3) & 2) != 0) &&
     (*(int *)(unaff_EBX + 0x90) < *(int *)(unaff_EBX + 200))) {
    uStack0000000c = 0x13d5f0;
    _wakeup();
    *(byte *)(unaff_EBX + 0xd3) = *(byte *)(unaff_EBX + 0xd3) & 0xfd;
  }
  return;
}

