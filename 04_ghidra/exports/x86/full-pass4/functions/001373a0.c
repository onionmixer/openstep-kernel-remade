/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001373a0 */

undefined4 __svcauth_unix(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  boolean_t bVar7;
  int iVar8;
  undefined4 uVar9;
  XDR local_1c;
  
  puVar1 = *(uint **)(param_1 + 0x18);
  puVar1[1] = (uint)(puVar1 + 6);
  puVar1[5] = (uint)(puVar1 + 0x46);
  uVar2 = *(uint *)(param_2 + 0x20);
  _xdrmem_create(&local_1c,*(char **)(param_2 + 0x1c),uVar2,XDR_DECODE);
  puVar4 = (uint *)(*(local_1c.x_ops)->x_inline)(&local_1c,uVar2);
  if (puVar4 == (uint *)0x0) {
    bVar7 = _xdr_authunix_parms();
    if (bVar7 == 0) {
      local_1c.x_op = XDR_FREE;
      _xdr_authunix_parms();
      uVar9 = 1;
      goto LAB_00137501;
    }
LAB_001374e8:
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x20) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x28) = 0;
    uVar9 = 0;
  }
  else {
    uVar5 = *puVar4;
    *puVar1 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
    uVar5 = puVar4[1];
    uVar5 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
    if ((int)uVar5 < 0x100) {
      _bcopy(puVar4 + 2,(void *)puVar1[1],uVar5);
      *(undefined1 *)(uVar5 + puVar1[1]) = 0;
      uVar6 = uVar5 + 3;
      if ((int)uVar6 < 0) {
        uVar6 = uVar5 + 6;
      }
      puVar4 = (uint *)((int)(puVar4 + 2) + (uVar6 & 0xfffffffc));
      uVar5 = *puVar4;
      puVar1[2] = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      uVar5 = puVar4[1];
      puVar1[3] = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      uVar5 = puVar4[2];
      puVar4 = puVar4 + 3;
      uVar5 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
      if ((int)uVar5 < 0x11) {
        puVar1[4] = uVar5;
        iVar8 = 0;
        if (0 < (int)uVar5) {
          do {
            uVar3 = *puVar4;
            puVar4 = puVar4 + 1;
            *(uint *)(puVar1[5] + iVar8 * 4) =
                 uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
            iVar8 = iVar8 + 1;
          } while (iVar8 < (int)uVar5);
        }
        if (uVar2 < (uVar6 & 0xfffffffc) + 0x14 + uVar5 * 4) {
          _printf(s_bad_auth_len_gid__d_str__d_auth___001dd1b4,uVar5,uVar2,uVar2);
          uVar9 = 1;
          goto LAB_00137501;
        }
        goto LAB_001374e8;
      }
    }
    uVar9 = 1;
  }
LAB_00137501:
  (*(local_1c.x_ops)->x_destroy)(&local_1c);
  return uVar9;
}

