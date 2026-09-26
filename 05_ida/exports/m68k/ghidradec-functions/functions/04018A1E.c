
void _dnlc_purge(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  dword_40B6D90 = dword_40B6D90 + 1;
  while( true ) {
    puVar2 = &_nc_hash;
    while (puVar1 = (undefined4 *)*puVar2, puVar2 == puVar1) {
      puVar2 = puVar2 + 2;
      if (&DAT_40b6d5f < puVar2) {
        return;
      }
    }
    if ((puVar1[5] == 0) || (puVar1[4] == 0)) break;
    sub_4018AFE(puVar1);
  }
                    /* WARNING: Subroutine does not return */
  _panic(aDnlcPurgeZeroV);
}
