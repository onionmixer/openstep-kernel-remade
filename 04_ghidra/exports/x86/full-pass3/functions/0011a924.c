/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011a924 */

/* WARNING: Removing unreachable block (ram,0x0011aa02) */

uint * _getnewbuf(void)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  do {
    uVar3 = _splhigh();
    puVar4 = (undefined4 *)&DAT_001e87e8;
    do {
      if ((undefined4 *)puVar4[3] != puVar4) break;
      puVar4 = puVar4 + -0x11;
    } while (&_bfreelist < puVar4);
    if (puVar4 == &_bfreelist) {
      _bfreelist._0_1_ = (byte)_bfreelist | 0x40;
      uVar5 = 0x15;
      puVar4 = &_bfreelist;
      _sleep(0x1e8760);
      _splx(uVar3,puVar4,uVar5);
    }
    else {
      _splx(uVar3);
      puVar1 = (uint *)puVar4[3];
      uVar3 = _splbio();
      *(uint *)(puVar1[4] + 0xc) = puVar1[3];
      *(uint *)(puVar1[3] + 0x10) = puVar1[4];
      *(byte *)puVar1 = (byte)*puVar1 | 8;
      _splx(uVar3);
      uVar2 = *puVar1;
      if ((uVar2 & 0x200) == 0) {
        *puVar1 = 8;
        return puVar1;
      }
      *puVar1 = uVar2 & 0xfffffdf8 | 0x100;
      if ((uVar2 & 0x200) == 0) {
        *(int *)(_active_u + 0x1a0) = *(int *)(_active_u + 0x1a0) + 1;
      }
      if ((int)puVar1[6] < (int)puVar1[5]) {
                    /* WARNING: Subroutine does not return */
        _panic(s_bwrite_001db583);
      }
      (**(code **)(*(int *)(puVar1[0x10] + 0x1c) + 0x54))(puVar1);
      if ((uVar2 & 0x200) != 0) {
        *(byte *)puVar1 = (byte)*puVar1 | 0x80;
      }
    }
  } while( true );
}

