/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00125554 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _icmp_error(byte *param_1,uint param_2,undefined1 param_3,undefined4 param_4,
                undefined4 *param_5)

{
  undefined1 *puVar1;
  byte bVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  size_t local_c;
  size_t local_8;
  
  local_8 = (*param_1 & 0xf) * 4;
  if (param_2 != 5) {
    __icmpstat = __icmpstat + 1;
  }
  if ((*(ushort *)(param_1 + 6) & 0x9fff) == 0) {
    if (((((param_1[9] == 1) && (param_2 != 5)) && (bVar2 = param_1[local_8], bVar2 != 0)) &&
        ((bVar2 != 8 && (1 < (byte)(bVar2 - 0xd))))) &&
       ((1 < (byte)(bVar2 - 0xf) && (1 < (byte)(bVar2 - 0x11))))) {
      _DAT_001eab38 = _DAT_001eab38 + 1;
    }
    else if ((*(uint *)(param_1 + 0x10) & 0xf0) != 0xe0) {
      iVar3 = _in_broadcast(*(uint *)(param_1 + 0x10));
      if (iVar3 == 0) {
        iVar3 = _m_get(0,2);
        if (iVar3 != 0) {
          if (*(short *)(param_1 + 2) < 9) {
            local_c = (int)*(short *)(param_1 + 2) + local_8;
          }
          else {
            local_c = local_8 + 8;
          }
          *(short *)(iVar3 + 8) = (short)local_c + 8;
          iVar5 = 0x7c - (short)((short)local_c + 8);
          *(int *)(iVar3 + 4) = iVar5;
          puVar1 = (undefined1 *)(iVar5 + iVar3);
          if (0x12 < param_2) {
                    /* WARNING: Subroutine does not return */
            _panic(s_icmp_error_001dbce0);
          }
          *(int *)(&DAT_001eab3c + param_2 * 4) = *(int *)(&DAT_001eab3c + param_2 * 4) + 1;
          *puVar1 = (undefined1)param_2;
          if (param_2 == 5) {
            *(undefined4 *)(puVar1 + 4) = *param_5;
          }
          else {
            *(undefined4 *)(puVar1 + 4) = 0;
          }
          if (param_2 == 0xc) {
            puVar1[4] = param_3;
            param_3 = 0;
          }
          puVar1[1] = param_3;
          _bcopy(param_1,puVar1 + 8,local_c);
          *(ushort *)(puVar1 + 10) =
               (ushort)((short)local_8 + *(short *)(puVar1 + 10)) >> 8 |
               ((short)local_8 + *(short *)(puVar1 + 10)) * 0x100;
          if ((0x70 < local_8 + (int)*(short *)(iVar3 + 8)) &&
             (local_8 = 0x14, 0x70 < (int)*(short *)(iVar3 + 8) + 0x14U)) {
                    /* WARNING: Subroutine does not return */
            _panic(s_icmp_len_001dbceb);
          }
          *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) - local_8;
          *(short *)(iVar3 + 8) = *(short *)(iVar3 + 8) + (short)local_8;
          pvVar4 = (void *)(iVar3 + *(int *)(iVar3 + 4));
          _bcopy(param_1,pvVar4,local_8);
          *(undefined2 *)((int)pvVar4 + 2) = *(undefined2 *)(iVar3 + 8);
          *(undefined1 *)((int)pvVar4 + 9) = 1;
          _icmp_reflect(pvVar4,param_4);
        }
      }
    }
  }
  _m_freem((uint)param_1 & 0xffffff80);
  return;
}

