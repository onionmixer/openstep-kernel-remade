/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011ac28 */

void _blkflush(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint *puVar6;
  undefined4 uVar7;
  
  uVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x80))(param_1);
  if ((int)uVar2 < 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_Couldn_t_determine_device_blocks_001db619);
  }
  iVar3 = param_2;
  if (param_2 < 0) {
    iVar3 = param_2 + 7;
  }
  uVar4 = (iVar3 >> 3) + param_1 & 0xf;
LAB_0011ac8f:
  puVar6 = (uint *)(&DAT_001e8884)[uVar4 * 3];
  do {
    if (puVar6 == (uint *)(&_bufhash + uVar4 * 0xc)) {
      return;
    }
    if ((((puVar6[0x10] == param_1) && ((*puVar6 & 0x10000) == 0)) && (puVar6[5] != 0)) &&
       (((int)puVar6[9] <= (int)((param_3 / uVar2 - 1) + param_2) &&
        (param_2 < (int)((int)puVar6[5] / (int)uVar2 + puVar6[9]))))) {
      uVar5 = _splhigh();
      uVar1 = *puVar6;
      if ((uVar1 & 8) != 0) {
        *puVar6 = uVar1 | 0x40;
        uVar7 = 0x15;
        _sleep((uint)puVar6);
        _splx(uVar5,puVar6,uVar7);
        goto LAB_0011ac8f;
      }
      if ((uVar1 & 0x200) != 0) break;
      _splx(uVar5);
    }
    puVar6 = (uint *)puVar6[1];
  } while( true );
  _splx(uVar5);
  uVar5 = _splbio();
  *(uint *)(puVar6[4] + 0xc) = puVar6[3];
  *(uint *)(puVar6[3] + 0x10) = puVar6[4];
  *(byte *)puVar6 = (byte)*puVar6 | 8;
  _splx(uVar5);
  uVar1 = *puVar6;
  *puVar6 = uVar1 & 0xfffffdf8;
  if ((uVar1 & 0x200) == 0) {
    *(int *)(_active_u + 0x1a0) = *(int *)(_active_u + 0x1a0) + 1;
  }
  if ((int)puVar6[6] < (int)puVar6[5]) {
                    /* WARNING: Subroutine does not return */
    _panic(s_bwrite_001db583);
  }
  (**(code **)(*(int *)(puVar6[0x10] + 0x1c) + 0x54))(puVar6);
  if ((uVar1 & 0x100) == 0) {
    _biowait(puVar6);
    _brelse(puVar6);
  }
  else if ((uVar1 & 0x200) != 0) {
    *(byte *)puVar6 = (byte)*puVar6 | 0x80;
  }
  goto LAB_0011ac8f;
}

