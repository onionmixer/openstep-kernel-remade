/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011aad4 */

void _biodone(uint *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if ((*param_1 & 2) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_dup_biodone_001db60d);
  }
  uVar1 = *param_1;
  *param_1 = uVar1 | 2;
  if ((uVar1 & 0x200000) == 0) {
    if ((uVar1 & 0x100) == 0) {
      *param_1 = CONCAT31((int3)(uVar1 >> 8),(char)(uVar1 | 2)) & 0xffffffbf;
      _wakeup(param_1);
    }
    else {
      if ((uVar1 & 0x40) != 0) {
        _wakeup(param_1);
      }
      if ((_bfreelist & 0x40) != 0) {
        _bfreelist = _bfreelist & 0xffffffbf;
        _wakeup(&_bfreelist);
      }
      if ((*param_1 & 0x400200) == 0x400000) {
        *param_1 = *param_1 | 0x10000;
      }
      uVar1 = *param_1;
      if ((uVar1 & 4) != 0) {
        if ((uVar1 & 0x20000) == 0) {
          FUN_0011b26c(param_1);
        }
        else {
          *param_1 = uVar1 & 0xfffffffb;
        }
      }
      uVar2 = _splhigh();
      if ((int)param_1[6] < 1) {
        DAT_001e8838[4] = (uint)param_1;
        param_1[3] = (uint)DAT_001e8838;
        DAT_001e8838 = param_1;
        param_1[4] = (uint)&DAT_001e882c;
      }
      else {
        uVar1 = *param_1;
        if ((uVar1 & 0x10004) == 0) {
          if ((uVar1 & 0x20000) == 0) {
            puVar3 = &DAT_001e87a4;
            if ((char)uVar1 < '\0') {
              puVar3 = (undefined4 *)&DAT_001e87e8;
            }
          }
          else {
            puVar3 = &_bfreelist;
          }
          *(uint **)(puVar3[4] + 0xc) = param_1;
          param_1[4] = puVar3[4];
          puVar3[4] = param_1;
          param_1[3] = (uint)puVar3;
        }
        else {
          DAT_001e87f4[4] = (uint)param_1;
          param_1[3] = (uint)DAT_001e87f4;
          DAT_001e87f4 = param_1;
          param_1[4] = (uint)&DAT_001e87e8;
        }
      }
      *param_1 = *param_1 & 0xffbffe37;
      _splx(uVar2);
    }
  }
  else {
    *param_1 = uVar1 & 0xffdfffff | 2;
    (*(code *)param_1[0xc])(param_1);
  }
  return;
}

