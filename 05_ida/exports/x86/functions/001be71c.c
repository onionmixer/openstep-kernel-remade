/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1be71c. */
unsigned int __cdecl audio_mulaw8_peak(int a1, unsigned __int8 *a2, unsigned int a3, _DWORD *a4, _DWORD *a5)
{
  unsigned int v6; // ecx
  unsigned int result; // eax
  unsigned __int8 *v8; // edx
  unsigned int v9; // ecx
  __int16 v10; // ax
  unsigned __int8 *v11; // edx
  unsigned __int8 *v12; // edx
  unsigned __int8 *v13; // edx

  *a5 = 0; /*0x1be731*/
  *a4 = 0; /*0x1be737*/
  if ( a1 == 1 ) /*0x1be740*/
  {
    v6 = 0; /*0x1be742*/
    for ( result = a3 >> 2; v6 < a3 >> 2; ++v6 ) /*0x1be746*/
    {
      LOWORD(result) = audio_muLaw[*a2]; /*0x1be753*/
      v8 = a2 + 1; /*0x1be75b*/
      if ( (result & 0x8000u) != 0 ) /*0x1be75f*/
        LOWORD(result) = -(__int16)result; /*0x1be761*/
      result = (__int16)result; /*0x1be764*/
      if ( *a4 < (unsigned int)(__int16)result ) /*0x1be767*/
        *a4 = (__int16)result; /*0x1be769*/
      a2 = v8 + 3; /*0x1be76b*/
    }
    *a5 = *a4; /*0x1be775*/
  }
  else
  {
    v9 = 0; /*0x1be77c*/
    for ( result = a3 >> 2; v9 < a3 >> 2; ++v9 ) /*0x1be780*/
    {
      v10 = audio_muLaw[*a2]; /*0x1be78f*/
      v11 = a2 + 1; /*0x1be797*/
      if ( v10 < 0 ) /*0x1be79b*/
        v10 = -v10; /*0x1be79d*/
      if ( *a4 < (unsigned int)v10 ) /*0x1be7a3*/
        *a4 = v10; /*0x1be7a5*/
      v12 = v11 + 1; /*0x1be7a7*/
      LOWORD(result) = audio_muLaw[*v12]; /*0x1be7ab*/
      v13 = v12 + 1; /*0x1be7b3*/
      if ( (result & 0x8000u) != 0 ) /*0x1be7b7*/
        LOWORD(result) = -(__int16)result; /*0x1be7b9*/
      result = (__int16)result; /*0x1be7bc*/
      if ( *a5 < (unsigned int)(__int16)result ) /*0x1be7bf*/
        *a5 = (__int16)result; /*0x1be7c1*/
      a2 = v13 + 1; /*0x1be7c3*/
    }
  }
  return result; /*0x1be7cc*/
}
