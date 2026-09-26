/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013358b */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0013358b(void)

{
  short sVar1;
  int iVar2;
  undefined4 unaff_EBX;
  int iVar3;
  int unaff_EBP;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  *(undefined4 *)(unaff_EBP + -0x110) = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x20);
  *(int *)(unaff_EBP + -0x114) =
       *(int *)(unaff_EBP + -0xf0) * *(int *)(*(int *)(unaff_EBP + 8) + 0x24);
  *(undefined4 *)(unaff_EBP + -0x118) = unaff_EBX;
  *(undefined4 *)(unaff_EBP + -0x11c) = *(undefined4 *)(*(int *)(unaff_EBP + -0xe8) + 0x70);
  do {
    iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(unaff_EBP + -0xec) + 0x24) + 0x128) + 0x20);
    if (*(int *)(unaff_EBP + -0x118) < iVar3) {
      iVar3 = *(int *)(unaff_EBP + -0x118);
    }
    *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x110);
    puVar4 = (undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0xec) + 0x30) + 0x40);
    puVar5 = (undefined4 *)(unaff_EBP + -0x9c);
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_EBP + -0x114);
    *(int *)(unaff_EBP + -0x74) = iVar3;
    *(int *)(unaff_EBP + -0x70) = iVar3;
    *(undefined4 *)(unaff_EBP + -0x78) = *(undefined4 *)(unaff_EBP + -0x114);
    iVar2 = _rfscall(*(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0xec) + 0x24) + 0x128),8,
                     _xdr_writeargs,unaff_EBP + -0x9c,_xdr_attrstat,unaff_EBP + -0xe4);
    if ((iVar2 == 0) && (iVar2 = *(int *)(unaff_EBP + -0xe4), iVar2 == 0x46)) {
      _btrash();
      _nfs_invalidate_caches(*(undefined4 *)(unaff_EBP + -0xec));
    }
    *(int *)(unaff_EBP + -0x118) = *(int *)(unaff_EBP + -0x118) - iVar3;
    *(int *)(unaff_EBP + -0x110) = *(int *)(unaff_EBP + -0x110) + iVar3;
    *(int *)(unaff_EBP + -0x114) = *(int *)(unaff_EBP + -0x114) + iVar3;
    if (iVar2 != 0) goto LAB_001336b7;
  } while (*(int *)(unaff_EBP + -0x118) != 0);
  _nfs_attrcache(*(undefined4 *)(unaff_EBP + -0xec));
LAB_001336b7:
  if (iVar2 == 0x1c) {
    _printf(s_NFS_write_error__on_host__s_remo_001dcabc);
  }
  else {
    if (iVar2 < 0x1d) {
      if (iVar2 == 0) goto LAB_0013372d;
    }
    else if (iVar2 == 0x45) goto LAB_0013372d;
    _printf(s_NFS_write_error__d_on_host__s_fh_001dcaf1,iVar2);
    FUN_00131898(*(int *)(*(int *)(unaff_EBP + -0xec) + 0x30) + 0x40);
    _printf(&DAT_001dcb13);
  }
LAB_0013372d:
  iVar3 = *(int *)(unaff_EBP + 8);
  sVar1 = (short)iVar2;
  *(short *)(iVar3 + 0x1c) = sVar1;
  iVar2 = (int)sVar1;
  if ((*(byte *)(iVar3 + 1) & 1) != 0) {
    *(short *)(*(int *)(unaff_EBP + -0xe8) + 0x62) = sVar1;
  }
  if ((iVar2 != 0) && (iVar2 != -0x62)) {
    **(byte **)(unaff_EBP + 8) = **(byte **)(unaff_EBP + 8) | 4;
    iVar3 = **(int **)(unaff_EBP + -0xec);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x34) == 0)) {
      *(int *)(iVar3 + 0x34) = iVar2;
    }
  }
  _biodone();
  return iVar2;
}

