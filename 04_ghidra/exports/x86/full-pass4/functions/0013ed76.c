/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013ed76 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0013ed76(void)

{
  ushort uVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  int unaff_EBX;
  size_t sVar5;
  int unaff_EBP;
  undefined4 unaff_ESI;
  int *piVar6;
  
  iVar3 = _bmap();
  if ((iVar3 < 1) || (*(char *)(DAT_001e875c + 0x68) != '\0')) {
    iVar3 = 0x1c;
    if (*(char *)(DAT_001e875c + 0x68) != '\0') {
      iVar3 = (int)*(char *)(DAT_001e875c + 0x68);
    }
  }
  else {
    *(undefined4 *)(unaff_EBX + 0x6c) = unaff_ESI;
    *(byte *)(unaff_EBX + 0x44) = *(byte *)(unaff_EBX + 0x44) | 0x42;
    iVar3 = _blkatoff();
    *(int *)(*(int *)(unaff_EBP + 0xc) + 0xc) = iVar3;
    if (iVar3 == 0) {
      iVar3 = (int)*(char *)(DAT_001e875c + 0x68);
    }
    else {
      piVar6 = (int *)(*(uint **)(unaff_EBP + 0xc))[4];
      uVar4 = **(uint **)(unaff_EBP + 0xc);
      if (uVar4 == 0) {
        _bzero(piVar6,0x400);
        *(undefined2 *)(piVar6 + 1) = 0x400;
      }
      else {
        if (2 < uVar4) {
                    /* WARNING: Subroutine does not return */
          _panic(s_dirprepareentry__invalid_slot_st_001dde87);
        }
        *(int **)(unaff_EBP + -8) = piVar6;
        sVar5 = (*(ushort *)((int)piVar6 + 6) + 4 & 0xfffffffc) + 8;
        uVar4 = (uint)*(ushort *)(piVar6 + 1);
        *(uint *)(unaff_EBP + -4) = uVar4 - sVar5;
        *(uint *)(unaff_EBP + -0x10) = uVar4;
        if ((int)uVar4 < *(int *)(*(int *)(unaff_EBP + 0xc) + 8)) {
          do {
            *(int *)(unaff_EBP + -0xc) = *(int *)(unaff_EBP + -8) + *(int *)(unaff_EBP + -0x10);
            if (*piVar6 == 0) {
              *(int *)(unaff_EBP + -4) = *(int *)(unaff_EBP + -4) + sVar5;
            }
            else {
              *(short *)(piVar6 + 1) = (short)sVar5;
              piVar6 = (int *)((int)piVar6 + sVar5);
            }
            pvVar2 = *(void **)(unaff_EBP + -0xc);
            sVar5 = (*(ushort *)((int)pvVar2 + 6) + 4 & 0xfffffffc) + 8;
            uVar1 = *(ushort *)((int)pvVar2 + 4);
            *(int *)(unaff_EBP + -4) = *(int *)(unaff_EBP + -4) + (uVar1 - sVar5);
            *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + (uint)uVar1;
            _bcopy(pvVar2,piVar6,sVar5);
          } while (*(int *)(unaff_EBP + -0x10) < *(int *)(*(int *)(unaff_EBP + 0xc) + 8));
        }
        if (*piVar6 == 0) {
          *(short *)(piVar6 + 1) = *(short *)(unaff_EBP + -4) + (short)sVar5;
        }
        else {
          *(short *)(piVar6 + 1) = (short)sVar5;
          piVar6 = (int *)((int)piVar6 + sVar5);
          *(undefined2 *)(piVar6 + 1) = *(undefined2 *)(unaff_EBP + -4);
        }
      }
      *(int **)(*(int *)(unaff_EBP + 0xc) + 0x10) = piVar6;
      iVar3 = 0;
    }
  }
  return iVar3;
}

