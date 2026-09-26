
undefined4 _assert_wait(uint param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  puVar2 = _active_threads;
  if (_active_threads[0xe] != 0) {
    _printf(aAssertWaitAlre,_active_threads[0xe]);
                    /* WARNING: Subroutine does not return */
    _panic(aAssertWait);
  }
  uVar3 = 0;
  bVar5 = false;
  if (param_1 == 0) {
    if (param_2 != 0) {
      uVar4 = 1;
      goto loc_4050844;
    }
  }
  else {
    uVar4 = param_1;
    if ((int)param_1 < 0) {
      uVar4 = ~param_1;
    }
    uVar3 = ((int)uVar4 / 0x3b) * 0x3b;
    bVar5 = uVar4 < uVar3;
    iVar1 = (int)uVar4 % 0x3b;
    *_active_threads = &_wait_queue + iVar1 * 2;
    puVar2[1] = (&dword_40C2804)[iVar1 * 2];
    *(undefined4 **)puVar2[1] = puVar2;
    (&dword_40C2804)[iVar1 * 2] = puVar2;
    puVar2[0xe] = param_1;
    if (param_2 != 0) {
      uVar4 = 1;
      goto loc_4050844;
    }
  }
  uVar4 = 9;
loc_4050844:
  uVar4 = uVar4 | puVar2[0x12];
  puVar2[0x12] = uVar4;
  return CONCAT22((sword)(uVar3 >> 0x10),
                  (word)(byte)(bVar5 << 4 | ((int)uVar4 < 0) << 3 | (uVar4 == 0) << 2));
}

