/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013ef24 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0013ef24(void)

{
  ushort uVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int unaff_EBP;
  
  iVar6 = **(int **)(unaff_EBP + 0x10);
  if (iVar6 == 2) {
    uVar4 = _dirpref();
  }
  else {
    uVar4 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x48);
  }
  uVar1 = *(ushort *)(*(int *)(unaff_EBP + 0x10) + 4);
  uVar3 = *(undefined4 *)(&_vttoif_tab + iVar6 * 4);
  iVar5 = _ialloc(*(undefined4 *)(unaff_EBP + 8),uVar4);
  if (iVar5 == 0) {
    iVar6 = (int)*(char *)(DAT_001e875c + 0x68);
  }
  else {
    *(byte *)(iVar5 + 0x44) = *(byte *)(iVar5 + 0x44) | 0x46;
    *(ushort *)(iVar5 + 100) = (ushort)uVar3 | uVar1;
    if ((iVar6 - 3U < 2) || (iVar6 == 9)) {
      sVar2 = *(short *)(*(int *)(unaff_EBP + 0x10) + 0x38);
      *(int *)(iVar5 + 0x8c) = (int)sVar2;
      *(short *)(iVar5 + 0x38) = sVar2;
    }
    *(int *)(iVar5 + 0x34) = iVar6;
    if (iVar6 == 2) {
      *(undefined2 *)(iVar5 + 0x66) = 2;
    }
    else {
      *(undefined2 *)(iVar5 + 0x66) = 1;
    }
    if (*(short *)(*(int *)(iVar5 + 0x30) + 0x124) == 0) {
      *(undefined2 *)(iVar5 + 0x68) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
      *(undefined2 *)(iVar5 + 0x6a) = *(undefined2 *)(*(int *)(unaff_EBP + 8) + 0x6a);
    }
    else {
      *(undefined2 *)(iVar5 + 0xe4) = *(undefined2 *)(*(int *)(unaff_EBP + 8) + 0xe4);
      *(undefined2 *)(iVar5 + 0xe6) = *(undefined2 *)(*(int *)(unaff_EBP + 8) + 0xe6);
      *(undefined2 *)(iVar5 + 0x68) = *(undefined2 *)(*(int *)(iVar5 + 0x30) + 0x124);
      *(undefined2 *)(iVar5 + 0x6a) = _nogroup;
    }
    if ((*(byte *)(iVar5 + 0x65) & 4) != 0) {
      iVar7 = _groupmember();
      if (iVar7 == 0) {
        *(ushort *)(iVar5 + 100) = *(ushort *)(iVar5 + 100) & 0xfbff;
      }
    }
    _iupdat(iVar5);
    if (iVar6 == 2) {
      uVar4 = FUN_0013f0a4(iVar5);
      *(undefined4 *)(unaff_EBP + -4) = uVar4;
    }
    if (*(int *)(unaff_EBP + -4) == 0) {
      uVar1 = *(ushort *)(iVar5 + 0x44);
      *(ushort *)(iVar5 + 0x44) = uVar1 & 0xfffe;
      if ((uVar1 & 0x10) != 0) {
        *(ushort *)(iVar5 + 0x44) = uVar1 & 0xffee;
        _wakeup();
      }
      **(int **)(unaff_EBP + 0xc) = iVar5;
    }
    else {
      *(undefined2 *)(iVar5 + 0x66) = 0;
      *(byte *)(iVar5 + 0x44) = *(byte *)(iVar5 + 0x44) | 0x40;
      _iput();
    }
    iVar6 = *(int *)(unaff_EBP + -4);
  }
  return iVar6;
}

