/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00136720 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

boolean_t _xdr_replymsg(void)

{
  uint *puVar1;
  boolean_t bVar2;
  uint uVar3;
  int32_t *piVar4;
  __rpc_xdr *in_stack_00000004;
  uint *in_stack_00000008;
  
  if ((((in_stack_00000004->x_op == XDR_ENCODE) && (in_stack_00000008[2] == 0)) &&
      (in_stack_00000008[1] == 1)) &&
     (puVar1 = (uint *)(*in_stack_00000004->x_ops->x_inline)
                                 (in_stack_00000004,in_stack_00000008[5] + 0x18),
     puVar1 != (uint *)0x0)) {
    uVar3 = *in_stack_00000008;
    *puVar1 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar3 = in_stack_00000008[1];
    puVar1[1] = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar3 = in_stack_00000008[2];
    puVar1[2] = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar3 = in_stack_00000008[3];
    puVar1[3] = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar3 = in_stack_00000008[5];
    puVar1[4] = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    puVar1 = puVar1 + 5;
    if (in_stack_00000008[5] != 0) {
      _bcopy((void *)in_stack_00000008[4],puVar1,in_stack_00000008[5]);
      puVar1 = (uint *)((int)puVar1 + (in_stack_00000008[5] + 3 & 0xfffffffc));
    }
    uVar3 = in_stack_00000008[6];
    *puVar1 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    if (in_stack_00000008[6] == 0) {
      bVar2 = (*(code *)in_stack_00000008[8])(in_stack_00000004,in_stack_00000008[7]);
      return bVar2;
    }
    if (in_stack_00000008[6] != 2) {
      return 1;
    }
    bVar2 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 7);
    if (bVar2 != 0) {
      bVar2 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 8);
      return bVar2;
    }
  }
  else {
    if ((in_stack_00000004->x_op != XDR_DECODE) ||
       (puVar1 = (uint *)(*in_stack_00000004->x_ops->x_inline)(in_stack_00000004,0xc),
       puVar1 == (uint *)0x0)) {
      bVar2 = _xdr_u_long(in_stack_00000004,in_stack_00000008);
      if ((bVar2 != 0) &&
         ((bVar2 = _xdr_enum(in_stack_00000004,(int *)(in_stack_00000008 + 1)), bVar2 != 0 &&
          (in_stack_00000008[1] == 1)))) {
        bVar2 = _xdr_union(in_stack_00000004,(int *)(in_stack_00000008 + 2),
                           (char *)(in_stack_00000008 + 3),(xdr_discrim *)&DAT_001dd140,
                           (xdrproc_t)0x0);
        return bVar2;
      }
      return 0;
    }
    uVar3 = *puVar1;
    *in_stack_00000008 =
         uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar3 = puVar1[1];
    uVar3 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    in_stack_00000008[1] = uVar3;
    if (uVar3 == 1) {
      uVar3 = puVar1[2];
      uVar3 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
      in_stack_00000008[2] = uVar3;
      if (uVar3 == 0) {
        puVar1 = (uint *)(*in_stack_00000004->x_ops->x_inline)(in_stack_00000004,8);
        if (puVar1 == (uint *)0x0) {
          bVar2 = _xdr_enum(in_stack_00000004,(int *)(in_stack_00000008 + 3));
          if (bVar2 == 0) {
            return 0;
          }
          bVar2 = _xdr_u_int(in_stack_00000004,in_stack_00000008 + 5);
          if (bVar2 == 0) {
            return 0;
          }
        }
        else {
          uVar3 = *puVar1;
          in_stack_00000008[3] =
               uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
          uVar3 = puVar1[1];
          in_stack_00000008[5] =
               uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
        }
        uVar3 = in_stack_00000008[5];
        if (uVar3 != 0) {
          if (400 < uVar3) {
            return 0;
          }
          if (in_stack_00000008[4] == 0) {
            uVar3 = _kalloc(uVar3);
            in_stack_00000008[4] = uVar3;
          }
          piVar4 = (*in_stack_00000004->x_ops->x_inline)
                             (in_stack_00000004,in_stack_00000008[5] + 3 & 0xfffffffc);
          if (piVar4 == (int32_t *)0x0) {
            bVar2 = _xdr_opaque(in_stack_00000004,(char *)in_stack_00000008[4],in_stack_00000008[5])
            ;
            if (bVar2 == 0) {
              return 0;
            }
          }
          else {
            _bcopy(piVar4,(void *)in_stack_00000008[4],in_stack_00000008[5]);
          }
        }
        bVar2 = _xdr_enum(in_stack_00000004,(int *)(in_stack_00000008 + 6));
        if (bVar2 != 0) {
          if (in_stack_00000008[6] == 0) {
            bVar2 = (*(code *)in_stack_00000008[8])(in_stack_00000004,in_stack_00000008[7]);
            return bVar2;
          }
          if (in_stack_00000008[6] != 2) {
            return 1;
          }
          bVar2 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 7);
          if (bVar2 != 0) {
            bVar2 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 8);
            return bVar2;
          }
        }
      }
      else if ((uVar3 == 1) &&
              (bVar2 = _xdr_enum(in_stack_00000004,(int *)(in_stack_00000008 + 3)), bVar2 != 0)) {
        if (in_stack_00000008[3] == 0) {
          bVar2 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 4);
          if (bVar2 != 0) {
            bVar2 = _xdr_u_long(in_stack_00000004,in_stack_00000008 + 5);
            return bVar2;
          }
        }
        else if (in_stack_00000008[3] == 1) {
          bVar2 = _xdr_enum(in_stack_00000004,(int *)(in_stack_00000008 + 4));
          return bVar2;
        }
      }
    }
  }
  return 0;
}

