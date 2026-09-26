/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00136250 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

boolean_t _xdr_callmsg(void)

{
  uint *puVar1;
  uint uVar2;
  int32_t *piVar3;
  boolean_t bVar4;
  int iVar5;
  __rpc_xdr *in_stack_00000004;
  uint *in_stack_00000008;
  
  if (in_stack_00000004->x_op == XDR_ENCODE) {
    if (400 < in_stack_00000008[8]) {
      return 0;
    }
    if (400 < in_stack_00000008[0xb]) {
      return 0;
    }
    puVar1 = (uint *)(*in_stack_00000004->x_ops->x_inline)
                               (in_stack_00000004,
                                (in_stack_00000008[8] + 3 & 0xfffffffc) + 0x28 +
                                (in_stack_00000008[0xb] + 3 & 0xfffffffc));
    if (puVar1 != (uint *)0x0) {
      uVar2 = *in_stack_00000008;
      *puVar1 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      uVar2 = in_stack_00000008[1];
      puVar1[1] = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      if (in_stack_00000008[1] != 0) {
        return 0;
      }
      uVar2 = in_stack_00000008[2];
      puVar1[2] = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      if (in_stack_00000008[2] != 2) {
        return 0;
      }
      uVar2 = in_stack_00000008[3];
      puVar1[3] = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      uVar2 = in_stack_00000008[4];
      puVar1[4] = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      uVar2 = in_stack_00000008[5];
      puVar1[5] = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      uVar2 = in_stack_00000008[6];
      puVar1[6] = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      uVar2 = in_stack_00000008[8];
      puVar1[7] = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      puVar1 = puVar1 + 8;
      if (in_stack_00000008[8] != 0) {
        _bcopy((void *)in_stack_00000008[7],puVar1,in_stack_00000008[8]);
        puVar1 = (uint *)((int)puVar1 + (in_stack_00000008[8] + 3 & 0xfffffffc));
      }
      uVar2 = in_stack_00000008[9];
      *puVar1 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      uVar2 = in_stack_00000008[0xb];
      puVar1[1] = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
      puVar1 = puVar1 + 2;
      uVar2 = in_stack_00000008[0xb];
      if (uVar2 == 0) {
        return 1;
      }
      piVar3 = (int32_t *)in_stack_00000008[10];
      goto LAB_00136509;
    }
  }
  if ((in_stack_00000004->x_op != XDR_DECODE) ||
     (puVar1 = (uint *)(*in_stack_00000004->x_ops->x_inline)(in_stack_00000004,0x20),
     puVar1 == (uint *)0x0)) {
    bVar4 = _xdr_u_long(in_stack_00000004,in_stack_00000008);
    if ((((bVar4 != 0) &&
         ((((bVar4 = _xdr_enum(in_stack_00000004,(int *)(in_stack_00000008 + 1)), bVar4 != 0 &&
            (in_stack_00000008[1] == 0)) &&
           (bVar4 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 2), bVar4 != 0)) &&
          ((in_stack_00000008[2] == 2 &&
           (bVar4 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 3), bVar4 != 0)))))) &&
        (bVar4 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 4), bVar4 != 0)) &&
       ((bVar4 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 5), bVar4 != 0 &&
        (iVar5 = _xdr_opaque_auth(in_stack_00000004,in_stack_00000008 + 6), iVar5 != 0)))) {
      bVar4 = _xdr_opaque_auth(in_stack_00000004,in_stack_00000008 + 9);
      return bVar4;
    }
    return 0;
  }
  uVar2 = *puVar1;
  *in_stack_00000008 =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  uVar2 = puVar1[1];
  uVar2 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  in_stack_00000008[1] = uVar2;
  if (uVar2 != 0) {
    return 0;
  }
  uVar2 = puVar1[2];
  uVar2 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  in_stack_00000008[2] = uVar2;
  if (uVar2 != 2) {
    return 0;
  }
  uVar2 = puVar1[3];
  in_stack_00000008[3] =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  uVar2 = puVar1[4];
  in_stack_00000008[4] =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  uVar2 = puVar1[5];
  in_stack_00000008[5] =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  uVar2 = puVar1[6];
  in_stack_00000008[6] =
       uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  uVar2 = puVar1[7];
  uVar2 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  in_stack_00000008[8] = uVar2;
  if (uVar2 != 0) {
    if (400 < uVar2) {
      return 0;
    }
    if (in_stack_00000008[7] == 0) {
      uVar2 = _kalloc(uVar2);
      in_stack_00000008[7] = uVar2;
    }
    piVar3 = (*in_stack_00000004->x_ops->x_inline)
                       (in_stack_00000004,in_stack_00000008[8] + 3 & 0xfffffffc);
    if (piVar3 == (int32_t *)0x0) {
      bVar4 = _xdr_opaque(in_stack_00000004,(char *)in_stack_00000008[7],in_stack_00000008[8]);
      if (bVar4 == 0) {
        return 0;
      }
    }
    else {
      _bcopy(piVar3,(void *)in_stack_00000008[7],in_stack_00000008[8]);
    }
  }
  puVar1 = (uint *)(*in_stack_00000004->x_ops->x_inline)(in_stack_00000004,8);
  if (puVar1 == (uint *)0x0) {
    bVar4 = _xdr_enum(in_stack_00000004,(int *)(in_stack_00000008 + 9));
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = _xdr_u_int(in_stack_00000004,in_stack_00000008 + 0xb);
    if (bVar4 == 0) {
      return 0;
    }
  }
  else {
    uVar2 = *puVar1;
    in_stack_00000008[9] =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
    uVar2 = puVar1[1];
    in_stack_00000008[0xb] =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  }
  uVar2 = in_stack_00000008[0xb];
  if (uVar2 == 0) {
    return 1;
  }
  if (400 < uVar2) {
    return 0;
  }
  if (in_stack_00000008[10] == 0) {
    uVar2 = _kalloc(uVar2);
    in_stack_00000008[10] = uVar2;
  }
  piVar3 = (*in_stack_00000004->x_ops->x_inline)
                     (in_stack_00000004,in_stack_00000008[0xb] + 3 & 0xfffffffc);
  if (piVar3 == (int32_t *)0x0) {
    bVar4 = _xdr_opaque(in_stack_00000004,(char *)in_stack_00000008[10],in_stack_00000008[0xb]);
    if (bVar4 == 0) {
      return 0;
    }
    return 1;
  }
  uVar2 = in_stack_00000008[0xb];
  puVar1 = (uint *)in_stack_00000008[10];
LAB_00136509:
  _bcopy(piVar3,puVar1,uVar2);
  return 1;
}

