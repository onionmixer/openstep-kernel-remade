/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1be7d4. */
unsigned int __cdecl audio_linear16_peak(int a1, __int16 *a2, unsigned int a3, _DWORD *a4, _DWORD *a5)
{
  unsigned int v6; // ecx
  unsigned int result; // eax
  _WORD *v8; // edx
  unsigned int v9; // ecx
  __int16 v10; // ax
  _WORD *v11; // edx

  *a5 = 0; /*0x1be7e9*/
  *a4 = 0; /*0x1be7ef*/
  if ( a1 == 1 ) /*0x1be7f8*/
  {
    v6 = 0; /*0x1be7fa*/
    for ( result = a3 >> 1; v6 < a3 >> 1; ++v6 ) /*0x1be7fe*/
    {
      LOWORD(result) = *a2; /*0x1be808*/
      v8 = a2 + 1; /*0x1be80b*/
      if ( (result & 0x8000u) != 0 ) /*0x1be811*/
        LOWORD(result) = -(__int16)result; /*0x1be813*/
      result = (__int16)result; /*0x1be816*/
      if ( *a4 < (unsigned int)(__int16)result ) /*0x1be819*/
        *a4 = (__int16)result; /*0x1be81b*/
      a2 = v8 + 1; /*0x1be81d*/
    }
    *a5 = *a4; /*0x1be827*/
  }
  else
  {
    v9 = 0; /*0x1be82c*/
    for ( result = a3 >> 1; v9 < a3 >> 1; ++v9 ) /*0x1be830*/
    {
      v10 = *a2; /*0x1be838*/
      v11 = a2 + 1; /*0x1be83b*/
      if ( v10 < 0 ) /*0x1be841*/
        v10 = -v10; /*0x1be843*/
      if ( *a4 < (unsigned int)v10 ) /*0x1be849*/
        *a4 = v10; /*0x1be84b*/
      LOWORD(result) = *v11; /*0x1be84d*/
      a2 = v11 + 1; /*0x1be850*/
      if ( (result & 0x8000u) != 0 ) /*0x1be856*/
        LOWORD(result) = -(__int16)result; /*0x1be858*/
      result = (__int16)result; /*0x1be85b*/
      if ( *a5 < (unsigned int)(__int16)result ) /*0x1be85e*/
        *a5 = (__int16)result; /*0x1be860*/
    }
  }
  return result; /*0x1be86a*/
}
