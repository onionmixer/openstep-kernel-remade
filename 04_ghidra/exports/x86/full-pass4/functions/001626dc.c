/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001626dc */

void FUN_001626dc(undefined2 param_1)

{
  ushort uVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  byte *local_40;
  int local_3c;
  byte local_34;
  byte local_33;
  undefined2 local_32;
  ushort local_30;
  undefined1 local_2c;
  ushort local_2a;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  undefined1 local_17;
  ushort local_16;
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_c;
  undefined2 local_a;
  ushort local_8;
  undefined2 local_6;
  
  if (DAT_001e6448 != 0) {
    _kdp_panic(s_kdp_send_001df3d0);
  }
  pvVar2 = (void *)(DAT_001e6440 + 0x1e5e38);
  DAT_001e6440 = DAT_001e6440 + -0x1c;
  _bcopy(pvVar2,&local_20,0x1c);
  local_1c = 0;
  local_20 = 0;
  local_18 = 0;
  local_17 = 0x11;
  local_16 = (ushort)((short)DAT_001e6444 + 8U) >> 8 | ((short)DAT_001e6444 + 8U) * 0x100;
  local_14 = _adr;
  local_10 = DAT_001f66cc;
  local_c = 0x7304;
  local_a = param_1;
  local_6 = 0;
  local_8 = local_16;
  _bcopy(&local_20,&DAT_001e5e54 + DAT_001e6440,0x1c);
  _bcopy(&DAT_001e5e54 + DAT_001e6440,&local_34,0x14);
  uVar1 = _ip_id;
  local_32 = (ushort)((short)DAT_001e6444 + 0x1cU) >> 8 | ((short)DAT_001e6444 + 0x1cU) * 0x100;
  _ip_id = _ip_id + 1;
  local_30 = uVar1 >> 8 | uVar1 << 8;
  local_34 = 0x45;
  local_2c = _udp_ttl;
  iVar3 = 5;
  local_3c = 0;
  iVar6 = 0;
  local_40 = (byte *)&local_32;
  pbVar5 = &local_34;
  do {
    iVar3 = iVar3 + -1;
    local_3c = local_3c + (uint)local_40[-1] + (uint)local_40[1];
    iVar6 = iVar6 + (uint)*pbVar5 + (uint)*local_40;
    local_40 = local_40 + 4;
    pbVar5 = pbVar5 + 4;
  } while (iVar3 != 0);
  uVar4 = iVar6 * 0x100 + local_3c;
  uVar4 = (uVar4 & 0xffff) + (uVar4 >> 0x10);
  if (0xffff < uVar4) {
    uVar4 = (uint)(ushort)((short)uVar4 + 1);
  }
  local_2a = (ushort)~(ushort)uVar4 >> 8 | ~(ushort)uVar4 << 8;
  _bcopy(&local_34,&DAT_001e5e54 + DAT_001e6440,0x14);
  iVar6 = DAT_001e6440;
  DAT_001e6444 = DAT_001e6444 + 0x1c;
  iVar3 = DAT_001e6440 + 2;
  pvVar2 = (void *)((int)&DAT_001e5e4c + DAT_001e6440);
  DAT_001e6440 = DAT_001e6440 + -0xe;
  _bcopy(&DAT_001f66c4,pvVar2,6);
  _bcopy(&DAT_001f66d0,(void *)((int)&DAT_001e5e44 + iVar3),6);
  *(undefined2 *)(iVar6 + 0x1e5e52) = 8;
  DAT_001e6444 = DAT_001e6444 + 0xe;
  _kdp_en_send_pkt(&DAT_001e5e54 + DAT_001e6440,DAT_001e6444);
  return;
}

