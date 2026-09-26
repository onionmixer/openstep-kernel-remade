/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013f107 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0013f107(void)

{
  byte *pbVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  iVar4 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(iVar4 + 0x6c) = 0x400;
  pbVar1 = (byte *)(iVar4 + 0x44);
  *pbVar1 = *pbVar1 | 0x42;
  iVar4 = *(int *)(unaff_EBP + 0xc);
  *(short *)(iVar4 + 0x66) = *(short *)(iVar4 + 0x66) + 1;
  *(byte *)(iVar4 + 0x44) = *(byte *)(iVar4 + 0x44) | 0x40;
  _iupdat(iVar4);
  iVar4 = _bread(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x40),
                 unaff_ESI << ((byte)*(undefined4 *)(unaff_EBX + 100) & 0x1f),
                 *(undefined4 *)(unaff_EBX + 0x34));
  cVar2 = *(char *)(DAT_001e875c + 0x68);
  if (cVar2 == '\0') {
    puVar3 = *(undefined4 **)(iVar4 + 0x20);
    puVar6 = &_mastertemplate;
    puVar7 = puVar3;
    for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    *puVar3 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x48);
    puVar3[3] = *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0x48);
    _byte_swap_dir_block_out();
    _bwrite(iVar4);
    cVar2 = *(char *)(DAT_001e875c + 0x68);
  }
  return (int)cVar2;
}

