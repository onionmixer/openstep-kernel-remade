
int _en_recv(uint *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined *puVar2;
  sword sVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  byte bVar9;
  int iVar8;
  undefined2 extraout_D1u;
  undefined2 extraout_D1u_00;
  undefined2 extraout_D1u_01;
  undefined2 extraout_D1u_02;
  undefined2 extraout_D1u_03;
  undefined2 extraout_D1u_04;
  undefined2 uVar10;
  undefined4 in_D1;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint *puVar14;
  
  iVar1 = _slot_id_bmap;
  iVar4 = _slot_id;
  uVar10 = (undefined2)((uint)in_D1 >> 0x10);
  puVar14 = (uint *)(_slot_id + 0x2000150);
  iVar12 = 0;
  if (param_4 != 0) {
    dword_40C8F3E = param_4;
  }
  if (((byte_40C9139 & 1) == 0) && (dword_40B55A4 == 0)) {
    _bcopy(&_etheraddr,&unk_40C8F38,6);
    _bytecopy(&_etheraddr,iVar1 + 0x2006008,6);
    *(undefined *)(iVar1 + 0x2006006) = 0x80;
    if (_dma_chip != 0x139) {
      *(undefined *)(iVar1 + 0x2006006) = 0;
    }
    *(undefined *)(iVar1 + 0x2006001) = 0;
    sub_408DBD2(iVar1 + 0x2006002,0xff);
    sub_408DBD2(iVar1 + 0x2006003,0);
    uVar5 = 0;
    if (_dma_chip != 0x139) {
      uVar5 = 0x80;
    }
    puVar2 = (undefined *)(iVar1 + 0x2006005);
    sub_408DBD2(puVar2,uVar5);
    if (_dma_chip == 0x139) {
      *(undefined *)(iVar1 + 0x2006006) = 0;
    }
    if (_dma_chip == 0x139) {
      *(byte *)(iVar1 + 0x2006004) = *(byte *)(iVar1 + 0x2006004) | 2;
      *puVar2 = 1;
      uVar10 = extraout_D1u;
    }
    else {
      sub_408DBD2(puVar2,0xa2);
      uVar10 = extraout_D1u_00;
    }
    dword_40B55A4 = 1;
  }
  if (dword_40B55A0 == 0) {
    _cache_flush(dword_40C8EFC,dword_40C8EFC + 0x242,0x40000);
    dword_40B55A8 = 0;
    dword_40B55A0 = 1;
    uVar10 = extraout_D1u_01;
  }
  if (_dma_chip != 0x139) {
    iVar13 = iVar1 + 0x2006002;
    iVar6 = sub_408DC16(iVar13);
    uVar10 = extraout_D1u_02;
    if ((iVar6 != 0) && (uVar7 = sub_408DB8A(iVar13), uVar10 = extraout_D1u_03, (uVar7 & 1) != 0)) {
      sub_408DBD2(iVar13,0xff);
      bVar9 = sub_408DB8A(iVar1 + 0x2006005);
      sub_408DBD2(iVar1 + 0x2006005,bVar9 | 0x80);
      uVar10 = extraout_D1u_04;
    }
  }
  if (dword_40B559C != 0) {
    uVar5 = CONCAT22(uVar10,_dma_chip);
    do {
      if (_dma_chip != 0x139) break;
    } while (*puVar14 == 0);
    if ((*puVar14 & 0x1000000) != 0) {
      return 0;
    }
    iVar1 = (&_en_pkt)[dword_40B55A8];
    if (*(sword *)(iVar1 + 0xc) == 0x800) {
      if (*(char *)(iVar1 + 0x17) == '\x11') {
        *param_1 = (uint)*(word *)(iVar1 + 0x22);
        if (_dma_chip == 0x139) {
          uVar7 = *(uint *)(iVar4 + 0x2004150) & 0x3fffffff;
        }
        else {
          uVar7 = (CONCAT31((int3)((uint)uVar5 >> 8),*(undefined *)(_slot_id_bmap + 0x2006007)) |
                  0xfffffff0) + *(int *)(iVar4 + 0x2004150);
        }
        iVar1 = (&_en_pkt)[dword_40B55A8];
        uVar11 = (uVar7 - iVar1) - 4;
        iVar13 = (&_en_pkt)[dword_40B55A8];
        if (_dma_chip == 0) {
          iVar6 = iVar13 + 1;
          iVar8 = _bcmp(iVar6,&unk_40C8F38,6);
          if ((iVar8 == 0) || (iVar8 = _bcmp(iVar6,&_etherbcastaddr,6), iVar8 == 0)) {
            uVar11 = (uVar7 - iVar1) - 5;
            iVar13 = iVar6;
          }
        }
        if ((((uVar11 < 0x5dd) && (param_2 <= (int)uVar11)) && (iVar12 = iVar13, uVar11 != 0)) &&
           (param_3 == 0)) {
          _bcopy(iVar13,&_en_pkt_hdr,0x2a);
        }
      }
    }
    else if (*(sword *)(iVar1 + 0xc) == 0x806) {
      _en_arp_input(iVar1);
    }
  }
  sVar3 = _dma_chip;
  uVar11 = dword_40B55A8 ^ 1;
  uVar7 = 0x940000;
  if (_dma_chip == 0x139) {
    uVar7 = 0x340000;
  }
  dword_40B55A8 = uVar11;
  *puVar14 = uVar7;
  *(undefined4 *)(iVar4 + 0x2004150) = (&_en_pkt)[uVar11];
  *(int *)(iVar4 + 0x2004154) = (&_en_pkt)[uVar11] + 0x5e0;
  if (sVar3 != 0x139) {
    *(undefined4 *)(iVar4 + 0x200411c) = (&_en_pkt)[uVar11];
  }
  *puVar14 = 0x50000;
  _cache_flush((&_en_pkt)[dword_40B55A8 ^ 1],(&_en_pkt)[dword_40B55A8 ^ 1] + 0x242,0x40000);
  dword_40B559C = 1;
  return iVar12;
}
