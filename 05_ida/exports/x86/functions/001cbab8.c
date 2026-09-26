/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cbab8. */
int __cdecl NXNextHashState(NXHashTable *table, NXHashState *state, void **data)
{
  _DWORD *buckets; // ecx
  int v4; // eax
  _DWORD *v5; // ecx
  void *v6; // eax

  buckets = table->buckets; /*0x1cbac6*/
  if ( state->j ) /*0x1cbac9*/
  {
LABEL_4:
    --state->j; /*0x1cbae3*/
    v5 = &buckets[2 * state->i]; /*0x1cbaef*/
    if ( *v5 == 1 ) /*0x1cbaf4*/
      v6 = (void *)v5[1]; /*0x1cbaf6*/
    else
      v6 = *(void **)(v5[1] + 4 * state->j); /*0x1cbb06*/
    *data = v6; /*0x1cbb09*/
    return 1; /*0x1cbb0b*/
  }
  else
  {
    while ( state->i ) /*0x1cbad3*/
    {
      --state->i; /*0x1cbad5*/
      v4 = buckets[2 * state->i]; /*0x1cbad9*/
      state->j = v4; /*0x1cbadc*/
      if ( v4 ) /*0x1cbae1*/
        goto LABEL_4; /*0x1cbae1*/
    }
    return 0; /*0x1cbafc*/
  }
}
