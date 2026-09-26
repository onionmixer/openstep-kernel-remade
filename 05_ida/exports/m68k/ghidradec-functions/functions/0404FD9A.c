
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_404FD9A(undefined2 param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  undefined auStack_3a [6];
  byte abStack_34 [2];
  undefined2 uStack_32;
  sword sStack_30;
  undefined uStack_2c;
  word wStack_2a;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined uStack_18;
  undefined uStack_17;
  sword sStack_16;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined2 uStack_c;
  undefined2 uStack_a;
  sword sStack_8;
  undefined2 uStack_6;
  
  if (dword_40B3FBA == 0) {
    _kdp_panic(aKdpReply);
  }
  puVar1 = DAT_40b39ac + dword_40B3FB2;
  dword_40B3FB2 = dword_40B3FB2 + -0x1c;
  _bcopy(puVar1,&uStack_20,0x1c);
  uVar2 = uStack_14;
  uStack_1c = 0;
  uStack_20 = 0;
  uStack_18 = 0;
  uStack_17 = 0x11;
  sStack_16 = word_40B3FB8 + 8;
  uStack_14 = uStack_10;
  uStack_10 = uVar2;
  uStack_c = 0x473;
  uStack_a = param_1;
  uStack_6 = 0;
  sStack_8 = sStack_16;
  _bcopy(&uStack_20,unk_40B39C8 + dword_40B3FB2,0x1c);
  _bcopy(unk_40B39C8 + dword_40B3FB2,abStack_34,0x14);
  uStack_32 = word_40B3FB8 + 0x1c;
  sStack_30 = _ip_id;
  _ip_id = _ip_id + 1;
  abStack_34[0] = 0x45;
  uStack_2c = byte_40AEBC7;
  wStack_2a = 0;
  iVar7 = 0;
  iVar4 = 0;
  iVar6 = 4;
  pbVar5 = abStack_34;
  do {
    iVar7 = (uint)pbVar5[3] + (uint)pbVar5[1] + iVar7;
    iVar4 = (uint)pbVar5[2] + (uint)*pbVar5 + iVar4;
    pbVar5 = pbVar5 + 4;
    bVar8 = iVar6 != 0;
    iVar6 = iVar6 + -1;
  } while (bVar8);
  uVar3 = iVar7 + iVar4 * 0x100;
  uVar3 = (uVar3 >> 0x10) + (uVar3 & 0xffff);
  if (0xffff < uVar3) {
    uVar3 = (uint)(word)((sword)uVar3 + 1);
  }
  wStack_2a = ~(word)uVar3;
  _bcopy(abStack_34,unk_40B39C8 + dword_40B3FB2,0x14);
  iVar6 = dword_40B3FB2;
  _unk_40B3FB6 = _unk_40B3FB6 + 0x1c;
  iVar7 = (int)&dword_40B39BA + dword_40B3FB2;
  iVar4 = dword_40B3FB2 + 0x40b39c0;
  dword_40B3FB2 = dword_40B3FB2 + -0xe;
  _bcopy(iVar4,auStack_3a,6);
  _bcopy(iVar7,iVar4,6);
  _bcopy(auStack_3a,iVar7,6);
  *(undefined2 *)(&byte_40B39C6 + iVar6) = 0x800;
  _unk_40B3FB6 = _unk_40B3FB6 + 0xe;
  _bcopy(unk_40B39C8,unk_40B3FBE,0x5f6);
  _kdp_en_send_pkt(unk_40B39C8 + dword_40B3FB2,_unk_40B3FB6);
  byte_40B39C6 = byte_40B39C6 + '\x01';
  return;
}
