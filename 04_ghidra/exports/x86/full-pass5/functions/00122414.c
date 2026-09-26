/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00122414 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00122414(void)

{
  int iVar1;
  int unaff_EBX;
  int iVar2;
  ushort *puVar3;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBX + 0xc) = *(undefined4 *)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 0x10);
  iVar1 = _m_get(0);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 8) = 0x1c;
    *(undefined2 *)(unaff_EBP + -0x30) = 0x806;
    *(undefined2 *)(iVar1 + 8) = 0x1c;
    *(void **)(unaff_EBP + -0x38) = (void *)(unaff_EBP + -0x30);
    _bcopy((void *)(unaff_EBP + -0x30),(void *)(unaff_EBP + -0x2e + (uint)DAT_001db968 * 2),2);
    _bcopy((void *)(DAT_001db969 + 0x1db96c + (uint)DAT_001db968),(void *)(unaff_EBP + -0x2e),
           (uint)DAT_001db968);
    iVar2 = 0x7c - *(short *)(iVar1 + 8);
    *(int *)(iVar1 + 4) = iVar2;
    puVar3 = (ushort *)(iVar2 + iVar1);
    _bcopy(&_arpethertempl,puVar3,(int)*(short *)(iVar1 + 8));
    _bcopy(*(void **)(unaff_EBP + 0xc),puVar3 + 4,(uint)DAT_001db968);
    _bcopy((void *)(unaff_EBP + -0x18),(void *)((int)puVar3 + DAT_001db968 + 8),(uint)DAT_001db969);
    _bcopy(*(void **)(unaff_EBP + 0x18),
           (void *)(DAT_001db969 + 8 + (uint)DAT_001db968 * 2 + (int)puVar3),(uint)DAT_001db969);
    *puVar3 = *puVar3 >> 8 | *puVar3 << 8;
    puVar3[1] = puVar3[1] >> 8 | puVar3[1] << 8;
    puVar3[3] = puVar3[3] >> 8 | puVar3[3] << 8;
    *(undefined2 *)(unaff_EBP + -0x30) = 0;
    _if_output_mbuf(*(undefined4 *)(unaff_EBP + 8),iVar1);
  }
  _splx();
  return 0;
}

