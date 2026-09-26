/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013f1d2 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0013f1d2(void)

{
  short *psVar1;
  short sVar2;
  ushort uVar3;
  undefined4 *puVar4;
  int iVar5;
  int unaff_EBX;
  int unaff_EBP;
  uint unaff_ESI;
  int iVar6;
  
  if (**(char **)(unaff_EBP + 0xc) == '.') {
    if (unaff_EBX == 1) {
      return 0x16;
    }
    if ((unaff_EBX == 2) && (*(char *)(*(int *)(unaff_EBP + 0xc) + 1) == '.')) {
      return 0x42;
    }
  }
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -8) = 0;
  while ((*(ushort *)(unaff_ESI + 0x44) & 1) != 0) {
    *(ushort *)(unaff_ESI + 0x44) = *(ushort *)(unaff_ESI + 0x44) | 0x10;
    _sleep(unaff_ESI);
  }
  *(byte *)(unaff_ESI + 0x44) = *(byte *)(unaff_ESI + 0x44) | 1;
  if ((*(ushort *)(unaff_ESI + 100) & 0xf000) == 0x4000) {
    iVar6 = _iaccess();
    if (iVar6 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 2;
      iVar6 = FUN_0013e5c8();
      if (iVar6 == 0) {
        if ((*(int *)(unaff_EBP + -0x18) == 0) ||
           ((*(int *)(unaff_EBP + 0x10) != 0 &&
            (*(int *)(unaff_EBP + 0x10) != *(int *)(unaff_EBP + -0x18))))) {
          iVar6 = 2;
        }
        else if (((((*(byte *)(unaff_ESI + 0x65) & 2) == 0) ||
                  (sVar2 = *(short *)(*(int *)(_active_u + 0x1c) + 2), sVar2 == 0)) ||
                 (*(short *)(unaff_ESI + 0x68) == sVar2)) ||
                (*(short *)(*(int *)(unaff_EBP + -0x18) + 0x68) == sVar2)) {
          iVar5 = *(int *)(unaff_EBP + -0x18);
          if (*(int *)(iVar5 + 0x18) == 0) {
            if (((*(int *)(unaff_EBP + 0x14) == 0) ||
                ((*(ushort *)(iVar5 + 100) & 0xf000) != 0x4000)) ||
               ((*(short *)(iVar5 + 0x66) == 2 && (iVar5 = FUN_0013f5e4(iVar5), iVar5 != 0)))) {
              _dnlc_remove(unaff_ESI + 0xc);
              puVar4 = *(undefined4 **)(unaff_EBP + -4);
              if ((*(uint *)(unaff_EBP + -0x10) & 0x3ff) == 0) {
                *puVar4 = 0;
              }
              else {
                psVar1 = (short *)((int)puVar4 + (4 - *(int *)(unaff_EBP + -0xc)));
                *psVar1 = *psVar1 + *(short *)(puVar4 + 1);
              }
              _byte_swap_dir_block_out();
              _bwrite(*(undefined4 *)(unaff_EBP + -8));
              *(undefined4 *)(unaff_EBP + -8) = 0;
              *(byte *)(unaff_ESI + 0x44) = *(byte *)(unaff_ESI + 0x44) | 0x42;
              iVar5 = *(int *)(unaff_EBP + -0x18);
              *(byte *)(iVar5 + 0x44) = *(byte *)(iVar5 + 0x44) | 0x40;
              if (*(char *)(DAT_001e875c + 0x68) == '\0') {
                if (0 < *(short *)(iVar5 + 0x66)) {
                  if ((*(int *)(unaff_EBP + 0x14) == 0) ||
                     ((*(ushort *)(iVar5 + 100) & 0xf000) != 0x4000)) {
                    psVar1 = (short *)(*(int *)(unaff_EBP + -0x18) + 0x66);
                    *psVar1 = *psVar1 + -1;
                  }
                  else {
                    *(short *)(iVar5 + 0x66) = *(short *)(iVar5 + 0x66) + -2;
                    *(short *)(unaff_ESI + 0x66) = *(short *)(unaff_ESI + 0x66) + -1;
                    _dnlc_remove(iVar5 + 0xc);
                    _dnlc_remove(*(int *)(unaff_EBP + -0x18) + 0xc,&DAT_001ddee6);
                    _itrunc(*(undefined4 *)(unaff_EBP + -0x18),0);
                  }
                }
              }
              else {
                iVar6 = (int)*(char *)(DAT_001e875c + 0x68);
              }
            }
            else {
              iVar6 = 0x42;
            }
          }
          else {
            iVar6 = 0x10;
          }
        }
        else {
          iVar6 = 1;
        }
      }
    }
  }
  else {
    iVar6 = 0x14;
  }
  if ((*(int *)(unaff_EBP + -0x18) != 0) &&
     (_iput(), *(short *)(*(int *)(unaff_EBP + -0x18) + 0x66) == 0)) {
    _vnode_uncache();
  }
  iVar5 = *(int *)(unaff_EBP + -8);
  if (iVar5 != 0) {
    _byte_swap_dir_block_out();
    _brelse(iVar5);
  }
  uVar3 = *(ushort *)(unaff_ESI + 0x44);
  *(ushort *)(unaff_ESI + 0x44) = uVar3 & 0xfffe;
  if ((uVar3 & 0x10) != 0) {
    *(ushort *)(unaff_ESI + 0x44) = uVar3 & 0xffee;
    _wakeup();
  }
  return iVar6;
}

