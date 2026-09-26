/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019c2de */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019c2de(void)

{
  undefined4 uVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined2 *puVar7;
  undefined4 *puVar8;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
LAB_0019c2e1:
  do {
    uVar1 = *(undefined4 *)(unaff_ESI + 0xb0);
    iVar4 = *(int *)(unaff_EBP + -8);
    uVar2 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) goto LAB_0019c358;
        puVar6 = *(undefined1 **)(unaff_EBP + -0xc);
        while (iVar4 = iVar4 + -1, iVar4 != -1) {
          *puVar6 = (char)uVar1;
          puVar6 = puVar6 + 1;
        }
      }
      else {
        puVar7 = *(undefined2 **)(unaff_EBP + -0xc);
        while (iVar4 = iVar4 + -1, iVar4 != -1) {
          *puVar7 = (short)uVar1;
          puVar7 = puVar7 + 1;
        }
      }
    }
    else {
      if (uVar2 != 4) {
LAB_0019c358:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
      }
      puVar8 = *(undefined4 **)(unaff_EBP + -0xc);
      while (iVar4 = iVar4 + -1, iVar4 != -1) {
        *puVar8 = uVar1;
        puVar8 = puVar8 + 1;
      }
    }
    *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 1;
    if (0xb < *(int *)(unaff_EBP + -0x2c)) {
      *(int *)(unaff_ESI + 0xe0) = unaff_ESI + 0xdd;
      iVar4 = 2;
      do {
        *(undefined1 *)(iVar4 + 0xdc + unaff_ESI) = 0;
        iVar4 = iVar4 + -1;
      } while (-1 < iVar4);
      *(undefined4 *)(unaff_ESI + 0xd8) = 0;
      if (*(int *)(unaff_ESI + 0x94) <= *(int *)(unaff_ESI + 0xa8)) {
        *(undefined4 *)(unaff_ESI + 0xa8) = 0;
        *(int *)(unaff_ESI + 0xa4) = *(int *)(unaff_ESI + 0xa4) + 1;
      }
      if (*(int *)(unaff_ESI + 0x9c) <= *(int *)(unaff_ESI + 0xa4)) {
        *(int *)(unaff_ESI + 0xa4) = *(int *)(unaff_ESI + 0x9c) + -1;
        uVar2 = *(uint *)(unaff_ESI + 0x1c);
        if (uVar2 < 4) {
          if (uVar2 < 2) {
            if (uVar2 != 1) goto LAB_0019c644;
            *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_ESI + 0x98);
          }
          else {
            *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_ESI + 0x98) * 2;
          }
        }
        else {
          if (uVar2 != 4) {
LAB_0019c644:
                    /* WARNING: Subroutine does not return */
            _panic(s_FBConsole_FBPutC__bogus_bitsPerP_001e47a3);
          }
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_ESI + 0x98) << 2;
        }
        iVar4 = *(int *)(unaff_ESI + 0x8c);
        iVar5 = *(int *)(unaff_ESI + 0x90) + 0xc;
        uVar2 = *(uint *)(unaff_ESI + 0x1c);
        if (uVar2 < 4) {
          if (uVar2 < 2) {
            if (uVar2 != 1) goto LAB_0019c6ac;
            *(int *)(unaff_EBP + -0x10) =
                 iVar5 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar4;
          }
          else {
            *(int *)(unaff_EBP + -0x10) =
                 iVar5 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar4 * 2;
          }
        }
        else {
          if (uVar2 != 4) {
LAB_0019c6ac:
                    /* WARNING: Subroutine does not return */
            _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
          }
          *(int *)(unaff_EBP + -0x10) =
               iVar5 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar4 * 4;
        }
        iVar4 = *(int *)(unaff_ESI + 0x8c);
        iVar5 = *(int *)(unaff_ESI + 0x90);
        uVar2 = *(uint *)(unaff_ESI + 0x1c);
        if (uVar2 < 4) {
          if (uVar2 < 2) {
            if (uVar2 != 1) goto LAB_0019c714;
            *(int *)(unaff_EBP + -0x14) =
                 iVar5 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar4;
          }
          else {
            *(int *)(unaff_EBP + -0x14) =
                 iVar5 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar4 * 2;
          }
        }
        else {
          if (uVar2 != 4) {
LAB_0019c714:
                    /* WARNING: Subroutine does not return */
            _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
          }
          *(int *)(unaff_EBP + -0x14) =
               iVar5 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar4 * 4;
        }
        iVar4 = 0xc;
        if (0xc < *(int *)(unaff_ESI + 0xa0)) {
          do {
            pvVar3 = *(void **)(unaff_EBP + -0x14);
            _memmove(pvVar3,*(void **)(unaff_EBP + -0x10),*(size_t *)(unaff_EBP + -0x18));
            iVar5 = *(int *)(unaff_ESI + 0x10);
            *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + iVar5;
            *(int *)(unaff_EBP + -0x14) = (int)pvVar3 + iVar5;
            iVar4 = iVar4 + 1;
          } while (iVar4 < *(int *)(unaff_ESI + 0xa0));
        }
        *(undefined4 *)(unaff_ESI + 0xa8) = 0;
        iVar4 = *(int *)(unaff_ESI + 0x8c);
        *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_ESI + 0x90) + *(int *)(unaff_ESI + 0xa4) * 0xc;
        *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_ESI + 0x98);
        *(undefined4 *)(unaff_EBP + -0x2c) = 0;
        do {
          iVar5 = *(int *)(unaff_EBP + -0x1c);
          *(int *)(unaff_EBP + -0x1c) = iVar5 + 1;
          uVar2 = *(uint *)(unaff_ESI + 0x1c);
          if (uVar2 < 4) {
            if (uVar2 < 2) {
              if (uVar2 != 1) goto LAB_0019c7e8;
              *(int *)(unaff_EBP + -0x24) =
                   iVar5 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar4;
            }
            else {
              *(int *)(unaff_EBP + -0x24) =
                   iVar5 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar4 * 2;
            }
          }
          else {
            if (uVar2 != 4) {
LAB_0019c7e8:
                    /* WARNING: Subroutine does not return */
              _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
            }
            *(int *)(unaff_EBP + -0x24) =
                 iVar5 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar4 * 4;
          }
          uVar1 = *(undefined4 *)(unaff_ESI + 0xb0);
          iVar5 = *(int *)(unaff_EBP + -0x20);
          uVar2 = *(uint *)(unaff_ESI + 0x1c);
          if (uVar2 < 4) {
            if (uVar2 < 2) {
              if (uVar2 != 1) goto LAB_0019c86c;
              puVar6 = *(undefined1 **)(unaff_EBP + -0x24);
              while (iVar5 = iVar5 + -1, iVar5 != -1) {
                *puVar6 = (char)uVar1;
                puVar6 = puVar6 + 1;
              }
            }
            else {
              puVar7 = *(undefined2 **)(unaff_EBP + -0x24);
              while (iVar5 = iVar5 + -1, iVar5 != -1) {
                *puVar7 = (short)uVar1;
                puVar7 = puVar7 + 1;
              }
            }
          }
          else {
            if (uVar2 != 4) {
LAB_0019c86c:
                    /* WARNING: Subroutine does not return */
              _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
            }
            puVar8 = *(undefined4 **)(unaff_EBP + -0x24);
            while (iVar5 = iVar5 + -1, iVar5 != -1) {
              *puVar8 = uVar1;
              puVar8 = puVar8 + 1;
            }
          }
          *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 1;
        } while (*(int *)(unaff_EBP + -0x2c) < 0xc);
      }
      FUN_0019ba18();
      return;
    }
    iVar4 = *(int *)(unaff_EBP + -4);
    *(int *)(unaff_EBP + -4) = iVar4 + 1;
    uVar2 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) {
LAB_0019c2d4:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        *(int *)(unaff_EBP + -0xc) =
             iVar4 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + unaff_EBX;
      }
      else {
        *(int *)(unaff_EBP + -0xc) =
             iVar4 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + unaff_EBX * 2;
      }
      goto LAB_0019c2e1;
    }
    if (uVar2 != 4) goto LAB_0019c2d4;
    *(int *)(unaff_EBP + -0xc) =
         iVar4 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + unaff_EBX * 4;
  } while( true );
}

