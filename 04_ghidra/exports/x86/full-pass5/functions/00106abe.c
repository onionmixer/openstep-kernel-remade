/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00106abe */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00106abe(void)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_EBX + 8) = _freeproc;
  _freeproc = *(undefined4 *)(unaff_EBX + 8);
  *(undefined1 *)(unaff_EBX + 0x13) = 4;
  *(undefined4 *)(unaff_EBX + 0x60) = 0;
  *(undefined4 *)(unaff_EBX + 0x5c) = 0;
  *(uint *)(unaff_EBX + 0x28) =
       CONCAT31((uint3)((uint)*(undefined4 *)(unaff_ESI + 0x28) >> 8) & 0x21080,1);
  *(undefined2 *)(unaff_EBX + 0x2c) = *(undefined2 *)(unaff_ESI + 0x2c);
  *(uint *)(unaff_EBX + 0x28) =
       *(uint *)(unaff_EBX + 0x28) | *(uint *)(unaff_ESI + 0x28) & 0x40000000;
  *(byte *)(unaff_EBX + 0x16) = *(byte *)(unaff_EBX + 0x16) & 0xfd | *(byte *)(unaff_ESI + 0x16) & 2
  ;
  iVar3 = _get_posix_proc();
  *(int *)(unaff_EBP + -0x10) = iVar3;
  *(undefined2 *)(*(int *)(unaff_EBP + 0x10) + 4) = *(undefined2 *)(iVar3 + 4);
  *(undefined2 *)(*(int *)(unaff_EBP + 0x10) + 6) = *(undefined2 *)(*(int *)(unaff_EBP + -0x10) + 6)
  ;
  *(undefined2 *)(*(int *)(unaff_EBP + 0x10) + 8) = *(undefined2 *)(*(int *)(unaff_EBP + -0x10) + 8)
  ;
  iVar3 = *(int *)(unaff_EBP + 0x10);
  *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x10);
  *(byte *)(iVar3 + 0x18) = *(byte *)(iVar3 + 0x18) & 0xfc;
  *(undefined4 *)(iVar3 + 0x14) = 0;
  *(undefined2 *)(unaff_EBX + 0x2e) = *(undefined2 *)(unaff_ESI + 0x2e);
  *(undefined1 *)(unaff_EBX + 0x15) = *(undefined1 *)(unaff_ESI + 0x15);
  *(undefined2 *)(unaff_EBX + 0x30) = **(undefined2 **)(unaff_EBP + 0x10);
  *(undefined2 *)(unaff_EBX + 0x32) = *(undefined2 *)(unaff_ESI + 0x30);
  *(int *)(unaff_EBX + 0x44) = unaff_ESI;
  *(undefined4 *)(unaff_EBX + 0x4c) = *(undefined4 *)(unaff_ESI + 0x48);
  if (*(int *)(unaff_ESI + 0x48) != 0) {
    *(int *)(*(int *)(unaff_ESI + 0x48) + 0x50) = unaff_EBX;
  }
  *(undefined4 *)(unaff_EBX + 0x50) = 0;
  *(undefined4 *)(unaff_EBX + 0x48) = 0;
  *(int *)(unaff_ESI + 0x48) = unaff_EBX;
  *(undefined1 *)(unaff_EBX + 0x14) = 0;
  *(undefined1 *)(unaff_EBX + 0x12) = 0;
  *(undefined4 *)(unaff_EBX + 0x1c) = *(undefined4 *)(unaff_ESI + 0x1c);
  *(undefined4 *)(unaff_EBX + 0x24) = *(undefined4 *)(unaff_ESI + 0x24);
  *(undefined4 *)(unaff_EBX + 0x20) = *(undefined4 *)(unaff_ESI + 0x20);
  *(undefined4 *)(unaff_EBX + 0x7c) = 0;
  *(undefined4 *)(unaff_EBX + 0x80) = 0;
  *(undefined2 *)(unaff_EBX + 0x34) = 0;
  *(undefined4 *)(unaff_EBX + 0x18) = 0;
  *(undefined1 *)(unaff_EBX + 0x17) = 0;
  *(byte *)(unaff_EBX + 0x16) = *(byte *)(unaff_EBX + 0x16) & 0xfe;
  _pidhash_enter();
  iVar3 = *(int *)(*(int *)(unaff_EBP + -4) + 0x160);
  if (iVar3 != 0) {
    psVar1 = (short *)(iVar3 + 6);
    *psVar1 = *psVar1 + 1;
  }
  iVar3 = *(int *)(*(int *)(unaff_EBP + -4) + 0x164);
  if (iVar3 != 0) {
    psVar1 = (short *)(iVar3 + 6);
    *psVar1 = *psVar1 + 1;
  }
  psVar1 = *(short **)(*(int *)(unaff_EBP + -4) + 0x1c);
  *psVar1 = *psVar1 + 1;
  *(uint *)(unaff_ESI + 0x28) = *(uint *)(unaff_ESI + 0x28) | 0x100;
  *(undefined4 *)(unaff_EBX + 0x70) = 0;
  *(undefined4 *)(unaff_EBX + 0x74) = 0;
  *(undefined4 *)(unaff_EBX + 0x78) = 0;
  uVar4 = _procdup();
  *(undefined4 *)(unaff_EBP + -8) = uVar4;
  *(undefined4 *)(unaff_EBP + -0xc) = 0;
  while (*(int *)(unaff_EBP + -0xc) <= *(int *)(*(int *)(*(int *)(unaff_EBX + 0x68) + 0x38) + 0x158)
        ) {
    iVar3 = *(int *)(*(int *)(*(int *)(unaff_EBX + 0x68) + 0x38) + 0x150);
    iVar2 = *(int *)(iVar3 + *(int *)(unaff_EBP + -0xc) * 4);
    if (iVar2 != 0) {
      if (iVar2 == -0x10000) {
        *(undefined4 *)(iVar3 + *(int *)(unaff_EBP + -0xc) * 4) = 0;
      }
      else {
        *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + 1;
      }
    }
    *(int *)(unaff_EBP + -0xc) = *(int *)(unaff_EBP + -0xc) + 1;
  }
  _lock_init(*(int *)(*(int *)(unaff_EBX + 0x68) + 0x38) + 0x20);
  _uarea_init(*(undefined4 *)(unaff_EBP + -8));
  *(undefined4 *)(*(int *)(unaff_EBP + 0x10) + 0xc) =
       *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0xc);
  *(int *)(*(int *)(unaff_EBP + -0x10) + 0xc) = unaff_EBX;
  *(int *)(unaff_EBX + 8) = _allproc;
  *(int *)(_allproc + 0xc) = unaff_EBX + 8;
  *(int **)(unaff_EBX + 0xc) = &_allproc;
  _allproc = unaff_EBX;
  *(undefined1 *)(unaff_EBX + 0x13) = 3;
  _spl0();
  *(uint *)(unaff_ESI + 0x28) = *(uint *)(unaff_ESI + 0x28) & 0xfffffeff;
  return *(undefined4 *)(unaff_EBP + -8);
}

