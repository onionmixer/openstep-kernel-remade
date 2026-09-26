/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b020 */

void _binvalfree(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  undefined4 uVar5;
  
LAB_0011b026:
  uVar3 = _splhigh();
  puVar4 = &_bfreelist;
  do {
    for (puVar1 = (uint *)puVar4[3]; puVar1 != puVar4; puVar1 = (uint *)puVar1[3]) {
      if ((puVar1[0x10] == param_1) || (param_1 == 0)) {
        if ((*puVar1 & 0x200) == 0) {
          *puVar1 = *puVar1 | 0x10000;
          FUN_0011b26c(puVar1);
          _splx(uVar3);
        }
        else {
          puVar1[0xc] = (uint)_brelvp_wakeup;
          *puVar1 = *puVar1 | 0x200100;
          uVar5 = _splbio();
          *(uint *)(puVar1[4] + 0xc) = puVar1[3];
          *(uint *)(puVar1[3] + 0x10) = puVar1[4];
          *(byte *)puVar1 = (byte)*puVar1 | 8;
          _splx(uVar5);
          _splx(uVar3);
          uVar2 = *puVar1;
          *puVar1 = uVar2 & 0xfffffdf8;
          if ((uVar2 & 0x200) == 0) {
            *(int *)(_active_u + 0x1a0) = *(int *)(_active_u + 0x1a0) + 1;
          }
          if ((int)puVar1[6] < (int)puVar1[5]) {
                    /* WARNING: Subroutine does not return */
            _panic(s_bwrite_001db583);
          }
          (**(code **)(*(int *)(puVar1[0x10] + 0x1c) + 0x54))(puVar1);
          if ((uVar2 & 0x100) == 0) {
            _biowait(puVar1);
            _brelse(puVar1);
          }
          else if ((uVar2 & 0x200) != 0) {
            *(byte *)puVar1 = (byte)*puVar1 | 0x80;
          }
        }
        goto LAB_0011b026;
      }
    }
    puVar4 = puVar4 + 0x11;
    if ((uint *)0x1e882b < puVar4) {
      _splx(uVar3);
      return;
    }
  } while( true );
}

