/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00135df4 */

undefined4
_pmap_kgetport(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 local_2c;
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
  
  local_26 = 0;
  local_2c = 0;
  if (DAT_001e59f0 == 0) {
    iVar2 = 0xf;
    puVar3 = &DAT_001e5a18;
    do {
      *puVar3 = 0xffff;
      puVar3 = puVar3 + -1;
      iVar2 = iVar2 + -1;
    } while (-1 < iVar2);
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
    iVar2 = (**(code **)piVar1[1])
                      (piVar1,3,_xdr_pmap,&local_14,_xdr_u_short,&local_26,DAT_001dd0d8,DAT_001dd0dc
                      );
    if (iVar2 == 0) {
      if (local_26 == 0) {
        local_2c = 0xffffffff;
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
  return local_2c;
}

