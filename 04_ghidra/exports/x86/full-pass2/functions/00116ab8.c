/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116ab8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _sbdrop(short *param_1,int param_2)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *local_8;
  
  puVar4 = *(undefined4 **)(param_1 + 6);
  local_8 = (undefined4 *)0x0;
  if (puVar4 == (undefined4 *)0x0) goto LAB_00116bc2;
  do {
    local_8 = (undefined4 *)puVar4[0x1f];
LAB_00116bc2:
    while( true ) {
      if (param_2 < 1) goto LAB_00116c83;
      if (puVar4 == (undefined4 *)0x0) break;
      sVar1 = *(short *)(puVar4 + 2);
      if (param_2 < sVar1) {
        *(short *)(puVar4 + 2) = sVar1 - (short)param_2;
        puVar4[1] = puVar4[1] + param_2;
        *param_1 = *param_1 - (short)param_2;
        goto LAB_00116c83;
      }
      param_2 = param_2 - sVar1;
      *param_1 = *param_1 - sVar1;
      sVar1 = param_1[2];
      param_1[2] = sVar1 + -0x80;
      if (0x7c < (uint)puVar4[1]) {
        param_1[2] = sVar1 + -0x480;
      }
      uVar3 = _splimp();
      if (*(short *)((int)puVar4 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_mfree_001db38b);
      }
      *(short *)(&DAT_001e917c + *(short *)((int)puVar4 + 10) * 2) =
           *(short *)(&DAT_001e917c + *(short *)((int)puVar4 + 10) * 2) + -1;
      _DAT_001e917c = _DAT_001e917c + 1;
      *(undefined2 *)((int)puVar4 + 10) = 0;
      if (0x7f < (uint)puVar4[1]) {
        _mclput(puVar4);
      }
      puVar2 = (undefined4 *)*puVar4;
      *puVar4 = _mfree;
      puVar4[1] = 0;
      puVar4[0x1f] = 0;
      _mfree = puVar4;
      _splx(uVar3);
      puVar4 = puVar2;
      if (_m_want != 0) {
        _m_want = 0;
        _wakeup(&_mfree);
      }
    }
    puVar4 = local_8;
    if (local_8 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_sbdrop_001db384);
    }
  } while( true );
LAB_00116c83:
  if (puVar4 == (undefined4 *)0x0) {
LAB_00116cbc:
    *(undefined4 **)(param_1 + 6) = local_8;
    return;
  }
  if (*(short *)(puVar4 + 2) != 0) {
    if (puVar4 != (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + 6) = puVar4;
      puVar4[0x1f] = local_8;
      return;
    }
    goto LAB_00116cbc;
  }
  *param_1 = *param_1;
  sVar1 = param_1[2];
  param_1[2] = sVar1 + -0x80;
  if (0x7c < (uint)puVar4[1]) {
    param_1[2] = sVar1 + -0x480;
  }
  uVar3 = _splimp();
  if (*(short *)((int)puVar4 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_mfree_001db391);
  }
  *(short *)(&DAT_001e917c + *(short *)((int)puVar4 + 10) * 2) =
       *(short *)(&DAT_001e917c + *(short *)((int)puVar4 + 10) * 2) + -1;
  _DAT_001e917c = _DAT_001e917c + 1;
  *(undefined2 *)((int)puVar4 + 10) = 0;
  if (0x7f < (uint)puVar4[1]) {
    _mclput(puVar4);
  }
  puVar2 = (undefined4 *)*puVar4;
  *puVar4 = _mfree;
  puVar4[1] = 0;
  puVar4[0x1f] = 0;
  _mfree = puVar4;
  _splx(uVar3);
  puVar4 = puVar2;
  if (_m_want != 0) {
    _m_want = 0;
    _wakeup(&_mfree);
  }
  goto LAB_00116c83;
}

