/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00122c2c */

uint * _arptnew(uint param_1,uint *param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  int local_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  if (DAT_001dba20 != 0) {
    DAT_001dba20 = 0;
    _timeout(0x1220b4);
  }
  puVar3 = (uint *)(&_arptab + (*param_2 % 0x13) * 0xb4);
  local_c = 0;
  puVar4 = puVar3;
  puVar5 = (uint *)0x0;
  do {
    puVar1 = puVar4;
    if (*(byte *)((int)puVar3 + 0xb) == 0) goto LAB_00122cfc;
    puVar1 = puVar5;
    if (((*(byte *)((int)puVar3 + 0xb) & 4) == 0) &&
       ((puVar5 == (uint *)0x0 || ((int)local_8 < (int)(uint)*(byte *)((int)puVar3 + 10))))) {
      local_8 = (uint)*(byte *)((int)puVar3 + 10);
      puVar1 = puVar3;
    }
    local_c = local_c + 1;
    puVar3 = puVar3 + 5;
    puVar4 = puVar4 + 5;
    puVar5 = puVar1;
  } while (local_c < 9);
  if (puVar1 == (uint *)0x0) {
    puVar1 = (uint *)0x0;
  }
  else {
    uVar2 = _splimp();
    if (puVar1[3] != 0) {
      _m_freem(puVar1[3]);
    }
    puVar1[3] = 0;
    *(undefined1 *)((int)puVar1 + 0xb) = 0;
    *(undefined1 *)((int)puVar1 + 10) = 0;
    *puVar1 = 0;
    _splx(uVar2);
LAB_00122cfc:
    *puVar1 = *param_2;
    *(undefined1 *)((int)puVar1 + 0xb) = 1;
    puVar1[4] = param_1;
  }
  return puVar1;
}

