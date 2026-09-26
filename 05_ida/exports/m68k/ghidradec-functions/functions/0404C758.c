
void sub_404C758(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uStack_8;
  
  if (*(sword *)(*(int *)(_active_u + 0x1a) + 2) == 0) {
    uVar3 = *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18);
    *(uint *)(param_1 + 0x18) = uVar3;
    if ((((-1 < *(int *)(param_1 + 0x14)) && (0x2b < uVar3)) &&
        (uVar5 = (uint)*(sword *)(param_1 + 0x2e), 0x14 < uVar5)) && (uVar5 <= uVar3 - 0x18)) {
      uStack_8 = 0;
      iVar6 = param_1 + 0x2c;
      puVar1 = &uStack_8;
      puVar2 = _mfree;
      for (; _mfree = puVar2, 0 < (int)uVar5; uVar5 = uVar5 - uVar3) {
        if (puVar2 == (undefined4 *)0x0) {
          puVar2 = (undefined4 *)_m_more(1,1);
        }
        else {
          if (*(sword *)((int)puVar2 + 10) != 0) {
                    /* WARNING: Subroutine does not return */
            _panic(&aMget);
          }
          *(undefined2 *)((int)puVar2 + 10) = 1;
          word_40B61CC = word_40B61CC + -1;
          word_40B61CE = word_40B61CE + 1;
          _mfree = (undefined4 *)*puVar2;
          *puVar2 = 0;
          puVar2[1] = 0xc;
        }
        if (puVar2 == (undefined4 *)0x0) {
          _m_freem(uStack_8);
          return;
        }
        uVar3 = _m68k_page_size;
        if ((int)_m68k_page_size < 0) {
          uVar3 = _m68k_page_size + 1;
        }
        if ((int)uVar5 < (int)uVar3 >> 1) {
loc_404C8BE:
          uVar3 = 0x70;
          if ((int)uVar5 < 0x71) {
loc_404C8C4:
            uVar3 = uVar5;
          }
        }
        else {
          if (_mclfree == (undefined4 *)0x0) {
            _m_clalloc(1,1,0);
          }
          if (_mclfree == (undefined4 *)0x0) {
            *(undefined2 *)(puVar2 + 2) = 0x70;
          }
          else {
            _mclrefcnt[(int)_mclfree - _mbutl >> 10] =
                 _mclrefcnt[(int)_mclfree - _mbutl >> 10] + '\x01';
            dword_40B61BC = dword_40B61BC + -1;
            iVar4 = (int)_mclfree - (int)puVar2;
            _mclfree = (undefined4 *)*_mclfree;
            puVar2[1] = iVar4;
            *(undefined2 *)(puVar2 + 2) = 0x400;
            *(undefined2 *)(puVar2 + 3) = 1;
          }
          uVar3 = (uint)*(sword *)(puVar2 + 2);
          if (uVar3 != _m68k_page_size) goto loc_404C8BE;
          if ((int)uVar5 < (int)uVar3) goto loc_404C8C4;
        }
        *(sword *)(puVar2 + 2) = (sword)uVar3;
        _bcopy(iVar6,puVar2[1] + (int)puVar2,uVar3);
        iVar6 = uVar3 + iVar6;
        *puVar1 = puVar2;
        puVar1 = puVar2;
        puVar2 = _mfree;
      }
      if (dword_40AF8B0 != *(int *)(param_1 + 0x3c)) {
        if (dword_40AF8A8 != 0) {
          if (*(sword *)(dword_40AF8A8 + 0x26) == 1) {
            _rtfree(dword_40AF8A8);
          }
          else {
            *(sword *)(dword_40AF8A8 + 0x26) = *(sword *)(dword_40AF8A8 + 0x26) + -1;
          }
        }
        dword_40AF8A8 = 0;
      }
      _ip_output(uStack_8,0,&dword_40AF8A8,0x21);
    }
  }
  return;
}
