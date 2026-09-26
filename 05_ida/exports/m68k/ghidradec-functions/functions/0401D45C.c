
undefined8 _rawintr(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 in_D0;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  sword *psVar6;
  int iVar7;
  char in_XF;
  char in_NF;
  char in_ZF;
  bool bVar8;
  char in_VF;
  bool bVar9;
  byte in_CF;
  bool bVar10;
  word wVar11;
  
  while( true ) {
    puVar2 = _rawintrq;
    wVar11 = (word)(byte)(in_XF << 4 | in_NF << 3 | in_ZF << 2 | in_VF << 1 | in_CF);
    puVar3 = (undefined4 *)CONCAT22((sword)((uint)in_D0 >> 0x10),wVar11);
    bVar8 = _rawintrq == (undefined4 *)0x0;
    bVar9 = false;
    bVar10 = false;
    iVar7 = 0;
    if (!bVar8) {
      puVar3 = (undefined4 *)_rawintrq[0x1f];
      if (puVar3 == (undefined4 *)0x0) {
        dword_40B5A68 = 0;
      }
      puVar1 = _rawintrq + 0x1f;
      _rawintrq = puVar3;
      *puVar1 = 0;
      bVar10 = dword_40B5A6C == 0;
      bVar9 = SBORROW4(dword_40B5A6C,1);
      iVar7 = dword_40B5A6C + -1;
      bVar8 = iVar7 == 0;
      dword_40B5A6C = iVar7;
    }
    if (puVar2 == (undefined4 *)0x0) break;
    psVar6 = (sword *)(puVar2[1] + (int)puVar2);
    iVar7 = 0;
    for (puVar3 = _rawcb; (undefined4 **)puVar3 != &_rawcb; puVar3 = (undefined4 *)*puVar3) {
      if ((((*psVar6 == *(sword *)(puVar3 + 0xb)) &&
           ((*(sword *)((int)puVar3 + 0x2e) == 0 || (*(sword *)((int)puVar3 + 0x2e) == psVar6[1]))))
          && (((*(byte *)((int)puVar3 + 0x4d) & 1) == 0 ||
              (iVar4 = _bcmp(puVar3 + 7,psVar6 + 2,0x10), iVar4 == 0)))) &&
         (((*(byte *)((int)puVar3 + 0x4d) & 2) == 0 ||
          (iVar4 = _bcmp(puVar3 + 3,psVar6 + 10,0x10), iVar4 == 0)))) {
        if ((iVar7 != 0) && (iVar4 = _m_copy(*puVar2,0,1000000000), iVar4 != 0)) {
          iVar5 = _sbappendaddr(iVar7 + 0x22,psVar6 + 10,iVar4,0);
          if (iVar5 == 0) {
            _m_freem(iVar4);
          }
          else {
            _sowakeup(iVar7,iVar7 + 0x22);
          }
        }
        iVar7 = puVar3[2];
      }
    }
    in_XF = '\0';
    if (iVar7 == 0) {
      in_NF = (int)puVar2 < 0;
      in_ZF = puVar2 == (undefined4 *)0x0;
      in_VF = '\0';
      in_CF = 0;
      in_D0 = _m_freem(puVar2);
    }
    else {
      iVar4 = _sbappendaddr(iVar7 + 0x22,psVar6 + 10,*puVar2,0);
      if (iVar4 == 0) {
        _m_freem(*puVar2);
      }
      else {
        _sowakeup(iVar7,iVar7 + 0x22);
      }
      in_NF = (int)puVar2 < 0;
      in_ZF = puVar2 == (undefined4 *)0x0;
      in_VF = '\0';
      in_CF = 0;
      in_D0 = _m_free(puVar2);
    }
  }
  return CONCAT44(CONCAT22((sword)((uint)puVar3 >> 0x10),
                           (word)(byte)(bVar10 << 4 | (iVar7 < 0) << 3 | bVar8 << 2 | bVar9 << 1 |
                                       bVar10)),(int)(sword)wVar11);
}
