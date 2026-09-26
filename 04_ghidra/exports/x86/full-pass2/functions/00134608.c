/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00134608 */

undefined4 _xdr_putrddirres(XDR *param_1,uint *param_2)

{
  uint *puVar1;
  ushort uVar2;
  uint uVar3;
  boolean_t bVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  boolean_t local_18;
  uint local_14;
  uint local_10;
  uint *local_c;
  boolean_t local_8;
  
  local_8 = 1;
  local_18 = 0;
  if ((param_1->x_op == XDR_ENCODE) && (bVar4 = _xdr_enum(param_1,(int *)(param_2 + 1)), bVar4 != 0)
     ) {
    if (param_2[1] == 0) {
      uVar6 = (*param_1->x_ops->x_getpostn)(param_1);
      local_14 = param_2[2];
      puVar8 = (uint *)param_2[5];
      for (uVar3 = param_2[3]; 0 < (int)uVar3; uVar3 = uVar3 - (ushort)*puVar1) {
        uVar2 = (ushort)puVar8[1];
        if ((uVar2 == 0) || ((uint)uVar2 < *(ushort *)((int)puVar8 + 6) + 9)) goto LAB_00134770;
        local_14 = local_14 + uVar2;
        if (*puVar8 != 0) {
          local_c = puVar8 + 2;
          local_10 = (uint)*(ushort *)((int)puVar8 + 6);
          bVar4 = _xdr_bool(param_1,&local_8);
          if ((((bVar4 == 0) || (bVar4 = _xdr_u_long(param_1,puVar8), bVar4 == 0)) ||
              (bVar4 = _xdr_bytes(param_1,(char **)&local_c,&local_10,0xff), bVar4 == 0)) ||
             (bVar4 = _xdr_u_long(param_1,&local_14), bVar4 == 0)) goto LAB_00134770;
          uVar7 = (*param_1->x_ops->x_getpostn)(param_1);
          if (*param_2 <= uVar7 - uVar6) {
            param_2[4] = 0;
            break;
          }
        }
        puVar1 = puVar8 + 1;
        puVar8 = (uint *)((int)puVar8 + (uint)(ushort)*puVar1);
      }
      bVar4 = _xdr_bool(param_1,&local_18);
      if ((bVar4 == 0) || (bVar4 = _xdr_bool(param_1,param_2 + 4), bVar4 == 0)) goto LAB_00134770;
    }
    uVar5 = 1;
  }
  else {
LAB_00134770:
    uVar5 = 0;
  }
  return uVar5;
}

