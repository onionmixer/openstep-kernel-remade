/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011a9e8 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

uint * __analysis_fragment_0011a9e8(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint *unaff_EBX;
  uint unaff_ESI;
  uint unaff_EDI;
  
LAB_0011a9eb:
  (**(code **)(*(int *)(unaff_EBX[0x10] + 0x1c) + 0x54))();
  if ((unaff_ESI & 0x100) == 0) {
    _biowait();
    _brelse(unaff_EBX);
  }
  else if (unaff_EDI != 0) {
    *(byte *)unaff_EBX = (byte)*unaff_EBX | 0x80;
  }
  do {
    uVar2 = _splhigh();
    puVar3 = (undefined4 *)&DAT_001e87e8;
    do {
      if ((undefined4 *)puVar3[3] != puVar3) break;
      puVar3 = puVar3 + -0x11;
    } while (&_bfreelist < puVar3);
    if (puVar3 != &_bfreelist) break;
    _bfreelist._0_1_ = (byte)_bfreelist | 0x40;
    _sleep(0x1e8760);
    _splx(uVar2);
  } while( true );
  _splx();
  unaff_EBX = (uint *)puVar3[3];
  uVar2 = _splbio();
  *(uint *)(unaff_EBX[4] + 0xc) = unaff_EBX[3];
  *(uint *)(unaff_EBX[3] + 0x10) = unaff_EBX[4];
  *(byte *)unaff_EBX = (byte)*unaff_EBX | 8;
  _splx(uVar2);
  uVar1 = *unaff_EBX;
  if ((uVar1 & 0x200) == 0) {
    *unaff_EBX = 8;
    return unaff_EBX;
  }
  unaff_ESI = uVar1 | 0x100;
  *unaff_EBX = uVar1 & 0xfffffdf8 | 0x100;
  unaff_EDI = uVar1 & 0x200;
  if (unaff_EDI == 0) {
    *(int *)(_active_u + 0x1a0) = *(int *)(_active_u + 0x1a0) + 1;
  }
  if ((int)unaff_EBX[6] < (int)unaff_EBX[5]) {
                    /* WARNING: Subroutine does not return */
    _panic(s_bwrite_001db583);
  }
  goto LAB_0011a9eb;
}

