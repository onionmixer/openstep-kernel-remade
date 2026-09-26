
undefined4 _sdopen(word param_1,byte param_2)

{
  uint uVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  
  uVar1 = (param_1 & 0xff) >> 3;
  bVar2 = (byte)(1 << (param_1 & 7));
  puVar3 = *(undefined4 **)(unk_40B4FDE + uVar1 * 4);
  if (uVar1 < 0x10) {
    _lock_write(&unk_40B504A);
    if ((puVar3 == (undefined4 *)0x0) || ((puVar3[2] & 0x81) != 0x80)) {
      if ((param_2 & 4) != 0) {
        _lock_done(&unk_40B504A);
        return 0x23;
      }
      if (dword_40B2088 == 0) {
        _lock_done(&unk_40B504A);
        return 6;
      }
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)sub_407E802(uVar1);
        *(undefined4 **)(unk_40B4FDE + uVar1 * 4) = puVar3;
        for (puVar4 = _sd_sdd; puVar4 < _sd_sdd + dword_40B2084 * 0xc2;
            puVar4 = (undefined *)((int)puVar4 + 0xc2)) {
          if (((*(char *)(*(int *)((int)puVar4 + 0xb2) + 1) < '\0') && (*(int *)puVar4 == 0)) &&
             (*(int *)((int)puVar4 + 4) == 0)) goto loc_407CF2C;
        }
        puVar4 = _sd_sdd;
        while( true ) {
          if (_sd_sdd + dword_40B2084 * 0xc2 <= puVar4) {
                    /* WARNING: Subroutine does not return */
            _panic(aSdopenNoRemova);
          }
          if (*(char *)(*(int *)((int)puVar4 + 0xb2) + 1) < '\0') break;
          puVar4 = (undefined *)((int)puVar4 + 0xc2);
        }
loc_407CF2C:
        *puVar3 = puVar4;
      }
      puVar3[2] = puVar3[2] | 0x40;
      _lock_done(&unk_40B504A);
      sub_407CCEE(puVar3,0);
      if ((*(byte *)((int)puVar3 + 0xb) & 1) != 0) {
        return 6;
      }
    }
    else {
      _lock_done(&unk_40B504A);
    }
    *(undefined2 *)((int)puVar3 + 0x16) = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 6);
    if (param_1 >> 8 == dword_40B502A) {
      *(byte *)((int)puVar3 + 0xd) = bVar2 | *(byte *)((int)puVar3 + 0xd);
    }
    else {
      *(byte *)(puVar3 + 3) = bVar2 | *(byte *)(puVar3 + 3);
    }
  }
  else if (uVar1 != 0x10) {
    return 6;
  }
  return 0;
}
