/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001341f8 */

undefined4 FUN_001341f8(XDR *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  boolean_t bVar3;
  int iVar4;
  
  if (param_1->x_op == XDR_ENCODE) {
    puVar2 = (uint *)(*param_1->x_ops->x_inline)(param_1,0x44);
    if (puVar2 != (uint *)0x0) {
      uVar1 = *param_2;
      *puVar2 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[1];
      puVar2[1] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[2];
      puVar2[2] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[3];
      puVar2[3] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[4];
      puVar2[4] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[5];
      puVar2[5] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[6];
      puVar2[6] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[7];
      puVar2[7] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[8];
      puVar2[8] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[9];
      puVar2[9] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[10];
      puVar2[10] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[0xb];
      puVar2[0xb] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[0xc];
      puVar2[0xc] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[0xd];
      puVar2[0xd] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[0xe];
      puVar2[0xe] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[0xf];
      puVar2[0xf] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = param_2[0x10];
      puVar2[0x10] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
      ;
      return 1;
    }
  }
  else {
    puVar2 = (uint *)(*param_1->x_ops->x_inline)(param_1,0x44);
    if (puVar2 != (uint *)0x0) {
      uVar1 = *puVar2;
      *param_2 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = puVar2[1];
      param_2[1] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = puVar2[2];
      param_2[2] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = puVar2[3];
      param_2[3] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = puVar2[4];
      param_2[4] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = puVar2[5];
      param_2[5] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = puVar2[6];
      param_2[6] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = puVar2[7];
      param_2[7] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = puVar2[8];
      param_2[8] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = puVar2[9];
      param_2[9] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = puVar2[10];
      param_2[10] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      uVar1 = puVar2[0xb];
      param_2[0xb] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
      ;
      uVar1 = puVar2[0xc];
      param_2[0xc] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
      ;
      uVar1 = puVar2[0xd];
      param_2[0xd] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
      ;
      uVar1 = puVar2[0xe];
      param_2[0xe] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
      ;
      uVar1 = puVar2[0xf];
      param_2[0xf] = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18
      ;
      uVar1 = puVar2[0x10];
      param_2[0x10] =
           uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
      return 1;
    }
  }
  bVar3 = _xdr_enum(param_1,(int *)param_2);
  if (((((bVar3 != 0) && (bVar3 = _xdr_u_long(param_1,param_2 + 1), bVar3 != 0)) &&
       (bVar3 = _xdr_u_long(param_1,param_2 + 2), bVar3 != 0)) &&
      ((((bVar3 = _xdr_u_long(param_1,param_2 + 3), bVar3 != 0 &&
         (bVar3 = _xdr_u_long(param_1,param_2 + 4), bVar3 != 0)) &&
        ((bVar3 = _xdr_u_long(param_1,param_2 + 5), bVar3 != 0 &&
         ((bVar3 = _xdr_u_long(param_1,param_2 + 6), bVar3 != 0 &&
          (bVar3 = _xdr_u_long(param_1,param_2 + 7), bVar3 != 0)))))) &&
       (bVar3 = _xdr_u_long(param_1,param_2 + 8), bVar3 != 0)))) &&
     ((((bVar3 = _xdr_u_long(param_1,param_2 + 9), bVar3 != 0 &&
        (bVar3 = _xdr_u_long(param_1,param_2 + 10), bVar3 != 0)) &&
       (iVar4 = FUN_00134924(param_1,param_2 + 0xb), iVar4 != 0)) &&
      ((iVar4 = FUN_00134924(param_1,param_2 + 0xd), iVar4 != 0 &&
       (iVar4 = FUN_00134924(param_1,param_2 + 0xf), iVar4 != 0)))))) {
    return 1;
  }
  return 0;
}

