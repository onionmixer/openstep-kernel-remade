/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001628f4 */

void FUN_001628f4(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  byte local_34 [20];
  undefined1 local_20 [9];
  char local_17;
  undefined4 local_14;
  undefined4 local_10;
  ushort local_a;
  ushort local_8;
  
  if (DAT_001e6448 != 0) {
    _kdp_panic(s_kdp_poll_001df3d9);
  }
  DAT_001e6440 = 0;
  _kdp_en_recv_pkt(&DAT_001e5e54,&DAT_001e6444,3);
  iVar3 = DAT_001e6440;
  iVar4 = DAT_001e6440;
  if ((DAT_001e6444 != 0) && (0x29 < DAT_001e6444)) {
    puVar1 = &DAT_001e5e54 + DAT_001e6440;
    iVar4 = DAT_001e6440 + 0xe;
    if ((ushort)(*(ushort *)((int)&DAT_001e5e60 + DAT_001e6440) >> 8 |
                *(ushort *)((int)&DAT_001e5e60 + DAT_001e6440) << 8) == 0x800) {
      puVar2 = &DAT_001e5e62 + DAT_001e6440;
      DAT_001e6440 = DAT_001e6440 + 0xe;
      _bcopy(puVar2,local_20,0x1c);
      _bcopy(&DAT_001e5e54 + DAT_001e6440,local_34,0x14);
      DAT_001e6440 = DAT_001e6440 + 0x1c;
      iVar4 = DAT_001e6440;
      if (((local_17 == '\x11') && ((local_34[0] & 0xf) < 6)) &&
         ((ushort)(local_a >> 8 | local_a << 8) == 0x473)) {
        if (DAT_001f66a8 == 0) {
          _bcopy(puVar1,&DAT_001f66c4,6);
          _adr = local_10;
          _bcopy(&DAT_001e5e5a + iVar3,&DAT_001f66d0,6);
          DAT_001f66cc = local_14;
        }
        DAT_001e6444 = (ushort)(local_8 >> 8 | local_8 << 8) - 8;
        DAT_001e6448 = 1;
        iVar4 = DAT_001e6440;
      }
    }
  }
  DAT_001e6440 = iVar4;
  return;
}

