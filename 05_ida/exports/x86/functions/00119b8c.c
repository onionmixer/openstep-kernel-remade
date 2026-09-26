/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x119b8c. */
int *__cdecl bread(int a1, int a2, int a3)
{
  int *v3; // ebx
  int v4; // eax
  int v6; // [esp+0h] [ebp-4h]

  ++bstats; /*0x119b93*/
  if ( !a3 ) /*0x119b9b*/
    panic(aBreadSize0); /*0x119ba2*/
  v3 = (int *)getblk(a1, a2, a3); /*0x119bb8*/
  v4 = *v3; /*0x119bba*/
  if ( (*v3 & 2) != 0 ) /*0x119bc1*/
  {
    ++dword_1E99C4; /*0x119bc3*/
    return v3; /*0x119bc9*/
  }
  else
  {
    LOBYTE(v4) = v4 | 1; /*0x119bd0*/
    *v3 = v4; /*0x119bd2*/
    if ( v3[5] > v3[6] ) /*0x119bda*/
      panic(aBread); /*0x119be1*/
    (*(void (__stdcall **)(int *, int))(*(_DWORD *)(v3[16] + 28) + 84))(v3, v6); /*0x119bf3*/
    ++*(_DWORD *)(active_u + 412); /*0x119bfa*/
    biowait((unsigned int)v3); /*0x119c01*/
    return v3; /*0x119c06*/
  }
}
