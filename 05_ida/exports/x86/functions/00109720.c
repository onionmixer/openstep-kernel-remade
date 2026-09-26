/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x109720. */
int __cdecl killpg1(char *a1, int a2, int a3)
{
  int v3; // edi
  int v4; // esi
  unsigned int i; // ebx
  __int16 v6; // ax
  int result; // eax
  int v8; // [esp+Ch] [ebp-4h]

  v3 = a2; /*0x109729*/
  v8 = 0; /*0x10972c*/
  if ( !a3 && !a2 ) /*0x10973b*/
  {
    v3 = *(__int16 *)(*(_DWORD *)active_u + 46); /*0x109744*/
    if ( !*(_WORD *)(*(_DWORD *)active_u + 46) ) /*0x109744*/
      return 3; /*0x109744*/
  }
  v4 = 0; /*0x109750*/
  for ( i = allproc; i; i = *(_DWORD *)(i + 8) ) /*0x10975a*/
  {
    if ( (*(__int16 *)(i + 46) == v3 || a3) /*0x109784*/
      && *(_WORD *)(i + 50)
      && (*(_BYTE *)(i + 40) & 2) == 0
      && (!a3 || *(_DWORD *)active_u != i) )
    {
      v6 = *(_WORD *)(*(_DWORD *)(active_u + 28) + 2); /*0x10978e*/
      if ( !v6 || *(_WORD *)(i + 44) == v6 || a1 == (char *)19 && inferior(i) ) /*0x1097a4*/
      {
        ++v4; /*0x1097c0*/
        if ( a1 ) /*0x1097c5*/
          psignal(i, a1); /*0x1097cc*/
      }
      else if ( !a3 ) /*0x1097b4*/
      {
        v8 = 1; /*0x1097b6*/
      }
    }
  }
  result = v8; /*0x1097db*/
  if ( !v8 && !v4 ) /*0x1097e4*/
    return 3; /*0x1097e6*/
  return result; /*0x1097ee*/
}
