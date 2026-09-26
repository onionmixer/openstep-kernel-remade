/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011ae9f */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0011ae9f(void)

{
  undefined4 uVar1;
  uint *puVar2;
  uint *unaff_EBX;
  int unaff_EBP;
  uint unaff_ESI;
  uint unaff_EDI;
  
LAB_0011aea2:
  (**(code **)(*(int *)(unaff_EBX[0x10] + 0x1c) + 0x54))();
  if ((unaff_ESI & 0x100) == 0) {
    _biowait();
    _brelse(unaff_EBX);
  }
  else if (unaff_EDI != 0) {
    *(byte *)unaff_EBX = (byte)*unaff_EBX | 0x80;
  }
  uVar1 = _splhigh();
  puVar2 = &_bfreelist;
  do {
    for (unaff_EBX = (uint *)puVar2[3]; unaff_EBX != puVar2; unaff_EBX = (uint *)unaff_EBX[3]) {
      if ((((*(short *)(unaff_EBP + -4) == -1) ||
           (*(ushort *)(unaff_EBP + -4) ==
            (*(ushort *)(unaff_EBP + -8) & *(ushort *)((int)unaff_EBX + 0x1e)))) &&
          ((*unaff_EBX & 0x200) != 0)) &&
         ((unaff_EBX[0x10] == *(uint *)(unaff_EBP + 8) || (*(uint *)(unaff_EBP + 8) == 0)))) {
        *unaff_EBX = *unaff_EBX | 0x100;
        _splbio();
        *(uint *)(unaff_EBX[4] + 0xc) = unaff_EBX[3];
        *(uint *)(unaff_EBX[3] + 0x10) = unaff_EBX[4];
        *(byte *)unaff_EBX = (byte)*unaff_EBX | 8;
        _splx();
        _splx(uVar1);
        unaff_ESI = *unaff_EBX;
        *unaff_EBX = unaff_ESI & 0xfffffdf8;
        unaff_EDI = unaff_ESI & 0x200;
        if (unaff_EDI == 0) {
          *(int *)(_active_u + 0x1a0) = *(int *)(_active_u + 0x1a0) + 1;
        }
        if ((int)unaff_EBX[6] < (int)unaff_EBX[5]) {
                    /* WARNING: Subroutine does not return */
          _panic(s_bwrite_001db583);
        }
        goto LAB_0011aea2;
      }
    }
    puVar2 = puVar2 + 0x11;
    if ((uint *)0x1e882b < puVar2) {
      _splx();
      return;
    }
  } while( true );
}

