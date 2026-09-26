/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x127a88. */
int __cdecl ip_ctloutput(int a1, int a2, int a3, int a4, int *a5)
{
  int v5; // esi
  int v6; // ebx
  int v8; // eax
  int *v9; // eax
  int v10; // edx

  v5 = 0; /*0x127a97*/
  v6 = *(_DWORD *)(a2 + 8); /*0x127a99*/
  if ( a3 ) /*0x127aa0*/
    goto LABEL_19; /*0x127aa0*/
  if ( !a1 ) /*0x127aaa*/
  {
    if ( a4 == 1 ) /*0x127afb*/
    {
      v9 = m_get(1, 10); /*0x127b10*/
      *a5 = (int)v9; /*0x127b15*/
      v10 = *(_DWORD *)(v6 + 56); /*0x127b1a*/
      if ( v10 ) /*0x127b1f*/
      {
        v9[1] = *(_DWORD *)(v10 + 4); /*0x127b24*/
        *(_WORD *)(*a5 + 8) = *(_WORD *)(*(_DWORD *)(v6 + 56) + 8); /*0x127b30*/
        bcopy( /*0x127b46*/
          (const void *)(*(_DWORD *)(*(_DWORD *)(v6 + 56) + 4) + *(_DWORD *)(v6 + 56)),
          (void *)(*(_DWORD *)(*a5 + 4) + *a5),
          *(__int16 *)(*a5 + 8));
      }
      else
      {
        *((_WORD *)v9 + 4) = 0; /*0x127b50*/
      }
LABEL_20:
      if ( a1 == 1 ) /*0x127b75*/
      {
        if ( *a5 ) /*0x127b77*/
          m_free(*a5); /*0x127b7e*/
      }
      return v5; /*0x127b7e*/
    }
    if ( a4 >= 1 && a4 <= 7 && a4 >= 3 ) /*0x127b07*/
    {
      v8 = ip_getmoptions(a4, *(_DWORD *)(v6 + 60), a5); /*0x127b5e*/
      goto LABEL_18; /*0x127b09*/
    }
LABEL_19:
    v5 = 22; /*0x127b6c*/
    goto LABEL_20; /*0x127b6c*/
  }
  if ( a1 == 1 ) /*0x127ab0*/
  {
    if ( a4 == 1 ) /*0x127ab9*/
      return ip_pcbopts(v6 + 56, *a5); /*0x127ac7*/
    if ( a4 >= 1 && a4 <= 7 && a4 >= 3 ) /*0x127ae1*/
    {
      v8 = ip_setmoptions(a4, v6 + 60, *a5); /*0x127aef*/
LABEL_18:
      v5 = v8; /*0x127b63*/
      goto LABEL_20; /*0x127b68*/
    }
    goto LABEL_19; /*0x127ae1*/
  }
  return v5; /*0x127b88*/
}
