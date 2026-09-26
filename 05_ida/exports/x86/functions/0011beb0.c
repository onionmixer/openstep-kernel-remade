/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11beb0. */
int __cdecl vno_bsd_lock(int a1, char a2)
{
  int v2; // eax
  unsigned int v4; // eax
  __int16 v5; // ax
  int v6; // [esp+4h] [ebp-8h]

  v2 = *(_DWORD *)(a1 + 8); /*0x11beba*/
  if ( (v2 & 0x100) != 0 && (a2 & 2) != 0 || (v2 & 0x80u) != 0 && (a2 & 1) != 0 ) /*0x11bed4*/
    return 0; /*0x11bed4*/
  v6 = *(_DWORD *)(a1 + 24); /*0x11bee7*/
  if ( setjmp((int *)(dword_1E875C + 40)) ) /*0x11bf03*/
  {
    if ( ((*(int *)(active_u + 320) >> (*(_BYTE *)(*(_DWORD *)active_u + 23) - 1)) & 1) == 0 ) /*0x11bf28*/
    {
      *(_BYTE *)(dword_1E875C + 105) = 2; /*0x11bf39*/
      return 0; /*0x11bf3d*/
    }
    return 4; /*0x11bf2f*/
  }
  while ( 1 ) /*0x11bf83*/
  {
    while ( (*(_BYTE *)(v6 + 4) & 4) != 0 ) /*0x11bf83*/
    {
      if ( (*(_BYTE *)(a1 + 9) & 1) == 0 ) /*0x11bf4b*/
      {
        if ( (a2 & 4) != 0 ) /*0x11bf60*/
          return 35; /*0x11bf60*/
        *(_BYTE *)(v6 + 4) |= 0x10u; /*0x11bf65*/
        v4 = v6 + 10; /*0x11bf70*/
        goto LABEL_13; /*0x11bf70*/
      }
      vno_bsd_unlock(a1, 256); /*0x11bf53*/
    }
    if ( (a2 & 2) == 0 ) /*0x11bf8b*/
      break; /*0x11bf8b*/
    v5 = *(_WORD *)(v6 + 4); /*0x11bf90*/
    if ( (v5 & 8) == 0 ) /*0x11bf96*/
      break; /*0x11bf96*/
    if ( *(char *)(a1 + 8) >= 0 ) /*0x11bf9f*/
    {
      if ( (a2 & 4) != 0 ) /*0x11bfb3*/
        return 35; /*0x11bfba*/
      LOBYTE(v5) = v5 | 0x10; /*0x11bfbc*/
      *(_WORD *)(v6 + 4) = v5; /*0x11bfc1*/
      v4 = v6 + 8; /*0x11bfca*/
LABEL_13:
      sleep(v4); /*0x11bf73*/
    }
    else
    {
      vno_bsd_unlock(a1, 128); /*0x11bfa7*/
    }
  }
  if ( (*(_BYTE *)(a1 + 9) & 1) != 0 ) /*0x11bfd7*/
    panic(aVnoBsdLock); /*0x11bfde*/
  if ( (a2 & 2) != 0 ) /*0x11bfe7*/
  {
    ++*(_WORD *)(v6 + 10); /*0x11bfec*/
    *(_BYTE *)(v6 + 4) |= 4u; /*0x11bff0*/
    *(_DWORD *)(a1 + 8) |= 0x100u; /*0x11bff7*/
  }
  if ( (a2 & 1) != 0 && *(char *)(a1 + 8) >= 0 ) /*0x11c00b*/
  {
    ++*(_WORD *)(v6 + 8); /*0x11c010*/
    *(_BYTE *)(v6 + 4) |= 8u; /*0x11c014*/
    *(_BYTE *)(a1 + 8) |= 0x80u; /*0x11c01b*/
  }
  return 0; /*0x11c021*/
}
