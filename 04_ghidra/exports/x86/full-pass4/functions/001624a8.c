/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001624a8 */

void FUN_001624a8(undefined2 param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  uint uVar5;
  void *pvVar6;
  byte *pbVar7;
  int iVar8;
  byte *local_48;
  int local_44;
  undefined1 local_3c [8];
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
  
  if (DAT_001e6448 == 0) {
    _kdp_panic(s_kdp_reply_001df3c6);
  }
  pvVar3 = (void *)(DAT_001e6440 + 0x1e5e38);
  DAT_001e6440 = DAT_001e6440 + -0x1c;
  _bcopy(pvVar3,&local_20,0x1c);
  uVar2 = local_14;
  local_1c = 0;
  local_20 = 0;
  local_18 = 0;
  local_17 = 0x11;
  local_16 = (ushort)((short)DAT_001e6444 + 8U) >> 8 | ((short)DAT_001e6444 + 8U) * 0x100;
  local_14 = local_10;
  local_10 = uVar2;
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
  iVar4 = 5;
  local_44 = 0;
  iVar8 = 0;
  local_48 = (byte *)&local_32;
  pbVar7 = &local_34;
  do {
    iVar4 = iVar4 + -1;
    local_44 = local_44 + (uint)local_48[-1] + (uint)local_48[1];
    iVar8 = iVar8 + (uint)*pbVar7 + (uint)*local_48;
    local_48 = local_48 + 4;
    pbVar7 = pbVar7 + 4;
  } while (iVar4 != 0);
  uVar5 = iVar8 * 0x100 + local_44;
  uVar5 = (uVar5 & 0xffff) + (uVar5 >> 0x10);
  if (0xffff < uVar5) {
    uVar5 = (uint)(ushort)((short)uVar5 + 1);
  }
  local_2a = (ushort)~(ushort)uVar5 >> 8 | ~(ushort)uVar5 << 8;
  _bcopy(&local_34,&DAT_001e5e54 + DAT_001e6440,0x14);
  iVar4 = DAT_001e6440;
  DAT_001e6444 = DAT_001e6444 + 0x1c;
  pvVar6 = (void *)((int)&DAT_001e5e44 + DAT_001e6440 + 2);
  pvVar3 = (void *)((int)&DAT_001e5e4c + DAT_001e6440);
  DAT_001e6440 = DAT_001e6440 + -0xe;
  _bcopy(pvVar3,local_3c,6);
  _bcopy(pvVar6,pvVar3,6);
  _bcopy(local_3c,pvVar6,6);
  *(undefined2 *)(iVar4 + 0x1e5e52) = 8;
  DAT_001e6444 = DAT_001e6444 + 0xe;
  _bcopy(&DAT_001e5e54,&DAT_001e644c,0x5f8);
  _kdp_en_send_pkt(&DAT_001e5e54 + DAT_001e6440,DAT_001e6444);
  DAT_001e5e50 = DAT_001e5e50 + '\x01';
  return;
}

