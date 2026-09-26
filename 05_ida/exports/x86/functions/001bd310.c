/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bd310. */
int __cdecl snd_server(_DWORD *a1, int a2)
{
  int v2; // edi
  unsigned int v3; // edx
  int v4; // eax
  int v6; // [esp+Ch] [ebp-4h]

  v6 = 1; /*0x1bd31f*/
  v2 = 0; /*0x1bd326*/
  *(_BYTE *)(a2 + 3) = 1; /*0x1bd328*/
  *(_DWORD *)(a2 + 4) = 24; /*0x1bd32c*/
  *(_DWORD *)(a2 + 8) = 0; /*0x1bd333*/
  *(_DWORD *)(a2 + 12) = 0; /*0x1bd33a*/
  *(_DWORD *)(a2 + 16) = 0; /*0x1bd341*/
  *(_DWORD *)(a2 + 20) = 0; /*0x1bd348*/
  v3 = a1[5]; /*0x1bd34f*/
  if ( v3 > 1 )
  {
    if ( v3 - 100 > 0x10 )
    {
      if ( v3 - 200 > 7 )
      {
        audio_snd_reply_illegal_msg(a2, 0, a1[4], v3, 102); /*0x1bd3b6*/
      }
      else
      {
        IOLog((int)"Audio: received dsp cmd port msg!\n");
        audio_snd_reply_illegal_msg(a2, 0, a1[4], a1[5], 102); /*0x1bd39a*/
      }
      v6 = 0; /*0x1bd39f*/
      goto LABEL_10; /*0x1bd3a9*/
    }
    v4 = sub_1BCAD4((int)a1, a2); /*0x1bd36a*/
  }
  else
  {
    v4 = sub_1BC56C(a1, a2); /*0x1bd359*/
  }
  v2 = v4; /*0x1bd36f*/
LABEL_10:
  if ( v2 ) /*0x1bd3c7*/
    audio_snd_reply_illegal_msg(a2, 0, a1[4], a1[5], v2); /*0x1bd3d5*/
  return v6; /*0x1bd3e0*/
}
