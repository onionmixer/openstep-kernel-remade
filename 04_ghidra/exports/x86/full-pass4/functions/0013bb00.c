/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013bb00 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

byte * __analysis_fragment_0013bb00(void)

{
  byte *pbVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int unaff_EBX;
  size_t sVar8;
  int unaff_EBP;
  int unaff_ESI;
  char *pcStack00000010;
  
  if ((*(short *)(*(int *)(_active_u + 0x1c) + 2) == 0) ||
     (*(int *)(unaff_EBP + -0x10) =
           (*(int *)(unaff_EBX + 0xc4) << ((byte)*(undefined4 *)(unaff_EBX + 0x60) & 0x1f)) +
           *(int *)(unaff_EBX + 0xcc),
     iVar5 = (*(int *)(unaff_EBX + 0x28) * *(int *)(unaff_EBX + 0x3c)) / 100,
     *(int *)(unaff_EBP + -0x10) != iVar5 && -1 < *(int *)(unaff_EBP + -0x10) - iVar5)) {
    if (*(int *)(unaff_EBP + 0xc) == 0) {
      pcStack00000010 = *(char **)(unaff_EBX + 0x30);
      _printf(s_dev___0x_x__bsize____d__bprev_____001dda90);
                    /* WARNING: Subroutine does not return */
      _panic(s_realloccg__bad_bprev_001ddabd);
    }
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + 0xc) / *(int *)(unaff_EBX + 0xbc);
    pcStack00000010 = *(char **)(unaff_EBP + 0xc);
    iVar5 = _fragextend();
    *(int *)(unaff_EBP + -8) = iVar5;
    if (iVar5 != 0) {
      do {
        pcStack00000010 = *(char **)(*(int *)(unaff_EBP + 8) + 0x40);
        pbVar6 = (byte *)_bread();
        if ((*pbVar6 & 4) != 0) {
          _brelse();
          return (byte *)0x0;
        }
        pcStack00000010 = (char *)0x13bbdd;
        iVar5 = _brealloc();
      } while (iVar5 == 0);
      *pbVar6 = *pbVar6 | 2;
      sVar8 = *(int *)(unaff_EBP + 0x18) - *(int *)(unaff_EBP + 0x14);
      pcStack00000010 = (char *)0x13bbfc;
      _bzero((void *)(*(int *)(unaff_EBP + 0x14) + *(int *)(pbVar6 + 0x20)),sVar8);
      pcStack00000010 = (char *)(*(int *)(unaff_EBP + 8) + 0xc);
      iVar7 = (**(code **)(*(int *)(*(int *)(unaff_EBP + 8) + 0x28) + 0x80))();
      iVar5 = *(int *)(unaff_EBP + 8);
      piVar2 = (int *)(iVar5 + 0xcc);
      *piVar2 = *piVar2 + (int)sVar8 / iVar7;
      pbVar1 = (byte *)(iVar5 + 0x44);
      *pbVar1 = *pbVar1 | 0x42;
      return pbVar6;
    }
    if (*(int *)(unaff_EBX + 0x24) <= unaff_ESI) {
      unaff_ESI = 0;
    }
    if (*(int *)(unaff_EBX + 0x80) == 0) {
      *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(unaff_EBX + 0x30);
      if (((*(int *)(unaff_EBX + 0x3c) + -2) * *(int *)(unaff_EBX + 0x28)) / 100 <=
          *(int *)(unaff_EBX + 0xcc)) {
        pcStack00000010 = (char *)0x5;
        _log();
        *(undefined4 *)(unaff_EBX + 0x80) = 1;
      }
    }
    else if (*(int *)(unaff_EBX + 0x80) == 1) {
      *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(unaff_EBP + 0x18);
      if ((4 < *(int *)(unaff_EBX + 0x3c)) &&
         (*(int *)(unaff_EBX + 0xcc) <=
          (*(int *)(unaff_EBX + 0x3c) * *(int *)(unaff_EBX + 0x28)) / 200)) {
        pcStack00000010 = (char *)0x5;
        _log();
        *(undefined4 *)(unaff_EBX + 0x80) = 0;
      }
    }
    else {
      *(undefined4 *)(unaff_EBX + 0x80) = 1;
      *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(unaff_EBP + 0x18);
    }
    pcStack00000010 = (char *)unaff_ESI;
    iVar5 = _hashalloc();
    *(int *)(unaff_EBP + -8) = iVar5;
    if (0 < iVar5) {
      pcStack00000010 = *(char **)(*(int *)(unaff_EBP + 8) + 0x40);
      pbVar6 = (byte *)_bread();
      *(byte **)(unaff_EBP + -0x18) = pbVar6;
      if ((*pbVar6 & 4) != 0) {
        _brelse();
        return (byte *)0x0;
      }
      pcStack00000010 = *(char **)(*(int *)(unaff_EBP + 8) + 0x40);
      pbVar6 = (byte *)_getblk();
      _bcopy(*(void **)(*(int *)(unaff_EBP + -0x18) + 0x20),*(void **)(pbVar6 + 0x20),
             *(size_t *)(unaff_EBP + 0x14));
      sVar8 = *(int *)(unaff_EBP + 0x18) - *(int *)(unaff_EBP + 0x14);
      *(size_t *)(unaff_EBP + -0xc) = sVar8;
      _bzero((void *)(*(int *)(unaff_EBP + 0x14) + *(int *)(pbVar6 + 0x20)),sVar8);
      uVar3 = **(uint **)(unaff_EBP + -0x18);
      if ((uVar3 & 0x200) != 0) {
        **(uint **)(unaff_EBP + -0x18) = uVar3 & 0xfffffdff;
        *(int *)(_active_u + 0x1a0) = *(int *)(_active_u + 0x1a0) + -1;
      }
      _brelse();
      pcStack00000010 = *(char **)(unaff_EBP + 0xc);
      uVar4 = *(undefined4 *)(unaff_EBP + 8);
      _free_block();
      if (*(int *)(unaff_EBP + 0x18) < *(int *)(unaff_EBP + -4)) {
        pcStack00000010 = (char *)uVar4;
        _free_block();
      }
      iVar7 = (**(code **)(*(int *)(*(int *)(unaff_EBP + 8) + 0x28) + 0x80))();
      iVar5 = *(int *)(unaff_EBP + 8);
      piVar2 = (int *)(iVar5 + 0xcc);
      *piVar2 = *piVar2 + *(int *)(unaff_EBP + -0xc) / iVar7;
      pbVar1 = (byte *)(iVar5 + 0x44);
      *pbVar1 = *pbVar1 | 0x42;
      return pbVar6;
    }
  }
  if ((*(byte *)(unaff_EBX + 0xd3) & 1) == 0) {
    pcStack00000010 = (char *)0x13be34;
    _fserr();
  }
  *(byte *)(unaff_EBX + 0xd3) = *(byte *)(unaff_EBX + 0xd3) | 1;
  if ((*(byte *)(_active_u + 0x260) & 8) == 0) {
    pcStack00000010 = s__s___s_001dda0e;
    _uprintf();
  }
  if (*(int *)(DAT_001e875c + 0x6c) == 0) {
    *(int *)(DAT_001e875c + 0x6c) = unaff_EBX;
    *(undefined1 *)(DAT_001e875c + 0x70) = 1;
  }
  *(undefined1 *)(DAT_001e875c + 0x68) = 0x1c;
  return (byte *)0x0;
}

