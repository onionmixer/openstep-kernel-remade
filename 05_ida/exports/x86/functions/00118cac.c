/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x118cac. */
void __cdecl unp_scan(int *a1, void (__cdecl *a2)(int))
{
  int *i; // ecx
  int *v3; // edx
  __int16 v4; // ax
  int *v5; // esi
  signed int v6; // ebx
  int v7; // [esp-4h] [ebp-18h]
  signed int v8; // [esp+Ch] [ebp-8h]
  int *v9; // [esp+10h] [ebp-4h]

  for ( i = a1; i; i = (int *)i[31] ) /*0x118cba*/
  {
    v3 = i; /*0x118cbc*/
    if ( i ) /*0x118cc0*/
    {
      while ( 1 ) /*0x118cc4*/
      {
        if ( *((_WORD *)v3 + 5) == 12 ) /*0x118cc9*/
        {
          v4 = *((_WORD *)v3 + 4); /*0x118ccb*/
          if ( v4 ) /*0x118cd2*/
            break; /*0x118cd2*/
        }
        v3 = (int *)*v3; /*0x118d04*/
        if ( !v3 ) /*0x118d08*/
          goto LABEL_9; /*0x118d08*/
      }
      v8 = (unsigned int)v4 >> 2; /*0x118cd8*/
      v5 = (int *)((char *)v3 + v3[1]); /*0x118cdd*/
      v6 = 0; /*0x118ce0*/
      if ( v8 ) /*0x118ce4*/
      {
        do /*0x118d00*/
        {
          v7 = *v5++; /*0x118cea*/
          v9 = i; /*0x118cee*/
          a2(v7); /*0x118cf4*/
          ++v6; /*0x118cf9*/
          i = v9; /*0x118cfa*/
        }
        while ( v8 > v6 ); /*0x118d00*/
      }
    }
LABEL_9:
    ; /*0x118d0a*/
  }
}
