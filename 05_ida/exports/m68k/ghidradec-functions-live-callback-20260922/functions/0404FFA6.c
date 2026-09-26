
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_404FFA6(undefined2 param_1)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
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
  
  if (dword_40B3FBA != 0) {
    _kdp_panic(aKdpSend);
  }
  puVar1 = DAT_40b39ac + dword_40B3FB2;
  dword_40B3FB2 = dword_40B3FB2 + -0x1c;
  _bcopy(puVar1,&uStack_20,0x1c);
  uStack_1c = 0;
  uStack_20 = 0;
  uStack_18 = 0;
  uStack_17 = 0x11;
  sStack_16 = word_40B3FB8 + 8;
  uStack_14 = _adr;
  uStack_10 = dword_40C25BE;
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
  iVar6 = 0;
  iVar3 = 0;
  iVar5 = 4;
  pbVar4 = abStack_34;
  do {
    iVar6 = (uint)pbVar4[3] + (uint)pbVar4[1] + iVar6;
    iVar3 = (uint)pbVar4[2] + (uint)*pbVar4 + iVar3;
    pbVar4 = pbVar4 + 4;
    bVar7 = iVar5 != 0;
    iVar5 = iVar5 + -1;
  } while (bVar7);
  uVar2 = iVar6 + iVar3 * 0x100;
  uVar2 = (uVar2 >> 0x10) + (uVar2 & 0xffff);
  if (0xffff < uVar2) {
    uVar2 = (uint)(word)((sword)uVar2 + 1);
  }
  wStack_2a = ~(word)uVar2;
  _bcopy(abStack_34,unk_40B39C8 + dword_40B3FB2,0x14);
  iVar5 = dword_40B3FB2;
  _unk_40B3FB6 = _unk_40B3FB6 + 0x1c;
  iVar6 = (int)&dword_40B39BA + dword_40B3FB2;
  iVar3 = dword_40B3FB2 + 0x40b39c0;
  dword_40B3FB2 = dword_40B3FB2 + -0xe;
  _bcopy(&unk_40C25B8,iVar3,6);
  _bcopy(&unk_40C25C2,iVar6,6);
  *(undefined2 *)(&byte_40B39C6 + iVar5) = 0x800;
  _unk_40B3FB6 = _unk_40B3FB6 + 0xe;
  _kdp_en_send_pkt(unk_40B39C8 + dword_40B3FB2,_unk_40B3FB6);
  return;
}

