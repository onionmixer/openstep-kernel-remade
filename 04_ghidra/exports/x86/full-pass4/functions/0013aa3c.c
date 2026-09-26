/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013aa3c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0013aa3c(void)

{
  uint uVar1;
  byte bVar2;
  int *piVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int unaff_EBP;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -8) = 0;
  *(int *)(unaff_EBP + -0x40) = _page_size;
  iVar5 = _page_size;
  if (*(int *)(unaff_EBP + -0x40) == _page_size) {
    _DAT_001e5a60 = _DAT_001e5a60 + 1;
    iVar5 = *(int *)(unaff_ESI + 8);
    *(int *)(unaff_EBP + -0x50) = iVar5;
    *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(iVar5 + 0x1c);
    iVar5 = (**(code **)(*(int *)(unaff_EBP + -0x54) + 0x74))
                      (*(undefined4 *)(unaff_EBP + -0x50),*(undefined4 *)(unaff_EBP + 0xc));
    iVar6 = *(int *)(*(int *)(unaff_EBP + 8) + 0x30);
    bVar2 = *(byte *)(iVar6 + 0x79);
    *(byte *)(unaff_EBP + -0x54) = bVar2;
    *(byte *)(iVar6 + 0x79) = bVar2 & 0xfe;
    if ((*(byte *)(unaff_EBP + -0x54) & 2) == 0) {
      return iVar5;
    }
    *(byte *)(iVar6 + 0x79) = *(byte *)(unaff_EBP + -0x54) & 0xfc;
LAB_0013ac28:
    *(int *)(unaff_EBP + -0x50) = iVar6 + 0x79;
    _wakeup();
  }
  else {
    *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -4);
    *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -8);
    _DAT_001e5a34 = _DAT_001e5a34 + 1;
    if (*(int *)(unaff_ESI + 0x2c) == *(int *)(unaff_EBP + -4)) {
      _DAT_001e5a38 = _DAT_001e5a38 + 1;
      *(int *)(unaff_EBP + -0xc) = *(int *)(unaff_EBP + -8) + *(int *)(unaff_ESI + 0x24);
    }
    else if (*(int *)(unaff_ESI + 0x40) == *(int *)(unaff_EBP + -0x44)) {
      _DAT_001e5a3c = _DAT_001e5a3c + 1;
      *(int *)(unaff_EBP + -0xc) = *(int *)(unaff_EBP + -0x48) + *(int *)(unaff_ESI + 0x34);
    }
    else {
      if (*(char *)(unaff_ESI + 0x30) == '\0') {
LAB_0013abc4:
        *(undefined4 *)(unaff_ESI + 0x2c) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_ESI + 0x28);
        iVar5 = *(int *)(unaff_ESI + 8);
        *(int *)(unaff_EBP + -0x54) = iVar5;
        pcVar4 = *(code **)(*(int *)(iVar5 + 0x1c) + 0x74);
        *(code **)(unaff_EBP + -0x50) = pcVar4;
        iVar5 = (*pcVar4)(*(undefined4 *)(unaff_EBP + -0x54),unaff_EBP + -0x3c);
        if (iVar5 == 0) {
          *(undefined4 *)(unaff_ESI + 0x2c) = *(undefined4 *)(unaff_EBP + -0x44);
          *(int *)(unaff_EBP + -0xc) = *(int *)(unaff_EBP + -0x48) + *(int *)(unaff_ESI + 0x24);
        }
      }
      else {
        _DAT_001e5a40 = _DAT_001e5a40 + 1;
        piVar3 = *(int **)(unaff_ESI + 8);
        *(int **)(unaff_EBP + -0x54) = piVar3;
        *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(unaff_ESI + 0x28);
        uVar1 = iVar5 + *(int *)(unaff_ESI + 0x2c);
        iVar6 = *piVar3;
        *(int *)(unaff_EBP + -0x50) = iVar6;
        if (*(uint *)(iVar6 + 0x14) < uVar1) {
          *(uint *)(iVar6 + 0x14) = uVar1;
        }
        *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(*(int *)(unaff_EBP + -0x54) + 0x1c);
        iVar5 = (**(code **)(*(int *)(unaff_EBP + -0x50) + 0x78))
                          (*(undefined4 *)(unaff_EBP + -0x54),*(undefined4 *)(unaff_EBP + -0x4c),
                           iVar5);
        if (iVar5 == 0) {
          *(undefined1 *)(unaff_ESI + 0x30) = 0;
          goto LAB_0013abc4;
        }
        _printf(s_cannot_flush_input_cache__001dd80d);
      }
      if (iVar5 != 0) {
        iVar6 = *(int *)(*(int *)(unaff_EBP + 8) + 0x30);
        bVar2 = *(byte *)(iVar6 + 0x79);
        *(byte *)(unaff_EBP + -0x54) = bVar2;
        *(byte *)(iVar6 + 0x79) = bVar2 & 0xfe;
        if ((*(byte *)(unaff_EBP + -0x54) & 2) == 0) {
          return iVar5;
        }
        *(byte *)(iVar6 + 0x79) = *(byte *)(unaff_EBP + -0x54) & 0xfc;
        goto LAB_0013ac28;
      }
    }
    iVar5 = *(int *)(unaff_EBP + -4);
    if (iVar5 < 0) {
      iVar5 = iVar5 + 0x1fff;
    }
    *(int *)(unaff_EBP + -0x50) = iVar5 >> 0xd;
    _uncompress_data_to_phys
              (*(undefined4 *)(unaff_EBP + -0xc),*(undefined4 *)(unaff_EBP + -0x40),
               *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0x24),_page_size);
    iVar5 = *(int *)(*(int *)(unaff_EBP + 8) + 0x30);
    bVar2 = *(byte *)(iVar5 + 0x79);
    *(byte *)(iVar5 + 0x79) = bVar2 & 0xfe;
    if ((bVar2 & 2) != 0) {
      *(byte *)(iVar5 + 0x79) = bVar2 & 0xfc;
      _wakeup();
    }
    iVar5 = 0;
  }
  return iVar5;
}

