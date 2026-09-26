/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00135f10 */

int _getport_loop(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  char *pcVar5;
  int local_30;
  int local_2c;
  ushort local_26;
  undefined2 local_24;
  undefined2 uStack_22;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_30 = 0;
  while( true ) {
    local_26 = 0;
    local_2c = 0;
    if (DAT_001e59f0 == 0) {
      iVar3 = 0xf;
      puVar4 = &DAT_001e5a18;
      do {
        *puVar4 = 0xffff;
        puVar4 = puVar4 + -1;
        iVar3 = iVar3 + -1;
      } while (-1 < iVar3);
      DAT_001e59f0 = DAT_001e59f0 + 1;
    }
    local_20 = param_1[1];
    local_1c = param_1[2];
    local_18 = param_1[3];
    _local_24 = CONCAT22(0x6f00,(short)*param_1);
    piVar1 = (int *)_clntkudp_create(&local_24,100000,2,4,&DAT_001e59f0);
    if (piVar1 != (int *)0x0) {
      local_14 = param_2;
      local_10 = param_3;
      local_c = param_4;
      local_8 = 0;
      iVar3 = (**(code **)piVar1[1])
                        (piVar1,3,_xdr_pmap,&local_14,_xdr_u_short,&local_26,DAT_001dd0d8,
                         DAT_001dd0dc);
      if (iVar3 == 0) {
        if (local_26 == 0) {
          local_2c = -1;
        }
        else {
          *(ushort *)((int)param_1 + 2) = local_26 >> 8 | local_26 << 8;
        }
      }
      else {
        local_2c = 1;
      }
      (**(code **)(*(int *)(*piVar1 + 0x20) + 0x10))(*piVar1);
      (**(code **)(piVar1[1] + 0x10))(piVar1);
    }
    if (local_2c < 1) {
      if (local_30 == 0) {
        return local_2c;
      }
      pcVar5 = s_Portmapper_ok_001dd12f;
      goto LAB_001360af;
    }
    if ((*(byte *)(_active_threads + 0x17c) & 3) != 0) break;
    iVar3 = *_active_u;
    uVar2 = *(uint *)(iVar3 + 0x18) | *(uint *)(*(int *)(_active_threads + 0x84) + 0x7c);
    if ((uVar2 != 0) &&
       ((((*(byte *)(iVar3 + 0x28) & 0x10) != 0 ||
         ((~(*(uint *)(iVar3 + 0x20) | *(uint *)(iVar3 + 0x1c)) & uVar2) != 0)) &&
        (iVar3 = _issig(0), iVar3 != 0)))) break;
    local_30 = local_30 + 1;
    if (local_30 == 1) {
      _printf(s_Portmapper_not_responding__still_001dd106);
    }
  }
  pcVar5 = s_Portmapper_not_responding__givin_001dd0e0;
LAB_001360af:
  _printf(pcVar5);
  return local_2c;
}

