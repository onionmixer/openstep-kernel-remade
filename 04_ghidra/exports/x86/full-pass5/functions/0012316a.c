/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012316a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0012316a(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  void *pvVar6;
  int unaff_EBP;
  undefined4 *puVar7;
  int *unaff_EDI;
  
  *(short *)(&DAT_001e917c + *(short *)((int)unaff_EDI + 10) * 2) =
       *(short *)(&DAT_001e917c + *(short *)((int)unaff_EDI + 10) * 2) + -1;
  _DAT_001e917c = _DAT_001e917c + 1;
  *(undefined2 *)((int)unaff_EDI + 10) = 0;
  if (0x7f < (uint)unaff_EDI[1]) {
    _mclput();
  }
  iVar2 = *unaff_EDI;
  *unaff_EDI = (int)_mfree;
  unaff_EDI[1] = 0;
  unaff_EDI[0x1f] = 0;
  _mfree = unaff_EDI;
  _splx();
  if (_m_want != 0) {
    _m_want = 0;
    _wakeup();
  }
  *(int *)(unaff_EBP + -0x1c) = iVar2 + *(int *)(iVar2 + 4);
  if ((((0x1b < *(ushort *)(iVar2 + 8)) && (-1 < *(char *)(*(int *)(unaff_EBP + 8) + 0xc))) &&
      (uVar1 = *(ushort *)(*(int *)(unaff_EBP + -0x1c) + 2),
      (ushort)(uVar1 >> 8 | uVar1 << 8) == 0x800)) &&
     ((_revarp != 0 &&
      (uVar1 = *(ushort *)(*(int *)(unaff_EBP + -0x1c) + 6), (ushort)(uVar1 >> 8 | uVar1 << 8) == 3)
      ))) {
    puVar7 = (undefined4 *)&_arptab;
    puVar5 = &DAT_001e9c84;
    do {
      if (((puVar5[7] & 4) != 0) &&
         (iVar4 = _bcmp(puVar5,(void *)(*(int *)(unaff_EBP + -0x1c) + 0x12),6), iVar4 == 0)) break;
      puVar5 = puVar5 + 0x14;
      puVar7 = puVar7 + 5;
    } while (puVar7 < &_master_processor);
    if (puVar7 < &_master_processor) {
      *(void **)(unaff_EBP + -0x20) = (void *)(unaff_EBP + -0x16);
      _bcopy((void *)(*(int *)(unaff_EBP + -0x1c) + 8),(void *)(unaff_EBP + -0x16),6);
      _bcopy(puVar7,(void *)(*(int *)(unaff_EBP + -0x1c) + 0x18),4);
      iVar4 = *(int *)(*(int *)(unaff_EBP + 8) + 0x18);
      if (iVar4 != 0) {
        do {
          if (*(int *)(iVar4 + 0x20) == *(int *)(unaff_EBP + 8)) {
            _bcopy((void *)(iVar4 + 4),(void *)(*(int *)(unaff_EBP + -0x1c) + 0xe),4);
            break;
          }
          iVar4 = *(int *)(iVar4 + 0x24);
        } while (iVar4 != 0);
        if (iVar4 != 0) {
          pvVar6 = (void *)(*(int *)(unaff_EBP + 8) + 0x60);
          _bcopy(pvVar6,(void *)(*(int *)(unaff_EBP + -0x1c) + 8),6);
          _bcopy(pvVar6,(void *)(*(int *)(unaff_EBP + -0x20) + 6),6);
          *(undefined2 *)(*(int *)(unaff_EBP + -0x20) + 0xc) = 0x8035;
          iVar4 = *(int *)(unaff_EBP + -0x1c);
          *(undefined2 *)(iVar4 + 6) = 0x400;
          *(undefined2 *)(unaff_EBP + -0x18) = 0;
          if (_revarpdebug != 0) {
            uVar3 = *(uint *)(iVar4 + 0x18);
            _printf(s_revarp_reply_to__X_from__X_001dba4d,
                    uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18)
            ;
          }
          (**(code **)(*(int *)(unaff_EBP + 8) + 0x34))(*(int *)(unaff_EBP + 8),iVar2);
          return;
        }
      }
      if (_revarpdebug != 0) {
        _printf(s_revarp__can_t_find_ifaddr_001dba32);
      }
    }
  }
  _m_freem();
  return;
}

