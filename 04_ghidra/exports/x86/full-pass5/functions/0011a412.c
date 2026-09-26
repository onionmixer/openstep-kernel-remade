/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011a412 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

uint * __analysis_fragment_0011a412(void)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int unaff_EBP;
  uint *puStack00000010;
  
  iVar1 = *(int *)(unaff_EBP + 0xc);
  if (iVar1 < 0) {
    iVar1 = iVar1 + 7;
  }
  uVar2 = (iVar1 >> 3) + *(int *)(unaff_EBP + 8) & 0xf;
LAB_0011a432:
  do {
    for (puVar3 = (uint *)(&DAT_001e8884)[uVar2 * 3]; puVar3 != (uint *)(&_bufhash + uVar2 * 0xc);
        puVar3 = (uint *)puVar3[1]) {
      if (((puVar3[9] == *(uint *)(unaff_EBP + 0xc)) && (puVar3[0x10] == *(uint *)(unaff_EBP + 8)))
         && ((*puVar3 & 0x10000) == 0)) {
        puStack00000010 = (uint *)0x11a45f;
        puStack00000010 = (uint *)_splhigh();
        if ((*puVar3 & 8) == 0) {
          _splx();
          _splbio();
          *(uint *)(puVar3[4] + 0xc) = puVar3[3];
          *(uint *)(puVar3[3] + 0x10) = puVar3[4];
          *(byte *)puVar3 = (byte)*puVar3 | 8;
          _splx();
          puStack00000010 = *(uint **)(unaff_EBP + 0x10);
          if (((uint *)puVar3[5] == puStack00000010) || (iVar1 = _brealloc(), iVar1 != 0)) {
            *puVar3 = *puVar3 | 0x8000;
            return puVar3;
          }
        }
        else {
          *puVar3 = *puVar3 | 0x40;
          puStack00000010 = (uint *)0x15;
          _sleep((uint)puVar3);
          _splx();
        }
        goto LAB_0011a432;
      }
    }
    puStack00000010 = (uint *)0x11a4e0;
    puVar3 = (uint *)_getnewbuf();
    puStack00000010 = puVar3;
    _bfree();
    *(uint *)(puVar3[2] + 4) = puVar3[1];
    *(uint *)(puVar3[1] + 8) = puVar3[2];
    FUN_0011b244();
    *(undefined2 *)((int)puVar3 + 0x1e) = *(undefined2 *)(*(int *)(unaff_EBP + 8) + 0x2c);
    puVar3[9] = *(uint *)(unaff_EBP + 0xc);
    *(undefined2 *)(puVar3 + 7) = 0;
    puVar3[10] = 0;
    puVar3[1] = (&DAT_001e8884)[uVar2 * 3];
    puVar3[2] = (uint)(&_bufhash + uVar2 * 0xc);
    *(uint **)((&DAT_001e8884)[uVar2 * 3] + 8) = puVar3;
    (&DAT_001e8884)[uVar2 * 3] = puVar3;
    iVar1 = _brealloc();
    if (iVar1 != 0) {
      return puVar3;
    }
  } while( true );
}

