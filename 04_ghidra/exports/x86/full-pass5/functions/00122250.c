/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00122250 */

undefined4
_arpresolve(uint param_1,void *param_2,uint param_3,uint param_4,uint *param_5,undefined1 *param_6,
           undefined4 *param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  int iVar5;
  ushort *puVar6;
  undefined2 local_34;
  undefined1 local_32 [6];
  uint local_2c [2];
  undefined2 local_24;
  undefined1 local_22 [6];
  uint local_1c [2];
  undefined2 local_14 [2];
  uint local_10;
  
  *param_7 = 0;
  if ((*param_5 & 0xf0) == 0xe0) {
    *param_6 = 1;
    param_6[1] = 0;
    param_6[2] = 0x5e;
    param_6[3] = *(byte *)((int)param_5 + 1) & 0x7f;
    param_6[4] = *(undefined1 *)((int)param_5 + 2);
    param_6[5] = *(undefined1 *)((int)param_5 + 3);
    uVar1 = 1;
  }
  else {
    iVar2 = _in_broadcast(*param_5);
    if (iVar2 == 0) {
      uVar1 = _in_lnaof(*param_5);
      if (*param_5 == param_3) {
        if (_useloopback == 0) {
          _bcopy(param_2,param_6,4);
          uVar1 = 1;
        }
        else {
          local_14[0] = 2;
          local_10 = *param_5;
          _looutput(_loifp,param_4,local_14);
          uVar1 = 0;
        }
      }
      else {
        uVar3 = _splimp();
        puVar4 = (uint *)(&_arptab + (*param_5 % 0x13) * 0xb4);
        iVar2 = 0;
        do {
          if ((*puVar4 == *param_5) && ((param_1 == 0 || (puVar4[4] == param_1)))) break;
          iVar2 = iVar2 + 1;
          puVar4 = puVar4 + 5;
        } while (iVar2 < 9);
        if (8 < iVar2) {
          puVar4 = (uint *)0x0;
        }
        if (puVar4 == (uint *)0x0) {
          if (*(char *)(param_1 + 0xc) < '\0') {
            _bcopy(param_2,param_6,3);
            param_6[3] = (byte)((uint)uVar1 >> 0x10) & 0x7f;
            param_6[4] = (char)((uint)uVar1 >> 8);
            param_6[5] = (char)uVar1;
            _splx(uVar3);
            uVar1 = 1;
          }
          else {
            iVar2 = _arptnew(param_1,param_5);
            if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
              _panic(s_arpresolve__no_free_entry_001db998);
            }
            *(uint *)(iVar2 + 0xc) = param_4;
            local_1c[0] = param_3;
            iVar2 = _m_get(0,1);
            if (iVar2 != 0) {
              *(undefined2 *)(iVar2 + 8) = 0x1c;
              local_34 = 0x806;
              *(undefined2 *)(iVar2 + 8) = 0x1c;
              _bcopy(&local_34,local_32 + (uint)DAT_001db968 * 2,2);
              _bcopy((void *)(DAT_001db969 + 0x1db96c + (uint)DAT_001db968),local_32,
                     (uint)DAT_001db968);
              iVar5 = 0x7c - *(short *)(iVar2 + 8);
              *(int *)(iVar2 + 4) = iVar5;
              puVar6 = (ushort *)(iVar5 + iVar2);
              _bcopy(&_arpethertempl,puVar6,(int)*(short *)(iVar2 + 8));
              _bcopy(param_2,puVar6 + 4,(uint)DAT_001db968);
              _bcopy(local_1c,(void *)((int)puVar6 + DAT_001db968 + 8),(uint)DAT_001db969);
              _bcopy(param_5,(void *)(DAT_001db969 + 8 + (uint)DAT_001db968 * 2 + (int)puVar6),
                     (uint)DAT_001db969);
              *puVar6 = *puVar6 >> 8 | *puVar6 << 8;
              puVar6[1] = puVar6[1] >> 8 | puVar6[1] << 8;
              puVar6[3] = puVar6[3] >> 8 | puVar6[3] << 8;
              local_34 = 0;
              _if_output_mbuf(param_1,iVar2,&local_34);
            }
            _splx(uVar3);
            uVar1 = 0;
          }
        }
        else {
          *(undefined1 *)((int)puVar4 + 10) = 0;
          if ((*(byte *)((int)puVar4 + 0xb) & 2) == 0) {
            if (puVar4[3] != 0) {
              _m_freem(puVar4[3]);
            }
            puVar4[3] = param_4;
            local_2c[0] = param_3;
            iVar2 = _m_get(0,1);
            if (iVar2 != 0) {
              *(undefined2 *)(iVar2 + 8) = 0x1c;
              local_24 = 0x806;
              *(undefined2 *)(iVar2 + 8) = 0x1c;
              _bcopy(&local_24,local_22 + (uint)DAT_001db968 * 2,2);
              _bcopy((void *)(DAT_001db969 + 0x1db96c + (uint)DAT_001db968),local_22,
                     (uint)DAT_001db968);
              iVar5 = 0x7c - *(short *)(iVar2 + 8);
              *(int *)(iVar2 + 4) = iVar5;
              puVar6 = (ushort *)(iVar5 + iVar2);
              _bcopy(&_arpethertempl,puVar6,(int)*(short *)(iVar2 + 8));
              _bcopy(param_2,puVar6 + 4,(uint)DAT_001db968);
              _bcopy(local_2c,(void *)((int)puVar6 + DAT_001db968 + 8),(uint)DAT_001db969);
              _bcopy(param_5,(void *)(DAT_001db969 + 8 + (uint)DAT_001db968 * 2 + (int)puVar6),
                     (uint)DAT_001db969);
              *puVar6 = *puVar6 >> 8 | *puVar6 << 8;
              puVar6[1] = puVar6[1] >> 8 | puVar6[1] << 8;
              puVar6[3] = puVar6[3] >> 8 | puVar6[3] << 8;
              local_24 = 0;
              _if_output_mbuf(param_1,iVar2,&local_24);
            }
            _splx(uVar3);
            uVar1 = 0;
          }
          else {
            _bcopy(puVar4 + 1,param_6,6);
            if ((*(byte *)((int)puVar4 + 0xb) & 0x10) != 0) {
              *param_7 = 1;
            }
            _splx(uVar3);
            uVar1 = 1;
          }
        }
      }
    }
    else {
      _bcopy((void *)(DAT_001db969 + 0x1db96c + (uint)DAT_001db968),param_6,(uint)DAT_001db968);
      uVar1 = 1;
    }
  }
  return uVar1;
}

