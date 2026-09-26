/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00134d3c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00134d3c(XDR *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  boolean_t bVar5;
  char *pcVar6;
  
  iVar2 = FUN_001341f8(param_1,param_2);
  if (iVar2 != 0) {
    if ((param_1->x_op == XDR_ENCODE) && (*(int *)(param_2 + 0x4c) != 0)) {
      uVar3 = _splimp();
      puVar4 = _mfree;
      if (_mfree == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)_m_more(1,1);
      }
      else {
        if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(&DAT_001dcd0e);
        }
        *(undefined2 *)((int)_mfree + 10) = 1;
        _DAT_001e917c = _DAT_001e917c + -1;
        _DAT_001e917e = _DAT_001e917e + 1;
        puVar1 = (undefined4 *)*_mfree;
        *_mfree = 0;
        _mfree = puVar1;
        puVar4[1] = 0xc;
      }
      _splx(uVar3);
      if (puVar4 == (undefined4 *)0x0) {
        _printf(s_xdr_rrok__FAILED__can_t_get_mbuf_001dcd13);
        return 0;
      }
      pcVar6 = (char *)((int)puVar4 + puVar4[1]);
      *(code **)pcVar6 = FUN_00134e98;
      pcVar6[4] = '\0';
      pcVar6[5] = '\0';
      pcVar6[6] = '\0';
      pcVar6[7] = '\0';
      *(undefined4 *)(pcVar6 + 8) = *(undefined4 *)(param_2 + 0x50);
      *(undefined4 *)(pcVar6 + 0xc) = *(undefined4 *)(param_2 + 0x4c);
      *(undefined4 *)(pcVar6 + 0x10) = *(undefined4 *)(param_2 + 0x48);
      *(undefined4 *)(pcVar6 + 0x14) = *(undefined4 *)(param_2 + 0x44);
      param_1->x_public = pcVar6;
      iVar2 = _xdrmbuf_putbuf(param_1,*(undefined4 *)(param_2 + 0x48),
                              *(undefined4 *)(param_2 + 0x44),FUN_00134f7c,pcVar6);
      if (iVar2 != 0) {
        return 1;
      }
      pcVar6[4] = '\x01';
      pcVar6[5] = '\0';
      pcVar6[6] = '\0';
      pcVar6[7] = '\0';
    }
    bVar5 = _xdr_bytes(param_1,(char **)(param_2 + 0x48),(uint *)(param_2 + 0x44),0x2000);
    if (bVar5 != 0) {
      return 1;
    }
  }
  return 0;
}

